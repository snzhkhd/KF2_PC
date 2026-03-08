#include "recomp.h"
#include "disable_warnings.h"

void InitParticleSystem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x1280
    ctx->r4 = ADD32(ctx->r4, -0X1280);
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
L_8004861C:
    // sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // sltiu       $v0, $v0, 0x80
    ctx->r2 = ctx->r2 < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8004861C
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x48
        ctx->r4 = ADD32(ctx->r4, 0X48);
        goto L_8004861C;
    }
    // addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
