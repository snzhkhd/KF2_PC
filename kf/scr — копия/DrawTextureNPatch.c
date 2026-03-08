#include "recomp.h"
#include "disable_warnings.h"

void DrawTextureNPatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // addiu       $a2, $a2, -0x5E
    ctx->r6 = ADD32(ctx->r6, -0X5E);
    // addiu       $a3, $a3, -0x5E
    ctx->r7 = ADD32(ctx->r7, -0X5E);
    // sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // ori         $s7, $zero, 0x9
    ctx->r23 = 0 | 0X9;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // addiu       $s0, $s0, 0x7B2C
    ctx->r16 = ADD32(ctx->r16, 0X7B2C);
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
L_800242EC:
    // lh          $fp, 0xA($s0)
    ctx->r30 = MEM_H(0XA, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $s6, $v0, L_80024314
    if (ctx->r22 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80024314;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(0X20, ctx->r29);
    // lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(0X64, ctx->r29);
    // addiu       $s4, $s4, 0x21
    ctx->r20 = ADD32(ctx->r20, 0X21);
    // addu        $v0, $t1, $t0
    ctx->r2 = ADD32(ctx->r9, ctx->r8);
    // j           L_80024328
    // addu        $fp, $fp, $v0
    ctx->r30 = ADD32(ctx->r30, ctx->r2);
    goto L_80024328;
    // addu        $fp, $fp, $v0
    ctx->r30 = ADD32(ctx->r30, ctx->r2);
L_80024314:
    // bne         $s6, $v0, L_80024328
    if (ctx->r22 != ctx->r2) {
        // addiu       $v0, $s4, 0x1C
        ctx->r2 = ADD32(ctx->r20, 0X1C);
        goto L_80024328;
    }
    // addiu       $v0, $s4, 0x1C
    ctx->r2 = ADD32(ctx->r20, 0X1C);
    // lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(0X20, ctx->r29);
    // nop

    // addu        $s4, $v0, $t1
    ctx->r20 = ADD32(ctx->r2, ctx->r9);
L_80024328:
    // lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(0X10, ctx->r29);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // sll         $v0, $s7, 1
    ctx->r2 = S32(ctx->r23) << 1;
    // addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // sll         $s5, $v0, 2
    ctx->r21 = S32(ctx->r2) << 2;
L_8002433C:
    // lh          $s1, 0x8($s0)
    ctx->r17 = MEM_H(0X8, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $s3, $v0, L_80024364
    if (ctx->r19 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80024364;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(0X18, ctx->r29);
    // lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(0X60, ctx->r29);
    // addiu       $s2, $s2, 0x21
    ctx->r18 = ADD32(ctx->r18, 0X21);
    // addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // j           L_80024378
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    goto L_80024378;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_80024364:
    // bne         $s3, $v0, L_80024378
    if (ctx->r19 != ctx->r2) {
        // addiu       $v0, $s2, 0x1C
        ctx->r2 = ADD32(ctx->r18, 0X1C);
        goto L_80024378;
    }
    // addiu       $v0, $s2, 0x1C
    ctx->r2 = ADD32(ctx->r18, 0X1C);
    // lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(0X18, ctx->r29);
    // nop

    // addu        $s2, $v0, $t0
    ctx->r18 = ADD32(ctx->r2, ctx->r8);
L_80024378:
    // jal         0x8002492C
    // addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    GPU_Cmd_SetupFlatGrayQuad(rdram, ctx);
    goto after_0;
    // addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    after_0:
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $t1, $zero, 0xFF
    ctx->r9 = 0 | 0XFF;
    // sb          $t1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r9;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $t0, $zero, 0xFF
    ctx->r8 = 0 | 0XFF;
    // sb          $t0, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r8;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $t1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r9;
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // jal         0x800672EC
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    GPU_Cmd_SetBlendFlag(rdram, ctx);
    goto after_1;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_1:
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // addu        $a0, $s2, $s1
    ctx->r4 = ADD32(ctx->r18, ctx->r17);
    // sh          $v0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r2;
    // lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(0X2, ctx->r16);
    // addu        $v0, $s4, $fp
    ctx->r2 = ADD32(ctx->r20, ctx->r30);
    // sh          $s2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r18;
    // sh          $s4, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r20;
    // sh          $a0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r4;
    // sh          $s4, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r20;
    // sh          $s2, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r18;
    // sh          $v0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r2;
    // sh          $a0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r4;
    // sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // sh          $a1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r5;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // lbu         $v1, 0x8($s0)
    ctx->r3 = MEM_BU(0X8, ctx->r16);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // sb          $v0, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // ori         $a0, $zero, 0x14
    ctx->r4 = 0 | 0X14;
    // sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(0XA, ctx->r16);
    // lw          $a1, 0xF0($gp)
    ctx->r5 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x1D($a1)
    MEM_B(0X1D, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // lbu         $v1, 0x8($s0)
    ctx->r3 = MEM_BU(0X8, ctx->r16);
    // lw          $a1, 0xF0($gp)
    ctx->r5 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x24($a1)
    MEM_B(0X24, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(0XA, ctx->r16);
    // lw          $a1, 0xF0($gp)
    ctx->r5 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80024974
    // sb          $v0, 0x25($a1)
    MEM_B(0X25, ctx->r5) = ctx->r2;
    GPU_Cmd_FinalizeAndAdvance(rdram, ctx);
    goto after_2;
    // sb          $v0, 0x25($a1)
    MEM_B(0X25, ctx->r5) = ctx->r2;
    after_2:
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // addiu       $v0, $v0, 0x7AC0
    ctx->r2 = ADD32(ctx->r2, 0X7AC0);
    // addu        $s0, $s5, $v0
    ctx->r16 = ADD32(ctx->r21, ctx->r2);
    // slti        $v0, $s3, 0x3
    ctx->r2 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8002433C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002433C;
    }
    // nop

    // addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // slti        $v0, $s6, 0x3
    ctx->r2 = SIGNED(ctx->r22) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_800242EC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800242EC;
    }
    // nop

    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(0X48, ctx->r29);
    // lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(0X44, ctx->r29);
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
