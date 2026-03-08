#include "recomp.h"
#include "disable_warnings.h"

void InventoryAddItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // nop

    // sltiu       $v0, $v1, 0x63
    ctx->r2 = ctx->r3 < 0X63 ? 1 : 0;
    // bne         $v0, $zero, L_80049DA4
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_80049DA4;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // jal         0x80035CC4
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    MessageQueuePush(rdram, ctx);
    goto after_0;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_0:
    // j           L_80049DD4
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80049DD4;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80049DA4:
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // addiu       $at, $at, -0x2190
    ctx->r1 = ADD32(ctx->r1, -0X2190);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // nop

    // lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(0X18, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80049DD4:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
