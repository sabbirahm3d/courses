/* main.asm
State machine implementation of Mastermind
*/

; Include the butterfly definitions for the M169P.
.INCLUDE "m169pdef.inc" ;(BUTTERFLY DEFINITIONS)

; initialize the stack and also define the port functionality
.DEF PORTDEF    = R16

; Counters 1 and 2 are used to waste time so that the buzzer sound is hearable
.DEF CTR        = R17              
.DEF CTR2       = R18

; registers to handle the comparisons
.DEF USER       = R19
.DEF CURSOR     = R20
.DEF NSHIFT     = R21
.DEF REALSTATE  = R22

; secret code to win the game (UP, DOWN, LEFT, RIGHT)
.EQU SECRET     = 0b00011011

; mapping of joystick inputs to codes embedded in SECRET
.EQU UP         = 0b00000000
.EQU DOWN       = 0b00000001
.EQU LEFT       = 0b00000010
.EQU RIGHT      = 0b00000011


.ORG $0000

; include instructions from 'uart.asm' to implement transmission with the UART
.INCLUDE "uart.asm"

                RJMP START

; initialize the stack.
START:          LDI PORTDEF, HIGH(RAMEND)   ; upper byte
                OUT SPH, PORTDEF            ; to stack pointer

                LDI PORTDEF, LOW(RAMEND)    ; lower byte
                OUT SPL, PORTDEF            ; to stack pointer

; initialize the ports for I/O
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

; descriptions of states
; STATE0 is the initial state of the game, where the machine waits for the
; user's first input. The correct input progresses the game to the next state,
; and an incorrect input results in the buzzer being triggered.
STATE0:         LDI NSHIFT, 3
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b11000000
                LD REALSTATE, (CURSOR >> 6) ; shift REALSTATE to map the codes
                                            ; of the joystick inputs

                RCALL TRANSMIT_0            ; transmit '0' for STATE0
                RCALL TRANSMIT_COMMA        ; transmit ','

                RCALL RDINPUT
                RCALL WHICHINPUT            ; check which input was expected
                RCALL TRANSMIT_COMMA
                RCALL CMPINPUT

                RCALL TRANSMIT_S            ; transmit 'S' for success
                RCALL TRANSMIT_NEWL         ; transmit '\n' to proceed to next
                                            ; state


; STATE1 is the second state of the game, where the machine waits for the
; user's second input. The correct input progresses the game to the next state,
; and an incorrect input results in the buzzer being triggered.
STATE1:         CLR USER
                LDI NSHIFT, 2
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b00110000
                LD REALSTATE, (CURSOR >> 4) ; shift REALSTATE to map the codes
                                            ; of the joystick inputs

                RCALL TRANSMIT_1            ; transmit '1' for STATE1
                RCALL TRANSMIT_COMMA        ; transmit ','

                RCALL RDINPUT
                RCALL WHICHINPUT            ; check which input was expected
                RCALL TRANSMIT_COMMA
                RCALL CMPINPUT

                RCALL TRANSMIT_S            ; transmit 'S' for success
                RCALL TRANSMIT_NEWL         ; transmit '\n' to proceed to next
                                            ; state

; STATE2 is the third state of the game, where the machine waits for the
; user's third input. The correct input progresses the game to the next state,
; and an incorrect input results in the buzzer being triggered.
STATE2:         CLR USER
                LDI NSHIFT, 1
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b00001100
                LD REALSTATE, (CURSOR >> 2) ; shift REALSTATE to map the codes
                                            ; of the joystick inputs

                RCALL TRANSMIT_2            ; transmit '2' for STATE2
                RCALL TRANSMIT_COMMA        ; transmit ','

                RCALL RDINPUT
                RCALL WHICHINPUT            ; check which input was expected
                RCALL TRANSMIT_COMMA
                RCALL CMPINPUT

                RCALL TRANSMIT_S            ; transmit 'S' for success
                RCALL TRANSMIT_NEWL         ; transmit '\n' to proceed to next
                                            ; state

