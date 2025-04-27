global ft_strlen                    ; makes the ft_strlen label visible to the linker

ft_strlen:
	xor		rax, rax                ; set rax to zero

.loop:                              ; . sets local label without it label is global
    cmp     byte [rdi + rax], 0     ; rdi = pointer to the start of the string
    je      .return                 ; if the byte is zero (null terminator), jump to .return
    inc     rax                     ; increment rax number
    jmp     .loop                   ; jump to loop

.return:
    ret                             ; return with rax holding the length