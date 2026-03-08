#include "recomp.h"
#include "disable_warnings.h"

void sub_8005CB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3) >> 14;
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0xA0($a3)
    ctx->r2 = MEM_W(0XA0, ctx->r7);
    // lh          $t0, 0x44($a3)
    ctx->r8 = MEM_H(0X44, ctx->r7);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // blez        $t0, L_8005CBD4
    if (SIGNED(ctx->r8) <= 0) {
        // sw          $v0, 0xA0($a3)
        MEM_W(0XA0, ctx->r7) = ctx->r2;
        goto L_8005CBD4;
    }
    // sw          $v0, 0xA0($a3)
    MEM_W(0XA0, ctx->r7) = ctx->r2;
    // divu        $zero, $v0, $t0
    lo = S32(U32(ctx->r2) / U32(ctx->r8)); hi = S32(U32(ctx->r2) % U32(ctx->r8));
    // bne         $t0, $zero, L_8005CB98
    if (ctx->r8 != 0) {
        // nop
    
        goto L_8005CB98;
    }
    // nop

    // break       7
    do_break(2147863444);
L_8005CB98:
    // mfhi        $v0
    ctx->r2 = hi;
    // nop

    // bne         $v0, $zero, L_8005CD10
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005CD10;
    }
    // nop

    // lw          $v1, 0x8C($a3)
    ctx->r3 = MEM_W(0X8C, ctx->r7);
    // lw          $a0, 0xA4($a3)
    ctx->r4 = MEM_W(0XA4, ctx->r7);
    // nop

    // sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8005CBCC
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8005CBCC;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_8005CC1C
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_8005CC1C;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8005CBCC:
    // j           L_8005CC1C
    // sw          $v0, 0x8C($a3)
    MEM_W(0X8C, ctx->r7) = ctx->r2;
    goto L_8005CC1C;
    // sw          $v0, 0x8C($a3)
    MEM_W(0X8C, ctx->r7) = ctx->r2;
L_8005CBD4:
    // lw          $v1, 0x8C($a3)
    ctx->r3 = MEM_W(0X8C, ctx->r7);
    // lw          $a0, 0xA4($a3)
    ctx->r4 = MEM_W(0XA4, ctx->r7);
    // nop

    // sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8005CBF8
    if (ctx->r2 == 0) {
        // addu        $v0, $t0, $v1
        ctx->r2 = ADD32(ctx->r8, ctx->r3);
        goto L_8005CBF8;
    }
    // addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // sw          $v0, 0x8C($a3)
    MEM_W(0X8C, ctx->r7) = ctx->r2;
    // j           L_8005CC10
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    goto L_8005CC10;
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
L_8005CBF8:
    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_8005CC1C
    if (ctx->r2 == 0) {
        // subu        $v0, $v1, $t0
        ctx->r2 = SUB32(ctx->r3, ctx->r8);
        goto L_8005CC1C;
    }
    // subu        $v0, $v1, $t0
    ctx->r2 = SUB32(ctx->r3, ctx->r8);
    // lw          $a0, 0xA4($a3)
    ctx->r4 = MEM_W(0XA4, ctx->r7);
    // sw          $v0, 0x8C($a3)
    MEM_W(0X8C, ctx->r7) = ctx->r2;
    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
L_8005CC10:
    // beq         $v0, $zero, L_8005CC1C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005CC1C;
    }
    // nop

    // sw          $a0, 0x8C($a3)
    MEM_W(0X8C, ctx->r7) = ctx->r4;
L_8005CC1C:
    // lh          $v1, 0x4A($a3)
    ctx->r3 = MEM_H(0X4A, ctx->r7);
    // lw          $v0, 0x8C($a3)
    ctx->r2 = MEM_W(0X8C, ctx->r7);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5D30($v0)
    ctx->r2 = MEM_W(-0X5D30, ctx->r2);
    // nop

    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_8005CC68
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8005CC68;
    }
    // nop

    // break       7
    do_break(2147863652);
L_8005CC68:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // sh          $v0, 0x70($a3)
    MEM_H(0X70, ctx->r7) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8005CC84
    if (SIGNED(ctx->r2) > 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005CC84;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x70($a3)
    MEM_H(0X70, ctx->r7) = ctx->r2;
L_8005CC84:
    // lw          $v0, 0xA0($a3)
    ctx->r2 = MEM_W(0XA0, ctx->r7);
    // nop

    // beq         $v0, $zero, L_8005CCA8
    if (ctx->r2 == 0) {
        // sll         $a2, $a2, 16
        ctx->r6 = S32(ctx->r6) << 16;
        goto L_8005CCA8;
    }
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // lw          $v1, 0x8C($a3)
    ctx->r3 = MEM_W(0X8C, ctx->r7);
    // lw          $v0, 0xA4($a3)
    ctx->r2 = MEM_W(0XA4, ctx->r7);
    // nop

    // bne         $v1, $v0, L_8005CD10
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005CD10;
    }
    // nop

L_8005CCA8:
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, -0x2248
    ctx->r4 = ADD32(ctx->r4, -0X2248);
    // sra         $a2, $a2, 14
    ctx->r6 = S32(ctx->r6) >> 14;
    // addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(0X0, ctx->r6);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // lw          $v1, 0x90($a1)
    ctx->r3 = MEM_W(0X90, ctx->r5);
    // addiu       $a0, $zero, -0x41
    ctx->r4 = ADD32(0, -0X41);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // sw          $v1, 0x90($a1)
    MEM_W(0X90, ctx->r5) = ctx->r3;
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(0X90, ctx->r2);
    // addiu       $a0, $zero, -0x81
    ctx->r4 = ADD32(0, -0X81);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // sw          $v1, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r3;
L_8005CD10:
    // jr          $ra
    // nop

    return;
    // nop

;}
