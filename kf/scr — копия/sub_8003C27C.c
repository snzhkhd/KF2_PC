#include "recomp.h"
#include "disable_warnings.h"

void sub_8003C27C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, 0x79B4($v1)
    ctx->r3 = MEM_W(0X79B4, ctx->r3);
    // andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $a1, $v0, L_8003C2AC
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_8003C2AC;
    }
    // nop

    // lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(0XC, ctx->r3);
    // nop

    // beq         $v0, $a1, L_8003C2AC
    if (ctx->r2 == ctx->r5) {
        // nop
    
        goto L_8003C2AC;
    }
    // nop

    // sb          $a0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r4;
    // sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_8003C2AC:
    // jr          $ra
    // nop

    return;
    // nop

;}
