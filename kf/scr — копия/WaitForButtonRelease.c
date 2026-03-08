#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"

void WaitForButtonRelease(uint8_t* rdram, recomp_context* ctx) 
{
	//printf("WaitForButtonRelease bypassed\n");
	//ctx->r2 = 0;
    printf("WaitForButtonRelease\n");

    // *(gp + 104) = 0
    MEM_W(0x68, ctx->r28) = 0;

    uint32_t result;
    do {
        // Без этого пад не обновляется — вечный цикл
        PsyX_UpdateInput();

        KF_PadRead(rdram, ctx);
        result = ctx->r2;
    } while (result != 0);

    ctx->r2 = 0;

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // sw          $ra, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r31;
//    // sw          $zero, 0x68($gp)
//    MEM_W(0X68, ctx->r28) = 0;
//L_80024EE0:
//    // jal         0x80061ADC
//    // ori         $a0, $zero, 0x1
//    ctx->r4 = 0 | 0X1;
//    KF_PadRead(rdram, ctx);
//    goto after_0;
//    // ori         $a0, $zero, 0x1
//    ctx->r4 = 0 | 0X1;
//    after_0:
//    // bne         $v0, $zero, L_80024EE0
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_80024EE0;
//    }
//    // nop
//
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
