#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4A6F
    ctx->r4 = ADD32(ctx->r4, -0X4A6F);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // beq         $v1, $v0, L_8002C0E4
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x11
        ctx->r2 = 0 | 0X11;
        goto L_8002C0E4;
    }
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // ori         $a0, $zero, 0xB
    ctx->r4 = 0 | 0XB;
    // jal         0x80014570
    // ori         $a1, $zero, 0x6E
    ctx->r5 = 0 | 0X6E;
    PlaySoundEffect(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0x6E
    ctx->r5 = 0 | 0X6E;
    after_0:
    // beq         $s0, $zero, L_8002C0D4
    if (ctx->r16 == 0) {
        // nop
    
        goto L_8002C0D4;
    }
    // nop

    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x49EC
    ctx->r5 = ADD32(ctx->r5, -0X49EC);
    // lwl         $v0, 0x3($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r16);
    // lwr         $v0, 0x0($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r16);
    // lwl         $v1, 0x7($s0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r16);
    // lwr         $v1, 0x4($s0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r16);
    // swl         $v0, 0x3($a1)
    do_swl(rdram, 0X3, ctx->r5, ctx->r2);
    // swr         $v0, 0x0($a1)
    do_swr(rdram, 0X0, ctx->r5, ctx->r2);
    // swl         $v1, 0x7($a1)
    do_swl(rdram, 0X7, ctx->r5, ctx->r3);
    // swr         $v1, 0x4($a1)
    do_swr(rdram, 0X4, ctx->r5, ctx->r3);
L_8002C0D4:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x49E4($at)
    MEM_H(-0X49E4, ctx->r1) = 0;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4A36($at)
    MEM_H(-0X4A36, ctx->r1) = 0;
L_8002C0E4:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
