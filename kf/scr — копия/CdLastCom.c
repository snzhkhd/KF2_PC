#include "recomp.h"
#include "disable_warnings.h"

void KF_CdLastCom(uint8_t* rdram, recomp_context* ctx) 
{
	printf("KF_CdLastCom\n");
	ctx->r2 = 1;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // addu        $s0, $a0, $zero
//    ctx->r16 = ADD32(ctx->r4, 0);
//    // ori         $v0, $zero, 0x2
//    ctx->r2 = 0 | 0X2;
//    // bne         $s0, $v0, L_8004C94C
//    if (ctx->r16 != ctx->r2) {
//        // sw          $ra, 0x14($sp)
//        MEM_W(0X14, ctx->r29) = ctx->r31;
//        goto L_8004C94C;
//    }
//    // sw          $ra, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r31;
//    // jal         0x8004E3BC
//    // nop
//
//    sub_8004E3BC(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//    // j           L_8004C97C
//    // ori         $v0, $zero, 0x1
//    ctx->r2 = 0 | 0X1;
//    goto L_8004C97C;
//    // ori         $v0, $zero, 0x1
//    ctx->r2 = 0 | 0X1;
//L_8004C94C:
//    // jal         0x8004E42C
//    // nop
//
//    sub_8004E42C(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // bne         $v0, $zero, L_8004C97C
//    if (ctx->r2 != 0) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_8004C97C;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // ori         $v0, $zero, 0x1
//    ctx->r2 = 0 | 0X1;
//    // bne         $s0, $v0, L_8004C97C
//    if (ctx->r16 != ctx->r2) {
//        // nop
//    
//        goto L_8004C97C;
//    }
//    // nop
//
//    // jal         0x8004E2C8
//    // nop
//
//    sub_8004E2C8(rdram, ctx);
//    goto after_2;
//    // nop
//
//    after_2:
//    // bne         $v0, $zero, L_8004C97C
//    if (ctx->r2 != 0) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_8004C97C;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // ori         $v0, $zero, 0x1
//    ctx->r2 = 0 | 0X1;
//L_8004C97C:
//    // lw          $ra, 0x14($sp)
//    ctx->r31 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
