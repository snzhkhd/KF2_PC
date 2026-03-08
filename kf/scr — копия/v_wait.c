#include "recomp.h"
#include "disable_warnings.h"

void v_wait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sll         $a1, $a1, 15
    ctx->r5 = S32(ctx->r5) << 15;
    // sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6128($v0)
    ctx->r2 = MEM_W(0X6128, ctx->r2);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_80062810
    if (ctx->r2 == 0) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_80062810;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800627AC:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // bne         $v0, $v1, L_800627F8
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_800627F8;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x362C
    ctx->r4 = ADD32(ctx->r4, 0X362C);
    // jal         0x80062C20
    // nop

    sub_80062C20(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x80062A70
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_ChangeClearPAD(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // jal         0x80062B00
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    ChangeClearRCnt(rdram, ctx);
    goto after_2;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // j           L_80062810
    // nop

    goto L_80062810;
    // nop

L_800627F8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6128($v0)
    ctx->r2 = MEM_W(0X6128, ctx->r2);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_800627AC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800627AC;
    }
    // nop

L_80062810:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
