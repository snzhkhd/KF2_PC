#include "recomp.h"
#include "disable_warnings.h"

void loadDatabaseCallback(uint8_t* rdram, recomp_context* ctx) 
{
    printf("Map_Load state LoadingTileset\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = ctx->r2;
    // jr          $ra
    // nop

    return;
    // nop

;}
