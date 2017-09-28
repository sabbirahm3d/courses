/* mastermind.asm
State machine implementation of Mastermind
*/

; Include the butterfly definitions for the M169P.
.INCLUDE "m169pdef.inc" ;(BUTTERFLY DEFINITIONS)
;.INCLUDE "uart.asm"

; initialize the stack and also define the port functionality
.DEF PORTDEF    = R19
; Counters 1 and 2 are used to waste time so that the buzzer sound is hearable
.DEF CTR        = R20              
.DEF CTR2       = R21

; registers to handle the comparisons
.DEF USER       = R22
.DEF CURSOR     = R23
.DEF NSHIFT     = R24

; secret code to win the game (UP, DOWN, LEFT, RIGHT)
.EQU SECRET     = 0b00011011

; mapping of joystick inputs to simpler states
.EQU UP         = 0b00000000
.EQU DOWN       = 0b00000001
.EQU LEFT       = 0b00000010
.EQU RIGHT      = 0b00000011


.ORG $0000

                RJMP START

; Initializes the stack.
START:          LDI PORTDEF, HIGH(RAMEND)   ; upper byte
                OUT SPH, PORTDEF            ; to stack pointer

                LDI PORTDEF, LOW(RAMEND)    ; lower byte
                OUT SPL, PORTDEF            ; to stack pointer

; SETUPPORTS initializes the ports for I/O
SETUPPORTS:     LDI PORTDEF, 0b00100010     ; PORT B (pin 1) is the LED (output)
                OUT DDRB, PORTDEF           ; PORT B (pin 5) is the buzzer (output)
                                            ; PORT B (pins 6 and 7) are the UP
                                            ; and DOWN inputs of the joystick
                                            ; (input)

                LDI PORTDEF, 0b10000000     ; PORT D (pin 7) is the push button
                OUT PORTD, PORTDEF          ; (input)

                LDI PORTDEF, 0b00001100     ; PORT E (pins 2 and 3) are the 
                OUT PORTE, PORTDEF          ; LEFT and RIGHT inputs of the 
                                            ; joystick (input)


; STATE0
STATE0:         LDI NSHIFT, 3
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b11000000

                ; RJMP TRANSMIT_0             ; transmit '0' for STATE0
                ; RJMP TRANSMIT_COMMA         ; transmit ','

                RCALL RDINPUT
                RCALL CMPINPUT

                ; RJMP TRANSMIT_S             ; transmit 'S' for success
                ; RJMP TRANSMIT_NEWL          ; transmit '\n' to proceed to next
                ;                             ; state


; STATE1
STATE1:         CLR USER
                LDI NSHIFT, 2
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b00110000

                ; RJMP TRANSMIT_0  1          ; transmit '1' for STATE1
                ; RJMP TRANSMIT_COMMA         ; transmit ','

                RCALL RDINPUT
                RCALL CMPINPUT

                ; RJMP TRANSMIT_S             ; transmit 'S' for success
                ; RJMP TRANSMIT_NEWL          ; transmit '\n' to proceed to next
                ;                             ; state

; STATE2
STATE2:         CLR USER
                LDI NSHIFT, 1
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b00001100

                ; RJMP TRANSMIT_2             ; transmit '2' for STATE2
                ; RJMP TRANSMIT_COMMA         ; transmit ','

                RCALL RDINPUT
                RCALL CMPINPUT

                ; RJMP TRANSMIT_S             ; transmit 'S' for success
                ; RJMP TRANSMIT_NEWL          ; transmit '\n' to proceed to next
                ;                             ; state

; STATE3
STATE3:         CLR USER
                LDI NSHIFT, 0
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b00000011

                ; RJMP TRANSMIT_3             ; transmit '3' for STATE3
                ; RJMP TRANSMIT_COMMA         ; transmit ','

                RCALL RDINPUT
                RCALL CMPINPUT

                ; RJMP TRANSMIT_S             ; transmit 'S' for success
                ; RJMP TRANSMIT_NEWL          ; transmit '\n' to proceed to next
                ;                             ; state

                RCALL LEDON

