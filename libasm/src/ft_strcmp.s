; ---------------------------------
; strcmp - compare two strings
;
; int strcmp(const char *s1, const char *s2);
; ---------------------------------

global ft_strcmp

section .text

ft_strcmp:                            ; rdi = s1, src = s2
          xor   rcx, rcx              ; clear counter -> i = 0
          xor   rax, rax              ; clear s1 temp
          xor   rdx, rdx              ; clear s2 temp

compare_loop:
          mov   al, BYTE [rdi + rcx]  ; copy s1[i] to lower byte AX
          mov   dl, BYTE [rsi + rcx]  ; copy s2[i] to lower byte DX
          
          cmp   al, dl                ; s1[i] == s2[i]
          jne   .subtract             ; if (s1[i] != s2[i])  call .subtract
          
          cmp   al, 0x0               ; s1[i] == '\0'
          je   .subtract              ; if (s1[i] == '\0')  call .subtract

          inc   rcx                   ; i++
          jmp   compare_loop

.subtract:
          sub   rax, rdx              ; s1[i] - s2[i] -> tabela ASCII (libft behavior tested by Moulinette)
          ret