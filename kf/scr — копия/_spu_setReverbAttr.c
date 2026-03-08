#include "recomp.h"
#include "disable_warnings.h"

void _spu_setReverbAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(0X0, ctx->r4);
    // nop

    // sltiu       $a2, $a1, 0x1
    ctx->r6 = ctx->r5 < 0X1 ? 1 : 0;
    // bne         $a2, $zero, L_80052C28
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x1
        ctx->r2 = ctx->r5 & 0X1;
        goto L_80052C28;
    }
    // andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // beq         $v0, $zero, L_80052C3C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052C3C;
    }
    // nop

L_80052C28:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // sh          $v0, 0x1C0($v1)
    MEM_H(0X1C0, ctx->r3) = ctx->r2;
L_80052C3C:
    // bne         $a2, $zero, L_80052C4C
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x2
        ctx->r2 = ctx->r5 & 0X2;
        goto L_80052C4C;
    }
    // andi        $v0, $a1, 0x2
    ctx->r2 = ctx->r5 & 0X2;
    // beq         $v0, $zero, L_80052C60
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052C60;
    }
    // nop

L_80052C4C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nop

    // sh          $v0, 0x1C2($v1)
    MEM_H(0X1C2, ctx->r3) = ctx->r2;
L_80052C60:
    // bne         $a2, $zero, L_80052C70
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x4
        ctx->r2 = ctx->r5 & 0X4;
        goto L_80052C70;
    }
    // andi        $v0, $a1, 0x4
    ctx->r2 = ctx->r5 & 0X4;
    // beq         $v0, $zero, L_80052C84
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052C84;
    }
    // nop

L_80052C70:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // sh          $v0, 0x1C4($v1)
    MEM_H(0X1C4, ctx->r3) = ctx->r2;
L_80052C84:
    // bne         $a2, $zero, L_80052C94
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x8
        ctx->r2 = ctx->r5 & 0X8;
        goto L_80052C94;
    }
    // andi        $v0, $a1, 0x8
    ctx->r2 = ctx->r5 & 0X8;
    // beq         $v0, $zero, L_80052CA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052CA8;
    }
    // nop

L_80052C94:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(0XA, ctx->r4);
    // nop

    // sh          $v0, 0x1C6($v1)
    MEM_H(0X1C6, ctx->r3) = ctx->r2;
L_80052CA8:
    // bne         $a2, $zero, L_80052CB8
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x10
        ctx->r2 = ctx->r5 & 0X10;
        goto L_80052CB8;
    }
    // andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // beq         $v0, $zero, L_80052CCC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052CCC;
    }
    // nop

L_80052CB8:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
    // nop

    // sh          $v0, 0x1C8($v1)
    MEM_H(0X1C8, ctx->r3) = ctx->r2;
L_80052CCC:
    // bne         $a2, $zero, L_80052CDC
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x20
        ctx->r2 = ctx->r5 & 0X20;
        goto L_80052CDC;
    }
    // andi        $v0, $a1, 0x20
    ctx->r2 = ctx->r5 & 0X20;
    // beq         $v0, $zero, L_80052CF0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052CF0;
    }
    // nop

L_80052CDC:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(0XE, ctx->r4);
    // nop

    // sh          $v0, 0x1CA($v1)
    MEM_H(0X1CA, ctx->r3) = ctx->r2;
L_80052CF0:
    // bne         $a2, $zero, L_80052D00
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x40
        ctx->r2 = ctx->r5 & 0X40;
        goto L_80052D00;
    }
    // andi        $v0, $a1, 0x40
    ctx->r2 = ctx->r5 & 0X40;
    // beq         $v0, $zero, L_80052D14
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052D14;
    }
    // nop

L_80052D00:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(0X10, ctx->r4);
    // nop

    // sh          $v0, 0x1CC($v1)
    MEM_H(0X1CC, ctx->r3) = ctx->r2;
L_80052D14:
    // bne         $a2, $zero, L_80052D24
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x80
        ctx->r2 = ctx->r5 & 0X80;
        goto L_80052D24;
    }
    // andi        $v0, $a1, 0x80
    ctx->r2 = ctx->r5 & 0X80;
    // beq         $v0, $zero, L_80052D38
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052D38;
    }
    // nop

