#include "recomp.h"
#include "disable_warnings.h"

void sub_8004F418(uint8_t* rdram, recomp_context* ctx) 
{
    printf("sub_8004F418\n");
    // CdSetmode + CdlReadS для аудио стрима
    // CdlReadS уже обрабатывается в KFCD_CdControl
  //  ctx->r2 = 0;
////    uint64_t hi = 0, lo = 0, result = 0;
////    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
////    int c1cs = 0; 
////    // addiu       $sp, $sp, -0x20
////    ctx->r29 = ADD32(ctx->r29, -0X20);
////    // sw          $s0, 0x18($sp)
////    MEM_W(0X18, ctx->r29) = ctx->r16;
////    // addu        $s0, $a0, $zero
////    ctx->r16 = ADD32(ctx->r4, 0);
////    // ori         $a0, $zero, 0xE
////    ctx->r4 = 0 | 0XE;
////    // addiu       $a1, $sp, 0x10
////    ctx->r5 = ADD32(ctx->r29, 0X10);
////    // addu        $a2, $zero, $zero
////    ctx->r6 = ADD32(0, 0);
////    // sw          $ra, 0x1C($sp)
////    MEM_W(0X1C, ctx->r29) = ctx->r31;
////    // jal         0x8004CAC0
////    // sb          $s0, 0x10($sp)
////    MEM_B(0X10, ctx->r29) = ctx->r16;
////    KF_CdControl(rdram, ctx);
////    goto after_0;
////    // sb          $s0, 0x10($sp)
////    MEM_B(0X10, ctx->r29) = ctx->r16;
////    after_0:
////    // andi        $v0, $s0, 0x100
////    ctx->r2 = ctx->r16 & 0X100;
////    // beq         $v0, $zero, L_8004F488
////    if (ctx->r2 == 0) {
////        // andi        $v0, $s0, 0x20
////        ctx->r2 = ctx->r16 & 0X20;
////        goto L_8004F488;
////    }
////    // andi        $v0, $s0, 0x20
////    ctx->r2 = ctx->r16 & 0X20;
////    // beq         $v0, $zero, L_8004F460
////    if (ctx->r2 == 0) {
////        // ori         $v0, $zero, 0x1
////        ctx->r2 = 0 | 0X1;
////        goto L_8004F460;
////    }
////    // ori         $v0, $zero, 0x1
////    ctx->r2 = 0 | 0X1;
////    // lui         $at, 0x800A
////    ctx->r1 = S32(0X800A << 16);
////    // sw          $zero, -0x219C($at)
////    MEM_W(-0X219C, ctx->r1) = 0;
////    // j           L_8004F468
////    // nop
////
////    goto L_8004F468;
////    // nop
////
////L_8004F460:
////    // lui         $at, 0x800A
////    ctx->r1 = S32(0X800A << 16);
////    // sw          $v0, -0x219C($at)
////    MEM_W(-0X219C, ctx->r1) = ctx->r2;
////L_8004F468:
////    // lui         $a0, 0x8005
////    ctx->r4 = S32(0X8005 << 16);
////    // addiu       $a0, $a0, 0xA2C
////    ctx->r4 = ADD32(ctx->r4, 0XA2C);
////    // jal         0x8004CEE0
////    // nop
////
////    sub_8004CEE0(rdram, ctx);
////    goto after_1;
////    // nop
////
////    after_1:
////    // lui         $a0, 0x8005
////    ctx->r4 = S32(0X8005 << 16);
////    // addiu       $a0, $a0, -0x14C
////    ctx->r4 = ADD32(ctx->r4, -0X14C);
////    // jal         0x8004CA90
////    // nop
////
////    KF_CdSyncCallback(rdram, ctx);
////    goto after_2;
////    // nop
////
////    after_2:
////L_8004F488:
////    // ori         $a0, $zero, 0x1B
////    ctx->r4 = 0 | 0X1B;
////    // addu        $a1, $zero, $zero
////    ctx->r5 = ADD32(0, 0);
////    // jal         0x8004CAC0
////    // addu        $a2, $zero, $zero
////    ctx->r6 = ADD32(0, 0);
////    KF_CdControl(rdram, ctx);
////    goto after_3;
////    // addu        $a2, $zero, $zero
////    ctx->r6 = ADD32(0, 0);
////    after_3:
////    // lw          $ra, 0x1C($sp)
////    ctx->r31 = MEM_W(0X1C, ctx->r29);
////    // lw          $s0, 0x18($sp)
////    ctx->r16 = MEM_W(0X18, ctx->r29);
////    // addiu       $sp, $sp, 0x20
////    ctx->r29 = ADD32(ctx->r29, 0X20);
////    // jr          $ra
////    // nop
////
////    return;
////    // nop

;}
