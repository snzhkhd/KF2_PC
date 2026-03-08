#include "recomp.h"
#include "disable_warnings.h"

void sub_80057C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4) << 16;
    // srl         $t0, $t1, 24
    ctx->r8 = S32(U32(ctx->r9) >> 24);
    // sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8) << 1;
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $t0
    ctx->r3 = SUB32(ctx->r3, ctx->r8);
    // andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    ctx->r2 = MEM_W(0X0, ctx->r1);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $t0
    ctx->r3 = SUB32(ctx->r3, ctx->r8);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $a0, -0x191A($at)
    MEM_H(-0X191A, ctx->r1) = ctx->r4;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $a1, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r5;
    // lhu         $v0, 0x74($v1)
    ctx->r2 = MEM_HU(0X74, ctx->r3);
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // sra         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) >> 16;
    // sltiu       $v0, $v0, 0x80
    ctx->r2 = ctx->r2 < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80057CD8
    if (ctx->r2 != 0) {
        // sh          $a2, 0x76($v1)
        MEM_H(0X76, ctx->r3) = ctx->r6;
        goto L_80057CD8;
    }
    // sh          $a2, 0x76($v1)
    MEM_H(0X76, ctx->r3) = ctx->r6;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sh          $v0, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r2;
L_80057CD8:
    // lhu         $v0, 0x76($v1)
    ctx->r2 = MEM_HU(0X76, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x80
    ctx->r2 = ctx->r2 < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80057CF0
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x7F
        ctx->r2 = 0 | 0X7F;
        goto L_80057CF0;
    }
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sh          $v0, 0x76($v1)
    MEM_H(0X76, ctx->r3) = ctx->r2;
L_80057CF0:
    // andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // bne         $v0, $v1, L_80057DDC
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80057DDC;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x49D8($v0)
    ctx->r2 = MEM_BU(-0X49D8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80057DDC
    if (ctx->r2 == 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80057DDC;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // addiu       $a2, $a2, -0x7748
    ctx->r6 = ADD32(ctx->r6, -0X7748);
    // addiu       $a3, $a2, 0x2
    ctx->r7 = ADD32(ctx->r6, 0X2);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
L_80057D44:
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75A2
    ctx->r1 = ADD32(ctx->r1, -0X75A2);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // nop

    // bne         $v0, $t1, L_80057DBC
    if (ctx->r2 != ctx->r9) {
        // addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
        goto L_80057DBC;
    }
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // sll         $v0, $a0, 19
    ctx->r2 = S32(ctx->r4) << 19;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_80057DBC:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x49D8($v1)
    ctx->r3 = MEM_BU(-0X49D8, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80057D44
    if (ctx->r2 != 0) {
        // sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5) << 16;
        goto L_80057D44;
    }
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
L_80057DDC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x191A($v0)
    ctx->r2 = MEM_H(-0X191A, ctx->r2);
    // jr          $ra
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
