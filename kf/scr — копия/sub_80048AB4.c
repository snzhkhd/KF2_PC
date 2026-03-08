#include "recomp.h"
#include "disable_warnings.h"

void sub_80048AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v1, $a0, 0x14
    ctx->r3 = ADD32(ctx->r4, 0X14);
    // ori         $t0, $zero, 0xF2
    ctx->r8 = 0 | 0XF2;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // addiu       $a2, $a0, 0x13
    ctx->r6 = ADD32(ctx->r4, 0X13);
L_80048AC8:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $t0, L_80048AEC
    if (ctx->r2 == ctx->r8) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80048AEC;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // bne         $v0, $a3, L_80048AC8
    if (ctx->r2 != ctx->r7) {
        // nop
    
        goto L_80048AC8;
    }
    // nop

    // lbu         $v0, 0x10($a0)
    ctx->r2 = MEM_BU(0X10, ctx->r4);
    // j           L_80048B08
    // nop

    goto L_80048B08;
    // nop

L_80048AEC:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $a1, L_80048B04
    if (ctx->r2 == ctx->r5) {
        // subu        $v0, $v1, $a2
        ctx->r2 = SUB32(ctx->r3, ctx->r6);
        goto L_80048B04;
    }
    // subu        $v0, $v1, $a2
    ctx->r2 = SUB32(ctx->r3, ctx->r6);
    // j           L_80048AC8
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    goto L_80048AC8;
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80048B04:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80048B08:
    // jr          $ra
    // nop

    return;
    // nop

;}
