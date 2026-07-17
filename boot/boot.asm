[org 0x00]
[bits 16]
 
section code
 
.init:
    mov eax, 0x07c0
    mov ds, eax
    mov eax, 0xb800
    mov es, eax
    mov eax, 0        ; i = 0
    mov ebx, 0        ; index into the string
    mov ecx, 0        ; address in video memory
    mov dl, 0         ; current character
 
.clear:
    mov byte [es:eax], 0
    inc eax
    mov byte [es:eax], 0x30
    inc eax
 
    cmp eax, 2 * 25 * 80
    jl .clear
 
    mov eax, text1
    call .print       ; Call the print routine
    ;call .print      ; Optional second call
 
.end:
    jmp $             ; Hang here forever (simple infinite loop)
 
.print:
    mov dl, byte [eax + ebx]
    cmp dl, 0
    je .print_end
 
    mov byte [es:ecx], dl
 
    inc ebx
    inc ecx
    inc ecx
 
    jmp .print
 
.print_end:
    ret               ; Return to the instruction after 'call .print'
 
text:  db 'Hello, World!,', 0
text1: db 'This is another text', 0
 
times 510 - ($ - $$) db 0x00
db 0x55
db 0xaa