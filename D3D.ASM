; **************************************************
; ****************** SEGY OS D3D *******************
; **************************************************

; Global def: All matrices are 4x4 and all vectors are 4 component (x,y,z,w)
; Global def: Resolution is 640x480x8bpp, constant perspective projection
; Some dictionary for shortcuts:
; TRS = model matrix = translate * rotate * scale
; VPM = view-projection matrix = projection * (view=camera)
; MVP = VPM * TRS = projection * (view=camera) * translate * rotate * scale
; PPM = perspective projection matrix (perspective projector)
; CBB = current bound buffer
; CBM = current bound matrix
; CBC = current bound color
; LFB = linear frame buffer
; VAO = vertex array object
; VBO = vertex buffer object
; EBO = element buffer object

; void=D3D_BindBuffer(eax=&buffer);	  -binds buffer for future use
; void=D3D_ClearBuffer(void);		  -clears CBB
; void=D3D_SwapBuffers(void);		  -copies CBB to LFB
; void=D3D_BindColor(eax=color);	  -binds color for future drawing
; void=D3D_DrawLine(xmm3,xmm4);		  -draws line to CBB with CBC
; void=D3D_DrawTriangle(xmm5,xmm6,xmm7);  -draws triangle to CBB with CBC
; void=D3D_BindMatrix(eax=&matrix);	  -binds matrix for future use
; xmm0=D3D_TransformateVector(xmm3);	  -transformates vector with CBM
; void=D3D_MultiplyMatrix(eax=&matrix);   -multiplies CBM with given matrix
; void=D3D_ModelMatrix(eax=&model);	  -compute model matrix to CBM
; void=D3D_CameraMatrix(eax=&camera);	  -compute camera matrix to CBM
; void=D3D_PerspectiveMatrix(void);	  -compute perspective matrix to CBM
; void=D3D_RenderArrays(eax=&VAO);	  -draws VAO, CBM is used as MVP
; void=D3D_VerticalSync(void);		  -simple vsync, call after rendering
; Note: D3D_DrawLine, D3D_DrawTriangle: high 64 bits of registers are ignored

; struct align<0x10> matrix {
;     __m128[0x04];
; };
; struct align<0x10> model {
;     __m128 position;
;     __m128 rotation;
;     __m128 scale;
; };
; struct align<0x10> camera {
;     __m128 position;
;     __m128 rotation;
; };
; struct align<0x10> VBO {
;     __m128 vertices[];
;     dword 0xFFFFFFFF;
; };
; struct EBO {
;     int32 indices[];
;     dword 0xFFFFFFFF;
; };
; struct VAO {
;     VBO*;
;     EBO*;
; };

D3D_BindBuffer:
    xchg [D3D_Buffer],eax
    ret

D3D_ClearBuffer:
    mov ebx,[D3D_Buffer]
    xorps xmm0,xmm0
    mov ecx,640*480
D3D_ClearBuffer0:
    movaps [ebx+ecx],xmm0
    sub ecx,0x10
    jnz D3D_ClearBuffer0
    movaps [ebx],xmm0
    ret

D3D_SwapBuffers:
    mov ebx,[D3D_Buffer]
    mov edi,640*480
    push fs
    mov ax,SELECTOR_LFB
    mov fs,ax
D3D_SwapBuffers0:
    movaps xmm0,[ebx+edi]
    movaps [fs:edi],xmm0
    sub edi,0x10
    jnz D3D_SwapBuffers0
    movaps xmm0,[ebx]
    movaps [fs:0x00],xmm0
    pop fs
    ret

D3D_BindColor:
    xchg [D3D_Color],eax
    ret

D3D_DrawLine:
    subps xmm4,xmm3
    xorps xmm0,xmm0
    movaps xmm2,xmm4
    subps xmm0,xmm4
    maxps xmm2,xmm0
    comiss xmm4,[D3D_Fp0]
    jae D3D_DrawLine0
    movss xmm5,[D3D_Fm1]
    jmp D3D_DrawLine1
D3D_DrawLine0:
    movss xmm5,[D3D_Fp1]
D3D_DrawLine1:
    movaps xmm0,xmm4
    shufps xmm0,xmm0,0x01
    comiss xmm0,[D3D_Fp0]
    jae D3D_DrawLine2
    movss xmm0,[D3D_Fm1]
    jmp D3D_DrawLine3
D3D_DrawLine2:
    movss xmm0,[D3D_Fp1]
