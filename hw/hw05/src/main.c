/*
 * main.c
 *
 * Driver file for Homework 5: 777 for 7s. This script contains the
 * declarations and implementations of the LCD interface, menu functions and
 * other functions to handle user inputs and outputs (I/O).
 *
 */

// standard libraries
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>


// AVR libraries
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>


// ------------------ CONSTANTS ------------------
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define PORTB5_MASK  0b00100000
#define MIN_PULSE_WIDTH 10
#define LCDREGCNT 20
#define LCDINITCONTRAST 0x0F
#define pLCDREG ((unsigned char *)(0xEC))  // LCD Data Register 0
// First LCD segment register
#define LCDCONTRASTLEVEL(level) LCDCCR = ((LCDCCR & 0xF0) | (0x0F & (level)))

const char PROGMEM WELCOMESTR[] = "HELLO";
// slot words with multipliers stored in program memory
const char PROGMEM BACSTR[] = "BAC";
const char PROGMEM CAFSTR[] = "CAF";
const char PROGMEM DEFSTR[] = "DEF";
const char PROGMEM FABSTR[] = "FAB";
const char PROGMEM FAESTR[] = "FAE";
const char PROGMEM FACSTR[] = "FAC";
const char PROGMEM ADCSTR[] = "ADC";
const char PROGMEM CADSTR[] = "CAD";
const char PROGMEM DAESTR[] = "DAE";
const char PROGMEM DEBSTR[] = "DEB";
const char PROGMEM FEBSTR[] = "FEB";
const char PROGMEM CABSTR[] = "CAB";
const char PROGMEM FADSTR[] = "FAD";
const char PROGMEM FDASTR[] = "FDA";
const char PROGMEM ACESTR[] = "ACE";
const char PROGMEM BADSTR[] = "BAD";
const char PROGMEM BEDSTR[] = "BED";
const char PROGMEM DABSTR[] = "DAB";
const char PROGMEM FEDSTR[] = "FED";


char *WORD;
int WALLET = 10;
int BET = 1;
int GAMBLE = 0;

// initial ADC value
uint8_t INITADC;

// truncated look-up table used when converting ASCII to LCD display data
unsigned int LCDCHARTABLE[] = {
        0x0A51,     // '*' (?)
        0x2A80,     // '+'
        0x0000,     // ',' (Not defined)
        0x0A00,     // '-'
        0x0A51,     // '.' Degree sign
        0x0000,     // '/' (Not defined)
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
        0x3991,     // 'B' (+ 'b')
        0x1441,     // 'C' (+ 'c')
        0x3191,     // 'D' (+ 'd')
        0x1e41,     // 'E' (+ 'e')
        0x0e41,     // 'F' (+ 'f')
        0x0f50,     // 'H' (+ 'h')
        0x1440,     // 'L' (+ 'l')
        0x1551,     // 'O' (+ 'o')
        0x9021,     // 'S' (+ 's')
};


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

// ------------------ FUNCTION PROTOTYPES ------------------

// ------------------ BUZZER FUNCTIONS ------------------

void MusicSetupPort(void);

void MusicRest(void);

void MusicPlayA(void);

void MusicSetupTimer1(void);

void MusicSetNote(int);

// ------------------ LCD FUNCTIONS ------------------

void lcd_init(void);

void lcd_write_digit(char, int);  // digit can be 0 to 5

void lcd_all_segs(unsigned char);

void lcd_puts_P(const char[]);

// ------------------ JOYSTICK FUNCTIONS ------------------

uint8_t which_button(void);

uint8_t press_up(void);

uint8_t press_down(void);

uint8_t press_right(void);

uint8_t press_left(void);

uint8_t push_button(void);

// ------------------ MENU FUNCTIONS ------------------
void increase_bet(void);

void reset(void);

void slot_machine_screen(void);

void earnings_screen(void);

uint8_t multiplier(char *);

void spin(void);

void welcome_screen(void);

