#include "recomp.h"
#include "disable_warnings.h"

void AsyncStructForcedLoadSync(uint8_t* rdram, recomp_context* ctx) 
{
    static int call_count = 0;
 //   printf("[AsyncStructSync] call #%d\n", ++call_count);

    uint32_t* p_active = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
    uint32_t* p_queue = (uint32_t*)GET_PTR(ADDR_G_CDTASKQUEUE);

   /* printf("[AsyncStructSync] active=0x%08X queue=0x%08X active_state=%d\n",
        p_active ? *p_active : 0,
        p_queue ? *p_queue : 0,
        (p_active && *p_active) ? *(uint8_t*)GET_PTR(*p_active) : -1);*/

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, -0x57B8
    ctx->r16 = ADD32(ctx->r16, -0X57B8);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_800181A4:
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // lw          $v0, -0x4($s0)
    ctx->r2 = MEM_W(-0X4, ctx->r16);
    // nop

    // bne         $v1, $v0, L_800181DC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800181DC;
    }
    // nop

    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x57B8($v0)
    ctx->r2 = MEM_W(-0X57B8, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80018228
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80018228;
    }
    // nop

L_800181DC:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80017C60
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x6440($v0)
    ctx->r2 = MEM_BU(0X6440, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800181A4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800181A4;
    }
    // nop

    // jal         0x80019198
    // nop

    sub_80019198(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80019198
    // nop

    sub_80019198(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80019198
    // nop

    sub_80019198(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x80019198
    // nop

    sub_80019198(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_800181A4
    // nop

    goto L_800181A4;
    // nop

L_80018228:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop
    printf("[AsyncStructSync] #%d done\n", call_count);
    return;
    // nop

;}