D3D_DrawLine3:
    movaps xmm1,xmm2
    shufps xmm1,xmm1,0x01
    unpcklps xmm5,xmm0
    divss xmm1,xmm2
    comiss xmm1,[D3D_Fp1]
    jae D3D_DrawLine4
    movss xmm0,[D3D_Fp1]
    cvtss2si ecx,xmm2
    shufps xmm1,xmm1,0x00
    movss xmm1,xmm0
    mulps xmm5,xmm1
    jmp D3D_DrawLine5
D3D_DrawLine4:
    shufps xmm2,xmm2,0x01
    divss xmm5,xmm1
    cvtss2si ecx,xmm2
D3D_DrawLine5:
    mov ebx,[D3D_Buffer]
    inc ecx
    mov edi,[D3D_Color]
D3D_DrawLine6:
    cvtss2si eax,xmm3
    movaps xmm0,xmm3
    cmp eax,640
    jae D3D_DrawLine7
    shufps xmm0,xmm0,0x01
    cvtss2si edx,xmm0
    cmp edx,480
    jae D3D_DrawLine7
    imul edx,640
    add edx,eax
    mov ax,di
    mov [ebx+edx],al
D3D_DrawLine7:
    addps xmm3,xmm5
    loop D3D_DrawLine6
    ret
    
D3D_DrawTriangle:
    movsd [D3D_Temp+0x08],xmm5
    movsd xmm3,xmm5
    movsd xmm4,xmm6
    call D3D_DrawLine
    movsd xmm3,xmm6
    movsd xmm4,xmm7
    call D3D_DrawLine
    movsd xmm3,xmm7
    movsd xmm4,[D3D_Temp+0x08]
    call D3D_DrawLine
    ret
    
D3D_BindMatrix:
    xchg [D3D_Matrix],eax
    ret
    
D3D_TransformateVector:
    mov ebx,[D3D_Matrix]
    movaps xmm0,xmm3
    movaps xmm1,xmm3
    mulps xmm0,[ebx]
    movaps xmm2,xmm3
    mulps xmm1,[ebx+0x10]
    haddps xmm0,xmm0
    mulps xmm2,[ebx+0x20]
    haddps xmm1,xmm1
    haddps xmm0,xmm0
    mulps xmm3,[ebx+0x30]
    haddps xmm1,xmm1
    haddps xmm2,xmm2
    haddps xmm3,xmm3
    haddps xmm2,xmm2
    haddps xmm3,xmm3
    unpcklps xmm0,xmm1
    unpckhps xmm2,xmm3
    shufps xmm0,xmm2,0xE4
    ret
    
D3D_MultiplyMatrix:
    movaps xmm0,[eax]
    movaps xmm1,[eax+0x10]
    movaps xmm2,[eax+0x20]
    xor ecx,ecx
    movaps xmm3,[eax+0x30]
    mov ebx,[D3D_Matrix]
D3D_MultiplyMatrix0:
    movss xmm4,[ebx+ecx]
    movss xmm5,[ebx+ecx+0x04]
    shufps xmm4,xmm4,0x00
    movss xmm6,[ebx+ecx+0x08]
    shufps xmm5,xmm5,0x00
    movss xmm7,[ebx+ecx+0x0C]
    shufps xmm6,xmm6,0x00
    shufps xmm7,xmm7,0x00
    mulps xmm4,xmm0
    mulps xmm5,xmm1
    mulps xmm6,xmm2
    mulps xmm7,xmm3
    addps xmm4,xmm5
    addps xmm6,xmm7
    addps xmm4,xmm6
    movaps [ebx+ecx],xmm4
    add ecx,0x10
    cmp ecx,0x40
    jb D3D_MultiplyMatrix0
    ret

