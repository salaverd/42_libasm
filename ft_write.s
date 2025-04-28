global ft_write
extern ___error

; ft_write:                           ; rdi = file descriptor, rsi = string, rdx = byte count
;     mov rax, 0x2000004              ; write system call which address is in rax
;     syscall                         ; execute system call from rax
;     jc .err                         ; jump if carry flag is set (syscall failed)
;     ret
ft_write:                           ; rdi = file descriptor, rsi = string, rdx = byte count
    mov rax, 1                      ; syscall number for write (Linux)
    syscall                         ; perform syscall
    cmp rax, 0
    jl .err                         ; jump if result < 0 (error)
    ret

.err:
    push rax                        ; rax value saved in the stack
    call ___error                   ; calling external error handler
    pop qword[rax]                  ; poping saved value from the stack into rax
    mov rax, -1
    ret