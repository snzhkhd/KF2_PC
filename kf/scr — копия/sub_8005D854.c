#include "recomp.h"
#include "disable_warnings.h"

void sub_8005D854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $s0, $a1, 1
    ctx->r16 = S32(ctx->r5) << 1;
    // addu        $s0, $s0, $a1
    ctx->r16 = ADD32(ctx->r16, ctx->r5);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // subu        $s0, $s0, $a1
    ctx->r16 = SUB32(ctx->r16, ctx->r5);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // subu        $s0, $s0, $a1
    ctx->r16 = SUB32(ctx->r16, ctx->r5);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2248
    ctx->r2 = ADD32(ctx->r2, -0X2248);
    // sll         $s1, $a0, 2
    ctx->r17 = S32(ctx->r4) << 2;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5) << 8;
    // lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(0X0, ctx->r17);
    // or          $a0, $a1, $a0
    ctx->r4 = ctx->r5 | ctx->r4;
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // addu        $a2, $s0, $a2
    ctx->r6 = ADD32(ctx->r16, ctx->r6);
    // addiu       $a1, $a2, 0x78
    ctx->r5 = ADD32(ctx->r6, 0X78);
    // jal         0x80057DEC
    // addiu       $a2, $a2, 0x7A
    ctx->r6 = ADD32(ctx->r6, 0X7A);
    sub_80057DEC(rdram, ctx);
    goto after_0;
    // addiu       $a2, $a2, 0x7A
    ctx->r6 = ADD32(ctx->r6, 0X7A);
    after_0:
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // nop

    // addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // nop

    // addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // addiu       $a0, $zero, -0x9
    ctx->r4 = ADD32(0, -0X9);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(0X90, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // sw          $v0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r2;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
