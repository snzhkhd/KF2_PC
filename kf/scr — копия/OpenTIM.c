#include "recomp.h"
#include "disable_warnings.h"

void KF_OpenTIM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a0, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = ctx->r4;
    // jr          $ra
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
