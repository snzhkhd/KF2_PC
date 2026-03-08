#include "recomp.h"
#include "disable_warnings.h"

void sub_8003C250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8003C274
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003C274;
    }
    // nop

    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79B4($v0)
    ctx->r2 = MEM_W(0X79B4, ctx->r2);
    // nop

    // sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
    // sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
L_8003C274:
    // jr          $ra
    // nop

    return;
    // nop

;}
