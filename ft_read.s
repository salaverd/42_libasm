global ft_read
extern ___error

ft_read:
    mov rax, 0          ; syscall number for read (Linux)
    syscall             ; perform the syscall
    cmp rax, 0
    jl .error           ; if return value < 0, jump to error handler
    ret

.error:
    push rax            ; save error code (rax < 0)
    call ___error       ; get address of errno
    pop qword [rax]     ; set *errno = error code (stored in rax)
    mov rax, -1         ; return -1 to signal failure
    ret