; STATE3 is the fourth state of the game, where the machine waits for the
; user's fourth input. The correct input progresses the game to the next state,
; and an incorrect input results in the buzzer being triggered.
STATE3:         CLR USER
                LDI NSHIFT, 0
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b00000011
                LD REALSTATE, CURSOR        ; shift REALSTATE to map the codes
                                            ; of the joystick inputs
                RCALL TRANSMIT_3            ; transmit '3' for STATE3
                RCALL TRANSMIT_COMMA        ; transmit ','

                RCALL RDINPUT
                RCALL WHICHINPUT            ; check which input was expected
                RCALL TRANSMIT_COMMA
                RCALL CMPINPUT

                RCALL TRANSMIT_S            ; transmit 'S' for success
                RCALL TRANSMIT_NEWL         ; transmit '\n' to proceed to next
                                            ; state

                RCALL LEDON

; instructions to handle the I/O in the program
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

; joystick inputs
JOYSTICKUP:     RCALL TRANSMIT_U            ; transmit 'U'
                RCALL TRANSMIT_COMMA        ; transmit ','

                LDI USER, UP                ; load joystick input code to USER
                RCALL LSHIFT                ; shift left USER by NSHIFT*2 bits
                RJMP DEBOUNCEUP

JOYSTICKDN:     RCALL TRANSMIT_D            ; transmit 'D'
                RCALL TRANSMIT_COMMA        ; transmit ','

                LDI USER, DOWN              ; load joystick input code to USER
                RCALL LSHIFT                ; shift left USER by NSHIFT*2 bits
                RJMP DEBOUNCEDN

JOYSTICKLT:     RCALL TRANSMIT_L            ; transmit 'L'
                RCALL TRANSMIT_COMMA        ; transmit ','

                LDI USER, LEFT              ; load joystick input code to USER
                RCALL LSHIFT                ; shift left USER by NSHIFT*2 bits
                RJMP DEBOUNCELT

JOYSTICKRT:     RCALL TRANSMIT_R            ; transmit 'R'
                RCALL TRANSMIT_COMMA        ; transmit ','

                LDI USER, RIGHT             ; load joystick input code to USER
                RCALL LSHIFT                ; shift left USER by NSHIFT*2 bits
                RJMP DEBOUNCERT

RESETPB:        RJMP LEDOFF
                RJMP DEBOUNCEPB
                RJMP STATE0                 ; reset

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
                LSL USER                    ; left shift twice per iteration
                DEC NSHIFT                  ; decrement the number of shifts
                CPI NSHIFT, 1
                    BRGE LSHIFT             ; if NSHIFT >= 1, keep looping
                    RET                     ; else, break

WHICHINPUT:     CPI REALSTATE, UP           ; if user inputted 'UP'
                    BRNE TRANSMIT_U         ; transmit 'U'

                CPI REALSTATE, DOWN         ; if user inputted 'DOWN'
                    BRNE TRANSMIT_D         ; transmit 'D'

                CPI REALSTATE, LEFT         ; if user inputted 'LEFT'
                    BRNE TRANSMIT_L         ; transmit 'L'

                CPI REALSTATE, RIGHT        ; if user inputted 'RIGHT'
                    BRNE TRANSMIT_R         ; transmit 'R'

                    RET

CMPINPUT:       CP CURSOR, USER
                    RET
                BREQ BUZZERON


; instructions for the LED
; ----------------------------------------------------------------------------
; subroutine to turn on the LED
LEDON:          LDI PORTDEF, 0b00000010
                OUT PORTB, PORTDEF
                    RET

; subroutine to turn off the LED
LEDOFF:         LDI PORTDEF, 0b00000000
                OUT PORTB, PORTDEF
                    RET


; instructions for the buzzer
; ----------------------------------------------------------------------------
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

                RCALL TRANSMIT_F            ; transmit 'F' for failure
                RCALL TRANSMIT_NEWL         ; transmit '\n'

                JMP STATE0                  ; reset

; Used to make the buzzer sound hearable. Used to lower frequency enough so
; that the sound from the buzzer is hearable
WASTETIME:      CLR CTR

CONTWASTETIME:  NOP
                DEC CTR
                BRNE CONTWASTETIME
                    RET
