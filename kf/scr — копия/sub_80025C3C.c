#include "recomp.h"
#include "disable_warnings.h"

void sub_80025C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $t2, 0x6666
    ctx->r10 = S32(0X6666 << 16);
    // ori         $t2, $t2, 0x6667
    ctx->r10 = ctx->r10 | 0X6667;
    // ori         $t4, $zero, 0x19
    ctx->r12 = 0 | 0X19;
    // ori         $t3, $zero, 0x82
    ctx->r11 = 0 | 0X82;
    // ori         $v0, $zero, 0x82
    ctx->r2 = 0 | 0X82;
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // lw          $a3, -0x4B3C($a3)
    ctx->r7 = MEM_W(-0X4B3C, ctx->r7);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lbu         $t0, -0x4B34($t0)
    ctx->r8 = MEM_BU(-0X4B34, ctx->r8);
    // addiu       $a1, $a1, 0x4F
    ctx->r5 = ADD32(ctx->r5, 0X4F);
    // sb          $v0, 0x22($t1)
    MEM_B(0X22, ctx->r9) = ctx->r2;
    // sb          $a1, 0x23($t1)
    MEM_B(0X23, ctx->r9) = ctx->r5;
    // mult        $a3, $t2
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80025C78:
    // subu        $a0, $t4, $a2
    ctx->r4 = SUB32(ctx->r12, ctx->r6);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // sra         $v0, $a3, 31
    ctx->r2 = S32(ctx->r7) >> 31;
    // sb          $t3, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r11;
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
    // subu        $v0, $a3, $v0
    ctx->r2 = SUB32(ctx->r7, ctx->r2);
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v0, 0x4F
    ctx->r2 = ADD32(ctx->r2, 0X4F);
    // bne         $a3, $zero, L_80025CBC
    if (ctx->r7 != 0) {
        // sb          $v0, 0x5($a0)
        MEM_B(0X5, ctx->r4) = ctx->r2;
        goto L_80025CBC;
    }
    // sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // ori         $a2, $zero, 0x6
    ctx->r6 = 0 | 0X6;
L_80025CBC:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0x6
    ctx->r2 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_80025C78
    if (ctx->r2 != 0) {
        // mult        $a3, $t2
        result = S64(S32(ctx->r7)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80025C78;
    }
    // mult        $a3, $t2
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a1, 0x6666
    ctx->r5 = S32(0X6666 << 16);
    // ori         $a1, $a1, 0x6667
    ctx->r5 = ctx->r5 | 0X6667;
    // ori         $t2, $zero, 0x1E
    ctx->r10 = 0 | 0X1E;
    // ori         $a3, $zero, 0x82
    ctx->r7 = 0 | 0X82;
    // mult        $t0, $a1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80025CE4:
    // subu        $a0, $t2, $a2
    ctx->r4 = SUB32(ctx->r10, ctx->r6);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // sra         $v0, $t0, 31
    ctx->r2 = S32(ctx->r8) >> 31;
    // sb          $a3, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r7;
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
    // subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v0, 0x4F
    ctx->r2 = ADD32(ctx->r2, 0X4F);
    // bne         $t0, $zero, L_80025D28
    if (ctx->r8 != 0) {
        // sb          $v0, 0x5($a0)
        MEM_B(0X5, ctx->r4) = ctx->r2;
        goto L_80025D28;
    }
    // sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
L_80025D28:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0x2
    ctx->r2 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80025CE4
    if (ctx->r2 != 0) {
        // mult        $t0, $a1
        result = S64(S32(ctx->r8)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80025CE4;
    }
    // mult        $t0, $a1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // jr          $ra
    // nop

    return;
    // nop

;}
