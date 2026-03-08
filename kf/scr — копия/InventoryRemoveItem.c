#include "recomp.h"
#include "disable_warnings.h"

void InventoryRemoveItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // bne         $v0, $zero, L_80049D50
    if (ctx->r2 != 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80049D50;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_80049D64
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80049D64;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80049D50:
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80049D64:
    // jr          $ra
    // nop

    return;
    // nop

;}
