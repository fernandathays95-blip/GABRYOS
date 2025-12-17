; =========================================
; 3D.ASM - Cubo 3D wireframe simples
; Autor: Eu 😎
; Modo: Real Mode 16-bit
; Vídeo: VGA 320x200x256 (Mode 13h)
; =========================================

[BITS 16]
[ORG 0x100]

start:
    ; entra no modo gráfico
    mov ax, 0x0013
    int 0x10

main_loop:
    call clear_screen
    call rotate_cube
    call draw_cube
    call delay
    jmp main_loop

; -----------------------------------------
; Limpa a tela
; -----------------------------------------
clear_screen:
    mov ax, 0xA000
    mov es, ax
    xor di, di
    mov cx, 320*200
    xor al, al
    rep stosb
    ret

; -----------------------------------------
; Rotação fake (incrementa ângulo)
; -----------------------------------------
rotate_cube:
    inc byte [angle]
    ret

; -----------------------------------------
; Desenha o cubo (wireframe simples)
; -----------------------------------------
draw_cube:
    ; desenha pontos simulando vértices
    mov si, cube_points

.next_point:
    lodsw
    cmp ax, 0xFFFF
    je .done

    mov bx, ax        ; X
    lodsw
    mov dx, ax        ; Y

    call put_pixel
    jmp .next_point

.done:
    ret

; -----------------------------------------
; Desenha pixel
; BX = X , DX = Y
; -----------------------------------------
put_pixel:
    mov ax, 0xA000
    mov es, ax

    mov ax, dx
    mov cx, 320
    mul cx
    add ax, bx
    mov di, ax

    mov al, 15        ; cor branca
    stosb
    ret

; -----------------------------------------
; Delay simples
; -----------------------------------------
delay:
    mov cx, 0xFFFF
.wait:
    loop .wait
    ret

; -----------------------------------------
; Dados
; -----------------------------------------
angle db 0

cube_points:
    ; Quadrado simulando face 3D
    dw 140, 80
    dw 180, 80
    dw 180, 120
    dw 140, 120
    dw 140, 80
    dw 0xFFFF

; -----------------------------------------
; Saída (nunca chega aqui)
; -----------------------------------------
exit:
    mov ax, 0x0003
    int 0x10
    int 0x20
