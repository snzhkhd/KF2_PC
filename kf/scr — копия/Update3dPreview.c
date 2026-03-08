#include "recomp.h"
#include "disable_warnings.h"

void Update3dPreview(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A71($v0)
    ctx->r2 = MEM_BU(-0X4A71, ctx->r2);
    // addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // sw          $ra, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r31;
    // sw          $s1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r17;
    // beq         $v0, $zero, L_800234B4
    if (ctx->r2 == 0) {
        // sw          $s0, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->r16;
        goto L_800234B4;
    }
    // sw          $s0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r16;
    // andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_800234B4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800234B4;
    }
    // nop

    // lh          $v1, 0x106($gp)
    ctx->r3 = MEM_H(0X106, ctx->r28);
    // lh          $v0, 0x104($gp)
    ctx->r2 = MEM_H(0X104, ctx->r28);
    // lh          $a2, 0x108($gp)
    ctx->r6 = MEM_H(0X108, ctx->r28);
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // lhu         $v1, 0x10E($gp)
    ctx->r3 = MEM_HU(0X10E, ctx->r28);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x63CC
    ctx->r4 = ADD32(ctx->r4, 0X63CC);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x10C($gp)
    ctx->r2 = MEM_HU(0X10C, ctx->r28);
    // sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // lhu         $a2, 0x114($gp)
    ctx->r6 = MEM_HU(0X114, ctx->r28);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, 0x10C($gp)
    MEM_H(0X10C, ctx->r28) = ctx->r2;
    // lhu         $v0, 0x110($gp)
    ctx->r2 = MEM_HU(0X110, ctx->r28);
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // sh          $v1, 0x10E($gp)
    MEM_H(0X10E, ctx->r28) = ctx->r3;
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // sh          $v1, 0x10E($gp)
    MEM_H(0X10E, ctx->r28) = ctx->r3;
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, 0x110($gp)
    MEM_H(0X110, ctx->r28) = ctx->r2;
    // jal         0x8005F698
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    KF_RotMatrix(rdram, ctx);
    goto after_0;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // sh          $v0, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r2;
    // sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x800
    ctx->r2 = ADD32(0, -0X800);
    // ori         $s0, $zero, 0x1000
    ctx->r16 = 0 | 0X1000;
    // addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sh          $v0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r2;
    // sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // sh          $zero, 0x78($sp)
    MEM_H(0X78, ctx->r29) = 0;
    // sh          $v0, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r2;
    // sh          $s0, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r16;
    // sh          $zero, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = 0;
    // jal         0x800611CC
    // sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    sub_800611CC(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    after_1:
    // jal         0x8005E128
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    KF_SetLightMatrix(rdram, ctx);
    goto after_2;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // sh          $s0, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r16;
    // sh          $s0, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = ctx->r16;
    // sh          $s0, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r16;
    // sh          $s0, 0xB6($sp)
    MEM_H(0XB6, ctx->r29) = ctx->r16;
    // sh          $s0, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = ctx->r16;
    // sh          $s0, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = ctx->r16;
    // sh          $s0, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r16;
    // sh          $s0, 0xBE($sp)
    MEM_H(0XBE, ctx->r29) = ctx->r16;
    // jal         0x8005E158
    // sh          $s0, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r16;
    KF_SetColorMatrix(rdram, ctx);
    goto after_3;
    // sh          $s0, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r16;
    after_3:
    // jal         0x8005E0F8
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    KF_SetRotMatrix(rdram, ctx);
    goto after_4;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_4:
    // jal         0x8005E188
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    KF_SetTransMatrix(rdram, ctx);
    goto after_5;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
    // jal         0x80036428
    // nop

    sub_80036428(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(0X8, ctx->r2);
    // nop

    // sw          $v0, 0xF0($gp)
    MEM_W(0XF0, ctx->r28) = ctx->r2;
L_800234B4:
    // lw          $ra, 0xD8($sp)
    ctx->r31 = MEM_W(0XD8, ctx->r29);
    // lw          $s1, 0xD4($sp)
    ctx->r17 = MEM_W(0XD4, ctx->r29);
    // lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(0XD0, ctx->r29);
    // addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // jr          $ra
    // nop

    return;
    // nop

;}
