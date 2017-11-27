//
// Created by sabbir on 11/18/17.
//

#include "lcd_driver.h"


// Look-up table used when converting ASCII to
// LCD display data (segment control)
//__flash unsigned int LCD_character_table[] =
unsigned int LCD_character_table[] = {
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
        0x0000,     // ':' (Not defined)
        0x0000,     // ';' (Not defined)
        0x0000,     // '<' (Not defined)
        0x0000,     // '=' (Not defined)
        0x0000,     // '>' (Not defined)
        0x0000,     // '?' (Not defined)
        0x0000,     // '@' (Not defined)
        0x0f51,     // 'A' (+ 'a')
        0x3991,     // 'B' (+ 'b')
        0x1441,     // 'C' (+ 'c')
        0x3191,     // 'D' (+ 'd')
        0x1e41,     // 'E' (+ 'e')
        0x0e41,     // 'F' (+ 'f')
        0x1d41,     // 'G' (+ 'g')
        0x0f50,     // 'H' (+ 'h')
        0x2080,     // 'I' (+ 'i')
        0x1510,     // 'J' (+ 'j')
        0x8648,     // 'K' (+ 'k')
        0x1440,     // 'L' (+ 'l')
        0x0578,     // 'M' (+ 'm')
        0x8570,     // 'N' (+ 'n')
        0x1551,     // 'O' (+ 'o')
        0x0e51,     // 'P' (+ 'p')
        0x9551,     // 'Q' (+ 'q')
        0x8e51,     // 'R' (+ 'r')
        0x9021,     // 'S' (+ 's')
        0x2081,     // 'T' (+ 't')
        0x1550,     // 'U' (+ 'u')
        0x4448,     // 'V' (+ 'v')
        0xc550,     // 'W' (+ 'w')
        0xc028,     // 'X' (+ 'x')
        0x2028,     // 'Y' (+ 'y')
        0x5009,     // 'Z' (+ 'z')
        0x0000,     // '[' (Not defined)
        0x0000,     // '\' (Not defined)
        0x0000,     // ']' (Not defined)
        0x0000,     // '^' (Not defined)
        0x0000      // '_'
};


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
void LCD_Init(void) {

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
void LCD_WriteDigit(char c, char digit) {

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

        seg = LCD_character_table[c];
    }

    // Adjust mask according to LCD segment mapping
    if (digit & 0x01) {
        mask = 0x0F;  // Digit 1, 3, 5
    } else {  // Digit 0, 2, 4
        mask = 0xF0;
    }

    //ptr = LCD_Data + (digit >> 1);  // digit = {0,0,1,1,2,2}
    ptr = pLCDREG + (digit >> 1);  // digit = {0,0,1,1,2,2}

    for (i = 0; i < 4; i++) {
        nibble = seg & 0x000F;
        seg >>= 4;
        if (digit & 0x01)
            nibble <<= 4;
        *ptr = (*ptr & mask) | nibble;
        ptr += 5;
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
void LCD_AllSegments(char show) {

    unsigned char i;

    if (show) {
        show = 0xFF;
    }

    // Set/clear all bits in all LCD registers
    for (i = 0; i < LCD_REGISTER_COUNT; i++) {
        *(pLCDREG + i) = show;
    }

}
