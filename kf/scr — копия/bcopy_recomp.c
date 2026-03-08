#include "recomp.h"
#include "disable_warnings.h"

void bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {

    printf("bcopy_recomp\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // jr          $t2
    // addiu       $t1, $zero, 0x27
    ctx->r9 = ADD32(0, 0X27);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // addiu       $t1, $zero, 0x27
    ctx->r9 = ADD32(0, 0X27);
;}
