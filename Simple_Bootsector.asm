mov ah, 0x0e ; tty mode
mov al, 'H'
int 0x10
mov al, 'e'
int 0x10
mov al, 'l'
int 0x10
int 0x10 ; 'l' ; because 'l' is still on al
mov al, 'o'
int 0x10
mov al, ' '
int 0x10
mov al, 'W'
int 0x10
mov al, 'e'
int 0x10
mov al, 'l'
int 0x10
mov al, 'c'
int 0x10
mov al, 'o'
int 0x10
mov al, 'm'
int 0x10
mov al, 'e'
int 0x10

jmp $ ; jump to current address = infinite loop to prevent the program from closing automatically

; padding and magic number as always
times 510 - ($-$$) db 0
dw 0xaa55 ; our ever-present magic number
; Infinite loop (e9 fd ff) (explained above)
loop:
    jmp loop 


