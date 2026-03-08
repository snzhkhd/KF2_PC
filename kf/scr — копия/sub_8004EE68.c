#include "recomp.h"
#include "disable_warnings.h"

void sub_8004EE68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x8006263C
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    KF_VSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // addiu       $s3, $s3, -0xB64
    ctx->r19 = ADD32(ctx->r19, -0XB64);
    // lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // addiu       $s1, $s1, -0x8AC
    ctx->r17 = ADD32(ctx->r17, -0X8AC);
    // lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // addiu       $s0, $s0, -0xAE4
    ctx->r16 = ADD32(ctx->r16, -0XAE4);
    // addiu       $v0, $v0, 0x1E0
    ctx->r2 = ADD32(ctx->r2, 0X1E0);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64A8($at)
    MEM_W(0X64A8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x2FD4
    ctx->r2 = ADD32(ctx->r2, 0X2FD4);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x64AC($at)
    MEM_W(0X64AC, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64B0($at)
    MEM_W(0X64B0, ctx->r1) = ctx->r2;
L_8004EEC8:
    // jal         0x8006263C
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    KF_VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x64A8($v1)
    ctx->r3 = MEM_W(0X64A8, ctx->r3);
    // nop

    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8004EF10
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8004EF10;
    }
    // nop

    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x64AC($v1)
    ctx->r3 = MEM_W(0X64AC, ctx->r3);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64AC($at)
    MEM_W(0X64AC, ctx->r1) = ctx->r2;
    // lui         $v0, 0x1E
    ctx->r2 = S32(0X1E << 16);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8004EF80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004EF80;
    }
    // nop

L_8004EF10:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2E78
    ctx->r4 = ADD32(ctx->r4, 0X2E78);
    // jal         0x80062C20
    // nop

    sub_80062C20(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(0X0, ctx->r17);
    // lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(0X1, ctx->r17);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x64B0($a1)
    ctx->r5 = MEM_W(0X64B0, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB67($v0)
    ctx->r2 = MEM_BU(-0XB67, ctx->r2);
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(0X0, ctx->r2);
    // lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(0X0, ctx->r4);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2E88
    ctx->r4 = ADD32(ctx->r4, 0X2E88);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x8004E1E0
    // nop

    sub_8004E1E0(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_8004EF84
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004EF84;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004EF80:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004EF84:
    // bne         $v0, $zero, L_8004EFB4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004EFB4;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x850($v0)
    ctx->r2 = MEM_W(-0X850, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8004EFB4
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004EFB4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // beq         $s2, $zero, L_8004EEC8
    if (ctx->r18 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8004EEC8;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8004EFB4:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
