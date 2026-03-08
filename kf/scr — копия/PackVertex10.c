#include "recomp.h"
#include "disable_warnings.h"

void PackVertex10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // bltz        $a0, L_800640F8
    if (SIGNED(ctx->r4) < 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800640F8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61A4
    ctx->r2 = ADD32(ctx->r2, 0X61A4);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_800640F8
    if (ctx->r2 == 0) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_800640F8;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_800640F8:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bltz        $v1, L_8006413C
    if (SIGNED(ctx->r3) < 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8006413C;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61A6
    ctx->r2 = ADD32(ctx->r2, 0X61A6);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80064138
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80064138;
    }
    // nop

    // addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80064138:
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8006413C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61A0
    ctx->r2 = ADD32(ctx->r2, 0X61A0);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8006416C
    if (ctx->r2 != 0) {
        // andi        $v1, $a1, 0xFFF
        ctx->r3 = ctx->r5 & 0XFFF;
        goto L_8006416C;
    }
    // andi        $v1, $a1, 0xFFF
    ctx->r3 = ctx->r5 & 0XFFF;
    // andi        $v1, $a1, 0x3FF
    ctx->r3 = ctx->r5 & 0X3FF;
    // sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) << 10;
    // j           L_80064174
    // andi        $v0, $a0, 0x3FF
    ctx->r2 = ctx->r4 & 0X3FF;
    goto L_80064174;
    // andi        $v0, $a0, 0x3FF
    ctx->r2 = ctx->r4 & 0X3FF;
L_8006416C:
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // andi        $v0, $a0, 0xFFF
    ctx->r2 = ctx->r4 & 0XFFF;
L_80064174:
    // lui         $a0, 0xE300
    ctx->r4 = S32(0XE300 << 16);
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // jr          $ra
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    return;
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
;}
