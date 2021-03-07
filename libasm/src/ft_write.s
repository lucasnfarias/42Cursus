; ---------------------------------
; write - write to a file descriptor
;
; ssize_t write(int fd, const void *buf, size_t count);
; ---------------------------------

; rax = 1 -> syscall write
; rdi -> fd
; rsi -> buf
; rdx -> count

global ft_write
extern __errno_location

section .data

SYS_WRITE equ 1                   ; creating constant to syscall number for write

section .text

ft_write:
        mov     rax, SYS_WRITE    ; set to 1 for syscall write
        syscall                   ; call write

        cmp     rax, 0            ; compare write return value to zero
        jl      .error_handler    ; if (write_return < 0), throw error

        ret                       ; else, simply return

.error_handler:
        imul    rax, -1           ; negate rax
        push    rax
        call    __errno_location  ; set correct error
        pop     rdi
        mov     [rax], rdi
        mov     rax, -1
        ret