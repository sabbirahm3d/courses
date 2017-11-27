/*
 * main.c
 *
 * Driver file for Homework 4: Follow the Light. This script contains the
 * declarations and implementations of the ADC driver, LCD interface, menu
 * functions and other functions to handle user inputs and outputs (I/O).
 *
 */

// standard libraries
#include <stdlib.h>

// AVR libraries
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// ------------------ FUNCTION PROTOTYPES ------------------
#define LCD_REGISTER_COUNT 20

#define LCD_INITIAL_CONTRAST 0x0F

// LCD Data Register 0    // DEVICE SPECIFIC!!! (ATmega169)
#define pLCDREG ((unsigned char *)(0xEC))

// DEVICE SPECIFIC!!! (ATmega169) First LCD segment register
#define LCD_CONTRAST_LEVEL(level) LCDCCR = ((LCDCCR & 0xF0) | (0x0F & (level)))

//Functions
void lcd_init(void);

void lcd_write_digit(char, int);  // digit can be 0 to 5

void lcd_all_segs(unsigned char);


void adc_init();

void adc_start_flag();

void adc_clear_flag();

int adc_is_set_flag();

uint16_t get_adc();


// JOYSTICK FUNCTIONS
uint8_t press_up(void);

uint8_t press_down(void);

uint8_t press_right(void);

// SERVO FUNCTIONS
void follow_the_light(void);

void avoid_the_light(void);

// HELPER FUNCTIONS

uint8_t max3(uint8_t, uint8_t, uint8_t);


// --- constant strings stored in the program space for repeated use ---
// strings to build menus
const char PROGMEM FLTSTR[] = "FTL";
const char PROGMEM ATLSTR[] = "ATL";
uint8_t INITADC;

// Look-up table used when converting ASCII to
// LCD display data (segment control)
unsigned int LCDCHARTABLE[] = {
        0x5559,     // '0'
        0x0118,     // '1'
        0x1e11,     // '2
        0x1b11,     // '3
        0x0b50,     // '4
        0x1b41,     // '5
        0x1f41,     // '6
        0x0111,     // '7
        0x1f51,     // '8
        0x1b51,     // '9'
        0x0f51,     // 'A' (+ 'a')
        0x0e41,     // 'F' (+ 'f')
        0x1440,     // 'L' (+ 'l')
        0x2081     // 'T' (+ 't')
};


// ------------------ Helper function implementations ------------------

/*****************************************************************************
*
*   Function name : LCD_Init
*
*   Returns :       None
*
*   Parameters :    None
*
*   Purpose :       Initialize LCD_displayData buffer.
*                   Set up the LCD (timing, contrast, etc.)
*
*****************************************************************************/
void lcd_init() {

    lcd_all_segs(0);  // Clear segment buffer.

    LCD_CONTRAST_LEVEL(LCD_INITIAL_CONTRAST);  // Set the LCD contrast level

    // Select asynchronous clock source, enable all COM pins and enable all
    // segment pins.
    LCDCRB = (1 << LCDCS) | (3 << LCDMUX0) | (7 << LCDPM0);

    // Set LCD prescaler to give a framerate of 32,0 Hz
    LCDFRR = (0 << LCDPS0) | (7 << LCDCD0);

    // Enable LCD and set low power waveform
    LCDCRA = (1 << LCDEN) | (1 << LCDAB);

    // updated 2006-10-10, setting LCD drive time to 1150us in FW rev 07,
    // instead of previous 300us in FW rev 06. Due to some variations on the
    // LCD glass provided to the AVR Butterfly production.
    LCDCCR |= (1 << LCDDC2) | (1 << LCDDC1) | (1 << LCDDC0);

}


/*****************************************************************************
*
*   Function name : LCD_WriteDigit(char c, char digit)
*
*   Returns :       None
*
*   Parameters :    Inputs
*                   c: The symbol to be displayed in a LCD digit
*                   digit: In which digit (0-5) the symbol should be displayed
*                   Note: Digit 0 is the first used digit on the LCD,
*                   i.e LCD digit 2
*
*   Purpose :       Stores LCD control data in the LCD_displayData buffer.
*                   (The LCD_displayData is latched in the LCD_SOF interrupt.)
*
*****************************************************************************/
void lcd_write_digit(char c, int digit) {

    unsigned int seg = 0x0000;                  // Holds the segment pattern
    char mask, nibble;
    char *ptr;
    char i;


    if (digit > 5)                              // Skip if digit is illegal
        return;

    //Lookup character table for segmet data
    if ((c >= '*') && (c <= 'z')) {
        // c is a letter
        if (c >= 'a')                           // Convert to upper case
            c &= ~0x20;                         // if necessarry

        c -= '*';

        seg = LCDCHARTABLE[c];
    }

    // Adjust mask according to LCD segment mapping
    if (digit & 0x01) {

        mask = 0x0F; // Digit 1, 3, 5

    } else {  // Digit 0, 2, 4

        mask = 0xF0;

    }

    //ptr = LCD_Data + (digit >> 1);  // digit = {0,0,1,1,2,2}
    ptr = (char *) pLCDREG + (digit >> 1);  // digit = {0,0,1,1,2,2}

    for (i = 0; i < 4; i++) {
        nibble = seg & 0x000F;
        seg >>= 4;
        if (digit & 0x01)
            nibble <<= 4;
        *ptr = (*ptr & mask) | nibble;
        ptr += 5;
    }
}


