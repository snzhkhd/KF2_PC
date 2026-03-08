#include "recomp.h"
#include "disable_warnings.h"

void Map_MarkOccupiedTiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $a2, $a2, 0x800
    ctx->r6 = ADD32(ctx->r6, 0X800);
    // subu        $v0, $a0, $a2
    ctx->r2 = SUB32(ctx->r4, ctx->r6);
    // sra         $t3, $v0, 11
    ctx->r11 = S32(ctx->r2) >> 11;
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // subu        $t4, $a0, $t3
    ctx->r12 = SUB32(ctx->r4, ctx->r11);
    // subu        $t0, $a1, $a2
    ctx->r8 = SUB32(ctx->r5, ctx->r6);
    // sra         $t0, $t0, 11
    ctx->r8 = S32(ctx->r8) >> 11;
    // addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    // subu        $a1, $a1, $t0
    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    // sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8) << 1;
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $t3, 2
    ctx->r2 = S32(ctx->r11) << 2;
    // addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x428C
    ctx->r4 = ADD32(ctx->r4, -0X428C);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7) << 2;
    // addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8002E2C0:
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // sltiu       $v0, $t0, 0x50
    ctx->r2 = ctx->r8 < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_8002E304
    if (ctx->r2 == 0) {
        // addiu       $v1, $a0, 0x320
        ctx->r3 = ADD32(ctx->r4, 0X320);
        goto L_8002E304;
    }
    // addiu       $v1, $a0, 0x320
    ctx->r3 = ADD32(ctx->r4, 0X320);
    // addu        $t1, $t3, $zero
    ctx->r9 = ADD32(ctx->r11, 0);
    // addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8002E2DC:
    // sltiu       $v0, $t1, 0x50
    ctx->r2 = ctx->r9 < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_8002E2F8
    if (ctx->r2 == 0) {
        // addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_8002E2F8;
    }
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8002E2F8:
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $t2, L_8002E2DC
    if (ctx->r6 != ctx->r10) {
        // addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
        goto L_8002E2DC;
    }
    // addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
L_8002E304:
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $t2, L_8002E2C0
    if (ctx->r5 != ctx->r10) {
        // addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_8002E2C0;
    }
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // jr          $ra
    // nop

    return;
    // nop

;}
