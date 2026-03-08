#include "recomp.h"
#include "disable_warnings.h"

void PrepareReadTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // lw          $s2, -0x57BC($s2)
    ctx->r18 = MEM_W(-0X57BC, ctx->r18);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // jal         0x80018244
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    FAsyncLoadSomething_0005(rdram, ctx);
    goto after_0;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // sh          $zero, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = 0;
    // jal         0x80018418
    // sb          $zero, 0x24($s2)
    MEM_B(0X24, ctx->r18) = 0;
    ReadFromFile(rdram, ctx);
    goto after_1;
    // sb          $zero, 0x24($s2)
    MEM_B(0X24, ctx->r18) = 0;
    after_1:
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // srl         $v1, $a2, 11
    ctx->r3 = S32(U32(ctx->r6) >> 11);
    // sh          $v1, 0x22($s2)
    MEM_H(0X22, ctx->r18) = ctx->r3;
    // lh          $v0, 0x22($s2)
    ctx->r2 = MEM_H(0X22, ctx->r18);
    // sh          $v1, 0x20($s2)
    MEM_H(0X20, ctx->r18) = ctx->r3;
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_80018634
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x40
        ctx->r4 = 0 | 0X40;
        goto L_80018634;
    }
    // ori         $a0, $zero, 0x40
    ctx->r4 = 0 | 0X40;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // j           L_80018648
    // sh          $zero, 0x22($s2)
    MEM_H(0X22, ctx->r18) = 0;
    goto L_80018648;
    // sh          $zero, 0x22($s2)
    MEM_H(0X22, ctx->r18) = 0;
L_80018634:
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $v0, $v1, -0x10
    ctx->r2 = ADD32(ctx->r3, -0X10);
    // sh          $v0, 0x22($s2)
    MEM_H(0X22, ctx->r18) = ctx->r2;
L_80018648:
    // jal         0x800182F4
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    CreateCDTask(rdram, ctx);
    goto after_2;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
