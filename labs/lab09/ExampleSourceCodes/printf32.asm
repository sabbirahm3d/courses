;; To compile and run on 32-bit machine:
;;		nasm -f elf printf32.asm
;;		gcc -m32 -o printf32.out printf32.o
;;		./printf32.out
;; If running on a 32-bit linux machine -m32 flag is not needed
;; If running on your own 64-bit machine and receive errors when performing gcc
;; then you most likely don't have 32-bit libraries. Run the following commands in terminal 
;; sudo apt-get install gcc-multilib libc6-i386 libc6-dev-i386

%define SYS_EXIT 1
%define EXIT_SUCCESS 0
%define EXIT_FAILURE 1 

extern printf

section .data

	str:		db	"Hello world (32-bit)",10,0	;Ending 0 is needed to indicate end of string for C routines
	fmt_str:	db 	"Printing a string %s",10,0

	num:		dd	32	
	fmt_num:	db	"Printing a number %d",10,0

section .text

	global main

main:

	push    ebp				;Save stack state
    mov     ebp, esp

	push dword str			;Push format string argument onto stack
	push dword fmt_str		;Push formatting string onto stack
	call printf 			;Display results	
	add esp, 8				;Pop stack 2 times 4 bytes -> 8

	push dword [num]		;Push format string argument onto stack
	push dword fmt_num		;Push formatting string onto stack
	call printf 			;Display results	
	add esp, 8				;Pop stack 2 times 4 bytes -> 8

	mov esp, ebp			;Restore stack state
	pop ebp

	mov eax, SYS_EXIT		;Perform system exit
	mov ebx, EXIT_SUCCESS	;Exit success
	int 0x80				;Call OS
