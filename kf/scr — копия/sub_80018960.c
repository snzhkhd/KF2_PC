#include "recomp.h"
#include "disable_warnings.h"

void sub_80018960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // lw          $v0, 0x58($gp)
    ctx->r2 = MEM_W(0X58, ctx->r28);
    // lb          $v1, 0x5C($gp)
    ctx->r3 = MEM_B(0X5C, ctx->r28);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sb          $v1, 0x14($sp)
    MEM_B(0X14, ctx->r29) = ctx->r3;
    // addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // jal         0x80062B90
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    strcat_recomp(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x6320
    ctx->r5 = ADD32(ctx->r5, 0X6320);
    // jal         0x80062B90
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    strcat_recomp(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // jal         0x80018190
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004F4AC
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    KF_CdSearchFile(rdram, ctx);
    goto after_3;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // bne         $v0, $zero, L_800189CC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800189CC;
    }
    // nop

    // jal         0x800186B8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    nullsub_1(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
L_800189CC:
    // lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(0X54, ctx->r29);
    // addiu       $v1, $zero, -0x800
    ctx->r3 = ADD32(0, -0X800);
    // addiu       $v0, $v0, 0x7FF
    ctx->r2 = ADD32(ctx->r2, 0X7FF);
    // and         $s1, $v0, $v1
    ctx->r17 = ctx->r2 & ctx->r3;
    // jal         0x80017C18
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    AllocateMemory(rdram, ctx);
    goto after_5;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80018A04
    if (ctx->r16 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80018A04;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x800186C0
    // srl         $a2, $s1, 11
    ctx->r6 = S32(U32(ctx->r17) >> 11);
    CDReadSectorsInternal(rdram, ctx);
    goto after_6;
    // srl         $a2, $s1, 11
    ctx->r6 = S32(U32(ctx->r17) >> 11);
    after_6:
    // j           L_80018A08
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_80018A08;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80018A04:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80018A08:
    // lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(0X74, ctx->r29);
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(0X6C, ctx->r29);
    // lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(0X68, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
