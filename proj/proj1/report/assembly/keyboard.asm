; ----------------------------------------------------------------------------
; Instructions to initialize the keyboard controller integrated in the system 
; with the 82C55 Programmable Peripheral Interface (PPI) chip.
; 
; To assemble and run with the Makefile provided:
;     make SCRIPT=keyboard run
; 
; ----------------------------------------------------------------------------

KEYBRD_ADDR  EQU 00F2H          ; set 8279 addresses

; Program to initialize the keyboard with the 8279
START:
    MOV     DX, KEYBRD_ADDR     ; point to 8279 command address
    MOV     AL, 00000011B       ; set mode for left entry, 8-digit display,
                                ; decoded scan, N-key rollover
    OUT     DX, AL              ; send to 8279
    MOV     AL, 3EH             ; clock word for divide by 30
    OUT     DX, AL
    MOV     AL, C0H             ; clear display to display all zeroes
