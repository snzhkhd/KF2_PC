#include "recomp.h"
#include "disable_warnings.h"

void CDReadSectorsInternal(uint8_t* rdram, recomp_context* ctx) 
{
    printf("[CDReadSectorsInternal] active_stream=%08X stream[0]=%02X stream[1]=%02X\n",
        *(uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM),
        ((uint8_t*)GET_PTR(*(uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM)))[0],
        ((uint8_t*)GET_PTR(*(uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM)))[1]);

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80018190
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A4C($a0)
    ctx->r4 = MEM_W(-0X5A4C, ctx->r4);
    // jal         0x80062A30
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    KF_DisableEvent(rdram, ctx);
    goto after_1;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_1:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A48($a0)
    ctx->r4 = MEM_W(-0X5A48, ctx->r4);
    // jal         0x80062A30
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
    KF_DisableEvent(rdram, ctx);
    goto after_2;
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
    after_2:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A40($a0)
    ctx->r4 = MEM_W(-0X5A40, ctx->r4);
    // jal         0x80062A30
    // nop

    KF_DisableEvent(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_4;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
L_80018734:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_5;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
    // beq         $v0, $zero, L_80018734
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x2
        ctx->r4 = 0 | 0X2;
        goto L_80018734;
    }
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
L_8001874C:
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // jal         0x8004CF44
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    CdReadWithRetry(rdram, ctx);
    goto after_6;
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    after_6:
    // beq         $v0, $zero, L_8001874C
    if (ctx->r2 == 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8001874C;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_80018764:
    // jal         0x8004CF24
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    CdCheckStatus(rdram, ctx);
    goto after_7;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // blez        $s0, L_8001879C
    if (SIGNED(ctx->r16) <= 0) {
        // ori         $a0, $zero, 0x9
        ctx->r4 = 0 | 0X9;
        goto L_8001879C;
    }
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x6440($v0)
    ctx->r2 = MEM_BU(0X6440, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80018764
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x1
        ctx->r4 = 0 | 0X1;
        goto L_80018764;
    }
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // jal         0x80019198
    // nop

    sub_80019198(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // j           L_80018764
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    goto L_80018764;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_8001879C:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_9;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_9:
    // bne         $s0, $zero, L_800187B8
    if (ctx->r16 != 0) {
        // nop
    
        goto L_800187B8;
    }
    // nop

    // j           L_800187C8
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    goto L_800187C8;
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
L_800187B8:
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_80018734
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x2
        ctx->r4 = 0 | 0X2;
        goto L_80018734;
    }
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
L_800187C8:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A4C($a0)
    ctx->r4 = MEM_W(-0X5A4C, ctx->r4);
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A48($a0)
    ctx->r4 = MEM_W(-0X5A48, ctx->r4);
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5A40($a0)
    ctx->r4 = MEM_W(-0X5A40, ctx->r4);
    // jal         0x80062870
    // nop

    KF_EnableEvent(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $s5, $v0, L_8001880C
    if (ctx->r21 != ctx->r2) {
        // nop
    
        goto L_8001880C;
    }
    // nop

    // jal         0x800186B8
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    nullsub_1(rdram, ctx);
    goto after_13;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_13:
L_8001880C:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
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
