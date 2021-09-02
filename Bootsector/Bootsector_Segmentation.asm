mov ah, 0x0e ; tty

mov al, [the_code]
int 0x10 ; We know this doesn't work already.

mov bx, 0x7c0 ; The segment is automatically <<4 for you.
mov ds, bx ; Segmentation step
; WARNING: all memory references will be offset by 'ds' implicitly (what segmentation refers to)!
mov al, [the_code]
int 0x10

mov al, [es:the_code]
int 0x10 ; This is not right: 'es' currently is 0x000?

mov bx, 0x7c0
mov es, bx
mov al, [es:the_code]
int 0x10


jmp $ ; Jump to $.

the_code: ; Defining "the_code" as "X".
    db "X"

times 510 - ($-$$) db 0
dw 0xaa55
