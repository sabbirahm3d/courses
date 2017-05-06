%include "mine.inc"

global main
extern printf

         section .text


;================================================================================
; Get the args from the command line -- which should include only the file name.
;================================================================================
GetCommandLine:

         Enter 0
         Push_Regs ebx, ecx, edx

; Write NULL into the filename pointer arg given on the stack so the caller 
; (main) can exit with an error. 

         mov ebx, [ebp + 8]
         mov [ebx], dword 0

; Get argument count. Remember I pushed an arg and the return address and ebp are 
; at the top of the stack -- so argc is at offset 16 and an pointer to an array
; of pointers at 20. The first element is the program name. The other args are
; at positions 2 through n. In our case, only one arg is given -- the data file
; name. THIS ASSUMES gcc is used to link -- when ld is used, the stack is set up
; differently (see the nasm slides).

         mov ecx, [ebp + 16]

Make_Local_Str temp_gcl1_len, temp_gcl1_str, 'Argument count is %d', 10, 0
C_Sys_Call printf, 2, temp_gcl1_str, ecx
%ifdef DEBUG
%endif

; Check the value of argc. It should be exactly 2 -- which includes the program
; name and the data file name. 

         cmp ecx, 2
         if ne
            jmp gcl_done
         endif
         
mov ecx, [ebp + 20]
mov ebx, [ecx]
Make_Local_Str temp_gcl2_len, temp_gcl2_str, 'Program name is %s', 10, 0
C_Sys_Call printf, 2, temp_gcl2_str, ebx
%ifdef DEBUG
%endif

         mov ecx, [ebp + 20]
         mov ebx, [ecx + 4]

Make_Local_Str temp_gcl3_len, temp_gcl3_str, 'Filename is %s', 10, 0
C_Sys_Call printf, 2, temp_gcl3_str, ebx
%ifdef DEBUG
%endif

; Set the filename pointer arg on the stack to the address of the filename,
; also on the stack but at a different position.

         mov edx, [ebp + 8]
         mov [edx], ebx

gcl_done:

         Pop_Regs ebx, ecx, edx
         Leave
         ret


;================================================================================
;===================================== MAIN =====================================
;================================================================================

   section .data
input_filename_ptr:  dd 0

   section .text
main:
         push dword input_filename_ptr
         call GetCommandLine
         add esp, 4

; Check the filename for NULL and exit if so.

         cmp [input_filename_ptr], dword 0
         if e
            Make_Local_Str no_filename_len, no_filename_str, 'NULL filename ! Usage "mine filename"', 10, 0
            C_Sys_Call printf, 1, no_filename_str
            Sys_Exit -1
         endif

; REMEMBER -- IN THE CALL TO open -- YOU MUST DEREFERENCE [input_filename_ptr] SINCE
; input_filename_ptr IS A POINTER CONTAINING THE ADDRESS OF THE COMMAND LINE 
; FILENAME STRING.