L_80052D24:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(0X12, ctx->r4);
    // nop

    // sh          $v0, 0x1CE($v1)
    MEM_H(0X1CE, ctx->r3) = ctx->r2;
L_80052D38:
    // bne         $a2, $zero, L_80052D48
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x100
        ctx->r2 = ctx->r5 & 0X100;
        goto L_80052D48;
    }
    // andi        $v0, $a1, 0x100
    ctx->r2 = ctx->r5 & 0X100;
    // beq         $v0, $zero, L_80052D5C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052D5C;
    }
    // nop

L_80052D48:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(0X14, ctx->r4);
    // nop

    // sh          $v0, 0x1D0($v1)
    MEM_H(0X1D0, ctx->r3) = ctx->r2;
L_80052D5C:
    // bne         $a2, $zero, L_80052D6C
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x200
        ctx->r2 = ctx->r5 & 0X200;
        goto L_80052D6C;
    }
    // andi        $v0, $a1, 0x200
    ctx->r2 = ctx->r5 & 0X200;
    // beq         $v0, $zero, L_80052D80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052D80;
    }
    // nop

L_80052D6C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x16($a0)
    ctx->r2 = MEM_HU(0X16, ctx->r4);
    // nop

    // sh          $v0, 0x1D2($v1)
    MEM_H(0X1D2, ctx->r3) = ctx->r2;
L_80052D80:
    // bne         $a2, $zero, L_80052D90
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x400
        ctx->r2 = ctx->r5 & 0X400;
        goto L_80052D90;
    }
    // andi        $v0, $a1, 0x400
    ctx->r2 = ctx->r5 & 0X400;
    // beq         $v0, $zero, L_80052DA4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052DA4;
    }
    // nop

L_80052D90:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(0X18, ctx->r4);
    // nop

    // sh          $v0, 0x1D4($v1)
    MEM_H(0X1D4, ctx->r3) = ctx->r2;
L_80052DA4:
    // bne         $a2, $zero, L_80052DB4
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x800
        ctx->r2 = ctx->r5 & 0X800;
        goto L_80052DB4;
    }
    // andi        $v0, $a1, 0x800
    ctx->r2 = ctx->r5 & 0X800;
    // beq         $v0, $zero, L_80052DC8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052DC8;
    }
    // nop

L_80052DB4:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x1A($a0)
    ctx->r2 = MEM_HU(0X1A, ctx->r4);
    // nop

    // sh          $v0, 0x1D6($v1)
    MEM_H(0X1D6, ctx->r3) = ctx->r2;
L_80052DC8:
    // bne         $a2, $zero, L_80052DD8
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x1000
        ctx->r2 = ctx->r5 & 0X1000;
        goto L_80052DD8;
    }
    // andi        $v0, $a1, 0x1000
    ctx->r2 = ctx->r5 & 0X1000;
    // beq         $v0, $zero, L_80052DEC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052DEC;
    }
    // nop

L_80052DD8:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(0X1C, ctx->r4);
    // nop

    // sh          $v0, 0x1D8($v1)
    MEM_H(0X1D8, ctx->r3) = ctx->r2;
L_80052DEC:
    // bne         $a2, $zero, L_80052DFC
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x2000
        ctx->r2 = ctx->r5 & 0X2000;
        goto L_80052DFC;
    }
    // andi        $v0, $a1, 0x2000
    ctx->r2 = ctx->r5 & 0X2000;
    // beq         $v0, $zero, L_80052E10
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052E10;
    }
    // nop

L_80052DFC:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x1E($a0)
    ctx->r2 = MEM_HU(0X1E, ctx->r4);
    // nop

    // sh          $v0, 0x1DA($v1)
    MEM_H(0X1DA, ctx->r3) = ctx->r2;
L_80052E10:
    // bne         $a2, $zero, L_80052E20
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x4000
        ctx->r2 = ctx->r5 & 0X4000;
        goto L_80052E20;
    }
    // andi        $v0, $a1, 0x4000
    ctx->r2 = ctx->r5 & 0X4000;
    // beq         $v0, $zero, L_80052E34
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052E34;
    }
    // nop

L_80052E20:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x20($a0)
    ctx->r2 = MEM_HU(0X20, ctx->r4);
    // nop

    // sh          $v0, 0x1DC($v1)
    MEM_H(0X1DC, ctx->r3) = ctx->r2;
