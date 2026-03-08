#include "recomp.h"
#include "disable_warnings.h"

void PlayPositionalSound3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // addiu       $s5, $s5, -0x59C8
    ctx->r21 = ADD32(ctx->r21, -0X59C8);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(0X0, ctx->r21);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x59C4($v1)
    ctx->r3 = MEM_W(-0X59C4, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // lw          $v1, 0x8($s5)
    ctx->r3 = MEM_W(0X8, ctx->r21);
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // mflo        $a0
    ctx->r4 = lo;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // andi        $s7, $s4, 0x8000
    ctx->r23 = ctx->r20 & 0X8000;
    // andi        $s4, $s4, 0xFFF
    ctx->r20 = ctx->r20 & 0XFFF;
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x8005DBCC
    // addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    KF_SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    after_0:
    // sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2) << 3;
    // slt         $s0, $s3, $s0
    ctx->r16 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
    // beq         $s0, $zero, L_800142A4
    if (ctx->r16 == 0) {
        // subu        $v0, $s2, $s3
        ctx->r2 = SUB32(ctx->r18, ctx->r19);
        goto L_800142A4;
    }
    // subu        $v0, $s2, $s3
    ctx->r2 = SUB32(ctx->r18, ctx->r19);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // bne         $s2, $zero, L_8001423C
    if (ctx->r18 != 0) {
        // nop
    
        goto L_8001423C;
    }
    // nop

    // break       7
    do_break(2147566136);
L_8001423C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s2, $at, L_80014254
    if (ctx->r18 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80014254;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80014254
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80014254;
    }
    // nop

    // break       6
    do_break(2147566160);
L_80014254:
    // mflo        $s3
    ctx->r19 = lo;
    // nop

    // mult        $s3, $s6
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(0X0, ctx->r17);
    // lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(0X4, ctx->r17);
    // lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(0X8, ctx->r17);
    // mflo        $s0
    ctx->r16 = lo;
    // jal         0x8002D4A4
    // sra         $s2, $s0, 7
    ctx->r18 = S32(ctx->r16) >> 7;
    ResolveCurrentMetaTile(rdram, ctx);
    goto after_1;
    // sra         $s2, $s0, 7
    ctx->r18 = S32(ctx->r16) >> 7;
    after_1:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v1, -0x2A82($v1)
    ctx->r3 = MEM_HU(-0X2A82, ctx->r3);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x59B8($v0)
    ctx->r2 = MEM_HU(-0X59B8, ctx->r2);
    // nop

    // beq         $v1, $v0, L_8001429C
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $s2, 0x14
        ctx->r2 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
        goto L_8001429C;
    }
    // slti        $v0, $s2, 0x14
    ctx->r2 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // sra         $s2, $s0, 8
    ctx->r18 = S32(ctx->r16) >> 8;
    // slti        $v0, $s2, 0x14
    ctx->r2 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
L_8001429C:
    // beq         $v0, $zero, L_800142AC
    if (ctx->r2 == 0) {
        // slti        $v0, $s2, 0x80
        ctx->r2 = SIGNED(ctx->r18) < 0X80 ? 1 : 0;
        goto L_800142AC;
    }
    // slti        $v0, $s2, 0x80
    ctx->r2 = SIGNED(ctx->r18) < 0X80 ? 1 : 0;
L_800142A4:
    // j           L_800143B0
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_800143B0;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800142AC:
    // bne         $v0, $zero, L_800142B8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800142B8;
    }
    // nop

    // ori         $s2, $zero, 0x7F
    ctx->r18 = 0 | 0X7F;
L_800142B8:
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(0X0, ctx->r21);
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // lw          $a1, 0x8($s5)
    ctx->r5 = MEM_W(0X8, ctx->r21);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x80015804
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    Math_Atan2_Fixed(rdram, ctx);
    goto after_2;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_2:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x59B4($v1)
    ctx->r3 = MEM_H(-0X59B4, ctx->r3);
    // nop

    // addiu       $v1, $v1, -0x400
    ctx->r3 = ADD32(ctx->r3, -0X400);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $s0, $v0, 0xFFF
    ctx->r16 = ctx->r2 & 0XFFF;
    // slti        $v0, $s0, 0x800
    ctx->r2 = SIGNED(ctx->r16) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_80014304
    if (ctx->r2 != 0) {
        // slti        $v0, $s3, 0x40
        ctx->r2 = SIGNED(ctx->r19) < 0X40 ? 1 : 0;
        goto L_80014304;
    }
    // slti        $v0, $s3, 0x40
    ctx->r2 = SIGNED(ctx->r19) < 0X40 ? 1 : 0;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // subu        $s0, $v0, $s0
    ctx->r16 = SUB32(ctx->r2, ctx->r16);
    // slti        $v0, $s3, 0x40
    ctx->r2 = SIGNED(ctx->r19) < 0X40 ? 1 : 0;
L_80014304:
    // bne         $v0, $zero, L_80014330
    if (ctx->r2 != 0) {
        // sra         $s0, $s0, 1
        ctx->r16 = S32(ctx->r16) >> 1;
        goto L_80014330;
    }
    // sra         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16) >> 1;
    // bne         $s7, $zero, L_80014330
    if (ctx->r23 != 0) {
        // addiu       $a0, $s0, -0x200
        ctx->r4 = ADD32(ctx->r16, -0X200);
        goto L_80014330;
    }
    // addiu       $a0, $s0, -0x200
    ctx->r4 = ADD32(ctx->r16, -0X200);
    // sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19) << 1;
    // ori         $v0, $zero, 0x100
    ctx->r2 = 0 | 0X100;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // addiu       $s0, $v0, 0x200
    ctx->r16 = ADD32(ctx->r2, 0X200);
L_80014330:
    // jal         0x800601F4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    FixedSin(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // mult        $s2, $v0
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $s3, 0x1346
    ctx->r19 = S32(0X1346 << 16);
    // ori         $s3, $s3, 0x79AD
    ctx->r19 = ctx->r19 | 0X79AD;
    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // sra         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) >> 8;
    // subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // slti        $v0, $s1, 0x80
    ctx->r2 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8001436C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001436C;
    }
    // nop

    // ori         $s1, $zero, 0x7F
    ctx->r17 = 0 | 0X7F;
L_8001436C:
    // jal         0x800602D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    FixedCos(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // mult        $s2, $v0
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // sra         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) >> 8;
    // subu        $a2, $v1, $v0
    ctx->r6 = SUB32(ctx->r3, ctx->r2);
    // slti        $v0, $a2, 0x80
    ctx->r2 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_800143A0
    if (ctx->r2 != 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_800143A0;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // ori         $a2, $zero, 0x7F
    ctx->r6 = 0 | 0X7F;
L_800143A0:
    // lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(0X4C, ctx->r29);
    // jal         0x80014710
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    PlayAudioStream(rdram, ctx);
    goto after_5;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_800143B0:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
