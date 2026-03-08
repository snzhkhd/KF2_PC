#include "recomp.h"
#include "disable_warnings.h"

void sub_8004D910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x8006263C
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    KF_VSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // addiu       $s5, $s5, -0xAE4
    ctx->r21 = ADD32(ctx->r21, -0XAE4);
    // lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // addiu       $s2, $s2, -0x8AC
    ctx->r18 = ADD32(ctx->r18, -0X8AC);
    // addiu       $s6, $s2, 0x1
    ctx->r22 = ADD32(ctx->r18, 0X1);
    // addiu       $s3, $s2, 0x2
    ctx->r19 = ADD32(ctx->r18, 0X2);
    // addiu       $v0, $v0, 0x1E0
    ctx->r2 = ADD32(ctx->r2, 0X1E0);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64A8($at)
    MEM_W(0X64A8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x2F08
    ctx->r2 = ADD32(ctx->r2, 0X2F08);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x64AC($at)
    MEM_W(0X64AC, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64B0($at)
    MEM_W(0X64B0, ctx->r1) = ctx->r2;
L_8004D984:
    // jal         0x8006263C
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    KF_VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x64A8($v1)
    ctx->r3 = MEM_W(0X64A8, ctx->r3);
    // nop

    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8004D9CC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8004D9CC;
    }
    // nop

    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x64AC($v1)
    ctx->r3 = MEM_W(0X64AC, ctx->r3);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64AC($at)
    MEM_W(0X64AC, ctx->r1) = ctx->r2;
    // lui         $v0, 0x1E
    ctx->r2 = S32(0X1E << 16);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8004DA44
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DA44;
    }
    // nop

L_8004D9CC:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2E78
    ctx->r4 = ADD32(ctx->r4, 0X2E78);
    // jal         0x80062C20
    // nop

    sub_80062C20(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(0X1, ctx->r18);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x64B0($a1)
    ctx->r5 = MEM_W(0X64B0, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB67($v0)
    ctx->r2 = MEM_BU(-0XB67, ctx->r2);
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0xB64
    ctx->r1 = ADD32(ctx->r1, -0XB64);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $a2, 0x0($at)
    ctx->r6 = MEM_W(0X0, ctx->r1);
    // lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(0X0, ctx->r4);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2E88
    ctx->r4 = ADD32(ctx->r4, 0X2E88);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x8004E1E0
    // nop

    sub_8004E1E0(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_8004DA48
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004DA48;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004DA44:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004DA48:
    // bne         $v0, $zero, L_8004DBB0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004DBB0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // jal         0x80061CA8
    // nop

    KF_CheckCallback(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // beq         $v0, $zero, L_8004DB08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DB08;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $s1, $v0, 0x3
    ctx->r17 = ctx->r2 & 0X3;
L_8004DA78:
    // jal         0x8004D148
    // nop

    sub_8004D148(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8004DAF8
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x4
        ctx->r2 = ctx->r16 & 0X4;
        goto L_8004DAF8;
    }
    // andi        $v0, $s0, 0x4
    ctx->r2 = ctx->r16 & 0X4;
    // beq         $v0, $zero, L_8004DAC0
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x2
        ctx->r2 = ctx->r16 & 0X2;
        goto L_8004DAC0;
    }
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(-0XB84, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004DABC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DABC;
    }
    // nop

    // lbu         $a0, 0x0($s6)
    ctx->r4 = MEM_BU(0X0, ctx->r22);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x6498
    ctx->r5 = ADD32(ctx->r5, 0X6498);
    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_7;
    // nop

    after_7:
L_8004DABC:
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
L_8004DAC0:
    // beq         $v0, $zero, L_8004DA78
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DA78;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB88($v0)
    ctx->r2 = MEM_W(-0XB88, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004DA78
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DA78;
    }
    // nop

    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x6490
    ctx->r5 = ADD32(ctx->r5, 0X6490);
    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // j           L_8004DA78
    // nop

    goto L_8004DA78;
    // nop

L_8004DAF8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
L_8004DB08:
    // lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(0X0, ctx->r19);
    // nop

    // andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // beq         $a2, $zero, L_8004DB58
    if (ctx->r6 == 0) {
        // nop
    
        goto L_8004DB58;
    }
    // nop

    // sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x64A0
    ctx->r4 = ADD32(ctx->r4, 0X64A0);
    // beq         $s4, $zero, L_8004DBA0
    if (ctx->r20 == 0) {
        // addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
        goto L_8004DBA0;
    }
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // ori         $v1, $zero, 0x7
    ctx->r3 = 0 | 0X7;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8004DB38:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $v1, $a3, L_8004DB38
    if (ctx->r3 != ctx->r7) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8004DB38;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // j           L_8004DBB0
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    goto L_8004DBB0;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_8004DB58:
    // lbu         $v0, -0x1($s3)
    ctx->r2 = MEM_BU(-0X1, ctx->r19);
    // nop

    // andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // beq         $a2, $zero, L_8004DBA8
    if (ctx->r6 == 0) {
        // nop
    
        goto L_8004DBA8;
    }
    // nop

    // sb          $zero, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = 0;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x6498
    ctx->r4 = ADD32(ctx->r4, 0X6498);
    // beq         $a1, $zero, L_8004DBA0
    if (ctx->r5 == 0) {
        // ori         $v1, $zero, 0x7
        ctx->r3 = 0 | 0X7;
        goto L_8004DBA0;
    }
    // ori         $v1, $zero, 0x7
    ctx->r3 = 0 | 0X7;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8004DB88:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $v1, $a3, L_8004DB88
    if (ctx->r3 != ctx->r7) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8004DB88;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8004DBA0:
    // j           L_8004DBB0
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    goto L_8004DBB0;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_8004DBA8:
    // beq         $s7, $zero, L_8004D984
    if (ctx->r23 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004D984;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004DBB0:
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
