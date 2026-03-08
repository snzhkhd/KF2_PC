#include "recomp.h"
#include "disable_warnings.h"

void SetProjectileModel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(0X4, ctx->r4);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80038E64
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80038E64;
    }
    // nop

    // sb          $a1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r5;
    // sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
L_80038E64:
    // jr          $ra
    // nop

    return;
    // nop

;}