void lcd_puts_P(const char c[]) { //same const char *c

    uint8_t ch = pgm_read_byte(c);

    int location = 0;

    while (ch != 0) {
        lcd_write_digit(ch, location);
        ch = pgm_read_byte(++c);
        location++;
    }

}

/*****************************************************************************
*
*   Function name : LCD_AllSegments(unsigned char input)
*
*   Returns :       None
*
*   Parameters :    show -  [TRUE;FALSE]
*
*   Purpose :       shows or hide all all LCD segments on the LCD
*
*****************************************************************************/
void lcd_all_segs(unsigned char show) {

    unsigned char i;

    if (show){
        show = 0xFF;
    }

    // Set/clear all bits in all LCD registers
    for (i = 0; i < LCD_REGISTER_COUNT; i++){
        *(pLCDREG + i) = show;
    }
}


void interrupts_init(void) {
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
    if (((PINB & (1 << 4)) == 0) && ((pinBPrev & (1 << 4)) != 0)) {
        // if button pressed (bit is zero) and previous it wasn't
        PORTB ^= (1 << 0);  // toggle led on B0
    }

    pinBPrev = PINB;  // save button status
}

void pins_init(void) {

    // set B6, B7 as inputs, corresponding to the joystick UP and DOWN buttons
    DDRB &= ~(0b11100000);
    // set E2, E3 as inputs, corresponding to the joystick RIGHT button
    DDRE &= ~(0b00001000);

    PORTB |= 0b11100000;  // enable pull up resistors on B5, B6, B7
    PORTE |= 0b00001000;  // enable pull up resistor on pin E2, E3

    // setup output for servo
    DDRB |= (1 << 5);    // enable PORTB5 as output
    DDRB |= (1 << 0);    // enable PORTB0 as output for the first LED
    DDRB |= (1 << 1);    // enable PORTB1 as output for the second LED

    interrupts_init();    // setup the interrupts
    sei();                // enable global interrupts

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
    int muxSel_5b = 5;  //select ADC0 with single-ended conversion
    ADMUX = (uint8_t) (refSel_2b << REFS0) + (adlar_1b << ADLAR) + (muxSel_5b
            << MUX0);

    //enable adc and with interrupt disabled
    ADCSRA = (1 << ADEN) + (0 << ADSC) + (0 << ADATE) + (0 << ADIF) + (0
            << ADIE) + (0 << ADPS0);

    //Set auto conversion source
    //ADCSRB &= 0b11111000; //autoconversion (ADATAE) not set so trigger
    // source is not used
}

//Call this function to start an ADC conversion
void adc_start_flag() {

    ADCSRA |= 1 << ADSC;  // this is automatically cleared

}


void adc_clear_flag() {

    ADCSRA |= (1 << ADIF); // all interrupt flags are cleared by writing a one

}

int adc_is_set_flag() {

    return (ADCSRA & (1 << ADIF));

}

// modify this command to return ADC, value.  Hint: you can access it by using
// the macro symbol ADC.  Note, if accessing the high and low bytes
// individually, access ADCL first then ADCH
uint16_t get_adc() {

    return ADC;

}


int adc_acquire() {

    adc_clear_flag();
    adc_start_flag();
    while (!adc_is_set_flag());
    return get_adc();

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

void move_servo(int degrees) {

    PORTB &= (degrees & 0b00010000);

}

uint8_t max3(uint8_t a, uint8_t b, uint8_t c) {

    uint8_t m = a;
    (void) ((m < b) && (m = b)); //these are not conditional statements.
    (void) ((m < c) && (m = c)); //these are just boolean expressions.
    return m;

}

void follow_the_light() {

    uint8_t angle_prev, angle_next;

    move_servo(-10);
    angle_prev = get_adc();
    _delay_ms(500);

    move_servo(20);
    angle_next = get_adc();
    _delay_ms(500);

    // local sweep
    uint8_t optimal_angle = max3(INITADC, angle_prev, angle_next);
    lcd_puts_P((char *) optimal_angle);

    // full sweep
    while (get_adc() < optimal_angle) {
        _delay_ms(500);
        move_servo(20);
    }


}

//
void avoid_the_light() {

    uint8_t angle_prev, angle_next;

    move_servo(-10);
    angle_prev = get_adc();
    _delay_ms(500);

    move_servo(20);
    angle_next = get_adc();
    _delay_ms(500);

    // local sweep
    uint8_t optimal_angle = max3(INITADC, angle_prev, angle_next);
    lcd_puts_P((char *) optimal_angle);

    // full sweep
    while (get_adc() > optimal_angle) {
        _delay_ms(500);
        move_servo(20);
    }


}


/*
 * Main function for the program. Sitting in a loop until terminated by the
 * user, this function acts as the controller for the rest of the program. It
 * prompts users on their choices in the main menu and directs them to the
 * desired functionalities. */
int main() {

    lcd_init();
    adc_init();
    pins_init();

	lcd_puts_P(FLTSTR);
    uint8_t mode = 0;

    while (!press_right()) {

        if (press_up()) {
            mode++;
        } else if (press_down()) {
            mode--;
        }

        (mode % 2) ? lcd_puts_P(FLTSTR) : lcd_puts_P(ATLSTR);

    }

    // pressing right breaks out of the loop
    (mode % 2) ? follow_the_light() : avoid_the_light();

    return EXIT_SUCCESS;

}
