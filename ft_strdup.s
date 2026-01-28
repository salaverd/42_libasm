default rel

global ft_strdup
extern malloc, ft_strlen, ft_strcpy

ft_strdup:
    sub rsp, 8              ; keep stack 16-byte aligned
    mov [rsp], rdi          ; save original string pointer

    call ft_strlen          ; rax = length
    inc rax                 ; +1 for '\0'
    mov rdi, rax
    call malloc wrt ..plt   ; PIE-safe call

    test rax, rax
    je nullptr

    mov rsi, [rsp]          ; src
    mov rdi, rax            ; dst
    call ft_strcpy

    add rsp, 8
    ret

nullptr:
    add rsp, 8
    xor rax, rax
    ret