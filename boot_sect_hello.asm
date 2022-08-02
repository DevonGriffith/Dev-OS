mov ah, 0x0e ; tty mode
mov bx, HELLO
;call print

;call print_nl
jmp $ ; jump to current address = infinite loop
HELLO:
    db 'Welcome To Dev-OS...', 0

; padding and magic number
times 510 - ($-$$) db 0
dw 0xaa55 