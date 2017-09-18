/*
 * uart.asm
 *
 */ 

;Simple program to send "Hello! World" using AVR Butteryfly @ default 8Mhz
;runs 4800 buad with 2 stop bits and no partiy
.def TEMP=r16
.def TEMP0=r17
.def TEMP1=r18
; Initialize Stack Pointer to end of RAM
LDI TEMP, HIGH(RAMEND) ; Upper byte
OUT SPH,TEMP ; to stack pointer
LDI TEMP, LOW(RAMEND) ; Lower byte
OUT SPL,TEMP; to stack pointer
USART_Init:

;Load UBRRH with 0 and UBRRL with 103
;in other words FOSC/16/BAUD-1
;to set a baud rate of about 4800 at 8MHz
ldi TEMP,00
//mov UBRRH, TEMP ; can't do this since UBRRH is in the _extended_ i/o
sts UBRRH,TEMP
ldi TEMP,103
sts UBRRL,TEMP
;Clear all error flags
ldi TEMP,00
sts UCSRA,TEMP
;Enable Transmission and Reception
ldi TEMP,(1<<RXEN0)|(1<<TXEN0)
sts UCSRB,TEMP
; Set frame format: 8data, 2stop bit
ldi TEMP, (1<<USBS0)|(3<<UCSZ00)
sts UCSR0C,TEMP

;Transmit Data
USART_Transmit_H:
;Wait for empty transmit buffer
;sbis UCSR0A,UDRE ; can't do this
;rjmp USART_Transmit_H ; and this since UCSR0A is extended i/o
lds TEMP0, UCSR0A
sbrs TEMP0,UDRE
rjmp USART_Transmit_H
; send the data
ldi TEMP, 0x48
sts UDR0, TEMP
USART_Transmit_I:
; Wait for empty transmit buffer
lds TEMP0, UCSR0A
sbrs TEMP0,UDRE
rjmp USART_Transmit_I
; send the data
ldi TEMP, 0x49
sts UDR0, TEMP
USART_Transmit_exclamation:
; Wait for empty transmit buffer
lds TEMP0, UCSR0A
sbrs TEMP0,UDRE
rjmp USART_Transmit_exclamation
; send the data
ldi TEMP, 0x21
sts UDR0, TEMP

; now send the data using a function call

DONE:
rjmp DONE

USART_Transmit: ;assumes data is in register TEMP
; Wait for empty transmit buffer
;sbis UCSR0A,UDRE
lds TEMP0, UCSR0A
sbrs TEMP0,UDRE
rjmp USART_Transmit
; send the data
sts UDR0, TEMP
ret
