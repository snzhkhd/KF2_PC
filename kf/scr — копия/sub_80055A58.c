#include "recomp.h"
#include "disable_warnings.h"

void sub_80055A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1929($v1)
    ctx->r3 = MEM_BU(-0X1929, ctx->r3);
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
    // addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(0X5, ctx->r3);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // bgez        $v0, L_80055A9C
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_80055A9C;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_80055A9C:
    // sra         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2) >> 3;
    // slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80055AB4
    if (ctx->r2 != 0) {
        // addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
        goto L_80055AB4;
    }
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // addiu       $a0, $a1, -0x10
    ctx->r4 = ADD32(ctx->r5, -0X10);
L_80055AB4:
    // lbu         $v1, 0x4($v1)
    ctx->r3 = MEM_BU(0X4, ctx->r3);
    // addiu       $v0, $a3, 0x3C
    ctx->r2 = ADD32(ctx->r7, 0X3C);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // ori         $v1, $zero, 0xC
    ctx->r3 = 0 | 0XC;
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
    
    // bne         $v1, $zero, L_80055AE0
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80055AE0;
    }
    // nop

    // break       7
    do_break(2147834588);
L_80055AE0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80055AF8
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80055AF8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80055AF8
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80055AF8;
    }
    // nop

    // break       6
    do_break(2147834612);
L_80055AF8:
    // mflo        $v0
    ctx->r2 = lo;
    // mfhi        $v1
    ctx->r3 = hi;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x48
    ctx->r1 = ADD32(ctx->r1, 0X48);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // blez        $v0, L_80055B40
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80055B40;
    }
    // nop

    // j           L_80055B54
    // sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3) << (ctx->r2 & 31);
    goto L_80055B54;
    // sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3) << (ctx->r2 & 31);
L_80055B40:
    // bgez        $v0, L_80055B54
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80055B54;
    }
    // nop

    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // srav        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3) >> (ctx->r2 & 31);
L_80055B54:
    // jr          $ra
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
;}
