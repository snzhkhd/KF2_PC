#include "recomp.h"
#include "disable_warnings.h"

void MemCard_InitSystem(uint8_t* rdram, recomp_context* ctx) 
{

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // sw          $ra, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r31;
//    // jal         0x80062840
//    // nop
//
//    KF_EnterCriticalSection(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//    // jal         0x8004C8E4
//    // nop
//
//    StartCARD2(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // jal         0x80062A70
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    KF_ChangeClearPAD(rdram, ctx);
//    goto after_2;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_2:
//    // jal         0x80062A90
//    // nop
//
//    KF_bu_init(rdram, ctx);
//    goto after_3;
//    // nop
//
//    after_3:
//    // jal         0x80017C18
//    // ori         $a0, $zero, 0x4000
//    ctx->r4 = 0 | 0X4000;
//    AllocateMemory(rdram, ctx);
//    goto after_4;
//    // ori         $a0, $zero, 0x4000
//    ctx->r4 = 0 | 0X4000;
//    after_4:
//    // sw          $v0, 0x138($gp)
//    MEM_W(0X138, ctx->r28) = ctx->r2;
//    // bne         $v0, $zero, L_8002504C
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8002504C;
//    }
//    // nop
//
//    // jal         0x80062C10
//    // ori         $a0, $zero, 0x1
//    ctx->r4 = 0 | 0X1;
//    KF_exit(rdram, ctx);
//    goto after_5;
//    // ori         $a0, $zero, 0x1
//    ctx->r4 = 0 | 0X1;
//    after_5:
//L_8002504C:
//    // jal         0x80062AF0
//    // nop
//
//    KF_ExitCriticalSection(rdram, ctx);
//    goto after_6;
//    // nop
//
//    after_6:
//    // lw          $ra, 0x10($sp)
//    ctx->r31 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    // jr          $ra
//    // nop

    return;
    // nop

;}
