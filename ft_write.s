default rel

global ft_write
extern ___error

; ft_write:                           ; rdi = file descriptor, rsi = string, rdx = byte count
;     mov rax, 0x2000004              ; write system call which address is in rax
;     syscall                         ; execute system call from rax
;     jc .err                         ; jump if carry flag is set (syscall failed)
;     ret

ft_write:
    mov rax, 1              ; syscall: write
    syscall
    test rax, rax
    jge .ok                 ; if rax >= 0 -> success

    ; -------- error path -------
    neg rax                 ; rax = errno (positive)
    mov rdi, rax            ; save errno value

    sub rsp, 8              ; align stack before call
    call ___error wrt ..plt ; rax = &errno
    add rsp, 8

    mov [rax], edi          ; *errno = errno
    mov rax, -1
    ret

.ok:
    ret