#include "recomp.h"
#include "disable_warnings.h"

void FormatHUDNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80024B48
    if (ctx->r2 != 0) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_80024B48;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // bne         $a3, $v0, L_80024B50
    if (ctx->r7 != ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80024B50;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
L_80024B48:
    // j           L_80024B78
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    goto L_80024B78;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80024B50:
    // beq         $a3, $v0, L_80024B64
    if (ctx->r7 == ctx->r2) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_80024B64;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // bne         $a3, $v0, L_80024B6C
    if (ctx->r7 != ctx->r2) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_80024B6C;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
L_80024B64:
    // j           L_80024B78
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    goto L_80024B78;
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_80024B6C:
    // bne         $a3, $v0, L_80024B78
    if (ctx->r7 != ctx->r2) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_80024B78;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
L_80024B78:
    // sltiu       $v0, $a2, 0x1
    ctx->r2 = ctx->r6 < 0X1 ? 1 : 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // blez        $a1, L_80024BA0
    if (SIGNED(ctx->r5) <= 0) {
        // andi        $a2, $v0, 0xA
        ctx->r6 = ctx->r2 & 0XA;
        goto L_80024BA0;
    }
    // andi        $a2, $v0, 0xA
    ctx->r6 = ctx->r2 & 0XA;
    // addu        $v1, $t1, $zero
    ctx->r3 = ADD32(ctx->r9, 0);
L_80024B8C:
    // sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80024B8C
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80024B8C;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80024BA0:
    // addu        $v1, $t1, $a1
    ctx->r3 = ADD32(ctx->r9, ctx->r5);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $a3, $v0, L_80024BC4
    if (ctx->r7 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80024BC4;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // ori         $v0, $zero, 0x13
    ctx->r2 = 0 | 0X13;
    // j           L_80024C44
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    goto L_80024C44;
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
L_80024BC4:
    // bne         $a3, $v0, L_80024BD4
    if (ctx->r7 != ctx->r2) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_80024BD4;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // j           L_80024C3C
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    goto L_80024C3C;
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
L_80024BD4:
    // bne         $a3, $v0, L_80024BF0
    if (ctx->r7 != ctx->r2) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_80024BF0;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_80024C44
    // sb          $v0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r2;
    goto L_80024C44;
    // sb          $v0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r2;
L_80024BF0:
    // bne         $a3, $v0, L_80024C14
    if (ctx->r7 != ctx->r2) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_80024C14;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    // ori         $v0, $zero, 0x12
    ctx->r2 = 0 | 0X12;
    // sb          $v0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r2;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_80024C44
    // sb          $v0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r2;
    goto L_80024C44;
    // sb          $v0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r2;
L_80024C14:
    // bne         $a3, $v0, L_80024C30
    if (ctx->r7 != ctx->r2) {
        // ori         $v0, $zero, 0x6
        ctx->r2 = 0 | 0X6;
        goto L_80024C30;
    }
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // ori         $v0, $zero, 0xE
    ctx->r2 = 0 | 0XE;
    // sb          $v0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r2;
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // j           L_80024C44
    // sb          $v0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r2;
    goto L_80024C44;
    // sb          $v0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r2;
L_80024C30:
    // bne         $a3, $v0, L_80024C48
    if (ctx->r7 != ctx->r2) {
        // addiu       $t0, $a1, -0x1
        ctx->r8 = ADD32(ctx->r5, -0X1);
        goto L_80024C48;
    }
    // addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
    // ori         $v0, $zero, 0xB
    ctx->r2 = 0 | 0XB;
L_80024C3C:
    // sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_80024C44:
    // addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
L_80024C48:
    // bltz        $t0, L_80024CA0
    if (SIGNED(ctx->r8) < 0) {
        // lui         $a3, 0x6666
        ctx->r7 = S32(0X6666 << 16);
        goto L_80024CA0;
    }
    // lui         $a3, 0x6666
    ctx->r7 = S32(0X6666 << 16);
    // ori         $a3, $a3, 0x6667
    ctx->r7 = ctx->r7 | 0X6667;
    // addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // addu        $a2, $t1, $zero
    ctx->r6 = ADD32(ctx->r9, 0);
    // mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80024C60:
    // sra         $v0, $a0, 31
    ctx->r2 = S32(ctx->r4) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // bne         $a0, $zero, L_80024C90
    if (ctx->r4 != 0) {
        // sb          $v0, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_80024C90;
    }
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // addiu       $a1, $t1, -0x1
    ctx->r5 = ADD32(ctx->r9, -0X1);
L_80024C90:
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // slt         $v0, $a1, $a2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // beq         $v0, $zero, L_80024C60
    if (ctx->r2 == 0) {
        // mult        $a0, $a3
        result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80024C60;
    }
    // mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80024CA0:
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // jr          $ra
    // nop

    return;
    // nop

;}
