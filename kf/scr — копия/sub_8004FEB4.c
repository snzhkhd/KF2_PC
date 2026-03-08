#include "recomp.h"
#include "disable_warnings.h"

void sub_8004FEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x134($v0)
    ctx->r2 = MEM_W(0X134, ctx->r2);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // beq         $v0, $a0, L_8005081C
    if (ctx->r2 == ctx->r4) {
        // sw          $ra, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r31;
        goto L_8005081C;
    }
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // lw          $v0, -0x21A0($v0)
    ctx->r2 = MEM_W(-0X21A0, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004FF40
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004FF40;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x824($v0)
    ctx->r2 = MEM_W(-0X824, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8004FF40
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004FF40;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $a0, -0x1F78($at)
    MEM_W(-0X1F78, ctx->r1) = ctx->r4;
    // beq         $v0, $zero, L_8004FF30
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004FF30;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x118C($v0)
    ctx->r2 = MEM_W(0X118C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r2;
L_8004FF30:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $a0, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r4;
    // j           L_8005081C
    // nop

    goto L_8005081C;
    // nop

L_8004FF40:
    // jal         0x8004CA58
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    PadStartCom_0(rdram, ctx);
    goto after_0;
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // ori         $v1, $zero, 0x5
    ctx->r3 = 0 | 0X5;
    // beq         $v0, $v1, L_8005081C
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_8005081C;
    }
    // nop

    // lbu         $v0, 0x30($sp)
    ctx->r2 = MEM_BU(0X30, ctx->r29);
    // lbu         $v1, 0x31($sp)
    ctx->r3 = MEM_BU(0X31, ctx->r29);
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // sh          $v1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r3;
    // lhu         $v0, 0x22($sp)
    ctx->r2 = MEM_HU(0X22, ctx->r29);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_8004FF88
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x3
        ctx->r2 = 0 | 0X3;
        goto L_8004FF88;
    }
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r2;
    // j           L_8005081C
    // nop

    goto L_8005081C;
    // nop

L_8004FF88:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5D28($v0)
    ctx->r2 = MEM_W(-0X5D28, ctx->r2);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x10A8($v1)
    ctx->r3 = MEM_W(-0X10A8, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x774C($at)
    MEM_W(-0X774C, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004FFF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004FFF8;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004FFE8
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x4
        ctx->r2 = 0 | 0X4;
        goto L_8004FFE8;
    }
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x118C($v0)
    ctx->r2 = MEM_W(0X118C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
L_8004FFE8:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r2;
    // j           L_8005081C
    // nop

    goto L_8005081C;
    // nop

L_8004FFF8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x844($v0)
    ctx->r2 = MEM_W(-0X844, ctx->r2);
    // nop

    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x838($v0)
    ctx->r2 = MEM_W(-0X838, ctx->r2);
    // nop

    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x844($v0)
    ctx->r2 = MEM_W(-0X844, ctx->r2);
    // lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x838($v1)
    ctx->r3 = MEM_W(-0X838, ctx->r3);
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x834($v0)
    ctx->r2 = MEM_W(-0X834, ctx->r2);
    // ori         $a0, $a0, 0x943
    ctx->r4 = ctx->r4 | 0X943;
    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x830($v1)
    ctx->r3 = MEM_W(-0X830, ctx->r3);
    // ori         $v0, $zero, 0x1323
    ctx->r2 = 0 | 0X1323;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // lw          $v0, -0x219C($v0)
    ctx->r2 = MEM_W(-0X219C, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800500C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800500C0;
    }
    // nop

    // addiu       $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
L_80050074:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x83C($v0)
    ctx->r2 = MEM_W(-0X83C, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80050074
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80050074;
    }
    // nop

    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x83C($a0)
    ctx->r4 = MEM_W(-0X83C, ctx->r4);
L_800500A8:
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_800500A8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800500A8;
    }
    // nop

L_800500C0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80050100
    if (ctx->r2 == 0) {
        // lui         $t0, 0x1100
        ctx->r8 = S32(0X1100 << 16);
        goto L_80050100;
    }
    // lui         $t0, 0x1100
    ctx->r8 = S32(0X1100 << 16);
    // ori         $a2, $zero, 0x8
    ctx->r6 = 0 | 0X8;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, 0x118C($a1)
    ctx->r5 = MEM_W(0X118C, ctx->r5);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, -0x774C($a0)
    ctx->r4 = MEM_W(-0X774C, ctx->r4);
    // sll         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) << 11;
    // jal         0x8005082C
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    sub_8005082C(rdram, ctx);
    goto after_1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_1:
    // j           L_80050124
    // nop

    goto L_80050124;
    // nop

L_80050100:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, -0x774C($a1)
    ctx->r5 = MEM_W(-0X774C, ctx->r5);
    // ori         $a3, $zero, 0x8
    ctx->r7 = 0 | 0X8;
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // jal         0x80050860
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    sub_80050860(rdram, ctx);
    goto after_2;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
L_80050124:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x814($a0)
    ctx->r4 = MEM_W(-0X814, ctx->r4);
    // nop

    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8005015C
    if (ctx->r2 == 0) {
        // addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
        goto L_8005015C;
    }
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
L_80050148:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // bne         $v0, $zero, L_80050148
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80050148;
    }
    // nop

L_8005015C:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, -0x774C($v0)
    ctx->r2 = MEM_W(-0X774C, ctx->r2);
    // lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // lwl         $a0, 0x2B($sp)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X2B, ctx->r29);
    // lwr         $a0, 0x28($sp)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X28, ctx->r29);
    // nop

    // swl         $a0, 0x1F($v0)
    do_swl(rdram, 0X1F, ctx->r2, ctx->r4);
    // swr         $a0, 0x1C($v0)
    do_swr(rdram, 0X1C, ctx->r2, ctx->r4);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x834($v0)
    ctx->r2 = MEM_W(-0X834, ctx->r2);
    // ori         $v1, $v1, 0x843
    ctx->r3 = ctx->r3 | 0X843;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x830($v1)
    ctx->r3 = MEM_W(-0X830, ctx->r3);
    // ori         $v0, $zero, 0x1325
    ctx->r2 = 0 | 0X1325;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x19B0($v1)
    ctx->r3 = MEM_W(-0X19B0, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80050220
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80050220;
    }
    // nop

    // lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // lw          $a0, 0xA84($a0)
    ctx->r4 = MEM_W(0XA84, ctx->r4);
    // nop

    // beq         $a0, $zero, L_80050220
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80050220;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, -0x774C($v1)
    ctx->r3 = MEM_W(-0X774C, ctx->r3);
    // nop

    // lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(0X8, ctx->r3);
    // nop

    // beq         $a0, $v0, L_80050218
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80050218;
    }
    // nop

    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8005081C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005081C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x118C($v0)
    ctx->r2 = MEM_W(0X118C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r2;
    // j           L_8005081C
    // nop

    goto L_8005081C;
    // nop

L_80050218:
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $zero, -0x19B0($at)
    MEM_W(-0X19B0, ctx->r1) = 0;
L_80050220:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, -0x774C($a0)
    ctx->r4 = MEM_W(-0X774C, ctx->r4);
    // nop

    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // ori         $v1, $zero, 0x160
    ctx->r3 = 0 | 0X160;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $v1, L_8005025C
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8005025C;
    }
    // nop

    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lw          $v1, -0x1A00($v1)
    ctx->r3 = MEM_W(-0X1A00, ctx->r3);
    // srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // beq         $v0, $v1, L_800502A4
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_800502A4;
    }
    // nop

