#include "recomp.h"
#include "disable_warnings.h"

void DrawHUDNumberString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // lbu         $v1, 0x4($s2)
    ctx->r3 = MEM_BU(0X4, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80024274
    if (ctx->r3 == ctx->r2) {
        // addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
        goto L_80024274;
    }
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_80024010:
    // slti        $v0, $s4, 0x18
    ctx->r2 = SIGNED(ctx->r20) < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_80024274
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024274;
    }
    // nop

    // jal         0x8002492C
    // nop

    GPU_Cmd_SetupFlatGrayQuad(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // sh          $v0, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(0X8, ctx->r16);
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // sh          $v0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(0XA, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(0X8, ctx->r16);
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(0XA, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0xB
    ctx->r2 = ctx->r2 < 0XB ? 1 : 0;
    // beq         $v0, $zero, L_8002418C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002418C;
    }
    // nop

    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sb          $v0, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r2;
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
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sb          $v0, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r2;
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(0XA, ctx->r16);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // lbu         $v1, 0x8($s0)
    ctx->r3 = MEM_BU(0X8, ctx->r16);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r2;
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(0XA, ctx->r16);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80024254
    // sb          $v0, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r2;
    goto L_80024254;
    // sb          $v0, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r2;
L_8002418C:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addiu       $v1, $v1, -0xB
    ctx->r3 = ADD32(ctx->r3, -0XB);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sb          $v0, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // lbu         $v1, 0x8($s0)
    ctx->r3 = MEM_BU(0X8, ctx->r16);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r2;
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addiu       $v1, $v1, -0xB
    ctx->r3 = ADD32(ctx->r3, -0XB);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sb          $v0, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // lw          $v1, 0xF0($gp)
    ctx->r3 = MEM_W(0XF0, ctx->r28);
    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(0XA, ctx->r16);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r3;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // lbu         $v1, 0x8($s0)
    ctx->r3 = MEM_BU(0X8, ctx->r16);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(0XA, ctx->r16);
    // lw          $a0, 0xF0($gp)
    ctx->r4 = MEM_W(0XF0, ctx->r28);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r3;
L_80024254:
    // jal         0x80024974
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    GPU_Cmd_FinalizeAndAdvance(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    after_1:
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addiu       $s3, $s3, 0x7
    ctx->r19 = ADD32(ctx->r19, 0X7);
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80024010
    if (ctx->r3 != ctx->r2) {
        // addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_80024010;
    }
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80024274:
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
