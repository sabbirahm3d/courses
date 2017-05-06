;; To compile and run (must be a 64-bit linux machine):
;;		nasm -f elf64 printf64.asm
;;		gcc -o printf64.out printf64.o
;;		./printf64.out

%define SYS_EXIT 1
%define EXIT_SUCCESS 0
%define EXIT_FAILURE 1 

extern printf

section .data

	str:		db	"Hello world (64-bit)",10,0	;Ending 0 is needed to indicate end of string for C routines
	fmt_str:	db 	"Printing a string %s",10,0

	num:		dd	32	
	fmt_num:	db	"Printing a number %d",10,0

section .text

	global main

main:

	push    rbp				;Save stack state
    mov     rbp, rsp

	mov edi, fmt_str		;Place formating string in r/edi
	mov esi, str		 	;Place format string argument in r/esi
	mov eax, 0				;Tell printf # floating-point arguments used
	call printf 			;Display results	

	mov edi, fmt_num		;Place formating string in r/edi
	mov esi, [num]			;Place format string argument in r/esi
	mov eax, 0				;Tell printf # floating-point arguments used
	call printf 			;Display results

	mov rsp, rbp			;Restore stack state
	pop rbp

	mov eax, SYS_EXIT		;Perform system exit
	mov ebx, EXIT_SUCCESS	;Exit success
	int 0x80				;Call OS
