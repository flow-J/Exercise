data segment
tab db'hello wordl$'
data ends
code segment
assume cs:code, ds:data
start:
    mov ax,data
    mov ds,ax
    lea dx,tab
    mov ah,9h
    int 21h
    mov ah,4ch
    int 21h
code ends
    end start
