#include "recomp.h"
#include "disable_warnings.h"

void sub_8005AB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
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
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x27($s0)
    ctx->r3 = MEM_BU(0X27, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8005ABFC
    if (ctx->r3 != ctx->r2) {
        // addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
        goto L_8005ABFC;
    }
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8005ABFC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8005ABFC;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $a2, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r6;
    // j           L_8005AC24
    // sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    goto L_8005AC24;
    // sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
L_8005ABFC:
    // lbu         $v1, 0x16($s0)
    ctx->r3 = MEM_BU(0X16, ctx->r16);
    // ori         $v0, $zero, 0x1E
    ctx->r2 = 0 | 0X1E;
    // beq         $v1, $v0, L_8005AC28
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x14
        ctx->r2 = 0 | 0X14;
        goto L_8005AC28;
    }
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // beq         $v1, $v0, L_8005AC2C
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x28
        ctx->r2 = 0 | 0X28;
        goto L_8005AC2C;
    }
    // ori         $v0, $zero, 0x28
    ctx->r2 = 0 | 0X28;
    // lbu         $v0, 0x2A($s0)
    ctx->r2 = MEM_BU(0X2A, ctx->r16);
    // sb          $a2, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r6;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
L_8005AC24:
    // lbu         $v1, 0x16($s0)
    ctx->r3 = MEM_BU(0X16, ctx->r16);
L_8005AC28:
    // ori         $v0, $zero, 0x28
    ctx->r2 = 0 | 0X28;
L_8005AC2C:
    // bne         $v1, $v0, L_8005AC78
    if (ctx->r3 != ctx->r2) {
        // sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18) << 16;
        goto L_8005AC78;
    }
    // sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18) << 16;
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x21C8
    ctx->r2 = ADD32(ctx->r2, -0X21C8);
    // sll         $v1, $a0, 6
    ctx->r3 = S32(ctx->r4) << 6;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8005AC74
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005AC74;
    }
    // nop

    // jalr        $v0
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
L_8005AC74:
    // sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18) << 16;
L_8005AC78:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // jal         0x8005BB50
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8005BB50(rdram, ctx);
    goto after_1;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_1:
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
