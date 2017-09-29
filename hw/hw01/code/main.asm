/* main.asm
State machine implementation of Mastermind
*/

; include the Butterfly definitions for the M169P
.INCLUDE "m169pdef.inc"

; initialize the stack and also define the port functionality
.DEF PORTDEF    = R16

; Counters 1 and 2 are used to waste time so that the buzzer sound is hearable
.DEF CTR        = R17
.DEF CTR2       = R18

; registers to handle the comparisons
.DEF USER       = R19
.DEF CURSOR     = R20
.DEF REALSTATE  = R21
.DEF NSHIFT     = R22

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
SETUPPORTS:     LDI PORTDEF, 0b00100010     ; Pin 1 is the LED (output)
                OUT DDRB, PORTDEF           ; Pin 5 is the buzzer (output)
                                            ; Pins 6 and 7 are the UP and DOWN
                                            ; inputs of the joystick (input)

                LDI PORTDEF, 0b10000000     ; Pin 7 is the push button (input)
                OUT PORTD, PORTDEF

                LDI PORTDEF, 0b00001100     ; Pins 2 and 3 are the LEFT and
                OUT PORTE, PORTDEF          ; RIGHT inputs of the joystick
                                            ; (input)

; descriptions of states
; ----------------------------------------------------------------------------
; STATE0 is the initial state of the game, where the machine waits for the
; user's first input. The correct input progresses the game to the next state,
; and an incorrect input results in the buzzer being triggered.
STATE0:         RCALL TRANSMIT_0            ; transmit '0' for STATE0
                RCALL TRANSMIT_COMMA        ; transmit ','

                LDI CURSOR, SECRET          ; load and mask the secret code
                ANDI CURSOR, 0b11000000     ; into the CURSOR register
                LDI NSHIFT, 3               ; to shift USER BY 3*2 bits
                RCALL RDINPUT               ; get user's input

                CLR NSHIFT
                LDI NSHIFT, 3               ; shift REALSTATE to map the codes
                MOV REALSTATE, CURSOR       ; of the joystick inputs
                RCALL RSHIFT
                RCALL EXPINPUT              ; check which input was expected

                RCALL TRANSMIT_COMMA
                RCALL CMPINPUT

                RCALL TRANSMIT_1            ; transmit '1' for STATE1
                RCALL TRANSMIT_COMMA        ; transmit ','
                RCALL TRANSMIT_S            ; transmit 'S' for success
                RCALL TRANSMIT_NEWL         ; transmit '\n' to proceed to next
                                            ; state


; STATE1 is the second state of the game, where the machine waits for the
; user's second input. The correct input progresses the game to the next state,
; and an incorrect input results in the buzzer being triggered.
STATE1:         CLR USER
                LDI CURSOR, SECRET          ; load and mask the secret code
                ANDI CURSOR, 0b00110000     ; into the CURSOR register
                LDI NSHIFT, 2               ; to shift USER BY 2*2 bits
                RCALL RDINPUT               ; get user's input

                CLR NSHIFT
                LDI NSHIFT, 2               ; shift REALSTATE to map the codes
                MOV REALSTATE, CURSOR       ; of the joystick inputs
                RCALL RSHIFT
                RCALL EXPINPUT              ; check which input was expected

                RCALL TRANSMIT_COMMA
                RCALL CMPINPUT

                RCALL TRANSMIT_2            ; transmit '2' for STATE2
                RCALL TRANSMIT_COMMA        ; transmit ','
                RCALL TRANSMIT_S            ; transmit 'S' for success
                RCALL TRANSMIT_NEWL         ; transmit '\n' to proceed to next
                                            ; state

; STATE2 is the third state of the game, where the machine waits for the
; user's third input. The correct input progresses the game to the next state,
; and an incorrect input results in the buzzer being triggered.
STATE2:         CLR USER
                LDI CURSOR, SECRET          ; load and mask the secret code
                ANDI CURSOR, 0b00001100     ; into the CURSOR register
                LDI NSHIFT, 1               ; to shift USER BY 1*2 bits
                RCALL RDINPUT               ; get user's input

                CLR NSHIFT
                LDI NSHIFT, 1               ; shift REALSTATE to map the codes
                MOV REALSTATE, CURSOR       ; of the joystick inputs
                RCALL RSHIFT
                RCALL EXPINPUT              ; check which input was expected

                RCALL TRANSMIT_COMMA
                RCALL CMPINPUT

                RCALL TRANSMIT_3            ; transmit '3' for STATE3
                RCALL TRANSMIT_COMMA        ; transmit ','
                RCALL TRANSMIT_S            ; transmit 'S' for success
                RCALL TRANSMIT_NEWL         ; transmit '\n' to proceed to next
                                            ; state

; STATE3 is the fourth state of the game, where the machine waits for the
; user's fourth input. The correct input progresses the game to the next 
; state, and an incorrect input results in the buzzer being triggered
STATE3:         CLR USER
                LDI CURSOR, SECRET          ; load and mask the secret code
                ANDI CURSOR, 0b00000011     ; into the CURSOR register
                LDI NSHIFT, 0               ; to shift USER BY 0*2 bits
                RCALL RDINPUT               ; get user's input

                CLR NSHIFT
                LDI NSHIFT, 0               ; shift REALSTATE to map the codes
                MOV REALSTATE, CURSOR       ; of the joystick inputs
                RCALL RSHIFT
                RCALL EXPINPUT              ; check which input was expected

                RCALL TRANSMIT_COMMA
                RCALL CMPINPUT

                RCALL TRANSMIT_S            ; transmit 'S' for success
                RCALL TRANSMIT_NEWL         ; transmit '\n' to proceed to next
                                            ; state

                RCALL LEDON


