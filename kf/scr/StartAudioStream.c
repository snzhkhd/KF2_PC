#include "recomp.h"
#include "disable_warnings.h"

void StartAudioStream(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("[HLE Audio] StartAudioStream call\n");
    //// Ќе создаЄм CDTask Ч AsyncStructForcedLoadSync не будет ждать аудио
    //ctx->r2 = 254;  // "нет свободного канала" Ч безопасный возврат
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18) << 3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x59AC
    ctx->r3 = ADD32(ctx->r3, -0X59AC);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // beq         $s2, $zero, L_80014C00
    if (ctx->r18 == 0) {
        // sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
        goto L_80014C00;
    }
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $s2, $v0, L_80014C20
    if (ctx->r18 == ctx->r2) {
        // addiu       $s1, $v1, 0xE60
        ctx->r17 = ADD32(ctx->r3, 0XE60);
        goto L_80014C20;
    }
    // addiu       $s1, $v1, 0xE60
    ctx->r17 = ADD32(ctx->r3, 0XE60);
    // j           L_80014C08
    // nop

    goto L_80014C08;
    // nop

L_80014C00:
    // j           L_80014C20
    // addiu       $s1, $v1, 0xE68
    ctx->r17 = ADD32(ctx->r3, 0XE68);
    goto L_80014C20;
    // addiu       $s1, $v1, 0xE68
    ctx->r17 = ADD32(ctx->r3, 0XE68);
L_80014C08:
    // jal         0x80014AD0
    // nop

    FindFreeAudioChannel(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // beq         $s1, $zero, L_80014C60
    if (ctx->r17 == 0) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_80014C60;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80014C20:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // lw          $s0, -0x57BC($s0)
    ctx->r16 = MEM_W(-0X57BC, ctx->r16);
    // jal         0x80018244
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    FAsyncLoadSomething_0005(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    // sw          $s1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r17;
    // sh          $s2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r18;
    // lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(0X4, ctx->r17);
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x4844
    ctx->r7 = ADD32(ctx->r7, 0X4844);
    // jal         0x80018554
    // sll         $a1, $s4, 1
    ctx->r5 = S32(ctx->r20) << 1;
    CreateAudioCDTask(rdram, ctx);
    goto after_2;
    // sll         $a1, $s4, 1
    ctx->r5 = S32(ctx->r20) << 1;
    after_2:
L_80014C60:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
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
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
