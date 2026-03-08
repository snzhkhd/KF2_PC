#include "recomp.h"
#include "disable_warnings.h"

void sub_80039190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // addiu       $t1, $t1, -0x6810
    ctx->r9 = ADD32(ctx->r9, -0X6810);
    // andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80039340
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $a0, 0x6A
        ctx->r2 = ADD32(ctx->r4, 0X6A);
        goto L_80039340;
    }
    // addiu       $v0, $a0, 0x6A
    ctx->r2 = ADD32(ctx->r4, 0X6A);
    // ori         $a2, $zero, 0x18B
    ctx->r6 = 0 | 0X18B;
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // ori         $t0, $zero, 0xFF
    ctx->r8 = 0 | 0XFF;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $t2, $v0, 0x31
    ctx->r10 = ctx->r2 < 0X31 ? 1 : 0;
    // addiu       $a0, $t1, 0x38
    ctx->r4 = ADD32(ctx->r9, 0X38);
L_800391C4:
    // lbu         $v1, -0x34($a0)
    ctx->r3 = MEM_BU(-0X34, ctx->r4);
    // ori         $v0, $zero, 0x54
    ctx->r2 = 0 | 0X54;
    // beq         $v1, $v0, L_80039258
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x55
        ctx->r2 = SIGNED(ctx->r3) < 0X55 ? 1 : 0;
        goto L_80039258;
    }
    // slti        $v0, $v1, 0x55
    ctx->r2 = SIGNED(ctx->r3) < 0X55 ? 1 : 0;
    // beq         $v0, $zero, L_80039218
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x50
        ctx->r2 = 0 | 0X50;
        goto L_80039218;
    }
    // ori         $v0, $zero, 0x50
    ctx->r2 = 0 | 0X50;
    // beq         $v1, $v0, L_80039258
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x51
        ctx->r2 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
        goto L_80039258;
    }
    // slti        $v0, $v1, 0x51
    ctx->r2 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
    // beq         $v0, $zero, L_80039204
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
        goto L_80039204;
    }
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_8003932C
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8003932C;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800392D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800392D4;
    }
    // nop

    // j           L_80039330
    // addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    goto L_80039330;
    // addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
L_80039204:
    // ori         $v0, $zero, 0x51
    ctx->r2 = 0 | 0X51;
    // beq         $v1, $v0, L_80039294
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80039294;
    }
    // nop

    // j           L_80039330
    // addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    goto L_80039330;
    // addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
L_80039218:
    // ori         $v0, $zero, 0x5F
    ctx->r2 = 0 | 0X5F;
    // beq         $v1, $v0, L_80039258
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x60
        ctx->r2 = SIGNED(ctx->r3) < 0X60 ? 1 : 0;
        goto L_80039258;
    }
    // slti        $v0, $v1, 0x60
    ctx->r2 = SIGNED(ctx->r3) < 0X60 ? 1 : 0;
    // beq         $v0, $zero, L_80039244
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x58
        ctx->r2 = 0 | 0X58;
        goto L_80039244;
    }
    // ori         $v0, $zero, 0x58
    ctx->r2 = 0 | 0X58;
    // beq         $v1, $v0, L_80039270
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x59
        ctx->r2 = 0 | 0X59;
        goto L_80039270;
    }
    // ori         $v0, $zero, 0x59
    ctx->r2 = 0 | 0X59;
    // beq         $v1, $v0, L_800392BC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800392BC;
    }
    // nop

    // j           L_80039330
    // addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    goto L_80039330;
    // addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
L_80039244:
    // slti        $v0, $v1, 0xA4
    ctx->r2 = SIGNED(ctx->r3) < 0XA4 ? 1 : 0;
    // beq         $v0, $zero, L_8003932C
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0xA2
        ctx->r2 = SIGNED(ctx->r3) < 0XA2 ? 1 : 0;
        goto L_8003932C;
    }
    // slti        $v0, $v1, 0xA2
    ctx->r2 = SIGNED(ctx->r3) < 0XA2 ? 1 : 0;
    // bne         $v0, $zero, L_8003932C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003932C;
    }
    // nop

L_80039258:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // bne         $v0, $a1, L_8003932C
    if (ctx->r2 != ctx->r5) {
        // nop
    
        goto L_8003932C;
    }
    // nop

    // j           L_8003932C
    // sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    goto L_8003932C;
    // sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
L_80039270:
    // lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(0X1, ctx->r4);
    // nop

    // bne         $v0, $a1, L_8003932C
    if (ctx->r2 != ctx->r5) {
        // nop
    
        goto L_8003932C;
    }
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // sh          $a3, -0x30($a0)
    MEM_H(-0X30, ctx->r4) = ctx->r7;
    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // j           L_8003932C
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    goto L_8003932C;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80039294:
    // lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(0X5, ctx->r4);
    // nop

    // bne         $v0, $a1, L_8003932C
    if (ctx->r2 != ctx->r5) {
        // nop
    
        goto L_8003932C;
    }
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_8003932C
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    goto L_8003932C;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800392BC:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // bne         $v0, $a1, L_8003932C
    if (ctx->r2 != ctx->r5) {
        // nop
    
        goto L_8003932C;
    }
    // nop

    // j           L_8003932C
    // sh          $a3, -0x30($a0)
    MEM_H(-0X30, ctx->r4) = ctx->r7;
    goto L_8003932C;
    // sh          $a3, -0x30($a0)
    MEM_H(-0X30, ctx->r4) = ctx->r7;
L_800392D4:
    // beq         $t2, $zero, L_800392F8
    if (ctx->r10 == 0) {
        // nop
    
        goto L_800392F8;
    }
    // nop

    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v1, 0xFE
    ctx->r2 = ctx->r3 & 0XFE;
    // bne         $v0, $a1, L_8003932C
    if (ctx->r2 != ctx->r5) {
        // xori        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 ^ 0X1;
        goto L_8003932C;
    }
    // xori        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 ^ 0X1;
    // j           L_8003932C
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    goto L_8003932C;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800392F8:
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // bne         $v1, $a1, L_8003932C
    if (ctx->r3 != ctx->r5) {
        // sltiu       $v0, $v1, 0xC8
        ctx->r2 = ctx->r3 < 0XC8 ? 1 : 0;
        goto L_8003932C;
    }
    // sltiu       $v0, $v1, 0xC8
    ctx->r2 = ctx->r3 < 0XC8 ? 1 : 0;
    // beq         $v0, $zero, L_80039328
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80039328;
    }
    // nop

    // lhu         $v0, -0x30($a0)
    ctx->r2 = MEM_HU(-0X30, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8003932C
    if (ctx->r2 != 0) {
        // sltiu       $v0, $v1, 0x64
        ctx->r2 = ctx->r3 < 0X64 ? 1 : 0;
        goto L_8003932C;
    }
    // sltiu       $v0, $v1, 0x64
    ctx->r2 = ctx->r3 < 0X64 ? 1 : 0;
    // bne         $v0, $zero, L_8003932C
    if (ctx->r2 != 0) {
        // sh          $a3, -0x30($a0)
        MEM_H(-0X30, ctx->r4) = ctx->r7;
        goto L_8003932C;
    }
    // sh          $a3, -0x30($a0)
    MEM_H(-0X30, ctx->r4) = ctx->r7;
L_80039328:
    // sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
L_8003932C:
    // addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
L_80039330:
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_800391C4
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_800391C4;
    }
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80039340:
    // jr          $ra
    // nop

    return;
    // nop

;}
