#include "recomp.h"
#include "disable_warnings.h"

void AllocateParticleSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x1280
    ctx->r3 = ADD32(ctx->r3, -0X1280);
    // ori         $a0, $zero, 0x80
    ctx->r4 = 0 | 0X80;
    // ori         $a2, $zero, 0xFF
    ctx->r6 = 0 | 0XFF;
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_80042C58:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $a2, L_80042C7C
    if (ctx->r2 == ctx->r6) {
        // addu        $a0, $a0, $a1
        ctx->r4 = ADD32(ctx->r4, ctx->r5);
        goto L_80042C7C;
    }
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // bne         $v0, $zero, L_80042C58
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x48
        ctx->r3 = ADD32(ctx->r3, 0X48);
        goto L_80042C58;
    }
    // addiu       $v1, $v1, 0x48
    ctx->r3 = ADD32(ctx->r3, 0X48);
    // j           L_80042C80
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80042C80;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80042C7C:
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80042C80:
    // jr          $ra
    // nop

    return;
    // nop

;}
