//
// Created by sabbir on 11/26/17.
//

//comment out the following line if not using the bootloader
//#define USING_BOOTLOADER


//set F_CPU if not set already, dependent on use of boot loader
#ifndef F_CPU

#ifdef USING_BOOTLOADER
#define F_CPU 2000000UL
#else
#define F_CPU 8000000UL
#endif

#endif


#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "lcd_driver.h"


//////////////
//globals   //
//////////////


//////////////
//prototypes//
//////////////
void interrupts_init(void);

void BootLoaderFixes(void);

void PlayA(void);


////////
//MAIN//
////////
int main(void) {

#ifdef USING_BOOTLOADER
    BootLoaderFixes();
#endif

    /* Initialize and Clear the LCD */
    lcd_init();
    LCD_WriteDigit('N', 5);

    //Setup All Pushbuttons
    DDRB &= ~0b11010000;  //set B4, B6, B7 as inputs
    DDRE &= ~0b00001100;  //set all to inputs

    PORTB |= 0b11010000;  //enable pull up resistors on B4,B6,B7
    PORTE |= 0b00001100;  //enable pull up resistor on pin E2,E3

    //Setup Output for Music
    DDRB |= (1 << 5);    //enable PORTB5 as output
    DDRB |= (1 << 0);    //enable PORTB0 as output for the first LED
    DDRB |= (1 << 1);    //enable PORTB1 as output for the second LED

    interrupts_init();    //setup the interrupts
    sei();                //enable global interrupts

    PlayA();            // play A when program starts running

    // flash led on pin B1 every second
    for (;;) {
        PORTB ^= (1 << 1);
        _delay_ms(1000);
    }

}

////////////////////////
//Function Definitions//
////////////////////////


void interrupts_init(void) {
    // Setup for Center Button Interrupt

    // Unmask bit for Center Button on Butterfly, PB4->PCINT12 to allow it
    // to trigger interrupt flag PCIF1
    PCMSK1 |= (1 << PCINT12);
    EIMSK = (1 << PCIE1);    //Enable interrupt for flag PCIF1
}


//This performs adjustments needed to undo actions of Butterfly boot loader
void BootLoaderFixes(void) {
    // Boot loader Disables E2 and E3 digital input drivers, which are used
    // for left and right
    // The following code re-enables them by clearing the appropriate disable
    // bits
    DIDR1 &= ~((1 << AIN0D) | (1 << AIN1D));
}


////////////////////
// ISR DEFINITIONS//
////////////////////

// remember this is called on pin change 0->1 and 1->0
ISR(PCINT1_vect) {

    // for storing previous value of port to detect
    static uint8_t pinBPrev = 1;

    PlayA(); // play note every time interrupt is called

    //toggle PORTB0 based on center button status being newly pressed, but
    // not when it is released
    if (((PINB & (1 << 4)) == 0) &&
            ((pinBPrev & (1 << 4)) != 0)) {
        //if button pressed (bit is zero) and previous it wasn't
        PORTB ^= (1 << 0); //toggle led on B0
        LCD_WriteDigit('C', 5);
    } else {
        //do nothing
    }

    pinBPrev = PINB; //save button status
}


void PlayA() {

    for (uint8_t i = 0; i < 110; ++i) {
        PORTB ^= (1 << 5);            //toggle PORTB5
        _delay_us(500);
        _delay_us(500);
        _delay_us(136);
    }

}

