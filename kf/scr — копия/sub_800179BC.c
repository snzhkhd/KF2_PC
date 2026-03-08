#include "recomp.h"
#include "disable_warnings.h"

void sub_800179BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // jal         0x80017920
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    sub_80017920(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    after_0:
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80017A7C
    if (ctx->r3 == ctx->r2) {
        // subu        $v0, $s0, $s1
        ctx->r2 = SUB32(ctx->r16, ctx->r17);
        goto L_80017A7C;
    }
    // subu        $v0, $s0, $s1
    ctx->r2 = SUB32(ctx->r16, ctx->r17);
L_800179EC:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // addiu       $s2, $v0, 0xC
    ctx->r18 = ADD32(ctx->r2, 0XC);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80017A18
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_80017A18;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // jal         0x800177B0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_800177B0(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_80017A18:
    // bne         $v1, $v0, L_80017A68
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80017A68;
    }
    // nop

    // beq         $s0, $s1, L_80017A64
    if (ctx->r16 == ctx->r17) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80017A64;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // srl         $v1, $v0, 2
    ctx->r3 = S32(U32(ctx->r2) >> 2);
L_80017A38:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // bne         $v1, $zero, L_80017A38
    if (ctx->r3 != 0) {
        // addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
        goto L_80017A38;
    }
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // addiu       $v1, $s1, 0xC
    ctx->r3 = ADD32(ctx->r17, 0XC);
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // j           L_80017A68
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    goto L_80017A68;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80017A64:
    // addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
L_80017A68:
    // addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_800179EC
    if (ctx->r3 != ctx->r2) {
        // subu        $v0, $s0, $s1
        ctx->r2 = SUB32(ctx->r16, ctx->r17);
        goto L_800179EC;
    }
    // subu        $v0, $s0, $s1
    ctx->r2 = SUB32(ctx->r16, ctx->r17);
L_80017A7C:
    // addiu       $v0, $v0, -0xC
    ctx->r2 = ADD32(ctx->r2, -0XC);
    // sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
