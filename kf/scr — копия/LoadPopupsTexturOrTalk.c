#include "recomp.h"
#include "disable_warnings.h"

void LoadPopupsTexturOrTalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // jal         0x800188CC
    // andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    LoadTFile(rdram, ctx);
    goto after_1;
    // andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    after_1:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // jal         0x800373DC
    // nop

    ProcessTIMContainer(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x140($v0)
    ctx->r2 = MEM_W(0X140, ctx->r2);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x6378
    ctx->r4 = ADD32(ctx->r4, 0X6378);
    // addiu       $v0, $v0, 0x6400
    ctx->r2 = ADD32(ctx->r2, 0X6400);
    // addiu       $a1, $v0, 0x6400
    ctx->r5 = ADD32(ctx->r2, 0X6400);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x144($at)
    MEM_W(0X144, ctx->r1) = ctx->r2;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x14C($at)
    MEM_W(0X14C, ctx->r1) = ctx->r2;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $a1, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r5;
    // jal         0x8006335C
    // nop

    StoreImageWithCallback(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_5;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_5:
    // lh          $a1, 0xB8($gp)
    ctx->r5 = MEM_H(0XB8, ctx->r28);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lbu         $v0, 0x138($v0)
    ctx->r2 = MEM_BU(0X138, ctx->r2);
    // lh          $a2, 0xBA($gp)
    ctx->r6 = MEM_H(0XBA, ctx->r28);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, 0X160);
    // jal         0x800633C0
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    MoveImageWithCallback(rdram, ctx);
    goto after_6;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_6:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_7;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8003744C
    // ori         $a1, $zero, 0xC
    ctx->r5 = 0 | 0XC;
    LerpBrightnes(rdram, ctx);
    goto after_8;
    // ori         $a1, $zero, 0xC
    ctx->r5 = 0 | 0XC;
    after_8:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // bgez        $s0, L_800379B4
    if (SIGNED(ctx->r16) >= 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800379B4;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_80037984:
    // jal         0x80061ADC
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    KF_PadRead(rdram, ctx);
    goto after_9;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_9:
    // bne         $s0, $s1, L_800379A4
    if (ctx->r16 != ctx->r17) {
        // nop
    
        goto L_800379A4;
    }
    // nop

    // bne         $v0, $zero, L_80037984
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80037984;
    }
    // nop

    // j           L_80037984
    // addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
    goto L_80037984;
    // addiu       $s0, $zero, -0x2
    ctx->r16 = ADD32(0, -0X2);
L_800379A4:
    // beq         $v0, $zero, L_80037984
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80037984;
    }
    // nop

    // ori         $s0, $zero, 0x50
    ctx->r16 = 0 | 0X50;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800379B4:
    // jal         0x8003744C
    // addiu       $a1, $zero, -0xC
    ctx->r5 = ADD32(0, -0XC);
    LerpBrightnes(rdram, ctx);
    goto after_10;
    // addiu       $a1, $zero, -0xC
    ctx->r5 = ADD32(0, -0XC);
    after_10:
    // lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // addiu       $s0, $s0, 0x150
    ctx->r16 = ADD32(ctx->r16, 0X150);
    // lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(0X0, ctx->r16);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x6378
    ctx->r4 = ADD32(ctx->r4, 0X6378);
    // jal         0x800632F8
    // nop

    LoadImageWithCallback(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x140($v0)
    ctx->r2 = MEM_W(0X140, ctx->r2);
    // ori         $v1, $v1, 0x9000
    ctx->r3 = ctx->r3 | 0X9000;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x144($at)
    MEM_W(0X144, ctx->r1) = ctx->r2;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x14C($at)
    MEM_W(0X14C, ctx->r1) = ctx->r2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