L_80052E34:
    // bne         $a2, $zero, L_80052E44
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x8000
        ctx->r2 = ctx->r5 & 0X8000;
        goto L_80052E44;
    }
    // andi        $v0, $a1, 0x8000
    ctx->r2 = ctx->r5 & 0X8000;
    // beq         $v0, $zero, L_80052E58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052E58;
    }
    // nop

L_80052E44:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(0X22, ctx->r4);
    // nop

    // sh          $v0, 0x1DE($v1)
    MEM_H(0X1DE, ctx->r3) = ctx->r2;
L_80052E58:
    // bne         $a2, $zero, L_80052E6C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_80052E6C;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052E80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052E80;
    }
    // nop

L_80052E6C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x24($a0)
    ctx->r2 = MEM_HU(0X24, ctx->r4);
    // nop

    // sh          $v0, 0x1E0($v1)
    MEM_H(0X1E0, ctx->r3) = ctx->r2;
L_80052E80:
    // bne         $a2, $zero, L_80052E94
    if (ctx->r6 != 0) {
        // lui         $v0, 0x2
        ctx->r2 = S32(0X2 << 16);
        goto L_80052E94;
    }
    // lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052EA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052EA8;
    }
    // nop

L_80052E94:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x26($a0)
    ctx->r2 = MEM_HU(0X26, ctx->r4);
    // nop

    // sh          $v0, 0x1E2($v1)
    MEM_H(0X1E2, ctx->r3) = ctx->r2;
L_80052EA8:
    // bne         $a2, $zero, L_80052EBC
    if (ctx->r6 != 0) {
        // lui         $v0, 0x4
        ctx->r2 = S32(0X4 << 16);
        goto L_80052EBC;
    }
    // lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052ED0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052ED0;
    }
    // nop

L_80052EBC:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(0X28, ctx->r4);
    // nop

    // sh          $v0, 0x1E4($v1)
    MEM_H(0X1E4, ctx->r3) = ctx->r2;
L_80052ED0:
    // bne         $a2, $zero, L_80052EE4
    if (ctx->r6 != 0) {
        // lui         $v0, 0x8
        ctx->r2 = S32(0X8 << 16);
        goto L_80052EE4;
    }
    // lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052EF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052EF8;
    }
    // nop

L_80052EE4:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x2A($a0)
    ctx->r2 = MEM_HU(0X2A, ctx->r4);
    // nop

    // sh          $v0, 0x1E6($v1)
    MEM_H(0X1E6, ctx->r3) = ctx->r2;
L_80052EF8:
    // bne         $a2, $zero, L_80052F0C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x10
        ctx->r2 = S32(0X10 << 16);
        goto L_80052F0C;
    }
    // lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052F20
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052F20;
    }
    // nop

L_80052F0C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x2C($a0)
    ctx->r2 = MEM_HU(0X2C, ctx->r4);
    // nop

    // sh          $v0, 0x1E8($v1)
    MEM_H(0X1E8, ctx->r3) = ctx->r2;
L_80052F20:
    // bne         $a2, $zero, L_80052F34
    if (ctx->r6 != 0) {
        // lui         $v0, 0x20
        ctx->r2 = S32(0X20 << 16);
        goto L_80052F34;
    }
    // lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052F48
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052F48;
    }
    // nop

L_80052F34:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x2E($a0)
    ctx->r2 = MEM_HU(0X2E, ctx->r4);
    // nop

    // sh          $v0, 0x1EA($v1)
    MEM_H(0X1EA, ctx->r3) = ctx->r2;
L_80052F48:
    // bne         $a2, $zero, L_80052F5C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x40
        ctx->r2 = S32(0X40 << 16);
        goto L_80052F5C;
    }
    // lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052F70
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052F70;
    }
    // nop

L_80052F5C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x30($a0)
    ctx->r2 = MEM_HU(0X30, ctx->r4);
    // nop

    // sh          $v0, 0x1EC($v1)
    MEM_H(0X1EC, ctx->r3) = ctx->r2;
L_80052F70:
    // bne         $a2, $zero, L_80052F84
    if (ctx->r6 != 0) {
        // lui         $v0, 0x80
        ctx->r2 = S32(0X80 << 16);
        goto L_80052F84;
    }
    // lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052F98
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052F98;
    }
    // nop

