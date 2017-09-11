; ----------------------------------------------------------------------------
; Instructions to demonstrate an example interface with the 8254 programmable
; interval timer. This script sends a control byte to the control register.
; 
; To assemble and run with the Makefile provided:
;     make SCRIPT=pit run
; 
; ----------------------------------------------------------------------------

; Program to send a control byte to the control register
START:
    MOV     AL, 01110111B      ; counter 1, mode 3, BCD
    OUT     FFEEH, AL          ; send to control register
