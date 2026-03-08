#include "recomp.h"
#include "disable_warnings.h"

void sub_8005C7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2570($v0)
    ctx->r2 = MEM_W(-0X2570, ctx->r2);
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // beq         $v0, $v1, L_8005CA10
    if (ctx->r2 == ctx->r3) {
        // sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
        goto L_8005CA10;
    }
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v1, -0x2570($at)
    MEM_W(-0X2570, ctx->r1) = ctx->r3;
    // jal         0x800570D0
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    sub_800570D0(rdram, ctx);
    goto after_0;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    after_0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lh          $v0, -0x19C8($v0)
    ctx->r2 = MEM_H(-0X19C8, ctx->r2);
    // nop

    // blez        $v0, L_8005CA08
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8005CA08;
    }
    // nop

    // lui         $s4, 0x801E
    ctx->r20 = S32(0X801E << 16);
    // addiu       $s4, $s4, -0x2248
    ctx->r20 = ADD32(ctx->r20, -0X2248);
L_8005C850:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x1938($v1)
    ctx->r3 = MEM_W(-0X1938, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $v0, $v0, $s2
    ctx->r2 = S32(ctx->r2) << (ctx->r18 & 31);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8005C9F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C9F0;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lh          $v0, -0x19C0($v0)
    ctx->r2 = MEM_H(-0X19C0, ctx->r2);
    // nop

    // blez        $v0, L_8005C9F0
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8005C9F0;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $s3, $s4, $zero
    ctx->r19 = ADD32(ctx->r20, 0);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8005C888:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(0X90, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8005C950
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8005C950;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8005D34C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005D34C(rdram, ctx);
    goto after_1;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(0X90, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8005C8D8
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8005C8D8;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8005D538
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005D538(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_8005C8D8:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(0X90, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_8005C900
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8005C900;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8005CD18
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005CD18(rdram, ctx);
    goto after_3;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
L_8005C900:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(0X90, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8005C928
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8005C928;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8005CB30
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005CB30(rdram, ctx);
    goto after_4;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
L_8005C928:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(0X90, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8005C950
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8005C950;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8005CB30
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005CB30(rdram, ctx);
    goto after_5;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
L_8005C950:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(0X90, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_8005C978
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8005C978;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8005CA30
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005CA30(rdram, ctx);
    goto after_6;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
L_8005C978:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(0X90, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_8005C9A0
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8005C9A0;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8005CFA8
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005CFA8(rdram, ctx);
    goto after_7;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_7:
L_8005C9A0:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(0X90, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_8005C9D8
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8005C9D8;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8005C634
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8005C634(rdram, ctx);
    goto after_8;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_8:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sw          $zero, 0x90($v0)
    MEM_W(0X90, ctx->r2) = 0;
L_8005C9D8:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lh          $v0, -0x19C0($v0)
    ctx->r2 = MEM_H(-0X19C0, ctx->r2);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005C888
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0xAC
        ctx->r17 = ADD32(ctx->r17, 0XAC);
        goto L_8005C888;
    }
    // addiu       $s1, $s1, 0xAC
    ctx->r17 = ADD32(ctx->r17, 0XAC);
L_8005C9F0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lh          $v0, -0x19C8($v0)
    ctx->r2 = MEM_H(-0X19C8, ctx->r2);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005C850
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
        goto L_8005C850;
    }
    // addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_8005CA08:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $zero, -0x2570($at)
    MEM_W(-0X2570, ctx->r1) = 0;
L_8005CA10:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
