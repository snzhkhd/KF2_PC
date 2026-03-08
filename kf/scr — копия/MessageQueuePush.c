#include "recomp.h"
#include "disable_warnings.h"

void MessageQueuePush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // slti        $a0, $a0, 0xF0
    ctx->r4 = SIGNED(ctx->r4) < 0XF0 ? 1 : 0;
    // sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // beq         $a0, $zero, L_80035D5C
    if (ctx->r4 == 0) {
        // sw          $a3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r7;
        goto L_80035D5C;
    }
    // sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // addiu       $a1, $a1, 0x4DF5
    ctx->r5 = ADD32(ctx->r5, 0X4DF5);
    // lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(0X0, ctx->r5);
    // nop

    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x4DDC
    ctx->r1 = ADD32(ctx->r1, 0X4DDC);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80035D5C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80035D5C;
    }
    // nop

    // lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(0X0, ctx->r29);
    // nop

    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // addiu       $at, $at, 0x4DDC
    ctx->r1 = ADD32(ctx->r1, 0X4DDC);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // lw          $v1, 0x0($sp)
    ctx->r3 = MEM_W(0X0, ctx->r29);
    // ori         $v0, $zero, 0x15
    ctx->r2 = 0 | 0X15;
    // bne         $v1, $v0, L_80035D48
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $a1, -0x11
        ctx->r4 = ADD32(ctx->r5, -0X11);
        goto L_80035D48;
    }
    // addiu       $a0, $a1, -0x11
    ctx->r4 = ADD32(ctx->r5, -0X11);
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lhu         $v1, 0x4($sp)
    ctx->r3 = MEM_HU(0X4, ctx->r29);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_80035D48:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_80035D5C:
    // jr          $ra
    // nop

    return;
    // nop

;}
