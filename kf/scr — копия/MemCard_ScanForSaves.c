#include "recomp.h"
#include "disable_warnings.h"

void MemCard_ScanForSaves(uint8_t* rdram, recomp_context* ctx) 
{
    printf("MemCard_ScanForSaves bypassed\n");
    // a1 = &g_KF_SaveCount Ч пишем по указателю
    uint32_t count_ptr = ctx->r5;
    WRITE_W(count_ptr, 1);  // g_KF_SaveCount = 1, чтобы выйти из while
    ctx->r2 = 0; 

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x288
//    ctx->r29 = ADD32(ctx->r29, -0X288);
//    // sw          $s0, 0x270($sp)
//    MEM_W(0X270, ctx->r29) = ctx->r16;
//    // addu        $s0, $a0, $zero
//    ctx->r16 = ADD32(ctx->r4, 0);
//    // sw          $s1, 0x274($sp)
//    MEM_W(0X274, ctx->r29) = ctx->r17;
//    // addu        $s1, $a1, $zero
//    ctx->r17 = ADD32(ctx->r5, 0);
//    // sw          $s4, 0x280($sp)
//    MEM_W(0X280, ctx->r29) = ctx->r20;
//    // addu        $s4, $zero, $zero
//    ctx->r20 = ADD32(0, 0);
//    // sw          $ra, 0x284($sp)
//    MEM_W(0X284, ctx->r29) = ctx->r31;
//    // sw          $s3, 0x27C($sp)
//    MEM_W(0X27C, ctx->r29) = ctx->r19;
//    // sw          $s2, 0x278($sp)
//    MEM_W(0X278, ctx->r29) = ctx->r18;
//    // lb          $v0, 0x80($gp)
//    ctx->r2 = MEM_B(0X80, ctx->r28);
//    // lb          $v1, 0x81($gp)
//    ctx->r3 = MEM_B(0X81, ctx->r28);
//    // sb          $v0, 0x268($sp)
//    MEM_B(0X268, ctx->r29) = ctx->r2;
//    // sb          $v1, 0x269($sp)
//    MEM_B(0X269, ctx->r29) = ctx->r3;
//    // addu        $s3, $s0, $zero
//    ctx->r19 = ADD32(ctx->r16, 0);
//    // addu        $a0, $s3, $zero
//    ctx->r4 = ADD32(ctx->r19, 0);
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    // jal         0x80062B80
//    // ori         $a2, $zero, 0x258
//    ctx->r6 = 0 | 0X258;
//    memset_recomp(rdram, ctx);
//    goto after_0;
//    // ori         $a2, $zero, 0x258
//    ctx->r6 = 0 | 0X258;
//    after_0:
//    // lui         $a0, 0x8007
//    ctx->r4 = S32(0X8007 << 16);
//    // addiu       $a0, $a0, 0x6344
//    ctx->r4 = ADD32(ctx->r4, 0X6344);
//    // addu        $a1, $s3, $zero
//    ctx->r5 = ADD32(ctx->r19, 0);
//    // jal         0x80062B30
//    // sw          $zero, 0x0($s1)
//    MEM_W(0X0, ctx->r17) = 0;
//    firstfile2(rdram, ctx);
//    goto after_1;
//    // sw          $zero, 0x0($s1)
//    MEM_W(0X0, ctx->r17) = 0;
//    after_1:
//    // bne         $v0, $s3, L_80025240
//    if (ctx->r2 != ctx->r19) {
//        // addu        $a0, $s0, $zero
//        ctx->r4 = ADD32(ctx->r16, 0);
//        goto L_80025240;
//    }
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//L_80025200:
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // addiu       $a1, $a1, -0x1F58
//    ctx->r5 = ADD32(ctx->r5, -0X1F58);
//    // lw          $v0, 0x18($s0)
//    ctx->r2 = MEM_W(0X18, ctx->r16);
//    // ori         $a2, $zero, 0xC
//    ctx->r6 = 0 | 0XC;
//    // jal         0x80062BE0
//    // addu        $s4, $s4, $v0
//    ctx->r20 = ADD32(ctx->r20, ctx->r2);
//    KF_strncmp(rdram, ctx);
//    goto after_2;
//    // addu        $s4, $s4, $v0
//    ctx->r20 = ADD32(ctx->r20, ctx->r2);
//    after_2:
//    // bne         $v0, $zero, L_80025230
//    if (ctx->r2 != 0) {
//        // addiu       $s0, $s0, 0x28
//        ctx->r16 = ADD32(ctx->r16, 0X28);
//        goto L_80025230;
//    }
//    // addiu       $s0, $s0, 0x28
//    ctx->r16 = ADD32(ctx->r16, 0X28);
//    // lw          $v0, 0x0($s1)
//    ctx->r2 = MEM_W(0X0, ctx->r17);
//    // nop
//
//    // addiu       $v0, $v0, 0x1
//    ctx->r2 = ADD32(ctx->r2, 0X1);
//    // sw          $v0, 0x0($s1)
//    MEM_W(0X0, ctx->r17) = ctx->r2;
//L_80025230:
//    // jal         0x80062AA0
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    nextfile(rdram, ctx);
//    goto after_3;
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    after_3:
//    // beq         $v0, $s0, L_80025200
//    if (ctx->r2 == ctx->r16) {
//        // addu        $a0, $s0, $zero
//        ctx->r4 = ADD32(ctx->r16, 0);
//        goto L_80025200;
//    }
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//L_80025240:
//    // addu        $s0, $s3, $zero
//    ctx->r16 = ADD32(ctx->r19, 0);
//    // addiu       $a0, $sp, 0x10
//    ctx->r4 = ADD32(ctx->r29, 0X10);
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    // jal         0x80062B80
//    // ori         $a2, $zero, 0x258
//    ctx->r6 = 0 | 0X258;
//    memset_recomp(rdram, ctx);
//    goto after_4;
//    // ori         $a2, $zero, 0x258
//    ctx->r6 = 0 | 0X258;
//    after_4:
//    // addu        $s2, $zero, $zero
//    ctx->r18 = ADD32(0, 0);
//    // addiu       $s1, $s3, 0x20
//    ctx->r17 = ADD32(ctx->r19, 0X20);
//L_8002525C:
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // addiu       $a1, $a1, -0x1F58
//    ctx->r5 = ADD32(ctx->r5, -0X1F58);
//    // jal         0x80062BE0
//    // ori         $a2, $zero, 0xC
//    ctx->r6 = 0 | 0XC;
//    KF_strncmp(rdram, ctx);
//    goto after_5;
//    // ori         $a2, $zero, 0xC
//    ctx->r6 = 0 | 0XC;
//    after_5:
//    // bne         $v0, $zero, L_800252E0
//    if (ctx->r2 != 0) {
//        // addiu       $a0, $sp, 0x268
//        ctx->r4 = ADD32(ctx->r29, 0X268);
//        goto L_800252E0;
//    }
//    // addiu       $a0, $sp, 0x268
//    ctx->r4 = ADD32(ctx->r29, 0X268);
//    // lbu         $v0, -0x14($s1)
//    ctx->r2 = MEM_BU(-0X14, ctx->r17);
//    // jal         0x80062C00
//    // sb          $v0, 0x268($sp)
//    MEM_B(0X268, ctx->r29) = ctx->r2;
//    KF_atoi(rdram, ctx);
//    goto after_6;
//    // sb          $v0, 0x268($sp)
//    MEM_B(0X268, ctx->r29) = ctx->r2;
//    after_6:
//    // addiu       $v0, $v0, -0x1
//    ctx->r2 = ADD32(ctx->r2, -0X1);
//    // sll         $v1, $v0, 2
//    ctx->r3 = S32(ctx->r2) << 2;
//    // addu        $v1, $v1, $v0
//    ctx->r3 = ADD32(ctx->r3, ctx->r2);
//    // sll         $v1, $v1, 3
//    ctx->r3 = S32(ctx->r3) << 3;
//    // addiu       $v0, $sp, 0x10
//    ctx->r2 = ADD32(ctx->r29, 0X10);
//    // addu        $a3, $v0, $v1
//    ctx->r7 = ADD32(ctx->r2, ctx->r3);
//    // addu        $a2, $s0, $zero
//    ctx->r6 = ADD32(ctx->r16, 0);
//    // addu        $t0, $s1, $zero
//    ctx->r8 = ADD32(ctx->r17, 0);
//L_800252A4:
//    // lw          $v0, 0x0($a2)
//    ctx->r2 = MEM_W(0X0, ctx->r6);
//    // lw          $v1, 0x4($a2)
//    ctx->r3 = MEM_W(0X4, ctx->r6);
//    // lw          $a0, 0x8($a2)
//    ctx->r4 = MEM_W(0X8, ctx->r6);
//    // lw          $a1, 0xC($a2)
//    ctx->r5 = MEM_W(0XC, ctx->r6);
//    // sw          $v0, 0x0($a3)
//    MEM_W(0X0, ctx->r7) = ctx->r2;
//    // sw          $v1, 0x4($a3)
//    MEM_W(0X4, ctx->r7) = ctx->r3;
//    // sw          $a0, 0x8($a3)
//    MEM_W(0X8, ctx->r7) = ctx->r4;
//    // sw          $a1, 0xC($a3)
//    MEM_W(0XC, ctx->r7) = ctx->r5;
//    // addiu       $a2, $a2, 0x10
//    ctx->r6 = ADD32(ctx->r6, 0X10);
//    // bne         $a2, $t0, L_800252A4
//    if (ctx->r6 != ctx->r8) {
//        // addiu       $a3, $a3, 0x10
//        ctx->r7 = ADD32(ctx->r7, 0X10);
//        goto L_800252A4;
//    }
//    // addiu       $a3, $a3, 0x10
//    ctx->r7 = ADD32(ctx->r7, 0X10);
//    // lw          $v0, 0x0($a2)
//    ctx->r2 = MEM_W(0X0, ctx->r6);
//    // lw          $v1, 0x4($a2)
//    ctx->r3 = MEM_W(0X4, ctx->r6);
//    // sw          $v0, 0x0($a3)
//    MEM_W(0X0, ctx->r7) = ctx->r2;
//    // sw          $v1, 0x4($a3)
//    MEM_W(0X4, ctx->r7) = ctx->r3;
//L_800252E0:
//    // addiu       $s1, $s1, 0x28
//    ctx->r17 = ADD32(ctx->r17, 0X28);
//    // addiu       $s2, $s2, 0x1
//    ctx->r18 = ADD32(ctx->r18, 0X1);
//    // slti        $v0, $s2, 0xF
//    ctx->r2 = SIGNED(ctx->r18) < 0XF ? 1 : 0;
//    // bne         $v0, $zero, L_8002525C
//    if (ctx->r2 != 0) {
//        // addiu       $s0, $s0, 0x28
//        ctx->r16 = ADD32(ctx->r16, 0X28);
//        goto L_8002525C;
//    }
//    // addiu       $s0, $s0, 0x28
//    ctx->r16 = ADD32(ctx->r16, 0X28);
//    // addu        $a3, $s3, $zero
//    ctx->r7 = ADD32(ctx->r19, 0);
//    // addiu       $a2, $sp, 0x10
//    ctx->r6 = ADD32(ctx->r29, 0X10);
//    // addiu       $t0, $sp, 0x260
//    ctx->r8 = ADD32(ctx->r29, 0X260);
//L_80025300:
//    // lw          $v0, 0x0($a2)
//    ctx->r2 = MEM_W(0X0, ctx->r6);
//    // lw          $v1, 0x4($a2)
//    ctx->r3 = MEM_W(0X4, ctx->r6);
//    // lw          $a0, 0x8($a2)
//    ctx->r4 = MEM_W(0X8, ctx->r6);
//    // lw          $a1, 0xC($a2)
//    ctx->r5 = MEM_W(0XC, ctx->r6);
//    // sw          $v0, 0x0($a3)
//    MEM_W(0X0, ctx->r7) = ctx->r2;
//    // sw          $v1, 0x4($a3)
//    MEM_W(0X4, ctx->r7) = ctx->r3;
//    // sw          $a0, 0x8($a3)
//    MEM_W(0X8, ctx->r7) = ctx->r4;
//    // sw          $a1, 0xC($a3)
//    MEM_W(0XC, ctx->r7) = ctx->r5;
//    // addiu       $a2, $a2, 0x10
//    ctx->r6 = ADD32(ctx->r6, 0X10);
//    // bne         $a2, $t0, L_80025300
//    if (ctx->r6 != ctx->r8) {
//        // addiu       $a3, $a3, 0x10
//        ctx->r7 = ADD32(ctx->r7, 0X10);
//        goto L_80025300;
//    }
//    // addiu       $a3, $a3, 0x10
//    ctx->r7 = ADD32(ctx->r7, 0X10);
//    // lw          $v0, 0x0($a2)
//    ctx->r2 = MEM_W(0X0, ctx->r6);
//    // lw          $v1, 0x4($a2)
//    ctx->r3 = MEM_W(0X4, ctx->r6);
//    // sw          $v0, 0x0($a3)
//    MEM_W(0X0, ctx->r7) = ctx->r2;
//    // sw          $v1, 0x4($a3)
//    MEM_W(0X4, ctx->r7) = ctx->r3;
//    // lui         $v0, 0x1
//    ctx->r2 = S32(0X1 << 16);
//    // ori         $v0, $v0, 0xA000
//    ctx->r2 = ctx->r2 | 0XA000;
//    // slt         $v0, $v0, $s4
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
//    // lw          $ra, 0x284($sp)
//    ctx->r31 = MEM_W(0X284, ctx->r29);
//    // lw          $s4, 0x280($sp)
//    ctx->r20 = MEM_W(0X280, ctx->r29);
//    // lw          $s3, 0x27C($sp)
//    ctx->r19 = MEM_W(0X27C, ctx->r29);
//    // lw          $s2, 0x278($sp)
//    ctx->r18 = MEM_W(0X278, ctx->r29);
//    // lw          $s1, 0x274($sp)
//    ctx->r17 = MEM_W(0X274, ctx->r29);
//    // lw          $s0, 0x270($sp)
//    ctx->r16 = MEM_W(0X270, ctx->r29);
//    // addiu       $sp, $sp, 0x288
//    ctx->r29 = ADD32(ctx->r29, 0X288);
//    // jr          $ra
//    // nop

    return;
    // nop

;}
