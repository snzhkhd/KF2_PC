#include "recomp.h"
#include "disable_warnings.h"

void Entity_EnterCombatState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // jal         0x8003B848
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    Entity_LoadStats(rdram, ctx);
    goto after_0;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // ori         $s1, $zero, 0xFF
    ctx->r17 = 0 | 0XFF;
    // sb          $s2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r18;
    // sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // sb          $zero, 0xE($s0)
    MEM_B(0XE, ctx->r16) = 0;
    // sb          $s1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r17;
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_8003B91C
    if (ctx->r2 != 0) {
        // sw          $zero, 0x60($s0)
        MEM_W(0X60, ctx->r16) = 0;
        goto L_8003B91C;
    }
    // sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
L_8003B91C:
    // ori         $v0, $zero, 0x47
    ctx->r2 = 0 | 0X47;
    // sb          $v0, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r2;
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // ori         $v1, $zero, 0x800
    ctx->r3 = 0 | 0X800;
    // sh          $zero, 0x54($s0)
    MEM_H(0X54, ctx->r16) = 0;
    // sh          $zero, 0x52($s0)
    MEM_H(0X52, ctx->r16) = 0;
    // sh          $zero, 0x50($s0)
    MEM_H(0X50, ctx->r16) = 0;
    // sh          $zero, 0x58($s0)
    MEM_H(0X58, ctx->r16) = 0;
    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8003B950
    if (ctx->r2 == 0) {
        // sh          $v1, 0x16($s0)
        MEM_H(0X16, ctx->r16) = ctx->r3;
        goto L_8003B950;
    }
    // sh          $v1, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r3;
    // j           L_8003B954
    // sb          $s2, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r18;
    goto L_8003B954;
    // sb          $s2, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r18;
L_8003B950:
    // sb          $s1, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r17;
L_8003B954:
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(0X34, ctx->r16);
    // lhu         $a2, 0x1C($s0)
    ctx->r6 = MEM_HU(0X1C, ctx->r16);
    // jal         0x8002E25C
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_2;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    after_2:
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
