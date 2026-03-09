#include "recomp.h"
#include "disable_warnings.h"

void SPU_PlayVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(0X4C, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // lhu         $s7, 0x48($sp)
    ctx->r23 = MEM_HU(0X48, ctx->r29);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2570($v0)
    ctx->r2 = MEM_W(-0X2570, ctx->r2);
    // addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // bne         $v0, $v1, L_80058700
    if (ctx->r2 != ctx->r3) {
        // addu        $s4, $s0, $zero
        ctx->r20 = ADD32(ctx->r16, 0);
        goto L_80058700;
    }
    // addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    // j           L_80058A60
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80058A60;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058700:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v1, -0x2570($at)
    MEM_W(-0X2570, ctx->r1) = ctx->r3;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x8005984C
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005984C(rdram, ctx);
    goto after_0;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_0:
    // bne         $v0, $zero, L_80058930
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x21
        ctx->r2 = 0 | 0X21;
        goto L_80058930;
    }
    // ori         $v0, $zero, 0x21
    ctx->r2 = 0 | 0X21;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x191A($at)
    MEM_H(-0X191A, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $s5, -0x192E($at)
    MEM_B(-0X192E, ctx->r1) = ctx->r21;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $s7, -0x192D($at)
    MEM_B(-0X192D, ctx->r1) = ctx->r23;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $s3, -0x1924($at)
    MEM_B(-0X1924, ctx->r1) = ctx->r19;
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bne         $a0, $v1, L_80058778
    if (ctx->r4 != ctx->r3) {
        // slt         $v0, $v1, $a0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
        goto L_80058778;
    }
    // slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x192B($at)
    MEM_B(-0X192B, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $s2, -0x192C($at)
    MEM_B(-0X192C, ctx->r1) = ctx->r18;
    // j           L_8005880C
    // nop

    goto L_8005880C;
    // nop

L_80058778:
    // beq         $v0, $zero, L_800587C4
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 6
        ctx->r2 = S32(ctx->r3) << 6;
        goto L_800587C4;
    }
    // sll         $v0, $v1, 6
    ctx->r2 = S32(ctx->r3) << 6;
    // div         $zero, $v0, $a0
	if (ctx->r4 != 0)
    {
		lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
	}
	else { lo = 0; hi = 0; }
    // bne         $a0, $zero, L_80058790
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80058790;
    }
    // nop

    // break       7
    do_break(2147846028);
L_80058790:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_800587A8
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800587A8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_800587A8
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_800587A8;
    }
    // nop

    // break       6
    do_break(2147846052);
L_800587A8:
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $s2, -0x192C($at)
    MEM_B(-0X192C, ctx->r1) = ctx->r18;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x192B($at)
    MEM_B(-0X192B, ctx->r1) = ctx->r2;
    // j           L_8005880C
    // nop

    goto L_8005880C;
    // nop

L_800587C4:
    // sll         $v0, $a0, 6
    ctx->r2 = S32(ctx->r4) << 6;
    // div         $zero, $v0, $v1
	if (ctx->r3 != 0)
	{
		lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); 
		hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
	}
	else
	{
		lo = 0;
		hi = 0;
	}
    
    // bne         $v1, $zero, L_800587D8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800587D8;
    }
    // nop

    // break       7
    do_break(2147846100);
L_800587D8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_800587F0
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800587F0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_800587F0
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_800587F0;
    }
    // nop

    // break       6
    do_break(2147846124);
L_800587F0:
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $s4, -0x192C($at)
    MEM_B(-0X192C, ctx->r1) = ctx->r20;
    // ori         $v1, $zero, 0x7F
    ctx->r3 = 0 | 0X7F;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x192B($at)
    MEM_B(-0X192B, ctx->r1) = ctx->r3;
