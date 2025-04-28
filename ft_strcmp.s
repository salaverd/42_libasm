global ft_strcmp

ft_strcmp:                 ;rsi = s1, rdi = s2
    xor     rax, rax            ;rax = 0
    xor     rcx, rcx            ;rcx = 0
    
.loop:
    mov     al, [rdi]       ;Move the current byte of the s1 to the top of the RAX register (lower 
    mov     cl, [rsi]       ;Move the current byte of the s2 to the top of the RСX register (lower 
    cmp     ax, 0
    je      .end
    cmp     al, cl
    jne     .end
    inc     rdi
    inc     rsi
    jmp     .loop

.end:
    sub rax, rcx            ; substract the value of the second string byte from rax content
    ret                     ; return the rax content