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
move al,
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
mov al, '...'
int 0x10

jmp $ ; jump to current address = infinite loop to prevent the program from closing automatically

; padding and magic number as always
times 510 - ($-$$) db 0
dw 0xaa55 
; Infinite loop (e9 fd ff) (explained above)
loop:
    jmp loop 

; Fill with 510 zeros minus the size of the previous code to fill the 512 Bytes needed in the bootsector
times 510-($-$$) db 0
; Magic number as always
dw 0xaa55



; Now it's time to run the bootsector and see our work:

; nasm -fbin boot_sect_hello.asm -o boot_sect_hello.bin
; qemu boot_sect_hello.bin
