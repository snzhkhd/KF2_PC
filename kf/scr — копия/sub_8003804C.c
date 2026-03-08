#include "recomp.h"
#include "disable_warnings.h"

void sub_8003804C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // beq         $a0, $v0, L_80038118
    if (ctx->r4 == ctx->r2) {
        // sw          $a1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r5;
        goto L_80038118;
    }
    // sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // addiu       $a0, $a0, -0x6810
    ctx->r4 = ADD32(ctx->r4, -0X6810);
    // addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(0X6, ctx->r6);
    // addiu       $a0, $a0, -0x1E00
    ctx->r4 = ADD32(ctx->r4, -0X1E00);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $a1, $v0, L_800380F4
    if (ctx->r5 == ctx->r2) {
        // slti        $v0, $a1, 0x2
        ctx->r2 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
        goto L_800380F4;
    }
    // slti        $v0, $a1, 0x2
    ctx->r2 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800380B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800380B8;
    }
    // nop

    // beq         $a1, $zero, L_800380D4
    if (ctx->r5 == 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_800380D4;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_80038118
    // nop

    goto L_80038118;
    // nop

L_800380B8:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $a1, $v0, L_80038100
    if (ctx->r5 == ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80038100;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $a1, $v0, L_8003810C
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_8003810C;
    }
    // nop

    // j           L_80038118
    // nop

    goto L_80038118;
    // nop

L_800380D4:
    // sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // sb          $zero, 0x38($a2)
    MEM_B(0X38, ctx->r6) = 0;
    // lbu         $v1, 0x1($v1)
    ctx->r3 = MEM_BU(0X1, ctx->r3);
    // nop

    // bne         $v1, $v0, L_80038118
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x400
        ctx->r2 = 0 | 0X400;
        goto L_80038118;
    }
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // j           L_80038118
    // sh          $v0, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r2;
    goto L_80038118;
    // sh          $v0, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r2;
L_800380F4:
    // lbu         $v0, 0x8($sp)
    ctx->r2 = MEM_BU(0X8, ctx->r29);
    // j           L_80038118
    // sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    goto L_80038118;
    // sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_80038100:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_80038118
    // sb          $v0, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r2;
    goto L_80038118;
    // sb          $v0, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r2;
L_8003810C:
    // lhu         $v0, 0x8($sp)
    ctx->r2 = MEM_HU(0X8, ctx->r29);
    // nop

    // sh          $v0, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r2;
L_80038118:
    // jr          $ra
    // nop

    return;
    // nop

;}
