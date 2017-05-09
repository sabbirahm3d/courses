; ----------------------------------------------------------------------------------------
; Instructions to initialize the LCD controller integrated in the system with the 82C55
; Programmable Peripheral Interface (PPI) chip.
; 
; To assemble and run with the Makefile provided:
;     make SCRIPT=lcd run
; 
; ----------------------------------------------------------------------------------------

PORTA_ADDR  EQU 700H            ; set port addresses
PORTB_ADDR  EQU 701H
CMD_ADDR    EQU 703H

; macro to send a command or data to the LCD display
SEND MACRO PORTA_DATA, PORTB_DATA, DELAY
    MOV     AL, PORTA_DATA      ; PORTA_DATA to Port A
    MOV     DX, PORTA_ADDR
    OUT     DX, AL
    MOV     AL, PORTB_DATA      ; PORTB_DATA to Port B
    MOV     DX, PORTB_ADDR
    OUT     DX, AL
    OR      AL, 00000100B       ; set E bit
    OUT     DX, AL              ; send to Port B
    AND     AL, 11111011B       ; clear E bit
    NOP                         ; a small delay
    NOP
    OUT     DX, AL              ; send to Port B
    MOV     BL, DELAY           ; BL = delay count
    CALL    MS_DELAY            ; ms Time Delay
    ENDM

; Program to initialize the LCD display
START:
    MOV     AL, 80H             ; program the 82C55
    MOV     DX, CMD_ADDR
    OUT     DX, AL
    MOV     AL, 0
    MOV     DX, PORTB_ADDR      ; clear Port B
    SEND    30H, 2, 16          ; send 30H for 16 ms
    SEND    30H, 2, 5           ; send 30H for 5 ms
    SEND    30H, 2, 1           ; send 30H for 1 ms
    SEND    38H, 2, 1           ; send 38H for 1 ms
    SEND    8, 2, 1             ; send 8 for 1 ms
    SEND    1, 2, 2             ; send 1 for 2 ms
    SEND    0CH, 2, 1           ; send 0CH for 1 ms
    SEND    6, 2, 1             ; send 6 for 1 ms
