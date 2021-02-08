    mov eax,0x800000
    call D3D_BindBuffer
repeat:
    call D3D_ClearBuffer

    in al,0x60
    cmp al,0x11
    jne nokey0
    movss xmm0,[camera+0x08]
    subss xmm0,[velocity]
    movss [camera+0x08],xmm0
nokey0:
    cmp al,0x1F
    jne nokey1
    movss xmm0,[camera+0x08]
    addss xmm0,[velocity]
    movss [camera+0x08],xmm0
nokey1:
    cmp al,0x1E
    jne nokey2
    movss xmm0,[camera]
    subss xmm0,[velocity]
    movss [camera],xmm0
nokey2:
    cmp al,0x20
    jne nokey3
    movss xmm0,[camera]
    addss xmm0,[velocity]
    movss [camera],xmm0
nokey3:
    cmp al,0x49
    jne nokey4
    movss xmm0,[camera+0x04]
    addss xmm0,[velocity]
    movss [camera+0x04],xmm0
nokey4:
    cmp al,0x51
    jne nokey5
    movss xmm0,[camera+0x04]
    subss xmm0,[velocity]
    movss [camera+0x04],xmm0
nokey5:
    cmp al,0x48
    jne nokey6
    movss xmm0,[camera+0x10]
    addss xmm0,[velocity]
    movss [camera+0x10],xmm0
nokey6:
    cmp al,0x50
    jne nokey7
    movss xmm0,[camera+0x10]
    subss xmm0,[velocity]
    movss [camera+0x10],xmm0
nokey7:
    cmp al,0x4B
    jne nokey8
    movss xmm0,[camera+0x14]
    addss xmm0,[velocity]
    movss [camera+0x14],xmm0
nokey8:
    cmp al,0x4D
    jne nokey9
    movss xmm0,[camera+0x14]
    subss xmm0,[velocity]
    movss [camera+0x14],xmm0
nokey9:

    lea eax,[VPM]
    call D3D_BindMatrix
    call D3D_PerspectiveMatrix
    
    lea eax,[MAT]
    call D3D_BindMatrix
    lea eax,[camera]
    call D3D_CameraMatrix
    
    lea eax,[VPM]
    call D3D_BindMatrix
    lea eax,[MAT]
    call D3D_MultiplyMatrix

    movaps xmm0,[groundstart]
    movaps [cube],xmm0
ground:
    movaps xmm0,[VPM]
    movaps [MAT],xmm0
    movaps xmm0,[VPM+0x10]
    movaps [MAT+0x10],xmm0
    movaps xmm0,[VPM+0x20]
    movaps [MAT+0x20],xmm0
    movaps xmm0,[VPM+0x30]
    movaps [MAT+0x30],xmm0
    
    lea eax,[TRS]
    call D3D_BindMatrix
    lea eax,[cube]
    call D3D_ModelMatrix
    
    lea eax,[MAT]
    call D3D_BindMatrix
    lea eax,[TRS]
    call D3D_MultiplyMatrix
    
    mov eax,15
    call D3D_BindColor
    lea eax,[VAO]
    call D3D_RenderArrays

    movss xmm0,[increment]
    addss xmm0,[cube]
    movss [cube],xmm0
    movss xmm1,[groundend]
    comiss xmm1,[cube]
    jae ground
    movss xmm2,[groundstart]
    movss [cube],xmm2

    movss xmm0,[increment]
    addss xmm0,[cube+0x08]
    movss [cube+0x08],xmm0
    comiss xmm1,[cube+0x08]
    jae ground
    movss [cube+0x08],xmm2

    call D3D_SwapBuffers
    call D3D_VerticalSync
    jmp repeat

%include "D3D.asm"

ALIGN 0x10
VBO dd 0.5,-0.5,-0.5,1.0,0.5,-0.5,0.5,1.0,-0.5,-0.5,0.5,1.0,-0.5,-0.5,-0.5,1.0,0.5,0.5,-0.5,1.0,0.5,0.5,0.5,1.0,-0.5,0.5,0.5,1.0,-0.5,0.5,-0.5,1.0
    dd 0xFFFFFFFF
EBO dd 1,2,3,7,6,5,4,5,1,5,6,2,2,6,7,0,3,7,0,1,3,4,7,5,0,4,1,1,5,2,3,2,7,4,0,7
    dd 0xFFFFFFFF
VAO dd VBO,EBO

ALIGN 0x10
groundstart dd -10.0,-1.0,-10.0,0.0
increment dd 1.0
groundend dd 10.0
velocity dd 0.03,0.0
cube dd 0.0,0.0,0.0,0.0
     dd 0.0,0.0,0.0,0.0
     dd 1.0,0.2,1.0,0.0
camera dd 0.0,0.0,3.0,0.0
       dd 0.0,0.0,0.0,0.0

ALIGN 0x10
VPM dd 1.0,0.0,0.0,0.0
    dd 0.0,1.0,0.0,0.0
    dd 0.0,0.0,1.0,0.0
    dd 0.0,0.0,0.0,1.0
    
TRS dd 1.0,0.0,0.0,0.0
    dd 0.0,1.0,0.0,0.0
    dd 0.0,0.0,1.0,0.0
    dd 0.0,0.0,0.0,1.0

MAT dd 1.0,0.0,0.0,0.0
    dd 0.0,1.0,0.0,0.0
    dd 0.0,0.0,1.0,0.0
    dd 0.0,0.0,0.0,1.0


