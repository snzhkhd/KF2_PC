#include "recomp.h"
#include "disable_warnings.h"

void PlayAudioStream(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // beq         $s2, $v0, L_80014818
    if (ctx->r18 == ctx->r2) {
        // sw          $s1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r17;
        goto L_80014818;
    }
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A75($v0)
    ctx->r2 = MEM_BU(-0X4A75, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80014818
    if (ctx->r2 == 0) {
        // andi        $v1, $s2, 0xFF
        ctx->r3 = ctx->r18 & 0XFF;
        goto L_80014818;
    }
    // andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x5574
    ctx->r4 = ADD32(ctx->r4, -0X5574);
    // addu        $s1, $v0, $a0
    ctx->r17 = ADD32(ctx->r2, ctx->r4);
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(0X0, ctx->r17);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // beq         $v1, $a1, L_80014818
    if (ctx->r3 == ctx->r5) {
        // sll         $v1, $v1, 3
        ctx->r3 = S32(ctx->r3) << 3;
        goto L_80014818;
    }
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addiu       $v0, $a0, -0x438
    ctx->r2 = ADD32(ctx->r4, -0X438);
    // addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    // lh          $v1, 0x0($s3)
    ctx->r3 = MEM_H(0X0, ctx->r19);
    // nop

    // beq         $v1, $a1, L_80014818
    if (ctx->r3 == ctx->r5) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_80014818;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // beq         $v1, $v0, L_80014818
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80014818;
    }
    // nop

    // jal         0x800145F8
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_800145F8(rdram, ctx);
    goto after_0;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(0X6, ctx->r17);
    // nop

    // addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // bgez        $s0, L_800147CC
    if (SIGNED(ctx->r16) >= 0) {
        // addu        $s4, $v0, $zero
        ctx->r20 = ADD32(ctx->r2, 0);
        goto L_800147CC;
    }
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // j           L_800147DC
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    goto L_800147DC;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800147CC:
    // slti        $v0, $s0, 0x80
    ctx->r2 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_800147E0
    if (ctx->r2 != 0) {
        // sll         $v0, $s5, 16
        ctx->r2 = S32(ctx->r21) << 16;
        goto L_800147E0;
    }
    // sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21) << 16;
    // ori         $s0, $zero, 0x7F
    ctx->r16 = 0 | 0X7F;
L_800147DC:
    // sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21) << 16;
L_800147E0:
    // lh          $a0, 0x0($s3)
    ctx->r4 = MEM_H(0X0, ctx->r19);
    // lh          $a1, 0x2($s1)
    ctx->r5 = MEM_H(0X2, ctx->r17);
    // lh          $a2, 0x4($s1)
    ctx->r6 = MEM_H(0X4, ctx->r17);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16) << 16;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80058698
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    SPU_PlayVoice(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
    // sh          $s2, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r18;
L_80014818:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
