#include "recomp.h"
#include "disable_warnings.h"

void sub_80033FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // addiu       $a2, $a2, 0x4DFD
    ctx->r6 = ADD32(ctx->r6, 0X4DFD);
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // beq         $v0, $zero, L_800340F0
    if (ctx->r2 == 0) {
        // ori         $a3, $zero, 0xF0
        ctx->r7 = 0 | 0XF0;
        goto L_800340F0;
    }
    // ori         $a3, $zero, 0xF0
    ctx->r7 = 0 | 0XF0;
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // lh          $a1, 0x4DFE($a1)
    ctx->r5 = MEM_H(0X4DFE, ctx->r5);
    // nop

    // div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80033FF8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80033FF8;
    }
    // nop

    // break       7
    do_break(2147696628);
L_80033FF8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80034010
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80034010;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a1, $at, L_80034010
    if (ctx->r5 != ctx->r1) {
        // nop
    
        goto L_80034010;
    }
    // nop

    // break       6
    do_break(2147696652);
L_80034010:
    // mflo        $a1
    ctx->r5 = lo;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lh          $a0, 0x4E00($a0)
    ctx->r4 = MEM_H(0X4E00, ctx->r4);
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80034034
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80034034;
    }
    // nop

    // break       7
    do_break(2147696688);
L_80034034:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8003404C
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003404C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_8003404C
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_8003404C;
    }
    // nop

    // break       6
    do_break(2147696712);
L_8003404C:
    // mflo        $a0
    ctx->r4 = lo;
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lh          $v1, 0x4E02($v1)
    ctx->r3 = MEM_H(0X4E02, ctx->r3);
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80034070
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80034070;
    }
    // nop

    // break       7
    do_break(2147696748);
L_80034070:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80034088
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80034088;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80034088
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80034088;
    }
    // nop

    // break       6
    do_break(2147696772);
L_80034088:
    // mflo        $v1
    ctx->r3 = lo;
    // ori         $a2, $zero, 0x140
    ctx->r6 = 0 | 0X140;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xD0
    ctx->r2 = 0 | 0XD0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x37
    ctx->r2 = 0 | 0X37;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x7BDC
    ctx->r2 = 0 | 0X7BDC;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // jal         0x80033C78
    // sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    RenderFadeOverlay(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
L_800340F0:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
