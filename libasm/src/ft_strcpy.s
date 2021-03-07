; ---------------------------------
; strcpy - copy a string
;
; char *strcpy(char *dest, const char *src);
; ---------------------------------

global ft_strcpy

section .text

ft_strcpy:                            ; rdi = dest, src = rsi
          xor   rcx, rcx              ; clearing counter -> i = 0
          xor   rdx, rdx              ; set temp string -> tmp = 0
          cmp   rsi, 0                ; check if src is \0 -> !src
          jz    .end                  ; if (!src) return;
          jmp   .copy_loop

.increment:
          inc   rcx                   ; i++

.copy_loop:
          mov   dl, BYTE [rsi + rcx]  ; copy src[i] to lower byte DX
          mov   BYTE [rdi + rcx], dl  ; copy dl to dest
          cmp   dl, 0                 ; check if string ended -> src[i] == '\0'
          jnz   .increment

.end:
          mov   rax, rdi              ; setting dest as return value -> return(dest);
          ret