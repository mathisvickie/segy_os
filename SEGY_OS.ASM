
; **************************************************
; ******************** SEGY OS *********************
; **************************************************

; Memory map, see: https://wiki.osdev.org/Memory_Map_(x86)
; +---------------------+--------+--------------------+
; |     RAM region      | Size K |        Use         |
; +---------------------+--------+--------------------+
; | 0x000000 - 0x0003FF |      1 | Real mode IVT      |
; | 0x000400 - 0x0004FF |   0.25 | BIOS data          |
; | 0x000500 - 0x09FBFF | 637.75 | DOS / Free RAM     |
; | 0x09FC00 - 0x09FFFF |      1 | Extended BIOS data |
; | 0x0A0000 - 0x0BFFFF |    128 | BIOS video RAM     |
; | 0x0C0000 - 0x0FFFFF |    256 | BIOS ROM           |
; | 0x100000 - 0x3FFFFF |  3,072 | Kernel stack       |
; | 0x400000 - 0x7FFFFF |  4,096 | Kernel code & data |
; | 0x800000 - ???????? | ?????? | Free RAM           |
; +---------------------+--------+--------------------+

; Define kernel properties
KERNEL_START equ 0x400000
KERNEL_STACK equ 0x400000

; Define video mode, see: https://en.wikipedia.org/wiki/VESA_BIOS_Extensions
;VBE_MODE equ 0x101 ;640x480x256
VBE_MODE equ 0x811B ;1280x1024x4M

; 1. Now check CPU and print some its features (if they are supported)
; 2. Then set VBE mode and boot to 32-bit PM
; 3. Copy kernel to upper memory and jump to it
; ++ Automaticaly exported and ready for use are functions with "KRNL" prefix

ORG 0x100
BITS 16
    ; DOS entry, assume setuped segments and stack

    ; Set text mode 80x25 with 16 colors, say hello and version
    mov ax,0x03
    int 0x10
    mov si,RM_Hello_str
    call RM_Print
    
    ; Check if we are running in PM or VM8086
    smsw ax
    test ax,0x01
    jnz RM_ErrInsidePM
    
    ; Checking CPU...
    mov si,RM_CheckCPU_str
    call RM_Print
    
    ; Check if has CPUID
    mov si,RM_32bitPM_str
    call RM_Print
    call RM_HasCpuid
    test al,al
    je RM_ErrUnsupported
    mov si,RM_OK_str
    call RM_Print
    
    ; Has FPU
    xor al,al
    mov si,RM_FPU_str
    call RM_HasCpuidBit
    
    ; Has MMX
    mov al,0x17
    mov si,RM_MMX_str
    call RM_HasCpuidBit

    ; Has SSE
    mov al,0x19
    mov si,RM_SSE_str
    call RM_HasCpuidBit
    
    ; Has SSE2
    mov al,0x1A
    mov si,RM_SSE2_str
    call RM_HasCpuidBit

    ; Has VBE, store LFB address
    mov si,RM_VBE_str
    call RM_Print
    call RM_GetLFB
    test eax,eax
    je RM_ErrUnsupported
    push eax
    mov si,RM_OK_str
    call RM_Print

    ; Wait key
    mov si,RM_WaitKey_str
    call RM_Print
    xor ah,ah
    int 0x16

    ; Set custom VBE mode
    mov ax,0x4F02
    mov bx,VBE_MODE
    int 0x10

    ; Jump to Segy OS bootloader
    pop esi
    cli
    jmp BOOT
    
RM_Print: ;void=RM_Print(si=char*);
    lodsb
    test al,al
    je RM_Print0
    mov ah,0x0E
    xor bh,bh
    int 0x10
    jmp RM_Print
RM_Print0:
    ret
    
RM_HasCpuid: ;al=RM_HasCpuid(void);
    pushf
    mov ax,0xF000
    push ax
    popf
    pushf
    pop ax
    and ax,0xF000
    popf
    mov al,ah
    ret
    
RM_HasCpuidBit: ;void=RM_HasCpuidBit(al=bit to check, si=char*);
    push ax
    call RM_Print
    mov eax,0x01
    cpuid
    pop cx
    shr edx,cl
    bt dx,0x00
    jnc RM_ErrUnsupported
    mov si,RM_OK_str
    call RM_Print
    ret

RM_GetLFB: ;eax=RM_GetLFB(void);
    sub sp,0x100
    mov ax,0x4F01
    mov cx,VBE_MODE
    mov di,sp
    int 0x10
    movzx esp,sp
    mov esi,[esp+0x28]
    add sp,0x100
    mov eax,esi
    ret
    
RM_Error:
    call RM_Print
RM_ErrHalt:
    cli
    hlt
    jmp RM_ErrHalt
    
