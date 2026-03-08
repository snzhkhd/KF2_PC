#include "recomp.h"
#include "disable_warnings.h"

void PlaySfx(uint8_t* rdram, recomp_context* ctx) 
{
	ctx->r2 = 13;
	printf("[DEBUG] PlaySfx bypassed\n");
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // ori         $v0, $zero, 0x10
//    ctx->r2 = 0 | 0X10;
//    // bne         $a0, $v0, L_80024DC0
//    if (ctx->r4 != ctx->r2) {
//        // sw          $ra, 0x10($sp)
//        MEM_W(0X10, ctx->r29) = ctx->r31;
//        goto L_80024DC0;
//    }
//    // sw          $ra, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r31;
//    // j           L_80024DD0
//    // ori         $a0, $zero, 0x10
//    ctx->r4 = 0 | 0X10;
//    goto L_80024DD0;
//    // ori         $a0, $zero, 0x10
//    ctx->r4 = 0 | 0X10;
//L_80024DC0:
//    // addiu       $v0, $a0, -0x11
//    ctx->r2 = ADD32(ctx->r4, -0X11);
//    // sltiu       $v0, $v0, 0x2
//    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
//    // beq         $v0, $zero, L_80024DF0
//    if (ctx->r2 == 0) {
//        // ori         $v0, $zero, 0xD
//        ctx->r2 = 0 | 0XD;
//        goto L_80024DF0;
//    }
//    // ori         $v0, $zero, 0xD
//    ctx->r2 = 0 | 0XD;
//L_80024DD0:
//    // ori         $a1, $zero, 0x30
//    ctx->r5 = 0 | 0X30;
//    // ori         $a2, $zero, 0x30
//    ctx->r6 = 0 | 0X30;
//    // jal         0x80014710
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    PlayAudioStream(rdram, ctx);
//    goto after_0;
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    after_0:
//    // jal         0x8005C7F8
//    // nop
//
//    sub_8005C7F8(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // j           L_80024E2C
//    // nop
//
//    goto L_80024E2C;
//    // nop
//
//L_80024DF0:
//    // bne         $a0, $v0, L_80024E2C
//    if (ctx->r4 != ctx->r2) {
//        // ori         $a0, $zero, 0xD
//        ctx->r4 = 0 | 0XD;
//        goto L_80024E2C;
//    }
//    // ori         $a0, $zero, 0xD
//    ctx->r4 = 0 | 0XD;
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    // ori         $a2, $zero, 0x3A
//    ctx->r6 = 0 | 0X3A;
//    // jal         0x80014710
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    PlayAudioStream(rdram, ctx);
//    goto after_2;
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    after_2:
//    // jal         0x8006263C
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    KF_VSync(rdram, ctx);
//    goto after_3;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_3:
//    // jal         0x8006263C
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    KF_VSync(rdram, ctx);
//    goto after_4;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_4:
//    // ori         $a0, $zero, 0xD
//    ctx->r4 = 0 | 0XD;
//    // ori         $a1, $zero, 0x3A
//    ctx->r5 = 0 | 0X3A;
//    // addu        $a2, $zero, $zero
//    ctx->r6 = ADD32(0, 0);
//    // jal         0x80014710
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    PlayAudioStream(rdram, ctx);
//    goto after_5;
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    after_5:
//L_80024E2C:
//    // lw          $ra, 0x10($sp)
//    ctx->r31 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
