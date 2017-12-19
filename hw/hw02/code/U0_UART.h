#ifndef U0_UART_h
#define U0_UART_h

#include <avr/io.h>
#include <stdio.h>


#define BAUD_RATE   4800
/*

.equ	UBRRL	= UBRR0L	; For compatibility
.equ	UBRR	= UBRR0L	; For compatibility
.equ	UBRRH	= UBRR0H	; For compatibility
.equ	UCSRA	= UCSR0A	; For compatibility
.equ	UCSRB	= UCSR0B	; For compatibility
.equ	UDRE	= UDRE0	    ; For compatibility
.equ	UCSRC	= UCSR0C	; For compatibility
.equ	UCSZ1	= UCSZ01	; For compatibility
.equ	UDR	    = UDR0	    ; For compatibility
.equ	UCSZ0	= UCSZ00	; For compatibility
.equ	RXC	    = RXC0	    ; For compatibility
.equ	TXEN	= TXEN0	    ; For compatibility
.equ	RXEN	= RXEN0	    ; For compatibility
.equ	USBS	= USBS0	    ; For compatibility
*/
#define UBRRL UBRR0L
#define UBRR  UBRR0L
#define UBRRH UBRR0H
#define UCSRA UCSR0A
#define UCSRB UCSR0B
#define UDRE  UDRE0
#define UCSRC UCSR0C
#define UCSZ1 UCSZ01
#define UDR UDR0
#define UCSZ0 UCSZ00
#define RXC RXC0
#define TXEN TXEN0
#define RXEN RXEN0
#define USBS USBS0


void UARTInit(void);

int SerialPutch(char ch);

int UARTPutch(char ch, FILE *stream);

int UARTGetch(FILE *stream);

#endif
