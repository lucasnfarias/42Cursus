; ---------------------------------
; strdup - duplicate a string
;
; char *strdup(const char *s);
; ---------------------------------

global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy
extern __errno_location

section .text

ft_strdup:                            ; rdi = s
          xor   rax, rax              ; set rax = 0

memory_allocation:
          push  rdi                   ; save input string address on stack memory
          
          call  ft_strlen             ; get string size (number of bytes to allocate)
          mov   rdi, rax              ; move return value of ft_strlen in rdi
          inc   rdi                   ; add one more byte for null terminator

          call  malloc                ; allocate 'rdi' bytes -> malloc(rdi)
          cmp   rax, 0                ; check if malloc has failed
          je    .error_handler        ; if it's wrong, call error handler subroutine (U SHALL NOT PASS!!)

          jmp   .copy_string          ; if it's OK then copy this handsome string

.copy_string:
          pop   rdi                   ; retrieve input string address from stack
          mov   rsi, rdi              ; move input string address to rsi (function's second parameter)
          mov   rdi, rax              ; move newly allocated string to rdi (function's first parameter)
          call  ft_strcpy             ; call ft_strcpy to copy string, return value is on rax

          ret                         ; return rax -> return (new_alloc_string);

.error_handler:
          imul    rax, -1           ; negate rax
          push    rax               ; save rax value on top of the stack
          call    __errno_location  ; set correct errno number
          pop     rdi               ; retrieve rax value from stack and move to rdi
          mov     [rax], rdi
          mov     rax, -1           ; set return value to -1
          ret