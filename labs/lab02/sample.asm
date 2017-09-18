/*Sample code*/
/* Copy Right Ali Ahmad*/

 ;Include the butterfly definitions for the M169P.
   .INCLUDE "M169PDEF.INC" ;(BUTTERFLY DEFINITIONS)

;PORTDEF is used to initialize the stack and also define the port functionality.
.DEF PORTDEF	= R22
;Counter 1 and 2 are used to waste time so that the buzzer sound is hearable.
.DEF COUNTER	= R23
.DEF COUNTER2	= R24
.ORG $0000
	RJMP START

START:
;Initializes the stack.
LDI PORTDEF, HIGH(RAMEND) ; Upper byte
OUT SPH,PORTDEF ; to stack pointer
LDI PORTDEF, LOW(RAMEND) ; Lower byte
OUT SPL, PORTDEF; to stack pointer

;PORT_INIT initializes the ports for I/O. It is configured so
;that any of the PORT D Pin 7 is used for the push button (input)
;and PIN 1 on PORT B can be used for the LED (output)
;The buzzer is also connected to PORT B (Pin 5) so that is initialized as well.
PORT_INIT:
LDI PORTDEF, 0b00100010
OUT DDRB, PORTDEF
LDI PORTDEF, 0b10000000
OUT PORTD, PORTDEF

;STATE0:
;The very first state where no input has been entered. Will directly call READINPUT
;and wait for user to press the push button. Once the button is pressed, turns on
;the LED and jumps to next state.




;STATE1:
;The second state. Does the same thing as State 0 but this time beeps the for successful 
;push button press.




;STATE2:
;Once a button is pressed, turns off the LED and resets
;Return to state 0



;Routine to turn on the LED
TURNONLED:
	LDI PORTDEF, 0b00000010
	OUT PORTB, PORTDEF
	RET

;Beepnoise sets the buzzer high (at PortB, Pin 5) and then
;sits in a loop so that the buzzer is low enough frequency to be hearable to the
;human ear. 
BEEPNOISE:
	LDI PORTDEF, 0b00100000
	OUT	PORTB, PORTDEF
	;Wastetime is a counter that counts to 255 and then returns.
	RCALL WASTETIME
	;Once wastetime is finished, the buzzer is turned off 
	LDI PORTDEF, 0b11011111
	OUT	PORTB, PORTDEF
	;Wastetime is called again to make the period of the soundwave even lower
	RCALL WASTETIME
	;This whole thing is done 255 times to make the buzzer hearable.
	DEC COUNTER2
		BRNE BEEPNOISE
	RET


;Sits in loop and waits for user to press PIND 7
;If pressed, debounces
READINPUT:
	SBIS PIND, 7
		RJMP DEBOUNCE
	RJMP READINPUT
;Waits for user to stop pressing and then returns.
DEBOUNCE:
	SBIC PIND, 7
		RET
	RJMP DEBOUNCE

;The Wastetime subroutine used to make the buzzer sound hearable. Basically used
;to lower frequence enough so that the sound from the buzzer is hearable.
WASTETIME:
	CLR COUNTER
CONTWASTETIME:
	NOP
	DEC COUNTER
	BRNE CONTWASTETIME
		RET
