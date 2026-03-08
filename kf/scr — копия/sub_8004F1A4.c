#include "recomp.h"
#include "disable_warnings.h"

void sub_8004F1A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // bne         $a0, $v0, L_8004F22C
    if (ctx->r4 != ctx->r2) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_8004F22C;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // addiu       $s0, $s0, -0x890
    ctx->r16 = ADD32(ctx->r16, -0X890);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // blez        $v0, L_8004F23C
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8004F23C;
    }
    // nop

    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x89C($a0)
    ctx->r4 = MEM_W(-0X89C, ctx->r4);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, -0x894($a1)
    ctx->r5 = MEM_W(-0X894, ctx->r5);
    // jal         0x8004EFD4
    // nop

    sub_8004EFD4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x894($v0)
    ctx->r2 = MEM_W(-0X894, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x89C($v1)
    ctx->r3 = MEM_W(-0X89C, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r2;
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // j           L_8004F23C
    // nop

    goto L_8004F23C;
    // nop

L_8004F22C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x890
    ctx->r3 = ADD32(ctx->r3, -0X890);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8004F23C:
    // jal         0x8006263C
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    KF_VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, -0x88C
    ctx->r3 = ADD32(ctx->r3, -0X88C);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x890($v0)
    ctx->r2 = MEM_W(-0X890, ctx->r2);
    // nop

    // bgez        $v0, L_8004F280
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8004F280;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8A8($v0)
    ctx->r2 = MEM_W(-0X8A8, ctx->r2);
    // nop

    // blez        $v0, L_8004F280
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8004F280;
    }
    // nop

    // jal         0x8004E73C
    // nop

    sub_8004E73C(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8004F280:
    // lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // addiu       $s0, $s0, -0x890
    ctx->r16 = ADD32(ctx->r16, -0X890);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // bgtz        $v0, L_8004F2F8
    if (SIGNED(ctx->r2) > 0) {
        // ori         $a0, $zero, 0x9
        ctx->r4 = 0 | 0X9;
        goto L_8004F2F8;
    }
    // ori         $a0, $zero, 0x9
    ctx->r4 = 0 | 0X9;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x888($v0)
    ctx->r2 = MEM_W(-0X888, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x884($v1)
    ctx->r3 = MEM_W(-0X884, ctx->r3);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v1, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r3;
    // jal         0x8004DBE0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw_8004DBE0(rdram, ctx);
    goto after_3;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0xB80($v1)
    ctx->r3 = MEM_W(-0XB80, ctx->r3);
    // nop

    // beq         $v1, $zero, L_8004F2F8
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004F2F8;
    }
    // nop

    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8004F2F0
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x5
        ctx->r4 = 0 | 0X5;
        goto L_8004F2F0;
    }
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
L_8004F2F0:
    // jalr        $v1
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_4;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
L_8004F2F8:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
