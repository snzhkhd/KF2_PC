#include "recomp.h"
#include "disable_warnings.h"

void sub_8003DDB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // lw          $s0, 0x79B4($s0)
    ctx->r16 = MEM_W(0X79B4, ctx->r16);
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(0X0, ctx->r17);
    // lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(0X2C, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(0X2, ctx->r17);
    // lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(0X30, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lh          $v0, 0x4($s1)
    ctx->r2 = MEM_H(0X4, ctx->r17);
    // lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(0X34, ctx->r16);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lhu         $a0, 0x79AC($a0)
    ctx->r4 = MEM_HU(0X79AC, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lhu         $a3, 0x1C($s0)
    ctx->r7 = MEM_HU(0X1C, ctx->r16);
    // lhu         $v1, 0x1E($s0)
    ctx->r3 = MEM_HU(0X1E, ctx->r16);
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(0X1C, ctx->r29);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // jal         0x8002E4F4
    // nop

    sub_8002E4F4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // bne         $s2, $zero, L_8003DE74
    if (ctx->r18 != 0) {
        // nop
    
        goto L_8003DE74;
    }
    // nop

    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(0X1C, ctx->r29);
    // nop

    // sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // j           L_8003DF78
    // sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    goto L_8003DF78;
    // sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
L_8003DE74:
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // lhu         $a3, 0x1C($s0)
    ctx->r7 = MEM_HU(0X1C, ctx->r16);
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lhu         $a0, 0x79AC($a0)
    ctx->r4 = MEM_HU(0X79AC, ctx->r4);
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(0X30, ctx->r16);
    // lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(0X34, ctx->r16);
    // jal         0x8002E4F4
    // nop

    sub_8002E4F4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // beq         $v0, $zero, L_8003DECC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003DECC;
    }
    // nop

    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_8003DF78
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    goto L_8003DF78;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8003DECC:
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // lhu         $a3, 0x1C($s0)
    ctx->r7 = MEM_HU(0X1C, ctx->r16);
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lhu         $a0, 0x79AC($a0)
    ctx->r4 = MEM_HU(0X79AC, ctx->r4);
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(0X1C, ctx->r29);
    // lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(0X34, ctx->r16);
    // jal         0x8002E4F4
    // nop

    sub_8002E4F4(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // beq         $v0, $zero, L_8003DF24
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003DF24;
    }
    // nop

    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_8003DF78
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    goto L_8003DF78;
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
L_8003DF24:
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // lhu         $a3, 0x1C($s0)
    ctx->r7 = MEM_HU(0X1C, ctx->r16);
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lhu         $a0, 0x79AC($a0)
    ctx->r4 = MEM_HU(0X79AC, ctx->r4);
    // andi        $v1, $v1, 0xC000
    ctx->r3 = ctx->r3 & 0XC000;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(0X30, ctx->r16);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // jal         0x8002E4F4
    // nop

    sub_8002E4F4(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // beq         $v0, $zero, L_8003DF7C
    if (ctx->r2 == 0) {
        // addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
        goto L_8003DF7C;
    }
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
L_8003DF78:
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_8003DF7C:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
