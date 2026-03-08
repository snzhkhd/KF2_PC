#include "recomp.h"
#include "disable_warnings.h"

void JustReturn2(uint8_t* rdram, recomp_context* ctx) 
{
    printf("JustReturn2\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lbu         $v1, 0x61A2($v1)
    ctx->r3 = MEM_BU(0X61A2, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80063174
    if (ctx->r3 == ctx->r2) {
        // sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
        goto L_80063174;
    }
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_8006320C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8006320C;
    }
    // nop

    // j           L_80063250
    // nop

    goto L_80063250;
    // nop

L_80063174:
    // lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(0X4, ctx->r16);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lh          $v1, 0x61A4($v1)
    ctx->r3 = MEM_H(0X61A4, ctx->r3);
    // nop

    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_800631FC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800631FC;
    }
    // nop

    // lh          $a3, 0x0($s0)
    ctx->r7 = MEM_H(0X0, ctx->r16);
    // nop

    // addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800631FC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800631FC;
    }
    // nop

    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(0X2, ctx->r16);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lh          $a0, 0x61A6($a0)
    ctx->r4 = MEM_H(0X61A6, ctx->r4);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800631FC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800631FC;
    }
    // nop

    // lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(0X6, ctx->r16);
    // nop

    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800631FC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800631FC;
    }
    // nop

    // blez        $a1, L_800631FC
    if (SIGNED(ctx->r5) <= 0) {
        // nop
    
        goto L_800631FC;
    }
    // nop

    // bltz        $a3, L_800631FC
    if (SIGNED(ctx->r7) < 0) {
        // nop
    
        goto L_800631FC;
    }
    // nop

    // bltz        $v1, L_800631FC
    if (SIGNED(ctx->r3) < 0) {
        // nop
    
        goto L_800631FC;
    }
    // nop

    // bgtz        $a2, L_80063250
    if (SIGNED(ctx->r6) > 0) {
        // nop
    
        goto L_80063250;
    }
    // nop

L_800631FC:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3740
    ctx->r4 = ADD32(ctx->r4, 0X3740);
    // j           L_80063214
    // nop

    goto L_80063214;
    // nop

L_8006320C:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3760
    ctx->r4 = ADD32(ctx->r4, 0X3760);
L_80063214:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x619C($v0)
    ctx->r2 = MEM_W(0X619C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    after_0:
    // lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(0X0, ctx->r16);
    // lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(0X2, ctx->r16);
    // lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(0X4, ctx->r16);
    // lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(0X6, ctx->r16);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x619C($v1)
    ctx->r3 = MEM_W(0X619C, ctx->r3);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x374C
    ctx->r4 = ADD32(ctx->r4, 0X374C);
    // jalr        $v1
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
L_80063250:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
