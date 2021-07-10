mov ah, 0x0e

; Attempt 1 to access the memory
; Fails because it tries to print the memory address (pointer)
; not the actual contents
mov al, "1"
int 0x10
mov al, the_code
int 0x10

; Attempt 2
; It tries to print the memory address of 'the_code' which is the proper way.
; But, BIOS places our bootsector binary at address ** 0x7c00 **,
; we need to add that padding beforehand. We will do that next.
mov al, "2"
int 0x10
mov al, [the_code]
int 0x10

; Attempt 3
; Add the BIOS starting offset 0x7c00 to the memory address of the X
; and then dereference the contents of that pointer.
; We need the help of a different register 'bx' because 'mov al, [ax]' is illegal in assembly.
; A register cannot be used as source and destination for the same command.
mov al, "3"
int 0x10
mov bx, the_code
add bx, 0x7c00
mov al, [bx]
int 0x10

; Attempt 4
; We will try a shortcut (we know that the X is stored at byte 0x2d in our binary)
; That's smart but does not work, we don't want to be recounting label offsets every code change.
mov al, "4"
int 0x10
mov al, [0x7c2d]
int 0x10


jmp $ ; infinite loop

the_code:
    ; ASCII code 0x58 ('X') is stored just before the zero-padding.
    ; On this code that is at byte 0x2d (check it out using 'xxd file.bin')
    db "X"

; zero padding and magic bios number as we always use.
times 510-($-$$) db 0
dw 0xaa55
