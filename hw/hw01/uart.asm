/* uart.asm */ 

; Simple program to send "Hello! World" using AVR Butteryfly @ default 8Mhz
; runs 4800 buad with 2 stop bits and no parity
.DEF TEMP                       = R16
.DEF TEMP0                      = R17
.DEF TEMP1                      = R18

; Initialize Stack Pointer to end of RAM
LDI TEMP, HIGH(RAMEND)          ; Upper byte
OUT SPH, TEMP                   ; to stack pointer
LDI TEMP, LOW(RAMEND)           ; Lower byte
OUT SPL, TEMP                   ; to stack pointer

USART_INIT:

    ; Load UBRRH with 0 and UBRRL with 103
    ; in other words FOSC/16/BAUD-1
    ; to set a baud rate of about 4800 at 8MHz
    LDI TEMP, 00

    ; MOV UBRRH, TEMP ; can't do this since UBRRH is in the _extended_ i/o
    STS UBRRH, TEMP
    LDI TEMP, 103
    STS UBRRL, TEMP

    ; Clear all error flags
    LDI TEMP, 00
    STS UCSRA, TEMP

    ; Enable Transmission and Reception
    LDI TEMP, (1 << RXEN0) | (1 << TXEN0)
    STS UCSRB, TEMP

    ; Set frame format: 8data, 2stop bit
    LDI TEMP, (1 << USBS0) | (3 << UCSZ00)
    STS UCSR0C, TEMP

; Transmit Data
USART_TRANSMIT_H:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_H

    ; send the data
    LDI TEMP, 0x48
    STS UDR0, TEMP

USART_TRANSMIT_E:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_E

    ; send the data
    LDI TEMP, 0x45
    STS UDR0, TEMP

USART_TRANSMIT_L:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_L

    ; send the data
    LDI TEMP, 0x4C
    STS UDR0, TEMP

USART_TRANSMIT_O:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_O

    ; send the data
    LDI TEMP, 0x4F
    STS UDR0, TEMP

USART_TRANSMIT_EXCLAMATION:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_EXCLAMATION

    ; send the data
    LDI TEMP, 0x21
    STS UDR0, TEMP

; now send the data using a function call
DONE:
    RJMP DONE

; assumes data is in register TEMP
USART_TRANSMIT:

    ; Wait for empty transmit buffer
    ;sbis UCSR0A,UDRE
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT

    ; send the data
    STS UDR0, TEMP
    RET
