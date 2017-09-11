; ----------------------------------------------------------------------------
; Instructions to demonstrate an example of the 8259 interrupt controoler
; interfacing with the 8254 UART with a baud rate of 2400, 5 data bits, 1.5
; stop bit parity and reads the bytes from receive FIFO.
; 
; To assemble and run with the Makefile provided:
;     make SCRIPT=pic run
; 
; ----------------------------------------------------------------------------

PIC1        EQU 48H             ; 8259A control A0 = 0
PIC2        EQU 49H             ; 8259A control A0 = 1
ICW1        EQU 1BH             ; 8259A ICW1
ICW2        EQU 80H             ; 8259A ICW2
ICW4        EQU 03H             ; 8259A ICW4
OCW1        EQU 0FEH            ; 8259A OCW1
LINE        EQU 0F3H            ; 16550 line register
LSB         EQU 0F0H            ; 16550 baud divisor LSB
MSB         EQU 0F1H            ; 16550 baud divisor MSB
FIFO        EQU 0F2H            ; 16550 FIFO register
MSB         EQU 0F1H            ; 16550 interrupt register

INIT PROC NEAR

    ; initialize 16550

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

    ; program 8259A

    MOV     AL, ICW1             ; program ICW1
    OUT     PIC1, AL
    MOV     AL, ICW2             ; program ICW2
    OUT     PIC2, AL
    MOV     AL, ICW4             ; program ICW4
    OUT     PIC2, AL
    MOV     AL, OCW1             ; program OCW1
    OUT     PIC2, AL
    STI                          ; enable INTR pin

    ; enable 16550 interrupts

    MOV     AL, 5
    OUT     ITR, AL              ; enable interrupts

    RET

INIT ENDP