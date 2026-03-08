#include "recomp.h"
#include "disable_warnings.h"

void sub_80054FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x1930
    ctx->r3 = ADD32(ctx->r3, -0X1930);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // beq         $v0, $zero, L_80055080
    if (ctx->r2 == 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_80055080;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $t0, $v1, 0x7
    ctx->r8 = ADD32(ctx->r3, 0X7);
    // addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
L_80054FFC:
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lw          $a0, -0x1A08($a0)
    ctx->r4 = MEM_W(-0X1A08, ctx->r4);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(0X6, ctx->r4);
    // lbu         $v1, -0x5($t0)
    ctx->r3 = MEM_BU(-0X5, ctx->r8);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_80055068
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055068;
    }
    // nop

    // lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(0X7, ctx->r4);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80055068
    if (ctx->r2 != 0) {
        // andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
        goto L_80055068;
    }
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // lbu         $a0, 0x16($a0)
    ctx->r4 = MEM_BU(0X16, ctx->r4);
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // addu        $v1, $t1, $v1
    ctx->r3 = ADD32(ctx->r9, ctx->r3);
    // sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80055068:
    // lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(0X0, ctx->r10);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80054FFC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80054FFC;
    }
    // nop

L_80055080:
    // jr          $ra
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    return;
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
;}
