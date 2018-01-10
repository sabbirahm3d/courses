; ----------------------------------------------------------------------------
; Instructions to demonstrate an example interface with the 82C55 programmable
; peripheral interface. This script reads data derived from a control register
; and writes it to port B.
; 
; To assemble and run with the Makefile provided:
;     make SCRIPT=ppi run
; 
; ----------------------------------------------------------------------------

CTRL_BYTE  EQU 0091H            ; set control register with:
                                ; PA=IN, PB=OUT, PC0-PC3=IN, PC4-PC7=OUT,
                                ; MODE=0

; Program to read data from port A and write to port B using port addresses
; 300H-303H
START:
    MOV     AL, CTRL_BYTE       ; grab the control byte data
    MOV     DX, 303H
    OUT     DX, AL
    MOV     DX, 300H
    IN      AX, DX
    MOV     DX, 301H
    OUT     DX, AX
