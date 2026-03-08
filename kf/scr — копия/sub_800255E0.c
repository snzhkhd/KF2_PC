#include "recomp.h"
#include "disable_warnings.h"

void sub_800255E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x121C
    ctx->r5 = ADD32(ctx->r5, 0X121C);
    // lwl         $v0, 0x3($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r5);
    // lwr         $v0, 0x0($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r5);
    // lb          $v1, 0x4($a1)
    ctx->r3 = MEM_B(0X4, ctx->r5);
    // lb          $a0, 0x5($a1)
    ctx->r4 = MEM_B(0X5, ctx->r5);
    // swl         $v0, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r2);
    // swr         $v0, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r2);
    // sb          $v1, 0x14($sp)
    MEM_B(0X14, ctx->r29) = ctx->r3;
    // sb          $a0, 0x15($sp)
    MEM_B(0X15, ctx->r29) = ctx->r4;
    // addiu       $a0, $sp, 0x16
    ctx->r4 = ADD32(ctx->r29, 0X16);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80062B80
    // ori         $a2, $zero, 0x22
    ctx->r6 = 0 | 0X22;
    memset_recomp(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0x22
    ctx->r6 = 0 | 0X22;
    after_0:
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80025638:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x1F58
    ctx->r5 = ADD32(ctx->r5, -0X1F58);
    // jal         0x80062B90
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    strcat_recomp(rdram, ctx);
    goto after_1;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // addiu       $v0, $s3, 0x30
    ctx->r2 = ADD32(ctx->r19, 0X30);
    // sb          $v0, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r2;
    // jal         0x80062B10
    // sb          $zero, 0x22($sp)
    MEM_B(0X22, ctx->r29) = 0;
    open(rdram, ctx);
    goto after_2;
    // sb          $zero, 0x22($sp)
    MEM_B(0X22, ctx->r29) = 0;
    after_2:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_8002568C
    if (ctx->r16 == ctx->r2) {
        // addu        $s2, $s3, $zero
        ctx->r18 = ADD32(ctx->r19, 0);
        goto L_8002568C;
    }
    // addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $a1, 0x138($gp)
    ctx->r5 = MEM_W(0X138, ctx->r28);
    // jal         0x80062AC0
    // ori         $a2, $zero, 0x4000
    ctx->r6 = 0 | 0X4000;
    read(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0x4000
    ctx->r6 = 0 | 0X4000;
    after_3:
    // ori         $v1, $zero, 0x4000
    ctx->r3 = 0 | 0X4000;
    // beq         $v0, $v1, L_80025694
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80025694;
    }
    // nop

L_8002568C:
    // j           L_800256D0
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    goto L_800256D0;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
L_80025694:
    // jal         0x80062850
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // lw          $s0, 0x138($gp)
    ctx->r16 = MEM_W(0X138, ctx->r28);
    // jal         0x80025D40
    // addiu       $a0, $s0, 0x400
    ctx->r4 = ADD32(ctx->r16, 0X400);
    sub_80025D40(rdram, ctx);
    goto after_5;
    // addiu       $a0, $s0, 0x400
    ctx->r4 = ADD32(ctx->r16, 0X400);
    after_5:
    // lw          $v1, 0x200($s0)
    ctx->r3 = MEM_W(0X200, ctx->r16);
    // nop

    // bne         $v1, $v0, L_800256D0
    if (ctx->r3 != ctx->r2) {
        // ori         $v1, $zero, 0x2
        ctx->r3 = 0 | 0X2;
        goto L_800256D0;
    }
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // lw          $a0, 0x138($gp)
    ctx->r4 = MEM_W(0X138, ctx->r28);
    // jal         0x8004BC5C
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    sub_8004BC5C(rdram, ctx);
    goto after_6;
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_6:
    // sb          $s2, 0x7C($gp)
    MEM_B(0X7C, ctx->r28) = ctx->r18;
    // j           L_800256E0
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_800256E0;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800256D0:
    // slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80025638
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80025638;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800256E0:
    // lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
