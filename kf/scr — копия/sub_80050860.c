#include "recomp.h"
#include "disable_warnings.h"

void sub_80050860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sll         $a1, $s0, 4
    ctx->r5 = S32(ctx->r16) << 4;
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // addu        $at, $a1, $at
    ctx->r1 = ADD32(ctx->r5, ctx->r1);
    // lw          $v1, 0x1088($at)
    ctx->r3 = MEM_W(0X1088, ctx->r1);
    // lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(0X48, ctx->r29);
    // lbu         $s1, 0x4C($sp)
    ctx->r17 = MEM_BU(0X4C, ctx->r29);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_800508EC
    if (ctx->r3 == 0) {
        // andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
        goto L_800508EC;
    }
    // andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
L_800508C4:
    // beq         $a0, $a2, L_80050910
    if (ctx->r4 == ctx->r6) {
        // nop
    
        goto L_80050910;
    }
    // nop

    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // addu        $at, $a1, $at
    ctx->r1 = ADD32(ctx->r5, ctx->r1);
    // lw          $v0, 0x1088($at)
    ctx->r2 = MEM_W(0X1088, ctx->r1);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_800508C4
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800508C4;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_800508EC:
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // bne         $v0, $a1, L_80050934
    if (ctx->r2 != ctx->r5) {
        // sllv        $v0, $a1, $s0
        ctx->r2 = S32(ctx->r5) << (ctx->r16 & 31);
        goto L_80050934;
    }
    // sllv        $v0, $a1, $s0
    ctx->r2 = S32(ctx->r5) << (ctx->r16 & 31);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x828($v1)
    ctx->r3 = MEM_W(-0X828, ctx->r3);
    // nop

    // lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(0X2, ctx->r3);
    // j           L_8005094C
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    goto L_8005094C;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_80050910:
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // addu        $at, $a1, $at
    ctx->r1 = ADD32(ctx->r5, ctx->r1);
    // lw          $a1, 0x1088($at)
    ctx->r5 = MEM_W(0X1088, ctx->r1);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x31E4
    ctx->r4 = ADD32(ctx->r4, 0X31E4);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_800508EC
    // andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    goto L_800508EC;
    // andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_80050934:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x828($v1)
    ctx->r3 = MEM_W(-0X828, ctx->r3);
    // nop

    // lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(0X2, ctx->r3);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
L_8005094C:
    // sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x828($v0)
    ctx->r2 = MEM_W(-0X828, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sll         $a2, $s0, 2
    ctx->r6 = S32(ctx->r16) << 2;
    // addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $v0, $v0, $a2
    ctx->r2 = S32(ctx->r2) << (ctx->r6 & 31);
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x1080
    ctx->r5 = ctx->r5 | 0X1080;
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x82C($a0)
    ctx->r4 = MEM_W(-0X82C, ctx->r4);
    // sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16) << 4;
    // lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(0X0, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // or          $v0, $v0, $s4
    ctx->r2 = ctx->r2 | ctx->r20;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