RM_ErrInsidePM:
    mov si,RM_ErrInsidePM_str
    jmp RM_Error
    
RM_ErrUnsupported:
    mov si,RM_Unsupported_str
    jmp RM_Error
    
RM_Hello_str: db "Welcome to Segy OS, version: 0.1",0x0D,0x0A,0x0D,0x0A,0x00
RM_ErrInsidePM_str: db "ERROR: CPU is running in PM or VM8086",0x0D,0x0A,0x00
RM_CheckCPU_str: db "Checking CPU...",0x0D,0x0A,0x00
RM_OK_str: db "OK",0x0D,0x0A,0x00
RM_Unsupported_str: db "Not Supported",0x0D,0x0A,0x00
RM_32bitPM_str: db "PM32 x86: ",0x00
RM_FPU_str: db "FPU x87: ",0x00
RM_MMX_str: db "MMX: ",0x00
RM_SSE_str: db "SSE: ",0x00
RM_SSE2_str: db "SSE2: ",0x00
RM_VBE_str: db "VBE: ",0x00
RM_WaitKey_str: db 0x0D,0x0A,"Press any key to continue...",0x0D,0x0A,0x00

GDT: ;Global Descriptor Table
    dq 0

SELECTOR_CODE equ ($-GDT) ;Kernel code segment descriptor
    dw 0xFFFF	 ;Limit 0-15 bits
    dw 0x0000	 ;Base 0-15 bits (low)
    db 0x00	 ;Base 16-23 bits (middle)
    db 10011010b ;Access: 1, ring level 2bits (0=kernel 3=user), 1=segment (0=TSS), execute, 0=segment grows up (1=down), read/write, is accessed
    db 11001111b ;Granularity: 1=4KiB page (0=1B page), 1=32-bit PM (0=16bit PM), 0, 0, limit 16-19 bits (limit 4 last bits)(limit is 20 bit wide)
    db 0x00	 ;Base 24-31 bits (high)

SELECTOR_DATA equ ($-GDT) ;Kernel data segment descriptor
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10010010b
    db 11001111b
    db 0x00

SELECTOR_LFB equ ($-GDT) ;Kernel LFB segment descriptor (base will be set)
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10010010b
    db 11001111b
    db 0x00

GDT_register:  ;GDT register loaded to CPU
    dw $-GDT-1 ;Size of GDT decreased by one
    dd GDT     ;32-bit base

BOOT:
    ; Enable a20 (fast method). This may not work on all hardware :'(
    in al,0x92
    or al,0x02
    out 0x92,al

    ; Setup base of LFB segment descriptor
    mov eax,esi
    mov [GDT+SELECTOR_LFB+0x02],ax ;Low
    shr eax,0x10
    mov [GDT+SELECTOR_LFB+0x04],al ;Middle
    mov [GDT+SELECTOR_LFB+0x07],ah ;High

    ; Calculate physical address and load GDT
    mov ebx,cs
    shl ebx,0x04
    add [GDT_register+0x02],ebx
    lgdt [GDT_register]
    
    mov eax,cr0
    or eax,(1 << 0)   ;Enable PM
    and eax,~(1 << 2) ;Enable FPU
    or eax,(1 << 1)   ;Enable monitoring co-processor
    mov cr0,eax

    mov eax,cr4
    or eax,(1 << 9) | (1 << 10) ;Enable SSE with unmasked exceptions
    mov cr4,eax

    ; Switch CPU to 32-bit mode
    push dword SELECTOR_CODE
    lea eax,[ebx+PM32]
    push eax
    mov bp,sp
    jmp dword far [bp]

BITS 32
PM32:
    ; Setup segments
    mov ax,SELECTOR_DATA
    mov ds,ax
    mov ss,ax
    mov es,ax
    mov fs,ax
    mov gs,ax

    ; Initialize stack, save LFB address
    lea esp,[KERNEL_STACK]
    mov ebp,esp
    push esi

    ; Copy kernel to upper memory
    lea esi,[ebx+KERNEL_COPY]
    mov edi,KERNEL_START
    mov ecx,KERNEL_SIZE
    rep movsd

    ; Initialize all general purpose registers
    xor eax,eax
    mov ebx,eax
    mov ecx,eax
    mov edx,eax
    mov esi,eax
    mov edi,eax

    ; Absolute jump to relocated kernel
    jmp SELECTOR_CODE:KERNEL_START

ALIGN 0x10
KERNEL_COPY equ $
SECTION kernel, vstart=KERNEL_START, valign=0x10
ALIGN 0x10
    %INCLUDE "AUTORUN.ASM"
krnl_Halt:
    cli
    hlt
    jmp krnl_Halt

KERNEL_SIZE equ ($-$$+3)>>2


