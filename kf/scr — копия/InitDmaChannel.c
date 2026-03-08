#include "recomp.h"
#include "disable_warnings.h"

void InitDmaChannel(uint8_t* rdram, recomp_context* ctx)
{
    ctx->r2 = 0;
    return;
    /*
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0;
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
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
    // lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // addiu       $s3, $s3, -0xAE4
    ctx->r19 = ADD32(ctx->r19, -0XAE4);
    // lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // addiu       $s2, $s2, -0x8AC
    ctx->r18 = ADD32(ctx->r18, -0X8AC);
    // addiu       $s4, $s2, 0x1
    ctx->r20 = ADD32(ctx->r18, 0X1);
    // addiu       $v0, $v0, 0x1E0
    ctx->r2 = ADD32(ctx->r2, 0X1E0);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64A8($at)
    MEM_W(0X64A8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x2F00
    ctx->r2 = ADD32(ctx->r2, 0X2F00);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x64AC($at)
    MEM_W(0X64AC, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64B0($at)
    MEM_W(0X64B0, ctx->r1) = ctx->r2;
L_8004D6F8:
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
    // bne         $v1, $zero, L_8004D740
    if (ctx->r3 != 0) {
        // nop

        goto L_8004D740;
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
    // beq         $v0, $zero, L_8004D7B8
    if (ctx->r2 == 0) {
        // nop

        goto L_8004D7B8;
    }
    // nop

L_8004D740:
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
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB67($v0)
    ctx->r2 = MEM_BU(-0XB67, ctx->r2);
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
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

    ps1_printf(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x8004E1E0
    // nop

    sub_8004E1E0(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_8004D7BC
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004D7BC;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004D7B8:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004D7BC:
    // bne         $v0, $zero, L_8004D8E4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004D8E4;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // jal         0x80061CA8
    // nop

    KF_CheckCallback(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // beq         $v0, $zero, L_8004D87C
    if (ctx->r2 == 0) {
        // nop

        goto L_8004D87C;
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
L_8004D7EC:
    // jal         0x8004D148
    // nop

    sub_8004D148(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8004D86C
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x4
        ctx->r2 = ctx->r16 & 0X4;
        goto L_8004D86C;
    }
    // andi        $v0, $s0, 0x4
    ctx->r2 = ctx->r16 & 0X4;
    // beq         $v0, $zero, L_8004D834
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x2
        ctx->r2 = ctx->r16 & 0X2;
        goto L_8004D834;
    }
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(-0XB84, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004D830
    if (ctx->r2 == 0) {
        // nop

        goto L_8004D830;
    }
    // nop

    // lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(0X0, ctx->r20);
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
L_8004D830:
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
L_8004D834:
    // beq         $v0, $zero, L_8004D7EC
    if (ctx->r2 == 0) {
        // nop

        goto L_8004D7EC;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB88($v0)
    ctx->r2 = MEM_W(-0XB88, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004D7EC
    if (ctx->r2 == 0) {
        // nop

        goto L_8004D7EC;
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
    // j           L_8004D7EC
    // nop

    goto L_8004D7EC;
    // nop

L_8004D86C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
L_8004D87C:
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // nop

    // andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $a2, $v0, L_8004D89C
    if (ctx->r6 == ctx->r2) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_8004D89C;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // bne         $a2, $v0, L_8004D8DC
    if (ctx->r6 != ctx->r2) {
        // nop

        goto L_8004D8DC;
    }
    // nop

L_8004D89C:
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x6490
    ctx->r4 = ADD32(ctx->r4, 0X6490);
    // beq         $a1, $zero, L_8004D8D4
    if (ctx->r5 == 0) {
        // ori         $v1, $zero, 0x7
        ctx->r3 = 0 | 0X7;
        goto L_8004D8D4;
    }
    // ori         $v1, $zero, 0x7
    ctx->r3 = 0 | 0X7;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8004D8BC:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $v1, $a3, L_8004D8BC
    if (ctx->r3 != ctx->r7) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8004D8BC;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8004D8D4:
    // j           L_8004D8E4
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    goto L_8004D8E4;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_8004D8DC:
    // beq         $s5, $zero, L_8004D6F8
    if (ctx->r21 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004D6F8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004D8E4:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop
    */
    ;
}
