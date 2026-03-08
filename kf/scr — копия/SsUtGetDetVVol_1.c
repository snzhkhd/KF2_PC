#include "recomp.h"
#include "disable_warnings.h"

void SsUtGetDetVVol_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80059324
    if (ctx->r2 != 0) {
        // sll         $v1, $a0, 16
        ctx->r3 = S32(ctx->r4) << 16;
        goto L_80059324;
    }
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // j           L_8005935C
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8005935C;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80059324:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(0X44, ctx->r2);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(0X44, ctx->r2);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v1, 0x2($v1)
    ctx->r3 = MEM_HU(0X2, ctx->r3);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // sh          $v1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r3;
L_8005935C:
    // jr          $ra
    // nop

    return;
    // nop

;}
