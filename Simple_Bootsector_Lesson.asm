; The bootsector is the first sector of the disk (cylinder 0, head 0, sector 0) and it takes 512 bytes.

; To make sure that the "disk is bootable", the BIOS checks that bytes 511 and 512 of the alleged boot sector are bytes 0xAA55.

; Here is the assembly code for a simple bootsector:

; Infinite loop (e9 fd ff) to keep the bootsector open until we want to close it. 
loop:
    jmp loop 

; Fill with 510 zeros minus the size of the previous code (to make up the remaining bytes so the bootsector is 512 bytes, like it should be).
times 510-($-$$) db 0
; add the Magic number as always!
dw 0xaa55 
