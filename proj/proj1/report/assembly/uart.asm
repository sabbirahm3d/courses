; ----------------------------------------------------------------------------
; Instructions to demonstrate an example interface with the 8254 UART with a
; baud rate of 2400, 5 data bits, 1.5 stop bit parity and reads the bytes from
; receive FIFO.
; 
; To assemble and run with the Makefile provided:
;     make SCRIPT=uart run
; 
; ----------------------------------------------------------------------------

LINE        EQU 0F3H            ; 16550 line register
LSB         EQU 0F0H            ; 16550 baud divisor LSB
MSB         EQU 0F1H            ; 16550 baud divisor MSB
FIFO        EQU 0F2H            ; 16550 FIFO register

INIT PROC NEAR

    MOV     AL, 10011100        ; enable baud rate divisor
    OUT     LINE, AL
    MOV     AL, 50H             ; program baud rate 2400
    OUT     LSB, AL
    MOV     AL, 00H
    OUT     MSB, AL
    MOV     AL, 00011100B       ; program 5 data bits, even parity, 1 stop
    OUT     LINE, AL
    MOV     AL, 00000111B       ; enable transmitter and receiver
    OUT     FIFO, AL

    RET

INIT ENDP