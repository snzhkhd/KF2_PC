#include "recomp.h"
#include "disable_warnings.h"

void ui_DrawText(uint8_t* rdram, recomp_context* ctx) 
{
    //printf("[ui_DrawText] CALLED, writing to gp+240=0x%08X\n",
    //    MEM_W(0xF0, ctx->r28));

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $s1, 0x4
    ctx->r19 = ADD32(ctx->r17, 0X4);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(0X4, ctx->r17);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80023FB0
    if (ctx->r3 == ctx->r2) {
        // addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
        goto L_80023FB0;
    }
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // slti        $v0, $s4, 0x18
    ctx->r2 = SIGNED(ctx->r20) < 0X18 ? 1 : 0;
L_80023E60:
    // beq         $v0, $zero, L_80023FB0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80023FB0;
    }
    // nop

    // jal         0x8002492C
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    GPU_Cmd_SetupFlatGrayQuad(rdram, ctx);
    goto after_0;
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    after_0:
    // lw          $a1, 0xF0($gp)
    ctx->r5 = MEM_W(0XF0, ctx->r28);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // sh          $v0, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(0X8, ctx->r16);
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(0XA, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(0X8, ctx->r16);
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(0XA, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(0X0, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // andi        $a0, $v0, 0xF
    ctx->r4 = ctx->r2 & 0XF;
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // sb          $a0, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r4;
    // sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2) << 4;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sb          $a1, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r5;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sb          $v0, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r2;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // addiu       $s2, $s2, 0x7
    ctx->r18 = ADD32(ctx->r18, 0X7);
    // sb          $a1, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r5;
    // lw          $v0, 0xF0($gp)
    ctx->r2 = MEM_W(0XF0, ctx->r28);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // sb          $a0, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r4;
    // lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(0XA, ctx->r16);
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // sb          $v0, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sb          $a0, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r4;
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(0XA, ctx->r16);
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x80024974
    // sb          $a1, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r5;
    GPU_Cmd_FinalizeAndAdvance(rdram, ctx);
    goto after_1;
    // sb          $a1, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r5;
    after_1:
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80023E60
    if (ctx->r3 != ctx->r2) {
        // slti        $v0, $s4, 0x18
        ctx->r2 = SIGNED(ctx->r20) < 0X18 ? 1 : 0;
        goto L_80023E60;
    }
    // slti        $v0, $s4, 0x18
    ctx->r2 = SIGNED(ctx->r20) < 0X18 ? 1 : 0;
L_80023FB0:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
