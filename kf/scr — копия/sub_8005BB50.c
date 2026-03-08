#include "recomp.h"
#include "disable_warnings.h"

void sub_8005BB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(0X0, ctx->r3);
    // nop

    // bne         $a0, $zero, L_8005BBB8
    if (ctx->r4 != 0) {
        // andi        $v0, $a0, 0x80
        ctx->r2 = ctx->r4 & 0X80;
        goto L_8005BBB8;
    }
    // andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // j           L_8005BC04
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8005BC04;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005BBB8:
    // beq         $v0, $zero, L_8005BBF0
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4) << 2;
        goto L_8005BBF0;
    }
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // andi        $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 & 0X7F;
L_8005BBC4:
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(0X0, ctx->r3);
    // sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4) << 7;
    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // bne         $v1, $zero, L_8005BBC4
    if (ctx->r3 != 0) {
        // addu        $a0, $a0, $v0
        ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_8005BBC4;
    }
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
L_8005BBF0:
    // lw          $v1, 0x80($a1)
    ctx->r3 = MEM_W(0X80, ctx->r5);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // sw          $v1, 0x80($a1)
    MEM_W(0X80, ctx->r5) = ctx->r3;
L_8005BC04:
    // jr          $ra
    // nop

    return;
    // nop

;}
