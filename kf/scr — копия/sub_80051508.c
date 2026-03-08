#include "recomp.h"
#include "disable_warnings.h"

void sub_80051508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x780($v0)
    ctx->r2 = MEM_W(-0X780, ctx->r2);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // bne         $v0, $zero, L_80051610
    if (ctx->r2 != 0) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_80051610;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_80051558
    // nop

    goto L_80051558;
    // nop

L_80051530:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_80051558:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80051530
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_80051530;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_800515A8
    // nop

    goto L_800515A8;
    // nop

L_80051580:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_800515A8:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80051580
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xD
        ctx->r2 = 0 | 0XD;
        goto L_80051580;
    }
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // j           L_800515F8
    // nop

    goto L_800515F8;
    // nop

L_800515D0:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_800515F8:
    // nop

    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_800515D0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800515D0;
    }
    // nop

L_80051610:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x7CC($a0)
    ctx->r4 = MEM_W(-0X7CC, ctx->r4);
    // nop

    // lhu         $v0, 0x1AA($a0)
    ctx->r2 = MEM_HU(0X1AA, ctx->r4);
    // nop

    // andi        $v0, $v0, 0xFFCF
    ctx->r2 = ctx->r2 & 0XFFCF;
    // sh          $v0, 0x1AA($a0)
    MEM_H(0X1AA, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x1AA($a0)
    ctx->r2 = MEM_HU(0X1AA, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // beq         $v0, $zero, L_80051668
    if (ctx->r2 == 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_80051668;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80051644:
    // slti        $v0, $v1, 0xF01
    ctx->r2 = SIGNED(ctx->r3) < 0XF01 ? 1 : 0;
    // beq         $v0, $zero, L_80051668
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80051668;
    }
    // nop

    // lhu         $v0, 0x1AA($a0)
    ctx->r2 = MEM_HU(0X1AA, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // bne         $v0, $zero, L_80051644
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80051644;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80051668:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x798($v0)
    ctx->r2 = MEM_W(-0X798, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80051698
    if (ctx->r2 == 0) {
        // lui         $a0, 0xF000
        ctx->r4 = S32(0XF000 << 16);
        goto L_80051698;
    }
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x798($v0)
    ctx->r2 = MEM_W(-0X798, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_800516A4
    // nop

    goto L_800516A4;
    // nop

L_80051698:
    // ori         $a0, $a0, 0x9
    ctx->r4 = ctx->r4 | 0X9;
    // jal         0x80062A40
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    KF_DeliverEvent(rdram, ctx);
    goto after_1;
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    after_1:
L_800516A4:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
