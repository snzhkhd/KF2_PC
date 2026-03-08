#include "recomp.h"
#include "disable_warnings.h"

void CreateCDTask(uint8_t* rdram, recomp_context* ctx) 
{
    printf("CreateCDTask\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // addiu       $s1, $s1, -0x57BC
    ctx->r17 = ADD32(ctx->r17, -0X57BC);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // lw          $s5, 0x0($s1)
    ctx->r21 = MEM_W(0X0, ctx->r17);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // jal         0x80018244
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    FAsyncLoadSomething_0005(rdram, ctx);
    goto after_0;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_0:
    // jal         0x80062840
    // addiu       $s0, $s0, 0x7FF
    ctx->r16 = ADD32(ctx->r16, 0X7FF);
    KF_EnterCriticalSection(rdram, ctx);
    goto after_1;
    // addiu       $s0, $s0, 0x7FF
    ctx->r16 = ADD32(ctx->r16, 0X7FF);
    after_1:
    // sb          $s2, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r18;
    // sb          $zero, 0x1($s5)
    MEM_B(0X1, ctx->r21) = 0;
    // lwl         $v0, 0x3($s6)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r22);
    // lwr         $v0, 0x0($s6)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r22);
    // nop

    // swl         $v0, 0x5($s5)
    do_swl(rdram, 0X5, ctx->r21, ctx->r2);
    // swr         $v0, 0x2($s5)
    do_swr(rdram, 0X2, ctx->r21, ctx->r2);
    // lwl         $v0, 0x5($s5)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X5, ctx->r21);
    // lwr         $v0, 0x2($s5)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X2, ctx->r21);
    // nop

    // swl         $v0, 0x9($s5)
    do_swl(rdram, 0X9, ctx->r21, ctx->r2);
    // swr         $v0, 0x6($s5)
    do_swr(rdram, 0X6, ctx->r21, ctx->r2);
    // srl         $s0, $s0, 11
    ctx->r16 = S32(U32(ctx->r16) >> 11);
    // sw          $s3, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r19;
    // sw          $s0, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r16;
    // sw          $s4, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r20;
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // bne         $v0, $s1, L_800183A4
    if (ctx->r2 != ctx->r17) {
        // sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_800183A4;
    }
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // addiu       $v0, $v1, -0x258
    ctx->r2 = ADD32(ctx->r3, -0X258);
    // sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
L_800183A4:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x57B8($v0)
    ctx->r2 = MEM_W(-0X57B8, ctx->r2);
    // nop

    // bne         $v0, $s5, L_800183E0
    if (ctx->r2 != ctx->r21) {
        // nop
    
        goto L_800183E0;
    }
    // nop

    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_800183C4:
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // beq         $v0, $zero, L_800183C4
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_800183C4;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // j           L_800183EC
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    goto L_800183EC;
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
L_800183E0:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
L_800183EC:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
