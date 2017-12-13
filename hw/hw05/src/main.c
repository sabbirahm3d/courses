/*
 * main.c
 *
 * Driver file for Homework 5: 777 for 7s. This script contains the
 * declarations and implementations of the LCD interface, menu functions and
 * other functions to handle user inputs and outputs (I/O).
 *
 */


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
#define LCDREGCNT 20
#define LCDINITCONTRAST 0x0F
#define pLCDREG ((unsigned char *)(0xEC))  // LCD Data Register 0
// First LCD segment register
#define LCDCONTRASTLEVEL(level) LCDCCR = ((LCDCCR & 0xF0) | (0x0F & (level)))

const char PROGMEM WELCOMESTR[] = "HELLO";
const char PROGMEM BAC[] = "BAC";
const char PROGMEM CAF[] = "CAF";
const char PROGMEM DEF[] = "DEF";
const char PROGMEM FAB[] = "FAB";
const char PROGMEM FAE[] = "FAE";
const char PROGMEM FAC[] = "FAC";
const char PROGMEM ADC_str[] = "ADC";
const char PROGMEM CAD[] = "CAD";
const char PROGMEM DAE[] = "DAE";
const char PROGMEM DEB[] = "DEB";
const char PROGMEM FEB[] = "FEB";
const char PROGMEM CAB[] = "CAB";
const char PROGMEM FAD[] = "FAD";
const char PROGMEM FDA[] = "FDA";
const char PROGMEM ACE[] = "ACE";
const char PROGMEM BAD[] = "BAD";
const char PROGMEM BED[] = "BED";
const char PROGMEM DAB[] = "DAB";
const char PROGMEM FED[] = "FED";


char *WORD;
int WALLET = 10;
int BET = 1;

// initial ADC value
uint8_t INITADC;

// truncated look-up table used when converting ASCII to LCD display data
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
        0x2081      // 'T' (+ 't')
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

// ------------------ LCD FUNCTIONS ------------------

void lcd_init(void);

void lcd_write_digit(char, int);  // digit can be 0 to 5

void lcd_all_segs(unsigned char);

void lcd_puts_P(const char[]);

// ------------------ ADC FUNCTIONS ------------------

void adc_init();

void adc_start_flag();

void adc_clear_flag();

int adc_is_set_flag();

uint16_t get_adc();

// ------------------ JOYSTICK FUNCTIONS ------------------

uint8_t press_up(void);

uint8_t press_down(void);

uint8_t press_right(void);

// ------------------ SERVO FUNCTIONS ------------------

void follow_the_light(void);

void avoid_the_light(void);

// ------------------ HELPER FUNCTIONS ------------------

uint8_t max3(uint8_t, uint8_t, uint8_t);


// ------------------ FUNCTION IMPLEMENTATIONS ------------------


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


void increase_bet() {

    if (BET < 9) {
        BET++;
    }

}

void reset() {

    BET = 1;
    WALLET = 10;

}


void slot_machine_screen() {

    lcd_puts_P("%d AAA");


}

void earnings_screen() {

    if (WALLET > 0) {
        lcd_puts_P(WALLET);
    } else {
        lcd_puts_P("LOSE");
    }

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
 * Returns status of JOYSTICK RIGHT
 */
uint8_t push_button() {

    return (PORTE & 0b00001000);

}


uint8_t multiplier(char *word) {

    if (!strcmp(word, BAC) || !strcmp(word, CAF) || !strcmp(word, DEF)
            || !strcmp(word, FAB) || !strcmp(word, FAE)
            || !strcmp(word, FAC)) {

        return 1;

    } else if (!strcmp(word, ADC_str) || !strcmp(word, CAD) ||
            !strcmp(word, DAE) || !strcmp(word, DEB)
            || !strcmp(word, FEB)) {

        return 2;

    } else if (!strcmp(word, CAB) || !strcmp(word, FAD)
            || !strcmp(word, FDA)) {

        return 3;

    } else if (!strcmp(word, ACE) || !strcmp(word, BAD)) {

        return 4;

    } else if (!strcmp(word, BED) || !strcmp(word, DAB)
            || !strcmp(word, FED)) {

        return 5;

    } else {

        return 0;

    }


}


uint8_t spin() {

//    demo stuff
////////////////////////////

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
///////////////////////////

    uint8_t j = 0, k = 0;
    WORD = (char *) malloc((4 * sizeof(char)));
    for (unsigned int i = 0; i < 100; i++)
        for (char c = 'A'; c <= 'F'; ++c) {
            _delay_ms(10);
            if (k < 3 && (j % 50) == r) {
                printf("%c\n", c);
                WORD[k] = c;
                k++;
            }
            if (k == 3) {
                break;
            }
            j++;
        }


    WORD[3] = '\0';
    printf("SLOT: %s\n", WORD);

    int spin_result = multiplier(WORD);

    if (spin_result) {
        WALLET = WALLET - BET + (spin_result * BET);
    } else {
        WALLET -= BET;
    }

}


/*
 * Displays the main menu to the user and prompts for their input. The
 * function then returns the user's input to be treated as their choice from
 * the main menu prompt. */
uint8_t welcome_screen() {

    int choice;
    char user_line[20];

    if (push_button()) {
        return 1;
    } else if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%d", &choice);
    }

    return (uint8_t) choice;

}


uint8_t which_button() {

    if (!GAMBLE) {
        printf(WELCOMESTR);
    }

    return welcome_screen();

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
