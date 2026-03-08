#include "recomp.h"
#include "disable_warnings.h"

void UpdatePlayerMapContext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // beq         $a2, $zero, L_8001452C
    if (ctx->r6 == 0) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_8001452C;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x59C8
    ctx->r5 = ADD32(ctx->r5, -0X59C8);
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    // lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(0XC, ctx->r6);
    // nop

    // sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(0X0, ctx->r6);
    // lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(0X4, ctx->r6);
    // lw          $a2, 0x8($a2)
    ctx->r6 = MEM_W(0X8, ctx->r6);
    // jal         0x8002D4A4
    // nop

    ResolveCurrentMetaTile(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0x2A82($v0)
    ctx->r2 = MEM_HU(-0X2A82, ctx->r2);
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x59B8($at)
    MEM_H(-0X59B8, ctx->r1) = ctx->r2;
L_8001452C:
    // beq         $s0, $zero, L_8001455C
    if (ctx->r16 == 0) {
        // nop
    
        goto L_8001455C;
    }
    // nop

    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x59B6
    ctx->r5 = ADD32(ctx->r5, -0X59B6);
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
L_8001455C:
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
