#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4A6F
    ctx->r3 = ADD32(ctx->r3, -0X4A6F);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // bne         $v0, $zero, L_8002C11C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_8002C11C;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x49EC($at)
    MEM_H(-0X49EC, ctx->r1) = 0;
L_8002C11C:
    // jr          $ra
    // nop

    return;
    // nop

;}