L_8005880C:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, -0x2560($v1)
    ctx->r3 = MEM_W(-0X2560, ctx->r3);
    // sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22) << 16;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(0X1, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x1926($at)
    MEM_B(-0X1926, ctx->r1) = ctx->r3;
    // lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(0X4, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x1925($at)
    MEM_B(-0X1925, ctx->r1) = ctx->r3;
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1929($v1)
    ctx->r3 = MEM_BU(-0X1929, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x1930($at)
    MEM_B(-0X1930, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x1924($v0)
    ctx->r2 = MEM_BU(-0X1924, ctx->r2);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lw          $a0, -0x1A08($a0)
    ctx->r4 = MEM_W(-0X1A08, ctx->r4);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x1921($at)
    MEM_B(-0X1921, ctx->r1) = ctx->r3;
    // lhu         $a0, 0x16($v0)
    ctx->r4 = MEM_HU(0X16, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x1918($at)
    MEM_H(-0X1918, ctx->r1) = ctx->r4;
    // lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(0X2, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x1923($at)
    MEM_B(-0X1923, ctx->r1) = ctx->r3;
    // lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(0X3, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x1922($at)
    MEM_B(-0X1922, ctx->r1) = ctx->r3;
    // lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(0X4, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x1920($at)
    MEM_B(-0X1920, ctx->r1) = ctx->r3;
    // lbu         $v1, 0x5($v0)
    ctx->r3 = MEM_BU(0X5, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x191F($at)
    MEM_B(-0X191F, ctx->r1) = ctx->r3;
    // lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(0X1, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x191C($at)
    MEM_B(-0X191C, ctx->r1) = ctx->r3;
    // lbu         $v1, 0x6($v0)
    ctx->r3 = MEM_BU(0X6, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v1, -0x191E($at)
    MEM_B(-0X191E, ctx->r1) = ctx->r3;
    // lbu         $v0, 0x7($v0)
    ctx->r2 = MEM_BU(0X7, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x191D($at)
    MEM_B(-0X191D, ctx->r1) = ctx->r2;
    // beq         $a0, $zero, L_80058930
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80058930;
    }
    // nop

    // jal         0x8005476C
    // nop

    sub_8005476C(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x49D8($v1)
    ctx->r3 = MEM_BU(-0X49D8, ctx->r3);
    // andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // bne         $s0, $v1, L_80058940
    if (ctx->r16 != ctx->r3) {
        // sll         $v0, $s0, 1
        ctx->r2 = S32(ctx->r16) << 1;
        goto L_80058940;
    }
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
L_80058930:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, -0x2570($at)
    MEM_W(-0X2570, ctx->r1) = 0;
    // j           L_80058A60
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80058A60;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058940:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s1, -0x1916($at)
    MEM_H(-0X1916, ctx->r1) = ctx->r17;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // ori         $v1, $zero, 0x21
    ctx->r3 = 0 | 0X21;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A2
    ctx->r1 = ADD32(ctx->r1, -0X75A2);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759A
    ctx->r1 = ADD32(ctx->r1, -0X759A);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $fp, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r30;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1929($v1)
    ctx->r3 = MEM_BU(-0X1929, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759E
    ctx->r1 = ADD32(ctx->r1, -0X759E);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s6, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r22;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A0
    ctx->r1 = ADD32(ctx->r1, -0X75A0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x1918($v1)
    ctx->r3 = MEM_HU(-0X1918, ctx->r3);
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75B0
    ctx->r1 = ADD32(ctx->r1, -0X75B0);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r3;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x1924($a0)
    ctx->r4 = MEM_BU(-0X1924, ctx->r4);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A4
    ctx->r1 = ADD32(ctx->r1, -0X75A4);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s5, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r21;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AE
    ctx->r1 = ADD32(ctx->r1, -0X75AE);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, 0x0($at)
    MEM_H(0X0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759C
    ctx->r1 = ADD32(ctx->r1, -0X759C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r4;
    // jal         0x80055088
    // nop

    sub_80055088(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x1918($v1)
    ctx->r3 = MEM_HS(-0X1918, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80058A38
    if (ctx->r3 != ctx->r2) {
        // sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21) << 16;
        goto L_80058A38;
    }
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
    // jal         0x800552C0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_800552C0(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // j           L_80058A54
    // nop

    goto L_80058A54;
    // nop

L_80058A38:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23) << 16;
    // jal         0x80055A58
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_80055A58(rdram, ctx);
    goto after_4;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_4:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // jal         0x80054A10
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    sub_80054A10(rdram, ctx);
    goto after_5;
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_5:
L_80058A54:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, -0x2570($at)
    MEM_W(-0X2570, ctx->r1) = 0;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80058A60:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
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
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
