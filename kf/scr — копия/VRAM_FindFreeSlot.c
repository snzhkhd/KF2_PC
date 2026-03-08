#include "recomp.h"
#include "disable_warnings.h"

void VRAM_FindFreeSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, 0x4E0C
    ctx->r3 = ADD32(ctx->r3, 0X4E0C);
    // ori         $a0, $zero, 0x8
    ctx->r4 = 0 | 0X8;
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
L_8002F958:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $a1, L_8002F978
    if (ctx->r2 == ctx->r5) {
        // addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
        goto L_8002F978;
    }
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $zero, L_8002F958
    if (ctx->r4 != 0) {
        // addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
        goto L_8002F958;
    }
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // j           L_8002F97C
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8002F97C;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002F978:
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8002F97C:
    // jr          $ra
    // nop

    return;
    // nop

;}
