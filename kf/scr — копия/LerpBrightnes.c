#include "recomp.h"
#include "disable_warnings.h"

void LerpBrightnes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // ori         $s4, $zero, 0xC0
    ctx->r20 = 0 | 0XC0;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // ori         $s3, $zero, 0xF0
    ctx->r19 = 0 | 0XF0;
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // ori         $fp, $zero, 0x20
    ctx->r30 = 0 | 0X20;
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // ori         $s7, $zero, 0xA
    ctx->r23 = 0 | 0XA;
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // ori         $s6, $zero, 0x11F
    ctx->r22 = 0 | 0X11F;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // ori         $s5, $zero, 0x109
    ctx->r21 = 0 | 0X109;
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800374A0:
    // jal         0x8002FE74
    // nop

    KF_RenderBegin(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // ori         $t0, $zero, 0x80
    ctx->r8 = 0 | 0X80;
    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // sra         $v1, $s2, 1
    ctx->r3 = S32(ctx->r18) >> 1;
    // lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_800377F0
    if (ctx->r2 != 0) {
        // subu        $s1, $t0, $v1
        ctx->r17 = SUB32(ctx->r8, ctx->r3);
        goto L_800377F0;
    }
    // subu        $s1, $t0, $v1
    ctx->r17 = SUB32(ctx->r8, ctx->r3);
    // jal         0x800673A0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    GPU_Cmd_SetBaseParams(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x140
    ctx->r6 = 0 | 0X140;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // sh          $s4, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r20;
    // sh          $zero, 0x12($s0)
    MEM_H(0X12, ctx->r16) = 0;
    // sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // sh          $s3, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r19;
    // sh          $s4, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r20;
    // sh          $s3, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r19;
    // sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // sb          $s4, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r20;
    // sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // sb          $s3, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r19;
    // sb          $s4, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r20;
    // sb          $s3, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r19;
    // jal         0x80067010
    // sh          $zero, 0xE($s0)
    MEM_H(0XE, ctx->r16) = 0;
    KF_GetTPage(rdram, ctx);
    goto after_2;
    // sh          $zero, 0xE($s0)
    MEM_H(0XE, ctx->r16) = 0;
    after_2:
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // sb          $s1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r17;
    // sb          $s1, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r17;
    // sb          $s1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r17;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x15C($a0)
    ctx->r4 = MEM_W(0X15C, ctx->r4);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80067238
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_3:
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // nop

    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_800377F0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800377F0;
    }
    // nop

    // jal         0x800673A0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    GPU_Cmd_SetBaseParams(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x200
    ctx->r6 = 0 | 0X200;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // ori         $v0, $zero, 0x140
    ctx->r2 = 0 | 0X140;
    // ori         $t0, $zero, 0x80
    ctx->r8 = 0 | 0X80;
    // sb          $t0, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r8;
    // sh          $s4, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r20;
    // sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // sh          $zero, 0x12($s0)
    MEM_H(0X12, ctx->r16) = 0;
    // sh          $s4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r20;
    // sh          $s3, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r19;
    // sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    // sh          $s3, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r19;
    // sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // sb          $s3, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r19;
    // sb          $t0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r8;
    // sb          $s3, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r19;
    // jal         0x80067010
    // sh          $zero, 0xE($s0)
    MEM_H(0XE, ctx->r16) = 0;
    KF_GetTPage(rdram, ctx);
    goto after_5;
    // sh          $zero, 0xE($s0)
    MEM_H(0XE, ctx->r16) = 0;
    after_5:
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // sb          $s1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r17;
    // sb          $s1, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r17;
    // sb          $s1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r17;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x15C($a0)
    ctx->r4 = MEM_W(0X15C, ctx->r4);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80067238
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_6;
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_6:
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // nop

    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_800377F0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800377F0;
    }
    // nop

    // jal         0x800673A0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    GPU_Cmd_SetBaseParams(rdram, ctx);
    goto after_7;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800672EC
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    GPU_Cmd_SetBlendFlag(rdram, ctx);
    goto after_8;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_8:
    // ori         $a0, $zero, 0x240
    ctx->r4 = 0 | 0X240;
    // ori         $a1, $zero, 0x1FF
    ctx->r5 = 0 | 0X1FF;
    // ori         $s1, $zero, 0xFF
    ctx->r17 = 0 | 0XFF;
    // sh          $fp, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r30;
    // sh          $s7, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r23;
    // sh          $s6, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r22;
    // sh          $s7, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r23;
    // sh          $fp, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r30;
    // sh          $s5, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r21;
    // sh          $s6, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r22;
    // sh          $s5, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r21;
    // sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // sb          $s1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r17;
    // sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // sb          $s1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r17;
    // sb          $s1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r17;
    // jal         0x800670D8
    // sb          $s1, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r17;
    KF_GetClut(rdram, ctx);
    goto after_9;
    // sb          $s1, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r17;
    after_9:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // ori         $a2, $zero, 0x3C0
    ctx->r6 = 0 | 0X3C0;
    // ori         $a3, $zero, 0x100
    ctx->r7 = 0 | 0X100;
    // jal         0x80067010
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    KF_GetTPage(rdram, ctx);
    goto after_10;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    after_10:
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // sb          $s2, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r18;
    // sb          $s2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r18;
    // sb          $s2, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r18;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x15C($a0)
    ctx->r4 = MEM_W(0X15C, ctx->r4);
    // jal         0x80067238
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_11;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_11:
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // nop

    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_800377F0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800377F0;
    }
    // nop

    // jal         0x800673A0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    GPU_Cmd_SetBaseParams(rdram, ctx);
    goto after_12;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800672EC
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    GPU_Cmd_SetBlendFlag(rdram, ctx);
    goto after_13;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_13:
    // ori         $a0, $zero, 0x240
    ctx->r4 = 0 | 0X240;
    // ori         $a1, $zero, 0x1FF
    ctx->r5 = 0 | 0X1FF;
    // sh          $fp, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r30;
    // sh          $s7, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r23;
    // sh          $s6, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r22;
    // sh          $s7, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r23;
    // sh          $fp, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r30;
    // sh          $s5, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r21;
    // sh          $s6, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r22;
    // sh          $s5, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r21;
    // sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // sb          $s1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r17;
    // sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // sb          $s1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r17;
    // sb          $s1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r17;
    // jal         0x800670D8
    // sb          $s1, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r17;
    KF_GetClut(rdram, ctx);
    goto after_14;
    // sb          $s1, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r17;
    after_14:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // ori         $a2, $zero, 0x3C0
    ctx->r6 = 0 | 0X3C0;
    // ori         $a3, $zero, 0x100
    ctx->r7 = 0 | 0X100;
    // jal         0x80067010
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    KF_GetTPage(rdram, ctx);
    goto after_15;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    after_15:
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // sb          $s2, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r18;
    // sb          $s2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r18;
    // sb          $s2, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r18;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $a0, 0x15C($a0)
    ctx->r4 = MEM_W(0X15C, ctx->r4);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80067238
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    GPU_Cmd_MergeParams(rdram, ctx);
    goto after_16;
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_16:
L_800377F0:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_17;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_17:
    // jal         0x8002FF0C
    // nop

    KF_RenderEnd(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(0X10, ctx->r29);
    // nop

    // addu        $s2, $s2, $t0
    ctx->r18 = ADD32(ctx->r18, ctx->r8);
    // addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // sltiu       $v0, $v0, 0x77
    ctx->r2 = ctx->r2 < 0X77 ? 1 : 0;
    // beq         $v0, $zero, L_80037860
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80037860;
    }
    // nop

    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_19;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_19:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(0X18, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $t0, $v0, L_80037848
    if (ctx->r8 != ctx->r2) {
        // nop
    
        goto L_80037848;
    }
    // nop

    // bne         $v1, $zero, L_800374A0
    if (ctx->r3 != 0) {
        // addiu       $t0, $zero, -0x2
        ctx->r8 = ADD32(0, -0X2);
        goto L_800374A0;
    }
    // addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // j           L_800374A0
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    goto L_800374A0;
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_80037848:
    // beq         $v1, $zero, L_800374A0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_800374A0;
    }
    // nop

    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_20;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_20:
    // j           L_8003786C
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    goto L_8003786C;
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80037860:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_21;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_21:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
L_8003786C:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(0X40, ctx->r29);
    // lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(0X3C, ctx->r29);
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
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
