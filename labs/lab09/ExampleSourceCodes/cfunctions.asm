	;; NASM program to read from cmd line arg, open file, read first line, and print first line to screen
	;;	Uses fopen, fscanf, and printf
	;; For help using the stack to write subroutines, consult the assembly lecture "Stack Basics and Procedure Calls"

	;; nasm -f elf cfunctions.asm
	;; gcc cfunctions.o
	;; a.out input.txt
	
	
%include "mine.inc"
	
extern printf
extern fopen
extern fscanf

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_READ  3
%define SYSCALL_WRITE 4

	
global main

section .data
		
read_char:	db 'r', 0
format:		db "%d",10,0
filename:	dd 0
file_pointer:	dd 0
number:		dd 0
string:	        db "The integer is %d",10,0	
	
section .text

main:

	;; Get the filename, pointer to input filename is returned, will equal 0 for an invalid filname
	push	dword filename	; Push address of the pointer to the filename
	call	GetCommandLine	; Return address pushed to stack, Go to line 72, GetCommandLine
	add	esp, 4		; Resets stack value (equivalent to 'pop' inst)

	;; (You need to insert code here to error check filename)
	
	;; Open the file using fopen
	;; Equivalent to eax = fopen("input.txt", "r") if programmed in C
	push    dword read_char	; "r" to open a file for reading
	push    dword [filename] ; filename from cmd line arg
	call    fopen
	add     esp, 8

	;; Error check fstream returned from fopen
	cmp	eax, 0
	je	Exit		
	mov	[file_pointer], eax

	;; Read a value from the file using fscanf
	push	dword number	; Address of 'number'
	push    dword format	; %d to read an integer
	push    dword [file_pointer] ; fstream from fopen
	call    fscanf
	add     esp, 12

	;; Print first line from file
	push    dword [number]
	push    dword string
	call    printf
	add     esp, 8
	

Exit:	
	mov     EAX, SYSCALL_EXIT       
        mov     EBX, 0                
        int     080h                    
	ret		

GetCommandLine:

	;; Macros to move esp into ebp and push regs to be saved
         Enter 0
         Push_Regs ebx, ecx, edx

	;; Initially sets [filename] to 0, remains 0 if there's an error
         mov ebx, [ebp + 8]
         mov [ebx], dword 0

	;; Get argc (# of arguments)
         mov ecx, [ebp + 16]

	;; Checks the value of argc, should be 2 (a.out and input.txt), includes the if statement macro
         cmp ecx, 2
         if ne
            jmp gcl_done
         endif

	;; Get argv[0] ("a.out"/"cfunctions" or the executable, this is not used in the project)
	;; Consult slide 6 of Stack Basics... lecture
	 mov ecx, [ebp + 20]   	;  ptr to args ptr
	 mov ebx, [ecx]		;  argv[0]

	;; Get argv[1] ("input.txt")
         mov ecx, [ebp + 20]	; ptr to args ptr
         mov ebx, [ecx + 4]	; argv[1]

	;; Set the filename pointer arg on the stack to the address of the filename
         mov edx, [ebp + 8]
         mov [edx], ebx

gcl_done:
	;; Macros to return
         Pop_Regs ebx, ecx, edx
         Leave

	;; Return
         ret
