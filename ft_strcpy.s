global ft_strcpy

ft_strcpy:                                  ; rdi = s1, rsi = s2
    xor rcx, rcx                 
    xor r8, r8
.loop:
    mov r8b, byte[rsi + rcx]                ; move the current byte of the source string to the buffer
    mov byte[rdi + rcx], r8b                ; move the current byte of the source string from the buffer to the byte with the same index to the destination string
    cmp r8b, 0                              ; compare with zero (null terminator)
    je .return                              
    inc rcx                                 
    jmp .loop
    
.return:
    mov rax, rdi
    ret