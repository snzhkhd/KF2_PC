#include "recomp.h"
#include "disable_warnings.h"

void sub_80052510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // bgez        $v0, L_80052534
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
        goto L_80052534;
    }
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
L_80052534:
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_8005259C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005259C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $v0, -0x21BC($at)
    MEM_W(-0X21BC, ctx->r1) = ctx->r2;
    // beq         $a1, $zero, L_8005255C
    if (ctx->r5 == 0) {
        // ori         $v0, $v1, 0x100
        ctx->r2 = ctx->r3 | 0X100;
        goto L_8005255C;
    }
    // ori         $v0, $v1, 0x100
    ctx->r2 = ctx->r3 | 0X100;
    // j           L_80052560
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    goto L_80052560;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_8005255C:
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
L_80052560:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $v0, -0x21B8($at)
    MEM_W(-0X21B8, ctx->r1) = ctx->r2;
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // bne         $s0, $zero, L_80052584
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80052584;
    }
    // nop

    // jal         0x80053364
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80053364(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
L_80052584:
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x21BC
    ctx->r4 = ADD32(ctx->r4, -0X21BC);
    // jal         0x800526FC
    // nop

    sub_800526FC(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_800525A0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800525A0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8005259C:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800525A0:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
