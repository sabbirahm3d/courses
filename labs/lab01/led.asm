/* test .asm
* Created : 9/4/2012 10:50:44 AM
* Author : rrobucci
*/
// above is the file header comment created by the tool
//. INCLUDE " m169Pdef .inc" // optional , file was included by
// default when device was selected on project creation
// normally here we would define alias for ports , pins , and
// registers used instead of using magic numbers in the code
// LED on PB7 , button on PB6
// LED is "ON" when PB7 is high
// PB6 is low when button is pressed
// Will use R16 as temporary register
.ORG 0x00000
//* may press F1 with cursor over any instruction to see help
//* use F10 to step through code , note IO values that change
//* are highlighted in red
CBI DDRB , 6 // set direction for button
SBI PORTB , 6 // enable pull -up
//* in simulator , use the IOVIEW here and set PINB6 to
//* high to emulate button not being pressed
SBI DDRB , 7 // set direction for LED
//* in the simulator this loop should repeat until PINB6 is
// set low using the IOVIEW
CHECK_BUTTON :
// skips jump back if bit 6 of port B input is set
SBIC PINB , 6
JMP CHECK_BUTTON
LED_BLINK :
// Turn LED ON
SBI PORTB , 7 // sets bit of I/O
// Pause LOOP
// step through a few iterations using F10 and observe
// R16 changing in the processor tab ( highlighted with redn
// upon change )
LDI R16 , 255 // load immediate
BLINK_LOOP_ON :
DEC R16 // decrement R16 , set zero flag if zero reached
BRNE BLINK_LOOP_ON // *set breakpoint here using F9
//* and press F5 to avoid stepping through all loop
// iterations
// Turn LED OFF
CBI PORTB , 7 // clears bit of I/O
LDI R16 ,127 // Pause
BLINK_LOOP_OFF :
DEC R16
BRNE BLINK_LOOP_OFF
JMP LED_BLINK //* using F9 , set breakpoints on the SBI and
// CBI code lines above and repeatedly
// press F5 to see the LED pin toggle