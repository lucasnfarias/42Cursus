; ---------------------------------
; strlen - calculate the length of a string
;
; size_t	ft_strlen(const char *s);
; ---------------------------------

global    ft_strlen

section   .text
ft_strlen:
            xor     rax, rax                        ; same as setting i = 0
            jmp     compare_char                    ; start comparing characters

increment:
            inc     rax                             ;increment counter

compare_char:
            cmp     BYTE [rdi + rax], 0             ; is str[i] == 0
            jne      increment                      ;call incrementation if str[i] != 0

end:
            ret                                     ;return counter