#include "recomp.h"
#include "disable_warnings.h"

void sub_80027700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // lw          $v1, 0xC0($sp)
    ctx->r3 = MEM_W(0XC0, ctx->r29);
    // sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // lhu         $s2, 0x98($sp)
    ctx->r18 = MEM_HU(0X98, ctx->r29);
    // sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // lhu         $s5, 0x9C($sp)
    ctx->r21 = MEM_HU(0X9C, ctx->r29);
    // sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // lhu         $s6, 0xA0($sp)
    ctx->r22 = MEM_HU(0XA0, ctx->r29);
    // sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // lhu         $s7, 0xA4($sp)
    ctx->r23 = MEM_HU(0XA4, ctx->r29);
    // lhu         $t1, 0xAC($sp)
    ctx->r9 = MEM_HU(0XAC, ctx->r29);
    // sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // lhu         $fp, 0xA8($sp)
    ctx->r30 = MEM_HU(0XA8, ctx->r29);
    // sh          $t1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xB0($sp)
    ctx->r9 = MEM_HU(0XB0, ctx->r29);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xB4($sp)
    ctx->r9 = MEM_HU(0XB4, ctx->r29);
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // sh          $t1, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xB8($sp)
    ctx->r9 = MEM_HU(0XB8, ctx->r29);
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // sh          $t1, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xBC($sp)
    ctx->r9 = MEM_HU(0XBC, ctx->r29);
    // addu        $s4, $t0, $zero
    ctx->r20 = ADD32(ctx->r8, 0);
    // sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // sh          $t1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r9;
    // lhu         $t1, 0xC4($sp)
    ctx->r9 = MEM_HU(0XC4, ctx->r29);
    // andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // beq         $v0, $zero, L_80027790
    if (ctx->r2 == 0) {
        // sh          $t1, 0x58($sp)
        MEM_H(0X58, ctx->r29) = ctx->r9;
        goto L_80027790;
    }
    // sh          $t1, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r9;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_80027790:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // beq         $a3, $v0, L_800277C8
    if (ctx->r7 == ctx->r2) {
        // andi        $s1, $v1, 0x7FFF
        ctx->r17 = ctx->r3 & 0X7FFF;
        goto L_800277C8;
    }
    // andi        $s1, $v1, 0x7FFF
    ctx->r17 = ctx->r3 & 0X7FFF;
    // ori         $v0, $zero, 0x8001
    ctx->r2 = 0 | 0X8001;
    // bne         $a3, $v0, L_800277F0
    if (ctx->r7 != ctx->r2) {
        // nop
    
        goto L_800277F0;
    }
    // nop

    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a2, $a2, -0x4A60
    ctx->r6 = ADD32(ctx->r6, -0X4A60);
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(0X4, ctx->r8);
    // addiu       $v0, $v0, -0x6A4
    ctx->r2 = ADD32(ctx->r2, -0X6A4);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8002781C
    if (ctx->r3 != 0) {
        // lui         $v1, 0xFF67
        ctx->r3 = S32(0XFF67 << 16);
        goto L_8002781C;
    }
    // lui         $v1, 0xFF67
    ctx->r3 = S32(0XFF67 << 16);
L_800277C8:
    // ori         $v0, $zero, 0x6A4
    ctx->r2 = 0 | 0X6A4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a2, $a2, -0x4A64
    ctx->r6 = ADD32(ctx->r6, -0X4A64);
    // jal         0x80015B74
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    sub_80015B74(rdram, ctx);
    goto after_0;
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    after_0:
    // j           L_80027820
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    goto L_80027820;
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800277F0:
    // sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(0X0, ctx->r8);
    // lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(0X4, ctx->r8);
    // lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(0X8, ctx->r8);
    // jal         0x80027E20
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_80027E20(rdram, ctx);
    goto after_1;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_1:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80027824
    if (ctx->r3 != ctx->r2) {
        // slt         $v0, $v1, $s3
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
        goto L_80027824;
    }
    // slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // lui         $v1, 0xFF67
    ctx->r3 = S32(0XFF67 << 16);
L_8002781C:
    // ori         $v1, $v1, 0x6981
    ctx->r3 = ctx->r3 | 0X6981;
L_80027820:
    // slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
L_80027824:
    // bne         $v0, $zero, L_800278E8
    if (ctx->r2 != 0) {
        // andi        $a0, $s2, 0xFFFF
        ctx->r4 = ctx->r18 & 0XFFFF;
        goto L_800278E8;
    }
    // andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // ori         $a1, $zero, 0x1000
    ctx->r5 = 0 | 0X1000;
    // beq         $a0, $a1, L_80027890
    if (ctx->r4 == ctx->r5) {
        // sll         $v0, $v1, 12
        ctx->r2 = S32(ctx->r3) << 12;
        goto L_80027890;
    }
    // sll         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) << 12;
    // div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // bne         $s0, $zero, L_80027848
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80027848;
    }
    // nop

    // break       7
    do_break(2147645508);
L_80027848:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s0, $at, L_80027860
    if (ctx->r16 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80027860;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80027860
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80027860;
    }
    // nop

    // break       6
    do_break(2147645532);
L_80027860:
    // mflo        $v0
    ctx->r2 = lo;
    // subu        $v1, $a1, $a0
    ctx->r3 = SUB32(ctx->r5, ctx->r4);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_80027894
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    goto L_80027894;
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
L_80027890:
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80027894:
    // lhu         $t1, 0x30($sp)
    ctx->r9 = MEM_HU(0X30, ctx->r29);
    // nop

    // sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x38($sp)
    ctx->r9 = MEM_HU(0X38, ctx->r29);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x40($sp)
    ctx->r9 = MEM_HU(0X40, ctx->r29);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x48($sp)
    ctx->r9 = MEM_HU(0X48, ctx->r29);
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x50($sp)
    ctx->r9 = MEM_HU(0X50, ctx->r29);
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    // sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x58($sp)
    ctx->r9 = MEM_HU(0X58, ctx->r29);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // jal         0x80027344
    // sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    ApplyStatusEffect(rdram, ctx);
    goto after_2;
    // sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_2:
L_800278E8:
    // lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(0X84, ctx->r29);
    // lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(0X80, ctx->r29);
    // lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(0X7C, ctx->r29);
    // lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(0X78, ctx->r29);
    // lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(0X74, ctx->r29);
    // lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(0X70, ctx->r29);
    // lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(0X6C, ctx->r29);
    // lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(0X68, ctx->r29);
    // lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(0X64, ctx->r29);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // jr          $ra
    // nop

    return;
    // nop

;}
