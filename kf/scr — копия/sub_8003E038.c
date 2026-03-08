#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, 0x79B4($v1)
    ctx->r3 = MEM_W(0X79B4, ctx->r3);
    // ori         $v0, $zero, 0x60
    ctx->r2 = 0 | 0X60;
    // jr          $ra
    // sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    return;
    // sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
;}
