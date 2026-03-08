#include "recomp.h"
#include "disable_warnings.h"

void AllocateMemor_01(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // ori         $s1, $zero, 0x2
    ctx->r17 = 0 | 0X2;
    // addiu       $s0, $a0, 0x3
    ctx->r16 = ADD32(ctx->r4, 0X3);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x641C($v1)
    ctx->r3 = MEM_W(0X641C, ctx->r3);
    // addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // bne         $v1, $zero, L_8004C5DC
    if (ctx->r3 != 0) {
        // and         $s0, $s0, $v0
        ctx->r16 = ctx->r16 & ctx->r2;
        goto L_8004C5DC;
    }
    // and         $s0, $s0, $v0
    ctx->r16 = ctx->r16 & ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6404($v1)
    ctx->r3 = MEM_W(0X6404, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6414($v0)
    ctx->r2 = MEM_W(0X6414, ctx->r2);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8004C700
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_8004C700;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6404($v0)
    ctx->r2 = MEM_W(0X6404, ctx->r2);
    // nop

    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $v0, -0x2198($at)
    MEM_W(-0X2198, ctx->r1) = ctx->r2;
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x6404($at)
    MEM_W(0X6404, ctx->r1) = ctx->r2;
    // jal         0x8004C264
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8004C264(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // bne         $v0, $zero, L_8004C760
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004C760;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // lw          $v1, -0x2198($v1)
    ctx->r3 = MEM_W(-0X2198, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x641C($at)
    MEM_W(0X641C, ctx->r1) = ctx->r2;
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $v1, -0x1EEC($at)
    MEM_W(-0X1EEC, ctx->r1) = ctx->r3;
L_8004C5DC:
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // lw          $a0, -0x1EEC($a0)
    ctx->r4 = MEM_W(-0X1EEC, ctx->r4);
    // nop

    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $a0, -0x2198($at)
    MEM_W(-0X2198, ctx->r1) = ctx->r4;
    // j           L_8004C724
    // nop

    goto L_8004C724;
    // nop

L_8004C5F8:
    // lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // lw          $a1, -0x2198($a1)
    ctx->r5 = MEM_W(-0X2198, ctx->r5);
    // nop

    // lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(0X0, ctx->r5);
    // nop

    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_8004C644
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004C644;
    }
    // nop

    // bgez        $s0, L_8004C624
    if (SIGNED(ctx->r16) >= 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8004C624;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // addiu       $v0, $s0, 0x3
    ctx->r2 = ADD32(ctx->r16, 0X3);
L_8004C624:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // subu        $v1, $a0, $s0
    ctx->r3 = SUB32(ctx->r4, ctx->r16);
    // addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // j           L_8004C750
    // sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    goto L_8004C750;
    // sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
L_8004C644:
    // sltu        $v0, $a0, $s0
    ctx->r2 = ctx->r4 < ctx->r16 ? 1 : 0;
    // beq         $v0, $zero, L_8004C71C
    if (ctx->r2 == 0) {
        // srl         $v0, $a0, 2
        ctx->r2 = S32(U32(ctx->r4) >> 2);
        goto L_8004C71C;
    }
    // srl         $v0, $a0, 2
    ctx->r2 = S32(U32(ctx->r4) >> 2);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(0X4, ctx->r2);
    // addiu       $a3, $zero, -0x2
    ctx->r7 = ADD32(0, -0X2);
    // bne         $v1, $a3, L_8004C68C
    if (ctx->r3 != ctx->r7) {
        // addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
        goto L_8004C68C;
    }
    // addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // lw          $v0, -0x2198($v0)
    ctx->r2 = MEM_W(-0X2198, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x6404($at)
    MEM_W(0X6404, ctx->r1) = ctx->r2;
    // j           L_8004C71C
    // nop

    goto L_8004C71C;
    // nop

L_8004C68C:
    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_8004C6A8
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, 0x4
        ctx->r2 = ADD32(ctx->r4, 0X4);
        goto L_8004C6A8;
    }
    // addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // and         $v1, $v1, $a3
    ctx->r3 = ctx->r3 & ctx->r7;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8004C71C
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    goto L_8004C71C;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8004C6A8:
    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $a2, -0x2198($at)
    MEM_W(-0X2198, ctx->r1) = ctx->r6;
    // j           L_8004C71C
    // nop

    goto L_8004C71C;
    // nop

L_8004C6B8:
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // lw          $a0, -0x2198($a0)
    ctx->r4 = MEM_W(-0X2198, ctx->r4);
    // nop

    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // beq         $v1, $v0, L_8004C6E4
    if (ctx->r3 == ctx->r2) {
        // srl         $v0, $v1, 2
        ctx->r2 = S32(U32(ctx->r3) >> 2);
        goto L_8004C6E4;
    }
    // srl         $v0, $v1, 2
    ctx->r2 = S32(U32(ctx->r3) >> 2);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_8004C710
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    goto L_8004C710;
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8004C6E4:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bgtz        $s1, L_8004C708
    if (SIGNED(ctx->r17) > 0) {
        // nop
    
        goto L_8004C708;
    }
    // nop

    // jal         0x8004C264
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8004C264(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // beq         $v0, $zero, L_8004C71C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004C71C;
    }
    // nop

L_8004C700:
    // j           L_8004C760
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8004C760;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004C708:
    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // lw          $v0, -0x1EEC($v0)
    ctx->r2 = MEM_W(-0X1EEC, ctx->r2);
L_8004C710:
    // nop

    // lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // sw          $v0, -0x2198($at)
    MEM_W(-0X2198, ctx->r1) = ctx->r2;
L_8004C71C:
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // lw          $a0, -0x2198($a0)
    ctx->r4 = MEM_W(-0X2198, ctx->r4);
L_8004C724:
    // nop

    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_8004C6B8
    if (ctx->r2 == 0) {
        // ori         $v0, $s0, 0x1
        ctx->r2 = ctx->r16 | 0X1;
        goto L_8004C6B8;
    }
    // ori         $v0, $s0, 0x1
    ctx->r2 = ctx->r16 | 0X1;
    // bne         $v1, $v0, L_8004C5F8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004C5F8;
    }
    // nop

    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8004C750:
    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // lw          $v0, -0x2198($v0)
    ctx->r2 = MEM_W(-0X2198, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8004C760:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
