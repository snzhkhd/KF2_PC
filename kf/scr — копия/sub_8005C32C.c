#include "recomp.h"
#include "disable_warnings.h"

void sub_8005C32C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5) >> 16;
    // sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10) << 1;
    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4) >> 16;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, -0x2248
    ctx->r4 = ADD32(ctx->r4, -0X2248);
    // sll         $v1, $t3, 2
    ctx->r3 = S32(ctx->r11) << 2;
    // addu        $t1, $v1, $a0
    ctx->r9 = ADD32(ctx->r3, ctx->r4);
    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $t0, $a1, $v1
    ctx->r8 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($t0)
    ctx->r2 = MEM_W(0X90, ctx->r8);
    // addiu       $v1, $zero, -0x201
    ctx->r3 = ADD32(0, -0X201);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x90($t0)
    MEM_W(0X90, ctx->r8) = ctx->r2;
    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // addiu       $a0, $zero, -0x5
    ctx->r4 = ADD32(0, -0X5);
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $a2, $v0, L_8005C3F8
    if (ctx->r6 != ctx->r2) {
        // sh          $a3, 0x46($t0)
        MEM_H(0X46, ctx->r8) = ctx->r7;
        goto L_8005C3F8;
    }
    // sh          $a3, 0x46($t0)
    MEM_H(0X46, ctx->r8) = ctx->r7;
    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // sll         $a0, $t2, 8
    ctx->r4 = S32(ctx->r10) << 8;
    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // lhu         $a1, 0x74($t0)
    ctx->r5 = MEM_HU(0X74, ctx->r8);
    // lhu         $a2, 0x76($t0)
    ctx->r6 = MEM_HU(0X76, ctx->r8);
    // or          $a0, $a0, $t3
    ctx->r4 = ctx->r4 | ctx->r11;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $zero, 0x48($t0)
    MEM_H(0X48, ctx->r8) = 0;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x80057C6C
    // sb          $v0, 0x2B($t0)
    MEM_B(0X2B, ctx->r8) = ctx->r2;
    sub_80057C6C(rdram, ctx);
    goto after_0;
    // sb          $v0, 0x2B($t0)
    MEM_B(0X2B, ctx->r8) = ctx->r2;
    after_0:
    // j           L_8005C41C
    // nop

    goto L_8005C41C;
    // nop

L_8005C3F8:
    // bne         $a2, $zero, L_8005C41C
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8005C41C;
    }
    // nop

    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
L_8005C41C:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // nop

    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
