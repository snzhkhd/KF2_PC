#include "recomp.h"
#include "disable_warnings.h"

void sub_80058A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(0X28, ctx->r29);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2570($v0)
    ctx->r2 = MEM_W(-0X2570, ctx->r2);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // beq         $v0, $v1, L_80058BA8
    if (ctx->r2 == ctx->r3) {
        // addu        $t1, $a0, $zero
        ctx->r9 = ADD32(ctx->r4, 0);
        goto L_80058BA8;
    }
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v1, -0x2570($at)
    MEM_W(-0X2570, ctx->r1) = ctx->r3;
    // andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_80058BA0
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4) << 16;
        goto L_80058BA0;
    }
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759A
    ctx->r1 = ADD32(ctx->r1, -0X759A);
    // addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_80058BA0
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $a2, 16
        ctx->r2 = S32(ctx->r6) << 16;
        goto L_80058BA0;
    }
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759E
    ctx->r1 = ADD32(ctx->r1, -0X759E);
    // addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_80058BA0
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $a3, 16
        ctx->r2 = S32(ctx->r7) << 16;
        goto L_80058BA0;
    }
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759C
    ctx->r1 = ADD32(ctx->r1, -0X759C);
    // addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_80058BA0
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $t2, 16
        ctx->r2 = S32(ctx->r10) << 16;
        goto L_80058BA0;
    }
    // sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10) << 16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A4
    ctx->r1 = ADD32(ctx->r1, -0X75A4);
    // addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_80058BA0
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80058BA0;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75B0
    ctx->r1 = ADD32(ctx->r1, -0X75B0);
    // addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // nop

    // bne         $v1, $v0, L_80058B80
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80058B80;
    }
    // nop

    // jal         0x80055950
    // nop

    sub_80055950(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_80058B90
    // nop

    goto L_80058B90;
    // nop

L_80058B80:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $t1, -0x1916($at)
    MEM_H(-0X1916, ctx->r1) = ctx->r9;
    // jal         0x80054EFC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80054EFC(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
L_80058B90:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, -0x2570($at)
    MEM_W(-0X2570, ctx->r1) = 0;
    // j           L_80058BAC
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80058BAC;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80058BA0:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, -0x2570($at)
    MEM_W(-0X2570, ctx->r1) = 0;
L_80058BA8:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058BAC:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // nop

    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
