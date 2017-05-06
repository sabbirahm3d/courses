;; Code to print out an integer using printf
;; In this example the value in register eax is printed out
;; Assemble with NASM:	 nasm -f elf print_int.asm
;; Link with gcc:	gcc print_int.o
	
extern printf
	
	section .data
	
str1:	db 'The integer is %d',10,0
len1:	equ $-str1
	
	section .text
	global main		; use main instead of _start

	
main:	mov eax, 100 		; move some value into eax
	push eax		; push eax on the stack
	push dword str1		; push the sting on the stack
	call printf		; call printf
	add esp, byte 8		; remove the parameters from the stack

	mov eax, 1		; good old exit
	mov ebx, 0
	int 0x80
	