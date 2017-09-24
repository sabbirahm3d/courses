/* mastermind.asm
State machine implementation of Mastermind
*/

; Include the butterfly definitions for the M169P.
.INCLUDE "m169pdef.inc" ;(BUTTERFLY DEFINITIONS)
.INCLUDE "uart.asm"

; initialize the stack and also define the port functionality
.DEF PORTDEF                    = R22
; Counter 1 and 2 are used to waste time so that the buzzer sound is hearable
.DEF COUNTER                    = R23              
.DEF COUNTER2                   = R24

; secret code to win the game (UP, DOWN, LEFT, RIGHT)
.EQU SECRET                     = 0b00011011

.ORG $0000
    RJMP START

; Initializes the stack.
START:

    LDI PORTDEF, HIGH(RAMEND)   ; upper byte
    OUT SPH, PORTDEF            ; to stack pointer
    LDI PORTDEF, LOW(RAMEND)    ; lower byte
    OUT SPL, PORTDEF            ; to stack pointer

; PORT_INIT initializes the ports for I/O. It is configured so
; that any of the PORT D Pin 7 is used for the push button (input)
; and PIN 1 on PORT B can be used for the LED (output)
; The buzzer is also connected to PORT B (Pin 5) so that is initialized as well
PORT_INIT:

    LDI PORTDEF, 0b00100010
    OUT DDRB, PORTDEF
    LDI PORTDEF, 0b10000000
    OUT PORTD, PORTDEF

; STATE0:
; The very first state where no input has been entered. Will directly call 
; READINPUT and wait for user to press the push button. Once the button is
; pressed, turns on the LED and jumps to next state.
STATE0:

    RCALL READSTATE1

; STATE1:
; The second state. Does the same thing as State 0 but this time beeps the for
; successful push button press.
STATE1:

    RCALL READSTATE2

; STATE2:
; Once a button is pressed, turns off the LED and resets
; Return to state 0
STATE2:

    RCALL READSTATE3


STATE3:

    RCALL READSTATE4
    RCALL LEDON
    JMP STATE0


; Routine to turn on the LED
LEDON:
    LDI PORTDEF, 0b00000000
    OUT PORTB, PORTDEF
    RET

; BUZZERON sets the buzzer high (at PortB, Pin 5) and then sits in a loop so
; that the buzzer is low enough frequency to be hearable to the human ear. 
BUZZERON:

    LDI PORTDEF, 0b00100000
    OUT PORTB, PORTDEF

    ; Wastetime is a counter that counts to 255 and then returns.
    RCALL WASTETIME

    ; Once wastetime is finished, the buzzer is turned off 
    LDI PORTDEF, 0b11011111
    OUT PORTB, PORTDEF

    ; Wastetime is called again to make the period of the soundwave even lower
    RCALL WASTETIME

    ; This whole thing is done 255 times to make the buzzer hearable.
    DEC COUNTER2
        BRNE BUZZERON

    JMP STATE0                  ; reset
    RET

; sits in loop and waits for user to press PINB 6 (UP)
; if pressed, debounces
; if the wrong input is provided, BUZZERON is called and the program resets
READSTATE1:
    ; correct input
    SBIS PINB, 6                ; joystick up
        RJMP DEBOUNCE

    ; incorrect input
    SBIS PINB, 7                ; joystick down
        RCALL BUZZERON
    SBIS PINE, 2                ; joystick left
        RCALL BUZZERON
    SBIS PINE, 3                ; joystick right
        RCALL BUZZERON

    RJMP READSTATE1

; sits in loop and waits for user to press PINB 7 (DOWN)
; if pressed, debounces
; if the wrong input is provided, BUZZERON is called and the program resets
READSTATE2:
    ; correct input
    SBIS PINB, 7                ; joystick down
        RJMP DEBOUNCE

    ; incorrect input
    SBIS PINB, 6                ; joystick up
        RCALL BUZZERON
    SBIS PINE, 2                ; joystick left
        RCALL BUZZERON
    SBIS PINE, 3                ; joystick right
        RCALL BUZZERON

    RJMP READSTATE2

; sits in loop and waits for user to press PINE 2 (LEFT)
; if pressed, debounces
; if the wrong input is provided, BUZZERON is called and the program resets
READSTATE3:
    ; correct input
    SBIS PINE, 2                ; joystick left
        RJMP DEBOUNCE

    ; incorrect input
    SBIS PINB, 6                ; joystick up
        RCALL BUZZERON
    SBIS PINB, 7                ; joystick down
        RCALL BUZZERON
    SBIS PINE, 3                ; joystick right
        RCALL BUZZERON

    RJMP READSTATE3

; sits in loop and waits for user to press PINE 2 (RIGHT)
; if pressed, debounces
; if the wrong input is provided, BUZZERON is called and the program resets
READSTATE4:
    ; correct input
    SBIS PINE, 3                ; joystick right
        RJMP DEBOUNCE

    ; incorrect input
    SBIS PINB, 6                ; joystick up
        RCALL BUZZERON
    SBIS PINB, 7                ; joystick down
        RCALL BUZZERON
    SBIS PINE, 2                ; joystick left
        RCALL BUZZERON

    RJMP READSTATE4

READINPUT:
    SBIS PIND, 7
        RJMP DEBOUNCE
    RJMP READINPUT

; Waits for user to stop pressing and then returns.
DEBOUNCE:
    SBIC PIND, 7
        RET
    RJMP DEBOUNCE

; Used to make the buzzer sound hearable. Used
; to lower frequence enough so that the sound from the buzzer is hearable
WASTETIME:
    CLR COUNTER

CONTWASTETIME:
    NOP
    DEC COUNTER
    BRNE CONTWASTETIME
        RET

; ; definitions for the joystick inputs
; SBIS PINB, 6                    ; joystick up
;     RJMP JOYUP
; SBIS PINB, 7                    ; joystick down
;     RJMP JOYDOWN
; SBIS PINE, 2                    ; joystick left
;     RJMP JOYLEFT
; SBIS PINE, 3                    ; joystick right
;     RJMP JOYRIGHT
