/* mastermind.asm
State machine implementation of Mastermind
*/

; Include the butterfly definitions for the M169P.
.INCLUDE "m169pdef.inc" ;(BUTTERFLY DEFINITIONS)
.INCLUDE "uart.asm"

; initialize the stack and also define the port functionality
.DEF PORTDEF    = R22
; Counters 1 and 2 are used to waste time so that the buzzer sound is hearable
.DEF CTR        = R23              
.DEF CTR2       = R24

; registers to handle the comparisons
.DEF USER       = R25
.DEF CURSOR     = R26

; secret code to win the game (UP, DOWN, LEFT, RIGHT)
.EQU SECRET     = 0b00011011

; mapping of joystick inputs to simpler states
.EQU UP         = 0b00000000
.EQU DOWN       = 0b00000001
.EQU LEFT       = 0b00000010                ; LEFT also works as a 2-bit mask
                                            ; (since 0b00000010 = 3)
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
STATE0:         LDI USER, 0b00000000
                LDI CURSOR, (SECRET >> 6)
                RJMP USART_TRANSMIT_0
                RJMP USART_TRANSMIT_COMMA
                RCALL READINPUT

; STATE1
STATE1:         LDI USER, (USER << 2)
                LDI CURSOR, (SECRET >> 4)
                RJMP USART_TRANSMIT_1
                RJMP USART_TRANSMIT_COMMA
                RCALL READINPUT

; STATE2
STATE2:         LDI USER, (USER << 2)
                LDI CURSOR, (SECRET >> 2)
                RJMP USART_TRANSMIT_2
                RJMP USART_TRANSMIT_COMMA
                RCALL READINPUT

; STATE3
STATE3:         LDI USER, (USER << 2)
                LDI CURSOR, SECRET
                RJMP USART_TRANSMIT_3
                RJMP USART_TRANSMIT_COMMA
                RCALL READINPUT

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
                    RJMP STATE0             ; reset

                RJMP READINPUT

JOYSTICKUP:     RJMP USART_TRANSMIT_U
                RJMP USART_TRANSMIT_COMMA

                ADD USER, UP
                CP (USER & LEFT), (CURSOR & LEFT)
                    RJMP DEBOUNCEUP
                BRNE BUZZERON

JOYSTICKDN:     RJMP USART_TRANSMIT_D
                RJMP USART_TRANSMIT_COMMA

                ADD USER, DOWN
                CP (USER & LEFT), (CURSOR & LEFT)
                    RJMP DEBOUNCEDN
                BRNE BUZZERON

JOYSTICKLT:     RJMP USART_TRANSMIT_L
                RJMP USART_TRANSMIT_COMMA

                ADD USER, LEFT
                CP (USER & LEFT), (CURSOR & LEFT)
                    RJMP DEBOUNCELT
                BRNE BUZZERON

JOYSTICKRT:     RJMP USART_TRANSMIT_R
                RJMP USART_TRANSMIT_COMMA

                ADD USER, RIGHT
                CP (USER & LEFT), (CURSOR & LEFT)
                    RJMP DEBOUNCERT
                BRNE BUZZERON

RESETPB:        RJMP LEDOFF
                RJMP DEBOUNCEPB

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


; Routine to turn on the LED
LEDON:          LDI PORTDEF, 0b00000010
                OUT PORTB, PORTDEF
                RET

; Routine to turn off the LED
LEDON:          LDI PORTDEF, 0b00000000
                OUT PORTB, PORTDEF
                RET

; BUZZERON sets the buzzer high (at PortB, Pin 5) and then sits in a loop so
; that the buzzer is low enough frequency to be hearable to the human ear. 
BUZZERON:       LDI PORTDEF, 0b00100000
                OUT PORTB, PORTDEF

                RCALL WASTETIME             ; WASTETIME is a counter that
                                            ; counts to 255 and then returns

                LDI PORTDEF, 0b11011111     ; unce WASTETIME is finished, the
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
                BRNE CNTWASTETIME
                    RET
