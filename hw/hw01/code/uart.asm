/* uart.asm 
specifications for the UART interface
*/

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

; data for delimiters
USART_TRANSMIT_COMMA:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_COMMA

    ; send the data
    LDI TEMP, 0x2C              ; transmits ','
    STS UDR0, TEMP

USART_TRANSMIT_NEWLINE:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_COMMA

    ; send the data
    LDI TEMP, 0x0A              ; transmits ','
    STS UDR0, TEMP


; data for input status
USART_TRANSMIT_S:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_S

    ; send the data
    LDI TEMP, 0x53              ; transmits 'S'
    STS UDR0, TEMP

USART_TRANSMIT_F:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_F

    ; send the data
    LDI TEMP, 0x46              ; transmits 'F'
    STS UDR0, TEMP


; data for joystick input
USART_TRANSMIT_U:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_U

    ; send the data
    LDI TEMP, 0x55              ; transmits 'U'
    STS UDR0, TEMP

USART_TRANSMIT_D:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_D

    ; send the data
    LDI TEMP, 0x44              ; transmits 'D'
    STS UDR0, TEMP

USART_TRANSMIT_L:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_L

    ; send the data
    LDI TEMP, 0x4C              ; transmits 'L'
    STS UDR0, TEMP

USART_TRANSMIT_R:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_R

    ; send the data
    LDI TEMP, 0x52              ; transmits 'R'
    STS UDR0, TEMP


; data for states
USART_TRANSMIT_0:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_0

    ; send the data
    LDI TEMP, 0x30              ; transmits '0'
    STS UDR0, TEMP

USART_TRANSMIT_1:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_1

    ; send the data
    LDI TEMP, 0x31              ; transmits '1'
    STS UDR0, TEMP

USART_TRANSMIT_2:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_2

    ; send the data
    LDI TEMP, 0x32              ; transmits '2'
    STS UDR0, TEMP

USART_TRANSMIT_3:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_3

    ; send the data
    LDI TEMP, 0x33             ; transmits '3'
    STS UDR0, TEMP

USART_TRANSMIT_4:

    ; Wait for empty transmit buffer
    LDS TEMP0, UCSR0A
    SBRS TEMP0, UDRE
    RJMP USART_TRANSMIT_4

    ; send the data
    LDI TEMP, 0x34              ; transmits '4'
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
