#include "recomp.h"
#include "disable_warnings.h"

void sub_80013A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8004C24C
    // nop

    nullsub_3(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, -0xFC8
    ctx->r4 = ADD32(ctx->r4, -0XFC8);
    // jal         0x8004C500
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    sub_8004C500(rdram, ctx);
    goto after_1;
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_1:
    // jal         0x80061B2C
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_SetVideoMode(rdram, ctx);
    goto after_2;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_2:
    // jal         0x8004F310
    // nop

    sub_8004F310(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80061A8C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_PadInit(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // jal         0x8004C8C4
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    InitCARD2(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_5:
    // jal         0x80062A70
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_ChangeClearPAD(rdram, ctx);
    goto after_6;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // jal         0x80013ACC
    // nop

    ___MainGameLoop(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
