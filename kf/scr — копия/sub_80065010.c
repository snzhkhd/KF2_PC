#include "recomp.h"
#include "disable_warnings.h"

void sub_80065010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6280($v0)
    ctx->r2 = MEM_W(0X6280, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
    // and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // bne         $v0, $zero, L_80065310
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80065310;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x80061CD0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SetIntrMask(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x62A4($a0)
    ctx->r4 = MEM_W(0X62A4, ctx->r4);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A8($v1)
    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x62B0($at)
    MEM_W(0X62B0, ctx->r1) = ctx->r2;
    // beq         $a0, $v1, L_80065264
    if (ctx->r4 == ctx->r3) {
        // nop
    
        goto L_80065264;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6280($v0)
    ctx->r2 = MEM_W(0X6280, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // bne         $v0, $zero, L_80065264
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80065264;
    }
    // nop

    // lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // addiu       $s0, $s0, 0x6294
    ctx->r16 = ADD32(ctx->r16, 0X6294);
L_80065088:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A8($v0)
    ctx->r2 = MEM_W(0X62A8, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // bne         $v0, $v1, L_800650C8
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_800650C8;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61AC
    ctx->r2 = ADD32(ctx->r2, 0X61AC);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800650C8
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x2
        ctx->r4 = 0 | 0X2;
        goto L_800650C8;
    }
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // jal         0x80061BB4
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    DMACallback(rdram, ctx);
    goto after_1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
L_800650C8:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x6274($a0)
    ctx->r4 = MEM_W(0X6274, ctx->r4);
    // nop

    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80065100
    if (ctx->r2 != 0) {
        // addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
        goto L_80065100;
    }
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
L_800650EC:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // beq         $v0, $zero, L_800650EC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800650EC;
    }
    // nop

L_80065100:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x62A8($a1)
    ctx->r5 = MEM_W(0X62A8, ctx->r5);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A8($v1)
    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5) << 1;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x752C
    ctx->r1 = ADD32(ctx->r1, -0X752C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $a0, 0x0($at)
    ctx->r4 = MEM_W(0X0, ctx->r1);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x62A8($a1)
    ctx->r5 = MEM_W(0X62A8, ctx->r5);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x7528
    ctx->r1 = ADD32(ctx->r1, -0X7528);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $a1, 0x0($at)
    ctx->r5 = MEM_W(0X0, ctx->r1);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x7530
    ctx->r1 = ADD32(ctx->r1, -0X7530);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A8($v1)
    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x7530
    ctx->r1 = ADD32(ctx->r1, -0X7530);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A8($v1)
    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x752C
    ctx->r1 = ADD32(ctx->r1, -0X752C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A8($v1)
    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x7528
    ctx->r1 = ADD32(ctx->r1, -0X7528);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A8($v0)
    ctx->r2 = MEM_W(0X62A8, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x62A8($at)
    MEM_W(0X62A8, ctx->r1) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A8($v0)
    ctx->r2 = MEM_W(0X62A8, ctx->r2);
    // nop

    // beq         $v1, $v0, L_80065264
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80065264;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6280($v0)
    ctx->r2 = MEM_W(0X6280, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80065088
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80065088;
    }
    // nop

L_80065264:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x62B0($a0)
    ctx->r4 = MEM_W(0X62B0, ctx->r4);
    // jal         0x80061CD0
    // nop

    SetIntrMask(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A8($v0)
    ctx->r2 = MEM_W(0X62A8, ctx->r2);
    // nop

    // bne         $v1, $v0, L_800652F4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800652F4;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6280($v0)
    ctx->r2 = MEM_W(0X6280, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_800652F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800652F4;
    }
    // nop

    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x61A8
    ctx->r3 = ADD32(ctx->r3, 0X61A8);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // beq         $v0, $zero, L_800652F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800652F4;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x61AC($v0)
    ctx->r2 = MEM_W(0X61AC, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800652F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800652F4;
    }
    // nop

    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x61AC($v0)
    ctx->r2 = MEM_W(0X61AC, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_800652F4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A4($v0)
    ctx->r2 = MEM_W(0X62A4, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A8($v1)
    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
L_80065310:
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