// ------------------ HELPER FUNCTIONS ------------------

uint8_t max3(uint8_t, uint8_t, uint8_t);


// ------------------ FUNCTION IMPLEMENTATIONS ------------------


void MusicSetupPort() {
    DDRB |= PORTB5_MASK; //enable PORTB5 as output
}

void MusicSetNote(int period_us) {
    ICR1 = period_us / 2;
    OCR1A = period_us / 4;
    TCNT1 = 0;
}

void MusicRest() {
    OCR1A = 0;
};

void MusicPlayA() {
    MusicSetNote(2272);
    MusicRest();
}

void MusicSetupTimer1() {
    /* Timer/Counter1 Control Register A */
    int value_TCCR1A_COM1A_2b = 2; //clear on match up, set on match down
    int value_TCCR1A_COM1B_2b = 0; //disable
    //this one is spread over both regsters
    int value_TCCR1AB_WGM1_4b = 8; //PWM+frequency control using register ICR1
    /* Timer/Counter1 Control Register B */
    int value_TCCR1B_ICNC1_1b = 0; //no input capture noise cancel
    int value_TCCR1B_ICES1_1b = 0; //Dont Care since not used
    int value_TCCR1B_CS1_3b = 2; //use clock prescaler 8
    TCCR1A = (value_TCCR1A_COM1A_2b << COM1A0) + (value_TCCR1A_COM1B_2b
            << COM1B0) + ((value_TCCR1AB_WGM1_4b & 0x3) << WGM10);
    TCCR1B = (value_TCCR1B_ICNC1_1b << ICNC1) + (value_TCCR1B_ICES1_1b
            << ICES1) + (((value_TCCR1AB_WGM1_4b & 0b00001100) >> 2)
            << WGM12) + (value_TCCR1B_CS1_3b << CS10);

    /* Timer/Counter1 Input Capture Register */
    //also used for frequency setting
    ICR1 = 0xFF / 2; //16 bits //just some initial value



    /* Timer/Counter 1 Interrupt Mask Register */
    int value_TIMSK1_ICIE1_1b = 0;//input capture int. enable
    int value_TIMSK1_OCIE1B_1b = 0;//output compare int. enable
    int value_TIMSK1_OCIE1A_1b = 0;//output compare int. enable
    int value_TIMSK1_TOIE1_1b = 0;//overflow int. enable
    TIMSK1 = (value_TIMSK1_ICIE1_1b << ICIE1) + (value_TIMSK1_OCIE1B_1b
            << OCIE1B) + (value_TIMSK1_OCIE1A_1b << OCIE1A) + (
            value_TIMSK1_TOIE1_1b << TOIE1);
}


/*
 * Initialize LCD_displayData buffer. Set up the LCD (timing, contrast, etc.)
 */
void lcd_init() {

    // clear segment buffer
    lcd_all_segs(0);

    // set the LCD contrast level
    LCDCONTRASTLEVEL(LCDINITCONTRAST);

    // select asynchronous clock source, enable all COM pins and enable all
    // segment pins.
    LCDCRB = (1 << LCDCS) | (3 << LCDMUX0) | (7 << LCDPM0);

    // set LCD prescaler to give a framerate of 32,0 Hz
    LCDFRR = (0 << LCDPS0) | (7 << LCDCD0);

    // enable LCD and set low power waveform
    LCDCRA = (1 << LCDEN) | (1 << LCDAB);

    // updated 2006-10-10, setting LCD drive time to 1150us in FW rev 07,
    // instead of previous 300us in FW rev 06. Due to some variations on the
    // LCD glass provided to the AVR Butterfly production.
    LCDCCR |= (1 << LCDDC2) | (1 << LCDDC1) | (1 << LCDDC0);

}


/*
 * Stores LCD control data in the LCD_displayData buffer. (The LCD_displayData
 * is latched in the LCD_SOF interrupt.)
 */
