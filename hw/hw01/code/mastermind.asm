/* mastermind.asm
State machine implementation of Mastermind
*/

; Include the butterfly definitions for the M169P.
.INCLUDE "m169pdef.inc" ;(BUTTERFLY DEFINITIONS)
.INCLUDE "uart.asm"

; initialize the stack and also define the port functionality
.DEF PORTDEF     = R22
; Counter 1 and 2 are used to waste time so that the buzzer sound is hearable
.DEF CTR        = R23              
.DEF CTR2       = R24
.DEF JOYSTICK   = R2

; secret code to win the game (UP, DOWN, LEFT, RIGHT)
.EQU SECRET     = 0b00011011

; mapping of joystick inputs to simpler states
.EQU UP         = 0b00
.EQU DOWN       = 0b01
.EQU LEFT       = 0b10
.EQU RIGHT      = 0b11


.ORG $0000

                RJMP START

; Initializes the stack.
START:          LDI PORTDEF, HIGH(RAMEND)   ; upper byte
                OUT SPH, PORTDEF            ; to stack pointer
                LDI PORTDEF, LOW(RAMEND)    ; lower byte
                OUT SPL, PORTDEF            ; to stack pointer

; PORT_INIT initializes the ports for I/O. It is configured so
; that any of the PORT D Pin 7 is used for the push button (input)
; and PIN 1 on PORT B can be used for the LED (output)
; The buzzer is also connected to PORT B (Pin 5) so that is initialized as well
PORT_INIT:      LDI PORTDEF, 0b00100010
                OUT DDRB, PORTDEF
                LDI PORTDEF, 0b10000000
                OUT PORTD, PORTDEF

; STATE0
; STATE0:         LDI JOYSTICK, UP
                RCALL READINPUT

; STATE1:
STATE1:         RCALL READSTATE2

; STATE2:
STATE2:         RCALL READSTATE3


STATE3:         RCALL READSTATE4
                RCALL LEDON
                JMP STATE0


READINPUT:      SBIS PINB, 6                ; joystick up
                    RJMP JOYSTICKUP

                SBIS PINB, 7                ; joystick down
                    RCALL JOYSTICKDOWN

                SBIS PINE, 2                ; joystick left
                    RCALL JOYSTICKLEFT

                SBIS PINE, 3                ; joystick right
                    RCALL JOYSTICKRIGHT

                RJMP READINPUT

JOYSTICKUP:

; Waits for user to stop pressing and then returns.
DEBOUNCEUP:     SBIC PINB, 6
                    RET
                RJMP DEBOUNCEUP

DEBOUNCEDOWN:   SBIC PINB, 7
                    RET
                RJMP DEBOUNCEDOWN

DEBOUNCELEFT:   SBIC PINE, 2
                    RET
                RJMP DEBOUNCELEFT

DEBOUNCERIGHT:  SBIC PINE, 3
                    RET
                RJMP DEBOUNCERIGHT


; Routine to turn on the LED
LEDON:          LDI PORTDEF, 0b00000010
                OUT PORTB, PORTDEF
                RET

; BUZZERON sets the buzzer high (at PortB, Pin 5) and then sits in a loop so
; that the buzzer is low enough frequency to be hearable to the human ear. 
BUZZERON:       LDI PORTDEF, 0b00100000
                OUT PORTB, PORTDEF

                ; Wastetime is a counter that counts to 255 and then returns
                RCALL WASTETIME

                ; Once wastetime is finished, the buzzer is turned off 
                LDI PORTDEF, 0b11011111
                OUT PORTB, PORTDEF

                ; WASTETIME is called again to make the period of the soundwave
                ; even lower
                RCALL WASTETIME

                ; this proc is ran 255 times to make the buzzer hearable
                DEC CTR2
                    BRNE BUZZERON

                JMP STATE0                  ; reset
                RET

; Used to make the buzzer sound hearable. Used to lower frequence enough so
; that the sound from the buzzer is hearable
WASTETIME:      CLR CTR

CONTWASTETIME:  NOP
                DEC CTR
                BRNE CNTWASTETIME
                    RET
