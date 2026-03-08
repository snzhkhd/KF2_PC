#include "recomp.h"
#include "disable_warnings.h"

void sub_80034AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // addiu       $a2, $a2, 0x4F50
    ctx->r6 = ADD32(ctx->r6, 0X4F50);
    // lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(0X8, ctx->r4);
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // sltiu       $v0, $a1, 0x18
    ctx->r2 = ctx->r5 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_80034B3C
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80034B3C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x4F4C($v1)
    ctx->r3 = MEM_W(0X4F4C, ctx->r3);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // sltiu       $v0, $a0, 0x18
    ctx->r2 = ctx->r4 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_80034B38
    if (ctx->r2 == 0) {
        // addiu       $v1, $a2, 0x10
        ctx->r3 = ADD32(ctx->r6, 0X10);
        goto L_80034B38;
    }
    // addiu       $v1, $a2, 0x10
    ctx->r3 = ADD32(ctx->r6, 0X10);
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // j           L_80034B3C
    // nop

    goto L_80034B3C;
    // nop

L_80034B38:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80034B3C:
    // jr          $ra
    // nop

    return;
    // nop

;}
