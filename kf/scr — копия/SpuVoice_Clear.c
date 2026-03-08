#include "recomp.h"
#include "disable_warnings.h"

void SpuVoice_Clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4) >> 16;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80057C6C
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    sub_80057C6C(rdram, ctx);
    goto after_0;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    after_0:
    // jal         0x80057F04
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80057F04(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2) << (ctx->r16 & 31);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x1938($v1)
    ctx->r3 = MEM_W(-0X1938, ctx->r3);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lh          $a0, -0x19C0($a0)
    ctx->r4 = MEM_H(-0X19C0, ctx->r4);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x1938($at)
    MEM_W(-0X1938, ctx->r1) = ctx->r2;
    // blez        $a0, L_8005D4E0
    if (SIGNED(ctx->r4) <= 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_8005D4E0;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2248
    ctx->r3 = ADD32(ctx->r3, -0X2248);
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // ori         $a3, $zero, 0x7F
    ctx->r7 = 0 | 0X7F;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005D3F0:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0x90($v0)
    MEM_W(0X90, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sb          $v1, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = ctx->r3;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $zero, 0x3E($v0)
    MEM_H(0X3E, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $zero, 0x40($v0)
    MEM_H(0X40, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0x94($v0)
    MEM_W(0X94, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0x98($v0)
    MEM_W(0X98, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $zero, 0x42($v0)
    MEM_H(0X42, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $zero, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $zero, 0x44($v0)
    MEM_H(0X44, ctx->r2) = 0;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lh          $v1, -0x19C0($v1)
    ctx->r3 = MEM_H(-0X19C0, ctx->r3);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $a3, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r7;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slt         $v1, $a2, $v1
    ctx->r3 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sh          $a3, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r7;
    // bne         $v1, $zero, L_8005D3F0
    if (ctx->r3 != 0) {
        // addiu       $a0, $a0, 0xAC
        ctx->r4 = ADD32(ctx->r4, 0XAC);
        goto L_8005D3F0;
    }
    // addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
L_8005D4E0:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
