#include "recomp.h"
#include "disable_warnings.h"

void sub_80065460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // bne         $a0, $zero, L_80065514
    if (ctx->r4 != 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80065514;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x800655A8
    // nop

    SyncVSyncStatus(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_80065498
    // nop

    goto L_80065498;
    // nop

L_80065480:
    // jal         0x80065010
    // nop

    sub_80065010(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x800655DC
    // nop

    GPU_CheckTimeout_800655DC(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $zero, L_80065594
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80065594;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80065498:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A8($v0)
    ctx->r2 = MEM_W(0X62A8, ctx->r2);
    // nop

    // beq         $v1, $v0, L_800654CC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800654CC;
    }
    // nop

    // j           L_80065480
    // nop

    goto L_80065480;
    // nop

L_800654BC:
    // jal         0x800655DC
    // nop

    GPU_CheckTimeout_800655DC(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // bne         $v0, $zero, L_80065594
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80065594;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800654CC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6280($v0)
    ctx->r2 = MEM_W(0X6280, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_800654BC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800654BC;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6274($v0)
    ctx->r2 = MEM_W(0X6274, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_800654BC
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800654BC;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_80065594
    // nop

    goto L_80065594;
    // nop

L_80065514:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A4($v0)
    ctx->r2 = MEM_W(0X62A4, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A8($v1)
    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $s0, $v0, 0x3F
    ctx->r16 = ctx->r2 & 0X3F;
    // beq         $s0, $zero, L_80065540
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80065540;
    }
    // nop

    // jal         0x80065010
    // nop

    sub_80065010(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_80065540:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6280($v0)
    ctx->r2 = MEM_W(0X6280, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80065580
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80065580;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6274($v0)
    ctx->r2 = MEM_W(0X6274, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80065590
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80065590;
    }
    // nop

L_80065580:
    // bne         $s0, $zero, L_80065594
    if (ctx->r16 != 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80065594;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // j           L_80065594
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80065594;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80065590:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80065594:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
