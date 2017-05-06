; Demonstrates the proper way to call printf to print floating
; point numbers and also demonstrates scaled index addressing
; mode. NOTE: YOU CAN NOT USE the 16-bit registers, ax, bx, etc 
; in any of the complex addressing modes. You get an error 
; "invalid effective address" or
; "ELF format does not support non-32-bit relocations" 

global main
extern printf

section .data                           ;section declaration

; An array of two floating point numbers initialized to 23.25.

         myfloatarr times 2 dd 23.25
         myfloatstr db 'This number -> %f <- should be 23.25', 10, 0

section .text
main:


; Simple example of scaled index addressing mode.

         mov ebx, 1
         fld dword [ebx*4 + myfloatarr]

; Allocate 8 bytes of stack space. Loading st0 and popping it 
; converts the single precision number to double precision, which
; printf expects.

         sub esp, byte 8
         fstp qword [esp]
         push dword myfloatstr
         call printf
         add esp, byte 12

