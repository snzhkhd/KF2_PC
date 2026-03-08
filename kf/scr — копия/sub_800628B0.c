#include "recomp.h"
#include "disable_warnings.h"

void sub_800628B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $t0, $a0, 0xFFFF
    ctx->r8 = ctx->r4 & 0XFFFF;
    // slti        $v0, $t0, 0x3
    ctx->r2 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_800628C8
    if (ctx->r2 != 0) {
        // ori         $a3, $zero, 0x48
        ctx->r7 = 0 | 0X48;
        goto L_800628C8;
    }
    // ori         $a3, $zero, 0x48
    ctx->r7 = 0 | 0X48;
    // j           L_80062948
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80062948;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800628C8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6144($v0)
    ctx->r2 = MEM_W(0X6144, ctx->r2);
    // sll         $v1, $t0, 4
    ctx->r3 = S32(ctx->r8) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sltiu       $v0, $t0, 0x2
    ctx->r2 = ctx->r8 < 0X2 ? 1 : 0;
    // sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // sh          $a1, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r5;
    // beq         $v0, $zero, L_80062908
    if (ctx->r2 == 0) {
        // andi        $v0, $a2, 0x10
        ctx->r2 = ctx->r6 & 0X10;
        goto L_80062908;
    }
    // andi        $v0, $a2, 0x10
    ctx->r2 = ctx->r6 & 0X10;
    // beq         $v0, $zero, L_800628F8
    if (ctx->r2 == 0) {
        // andi        $v0, $a2, 0x1
        ctx->r2 = ctx->r6 & 0X1;
        goto L_800628F8;
    }
    // andi        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 & 0X1;
    // ori         $a3, $zero, 0x49
    ctx->r7 = 0 | 0X49;
L_800628F8:
    // bne         $v0, $zero, L_80062924
    if (ctx->r2 != 0) {
        // andi        $v0, $a2, 0x1000
        ctx->r2 = ctx->r6 & 0X1000;
        goto L_80062924;
    }
    // andi        $v0, $a2, 0x1000
    ctx->r2 = ctx->r6 & 0X1000;
    // j           L_80062924
    // ori         $a3, $a3, 0x100
    ctx->r7 = ctx->r7 | 0X100;
    goto L_80062924;
    // ori         $a3, $a3, 0x100
    ctx->r7 = ctx->r7 | 0X100;
L_80062908:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $t0, $v0, L_80062924
    if (ctx->r8 != ctx->r2) {
        // andi        $v0, $a2, 0x1000
        ctx->r2 = ctx->r6 & 0X1000;
        goto L_80062924;
    }
    // andi        $v0, $a2, 0x1000
    ctx->r2 = ctx->r6 & 0X1000;
    // andi        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 & 0X1;
    // bne         $v0, $zero, L_80062924
    if (ctx->r2 != 0) {
        // andi        $v0, $a2, 0x1000
        ctx->r2 = ctx->r6 & 0X1000;
        goto L_80062924;
    }
    // andi        $v0, $a2, 0x1000
    ctx->r2 = ctx->r6 & 0X1000;
    // ori         $a3, $zero, 0x248
    ctx->r7 = 0 | 0X248;
L_80062924:
    // beq         $v0, $zero, L_80062930
    if (ctx->r2 == 0) {
        // sll         $v1, $t0, 4
        ctx->r3 = S32(ctx->r8) << 4;
        goto L_80062930;
    }
    // sll         $v1, $t0, 4
    ctx->r3 = S32(ctx->r8) << 4;
    // ori         $a3, $a3, 0x10
    ctx->r7 = ctx->r7 | 0X10;
L_80062930:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x6144($a0)
    ctx->r4 = MEM_W(0X6144, ctx->r4);
    // nop

    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $a3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r7;
L_80062948:
    // jr          $ra
    // nop

    return;
    // nop

;}
