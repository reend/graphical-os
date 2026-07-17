[org 0x00]
[bits 16]
 
section .code
 
.init:
    mov eax, 0x07c0
    mov ds, eax
    mov eax, 0xb800
    mov es, eax
    mov eax, 0
    mov ebx, 0
    mov ecx, 0
    mov dl, 0
 
.clear:
    mov byte [es:eax], 0
    inc eax
    mov byte [es:eax], 0xB0
    inc eax
    cmp eax, 2 * 25 * 80
    jl .clear
 
    mov eax, .welcome
    mov ecx, 0 * 2 * 80
    push .end
    call .print
 
.end:
    jmp $
 
.print:
    mov ebx, 0
.print_main:
    mov dl, byte [eax + ebx]
    cmp dl, 0
    je .print_end
    mov byte [es:ecx], dl
    inc ebx
    inc ecx
    inc ecx
    jmp .print_main
 
.print_end:
    ret
 
.welcome: db 'Welcome to SaphireOS.', 0
 
times 510 - ($ - $$) db 0x00
db 0x55
db 0xaa