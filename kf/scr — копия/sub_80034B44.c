#include "recomp.h"
#include "disable_warnings.h"

void sub_80034B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10) << 1;
    // addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // addiu       $a1, $a1, 0x4F50
    ctx->r5 = ADD32(ctx->r5, 0X4F50);
    // lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(0X8, ctx->r4);
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a2, $v0, $t2
    ctx->r6 = SUB32(ctx->r2, ctx->r10);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // lw          $v1, 0x4F4C($v1)
    ctx->r3 = MEM_W(0X4F4C, ctx->r3);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $t4, $v0, $t2
    ctx->r12 = SUB32(ctx->r2, ctx->r10);
    // addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $a3, $v0, $a1
    ctx->r7 = ADD32(ctx->r2, ctx->r5);
L_80034BA0:
    // bltz        $a2, L_80034BEC
    if (SIGNED(ctx->r6) < 0) {
        // sltiu       $v0, $a2, 0x18
        ctx->r2 = ctx->r6 < 0X18 ? 1 : 0;
        goto L_80034BEC;
    }
    // sltiu       $v0, $a2, 0x18
    ctx->r2 = ctx->r6 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_80034BEC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80034BEC;
    }
    // nop

    // addu        $v1, $t4, $zero
    ctx->r3 = ADD32(ctx->r12, 0);
    // addu        $a1, $t2, $zero
    ctx->r5 = ADD32(ctx->r10, 0);
    // addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
L_80034BBC:
    // bltz        $v1, L_80034BE0
    if (SIGNED(ctx->r3) < 0) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_80034BE0;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // sltiu       $v0, $v1, 0x18
    ctx->r2 = ctx->r3 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_80034BE0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80034BE0;
    }
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // or          $v0, $t1, $v0
    ctx->r2 = ctx->r9 | ctx->r2;
    // addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
L_80034BE0:
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // bne         $a1, $t3, L_80034BBC
    if (ctx->r5 != ctx->r11) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80034BBC;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80034BEC:
    // addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // bne         $t0, $t3, L_80034BA0
    if (ctx->r8 != ctx->r11) {
        // addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_80034BA0;
    }
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // jr          $ra
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    return;
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
;}