void lcd_write_digit(char c, int digit) {

    unsigned int seg = 0x0000;  // holds the segment pattern
    char mask, nibble;
    char *ptr;
    char i;

    // skip if digit is illegal
    if (digit > 5) {
        return;
    }

    // lookup character table for segment data
    if ((c >= '*') && (c <= 'z')) {  // c is a letter
        // convert to upper case  if necessarry
        if (c >= 'a') {
            c &= ~0x20;
        }
        c -= '*';
        seg = LCDCHARTABLE[c];
    }

    // adjust mask according to LCD segment mapping
    if (digit & 0x01) {
        // digit 1, 3, 5
        mask = 0x0F;
    } else {
        // digit 0, 2, 4
        mask = 0xF0;
    }

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


/*
 * Flushes char arrays to LCD
 */
void lcd_puts_P(const char c[]) {

    uint8_t ch = pgm_read_byte(c);

    int location = 0;

    while (ch != 0) {
        lcd_write_digit(ch, location);
        ch = pgm_read_byte(++c);
        location++;
    }

}


/*
 * Shows or hide all all LCD segments on the LCD
 */
void lcd_all_segs(unsigned char show) {

    unsigned char i;

    if (show) {
        show = 0xFF;
    }

    // Set/clear all bits in all LCD registers
    for (i = 0; i < LCDREGCNT; i++) {
        *(pLCDREG + i) = show;
    }
}


/*
 * Initializes all interrupts utlitized in the program
 */
void interrupts_init(void) {
    // setup for center button interrupt

    // unmask bit for Center Button on Butterfly, PB4->PCINT12 to allow it
    // to trigger interrupt flag PCIF1
    PCMSK1 |= (1 << PCINT12);
    EIMSK = (1 << PCIE1);    // enable interrupt for flag PCIF1

}


/*
 * Initializes all pins utlitized in the program
 */
void pins_init(void) {

    // set B6, B7 as inputs, corresponding to the joystick UP and DOWN buttons
    DDRB &= ~(0b11100000);
    // set E2, E3 as inputs, corresponding to the joystick RIGHT button
    DDRE &= ~(0b00001000);

    // enable pull up resistors on B5, B6, B7
    PORTB |= 0b11100000;
    // enable pull up resistor on pin E2, E3
    PORTE |= 0b00001000;

    // setup output for servo
    // enable PORTB5 as output
    DDRB |= (1 << 5);
    // enable PORTB0 as output for the first LED
    DDRB |= (1 << 0);
    // enable PORTB1 as output for the second LED
    DDRB |= (1 << 1);

    // setup the interrupts
    interrupts_init();
    // enable global interrupts
    sei();

}

/*
 * Increases bet of the user up to the maximum
 */
void increase_bet() {

    if ((BET < 9) && (BET < WALLET)) {
        BET++;
    }

}

/*
 * Resets all values and states of the user
 */
void reset() {

    BET = 1;
    WALLET = 10;

}

/*
 * Displays current bet amount of user and the slot machine slots
 */
void slot_machine_screen() {

    lcd_puts_P("%d AAA");


}

/*
 * Displays the earning screen if the user has any, else ends game
 */
void earnings_screen() {

    if (WALLET > 0) {
        lcd_puts_P(WALLET);
    } else {
        lcd_puts_P("LOSE");
    }

}

/*
 * Assigns user inputs to integers for convenient option management
 */
uint8_t which_button() {

    if (!GAMBLE) {
        lcd_puts_P(WELCOMESTR);
    }

    if (push_button()) {
        return 1;
    } else if (press_up()) {
        return 2;
    } else if (press_down()) {
        return 3;
    } else if (press_left()) {
        return 4;
    } else if (press_right()) {
        return 5;
    }

    welcome_screen();

}


/*
 * Returns status of JOYSTICK UP
 */
uint8_t press_up() {

    return (PORTB & 0b10000000);

}


/*
 * Returns status of JOYSTICK DOWN
 */
uint8_t press_down() {

    return (PORTB & 0b01000000);

}


/*
 * Returns status of JOYSTICK RIGHT
 */
uint8_t press_right() {

    return (PORTE & 0b00001000);

}

/*
 * Returns status of JOYSTICK LEFT
 */
uint8_t press_left() {

    return (PORTE & 0b00001000);

}

/*
 * Returns status of JOYSTICK RIGHT
 */
uint8_t push_button() {

    return (PORTE & 0b00001000);

}


/*
 * Returns multiplier of the word the slots landed on
 */
uint8_t multiplier(char *word) {

    if (!strcmp(word, BACSTR) || !strcmp(word, CAFSTR) || !strcmp(word, DEFSTR)
            || !strcmp(word, FABSTR) || !strcmp(word, FAESTR)
            || !strcmp(word, FACSTR)) {

        return 1;

    } else if (!strcmp(word, ADCSTR) || !strcmp(word, CADSTR) ||
            !strcmp(word, DAESTR) || !strcmp(word, DEBSTR)
            || !strcmp(word, FEBSTR)) {

        return 2;

    } else if (!strcmp(word, CABSTR) || !strcmp(word, FADSTR)
            || !strcmp(word, FDASTR)) {

        return 3;

    } else if (!strcmp(word, ACESTR) || !strcmp(word, BADSTR)) {

        return 4;

    } else if (!strcmp(word, BEDSTR) || !strcmp(word, DABSTR)
            || !strcmp(word, FEDSTR)) {

        return 5;

    } else {

        return 0;

    }

}

/*
 * "Spins" the 3 character word to simulate a slot machine. Each of the slots
 * spin at different rates. The spinning halts per character after subsequent
 * push button interrupts are generated. The final word is then passed in to
 * the multiplier() function to determine its multiplier and recalculate the
 * global bet amount.
 */
void spin() {

    void delay(int number_of_seconds) {
        // Converting time into milli_seconds
        int milli_seconds = 1000 * number_of_seconds;

        // Stroing start time
        clock_t start_time = clock();

        // looping till required time is not achieved
        while (clock() < start_time + milli_seconds);
    }
    srand(time(NULL));
    int r = rand() % 50;

    uint8_t j = 0, k = 0;
    WORD = (char *) malloc((4 * sizeof(char)));
    for (unsigned int i = 0; i < 100; i++)
        // print from 'A' to 'F'
        for (char c = 'A'; c <= 'F'; ++c) {
            _delay_ms(10);
            if (k < 3 && (j % 50) == r) {
                lcd_puts_P(c);
                WORD[k] = c;
                k++;
            }
            if (k == 3) {
                break;
            }
            j++;
        }


    WORD[3] = '\0';
    lcd_puts_P(WORD);

    int spin_result = multiplier(WORD);

    if (spin_result) {
        WALLET = WALLET - BET + (spin_result * BET);
    } else {
        WALLET -= BET;
    }

}


/*
 * Displays the welcome screen 
 */
void welcome_screen() {

    if (push_button()) {
        return 1;
    }

}


/*
 * Main function for the program. Sitting in a loop until terminated by the
 * user, this function acts as the controller for the rest of the program. It
 * prompts users on their choices in the main menu and directs them to the
 * desired functionalities.
 */
int main() {

    uint8_t loop_flag = 1;
    uint8_t btn_pressed = 0;

    while (loop_flag) {

        btn_pressed = which_button();

        switch (btn_pressed) {

            // push button
            case 1: {
                spin();
                break;
            }

                // up button
            case 2: {
                increase_bet();
                slot_machine_screen();
                break;
            }

                // down button
            case 3: {
                reset();
                slot_machine_screen();
                break;
            }

                // left button
            case 4: {
                earnings_screen();
                break;
            }

                // right button
            case 5: {
                slot_machine_screen();
                break;
            }

            case 0: {
                loop_flag = 0;
                free(WORD);
                break;
            }

            default: {
                break;
            }
        }


    }

    return EXIT_SUCCESS;

}
