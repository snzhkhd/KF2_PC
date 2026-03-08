#include "recomp.h"
#include "disable_warnings.h"

void sub_800427C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_800427E4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_800427E4;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4B12($v0)
    ctx->r2 = MEM_HU(-0X4B12, ctx->r2);
L_800427E4:
    // jr          $ra
    // nop

    return;
    // nop

;}
