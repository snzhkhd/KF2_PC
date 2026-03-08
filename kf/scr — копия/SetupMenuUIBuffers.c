#include "recomp.h"
#include "disable_warnings.h"

void SetupMenuUIBuffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80037184
    // nop

    CleaningUpTempResources(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, 0X140);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x178($at)
    MEM_B(0X178, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x177($at)
    MEM_B(0X177, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x1D4($at)
    MEM_B(0X1D4, ctx->r1) = 0;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $zero, 0x1D3($at)
    MEM_B(0X1D3, ctx->r1) = 0;
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // addiu       $a2, $a2, 0x6478
    ctx->r6 = ADD32(ctx->r6, 0X6478);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(0X8, ctx->r2);
    // sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // sw          $a1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r5;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, 0x14C
    ctx->r3 = ADD32(ctx->r3, 0X14C);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // addiu       $a3, $a3, 0x6484
    ctx->r7 = ADD32(ctx->r7, 0X6484);
    // lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(0X0, ctx->r3);
    // lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(0X4, ctx->r3);
    // lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(0X8, ctx->r3);
    // sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    // sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // sw          $a2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r6;
    // addiu       $v0, $v0, 0x6400
    ctx->r2 = ADD32(ctx->r2, 0X6400);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x144($at)
    MEM_W(0X144, ctx->r1) = ctx->r2;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lbu         $v1, 0x138($v1)
    ctx->r3 = MEM_BU(0X138, ctx->r3);
    // addiu       $v0, $v0, 0x6400
    ctx->r2 = ADD32(ctx->r2, 0X6400);
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r2;
    // sw          $v0, 0xF8($gp)
    MEM_W(0XF8, ctx->r28) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80024794
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80024794;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sh          $zero, 0xFC($gp)
    MEM_H(0XFC, ctx->r28) = 0;
    // sh          $v0, 0xFE($gp)
    MEM_H(0XFE, ctx->r28) = ctx->r2;
    // j           L_8002479C
    // nop

    goto L_8002479C;
    // nop

L_80024794:
    // sh          $zero, 0xFC($gp)
    MEM_H(0XFC, ctx->r28) = 0;
    // sh          $zero, 0xFE($gp)
    MEM_H(0XFE, ctx->r28) = 0;
L_8002479C:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x63BC
    ctx->r4 = ADD32(ctx->r4, 0X63BC);
    // lw          $a1, 0xF8($gp)
    ctx->r5 = MEM_W(0XF8, ctx->r28);
    // ori         $v0, $zero, 0x140
    ctx->r2 = 0 | 0X140;
    // sh          $v0, 0x100($gp)
    MEM_H(0X100, ctx->r28) = ctx->r2;
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sh          $v0, 0x102($gp)
    MEM_H(0X102, ctx->r28) = ctx->r2;
    // jal         0x8006335C
    // nop

    StoreImageWithCallback(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x4A74
    ctx->r3 = ADD32(ctx->r3, -0X4A74);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // sb          $v0, 0xF4($gp)
    MEM_B(0XF4, ctx->r28) = ctx->r2;
    // lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(0X0, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80024810
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80024810;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x59D0($v0)
    ctx->r2 = MEM_W(-0X59D0, ctx->r2);
    // nop

    // bne         $v0, $v1, L_80024810
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80024810;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x8005D924
    // nop

    PlayTrack(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_80024810:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
