#include "recomp.h"
#include "disable_warnings.h"

void _SsStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_80053F68:
    // slti        $v0, $v1, 0xBB8
    ctx->r2 = SIGNED(ctx->r3) < 0XBB8 ? 1 : 0;
    // bne         $v0, $zero, L_80053F68
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x3
        ctx->r3 = ADD32(ctx->r3, 0X3);
        goto L_80053F68;
    }
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    // sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, 0x3D($at)
    MEM_B(0X3D, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x38($at)
    MEM_W(0X38, ctx->r1) = 0;
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, 0x3E($at)
    MEM_B(0X3E, ctx->r1) = ctx->r2;
    // lui         $s1, 0xF200
    ctx->r17 = S32(0XF200 << 16);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x2C($v1)
    ctx->r3 = MEM_W(0X2C, ctx->r3);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_8005402C
    if (ctx->r3 == ctx->r2) {
        // ori         $s1, $s1, 0x2
        ctx->r17 = ctx->r17 | 0X2;
        goto L_8005402C;
    }
    // ori         $s1, $s1, 0x2
    ctx->r17 = ctx->r17 | 0X2;
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_80053FD0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053FD0;
    }
    // nop

    // beq         $v1, $zero, L_80053FEC
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_80053FEC;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // j           L_80054034
    // nop

    goto L_80054034;
    // nop

L_80053FD0:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // beq         $v1, $v0, L_80054024
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_80054024;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // beq         $v1, $v0, L_80053FFC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80053FFC;
    }
    // nop

    // j           L_80054034
    // nop

    goto L_80054034;
    // nop

L_80053FEC:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, 0x3E($at)
    MEM_B(0X3E, ctx->r1) = ctx->r2;
    // j           L_800541C0
    // nop

    goto L_800541C0;
    // nop

L_80053FFC:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, 0x3E($at)
    MEM_B(0X3E, ctx->r1) = 0;
    // bne         $a0, $zero, L_80054014
    if (ctx->r4 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80054014;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_800540E0
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    goto L_800540E0;
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_80054014:
    // lui         $s1, 0xF200
    ctx->r17 = S32(0XF200 << 16);
    // ori         $s1, $s1, 0x3
    ctx->r17 = ctx->r17 | 0X3;
    // j           L_800540E0
    // ori         $s0, $zero, 0x1
    ctx->r16 = 0 | 0X1;
    goto L_800540E0;
    // ori         $s0, $zero, 0x1
    ctx->r16 = 0 | 0X1;
L_80054024:
    // j           L_800540E0
    // ori         $s0, $zero, 0x89D0
    ctx->r16 = 0 | 0X89D0;
    goto L_800540E0;
    // ori         $s0, $zero, 0x89D0
    ctx->r16 = 0 | 0X89D0;
L_8005402C:
    // j           L_800540E0
    // ori         $s0, $zero, 0x44E8
    ctx->r16 = 0 | 0X44E8;
    goto L_800540E0;
    // ori         $s0, $zero, 0x44E8
    ctx->r16 = 0 | 0X44E8;
L_80054034:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // bne         $v0, $zero, L_800541C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800541C0;
    }
    // nop

    // lw          $v1, -0x4($a0)
    ctx->r3 = MEM_W(-0X4, ctx->r4);
    // nop

    // slti        $v0, $v1, 0x46
    ctx->r2 = SIGNED(ctx->r3) < 0X46 ? 1 : 0;
    // beq         $v0, $zero, L_800540A4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x20
        ctx->r2 = S32(0X20 << 16);
        goto L_800540A4;
    }
    // lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // ori         $v0, $v0, 0x4CC0
    ctx->r2 = ctx->r2 | 0X4CC0;
    // div         $zero, $v0, $v1
	if (ctx->r3 != 0)
	{
		lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); 
		hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
	}
	else
	{
		hi = 0;
		lo = 0;
	}
    
    // bne         $v1, $zero, L_80054074
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054074;
    }
    // nop

    // break       7
    do_break(2147827824);
L_80054074:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8005408C
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8005408C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8005408C
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8005408C;
    }
    // nop

    // break       6
    do_break(2147827848);
L_8005408C:
    // mflo        $v0
    ctx->r2 = lo;
    // lbu         $v1, 0xD($a0)
    ctx->r3 = MEM_BU(0XD, ctx->r4);
    // nop

    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // j           L_800540D8
    // sb          $v1, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r3;
    goto L_800540D8;
    // sb          $v1, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r3;
L_800540A4:
    // lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // ori         $v0, $v0, 0x9980
    ctx->r2 = ctx->r2 | 0X9980;
    // div         $zero, $v0, $v1
	if (ctx->r3 != 0)
	{
		lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); 
		hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
	}
	else
	{
		hi = 0;
		lo = 0;
	}
    
    // bne         $v1, $zero, L_800540BC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800540BC;
    }
    // nop

    // break       7
    do_break(2147827896);
L_800540BC:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_800540D4
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800540D4;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_800540D4
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_800540D4;
    }
    // nop

    // break       6
    do_break(2147827920);
L_800540D4:
    // mflo        $v0
    ctx->r2 = lo;
L_800540D8:
    // nop

    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800540E0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x3C($v0)
    ctx->r2 = MEM_BU(0X3C, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80054114
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80054114;
    }
    // nop

    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(0X34, ctx->r4);
    // jal         0x80061BE4
    // nop

    KF_VSyncCallback(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_800541B8
    // nop

    goto L_800541B8;
    // nop

L_80054114:
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x800629F8
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_800629F8(rdram, ctx);
    goto after_3;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // jal         0x800628B0
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    sub_800628B0(rdram, ctx);
    goto after_4;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_4:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lbu         $a0, 0x3E($a0)
    ctx->r4 = MEM_BU(0X3E, ctx->r4);
    // nop

    // bne         $a0, $zero, L_8005417C
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8005417C;
    }
    // nop

    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80061B84
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    InterruptCallback(rdram, ctx);
    goto after_5;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lbu         $a0, 0x3E($a0)
    ctx->r4 = MEM_BU(0X3E, ctx->r4);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x38($at)
    MEM_W(0X38, ctx->r1) = ctx->r2;
    // lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // addiu       $a1, $a1, 0x3EC0
    ctx->r5 = ADD32(ctx->r5, 0X3EC0);
    // jal         0x80061B84
    // nop

    InterruptCallback(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_800541B8
    // nop

    goto L_800541B8;
    // nop

L_8005417C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x3D($v0)
    ctx->r2 = MEM_BU(0X3D, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800541A8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800541A8;
    }
    // nop

    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x34($a1)
    ctx->r5 = MEM_W(0X34, ctx->r5);
    // jal         0x80061B84
    // nop

    InterruptCallback(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // j           L_800541B8
    // nop

    goto L_800541B8;
    // nop

L_800541A8:
    // lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // addiu       $a1, $a1, 0x3F00
    ctx->r5 = ADD32(ctx->r5, 0X3F00);
    // jal         0x80061B84
    // nop

    InterruptCallback(rdram, ctx);
    goto after_8;
    // nop

    after_8:
L_800541B8:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_9;
    // nop

    after_9:
L_800541C0:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