D3D_ModelMatrix:
    mov ebx,[D3D_Matrix]
    fld dword[eax+0x10+0x00]
    fsin
    fstp dword[D3D_Temp]
    movss xmm2,[D3D_Temp]
    fld dword[eax+0x10+0x04]
    fsin
    fstp dword[D3D_Temp]
    movss xmm3,[D3D_Temp]
    fld dword[eax+0x10+0x08]
    fsin
    fstp dword[D3D_Temp]
    movss xmm4,[D3D_Temp]
    fld dword[eax+0x10+0x00]
    fcos
    fstp dword[D3D_Temp]
    movss xmm5,[D3D_Temp]
    fld dword[eax+0x10+0x04]
    fcos
    fstp dword[D3D_Temp]
    movss xmm6,[D3D_Temp]
    fld dword[eax+0x10+0x08]
    fcos
    fstp dword[D3D_Temp]
    movss xmm7,[D3D_Temp]
    movss xmm0,[eax+0x20]
    mulss xmm0,xmm7
    mulss xmm0,xmm6
    movss [ebx+0x10*0x00+0x04*0x00],xmm0
    movss xmm1,xmm7
    mulss xmm1,xmm3
    movss xmm0,xmm4
    mulss xmm1,xmm2
    mulss xmm0,xmm5
    addss xmm1,xmm0
    mulss xmm1,[eax+0x20]
    movss [ebx+0x10*0x01+0x04*0x00],xmm1
    movss xmm0,xmm4
    movss xmm1,xmm7
    mulss xmm0,xmm2
    mulss xmm1,xmm3
    mulss xmm1,xmm5
    subss xmm0,xmm1
    mulss xmm0,[eax+0x20]
    movss [ebx+0x10*0x02+0x04*0x00],xmm0
    movss xmm1,[eax+0x24]
    mulss xmm1,xmm4
    mulss xmm1,[D3D_Fm1]
    mulss xmm1,xmm6
    movss [ebx+0x10*0x00+0x04*0x01],xmm1
    movss xmm0,xmm7
    movss xmm1,xmm4
    mulss xmm0,xmm5
    mulss xmm1,xmm3
    mulss xmm1,xmm2
    subss xmm0,xmm1
    mulss xmm0,[eax+0x24]
    movss [ebx+0x10*0x01+0x04*0x01],xmm0
    mulss xmm4,xmm3
    mulss xmm7,xmm2
    mulss xmm4,xmm5
    addss xmm4,xmm7
    mulss xmm4,[eax+0x24]
    movss [ebx+0x10*0x02+0x04*0x01],xmm4
    mulss xmm3,[eax+0x28]
    movss [ebx+0x10*0x00+0x04*0x02],xmm3
    mulss xmm2,xmm6
    mulss xmm2,[D3D_Fm1]
    mulss xmm2,[eax+0x28]
    movss [ebx+0x10*0x01+0x04*0x02],xmm2
    mulss xmm5,xmm6
    mulss xmm5,[eax+0x28]
    movss [ebx+0x10*0x02+0x04*0x02],xmm5
    movss xmm0,[eax]
    movss xmm1,[eax+0x04]
    movss xmm2,[eax+0x08]
    movss [ebx+0x10*0x00+0x04*0x03],xmm0
    movss [ebx+0x10*0x01+0x04*0x03],xmm1
    movss [ebx+0x10*0x02+0x04*0x03],xmm2
    movaps xmm0,[D3D_Identic+0x30]
    movaps [ebx+0x30],xmm0
    ret

D3D_CameraMatrix:
    mov ebx,[D3D_Matrix]
    fld dword[eax+0x10]
    fsin
    fstp dword[D3D_Temp]
    movss xmm3,[D3D_Temp]
    fld dword[eax+0x14]
    fsin
    fstp dword[D3D_Temp]
    movss xmm4,[D3D_Temp]
    fld dword[eax+0x10]
    fcos
    fstp dword[D3D_Temp]
    movss xmm5,[D3D_Temp]
    fld dword[eax+0x14]
    fcos
    fstp dword[D3D_Temp]
    movss xmm6,[D3D_Temp]
    xorps xmm0,xmm0
    movaps xmm2,[D3D_Fm1]
    xorps xmm1,xmm1
    shufps xmm0,xmm4,0x44
    mulps xmm0,xmm2
    movss xmm0,xmm6
    movaps [ebx],xmm0
    movss xmm1,xmm3
    mulss xmm1,xmm4
    movss xmm7,xmm6
    unpcklps xmm1,xmm5
    mulss xmm7,xmm3
    shufps xmm1,xmm7,0x44
    movaps xmm7,xmm1
    mulps xmm7,xmm2
    movaps [ebx+0x10],xmm7
    mulss xmm3,xmm2
    mulss xmm4,xmm5
    movaps xmm7,[eax]
    unpcklps xmm4,xmm3
    mulss xmm5,xmm6
    shufps xmm4,xmm5,0x44
    movaps [ebx+0x20],xmm4
    mulps xmm0,xmm7
    mulps xmm1,xmm7
    mulps xmm4,xmm7
    haddps xmm0,xmm0
    haddps xmm1,xmm1
    haddps xmm4,xmm4
    haddps xmm0,xmm0
    haddps xmm1,xmm1
    mulss xmm0,xmm2
    haddps xmm4,xmm4
    movss [ebx+0x10*0x00+0x04*0x03],xmm0
    mulss xmm4,xmm2
    movss [ebx+0x10*0x01+0x04*0x03],xmm1
    movss [ebx+0x10*0x02+0x04*0x03],xmm4
    ret

