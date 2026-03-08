#include "recomp.h"
#include "disable_warnings.h"

void FindFreeOrOldestProjectileSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x6810
    ctx->r3 = ADD32(ctx->r3, -0X6810);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // ori         $t3, $zero, 0xFF
    ctx->r11 = 0 | 0XFF;
    // addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
L_80038E98:
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nop

    // beq         $v0, $t3, L_80038EEC
    if (ctx->r2 == ctx->r11) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_80038EEC;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // beq         $a2, $t2, L_80038EDC
    if (ctx->r6 == ctx->r10) {
        // nop
    
        goto L_80038EDC;
    }
    // nop

    // lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(0X3C, ctx->r4);
    // nop

    // subu        $v1, $a2, $v0
    ctx->r3 = SUB32(ctx->r6, ctx->r2);
    // bgez        $v1, L_80038ECC
    if (SIGNED(ctx->r3) >= 0) {
        // slt         $v0, $a3, $v1
        ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_80038ECC;
    }
    // slt         $v0, $a3, $v1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // slt         $v0, $a3, $v1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
L_80038ECC:
    // beq         $v0, $zero, L_80038EDC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80038EDC;
    }
    // nop

    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_80038EDC:
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $zero, L_80038E98
    if (ctx->r5 != 0) {
        // addiu       $a0, $a0, 0x44
        ctx->r4 = ADD32(ctx->r4, 0X44);
        goto L_80038E98;
    }
    // addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    // addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
L_80038EEC:
    // jr          $ra
    // nop

    return;
    // nop

;}
