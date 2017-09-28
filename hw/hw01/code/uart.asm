/* uart.asm 
specifications for the UART interface
*/

;  using AVR Butteryfly @ default 8Mhz
; runs 4800 buad with 2 stop bits and no parity
.DEF TEMP       = R22
.DEF TEMP0      = R23

USARTINIT:      LDI TEMP, 00                ; Load UBRRH with 0 and UBRRL with
                STS UBRRH, TEMP             ; 103 - in other words
                LDI TEMP, 103               ; FOSC/16/BAUD-1 to set a baud rate
                STS UBRRL, TEMP             ; of about 4800 at 8MHz

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
TRANSMIT_COMMA: LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_COMMA

                ; send the data
                LDI TEMP, 0x2C              ; transmits ','
                STS UDR0, TEMP

TRANSMIT_NEWL:  LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_NEWL

                ; send the data
                LDI TEMP, 0x0A              ; transmits '\n'
                STS UDR0, TEMP


; data for input status
TRANSMIT_S:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_S

                ; send the data
                LDI TEMP, 0x53              ; transmits 'S'
                STS UDR0, TEMP

TRANSMIT_F:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_F

                ; send the data
                LDI TEMP, 0x46              ; transmits 'F'
                STS UDR0, TEMP


; data for joystick input
TRANSMIT_U:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_U

                ; send the data
                LDI TEMP, 0x55              ; transmits 'U'
                STS UDR0, TEMP

TRANSMIT_D:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_D

                ; send the data
                LDI TEMP, 0x44              ; transmits 'D'
                STS UDR0, TEMP

TRANSMIT_L:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_L

                ; send the data
                LDI TEMP, 0x4C              ; transmits 'L'
                STS UDR0, TEMP

TRANSMIT_R:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_R

                ; send the data
                LDI TEMP, 0x52              ; transmits 'R'
                STS UDR0, TEMP


; data for states
TRANSMIT_0:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_0

                ; send the data
                LDI TEMP, 0x30              ; transmits '0'
                STS UDR0, TEMP

TRANSMIT_1:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_1

                ; send the data
                LDI TEMP, 0x31              ; transmits '1'
                STS UDR0, TEMP

TRANSMIT_2:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_2

                ; send the data
                LDI TEMP, 0x32              ; transmits '2'
                STS UDR0, TEMP

TRANSMIT_3:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_3

                ; send the data
                LDI TEMP, 0x33             ; transmits '3'
                STS UDR0, TEMP

TRANSMIT_4:     LDS TEMP0, UCSR0A           ; Wait for empty transmit buffer
                SBRS TEMP0, UDRE
                RJMP TRANSMIT_4

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
