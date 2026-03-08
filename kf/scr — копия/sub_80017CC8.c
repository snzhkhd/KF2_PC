#include "recomp.h"
#include "disable_warnings.h"

void sub_80017CC8(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("sub_80017CC8\n");
    // ∆дЄм 3 CD IRQ Ч на PC просто выходим
    MEM_W(0, 0x801BA5AC) = 0; // сбрасываем счЄтчик
    ctx->r2 = 0;

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // lui         $s0, 0x801C
//    ctx->r16 = S32(0X801C << 16);
//    // addiu       $s0, $s0, -0x5A54
//    ctx->r16 = ADD32(ctx->r16, -0X5A54);
//    // sw          $ra, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r31;
//L_80017CDC:
//    // jal         0x80062840
//    // nop
//
//    KF_EnterCriticalSection(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//    // lw          $v0, 0x0($s0)
//    ctx->r2 = MEM_W(0X0, ctx->r16);
//    // nop
//
//    // sltiu       $v0, $v0, 0x3
//    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
//    // beq         $v0, $zero, L_80017D10
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80017D10;
//    }
//    // nop
//
//    // jal         0x80062AF0
//    // nop
//
//    KF_ExitCriticalSection(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // jal         0x8006263C
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    KF_VSync(rdram, ctx);
//    goto after_2;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_2:
//    // j           L_80017CDC
//    // nop
//
//    goto L_80017CDC;
//    // nop
//
//L_80017D10:
//    // jal         0x80062AF0
//    // sw          $zero, 0x0($s0)
//    MEM_W(0X0, ctx->r16) = 0;
//    KF_ExitCriticalSection(rdram, ctx);
//    goto after_3;
//    // sw          $zero, 0x0($s0)
//    MEM_W(0X0, ctx->r16) = 0;
//    after_3:
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