; instructions to handle the I/O in the program
; ----------------------------------------------------------------------------
; sits in a loop and waits for the user to input any of the 5 possible inputs
; joystick up, joystick down, joystick left, joystick right and push button
; once an input is established, their respective subroutine is called
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

                RJMP RDINPUT                ; if nothing was pressed, loop


; joystick inputs
; ----------------------------------------------------------------------------
; if joystick up was pressed, the UART transmits 'U,' and the current state
; register loads the code for UP which is then shifted
JOYSTICKUP:     RCALL TRANSMIT_U            ; transmit 'U'
                RCALL TRANSMIT_COMMA        ; transmit ','

                LDI USER, UP                ; load joystick input code to USER
                RCALL LSHIFT                ; shift left USER by NSHIFT*2 bits
                RJMP DEBOUNCEUP
                    RET

; waits for user to stop pressing and then returns
DEBOUNCEUP:     SBIC PINB, 6
                    RET
                RJMP DEBOUNCEUP


; if joystick down was pressed, the UART transmits 'D,' and the current state
; register loads the code for DOWN which is then shifted
JOYSTICKDN:     RCALL TRANSMIT_D            ; transmit 'D'
                RCALL TRANSMIT_COMMA        ; transmit ','

                LDI USER, DOWN              ; load joystick input code to USER
                RCALL LSHIFT                ; shift left USER by NSHIFT*2 bits
                RJMP DEBOUNCEDN
                    RET

; waits for user to stop pressing and then returns
DEBOUNCEDN:     SBIC PINB, 7
                    RET
                RJMP DEBOUNCEDN


; if joystick left was pressed, the UART transmits 'L,' and the current state
; register loads the code for LEFT which is then shifted
JOYSTICKLT:     RCALL TRANSMIT_L            ; transmit 'L'
                RCALL TRANSMIT_COMMA        ; transmit ','

                LDI USER, LEFT              ; load joystick input code to USER
                RCALL LSHIFT                ; shift left USER by NSHIFT*2 bits
                RJMP DEBOUNCELT
                    RET

; waits for user to stop pressing and then returns
DEBOUNCELT:     SBIC PINE, 2
                    RET
                RJMP DEBOUNCELT


; if joystick right was pressed, the UART transmits 'R,' and the current state
; register loads the code for RIGHT which is then shifted
JOYSTICKRT:     RCALL TRANSMIT_R            ; transmit 'R'
                RCALL TRANSMIT_COMMA        ; transmit ','

                LDI USER, RIGHT             ; load joystick input code to USER
                RCALL LSHIFT                ; shift left USER by NSHIFT*2 bits
                RJMP DEBOUNCERT
                    RET

; waits for user to stop pressing and then returns
DEBOUNCERT:     SBIC PINE, 3
                    RET
                RJMP DEBOUNCERT


; if the reset push button was pressed, the program resets to STAT0
RESETPB:        RJMP LEDOFF                 ; turn off LED
                RJMP DEBOUNCEPB             ; debounce push button
                RJMP STATE0                 ; reset
                    RET

; waits for user to stop pressing and then returns
DEBOUNCEPB:     SBIC PIND, 7
                    RET
                RJMP DEBOUNCEPB


; instructions to compare user inputs to the secret code
; ----------------------------------------------------------------------------
; left shift the user input to match the position of the states in SECRET
LSHIFT:         LSL USER
                LSL USER                    ; left shift twice per iteration
                DEC NSHIFT                  ; decrement the number of shifts
                CPI NSHIFT, 1
                    BRGE LSHIFT             ; if NSHIFT >= 1, keep looping
                    RET                     ; else, break

; right shift the current state to match the position of the states in SECRET
RSHIFT:         LSR CURSOR
                LSR CURSOR                  ; right shift twice per iteration
                DEC NSHIFT                  ; decrement the number of shifts
                CPI NSHIFT, 1
                    BRGE LSHIFT             ; if NSHIFT >= 1, keep looping
                    RET                     ; else, break

; compares the current state to find the expected output
EXPINPUT:       CPI REALSTATE, UP           ; if current state is 'UP'
                    RCALL TRANSMIT_U        ; transmit 'U'

                CPI REALSTATE, DOWN         ; if current state is 'DOWN'
                    RCALL TRANSMIT_D        ; transmit 'D'

                CPI REALSTATE, LEFT         ; if current state is 'LEFT'
                    RCALL TRANSMIT_L        ; transmit 'L'

                CPI REALSTATE, RIGHT        ; if current state is 'RIGHT'
                    RCALL TRANSMIT_R        ; transmit 'R'

                    RET

; compare user's input to the current state and returns if true, else, branches
; to BUZZERON to reset the game
CMPINPUT:       CP CURSOR, USER
                    RET                     ; if equal, return from subroutine
                BREQ BUZZERON               ; else, trigger buzzer


; instructions for the LED
; ----------------------------------------------------------------------------
; subroutine to turn on the LED
LEDON:          LDI PORTDEF, 0b00000010     ; turn on LED
                OUT PORTB, PORTDEF
                    RET

; subroutine to turn off the LED
LEDOFF:         LDI PORTDEF, 0b00000000     ; turn off LED
                OUT PORTB, PORTDEF
                    RET


; instructions for the buzzer
; ----------------------------------------------------------------------------
; BUZZERON sets the buzzer high (at Port B, Pin 5) and then sits in a loop so
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
