#include "recomp.h"
#include "disable_warnings.h"

void InitPlayerInventory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // addiu       $s1, $s1, 0x519C
    ctx->r17 = ADD32(ctx->r17, 0X519C);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x40
    ctx->r6 = 0 | 0X40;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x800176E4
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    memset_0(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // addiu       $s0, $s1, 0x100
    ctx->r16 = ADD32(ctx->r17, 0X100);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0xE00
    ctx->r6 = 0 | 0XE00;
    memset_0(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0xE00
    ctx->r6 = 0 | 0XE00;
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sh          $v0, 0x51CC($at)
    MEM_H(0X51CC, ctx->r1) = ctx->r2;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sh          $v0, 0x51C8($at)
    MEM_H(0X51C8, ctx->r1) = ctx->r2;
    // lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // sh          $v0, 0x51C4($at)
    MEM_H(0X51C4, ctx->r1) = ctx->r2;
    // jal         0x80017AA4
    // ori         $a1, $zero, 0x3800
    ctx->r5 = 0 | 0X3800;
    Heap_Init(rdram, ctx);
    goto after_2;
    // ori         $a1, $zero, 0x3800
    ctx->r5 = 0 | 0X3800;
    after_2:
    // addiu       $s1, $s1, 0x3900
    ctx->r17 = ADD32(ctx->r17, 0X3900);
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8004ACD0:
    // sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $v1, L_8004ACD0
    if (ctx->r2 != ctx->r3) {
        // addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
        goto L_8004ACD0;
    }
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // addiu       $s0, $s0, -0x2190
    ctx->r16 = ADD32(ctx->r16, -0X2190);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x1E
    ctx->r6 = 0 | 0X1E;
    memset_0(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0x1E
    ctx->r6 = 0 | 0X1E;
    after_3:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
