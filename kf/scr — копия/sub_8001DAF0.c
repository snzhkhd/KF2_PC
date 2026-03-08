#include "recomp.h"
#include "disable_warnings.h"

void sub_8001DAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // sw          $s2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // ori         $s0, $zero, 0x9
    ctx->r16 = 0 | 0X9;
    // sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
L_8001DB10:
    // jal         0x800250A8
    // nop

    MemCard_CheckSlot(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8001DC00
    if (ctx->r3 == 0) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8001DC00;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s1, L_8001DB10
    if (ctx->r16 != ctx->r17) {
        // nop
    
        goto L_8001DB10;
    }
    // nop

    // ori         $s0, $zero, 0x2
    ctx->r16 = 0 | 0X2;
    // beq         $v1, $s0, L_8001DB8C
    if (ctx->r3 == ctx->r16) {
        // nop
    
        goto L_8001DB8C;
    }
    // nop

    // jal         0x8001E2B8
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    sub_8001E2B8(rdram, ctx);
    goto after_1;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_1:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // ori         $a2, $zero, 0x38
    ctx->r6 = 0 | 0X38;
    // ori         $a3, $zero, 0x50
    ctx->r7 = 0 | 0X50;
    // ori         $v0, $zero, 0xCE
    ctx->r2 = 0 | 0XCE;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x50
    ctx->r2 = 0 | 0X50;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // jal         0x8001EDE0
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8001EDE0(rdram, ctx);
    goto after_2;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_2:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_8001DB74:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_4:
    // beq         $v0, $zero, L_8001DB74
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001DB74;
    }
    // nop

    // j           L_8001DCAC
    // nop

    goto L_8001DCAC;
    // nop

L_8001DB8C:
    // jal         0x8001DCD0
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_8001DCD0(rdram, ctx);
    goto after_5;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_5:
    // bne         $v0, $zero, L_8001DBAC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001DBAC;
    }
    // nop

    // jal         0x800255B0
    // nop

    sub_800255B0(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_8001DC00
    // nop

    goto L_8001DC00;
    // nop

L_8001DBAC:
    // jal         0x8001E480
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    sub_8001E480(rdram, ctx);
    goto after_7;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_7:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // ori         $a2, $zero, 0x38
    ctx->r6 = 0 | 0X38;
    // ori         $a3, $zero, 0x50
    ctx->r7 = 0 | 0X50;
    // ori         $v0, $zero, 0xCE
    ctx->r2 = 0 | 0XCE;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x50
    ctx->r2 = 0 | 0X50;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // jal         0x8001EDE0
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8001EDE0(rdram, ctx);
    goto after_8;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_8:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_9;
    // nop

    after_9:
L_8001DBE8:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_10;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_10:
    // beq         $v0, $zero, L_8001DBE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001DBE8;
    }
    // nop

    // j           L_8001DCAC
    // nop

    goto L_8001DCAC;
    // nop

L_8001DC00:
    // jal         0x8001E810
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    sub_8001E810(rdram, ctx);
    goto after_11;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_11:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // ori         $a2, $zero, 0x38
    ctx->r6 = 0 | 0X38;
    // ori         $a3, $zero, 0x57
    ctx->r7 = 0 | 0X57;
    // ori         $s0, $zero, 0xCE
    ctx->r16 = 0 | 0XCE;
    // ori         $v0, $zero, 0x42
    ctx->r2 = 0 | 0X42;
    // ori         $s1, $zero, 0x2
    ctx->r17 = 0 | 0X2;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // jal         0x8001EDE0
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8001EDE0(rdram, ctx);
    goto after_12;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_12:
    // jal         0x80025700
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80025700(rdram, ctx);
    goto after_13;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_13:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8001DCB4
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8001DCB4;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8001DC64
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8001DC64;
    }
    // nop

    // jal         0x8001E2B8
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    sub_8001E2B8(rdram, ctx);
    goto after_14;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_14:
    // j           L_8001DC70
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    goto L_8001DC70;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_8001DC64:
    // jal         0x8001E648
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    sub_8001E648(rdram, ctx);
    goto after_15;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_15:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_8001DC70:
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // ori         $a2, $zero, 0x38
    ctx->r6 = 0 | 0X38;
    // ori         $a3, $zero, 0x50
    ctx->r7 = 0 | 0X50;
    // ori         $v0, $zero, 0x50
    ctx->r2 = 0 | 0X50;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // jal         0x8001EDE0
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    sub_8001EDE0(rdram, ctx);
    goto after_16;
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_16:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_17;
    // nop

    after_17:
L_8001DC9C:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_18;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_18:
    // beq         $v0, $zero, L_8001DC9C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001DC9C;
    }
    // nop

L_8001DCAC:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_19;
    // nop

    after_19:
L_8001DCB4:
    // lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(0X9C, ctx->r29);
    // lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(0X98, ctx->r29);
    // lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(0X94, ctx->r29);
    // lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(0X90, ctx->r29);
    // addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // jr          $ra
    // nop

    return;
    // nop

;}
