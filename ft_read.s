default rel

global ft_read
extern ___error

ft_read:
    mov rax, 0              ; syscall: read
    syscall
    test rax, rax
    jge .ok                 ; success if rax >= 0

    ; -------- error path --------
    neg rax                 ; rax = errno
    mov rdi, rax

    sub rsp, 8              ; align stack
    call ___error wrt ..plt
    add rsp, 8

    mov [rax], edi
    mov rax, -1
    ret

.ok:
    ret