#include "recomp.h"
#include "disable_warnings.h"

void sub_80054214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x80061B44
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    GsGetWorkBase(rdram, ctx);
    goto after_0;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $s0, 0x1000
    ctx->r2 = ctx->r16 & 0X1000;
    // beq         $v0, $zero, L_80054254
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80054254;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x30($at)
    MEM_W(0X30, ctx->r1) = ctx->r2;
    // andi        $v0, $s0, 0xFFF
    ctx->r2 = ctx->r16 & 0XFFF;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x2C($at)
    MEM_W(0X2C, ctx->r1) = ctx->r2;
    // j           L_80054264
    // nop

    goto L_80054264;
    // nop

L_80054254:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x30($at)
    MEM_W(0X30, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s0, 0x2C($at)
    MEM_W(0X2C, ctx->r1) = ctx->r16;
L_80054264:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x2C($v1)
    ctx->r3 = MEM_W(0X2C, ctx->r3);
    // nop

    // slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80054370
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_80054370;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80054360
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x3C
        ctx->r2 = 0 | 0X3C;
        goto L_80054360;
    }
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x3244
    ctx->r1 = ADD32(ctx->r1, 0X3244);
    // addu        $at, $at, $v0
    gpr jr_addend_800542A0;
    jr_addend_800542A0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800542A0 >> 2) {
        case 0: goto L_80054338; break;
        case 1: goto L_800542D0; break;
        case 2: goto L_8005430C; break;
        case 3: goto L_800542F8; break;
        case 4: goto L_800542A8; break;
        case 5: goto L_80054320; break;
        default: switch_error(__func__, 0x800542A0, 0x80013244);
    }
    // nop

L_800542A8:
    // ori         $v1, $zero, 0x32
    ctx->r3 = 0 | 0X32;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v1, -0x5D30($at)
    MEM_W(-0X5D30, ctx->r1) = ctx->r3;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $a0, $v0, L_800542E8
    if (ctx->r4 == ctx->r2) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_800542E8;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v1, 0x2C($at)
    MEM_W(0X2C, ctx->r1) = ctx->r3;
    // j           L_80054378
    // nop

    goto L_80054378;
    // nop

L_800542D0:
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D30($at)
    MEM_W(-0X5D30, ctx->r1) = ctx->r2;
    // bne         $a0, $zero, L_800542E8
    if (ctx->r4 != 0) {
        // nop
    
        goto L_800542E8;
    }
    // nop

    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
L_800542E8:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x2C($at)
    MEM_W(0X2C, ctx->r1) = ctx->r2;
    // j           L_80054378
    // nop

    goto L_80054378;
    // nop

L_800542F8:
    // ori         $v0, $zero, 0x78
    ctx->r2 = 0 | 0X78;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D30($at)
    MEM_W(-0X5D30, ctx->r1) = ctx->r2;
    // j           L_80054378
    // nop

    goto L_80054378;
    // nop

L_8005430C:
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D30($at)
    MEM_W(-0X5D30, ctx->r1) = ctx->r2;
    // j           L_80054378
    // nop

    goto L_80054378;
    // nop

L_80054320:
    // beq         $a0, $zero, L_8005435C
    if (ctx->r4 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005435C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $a0, $v0, L_8005434C
    if (ctx->r4 == ctx->r2) {
        // ori         $v0, $zero, 0x32
        ctx->r2 = 0 | 0X32;
        goto L_8005434C;
    }
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // j           L_80054360
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    goto L_80054360;
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
L_80054338:
    // beq         $a0, $zero, L_8005435C
    if (ctx->r4 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005435C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $a0, $v0, L_80054360
    if (ctx->r4 != ctx->r2) {
        // ori         $v0, $zero, 0x3C
        ctx->r2 = 0 | 0X3C;
        goto L_80054360;
    }
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
L_8005434C:
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D30($at)
    MEM_W(-0X5D30, ctx->r1) = ctx->r2;
    // j           L_80054378
    // nop

    goto L_80054378;
    // nop

L_8005435C:
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
L_80054360:
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D30($at)
    MEM_W(-0X5D30, ctx->r1) = ctx->r2;
    // j           L_80054378
    // nop

    goto L_80054378;
    // nop

L_80054370:
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v1, -0x5D30($at)
    MEM_W(-0X5D30, ctx->r1) = ctx->r3;
L_80054378:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
