#include "recomp.h"
#include "disable_warnings.h"

void sub_80044EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // lw          $s3, 0x1184($s3)
    ctx->r19 = MEM_W(0X1184, ctx->r19);
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // jal         0x80062BF0
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    rand_recomp(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // lh          $a0, 0x34($s3)
    ctx->r4 = MEM_H(0X34, ctx->r19);
    // lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(0X14, ctx->r19);
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // lh          $a0, 0x36($s3)
    ctx->r4 = MEM_H(0X36, ctx->r19);
    // lw          $v1, 0x18($s3)
    ctx->r3 = MEM_W(0X18, ctx->r19);
    // div         $zero, $v0, $s1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r17)));
    // bne         $s1, $zero, L_80044F30
    if (ctx->r17 != 0) {
        // nop
    
        goto L_80044F30;
    }
    // nop

    // break       7
    do_break(2147766060);
L_80044F30:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s1, $at, L_80044F48
    if (ctx->r17 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80044F48;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80044F48
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80044F48;
    }
    // nop

    // break       6
    do_break(2147766084);
L_80044F48:
    // mflo        $s5
    ctx->r21 = lo;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // lh          $v1, 0x38($s3)
    ctx->r3 = MEM_H(0X38, ctx->r19);
    // lw          $v0, 0x1C($s3)
    ctx->r2 = MEM_W(0X1C, ctx->r19);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // sh          $s0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r16;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_80044FEC
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_80044FEC;
    }
    // nop

L_80044F78:
    // jal         0x800602D0
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    FixedCos(rdram, ctx);
    goto after_1;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // jal         0x800601F4
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    FixedSin(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    after_2:
    // mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $s2, $s2, $s5
    ctx->r18 = ADD32(ctx->r18, ctx->r21);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, 0x1188($v1)
    ctx->r3 = MEM_W(0X1188, ctx->r3);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s3)
    ctx->r5 = MEM_BU(0X0, ctx->r19);
    // addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // jal         0x80042D2C
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    SpawnParticleEntity(rdram, ctx);
    goto after_3;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_3:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_80044F78
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_80044F78;
    }
    // nop

L_80044FEC:
    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
    // lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(0X50, ctx->r29);
    // lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(0X4C, ctx->r29);
    // lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
