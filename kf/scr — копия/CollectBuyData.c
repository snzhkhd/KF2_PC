#include "recomp.h"
#include "disable_warnings.h"

void CollectBuyData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(0X10, ctx->r29);
    // lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(0X14, ctx->r29);
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // slt         $v0, $t0, $t2
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // beq         $v0, $zero, L_8001F464
    if (ctx->r2 == 0) {
        // sll         $v0, $t1, 4
        ctx->r2 = S32(ctx->r9) << 4;
        goto L_8001F464;
    }
    // sll         $v0, $t1, 4
    ctx->r2 = S32(ctx->r9) << 4;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x29A8
    ctx->r3 = ADD32(ctx->r3, -0X29A8);
    // subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_8001F424:
    // lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(0X0, ctx->r7);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(0X0, ctx->r7);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // slt         $v0, $t0, $t2
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // bne         $v0, $zero, L_8001F424
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
        goto L_8001F424;
    }
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8001F464:
    // jr          $ra
    // nop

    return;
    // nop

;}
