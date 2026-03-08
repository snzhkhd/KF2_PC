#include "recomp.h"
#include "disable_warnings.h"

void sub_8002EB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // lhu         $a3, 0x4F4C($a3)
    ctx->r7 = MEM_HU(0X4F4C, ctx->r7);
    // lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(0X4, ctx->r4);
    // lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // lhu         $t0, 0x4F50($t0)
    ctx->r8 = MEM_HU(0X4F50, ctx->r8);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // srl         $v1, $v1, 12
    ctx->r3 = S32(U32(ctx->r3) >> 12);
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // srl         $a0, $a0, 12
    ctx->r4 = S32(U32(ctx->r4) >> 12);
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // nop

    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // subu        $t0, $v0, $a0
    ctx->r8 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // bgez        $v0, L_8002EB90
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $t3, $v1, $zero
        ctx->r11 = ADD32(ctx->r3, 0);
        goto L_8002EB90;
    }
    // addu        $t3, $v1, $zero
    ctx->r11 = ADD32(ctx->r3, 0);
    // negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // j           L_8002EB94
    // addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    goto L_8002EB94;
    // addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_8002EB90:
    // ori         $t5, $zero, 0x1
    ctx->r13 = 0 | 0X1;
L_8002EB94:
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // bgez        $v0, L_8002EBA8
    if (SIGNED(ctx->r2) >= 0) {
        // ori         $t4, $zero, 0x1
        ctx->r12 = 0 | 0X1;
        goto L_8002EBA8;
    }
    // ori         $t4, $zero, 0x1
    ctx->r12 = 0 | 0X1;
    // negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_8002EBA8:
    // sll         $a1, $t3, 16
    ctx->r5 = S32(ctx->r11) << 16;
    // sra         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) >> 16;
    // sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8) << 16;
    // sra         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8002EC44
    if (ctx->r2 != 0) {
        // addu        $a3, $t0, $zero
        ctx->r7 = ADD32(ctx->r8, 0);
        goto L_8002EC44;
    }
    // addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    // sra         $a1, $a1, 17
    ctx->r5 = S32(ctx->r5) >> 17;
    // addu        $a3, $t3, $zero
    ctx->r7 = ADD32(ctx->r11, 0);
    // lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // addiu       $t6, $t6, 0x4F60
    ctx->r14 = ADD32(ctx->r14, 0X4F60);
    // andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
L_8002EBD8:
    // sltiu       $v0, $a0, 0x18
    ctx->r2 = ctx->r4 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8002EC04
    if (ctx->r2 == 0) {
        // andi        $v1, $t1, 0xFFFF
        ctx->r3 = ctx->r9 & 0XFFFF;
        goto L_8002EC04;
    }
    // andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // sltiu       $v0, $v1, 0x18
    ctx->r2 = ctx->r3 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8002EC04
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_8002EC04;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_8002EC04:
    // subu        $v1, $a1, $t0
    ctx->r3 = SUB32(ctx->r5, ctx->r8);
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // bgtz        $v0, L_8002EC20
    if (SIGNED(ctx->r2) > 0) {
        // addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
        goto L_8002EC20;
    }
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // addu        $v0, $t1, $t4
    ctx->r2 = ADD32(ctx->r9, ctx->r12);
    // addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // addu        $a1, $t3, $v1
    ctx->r5 = ADD32(ctx->r11, ctx->r3);
L_8002EC20:
    // addu        $v0, $t2, $t5
    ctx->r2 = ADD32(ctx->r10, ctx->r13);
    // addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8002EBD8
    if (SIGNED(ctx->r2) >= 0) {
        // andi        $a0, $t2, 0xFFFF
        ctx->r4 = ctx->r10 & 0XFFFF;
        goto L_8002EBD8;
    }
    // andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
    // j           L_8002ECB8
    // nop

    goto L_8002ECB8;
    // nop

L_8002EC44:
    // sra         $a1, $a0, 17
    ctx->r5 = S32(ctx->r4) >> 17;
    // lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // addiu       $t6, $t6, 0x4F60
    ctx->r14 = ADD32(ctx->r14, 0X4F60);
    // andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
L_8002EC54:
    // sltiu       $v0, $a0, 0x18
    ctx->r2 = ctx->r4 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8002EC80
    if (ctx->r2 == 0) {
        // andi        $v1, $t1, 0xFFFF
        ctx->r3 = ctx->r9 & 0XFFFF;
        goto L_8002EC80;
    }
    // andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // sltiu       $v0, $v1, 0x18
    ctx->r2 = ctx->r3 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8002EC80
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_8002EC80;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_8002EC80:
    // subu        $v1, $a1, $t3
    ctx->r3 = SUB32(ctx->r5, ctx->r11);
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // bgtz        $v0, L_8002EC9C
    if (SIGNED(ctx->r2) > 0) {
        // addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
        goto L_8002EC9C;
    }
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // addu        $v0, $t2, $t5
    ctx->r2 = ADD32(ctx->r10, ctx->r13);
    // addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
L_8002EC9C:
    // addu        $v0, $t1, $t4
    ctx->r2 = ADD32(ctx->r9, ctx->r12);
    // addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8002EC54
    if (SIGNED(ctx->r2) >= 0) {
        // andi        $a0, $t2, 0xFFFF
        ctx->r4 = ctx->r10 & 0XFFFF;
        goto L_8002EC54;
    }
    // andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
L_8002ECB8:
    // jr          $ra
    // nop

    return;
    // nop

;}
