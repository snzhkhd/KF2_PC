#include "recomp.h"
#include "disable_warnings.h"

void OnAudioStreamComplete(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("OnAudioStreamComplete\n\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(0X18, ctx->r16);
    // nop

    // beq         $v1, $zero, L_8001487C
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8001487C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80014968
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80014968;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // j           L_8001496C
    // nop

    goto L_8001496C;
    // nop

L_8001487C:
    // lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(0X10, ctx->r16);
    // lh          $v1, 0x1A($s0)
    ctx->r3 = MEM_H(0X1A, ctx->r16);
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x59AC
    ctx->r2 = ADD32(ctx->r2, -0X59AC);
    // jal         0x800182A0
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    VerifyChecksum(rdram, ctx);
    goto after_0;
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    after_0:
    // beq         $v0, $zero, L_800148CC
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
        goto L_800148CC;
    }
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_800148B0:
    // addiu       $a1, $s0, 0x6
    ctx->r5 = ADD32(ctx->r16, 0X6);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // beq         $v0, $zero, L_800148B0
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_800148B0;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // j           L_8001496C
    // nop

    goto L_8001496C;
    // nop

L_800148CC:
    // lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(0X0, ctx->r17);
    // nop

    // beq         $a0, $s2, L_800148E4
    if (ctx->r4 == ctx->r18) {
        // nop
    
        goto L_800148E4;
    }
    // nop

    // jal         0x8005D010
    // nop

    FreeSPUVoice(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_800148E4:
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
    // nop

    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // jal         0x80053434
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    SsVabOpenHead(rdram, ctx);
    goto after_3;
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $s2, L_8001491C
    if (ctx->r2 != ctx->r18) {
        // addiu       $a0, $s0, 0x2
        ctx->r4 = ADD32(ctx->r16, 0X2);
        goto L_8001491C;
    }
    // addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    // jal         0x80017D2C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    NextCdTask(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // j           L_8001496C
    // nop

    goto L_8001496C;
    // nop

L_8001491C:
    // lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(0X10, ctx->r16);
    // jal         0x80018150
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    ConvertCdAddress(rdram, ctx);
    goto after_5;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_5:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5754
    ctx->r2 = ADD32(ctx->r2, -0X5754);
    // sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_8001494C:
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // beq         $v0, $zero, L_8001494C
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_8001494C;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // j           L_8001496C
    // nop

    goto L_8001496C;
    // nop

L_80014968:
    // sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
L_8001496C:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
