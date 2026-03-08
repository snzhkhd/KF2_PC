#include "recomp.h"
#include "disable_warnings.h"

void sub_80056D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(0X28, ctx->r29);
    // ori         $v0, $zero, 0xFFC0
    ctx->r2 = 0 | 0XFFC0;
    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A2
    ctx->r1 = ADD32(ctx->r1, -0X75A2);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // bne         $v0, $a1, L_80056FD4
    if (ctx->r2 != ctx->r5) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80056FD4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759A
    ctx->r1 = ADD32(ctx->r1, -0X759A);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_80056FD4
    if (ctx->r3 != ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80056FD4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759E
    ctx->r1 = ADD32(ctx->r1, -0X759E);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_80056FD4
    if (ctx->r3 != ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80056FD4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759C
    ctx->r1 = ADD32(ctx->r1, -0X759C);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x1929($v0)
    ctx->r2 = MEM_BU(-0X1929, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A4
    ctx->r1 = ADD32(ctx->r1, -0X75A4);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lhu         $a0, 0x0($at)
    ctx->r4 = MEM_HU(0X0, ctx->r1);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // blez        $a1, L_80056ED4
    if (SIGNED(ctx->r5) <= 0) {
        // andi        $v0, $a3, 0xFFFF
        ctx->r2 = ctx->r7 & 0XFFFF;
        goto L_80056ED4;
    }
    // andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, -0x1A08($v1)
    ctx->r3 = MEM_W(-0X1A08, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0xD($v0)
    ctx->r2 = MEM_BU(0XD, ctx->r2);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3F
    ctx->r3 = 0 | 0X3F;
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
    
    // bne         $v1, $zero, L_80056EA8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80056EA8;
    }
    // nop

    // break       7
    do_break(2147839652);
L_80056EA8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80056EC0
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80056EC0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80056EC0
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80056EC0;
    }
    // nop

    // break       6
    do_break(2147839676);
L_80056EC0:
    // mflo        $v0
    ctx->r2 = lo;
    // mfhi        $v1
    ctx->r3 = hi;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // j           L_80056F44
    // sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3) << 1;
    goto L_80056F44;
    // sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3) << 1;
L_80056ED4:
    // bgez        $a1, L_80056F40
    if (SIGNED(ctx->r5) >= 0) {
        // andi        $v1, $a3, 0xFFFF
        ctx->r3 = ctx->r7 & 0XFFFF;
        goto L_80056F40;
    }
    // andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x1A08($v0)
    ctx->r2 = MEM_W(-0X1A08, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(0XC, ctx->r3);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // bgez        $v1, L_80056F10
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80056F10;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x3F
    ctx->r2 = ADD32(ctx->r3, 0X3F);
L_80056F10:
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // bgez        $v1, L_80056F28
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80056F28;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x3F
    ctx->r2 = ADD32(ctx->r3, 0X3F);
L_80056F28:
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // j           L_80056F44
    // addiu       $a1, $v0, 0x7F
    ctx->r5 = ADD32(ctx->r2, 0X7F);
    goto L_80056F44;
    // addiu       $a1, $v0, 0x7F
    ctx->r5 = ADD32(ctx->r2, 0X7F);
L_80056F40:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80056F44:
    // sll         $v1, $s0, 16
    ctx->r3 = S32(ctx->r16) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x759C
    ctx->r1 = ADD32(ctx->r1, -0X759C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s0, -0x1916($at)
    MEM_H(-0X1916, ctx->r1) = ctx->r16;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x1924($at)
    MEM_B(-0X1924, ctx->r1) = ctx->r2;
    // jal         0x80055A58
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_80055A58(rdram, ctx);
    goto after_0;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_0:
    // sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4) << 4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7744
    ctx->r1 = ADD32(ctx->r1, -0X7744);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $v0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v1, 0x0($at)
    ctx->r3 = MEM_BU(0X0, ctx->r1);
    // nop

    // ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80056FD4:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
