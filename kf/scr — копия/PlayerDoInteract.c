#include "recomp.h"
#include "disable_warnings.h"

void PlayerDoInteract(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x49FA
    ctx->r5 = ADD32(ctx->r5, -0X49FA);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62CC($v1)
    ctx->r3 = MEM_W(0X62CC, ctx->r3);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002BB68
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002BB68;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F8($v0)
    ctx->r2 = MEM_HU(-0X49F8, ctx->r2);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8002BB68
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8002BB68;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A6F($v1)
    ctx->r3 = MEM_BU(-0X4A6F, ctx->r3);
    // nop

    // bne         $v1, $v0, L_8002BB60
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $a1, -0x6A
        ctx->r4 = ADD32(ctx->r5, -0X6A);
        goto L_8002BB60;
    }
    // addiu       $a0, $a1, -0x6A
    ctx->r4 = ADD32(ctx->r5, -0X6A);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x49EC($v0)
    ctx->r2 = MEM_BU(-0X49EC, ctx->r2);
    // nop

    // sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2) << 4;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x6810
    ctx->r2 = ADD32(ctx->r2, -0X6810);
    // jal         0x8002BCF8
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    sub_8002BCF8(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
    // j           L_8002BB68
    // nop

    goto L_8002BB68;
    // nop

L_8002BB60:
    // jal         0x8004A5E4
    // addiu       $a1, $a1, -0x4A
    ctx->r5 = ADD32(ctx->r5, -0X4A);
    Interact_8004A5E4(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, -0x4A
    ctx->r5 = ADD32(ctx->r5, -0X4A);
    after_1:
L_8002BB68:
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x49FA
    ctx->r17 = ADD32(ctx->r17, -0X49FA);
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62D0($v1)
    ctx->r3 = MEM_W(0X62D0, ctx->r3);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002BC5C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002BC5C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49F8($v0)
    ctx->r2 = MEM_HU(-0X49F8, ctx->r2);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8002BC5C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8002BC5C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x4AAC($v1)
    ctx->r3 = MEM_H(-0X4AAC, ctx->r3);
    // nop

    // bne         $v1, $v0, L_8002BC5C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8002BC5C;
    }
    // nop

    // jal         0x8002BA60
    // nop

    HideInGameUI(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x800196F4
    // nop

    InGameMenu(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // bltz        $s0, L_8002BC04
    if (SIGNED(ctx->r16) < 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_8002BC04;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // jal         0x8002B39C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    IsConsumable(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // bne         $v0, $zero, L_8002BC54
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8002BC54;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x800360A0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    KF_GpuUpdate(rdram, ctx);
    goto after_5;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // addiu       $a0, $s1, -0x6A
    ctx->r4 = ADD32(ctx->r17, -0X6A);
    // addiu       $a1, $s1, -0x4A
    ctx->r5 = ADD32(ctx->r17, -0X4A);
    // jal         0x80049108
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    UseItems_80049108(rdram, ctx);
    goto after_6;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // j           L_8002BC54
    // nop

    goto L_8002BC54;
    // nop

L_8002BC04:
    // bne         $s0, $v0, L_8002BC20
    if (ctx->r16 != ctx->r2) {
        // addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
        goto L_8002BC20;
    }
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x6460($at)
    MEM_W(0X6460, ctx->r1) = ctx->r2;
    // j           L_8002BC54
    // nop

    goto L_8002BC54;
    // nop

L_8002BC20:
    // bne         $s0, $v0, L_8002BC54
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8002BC54;
    }
    // nop

    // jal         0x8002601C
    // nop

    LoadSave(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lbu         $a0, 0x79D8($a0)
    ctx->r4 = MEM_BU(0X79D8, ctx->r4);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // jal         0x800260BC
    // sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    sub_800260BC(rdram, ctx);
    goto after_8;
    // sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    after_8:
L_8002BC54:
    // jal         0x80027C38
    // nop

    Player_ResetMovement(rdram, ctx);
    goto after_9;
    // nop

    after_9:
L_8002BC5C:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
