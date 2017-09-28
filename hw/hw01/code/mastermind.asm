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
                RCALL READINPUT
                RCALL CHECK
                ; RJMP USART_TRANSMIT_0
                ; RJMP USART_TRANSMIT_COMMA

; STATE1
STATE1:         CLR USER
                LDI NSHIFT, 2
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b00110000
                RCALL READINPUT
                RCALL CHECK
                ; RJMP USART_TRANSMIT_1
                ; RJMP USART_TRANSMIT_COMMA

; STATE2
STATE2:         CLR USER
                LDI NSHIFT, 1
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b00001100
                RCALL READINPUT
                RCALL CHECK
                ; RJMP USART_TRANSMIT_2
                ; RJMP USART_TRANSMIT_COMMA

; STATE3
STATE3:         CLR USER
                LDI NSHIFT, 0
				LDI CURSOR, SECRET
                ANDI CURSOR, 0b00000011
                RCALL CHECK
                RCALL READINPUT
                ; RJMP USART_TRANSMIT_3
                ; RJMP USART_TRANSMIT_COMMA

                RCALL LEDON

READINPUT:      SBIS PINB, 6                ; joystick up
                    RCALL JOYSTICKUP

                SBIS PINB, 7                ; joystick down
                    RCALL JOYSTICKDN

                SBIS PINE, 2                ; joystick left
                    RCALL JOYSTICKLT

                SBIS PINE, 3                ; joystick right
                    RCALL JOYSTICKRT

                SBIS PIND, 7                ; push button
                    RCALL RESETPB

                RJMP READINPUT

JOYSTICKUP:     ;RJMP USART_TRANSMIT_U
                ;RJMP USART_TRANSMIT_COMMA

                LDI USER, UP
                RCALL LSHIFT                ; shift left 6 bits
                RJMP DEBOUNCEUP

JOYSTICKDN:     ;RJMP USART_TRANSMIT_D
                ;RJMP USART_TRANSMIT_COMMA

                LDI USER, DOWN
                RCALL LSHIFT                ; shift left 4 bits
                RJMP DEBOUNCEDN

JOYSTICKLT:     ;RJMP USART_TRANSMIT_L
                ;RJMP USART_TRANSMIT_COMMA

                LDI USER, LEFT
                RCALL LSHIFT                ; shift left 2 bits
                RJMP DEBOUNCELT

JOYSTICKRT:     ;RJMP USART_TRANSMIT_R
                ;RJMP USART_TRANSMIT_COMMA

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
                BRNE LSHIFT
                    RET

CHECK:          CP CURSOR, USER
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

                JMP STATE0                  ; reset

; Used to make the buzzer sound hearable. Used to lower frequence enough so
; that the sound from the buzzer is hearable
WASTETIME:      CLR CTR

CONTWASTETIME:  NOP
                DEC CTR
                BRNE CONTWASTETIME
                    RET
