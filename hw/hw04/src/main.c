/*
 * main.c
 *
 * Driver file for Homework 2: Song Composer. This script contains the
 * declarations and implementations of the menu functions and other functions
 * to handle user inputs and outputs (I/O).
 *
 * */

// AVR libraries
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "lcd_driver.h"
#include "adc_controller.h"

// --- constant strings stored in the program space for repeated use ---
// strings to build menus
const char PROGMEM ftl_str[] = "FTL";
const char PROGMEM atl_str[] = "ATL";


// ------------------ Helper function declarations ------------------

// JOYSTICK FUNCTIONS
uint8_t press_up(void);

uint8_t press_down(void);

uint8_t press_right(void);

void follow_the_light(void);

void avoid_the_light(void);


void lcd_init(void) {

    LCD_AllSegments(FALSE);  // Clear segment buffer.

    LCD_CONTRAST_LEVEL(LCD_INITIAL_CONTRAST);  // Set the LCD contrast level

    // Select asynchronous clock source, enable all COM pins and enable all
    // segment pins.
    LCDCRB = (1 << LCDCS) | (3 << LCDMUX0) | (7 << LCDPM0);

    // Set LCD prescaler to give a framerate of 32,0 Hz
    LCDFRR = (0 << LCDPS0) | (7 << LCDCD0);

    // Enable LCD and set low power waveform
    LCDCRA = (1 << LCDEN) | (1 << LCDAB);

    //Enable LCD start of frame interrupt
    //LCDCRA |= (1<<LCDIE);  // fixed--don't need this

    //updated 2006-10-10, setting LCD drive time to 1150us in FW rev 07,
    //instead of previous 300us in FW rev 06. Due to some variations on the LCD
    //glass provided to the AVR Butterfly production.
    LCDCCR |= (1 << LCDDC2) | (1 << LCDDC1) | (1 << LCDDC0);

    //gLCD_Update_Required = FALSE;


}


void SetupInterrupts(void) {
    // Setup for Center Button Interrupt

    // Unmask bit for Center Button on Butterfly, PB4->PCINT12 to allow it
    // to trigger interrupt flag PCIF1
    PCMSK1 |= (1 << PCINT12);
    EIMSK = (1 << PCIE1);    //Enable interrupt for flag PCIF1

}

// ISR DEFINITIONS//

ISR(PCINT1_vect) {

    // for storing previous value of port to detect
    static uint8_t pinBPrev = 1;

    // toggle PORTB0 based on center button status being newly pressed, but
    // not when it is released
    if (((PINB & (1 << 4)) == 0) &&
            ((pinBPrev & (1 << 4)) != 0)) {
        //if button pressed (bit is zero) and previous it wasn't
        PORTB ^= (1 << 0);  // toggle led on B0
    }

    pinBPrev = PINB;  // save button status
}

void init_pins(void) {

    // set B6, B7 as inputs, corresponding to the joystick UP and DOWN buttons
    DDRB &= ~(0b11100000);
    // set E2, E3 as inputs, corresponding to the joystick RIGHT button
    DDRE &= ~(0b00001000);

    PORTB |= 0b11100000;  // enable pull up resistors on B5, B6, B7
    PORTE |= 0b00001000;  // enable pull up resistor on pin E2, E3

    // setup output for servo
    DDRB |= (1 << 5);    //enable PORTB5 as output
    DDRB |= (1 << 0);    //enable PORTB0 as output for the first LED
    DDRB |= (1 << 1);    //enable PORTB1 as output for the second LED

    SetupInterrupts();    //setup the interrupts
    sei();                //enable global interrupts

}

void adc_init() {
    // AVR Butteryfly Board Info:
    // The Neg. Temp. Coeff. resistor (NTC)      is on ADC channel 0
    // The Board Edge Voltage Input Reading (VR) is on ADC channel 1
    // The Light Dependant Resistor (LDR)        is on ADC channel 2


    // Disable Digital Input Buffer on pins being used for analog input to save
    // power using the Digital Input Disable Register
    DIDR0 |= 0b00000001; //disable PF0 (ADC0) digital input buffer

    //Select Voltage Reference, Set Left-Ship Option, Set Input Channel
    int refSel_2b = 1;    //select avcc, change to 3 for 1.1V reference
    int adlar_1b = 0;     //no need to left shift
    int muxSel_5b = XYZ;  //select ADC0 with single-ended conversion
    ADMUX = (refSel_2b << REFS0) + (adlar_1b << ADLAR) + (muxSel_5b << MUX0);

    //enable adc and with interrupt disabled
    ADCSRA = (1 << ADEN) + (0 << ADSC) + (0 << ADATE) + (0 << ADIF) + (0
            << ADIE) + (0 << ADPS0);

    //Set auto conversion source
    //ADCSRB &= 0b11111000; //autoconversion (ADATAE) not set so trigger
    // source is not used
}

//Call this function to start an ADC conversion
void ADCStartConversion() {

    ADCSRA |= 1 << ADSC;  // this is automatically cleared

}


void ADCClearConversionFlag() {

    ADCSRA |= (1 << ADIF); // all interrupt flags are cleared by writing a one

}

int ADCIsConversionCompleteFlagSet() {

    return (ADCSRA & (1 << ADIF));

}

// modify this command to return ADC, value.  Hint: you can access it by using
// the macro symbol ADC.  Note, if accessing the high and low bytes
// individually, access ADCL first then ADCH
uint16_t ADCGet() {

    return ADC;

}


int ADCAquire() {

    ADCClearConversionFlag();
    ADCStartConversion();
    while (!ADCIsConversionCompleteFlagSet());
    return ADCGet();

}


uint8_t press_up() {

    return (PORTB & 0b10000000);

}


uint8_t press_down() {

    return (PORTB & 0b01000000);

}


uint8_t press_right() {

    return (PORTE & 0b00001000);

}



// ------------------ Helper function implementations ------------------

/*
 * Main function for the program. Sitting in a loop until terminated by the
 * user, this function acts as the controller for the rest of the program. It
 * prompts users on their choices in the main menu and directs them to the
 * desired functionalities. */
int main() {

    lcd_init();
    adc_init();
    init_pins();

    uint8_t mode;

    while (!press_right()) {

        if (press_up()) {
            mode++;
        } else if (press_down()) {
            mode--;
        }

        if (!(mode % 2)) {
            lcd_puts_P(ftl_str);
        } else {
            lcd_puts_P(atl_str);
        }

        if (press_right) {

            if (!(mode % 2)) {
                avoid_the_light();
            } else {
                follow_the_light();
            }

        }
    }

    return EXIT_SUCCESS;

}
