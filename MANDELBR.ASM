    ;Fractal entry point

;Set some global definitions
MAX_ITERATIONS equ 48
COLOR_PALLETE equ 0x800000
TMP_BUFFER equ 0xC00000

    ;Create color pallete
    xor eax,eax
    xor ecx,ecx
    mov edi,COLOR_PALLETE
    cld
    jmp savecolor
nextcolor:
    cmp cl,0x10
    jae shiftpallete1
    mov ah,cl
    shl ah,0x03
    mov al,ah
    shl eax,0x08
    mov al,cl
    shl al,0x02
    add al,0x80
    jmp savecolor
shiftpallete1:
    cmp cl,0x40
    jae shiftpallete2
    mov ah,cl
    add ah,0x70
    mov al,ah
    shl eax,0x08
    mov al,cl
    add al,0xB0
    jmp savecolor
shiftpallete2:
    push ecx
    mov ch,0xFF
    sub cl,0x40
    sub ch,cl
    mov ah,ch
    mov al,ch
    shr al,0x01
    add al,0x80
    shl eax,0x08
    mov al,ch
    pop ecx
savecolor:
    stosd
    inc ecx
    cmp ecx,0x400000
    jbe nextcolor
    
    ;Start calculation
    movapd xmm5,[zoom]	;Global xmm5 is zoom
    xorps xmm7,xmm7	;Global xmm7 is pixel position
repeat:
    ;Main loop, xmm0=screen_to_complex_plane(xmm7)
    movapd xmm0,xmm7
    subpd xmm0,[center]
    divpd xmm0,xmm5

    mov ecx,0x01
    movapd xmm6,xmm0
    ;Iterate
nextiteration:
    ;Compute xmm0=xmm0^2+xmm6
    movapd xmm1,xmm0
    mulpd xmm1,xmm1
    hsubpd xmm1,xmm1
    movapd xmm2,xmm0
    shufpd xmm2,xmm2,0x01
    mulpd xmm0,xmm2
    addpd xmm0,xmm0
    movsd xmm0,xmm1

    addpd xmm0,xmm6

    ;Diverge to infinity ?
    movapd xmm1,xmm0
    mulpd xmm1,xmm1
    haddpd xmm1,xmm1
    ucomisd xmm1,[infinity]
    jae draw
    
    ;Next iteration
    inc ecx
    cmp ecx,MAX_ITERATIONS
    jb nextiteration

    xor ecx,ecx
draw:
    ;Get color and save it to buffer
    mov eax,[COLOR_PALLETE+ecx*0x04]
    movapd xmm0,xmm7
    mulpd xmm0,[linearizepixels]
    haddpd xmm0,xmm0
    cvtsd2si edi,xmm0
    mov [TMP_BUFFER+edi*0x04],eax

    ;Increment screen index x in xmm7
    addpd xmm7,[incX]
    comisd xmm7,[screenX]
    jb repeat
    movlpd xmm7,[zero]
    
    ;Increment screen index y in xmm7
    addpd xmm7,[incY]
    movapd xmm0,xmm7
    shufpd xmm0,xmm0,0x01
    ucomisd xmm0,[screenY]
    jb repeat
    xorps xmm7,xmm7

    ;Pseudo v-sync
    xor edi,edi
    mov esi,TMP_BUFFER
    mov ecx,1280*1024 ;76800
    push es
    mov ax,SELECTOR_LFB
    mov es,ax
    rep movsd
    pop es

    ;TODO: zoom in and repeat calculation
halt:
    cli
    hlt
    jmp halt

ALIGN 0x10
incX dq 1.0,0.0
incY dq 0.0,1.0
screenX dq 1280.0
screenY dq 1024.0
center dq 640.0,512.0
zoom dq 250.0,250.0
linearizepixels dq 1.0,1280.0
infinity dq 4.0
zero dq 0.0