RDINPUT:        SBIS PINB, 6                ; joystick up
                    RCALL JOYSTICKUP

                SBIS PINB, 7                ; joystick down
                    RCALL JOYSTICKDN

                SBIS PINE, 2                ; joystick left
                    RCALL JOYSTICKLT

                SBIS PINE, 3                ; joystick right
                    RCALL JOYSTICKRT

                SBIS PIND, 7                ; push button
                    RCALL RESETPB

                RJMP RDINPUT

JOYSTICKUP:     ;RJMP TRANSMIT_U
                ;RJMP TRANSMIT_COMMA

                LDI USER, UP
                RCALL LSHIFT                ; shift left 6 bits
                RJMP DEBOUNCEUP

JOYSTICKDN:     ;RJMP TRANSMIT_D
                ;RJMP TRANSMIT_COMMA

                LDI USER, DOWN
                RCALL LSHIFT                ; shift left 4 bits
                RJMP DEBOUNCEDN

JOYSTICKLT:     ;RJMP TRANSMIT_L
                ;RJMP TRANSMIT_COMMA

                LDI USER, LEFT
                RCALL LSHIFT                ; shift left 2 bits
                RJMP DEBOUNCELT

JOYSTICKRT:     ;RJMP TRANSMIT_R
                ;RJMP TRANSMIT_COMMA

                LDI USER, RIGHT
                RCALL LSHIFT                ; shift left 0 bits
                RJMP DEBOUNCERT

RESETPB:        RJMP LEDOFF
                RJMP DEBOUNCEPB
                RJMP STATE0             ; reset

; Waits for user to stop pressing and then returns.
DEBOUNCEPB:     SBIC PIND, 7
                    RET
                RJMP DEBOUNCEPB

DEBOUNCEUP:     SBIC PINB, 6
                    RET
                RJMP DEBOUNCEUP

DEBOUNCEDN:     SBIC PINB, 7
                    RET
                RJMP DEBOUNCEDN

DEBOUNCELT:     SBIC PINE, 2
                    RET
                RJMP DEBOUNCELT

DEBOUNCERT:     SBIC PINE, 3
                    RET
                RJMP DEBOUNCERT


LSHIFT:         LSL USER
                LSL USER
                DEC NSHIFT
                CP NSHIFT, 1
                    BREQ LSHIFT             ; if NSHIFT >= 1, keep looping
                    RET                     ; else, break

CMPINPUT:       CP CURSOR, USER
                    RET
                BREQ BUZZERON


; Routine to turn on the LED
LEDON:          LDI PORTDEF, 0b00000010
                OUT PORTB, PORTDEF
                    RET

; Routine to turn off the LED
LEDOFF:         LDI PORTDEF, 0b00000000
                OUT PORTB, PORTDEF
                    RET

; BUZZERON sets the buzzer high (at PortB, Pin 5) and then sits in a loop so
; that the buzzer is low enough frequency to be hearable to the human ear. 
BUZZERON:       LDI PORTDEF, 0b00100000
                OUT PORTB, PORTDEF

                RCALL WASTETIME             ; WASTETIME is a counter that
                                            ; counts to 255 and then returns

                LDI PORTDEF, 0b11011111     ; once WASTETIME is finished, the
                OUT PORTB, PORTDEF          ; buzzer is turned off 

                RCALL WASTETIME             ; WASTETIME is called again to
                                            ; make the period of the soundwave
                                            ; even lower

                DEC CTR2                    ; this proc is ran 255 times to
                    BRNE BUZZERON           ; make the buzzer hearable

                ; RJMP TRANSMIT_F             ; transmit 'F' for failure
                ; RJMP TRANSMIT_NEWL          ; transmit '\n'

                JMP STATE0                  ; reset

; Used to make the buzzer sound hearable. Used to lower frequence enough so
; that the sound from the buzzer is hearable
WASTETIME:      CLR CTR

CONTWASTETIME:  NOP
                DEC CTR
                BRNE CONTWASTETIME
                    RET
