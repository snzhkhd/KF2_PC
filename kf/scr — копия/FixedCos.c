#include "recomp.h"
#include "disable_warnings.h"

void FixedCos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // bgez        $a0, L_800602DC
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_800602DC;
    }
    // nop

    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800602DC:
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // slti        $v0, $a0, 0x801
    ctx->r2 = SIGNED(ctx->r4) < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_80060330
    if (ctx->r2 == 0) {
        // slti        $v0, $a0, 0x401
        ctx->r2 = SIGNED(ctx->r4) < 0X401 ? 1 : 0;
        goto L_80060330;
    }
    // slti        $v0, $a0, 0x401
    ctx->r2 = SIGNED(ctx->r4) < 0X401 ? 1 : 0;
    // beq         $v0, $zero, L_80060314
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x400
        ctx->r2 = 0 | 0X400;
        goto L_80060314;
    }
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x438C
    ctx->r1 = ADD32(ctx->r1, 0X438C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // j           L_80060378
    // nop

    goto L_80060378;
    // nop

L_80060314:
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x3B8C
    ctx->r1 = ADD32(ctx->r1, 0X3B8C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // j           L_80060378
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    goto L_80060378;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80060330:
    // slti        $v0, $a0, 0xC01
    ctx->r2 = SIGNED(ctx->r4) < 0XC01 ? 1 : 0;
    // bne         $v0, $zero, L_80060358
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xC00
        ctx->r2 = 0 | 0XC00;
        goto L_80060358;
    }
    // ori         $v0, $zero, 0xC00
    ctx->r2 = 0 | 0XC00;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x2B8C
    ctx->r1 = ADD32(ctx->r1, 0X2B8C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // j           L_80060378
    // nop

    goto L_80060378;
    // nop

L_80060358:
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x438C
    ctx->r1 = ADD32(ctx->r1, 0X438C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0x0($at)
    ctx->r2 = MEM_H(0X0, ctx->r1);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80060378:
    // jr          $ra
    // nop

    return;
    // nop

;}
