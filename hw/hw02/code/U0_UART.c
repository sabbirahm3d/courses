#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "U0_UART.h"

/* Assign I/O stream to UART */
FILE uart_stream = FDEV_SETUP_STREAM(UARTPutch, UARTGetch, _FDEV_SETUP_RW);

void UARTInit(void) {

    // BAUD RATE of 4800 for 8Mhz
    // UBRRH = 0;
    // UBRRL = 103;
    UBRRH = (((F_CPU / BAUD_RATE) / 16) - 1) >> 8;  // set baud rate
    UBRRL = (((F_CPU / BAUD_RATE) / 16) - 1);


    UCSRA = 0;  //clearing all flags


    UCSRB = (1 << RXEN0) | (1 << TXEN0);
    /* Enable Tx and Rx */
    //  UCSRB = (1<<RXEN)|(1<<TXEN);


    // UCSR0C =(1<<USBS0)|(3<<UCSZ00);
    /* Set Frame: Data 8 Bit, No Parity and 2 Stop Bit */
    UCSRC = (1 << USBS0) | (3 << UCSZ00);

}

int SerialPutch(char ch) {

    while (!(UCSRA & (1 << UDRE)));  // loop until bit is set
    UDR = ch;

    return 0;
}

int UARTPutch(char ch, FILE *stream) {

    if (ch == '\n')
        UARTPutch('\r', stream);

    while (!(UCSRA & (1 << UDRE)));  // loop until bit is set
    UDR = ch;

    return 0;

}

int UARTGetch(FILE *stream) {

    unsigned char ch;

    while (!(UCSRA & (1 << RXC)));  // loop until bit is set
    ch = UDR;

    /* Echo the output back to the terminal */
    UARTPutch(ch, stream);

    return ch;
}
