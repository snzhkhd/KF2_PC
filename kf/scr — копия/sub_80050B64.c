#include "recomp.h"
#include "disable_warnings.h"

void sub_80050B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $t2, $zero, 0x18
    ctx->r10 = 0 | 0X18;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // ori         $t1, $zero, 0x3
    ctx->r9 = 0 | 0X3;
    // ori         $t0, $zero, 0x2
    ctx->r8 = 0 | 0X2;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80050B7C:
    // sll         $v1, $a2, 4
    ctx->r3 = S32(ctx->r6) << 4;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x71C($a0)
    ctx->r4 = MEM_W(-0X71C, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sllv        $v0, $a3, $a2
    ctx->r2 = S32(ctx->r7) << (ctx->r6 & 31);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // lhu         $v1, 0xC($v1)
    ctx->r3 = MEM_HU(0XC, ctx->r3);
    // beq         $v0, $zero, L_80050BC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80050BC0;
    }
    // nop

    // beq         $v1, $zero, L_80050BB8
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80050BB8;
    }
    // nop

    // j           L_80050BD4
    // sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
    goto L_80050BD4;
    // sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
L_80050BB8:
    // j           L_80050BD4
    // sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    goto L_80050BD4;
    // sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
L_80050BC0:
    // beq         $v1, $zero, L_80050BD0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80050BD0;
    }
    // nop

    // j           L_80050BD4
    // sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    goto L_80050BD4;
    // sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
L_80050BD0:
    // sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_80050BD4:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slt         $v0, $a2, $t2
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r10) ? 1 : 0;
    // bne         $v0, $zero, L_80050B7C
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80050B7C;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // jr          $ra
    // nop

    return;
    // nop

;}