L_80052F84:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x32($a0)
    ctx->r2 = MEM_HU(0X32, ctx->r4);
    // nop

    // sh          $v0, 0x1EE($v1)
    MEM_H(0X1EE, ctx->r3) = ctx->r2;
L_80052F98:
    // bne         $a2, $zero, L_80052FAC
    if (ctx->r6 != 0) {
        // lui         $v0, 0x100
        ctx->r2 = S32(0X100 << 16);
        goto L_80052FAC;
    }
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052FC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052FC0;
    }
    // nop

L_80052FAC:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x34($a0)
    ctx->r2 = MEM_HU(0X34, ctx->r4);
    // nop

    // sh          $v0, 0x1F0($v1)
    MEM_H(0X1F0, ctx->r3) = ctx->r2;
L_80052FC0:
    // bne         $a2, $zero, L_80052FD4
    if (ctx->r6 != 0) {
        // lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
        goto L_80052FD4;
    }
    // lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80052FE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052FE8;
    }
    // nop

L_80052FD4:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x36($a0)
    ctx->r2 = MEM_HU(0X36, ctx->r4);
    // nop

    // sh          $v0, 0x1F2($v1)
    MEM_H(0X1F2, ctx->r3) = ctx->r2;
L_80052FE8:
    // bne         $a2, $zero, L_80052FFC
    if (ctx->r6 != 0) {
        // lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
        goto L_80052FFC;
    }
    // lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80053010
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053010;
    }
    // nop

L_80052FFC:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x38($a0)
    ctx->r2 = MEM_HU(0X38, ctx->r4);
    // nop

    // sh          $v0, 0x1F4($v1)
    MEM_H(0X1F4, ctx->r3) = ctx->r2;
L_80053010:
    // bne         $a2, $zero, L_80053024
    if (ctx->r6 != 0) {
        // lui         $v0, 0x800
        ctx->r2 = S32(0X800 << 16);
        goto L_80053024;
    }
    // lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80053038
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053038;
    }
    // nop

L_80053024:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(0X3A, ctx->r4);
    // nop

    // sh          $v0, 0x1F6($v1)
    MEM_H(0X1F6, ctx->r3) = ctx->r2;
L_80053038:
    // bne         $a2, $zero, L_8005304C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x1000
        ctx->r2 = S32(0X1000 << 16);
        goto L_8005304C;
    }
    // lui         $v0, 0x1000
    ctx->r2 = S32(0X1000 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80053060
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053060;
    }
    // nop

L_8005304C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(0X3C, ctx->r4);
    // nop

    // sh          $v0, 0x1F8($v1)
    MEM_H(0X1F8, ctx->r3) = ctx->r2;
L_80053060:
    // bne         $a2, $zero, L_80053074
    if (ctx->r6 != 0) {
        // lui         $v0, 0x2000
        ctx->r2 = S32(0X2000 << 16);
        goto L_80053074;
    }
    // lui         $v0, 0x2000
    ctx->r2 = S32(0X2000 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80053088
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053088;
    }
    // nop

L_80053074:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x3E($a0)
    ctx->r2 = MEM_HU(0X3E, ctx->r4);
    // nop

    // sh          $v0, 0x1FA($v1)
    MEM_H(0X1FA, ctx->r3) = ctx->r2;
L_80053088:
    // bne         $a2, $zero, L_8005309C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8005309C;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_800530B0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800530B0;
    }
    // nop

L_8005309C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x40($a0)
    ctx->r2 = MEM_HU(0X40, ctx->r4);
    // nop

    // sh          $v0, 0x1FC($v1)
    MEM_H(0X1FC, ctx->r3) = ctx->r2;
L_800530B0:
    // bne         $a2, $zero, L_800530C0
    if (ctx->r6 != 0) {
        // nop
    
        goto L_800530C0;
    }
    // nop

    // bgez        $a1, L_800530D4
    if (SIGNED(ctx->r5) >= 0) {
        // nop
    
        goto L_800530D4;
    }
    // nop

L_800530C0:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // lhu         $v0, 0x42($a0)
    ctx->r2 = MEM_HU(0X42, ctx->r4);
    // nop

    // sh          $v0, 0x1FE($v1)
    MEM_H(0X1FE, ctx->r3) = ctx->r2;
L_800530D4:
    // jr          $ra
    // nop

    return;
    // nop

;}
