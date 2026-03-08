#include "recomp.h"
#include "disable_warnings.h"

void sub_8002536C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x2E0
    ctx->r29 = ADD32(ctx->r29, -0X2E0);
    // sw          $s3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x2CC($sp)
    MEM_W(0X2CC, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x2D0($sp)
    MEM_W(0X2D0, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x2D8($sp)
    MEM_W(0X2D8, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x2DC($sp)
    MEM_W(0X2DC, ctx->r29) = ctx->r31;
    // sw          $s0, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = ctx->r16;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x121C
    ctx->r5 = ADD32(ctx->r5, 0X121C);
    // lwl         $v0, 0x3($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r5);
    // lwr         $v0, 0x0($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r5);
    // lb          $v1, 0x4($a1)
    ctx->r3 = MEM_B(0X4, ctx->r5);
    // lb          $a0, 0x5($a1)
    ctx->r4 = MEM_B(0X5, ctx->r5);
    // swl         $v0, 0x293($sp)
    do_swl(rdram, 0X293, ctx->r29, ctx->r2);
    // swr         $v0, 0x290($sp)
    do_swr(rdram, 0X290, ctx->r29, ctx->r2);
    // sb          $v1, 0x294($sp)
    MEM_B(0X294, ctx->r29) = ctx->r3;
    // sb          $a0, 0x295($sp)
    MEM_B(0X295, ctx->r29) = ctx->r4;
    // addiu       $a0, $sp, 0x296
    ctx->r4 = ADD32(ctx->r29, 0X296);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80062B80
    // ori         $a2, $zero, 0x22
    ctx->r6 = 0 | 0X22;
    memset_recomp(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0x22
    ctx->r6 = 0 | 0X22;
    after_0:
    // lb          $v0, 0x80($gp)
    ctx->r2 = MEM_B(0X80, ctx->r28);
    // lb          $v1, 0x81($gp)
    ctx->r3 = MEM_B(0X81, ctx->r28);
    // sb          $v0, 0x2B8($sp)
    MEM_B(0X2B8, ctx->r29) = ctx->r2;
    // sb          $v1, 0x2B9($sp)
    MEM_B(0X2B9, ctx->r29) = ctx->r3;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x1F58
    ctx->r5 = ADD32(ctx->r5, -0X1F58);
    // ori         $a2, $zero, 0xC
    ctx->r6 = 0 | 0XC;
    // jal         0x80062BE0
    // addiu       $s0, $sp, 0x290
    ctx->r16 = ADD32(ctx->r29, 0X290);
    KF_strncmp(rdram, ctx);
    goto after_1;
    // addiu       $s0, $sp, 0x290
    ctx->r16 = ADD32(ctx->r29, 0X290);
    after_1:
    // bne         $v0, $zero, L_8002558C
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8002558C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80062B90
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    strcat_recomp(rdram, ctx);
    goto after_2;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_2:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80062B10
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    open(rdram, ctx);
    goto after_3;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_3:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80025440
    if (ctx->r16 == ctx->r2) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80025440;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x80062AC0
    // ori         $a2, $zero, 0x280
    ctx->r6 = 0 | 0X280;
    read(rdram, ctx);
    goto after_4;
    // ori         $a2, $zero, 0x280
    ctx->r6 = 0 | 0X280;
    after_4:
    // ori         $v1, $zero, 0x280
    ctx->r3 = 0 | 0X280;
    // beq         $v0, $v1, L_80025448
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80025448;
    }
    // nop

L_80025440:
    // j           L_8002558C
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_8002558C;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80025448:
    // jal         0x80062850
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_5;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // ori         $a3, $a3, 0x86A0
    ctx->r7 = ctx->r7 | 0X86A0;
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $t3, $sp, 0x10
    ctx->r11 = ADD32(ctx->r29, 0X10);
    // ori         $t4, $zero, 0x4081
    ctx->r12 = 0 | 0X4081;
    // lui         $t2, 0x6666
    ctx->r10 = S32(0X6666 << 16);
    // ori         $t2, $t2, 0x6667
    ctx->r10 = ctx->r10 | 0X6667;
    // ori         $t1, $zero, 0x2C
    ctx->r9 = 0 | 0X2C;
    // addu        $v0, $t3, $t1
    ctx->r2 = ADD32(ctx->r11, ctx->r9);
L_80025478:
    // lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(0X0, ctx->r2);
    // lb          $a0, 0x1($v0)
    ctx->r4 = MEM_B(0X1, ctx->r2);
    // sb          $v1, 0x2C0($sp)
    MEM_B(0X2C0, ctx->r29) = ctx->r3;
    // sb          $a0, 0x2C1($sp)
    MEM_B(0X2C1, ctx->r29) = ctx->r4;
    // lhu         $v0, 0x2C0($sp)
    ctx->r2 = MEM_HU(0X2C0, ctx->r29);
    // nop

    // sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) << 16;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // beq         $v0, $t4, L_800254C0
    if (ctx->r2 == ctx->r12) {
        // addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
        goto L_800254C0;
    }
    // addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // sra         $v0, $v1, 24
    ctx->r2 = S32(ctx->r3) >> 24;
    // addiu       $v0, $v0, -0x4F
    ctx->r2 = ADD32(ctx->r2, -0X4F);
    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $v0, 0x2C0($sp)
    MEM_H(0X2C0, ctx->r29) = ctx->r2;
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_800254C0:
    // mult        $a3, $t2
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // sra         $v1, $a3, 31
    ctx->r3 = S32(ctx->r7) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $t0, 0x6
    ctx->r2 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_80025478
    if (ctx->r2 != 0) {
        // addu        $v0, $t3, $t1
        ctx->r2 = ADD32(ctx->r11, ctx->r9);
        goto L_80025478;
    }
    // addu        $v0, $t3, $t1
    ctx->r2 = ADD32(ctx->r11, ctx->r9);
    // sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $t3, $sp, 0x10
    ctx->r11 = ADD32(ctx->r29, 0X10);
    // ori         $t4, $zero, 0x4081
    ctx->r12 = 0 | 0X4081;
    // lui         $t2, 0x6666
    ctx->r10 = S32(0X6666 << 16);
    // ori         $t2, $t2, 0x6667
    ctx->r10 = ctx->r10 | 0X6667;
    // ori         $t1, $zero, 0x3E
    ctx->r9 = 0 | 0X3E;
    // addu        $v0, $t3, $t1
    ctx->r2 = ADD32(ctx->r11, ctx->r9);
L_80025508:
    // lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(0X0, ctx->r2);
    // lb          $a0, 0x1($v0)
    ctx->r4 = MEM_B(0X1, ctx->r2);
    // sb          $v1, 0x2C0($sp)
    MEM_B(0X2C0, ctx->r29) = ctx->r3;
    // sb          $a0, 0x2C1($sp)
    MEM_B(0X2C1, ctx->r29) = ctx->r4;
    // lhu         $v0, 0x2C0($sp)
    ctx->r2 = MEM_HU(0X2C0, ctx->r29);
    // nop

    // sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) << 16;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // beq         $v0, $t4, L_80025550
    if (ctx->r2 == ctx->r12) {
        // addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
        goto L_80025550;
    }
    // addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // sra         $v0, $v1, 24
    ctx->r2 = S32(ctx->r3) >> 24;
    // addiu       $v0, $v0, -0x4F
    ctx->r2 = ADD32(ctx->r2, -0X4F);
    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $v0, 0x2C0($sp)
    MEM_H(0X2C0, ctx->r29) = ctx->r2;
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_80025550:
    // mult        $a3, $t2
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // sra         $v1, $a3, 31
    ctx->r3 = S32(ctx->r7) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $t0, 0x2
    ctx->r2 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80025508
    if (ctx->r2 != 0) {
        // addu        $v0, $t3, $t1
        ctx->r2 = ADD32(ctx->r11, ctx->r9);
        goto L_80025508;
    }
    // addu        $v0, $t3, $t1
    ctx->r2 = ADD32(ctx->r11, ctx->r9);
    // lbu         $v0, 0xC($s3)
    ctx->r2 = MEM_BU(0XC, ctx->r19);
    // addiu       $a0, $sp, 0x2B8
    ctx->r4 = ADD32(ctx->r29, 0X2B8);
    // jal         0x80062C00
    // sb          $v0, 0x2B8($sp)
    MEM_B(0X2B8, ctx->r29) = ctx->r2;
    KF_atoi(rdram, ctx);
    goto after_6;
    // sb          $v0, 0x2B8($sp)
    MEM_B(0X2B8, ctx->r29) = ctx->r2;
    after_6:
    // sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002558C:
    // lw          $ra, 0x2DC($sp)
    ctx->r31 = MEM_W(0X2DC, ctx->r29);
    // lw          $s4, 0x2D8($sp)
    ctx->r20 = MEM_W(0X2D8, ctx->r29);
    // lw          $s3, 0x2D4($sp)
    ctx->r19 = MEM_W(0X2D4, ctx->r29);
    // lw          $s2, 0x2D0($sp)
    ctx->r18 = MEM_W(0X2D0, ctx->r29);
    // lw          $s1, 0x2CC($sp)
    ctx->r17 = MEM_W(0X2CC, ctx->r29);
    // lw          $s0, 0x2C8($sp)
    ctx->r16 = MEM_W(0X2C8, ctx->r29);
    // addiu       $sp, $sp, 0x2E0
    ctx->r29 = ADD32(ctx->r29, 0X2E0);
    // jr          $ra
    // nop

    return;
    // nop

;}