D3D_PerspectiveMatrix:
    mov ebx,[D3D_Matrix]
    movaps xmm0,[D3D_Perspective]
    movaps [ebx],xmm0
    movaps xmm0,[D3D_Perspective+0x10]
    movaps [ebx+0x10],xmm0
    movaps xmm0,[D3D_Perspective+0x20]
    movaps [ebx+0x20],xmm0
    movaps xmm0,[D3D_Perspective+0x30]
    movaps [ebx+0x30],xmm0
    ret
    
D3D_RenderArrays:
    push ebp
    mov [D3D_Temp+0x04],esp
    xor ecx,ecx
    mov ebx,[eax]
    sub esp,0x10
    and esp,0xFFFFFFF0
    mov ebp,esp
D3D_RenderArrays0:
    add ecx,0x10
    cmp dword[ebx+ecx],0xFFFFFFFF
    jne D3D_RenderArrays0
    sub esp,ecx
    xor edx,edx
D3D_RenderArrays1:
    movaps xmm3,[ebx+edx]
    push ebx
    call D3D_TransformateVector
    movaps xmm3,xmm0
    mov ebx,ebp
    shufps xmm0,xmm0,0xEF
    sub ebx,edx
    comiss xmm0,[D3D_TooSmallW]
    ja D3D_RenderArrays4
    xorps xmm3,xmm3
    jmp D3D_RenderArrays5
D3D_RenderArrays4:
    divps xmm3,xmm0
    addps xmm3,[D3D_Fp1]
    mulps xmm3,[D3D_ScreenHalf]
    shufps xmm3,xmm0,0xE4
D3D_RenderArrays5:
    movaps [ebx],xmm3
    add edx,0x10
    pop ebx
    cmp edx,ecx
    jbe D3D_RenderArrays1
    mov ebx,[eax+0x04]
D3D_RenderArrays2:
    mov eax,[ebx]
    mov edx,ebp
    cmp eax,0xFFFFFFFF
    je D3D_RenderArrays3
    shl eax,0x04
    xor ecx,ecx
    sub edx,eax
    cmp ecx,[edx+0x0C]
    je D3D_RenderArrays6
    movaps xmm5,[edx]
    mov eax,[ebx+0x04]
    mov edx,ebp
    shl eax,0x04
    sub edx,eax
    cmp ecx,[edx+0x0C]
    je D3D_RenderArrays6
    movaps xmm6,[edx]
    mov eax,[ebx+0x08]
    mov edx,ebp
    shl eax,0x04
    sub edx,eax
    cmp ecx,[edx+0x0C]
    je D3D_RenderArrays6
    movaps xmm7,[edx]
    push ebx
    call D3D_DrawTriangle
    pop ebx
D3D_RenderArrays6:
    add ebx,0x0C
    jmp D3D_RenderArrays2
D3D_RenderArrays3:
    mov esp,[D3D_Temp+0x04]
    pop ebp
    ret

D3D_VerticalSync:
    mov dx,0x03DA
D3D_VerticalSync0:
    in al,dx
    and al,0x08
    jnz D3D_VerticalSync0
D3D_VerticalSync1:
    in al,dx
    and al,0x08
    jz D3D_VerticalSync1
    ret

; Do not touch this values from outside, properly use exported functions
ALIGN 0x10
D3D_Buffer dd 0x00
D3D_Color dd 0x00
D3D_Matrix dd 0x00
D3D_TooSmallW dd 0.1
D3D_Temp dd 0x00,0x00,0x00,0x00

D3D_Fp0 dd 0.0,0.0,0.0,0.0
D3D_Fp1 dd 1.0,1.0,1.0,1.0
D3D_Fm1 dd -1.0,-1.0,-1.0,-1.0
D3D_ScreenHalf dd 320.0,240.0,0.0,0.0

D3D_Perspective dd 0.9534028741,0.0,0.0,0.0
                dd 0.0,1.191753593,0.0,0.0
                dd 0.0,0.0,-1.002002002,-0.2002002002
                dd 0.0,0.0,-1.0,0.0
                
D3D_Identic dd 1.0,0.0,0.0,0.0
            dd 0.0,1.0,0.0,0.0
            dd 0.0,0.0,1.0,0.0
            dd 0.0,0.0,0.0,1.0



