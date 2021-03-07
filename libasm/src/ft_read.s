; ---------------------------------
; read - read from a file descriptor
;
; ssize_t read(int fd, void *buf, size_t count);
; ---------------------------------

; rax = 0 -> syscall read
; rdi -> fd
; rsi -> buf
; rdx -> count

global ft_read

extern __errno_location

section .data

SYS_READ equ 0                    ; creating constant to syscall number for read

section .text

ft_read:
        mov     rax, SYS_READ     ; set to 0 for syscall read
        syscall                   ; call read

        cmp     rax, 0            ; compare read return value to zero
        jl      .error_handler    ; if (read_return < 0), throw error

        ret                       ; else, simply return

.error_handler:
        imul    rax, -1           ; negate rax
        push    rax
        call    __errno_location  ; set correct errno number
        pop     rdi
        mov     [rax], rdi
        mov     rax, -1           ; set return value to -1
        ret