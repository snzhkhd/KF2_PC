#include "recomp.h"
#include "disable_warnings.h"

void sub_8002AF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x49FA($v1)
    ctx->r3 = MEM_HU(-0X49FA, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F4($v0)
    ctx->r2 = MEM_W(0X62F4, ctx->r2);
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // beq         $v0, $zero, L_8002AF9C
    if (ctx->r2 == 0) {
        // sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
        goto L_8002AF9C;
    }
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F4($v0)
    ctx->r2 = MEM_W(-0X49F4, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A10($v1)
    ctx->r3 = MEM_HU(-0X4A10, ctx->r3);
    // sra         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) >> 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8002AFE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002AFE8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F4($v0)
    ctx->r2 = MEM_HU(-0X49F4, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A10($at)
    MEM_H(-0X4A10, ctx->r1) = ctx->r2;
    // j           L_8002B094
    // nop

    goto L_8002B094;
    // nop

L_8002AF9C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F8($v0)
    ctx->r2 = MEM_W(0X62F8, ctx->r2);
    // nop

    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // beq         $v0, $zero, L_8002B018
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B018;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F4($v0)
    ctx->r2 = MEM_W(-0X49F4, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A10($v1)
    ctx->r3 = MEM_HU(-0X4A10, ctx->r3);
    // sra         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) >> 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8002AFF8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002AFF8;
    }
    // nop

L_8002AFE8:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x4A10($at)
    MEM_H(-0X4A10, ctx->r1) = ctx->r4;
    // j           L_8002B094
    // nop

    goto L_8002B094;
    // nop

L_8002AFF8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F4($v0)
    ctx->r2 = MEM_HU(-0X49F4, ctx->r2);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A10($at)
    MEM_H(-0X4A10, ctx->r1) = ctx->r2;
    // j           L_8002B094
    // nop

    goto L_8002B094;
    // nop

L_8002B018:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A10($v0)
    ctx->r2 = MEM_H(-0X4A10, ctx->r2);
    // nop

    // blez        $v0, L_8002B05C
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002B05C;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F4($v0)
    ctx->r2 = MEM_W(-0X49F4, ctx->r2);
    // nop

    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A10($at)
    MEM_H(-0X4A10, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bltz        $v0, L_8002B08C
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8002B08C;
    }
    // nop

    // j           L_8002B094
    // nop

    goto L_8002B094;
    // nop

L_8002B05C:
    // bgez        $v0, L_8002B094
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8002B094;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F4($v0)
    ctx->r2 = MEM_W(-0X49F4, ctx->r2);
    // nop

    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A10($at)
    MEM_H(-0X4A10, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_8002B094
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8002B094;
    }
    // nop

L_8002B08C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A10($at)
    MEM_H(-0X4A10, ctx->r1) = 0;
L_8002B094:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x49FA($v1)
    ctx->r3 = MEM_HU(-0X49FA, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E4($v0)
    ctx->r2 = MEM_W(0X62E4, ctx->r2);
    // nop

    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // beq         $v0, $zero, L_8002B100
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B100;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F4($v0)
    ctx->r2 = MEM_W(-0X49F4, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A12($v1)
    ctx->r3 = MEM_HU(-0X4A12, ctx->r3);
    // sra         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) >> 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8002B14C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B14C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F4($v0)
    ctx->r2 = MEM_HU(-0X49F4, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A12($at)
    MEM_H(-0X4A12, ctx->r1) = ctx->r2;
    // j           L_8002B1F8
    // nop

    goto L_8002B1F8;
    // nop

L_8002B100:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62EC($v0)
    ctx->r2 = MEM_W(0X62EC, ctx->r2);
    // nop

    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // beq         $v0, $zero, L_8002B17C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002B17C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F4($v0)
    ctx->r2 = MEM_W(-0X49F4, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v1, -0x4A12($v1)
    ctx->r3 = MEM_HU(-0X4A12, ctx->r3);
    // sra         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) >> 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8002B15C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002B15C;
    }
    // nop

L_8002B14C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $s2, -0x4A12($at)
    MEM_H(-0X4A12, ctx->r1) = ctx->r18;
    // j           L_8002B1F8
    // nop

    goto L_8002B1F8;
    // nop

L_8002B15C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F4($v0)
    ctx->r2 = MEM_HU(-0X49F4, ctx->r2);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A12($at)
    MEM_H(-0X4A12, ctx->r1) = ctx->r2;
    // j           L_8002B1F8
    // nop

    goto L_8002B1F8;
    // nop

L_8002B17C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A12($v0)
    ctx->r2 = MEM_H(-0X4A12, ctx->r2);
    // nop

    // blez        $v0, L_8002B1C0
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8002B1C0;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F4($v0)
    ctx->r2 = MEM_W(-0X49F4, ctx->r2);
    // nop

    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A12($at)
    MEM_H(-0X4A12, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bltz        $v0, L_8002B1F0
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8002B1F0;
    }
    // nop

    // j           L_8002B1F8
    // nop

    goto L_8002B1F8;
    // nop

L_8002B1C0:
    // bgez        $v0, L_8002B1F8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8002B1F8;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x49F4($v0)
    ctx->r2 = MEM_W(-0X49F4, ctx->r2);
    // nop

    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A12($at)
    MEM_H(-0X4A12, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_8002B1F8
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8002B1F8;
    }
    // nop

L_8002B1F0:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A12($at)
    MEM_H(-0X4A12, ctx->r1) = 0;
L_8002B1F8:
    // lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // addiu       $s3, $s3, -0x4A12
    ctx->r19 = ADD32(ctx->r19, -0X4A12);
    // lh          $s0, 0x0($s3)
    ctx->r16 = MEM_H(0X0, ctx->r19);
    // nop

    // mult        $s0, $s0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $s0
    ctx->r16 = lo;
    // lh          $s1, 0x2($s3)
    ctx->r17 = MEM_H(0X2, ctx->r19);
    // nop

    // mult        $s1, $s1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $s1
    ctx->r17 = lo;
    // jal         0x8005DBCC
    // addu        $a0, $s0, $s1
    ctx->r4 = ADD32(ctx->r16, ctx->r17);
    KF_SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $s1
    ctx->r4 = ADD32(ctx->r16, ctx->r17);
    after_0:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bne         $v1, $zero, L_8002B240
    if (ctx->r3 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8002B240;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // j           L_8002B2C0
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    goto L_8002B2C0;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_8002B240:
    // div         $zero, $s0, $v1
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8002B250
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002B250;
    }
    // nop

    // break       7
    do_break(2147660364);
L_8002B250:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8002B268
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002B268;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $s0, $at, L_8002B268
    if (ctx->r16 != ctx->r1) {
        // nop
    
        goto L_8002B268;
    }
    // nop

    // break       6
    do_break(2147660388);
L_8002B268:
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(0X0, ctx->r19);
    // nop

    // bgez        $v0, L_8002B280
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $s2, $a0, $zero
        ctx->r18 = ADD32(ctx->r4, 0);
        goto L_8002B280;
    }
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // negu        $s2, $a0
    ctx->r18 = SUB32(0, ctx->r4);
L_8002B280:
    // div         $zero, $s1, $v1
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8002B290
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002B290;
    }
    // nop

    // break       7
    do_break(2147660428);
L_8002B290:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8002B2A8
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002B2A8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $s1, $at, L_8002B2A8
    if (ctx->r17 != ctx->r1) {
        // nop
    
        goto L_8002B2A8;
    }
    // nop

    // break       6
    do_break(2147660452);
L_8002B2A8:
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x2($s3)
    ctx->r2 = MEM_H(0X2, ctx->r19);
    // nop

    // bgez        $v0, L_8002B2C0
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_8002B2C0;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
L_8002B2C0:
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // mult        $s0, $s0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005DBCC
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    KF_SquareRoot0(rdram, ctx);
    goto after_1;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_1:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A0E($at)
    MEM_H(-0X4A0E, ctx->r1) = ctx->r2;
    // bltz        $s0, L_8002B308
    if (SIGNED(ctx->r16) < 0) {
        // addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
        goto L_8002B308;
    }
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4A42($a0)
    ctx->r4 = MEM_H(-0X4A42, ctx->r4);
    // j           L_8002B31C
    // nop

    goto L_8002B31C;
    // nop

L_8002B308:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4A42($a0)
    ctx->r4 = MEM_H(-0X4A42, ctx->r4);
    // negu        $a1, $s0
    ctx->r5 = SUB32(0, ctx->r16);
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
L_8002B31C:
    // jal         0x80029F08
    // nop

    sub_80029F08(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // blez        $a1, L_8002B344
    if (SIGNED(ctx->r5) <= 0) {
        // nop
    
        goto L_8002B344;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4A42($a0)
    ctx->r4 = MEM_H(-0X4A42, ctx->r4);
    // j           L_8002B35C
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    goto L_8002B35C;
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
L_8002B344:
    // bgez        $a1, L_8002B36C
    if (SIGNED(ctx->r5) >= 0) {
        // negu        $a1, $a1
        ctx->r5 = SUB32(0, ctx->r5);
        goto L_8002B36C;
    }
    // negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x4A42($a0)
    ctx->r4 = MEM_H(-0X4A42, ctx->r4);
    // nop

    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
L_8002B35C:
    // jal         0x80029F08
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    sub_80029F08(rdram, ctx);
    goto after_3;
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    after_3:
    // j           L_8002B37C
    // nop

    goto L_8002B37C;
    // nop

L_8002B36C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A50($at)
    MEM_H(-0X4A50, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A54($at)
    MEM_H(-0X4A54, ctx->r1) = 0;
L_8002B37C:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
