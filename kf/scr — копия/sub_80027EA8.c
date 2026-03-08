#include "recomp.h"
#include "disable_warnings.h"

void sub_80027EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4AA3($at)
    MEM_B(-0X4AA3, ctx->r1) = ctx->r4;
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $a0, $v0, L_80027EC8
    if (ctx->r4 == ctx->r2) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80027EC8;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4AA4($at)
    MEM_B(-0X4AA4, ctx->r1) = ctx->r2;
L_80027EC8:
    // jr          $ra
    // nop

    return;
    // nop

;}