L_8005025C:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80050280
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80050280;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = 0;
    // j           L_80050284
    // nop

    goto L_80050284;
    // nop

L_80050280:
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
L_80050284:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, -0x774C($v1)
    ctx->r3 = MEM_W(-0X774C, ctx->r3);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r2;
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // j           L_8005081C
    // nop

    goto L_8005081C;
    // nop

L_800502A4:
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // lh          $v1, -0x21A4($v1)
    ctx->r3 = MEM_H(-0X21A4, ctx->r3);
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // bne         $v1, $v0, L_800502E0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800502E0;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, -0x6E80($v1)
    ctx->r3 = MEM_W(-0X6E80, ctx->r3);
    // nop

    // beq         $v1, $zero, L_80050364
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80050364;
    }
    // nop

    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // beq         $v1, $v0, L_80050364
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80050364;
    }
    // nop

L_800502E0:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5D24($a0)
    ctx->r4 = MEM_W(-0X5D24, ctx->r4);
    // lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // lw          $a1, -0x5D28($a1)
    ctx->r5 = MEM_W(-0X5D28, ctx->r5);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, -0x6E80($at)
    MEM_W(-0X6E80, ctx->r1) = 0;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $zero, -0x21A4($at)
    MEM_H(-0X21A4, ctx->r1) = 0;
    // jal         0x800509EC
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    sub_800509EC(rdram, ctx);
    goto after_3;
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_3:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5D24($v0)
    ctx->r2 = MEM_W(-0X5D24, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, -0x774C($v1)
    ctx->r3 = MEM_W(-0X774C, ctx->r3);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D28($at)
    MEM_W(-0X5D28, ctx->r1) = ctx->r2;
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80050354
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x6
        ctx->r2 = 0 | 0X6;
        goto L_80050354;
    }
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x118C($v0)
    ctx->r2 = MEM_W(0X118C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
L_80050354:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r2;
    // j           L_8005081C
    // nop

    goto L_8005081C;
    // nop

L_80050364:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, -0x774C($v1)
    ctx->r3 = MEM_W(-0X774C, ctx->r3);
    // nop

    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // bne         $v0, $zero, L_800505CC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xA
        ctx->r2 = 0 | 0XA;
        goto L_800505CC;
    }
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(0X8, ctx->r3);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x19B4($v1)
    ctx->r3 = MEM_W(-0X19B4, ctx->r3);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $zero, -0x21A4($at)
    MEM_H(-0X21A4, ctx->r1) = 0;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6E80($at)
    MEM_W(-0X6E80, ctx->r1) = ctx->r2;
    // beq         $v1, $zero, L_80050458
    if (ctx->r3 == 0) {
        // sltu        $v0, $v0, $v1
        ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
        goto L_80050458;
    }
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80050458
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80050458;
    }
    // nop

    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5D24($a0)
    ctx->r4 = MEM_W(-0X5D24, ctx->r4);
    // lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // lw          $a1, -0x5D28($a1)
    ctx->r5 = MEM_W(-0X5D28, ctx->r5);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, -0x6E80($at)
    MEM_W(-0X6E80, ctx->r1) = 0;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $zero, -0x21A4($at)
    MEM_H(-0X21A4, ctx->r1) = 0;
    // jal         0x800509EC
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    sub_800509EC(rdram, ctx);
    goto after_4;
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_4:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5D24($v0)
    ctx->r2 = MEM_W(-0X5D24, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, -0x774C($v1)
    ctx->r3 = MEM_W(-0X774C, ctx->r3);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D28($at)
    MEM_W(-0X5D28, ctx->r1) = ctx->r2;
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // lw          $v1, -0x2114($v1)
    ctx->r3 = MEM_W(-0X2114, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x19B0($at)
    MEM_W(-0X19B0, ctx->r1) = ctx->r2;
    // beq         $v1, $zero, L_80050418
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80050418;
    }
    // nop

    // jalr        $v1
    // nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_80050418:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80050448
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x7
        ctx->r2 = 0 | 0X7;
        goto L_80050448;
    }
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x118C($v0)
    ctx->r2 = MEM_W(0X118C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
L_80050448:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r2;
    // j           L_8005081C
    // nop

    goto L_8005081C;
    // nop

L_80050458:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0xFDC($v0)
    ctx->r2 = MEM_W(-0XFDC, ctx->r2);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lw          $v1, -0x5D28($v1)
    ctx->r3 = MEM_W(-0X5D28, ctx->r3);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, -0x774C($a0)
    ctx->r4 = MEM_W(-0X774C, ctx->r4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_800505B4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800505B4;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B4($v0)
    ctx->r2 = MEM_W(-0X19B4, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80050504
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80050504;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // lw          $v1, -0x2114($v1)
    ctx->r3 = MEM_W(-0X2114, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x19B0($at)
    MEM_W(-0X19B0, ctx->r1) = ctx->r2;
    // beq         $v1, $zero, L_800504C4
    if (ctx->r3 == 0) {
        // nop
    
        goto L_800504C4;
    }
    // nop

    // jalr        $v1
    // nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_6;
    // nop

    after_6:
L_800504C4:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800504F4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x8
        ctx->r2 = 0 | 0X8;
        goto L_800504F4;
    }
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x118C($v0)
    ctx->r2 = MEM_W(0X118C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
L_800504F4:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r2;
    // j           L_8005081C
    // nop

    goto L_8005081C;
    // nop

L_80050504:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x10A8($v0)
    ctx->r2 = MEM_W(-0X10A8, ctx->r2);
    // nop

    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(0X0, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80050564
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80050564;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80050554
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x9
        ctx->r2 = 0 | 0X9;
        goto L_80050554;
    }
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x118C($v0)
    ctx->r2 = MEM_W(0X118C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
L_80050554:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r2;
    // j           L_8005081C
    // nop

    goto L_8005081C;
    // nop

L_80050564:
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lw          $a1, -0x10A8($a1)
    ctx->r5 = MEM_W(-0X10A8, ctx->r5);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, -0x774C($a0)
    ctx->r4 = MEM_W(-0X774C, ctx->r4);
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $zero, -0x5D28($at)
    MEM_W(-0X5D28, ctx->r1) = 0;
L_80050584:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_80050584
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
        goto L_80050584;
    }
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x10A8($v0)
    ctx->r2 = MEM_W(-0X10A8, ctx->r2);
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x774C($at)
    MEM_W(-0X774C, ctx->r1) = ctx->r2;
L_800505B4:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5D28($v0)
    ctx->r2 = MEM_W(-0X5D28, ctx->r2);
    // nop

    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D24($at)
    MEM_W(-0X5D24, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
L_800505CC:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r2;
    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // lhu         $v0, -0x21A4($v0)
    ctx->r2 = MEM_HU(-0X21A4, ctx->r2);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0xFDC($v1)
    ctx->r3 = MEM_W(-0XFDC, ctx->r3);
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $a0, -0x5D28($a0)
    ctx->r4 = MEM_W(-0X5D28, ctx->r4);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $v0, -0x21A4($at)
    MEM_H(-0X21A4, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x10A8($v0)
    ctx->r2 = MEM_W(-0X10A8, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a0, 6
    ctx->r2 = S32(ctx->r4) << 6;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // lw          $a0, -0x21A0($a0)
    ctx->r4 = MEM_W(-0X21A0, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v1, -0x10AC($at)
    MEM_W(-0X10AC, ctx->r1) = ctx->r3;
    // beq         $a0, $zero, L_8005065C
    if (ctx->r4 == 0) {
        // lui         $t0, 0x1100
        ctx->r8 = S32(0X1100 << 16);
        goto L_8005065C;
    }
    // lui         $t0, 0x1100
    ctx->r8 = S32(0X1100 << 16);
    // lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x834($v0)
    ctx->r2 = MEM_W(-0X834, ctx->r2);
    // ori         $v1, $v1, 0x943
    ctx->r3 = ctx->r3 | 0X943;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x830($v1)
    ctx->r3 = MEM_W(-0X830, ctx->r3);
    // ori         $v0, $zero, 0x1323
    ctx->r2 = 0 | 0X1323;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // j           L_80050678
    // nop

    goto L_80050678;
    // nop

L_8005065C:
    // lui         $v1, 0x2102
    ctx->r3 = S32(0X2102 << 16);
    // ori         $v1, $v1, 0x843
    ctx->r3 = ctx->r3 | 0X843;
    // lui         $t0, 0x1140
    ctx->r8 = S32(0X1140 << 16);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x834($v0)
    ctx->r2 = MEM_W(-0X834, ctx->r2);
    // ori         $t0, $t0, 0x100
    ctx->r8 = ctx->r8 | 0X100;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80050678:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, -0x774C($v0)
    ctx->r2 = MEM_W(-0X774C, ctx->r2);
    // nop

    // lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(0X6, ctx->r2);
    // lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(0X4, ctx->r2);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $v0, L_80050740
    if (ctx->r3 != ctx->r2) {
        // ori         $v1, $zero, 0x1
        ctx->r3 = 0 | 0X1;
        goto L_80050740;
    }
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v1, 0x134($at)
    MEM_W(0X134, ctx->r1) = ctx->r3;
    // beq         $v0, $zero, L_800506F4
    if (ctx->r2 == 0) {
        // ori         $a2, $zero, 0x1F8
        ctx->r6 = 0 | 0X1F8;
        goto L_800506F4;
    }
    // ori         $a2, $zero, 0x1F8
    ctx->r6 = 0 | 0X1F8;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, 0x118C($a1)
    ctx->r5 = MEM_W(0X118C, ctx->r5);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x10AC($a0)
    ctx->r4 = MEM_W(-0X10AC, ctx->r4);
    // sll         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) << 11;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8005082C
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    sub_8005082C(rdram, ctx);
    goto after_7;
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_7:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x118C($v0)
    ctx->r2 = MEM_W(0X118C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r2;
    // j           L_80050718
    // nop

    goto L_80050718;
    // nop

L_800506F4:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lw          $a1, -0x10AC($a1)
    ctx->r5 = MEM_W(-0X10AC, ctx->r5);
    // ori         $a3, $zero, 0x1F8
    ctx->r7 = 0 | 0X1F8;
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // jal         0x80050860
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    sub_80050860(rdram, ctx);
    goto after_8;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_8:
L_80050718:
    // lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // lw          $v0, 0xA80($v0)
    ctx->r2 = MEM_W(0XA80, ctx->r2);
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sh          $zero, -0x21A4($at)
    MEM_H(-0X21A4, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, -0x6E80($at)
    MEM_W(-0X6E80, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v0, -0x1A00($at)
    MEM_W(-0X1A00, ctx->r1) = ctx->r2;
    // j           L_800507BC
    // nop

    goto L_800507BC;
    // nop

L_80050740:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x19B8($v0)
    ctx->r2 = MEM_W(-0X19B8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80050798
    if (ctx->r2 == 0) {
        // ori         $a2, $zero, 0x1F8
        ctx->r6 = 0 | 0X1F8;
        goto L_80050798;
    }
    // ori         $a2, $zero, 0x1F8
    ctx->r6 = 0 | 0X1F8;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, 0x118C($a1)
    ctx->r5 = MEM_W(0X118C, ctx->r5);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x10AC($a0)
    ctx->r4 = MEM_W(-0X10AC, ctx->r4);
    // sll         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) << 11;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8005082C
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    sub_8005082C(rdram, ctx);
    goto after_9;
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_9:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x118C($v0)
    ctx->r2 = MEM_W(0X118C, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, 0x118C($at)
    MEM_W(0X118C, ctx->r1) = ctx->r2;
    // j           L_800507BC
    // nop

    goto L_800507BC;
    // nop

L_80050798:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lw          $a1, -0x10AC($a1)
    ctx->r5 = MEM_W(-0X10AC, ctx->r5);
    // ori         $a3, $zero, 0x1F8
    ctx->r7 = 0 | 0X1F8;
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // jal         0x80050860
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    sub_80050860(rdram, ctx);
    goto after_10;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_10:
L_800507BC:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x830($v1)
    ctx->r3 = MEM_W(-0X830, ctx->r3);
    // ori         $v0, $zero, 0x1325
    ctx->r2 = 0 | 0X1325;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, -0x774C($v1)
    ctx->r3 = MEM_W(-0X774C, ctx->r3);
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5D28($v0)
    ctx->r2 = MEM_W(-0X5D28, ctx->r2);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x19B8($v1)
    ctx->r3 = MEM_W(-0X19B8, ctx->r3);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // sw          $v0, -0x5D28($at)
    MEM_W(-0X5D28, ctx->r1) = ctx->r2;
    // beq         $v1, $zero, L_8005081C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8005081C;
    }
    // nop

    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x134($v0)
    ctx->r2 = MEM_W(0X134, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8005081C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005081C;
    }
    // nop

    // jal         0x80050A2C
    // nop

    sub_80050A2C(rdram, ctx);
    goto after_11;
    // nop

    after_11:
L_8005081C:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
