#include "recomp.h"
#include "disable_warnings.h"

void sub_8003FB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // lw          $s1, 0x60($s0)
    ctx->r17 = MEM_W(0X60, ctx->r16);
    // nop

    // lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8003FBC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003FBC0;
    }
    // nop

    // jal         0x8003FAE8
    // nop

    sub_8003FAE8(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $a1, $s0, 0x2C
    ctx->r5 = ADD32(ctx->r16, 0X2C);
    // ori         $a2, $zero, 0x7F
    ctx->r6 = 0 | 0X7F;
    // ori         $a3, $zero, 0x6000
    ctx->r7 = 0 | 0X6000;
    // lbu         $a0, 0x4($s1)
    ctx->r4 = MEM_BU(0X4, ctx->r17);
    // ori         $v1, $zero, 0x7800
    ctx->r3 = 0 | 0X7800;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // andi        $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 & 0X7F;
    // jal         0x80014414
    // addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    PlayPositionalSound3D_Wrap(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    after_1:
    // j           L_8003FBE0
    // nop

    goto L_8003FBE0;
    // nop

L_8003FBC0:
    // jal         0x8003FAE8
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003FAE8(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // addiu       $a1, $s0, 0x2C
    ctx->r5 = ADD32(ctx->r16, 0X2C);
    // ori         $a2, $zero, 0x6E
    ctx->r6 = 0 | 0X6E;
    // lbu         $a0, 0x4($s1)
    ctx->r4 = MEM_BU(0X4, ctx->r17);
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // jal         0x800143E0
    // addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    sub_800143E0(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    after_3:
L_8003FBE0:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
