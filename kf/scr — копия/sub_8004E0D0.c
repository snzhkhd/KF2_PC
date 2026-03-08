#include "recomp.h"
#include "disable_warnings.h"

void sub_8004E0D0(uint8_t* rdram, recomp_context* ctx) 
{

	// CD tray check Ч на PC всегда готов
	ctx->r2 = 1;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x880($v0)
//    ctx->r2 = MEM_W(-0X880, ctx->r2);
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0xB70($v1)
//    ctx->r3 = MEM_W(-0XB70, ctx->r3);
//    // addiu       $sp, $sp, -0x20
//    ctx->r29 = ADD32(ctx->r29, -0X20);
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // addu        $s0, $zero, $zero
//    ctx->r16 = ADD32(0, 0);
//    // sw          $ra, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r31;
//    // slt         $v0, $v0, $v1
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
//    // beq         $v0, $zero, L_8004E1C8
//    if (ctx->r2 == 0) {
//        // sw          $s1, 0x14($sp)
//        MEM_W(0X14, ctx->r29) = ctx->r17;
//        goto L_8004E1C8;
//    }
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // lui         $s1, 0x8007
//    ctx->r17 = S32(0X8007 << 16);
//    // lw          $s1, -0xB88($s1)
//    ctx->r17 = MEM_W(-0XB88, ctx->r17);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0xB78($v0)
//    ctx->r2 = MEM_W(-0XB78, ctx->r2);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $zero, -0xB88($at)
//    MEM_W(-0XB88, ctx->r1) = 0;
//    // andi        $v0, $v0, 0x10
//    ctx->r2 = ctx->r2 & 0X10;
//    // beq         $v0, $zero, L_8004E16C
//    if (ctx->r2 == 0) {
//        // ori         $a0, $zero, 0x16
//        ctx->r4 = 0 | 0X16;
//        goto L_8004E16C;
//    }
//    // ori         $a0, $zero, 0x16
//    ctx->r4 = 0 | 0X16;
//    // andi        $v0, $s0, 0xFF
//    ctx->r2 = ctx->r16 & 0XFF;
//L_8004E124:
//    // bne         $v0, $zero, L_8004E13C
//    if (ctx->r2 != 0) {
//        // addiu       $s0, $s0, 0x1
//        ctx->r16 = ADD32(ctx->r16, 0X1);
//        goto L_8004E13C;
//    }
//    // addiu       $s0, $s0, 0x1
//    ctx->r16 = ADD32(ctx->r16, 0X1);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x2F34
//    ctx->r4 = ADD32(ctx->r4, 0X2F34);
//    // jal         0x80062C20
//    // nop
//
//    sub_80062C20(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//L_8004E13C:
//    // ori         $a0, $zero, 0x1
//    ctx->r4 = 0 | 0X1;
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    // addu        $a2, $zero, $zero
//    ctx->r6 = ADD32(0, 0);
//    // jal         0x8004DBE0
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    CD_cw_8004DBE0(rdram, ctx);
//    goto after_1;
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    after_1:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0xB78($v0)
//    ctx->r2 = MEM_W(-0XB78, ctx->r2);
//    // nop
//
//    // andi        $v0, $v0, 0x10
//    ctx->r2 = ctx->r2 & 0X10;
//    // bne         $v0, $zero, L_8004E124
//    if (ctx->r2 != 0) {
//        // andi        $v0, $s0, 0xFF
//        ctx->r2 = ctx->r16 & 0XFF;
//        goto L_8004E124;
//    }
//    // andi        $v0, $s0, 0xFF
//    ctx->r2 = ctx->r16 & 0XFF;
//    // ori         $a0, $zero, 0x16
//    ctx->r4 = 0 | 0X16;
//L_8004E16C:
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // addiu       $a1, $a1, -0x87C
//    ctx->r5 = ADD32(ctx->r5, -0X87C);
//    // addu        $a2, $zero, $zero
//    ctx->r6 = ADD32(0, 0);
//    // jal         0x8004DBE0
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    CD_cw_8004DBE0(rdram, ctx);
//    goto after_2;
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    after_2:
//    // beq         $v0, $zero, L_8004E1B0
//    if (ctx->r2 == 0) {
//        // ori         $a0, $zero, 0x1
//        ctx->r4 = 0 | 0X1;
//        goto L_8004E1B0;
//    }
//    // ori         $a0, $zero, 0x1
//    ctx->r4 = 0 | 0X1;
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    // addu        $a2, $zero, $zero
//    ctx->r6 = ADD32(0, 0);
//    // jal         0x8004DBE0
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    CD_cw_8004DBE0(rdram, ctx);
//    goto after_3;
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    after_3:
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x2F44
//    ctx->r4 = ADD32(ctx->r4, 0X2F44);
//    // jal         0x80062C20
//    // nop
//
//    sub_80062C20(rdram, ctx);
//    goto after_4;
//    // nop
//
//    after_4:
//    // j           L_8004E16C
//    // ori         $a0, $zero, 0x16
//    ctx->r4 = 0 | 0X16;
//    goto L_8004E16C;
//    // ori         $a0, $zero, 0x16
//    ctx->r4 = 0 | 0X16;
//L_8004E1B0:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0xB70($v0)
//    ctx->r2 = MEM_W(-0XB70, ctx->r2);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $s1, -0xB88($at)
//    MEM_W(-0XB88, ctx->r1) = ctx->r17;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, -0x880($at)
//    MEM_W(-0X880, ctx->r1) = ctx->r2;
//L_8004E1C8:
//    // lw          $ra, 0x18($sp)
//    ctx->r31 = MEM_W(0X18, ctx->r29);
//    // lw          $s1, 0x14($sp)
//    ctx->r17 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x20
//    ctx->r29 = ADD32(ctx->r29, 0X20);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
