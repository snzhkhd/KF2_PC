#include "recomp.h"
#include "disable_warnings.h"

void Music_PlaySEQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A74($v0)
    ctx->r2 = MEM_BU(-0X4A74, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // beq         $v0, $zero, L_80014048
    if (ctx->r2 == 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_80014048;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x59CC($v0)
    ctx->r2 = MEM_W(-0X59CC, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80014048
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80014048;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x59D8($a0)
    ctx->r4 = MEM_W(-0X59D8, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lh          $a1, -0x59A4($a1)
    ctx->r5 = MEM_H(-0X59A4, ctx->r5);
    // jal         0x80059E38
    // nop

    SEQ_Open(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // ori         $a1, $zero, 0x3C
    ctx->r5 = 0 | 0X3C;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x59D4($at)
    MEM_H(-0X59D4, ctx->r1) = ctx->r2;
    // jal         0x80052198
    // ori         $a2, $zero, 0x3C
    ctx->r6 = 0 | 0X3C;
    CDAudio_SetVolume(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x3C
    ctx->r6 = 0 | 0X3C;
    after_1:
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x8005C42C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    SEQ_Play(rdram, ctx);
    goto after_2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // ori         $a0, $zero, 0x7F
    ctx->r4 = 0 | 0X7F;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x59D0($at)
    MEM_W(-0X59D0, ctx->r1) = ctx->r2;
    // jal         0x80054388
    // ori         $a1, $zero, 0x7F
    ctx->r5 = 0 | 0X7F;
    SetMasterVolume(rdram, ctx);
    goto after_3;
    // ori         $a1, $zero, 0x7F
    ctx->r5 = 0 | 0X7F;
    after_3:
L_80014048:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
