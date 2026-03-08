#include "recomp.h"
#include "disable_warnings.h"

void DrawTexture(uint8_t* rdram, recomp_context* ctx) 
{
    printf("KF -> DrawTexture loading animation?\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addiu       $s0, $a0, -0x43
    ctx->r16 = ADD32(ctx->r4, -0X43);
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // ori         $s7, $zero, 0x3C
    ctx->r23 = 0 | 0X3C;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // ori         $s4, $zero, 0xC8
    ctx->r20 = 0 | 0XC8;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // addiu       $s2, $s2, -0x4A64
    ctx->r18 = ADD32(ctx->r18, -0X4A64);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // lui         $s1, 0xA00A
    ctx->r17 = S32(0XA00A << 16);
    // ori         $s1, $s1, 0xA1
    ctx->r17 = ctx->r17 | 0XA1;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // ori         $s6, $zero, 0xD4
    ctx->r22 = 0 | 0XD4;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // ori         $s5, $zero, 0xE3
    ctx->r21 = 0 | 0XE3;
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79DD($v0)
    ctx->r2 = MEM_BU(0X79DD, ctx->r2);
    // sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16) << 3;
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // addiu       $v0, $v0, 0x1E0
    ctx->r2 = ADD32(ctx->r2, 0X1E0);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // jal         0x80018418
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    ReadFromFile(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // jal         0x80017C18
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    AllocateMemory(rdram, ctx);
    goto after_1;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // jal         0x800188CC
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LoadTFile(rdram, ctx);
    goto after_2;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // jal         0x800373DC
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    ProcessTIMContainer(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_8001A4C4:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x8002492C
    // nop

    GPU_Cmd_SetupFlatGrayQuad(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $v1, $zero, 0x5F
    ctx->r3 = 0 | 0X5F;
    // sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // ori         $a1, $zero, 0x104
    ctx->r5 = 0 | 0X104;
    // sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // ori         $v0, $zero, 0x1F
    ctx->r2 = 0 | 0X1F;
    // sh          $v0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0x7FE4
    ctx->r2 = 0 | 0X7FE4;
    // sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
    // sh          $v0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0xDC
    ctx->r2 = 0 | 0XDC;
    // sh          $s7, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r23;
    // sh          $a1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r5;
    // sh          $s7, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r23;
    // sh          $v0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r2;
    // sh          $a1, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r5;
    // sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // sb          $zero, 0xD($a0)
    MEM_B(0XD, ctx->r4) = 0;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $s4, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r20;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $zero, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = 0;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $s4, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r20;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $s4, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r20;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // jal         0x80024974
    // sb          $s4, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r20;
    GPU_Cmd_FinalizeAndAdvance(rdram, ctx);
    goto after_6;
    // sb          $s4, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r20;
    after_6:
    // jal         0x8002492C
    // nop

    GPU_Cmd_SetupFlatGrayQuad(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $v1, $zero, 0x7F
    ctx->r3 = 0 | 0X7F;
    // sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // ori         $v0, $zero, 0x1C
    ctx->r2 = 0 | 0X1C;
    // sh          $v0, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r2;
    // ori         $v0, $zero, 0x7D25
    ctx->r2 = 0 | 0X7D25;
    // sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x34
    ctx->r2 = ADD32(ctx->r2, 0X34);
    // sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $v0, $s6, $v0
    ctx->r2 = SUB32(ctx->r22, ctx->r2);
    // sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x43
    ctx->r2 = ADD32(ctx->r2, 0X43);
    // sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $v0, $s6, $v0
    ctx->r2 = SUB32(ctx->r22, ctx->r2);
    // sh          $v0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r2;
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x34
    ctx->r2 = ADD32(ctx->r2, 0X34);
    // sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $v0, $s5, $v0
    ctx->r2 = SUB32(ctx->r21, ctx->r2);
    // sh          $v0, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r2;
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x43
    ctx->r2 = ADD32(ctx->r2, 0X43);
    // sh          $v0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r2;
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $v0, $s5, $v0
    ctx->r2 = SUB32(ctx->r21, ctx->r2);
    // sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x1A($s2)
    ctx->r2 = MEM_HU(0X1A, ctx->r18);
    // nop

    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sra         $v1, $v0, 9
    ctx->r3 = S32(ctx->r2) >> 9;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // bne         $v1, $v0, L_8001A734
    if (ctx->r3 != ctx->r2) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_8001A734;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8001A734:
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addiu       $a1, $v1, -0x80
    ctx->r5 = ADD32(ctx->r3, -0X80);
    // sb          $a1, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r5;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $a0, $zero, 0x90
    ctx->r4 = 0 | 0X90;
    // sb          $a0, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r4;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // addiu       $v1, $v1, -0x71
    ctx->r3 = ADD32(ctx->r3, -0X71);
    // sb          $v1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $a0, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r4;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $a1, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r5;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $a1, $zero, 0x9F
    ctx->r5 = 0 | 0X9F;
    // sb          $a1, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r5;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // nop

    // sb          $v1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r3;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
    // jal         0x80024974
    // sb          $a1, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r5;
    GPU_Cmd_FinalizeAndAdvance(rdram, ctx);
    goto after_8;
    // sb          $a1, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r5;
    after_8:
    // ori         $a0, $zero, 0x36
    ctx->r4 = 0 | 0X36;
    // ori         $a1, $zero, 0xE
    ctx->r5 = 0 | 0XE;
    // ori         $a2, $zero, 0xD4
    ctx->r6 = 0 | 0XD4;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // ori         $a3, $zero, 0xD4
    ctx->r7 = 0 | 0XD4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80024298
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    DrawTextureNPatch(rdram, ctx);
    goto after_9;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_9:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // slti        $v0, $s3, 0x2
    ctx->r2 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001A4C4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001A4C4;
    }
    // nop

    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_11;
    // nop

    after_11:
L_8001A7D4:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_12;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_12:
    // beq         $v0, $zero, L_8001A7D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001A7D4;
    }
    // nop

    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // jal         0x80017C40
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    KF_PadChkVsync(rdram, ctx);
    goto after_14;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_14:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
