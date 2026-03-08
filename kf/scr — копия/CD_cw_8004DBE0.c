#include "..//kf_cd.h"
#include "disable_warnings.h"

void CD_cw_8004DBE0(uint8_t* rdram, recomp_context* ctx) 
{
	ctx->r2 = 1; // всегда успех
	uint8_t cmd = (uint8_t)ctx->r4;
	printf("[CD_cw_8004DBE0] cmd=0x%02X\n", cmd);
	/*

	KFCD_CdControl(rdram, ctx);*/

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0xB7C($v0)
//    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
//    // addiu       $sp, $sp, -0x50
//    ctx->r29 = ADD32(ctx->r29, -0X50);
//    // sw          $s5, 0x3C($sp)
//    MEM_W(0X3C, ctx->r29) = ctx->r21;
//    // addu        $s5, $a1, $zero
//    ctx->r21 = ADD32(ctx->r5, 0);
//    // sw          $s7, 0x44($sp)
//    MEM_W(0X44, ctx->r29) = ctx->r23;
//    // addu        $s7, $a2, $zero
//    ctx->r23 = ADD32(ctx->r6, 0);
//    // sw          $s0, 0x28($sp)
//    MEM_W(0X28, ctx->r29) = ctx->r16;
//    // addu        $s0, $a3, $zero
//    ctx->r16 = ADD32(ctx->r7, 0);
//    // sw          $s3, 0x34($sp)
//    MEM_W(0X34, ctx->r29) = ctx->r19;
//    // addu        $s3, $a0, $zero
//    ctx->r19 = ADD32(ctx->r4, 0);
//    // sw          $ra, 0x48($sp)
//    MEM_W(0X48, ctx->r29) = ctx->r31;
//    // sw          $s6, 0x40($sp)
//    MEM_W(0X40, ctx->r29) = ctx->r22;
//    // sw          $s4, 0x38($sp)
//    MEM_W(0X38, ctx->r29) = ctx->r20;
//    // sw          $s2, 0x30($sp)
//    MEM_W(0X30, ctx->r29) = ctx->r18;
//    // slti        $v0, $v0, 0x2
//    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
//    // bne         $v0, $zero, L_8004DC50
//    if (ctx->r2 != 0) {
//        // sw          $s1, 0x2C($sp)
//        MEM_W(0X2C, ctx->r29) = ctx->r17;
//        goto L_8004DC50;
//    }
//    // sw          $s1, 0x2C($sp)
//    MEM_W(0X2C, ctx->r29) = ctx->r17;
//    // andi        $v0, $s3, 0xFF
//    ctx->r2 = ctx->r19 & 0XFF;
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // addiu       $at, $at, -0xB64
//    ctx->r1 = ADD32(ctx->r1, -0XB64);
//    // addu        $at, $at, $v0
//    ctx->r1 = ADD32(ctx->r1, ctx->r2);
//    // lw          $a1, 0x0($at)
//    ctx->r5 = MEM_W(0X0, ctx->r1);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x2F14
//    ctx->r4 = ADD32(ctx->r4, 0X2F14);
//    // jal         0x80062BA0
//    // nop
//
//    psx_printf(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//L_8004DC50:
//    // andi        $v0, $s3, 0xFF
//    ctx->r2 = ctx->r19 & 0XFF;
//    // sll         $v1, $v0, 2
//    ctx->r3 = S32(ctx->r2) << 2;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // addiu       $at, $at, -0x944
//    ctx->r1 = ADD32(ctx->r1, -0X944);
//    // addu        $at, $at, $v1
//    ctx->r1 = ADD32(ctx->r1, ctx->r3);
//    // lw          $v0, 0x0($at)
//    ctx->r2 = MEM_W(0X0, ctx->r1);
//    // nop
//
//    // beq         $v0, $zero, L_8004DCB8
//    if (ctx->r2 == 0) {
//        // addu        $a0, $zero, $zero
//        ctx->r4 = ADD32(0, 0);
//        goto L_8004DCB8;
//    }
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // bne         $s5, $zero, L_8004DCB8
//    if (ctx->r21 != 0) {
//        // nop
//    
//        goto L_8004DCB8;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0xB7C($v0)
//    ctx->r2 = MEM_W(-0XB7C, ctx->r2);
//    // nop
//
//    // blez        $v0, L_8004E018
//    if (SIGNED(ctx->r2) <= 0) {
//        // addiu       $v0, $zero, -0x2
//        ctx->r2 = ADD32(0, -0X2);
//        goto L_8004E018;
//    }
//    // addiu       $v0, $zero, -0x2
//    ctx->r2 = ADD32(0, -0X2);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // addiu       $at, $at, -0xB64
//    ctx->r1 = ADD32(ctx->r1, -0XB64);
//    // addu        $at, $at, $v1
//    ctx->r1 = ADD32(ctx->r1, ctx->r3);
//    // lw          $a1, 0x0($at)
//    ctx->r5 = MEM_W(0X0, ctx->r1);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x2F1C
//    ctx->r4 = ADD32(ctx->r4, 0X2F1C);
//    // jal         0x80062BA0
//    // nop
//
//    psx_printf(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // j           L_8004E018
//    // addiu       $v0, $zero, -0x2
//    ctx->r2 = ADD32(0, -0X2);
//    goto L_8004E018;
//    // addiu       $v0, $zero, -0x2
//    ctx->r2 = ADD32(0, -0X2);
//L_8004DCB8:
//    // jal         0x8004D68C
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    InitDmaChannel(rdram, ctx);
//    goto after_2;
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    after_2:
//    // andi        $v1, $s3, 0xFF
//    ctx->r3 = ctx->r19 & 0XFF;
//    // ori         $v0, $zero, 0x2
//    ctx->r2 = 0 | 0X2;
//    // bne         $v1, $v0, L_8004DCFC
//    if (ctx->r3 != ctx->r2) {
//        // addu        $a0, $zero, $zero
//        ctx->r4 = ADD32(0, 0);
//        goto L_8004DCFC;
//    }
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // addu        $v1, $s5, $zero
//    ctx->r3 = ADD32(ctx->r21, 0);
//L_8004DCD4:
//    // lbu         $v0, 0x0($v1)
//    ctx->r2 = MEM_BU(0X0, ctx->r3);
//    // nop
//
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // addiu       $at, $at, -0xB6C
//    ctx->r1 = ADD32(ctx->r1, -0XB6C);
//    // addu        $at, $at, $a0
//    ctx->r1 = ADD32(ctx->r1, ctx->r4);
//    // sb          $v0, 0x0($at)
//    MEM_B(0X0, ctx->r1) = ctx->r2;
//    // addiu       $a0, $a0, 0x1
//    ctx->r4 = ADD32(ctx->r4, 0X1);
//    // slti        $v0, $a0, 0x4
//    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
//    // bne         $v0, $zero, L_8004DCD4
//    if (ctx->r2 != 0) {
//        // addiu       $v1, $v1, 0x1
//        ctx->r3 = ADD32(ctx->r3, 0X1);
//        goto L_8004DCD4;
//    }
//    // addiu       $v1, $v1, 0x1
//    ctx->r3 = ADD32(ctx->r3, 0X1);
//L_8004DCFC:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // addiu       $v0, $v0, -0x8AC
//    ctx->r2 = ADD32(ctx->r2, -0X8AC);
//    // sb          $zero, 0x0($v0)
//    MEM_B(0X0, ctx->r2) = 0;
//    // andi        $v0, $s3, 0xFF
//    ctx->r2 = ctx->r19 & 0XFF;
//    // sll         $a0, $v0, 2
//    ctx->r4 = S32(ctx->r2) << 2;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // addiu       $at, $at, -0xA44
//    ctx->r1 = ADD32(ctx->r1, -0XA44);
//    // addu        $at, $at, $a0
//    ctx->r1 = ADD32(ctx->r1, ctx->r4);
//    // lw          $v0, 0x0($at)
//    ctx->r2 = MEM_W(0X0, ctx->r1);
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // addiu       $v1, $v1, -0xA44
//    ctx->r3 = ADD32(ctx->r3, -0XA44);
//    // beq         $v0, $zero, L_8004DD38
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8004DD38;
//    }
//    // nop
//
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sb          $zero, -0x8AB($at)
//    MEM_B(-0X8AB, ctx->r1) = 0;
//L_8004DD38:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x8C4($v0)
//    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
//    // nop
//
//    // sb          $zero, 0x0($v0)
//    MEM_B(0X0, ctx->r2) = 0;
//    // addiu       $v0, $v1, 0x100
//    ctx->r2 = ADD32(ctx->r3, 0X100);
//    // addu        $v1, $a0, $v0
//    ctx->r3 = ADD32(ctx->r4, ctx->r2);
//    // lw          $v0, 0x0($v1)
//    ctx->r2 = MEM_W(0X0, ctx->r3);
//    // nop
//
//    // blez        $v0, L_8004DD90
//    if (SIGNED(ctx->r2) <= 0) {
//        // addu        $a0, $zero, $zero
//        ctx->r4 = ADD32(0, 0);
//        goto L_8004DD90;
//    }
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // addu        $a2, $v1, $zero
//    ctx->r6 = ADD32(ctx->r3, 0);
//    // addu        $a1, $s5, $zero
//    ctx->r5 = ADD32(ctx->r21, 0);
//L_8004DD68:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x8BC($v1)
//    ctx->r3 = MEM_W(-0X8BC, ctx->r3);
//    // lbu         $v0, 0x0($a1)
//    ctx->r2 = MEM_BU(0X0, ctx->r5);
//    // addiu       $a1, $a1, 0x1
//    ctx->r5 = ADD32(ctx->r5, 0X1);
//    // sb          $v0, 0x0($v1)
//    MEM_B(0X0, ctx->r3) = ctx->r2;
//    // lw          $v0, 0x0($a2)
//    ctx->r2 = MEM_W(0X0, ctx->r6);
//    // addiu       $a0, $a0, 0x1
//    ctx->r4 = ADD32(ctx->r4, 0X1);
//    // slt         $v0, $a0, $v0
//    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
//    // bne         $v0, $zero, L_8004DD68
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8004DD68;
//    }
//    // nop
//
//L_8004DD90:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x8C0($v0)
//    ctx->r2 = MEM_W(-0X8C0, ctx->r2);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sb          $s3, -0xB67($at)
//    MEM_B(-0XB67, ctx->r1) = ctx->r19;
//    // sb          $s3, 0x0($v0)
//    MEM_B(0X0, ctx->r2) = ctx->r19;
//    // bne         $s0, $zero, L_8004E018
//    if (ctx->r16 != 0) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_8004E018;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // jal         0x8006263C
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//    KF_VSync(rdram, ctx);
//    goto after_3;
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//    after_3:
//    // addiu       $v0, $v0, 0x1E0
//    ctx->r2 = ADD32(ctx->r2, 0X1E0);
//    // lui         $a0, 0x8007
//    ctx->r4 = S32(0X8007 << 16);
//    // addiu       $a0, $a0, -0x8AC
//    ctx->r4 = ADD32(ctx->r4, -0X8AC);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, 0x64A8($at)
//    MEM_W(0X64A8, ctx->r1) = ctx->r2;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $zero, 0x64AC($at)
//    MEM_W(0X64AC, ctx->r1) = 0;
//    // lbu         $v1, 0x0($a0)
//    ctx->r3 = MEM_BU(0X0, ctx->r4);
//    // lui         $v0, 0x8001
//    ctx->r2 = S32(0X8001 << 16);
//    // addiu       $v0, $v0, 0x2F2C
//    ctx->r2 = ADD32(ctx->r2, 0X2F2C);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, 0x64B0($at)
//    MEM_W(0X64B0, ctx->r1) = ctx->r2;
//    // bne         $v1, $zero, L_8004DF90
//    if (ctx->r3 != 0) {
//        // nop
//    
//        goto L_8004DF90;
//    }
//    // nop
//
//    // lui         $s4, 0x8007
//    ctx->r20 = S32(0X8007 << 16);
//    // addiu       $s4, $s4, -0xAE4
//    ctx->r20 = ADD32(ctx->r20, -0XAE4);
//    // addu        $s2, $a0, $zero
//    ctx->r18 = ADD32(ctx->r4, 0);
//    // addiu       $s6, $a0, 0x1
//    ctx->r22 = ADD32(ctx->r4, 0X1);
//L_8004DDFC:
//    // jal         0x8006263C
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//    KF_VSync(rdram, ctx);
//    goto after_4;
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//    after_4:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x64A8($v1)
//    ctx->r3 = MEM_W(0X64A8, ctx->r3);
//    // nop
//
//    // slt         $v1, $v1, $v0
//    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
//    // bne         $v1, $zero, L_8004DE44
//    if (ctx->r3 != 0) {
//        // nop
//    
//        goto L_8004DE44;
//    }
//    // nop
//
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x64AC($v1)
//    ctx->r3 = MEM_W(0X64AC, ctx->r3);
//    // nop
//
//    // addiu       $v0, $v1, 0x1
//    ctx->r2 = ADD32(ctx->r3, 0X1);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, 0x64AC($at)
//    MEM_W(0X64AC, ctx->r1) = ctx->r2;
//    // lui         $v0, 0x1E
//    ctx->r2 = S32(0X1E << 16);
//    // slt         $v0, $v0, $v1
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
//    // beq         $v0, $zero, L_8004DEBC
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8004DEBC;
//    }
//    // nop
//
//L_8004DE44:
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x2E78
//    ctx->r4 = ADD32(ctx->r4, 0X2E78);
//    // jal         0x80062C20
//    // nop
//
//    sub_80062C20(rdram, ctx);
//    goto after_5;
//    // nop
//
//    after_5:
//    // lbu         $a0, 0x0($s2)
//    ctx->r4 = MEM_BU(0X0, ctx->r18);
//    // lbu         $v0, 0x1($s2)
//    ctx->r2 = MEM_BU(0X1, ctx->r18);
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // lw          $a1, 0x64B0($a1)
//    ctx->r5 = MEM_W(0X64B0, ctx->r5);
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // addu        $v0, $v0, $s4
//    ctx->r2 = ADD32(ctx->r2, ctx->r20);
//    // sll         $a0, $a0, 2
//    ctx->r4 = S32(ctx->r4) << 2;
//    // lw          $v1, 0x0($v0)
//    ctx->r3 = MEM_W(0X0, ctx->r2);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lbu         $v0, -0xB67($v0)
//    ctx->r2 = MEM_BU(-0XB67, ctx->r2);
//    // addu        $a0, $a0, $s4
//    ctx->r4 = ADD32(ctx->r4, ctx->r20);
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // sw          $v1, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r3;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // addiu       $at, $at, -0xB64
//    ctx->r1 = ADD32(ctx->r1, -0XB64);
//    // addu        $at, $at, $v0
//    ctx->r1 = ADD32(ctx->r1, ctx->r2);
//    // lw          $a2, 0x0($at)
//    ctx->r6 = MEM_W(0X0, ctx->r1);
//    // lw          $a3, 0x0($a0)
//    ctx->r7 = MEM_W(0X0, ctx->r4);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x2E88
//    ctx->r4 = ADD32(ctx->r4, 0X2E88);
//    // jal         0x80062BA0
//    // nop
//
//    psx_printf(rdram, ctx);
//    goto after_6;
//    // nop
//
//    after_6:
//    // jal         0x8004E1E0
//    // nop
//
//    sub_8004E1E0(rdram, ctx);
//    goto after_7;
//    // nop
//
//    after_7:
//    // j           L_8004DEC0
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    goto L_8004DEC0;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//L_8004DEBC:
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_8004DEC0:
//    // bne         $v0, $zero, L_8004E018
//    if (ctx->r2 != 0) {
//        // addiu       $v0, $zero, -0x1
//        ctx->r2 = ADD32(0, -0X1);
//        goto L_8004E018;
//    }
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // jal         0x80061CA8
//    // nop
//
//    KF_CheckCallback(rdram, ctx);
//    goto after_8;
//    // nop
//
//    after_8:
//    // beq         $v0, $zero, L_8004DF80
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8004DF80;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x8C4($v0)
//    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
//    // nop
//
//    // lbu         $v0, 0x0($v0)
//    ctx->r2 = MEM_BU(0X0, ctx->r2);
//    // nop
//
//    // andi        $s1, $v0, 0x3
//    ctx->r17 = ctx->r2 & 0X3;
//L_8004DEF0:
//    // jal         0x8004D148
//    // nop
//
//    sub_8004D148(rdram, ctx);
//    goto after_9;
//    // nop
//
//    after_9:
//    // addu        $s0, $v0, $zero
//    ctx->r16 = ADD32(ctx->r2, 0);
//    // beq         $s0, $zero, L_8004DF70
//    if (ctx->r16 == 0) {
//        // andi        $v0, $s0, 0x4
//        ctx->r2 = ctx->r16 & 0X4;
//        goto L_8004DF70;
//    }
//    // andi        $v0, $s0, 0x4
//    ctx->r2 = ctx->r16 & 0X4;
//    // beq         $v0, $zero, L_8004DF38
//    if (ctx->r2 == 0) {
//        // andi        $v0, $s0, 0x2
//        ctx->r2 = ctx->r16 & 0X2;
//        goto L_8004DF38;
//    }
//    // andi        $v0, $s0, 0x2
//    ctx->r2 = ctx->r16 & 0X2;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0xB84($v0)
//    ctx->r2 = MEM_W(-0XB84, ctx->r2);
//    // nop
//
//    // beq         $v0, $zero, L_8004DF34
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8004DF34;
//    }
//    // nop
//
//    // lbu         $a0, 0x0($s6)
//    ctx->r4 = MEM_BU(0X0, ctx->r22);
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // addiu       $a1, $a1, 0x6498
//    ctx->r5 = ADD32(ctx->r5, 0X6498);
//    // jalr        $v0
//    // nop
//
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_10;
//    // nop
//
//    after_10:
//L_8004DF34:
//    // andi        $v0, $s0, 0x2
//    ctx->r2 = ctx->r16 & 0X2;
//L_8004DF38:
//    // beq         $v0, $zero, L_8004DEF0
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8004DEF0;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0xB88($v0)
//    ctx->r2 = MEM_W(-0XB88, ctx->r2);
//    // nop
//
//    // beq         $v0, $zero, L_8004DEF0
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8004DEF0;
//    }
//    // nop
//
//    // lbu         $a0, 0x0($s2)
//    ctx->r4 = MEM_BU(0X0, ctx->r18);
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // addiu       $a1, $a1, 0x6490
//    ctx->r5 = ADD32(ctx->r5, 0X6490);
//    // jalr        $v0
//    // nop
//
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_11;
//    // nop
//
//    after_11:
//    // j           L_8004DEF0
//    // nop
//
//    goto L_8004DEF0;
//    // nop
//
//L_8004DF70:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x8C4($v0)
//    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
//    // nop
//
//    // sb          $s1, 0x0($v0)
//    MEM_B(0X0, ctx->r2) = ctx->r17;
//L_8004DF80:
//    // lbu         $v0, 0x0($s2)
//    ctx->r2 = MEM_BU(0X0, ctx->r18);
//    // nop
//
//    // beq         $v0, $zero, L_8004DDFC
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8004DDFC;
//    }
//    // nop
//
//L_8004DF90:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // addiu       $v0, $v0, -0x8AC
//    ctx->r2 = ADD32(ctx->r2, -0X8AC);
//    // lbu         $v0, 0x0($v0)
//    ctx->r2 = MEM_BU(0X0, ctx->r2);
//    // ori         $v1, $zero, 0x2
//    ctx->r3 = 0 | 0X2;
//    // andi        $v0, $v0, 0xFF
//    ctx->r2 = ctx->r2 & 0XFF;
//    // bne         $v0, $v1, L_8004DFCC
//    if (ctx->r2 != ctx->r3) {
//        // addu        $a2, $s7, $zero
//        ctx->r6 = ADD32(ctx->r23, 0);
//        goto L_8004DFCC;
//    }
//    // addu        $a2, $s7, $zero
//    ctx->r6 = ADD32(ctx->r23, 0);
//    // andi        $v1, $s3, 0xFF
//    ctx->r3 = ctx->r19 & 0XFF;
//    // ori         $v0, $zero, 0xE
//    ctx->r2 = 0 | 0XE;
//    // bne         $v1, $v0, L_8004DFCC
//    if (ctx->r3 != ctx->r2) {
//        // nop
//    
//        goto L_8004DFCC;
//    }
//    // nop
//
//    // lbu         $v0, 0x0($s5)
//    ctx->r2 = MEM_BU(0X0, ctx->r21);
//    // nop
//
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sb          $v0, -0xB68($at)
//    MEM_B(-0XB68, ctx->r1) = ctx->r2;
//L_8004DFCC:
//    // lui         $a0, 0x8007
//    ctx->r4 = S32(0X8007 << 16);
//    // addiu       $a0, $a0, 0x6490
//    ctx->r4 = ADD32(ctx->r4, 0X6490);
//    // beq         $a2, $zero, L_8004DFFC
//    if (ctx->r6 == 0) {
//        // nop
//    
//        goto L_8004DFFC;
//    }
//    // nop
//
//    // ori         $v1, $zero, 0x7
//    ctx->r3 = 0 | 0X7;
//    // addiu       $a1, $zero, -0x1
//    ctx->r5 = ADD32(0, -0X1);
//L_8004DFE4:
//    // lbu         $v0, 0x0($a0)
//    ctx->r2 = MEM_BU(0X0, ctx->r4);
//    // addiu       $a0, $a0, 0x1
//    ctx->r4 = ADD32(ctx->r4, 0X1);
//    // addiu       $v1, $v1, -0x1
//    ctx->r3 = ADD32(ctx->r3, -0X1);
//    // sb          $v0, 0x0($a2)
//    MEM_B(0X0, ctx->r6) = ctx->r2;
//    // bne         $v1, $a1, L_8004DFE4
//    if (ctx->r3 != ctx->r5) {
//        // addiu       $a2, $a2, 0x1
//        ctx->r6 = ADD32(ctx->r6, 0X1);
//        goto L_8004DFE4;
//    }
//    // addiu       $a2, $a2, 0x1
//    ctx->r6 = ADD32(ctx->r6, 0X1);
//L_8004DFFC:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // addiu       $v0, $v0, -0x8AC
//    ctx->r2 = ADD32(ctx->r2, -0X8AC);
//    // lbu         $v0, 0x0($v0)
//    ctx->r2 = MEM_BU(0X0, ctx->r2);
//    // nop
//
//    // xori        $v0, $v0, 0x5
//    ctx->r2 = ctx->r2 ^ 0X5;
//    // sltiu       $v0, $v0, 0x1
//    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
//    // negu        $v0, $v0
//    ctx->r2 = SUB32(0, ctx->r2);
//L_8004E018:
//    // lw          $ra, 0x48($sp)
//    ctx->r31 = MEM_W(0X48, ctx->r29);
//    // lw          $s7, 0x44($sp)
//    ctx->r23 = MEM_W(0X44, ctx->r29);
//    // lw          $s6, 0x40($sp)
//    ctx->r22 = MEM_W(0X40, ctx->r29);
//    // lw          $s5, 0x3C($sp)
//    ctx->r21 = MEM_W(0X3C, ctx->r29);
//    // lw          $s4, 0x38($sp)
//    ctx->r20 = MEM_W(0X38, ctx->r29);
//    // lw          $s3, 0x34($sp)
//    ctx->r19 = MEM_W(0X34, ctx->r29);
//    // lw          $s2, 0x30($sp)
//    ctx->r18 = MEM_W(0X30, ctx->r29);
//    // lw          $s1, 0x2C($sp)
//    ctx->r17 = MEM_W(0X2C, ctx->r29);
//    // lw          $s0, 0x28($sp)
//    ctx->r16 = MEM_W(0X28, ctx->r29);
//    // addiu       $sp, $sp, 0x50
//    ctx->r29 = ADD32(ctx->r29, 0X50);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
