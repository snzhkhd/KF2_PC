#include "recomp.h"
#include "disable_warnings.h"

void sub_8004C358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(-0X4, ctx->r4);
    // addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
    // bne         $v0, $v1, L_8004C37C
    if (ctx->r2 != ctx->r3) {
        // addiu       $t1, $a0, -0x4
        ctx->r9 = ADD32(ctx->r4, -0X4);
        goto L_8004C37C;
    }
    // addiu       $t1, $a0, -0x4
    ctx->r9 = ADD32(ctx->r4, -0X4);
    // j           L_8004C4F8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8004C4F8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004C37C:
    // and         $v1, $v0, $v1
    ctx->r3 = ctx->r2 & ctx->r3;
    // sltu        $v0, $v1, $a1
    ctx->r2 = ctx->r3 < ctx->r5 ? 1 : 0;
    // beq         $v0, $zero, L_8004C458
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004C458;
    }
    // nop

    // addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
    // addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
L_8004C398:
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // nop

    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a2, $a3, $v0
    ctx->r6 = ADD32(ctx->r7, ctx->r2);
    // lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(0X4, ctx->r6);
    // nop

    // beq         $v0, $t2, L_8004C3D0
    if (ctx->r2 == ctx->r10) {
        // addiu       $a3, $a2, 0x4
        ctx->r7 = ADD32(ctx->r6, 0X4);
        goto L_8004C3D0;
    }
    // addiu       $a3, $a2, 0x4
    ctx->r7 = ADD32(ctx->r6, 0X4);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8004C458
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004C458;
    }
    // nop

    // j           L_8004C428
    // nop

    goto L_8004C428;
    // nop

L_8004C3D0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6414($v0)
    ctx->r2 = MEM_W(0X6414, ctx->r2);
    // subu        $v1, $a1, $t0
    ctx->r3 = SUB32(ctx->r5, ctx->r8);
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8004C458
    if (ctx->r2 != 0) {
        // ori         $v0, $v1, 0x1
        ctx->r2 = ctx->r3 | 0X1;
        goto L_8004C458;
    }
    // ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
    // sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // srl         $v0, $v1, 2
    ctx->r2 = S32(U32(ctx->r3) >> 2);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x6404($at)
    MEM_W(0X6404, ctx->r1) = ctx->r2;
    // sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6404($v0)
    ctx->r2 = MEM_W(0X6404, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x6404($at)
    MEM_W(0X6404, ctx->r1) = ctx->r2;
L_8004C428:
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // and         $v0, $v0, $t2
    ctx->r2 = ctx->r2 & ctx->r10;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // nop

    // and         $v0, $v0, $t2
    ctx->r2 = ctx->r2 & ctx->r10;
    // addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // sltu        $v0, $t0, $a1
    ctx->r2 = ctx->r8 < ctx->r5 ? 1 : 0;
    // bne         $v0, $zero, L_8004C398
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004C398;
    }
    // nop

L_8004C458:
    // lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(0X0, ctx->r9);
    // addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8004C4DC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004C4DC;
    }
    // nop

    // bgez        $a1, L_8004C47C
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
        goto L_8004C47C;
    }
    // addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // addiu       $v1, $a1, 0x3
    ctx->r3 = ADD32(ctx->r5, 0X3);
L_8004C47C:
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // bgez        $a1, L_8004C4A8
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_8004C4A8;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
L_8004C4A8:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(0X4, ctx->r2);
    // nop

    // ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(0X0, ctx->r9);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // j           L_8004C4F4
    // sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    goto L_8004C4F4;
    // sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_8004C4DC:
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // beq         $v0, $zero, L_8004C4F8
    if (ctx->r2 == 0) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_8004C4F8;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8004C4F4:
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8004C4F8:
    // jr          $ra
    // nop

    return;
    // nop

;}
