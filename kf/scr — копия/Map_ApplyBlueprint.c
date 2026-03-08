#include "recomp.h"
#include "disable_warnings.h"

void Map_ApplyBlueprint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(0X44, ctx->r29);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(0X48, ctx->r29);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sra         $s5, $a1, 11
    ctx->r21 = S32(ctx->r5) >> 11;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // jal         0x800602D0
    // sra         $s4, $a2, 11
    ctx->r20 = S32(ctx->r6) >> 11;
    FixedCos(rdram, ctx);
    goto after_0;
    // sra         $s4, $a2, 11
    ctx->r20 = S32(ctx->r6) >> 11;
    after_0:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800601F4
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    FixedSin(rdram, ctx);
    goto after_1;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_1:
    // addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // xori        $s0, $s0, 0x1
    ctx->r16 = ctx->r16 ^ 0X1;
    // sltu        $s0, $zero, $s0
    ctx->r16 = 0 < ctx->r16 ? 1 : 0;
    // negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
    // andi        $s0, $s0, 0x5
    ctx->r16 = ctx->r16 & 0X5;
    // sltiu       $v0, $s0, 0x1
    ctx->r2 = ctx->r16 < 0X1 ? 1 : 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // andi        $t3, $v0, 0x5
    ctx->r11 = ctx->r2 & 0X5;
    // lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(0X0, ctx->r18);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80037BE0
    if (ctx->r3 == ctx->r2) {
        // ori         $t2, $zero, 0xFE
        ctx->r10 = 0 | 0XFE;
        goto L_80037BE0;
    }
    // ori         $t2, $zero, 0xFE
    ctx->r10 = 0 | 0XFE;
    // ori         $t0, $zero, 0xFF
    ctx->r8 = 0 | 0XFF;
    // addiu       $a3, $s2, 0x9
    ctx->r7 = ADD32(ctx->r18, 0X9);
L_80037AAC:
    // lb          $a2, -0x1($a3)
    ctx->r6 = MEM_B(-0X1, ctx->r7);
    // nop

    // mult        $a2, $s1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lb          $v0, 0x0($a3)
    ctx->r2 = MEM_B(0X0, ctx->r7);
    // nop

    // mult        $v0, $t1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // mult        $a2, $t1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // sra         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5) >> 12;
    // addu        $a1, $a1, $s5
    ctx->r5 = ADD32(ctx->r5, ctx->r21);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) << 5;
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0x428C
    ctx->r3 = ADD32(ctx->r3, -0X428C);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $v0, $s6, 2
    ctx->r2 = S32(ctx->r22) << 2;
    // addu        $v1, $s2, $v0
    ctx->r3 = ADD32(ctx->r18, ctx->r2);
    // addu        $a1, $a0, $s0
    ctx->r5 = ADD32(ctx->r4, ctx->r16);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $t2, L_80037B4C
    if (ctx->r2 == ctx->r10) {
        // addu        $a0, $a0, $t3
        ctx->r4 = ADD32(ctx->r4, ctx->r11);
        goto L_80037B4C;
    }
    // addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
L_80037B4C:
    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // nop

    // beq         $v0, $t2, L_80037B68
    if (ctx->r2 == ctx->r10) {
        // nop
    
        goto L_80037B68;
    }
    // nop

    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // nop

    // sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
L_80037B68:
    // lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(0X2, ctx->r3);
    // nop

    // beq         $v0, $t0, L_80037B84
    if (ctx->r2 == ctx->r8) {
        // nop
    
        goto L_80037B84;
    }
    // nop

    // lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(0X2, ctx->r3);
    // nop

    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_80037B84:
    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // nop

    // beq         $v0, $t0, L_80037BA0
    if (ctx->r2 == ctx->r8) {
        // nop
    
        goto L_80037BA0;
    }
    // nop

    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // nop

    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80037BA0:
    // beq         $s3, $t0, L_80037BD0
    if (ctx->r19 == ctx->r8) {
        // addiu       $s2, $s2, 0xA
        ctx->r18 = ADD32(ctx->r18, 0XA);
        goto L_80037BD0;
    }
    // addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
    // lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(0X4, ctx->r5);
    // nop

    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // sb          $v0, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(0X4, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
L_80037BD0:
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // nop

    // bne         $v0, $t0, L_80037AAC
    if (ctx->r2 != ctx->r8) {
        // addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
        goto L_80037AAC;
    }
    // addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
L_80037BE0:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
