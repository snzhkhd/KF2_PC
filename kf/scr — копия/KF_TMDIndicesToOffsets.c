#include "recomp.h"
#include "disable_warnings.h"

void KF_TMDIndicesToOffsets(uint8_t* rdram, recomp_context* ctx) 
{
  /*  printf("[KF_TMDIndicesToOffsets] a1=%08X *(a1+8)=%d\n", ctx->r4, *(int*)(GET_PTR(ctx->r4) + 8));*/

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(0X8, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // beq         $t0, $v0, L_80030400
    if (ctx->r8 == ctx->r2) {
        // addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
        goto L_80030400;
    }
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // addiu       $t1, $a0, 0x1C
    ctx->r9 = ADD32(ctx->r4, 0X1C);
L_8003014C:
    // lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(0X0, ctx->r9);
    // lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(0X4, ctx->r9);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $a3, $a0, $v0
    ctx->r7 = ADD32(ctx->r4, ctx->r2);
L_8003015C:
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // beq         $a2, $t2, L_800303F4
    if (ctx->r6 == ctx->r10) {
        // addiu       $a1, $a3, 0x4
        ctx->r5 = ADD32(ctx->r7, 0X4);
        goto L_800303F4;
    }
    // addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // lbu         $v0, 0x1($a3)
    ctx->r2 = MEM_BU(0X1, ctx->r7);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a3, $a1, $v0
    ctx->r7 = ADD32(ctx->r5, ctx->r2);
    // srl         $v1, $v1, 24
    ctx->r3 = S32(U32(ctx->r3) >> 24);
    // andi        $v1, $v1, 0xFD
    ctx->r3 = ctx->r3 & 0XFD;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // sltiu       $v0, $v1, 0x1D
    ctx->r2 = ctx->r3 < 0X1D ? 1 : 0;
    // beq         $v0, $zero, L_8003015C
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8003015C;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x150C
    ctx->r1 = ADD32(ctx->r1, 0X150C);
    // addu        $at, $at, $v0
    gpr jr_addend_800301A4;
    jr_addend_800301A4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800301A4 >> 2) {
        case 0: goto L_800301AC; break;
        case 1: goto L_8003015C; break;
        case 2: goto L_8003015C; break;
        case 3: goto L_8003015C; break;
        case 4: goto L_8003022C; break;
        case 5: goto L_8003015C; break;
        case 6: goto L_8003015C; break;
        case 7: goto L_8003015C; break;
        case 8: goto L_800302AC; break;
        case 9: goto L_8003015C; break;
        case 10: goto L_8003015C; break;
        case 11: goto L_8003015C; break;
        case 12: goto L_80030350; break;
        case 13: goto L_8003015C; break;
        case 14: goto L_8003015C; break;
        case 15: goto L_8003015C; break;
        case 16: goto L_800301E0; break;
        case 17: goto L_8003015C; break;
        case 18: goto L_8003015C; break;
        case 19: goto L_8003015C; break;
        case 20: goto L_80030260; break;
        case 21: goto L_8003015C; break;
        case 22: goto L_8003015C; break;
        case 23: goto L_8003015C; break;
        case 24: goto L_800302EC; break;
        case 25: goto L_8003015C; break;
        case 26: goto L_8003015C; break;
        case 27: goto L_8003015C; break;
        case 28: goto L_80030390; break;
        default: switch_error(__func__, 0x800301A4, 0x8001150C);
    }
    // nop

L_800301AC:
    // lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(0X6, ctx->r5);
    // lhu         $v1, 0x8($a1)
    ctx->r3 = MEM_HU(0X8, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xA($a1)
    ctx->r2 = MEM_HU(0XA, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(0X4, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // j           L_8003015C
    // sh          $v1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r3;
    goto L_8003015C;
    // sh          $v1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r3;
L_800301E0:
    // lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(0X6, ctx->r5);
    // lhu         $v1, 0xA($a1)
    ctx->r3 = MEM_HU(0XA, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xE($a1)
    ctx->r2 = MEM_HU(0XE, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(0X4, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(0X8, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r3;
    // lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(0XC, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // j           L_8003015C
    // sh          $v1, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r3;
    goto L_8003015C;
    // sh          $v1, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r3;
L_8003022C:
    // lhu         $v0, 0xE($a1)
    ctx->r2 = MEM_HU(0XE, ctx->r5);
    // lhu         $v1, 0x10($a1)
    ctx->r3 = MEM_HU(0X10, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x12($a1)
    ctx->r2 = MEM_HU(0X12, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r3;
    // lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(0XC, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r2;
    // j           L_8003015C
    // sh          $v1, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r3;
    goto L_8003015C;
    // sh          $v1, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r3;
L_80030260:
    // lhu         $v0, 0xE($a1)
    ctx->r2 = MEM_HU(0XE, ctx->r5);
    // lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(0X12, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x16($a1)
    ctx->r2 = MEM_HU(0X16, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r3;
    // lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(0XC, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x10($a1)
    ctx->r2 = MEM_HU(0X10, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x14($a1)
    ctx->r3 = MEM_HU(0X14, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    // j           L_8003015C
    // sh          $v1, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r3;
    goto L_8003015C;
    // sh          $v1, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r3;
L_800302AC:
    // lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(0X6, ctx->r5);
    // lhu         $v1, 0xA($a1)
    ctx->r3 = MEM_HU(0XA, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(0X8, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(0X4, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(0XC, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // j           L_8003015C
    // sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
    goto L_8003015C;
    // sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
L_800302EC:
    // lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(0X6, ctx->r5);
    // lhu         $v1, 0xA($a1)
    ctx->r3 = MEM_HU(0XA, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xE($a1)
    ctx->r2 = MEM_HU(0XE, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(0X12, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(0X4, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x8($a1)
    ctx->r3 = MEM_HU(0X8, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(0XC, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x10($a1)
    ctx->r3 = MEM_HU(0X10, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
    // j           L_8003015C
    // sh          $v1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r3;
    goto L_8003015C;
    // sh          $v1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r3;
L_80030350:
    // lhu         $v0, 0x12($a1)
    ctx->r2 = MEM_HU(0X12, ctx->r5);
    // lhu         $v1, 0x16($a1)
    ctx->r3 = MEM_HU(0X16, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x14($a1)
    ctx->r2 = MEM_HU(0X14, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x10($a1)
    ctx->r3 = MEM_HU(0X10, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x18($a1)
    ctx->r2 = MEM_HU(0X18, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // j           L_8003015C
    // sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    goto L_8003015C;
    // sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
L_80030390:
    // lhu         $v0, 0x12($a1)
    ctx->r2 = MEM_HU(0X12, ctx->r5);
    // lhu         $v1, 0x16($a1)
    ctx->r3 = MEM_HU(0X16, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x1A($a1)
    ctx->r2 = MEM_HU(0X1A, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x1E($a1)
    ctx->r3 = MEM_HU(0X1E, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x10($a1)
    ctx->r2 = MEM_HU(0X10, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x14($a1)
    ctx->r3 = MEM_HU(0X14, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x18($a1)
    ctx->r2 = MEM_HU(0X18, ctx->r5);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v1, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r3;
    // lhu         $v1, 0x1C($a1)
    ctx->r3 = MEM_HU(0X1C, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    // j           L_8003015C
    // sh          $v1, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r3;
    goto L_8003015C;
    // sh          $v1, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r3;
L_800303F4:
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // bne         $t0, $t2, L_8003014C
    if (ctx->r8 != ctx->r10) {
        // addiu       $t1, $t1, 0x1C
        ctx->r9 = ADD32(ctx->r9, 0X1C);
        goto L_8003014C;
    }
    // addiu       $t1, $t1, 0x1C
    ctx->r9 = ADD32(ctx->r9, 0X1C);
L_80030400:
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // jr          $ra
    // nop

    return;
    // nop

;}
