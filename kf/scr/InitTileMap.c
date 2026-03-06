#include "recomp.h"
#include "disable_warnings.h"

void InitTileMap(uint8_t* rdram, recomp_context* ctx) 
{
    printf("InitTileMap\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79D8($v1)
    ctx->r3 = MEM_BU(0X79D8, ctx->r3);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lbu         $a0, 0x79D9($a0)
    ctx->r4 = MEM_BU(0X79D9, ctx->r4);
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // lbu         $a1, 0x79DA($a1)
    ctx->r5 = MEM_BU(0X79DA, ctx->r5);
    // lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // lbu         $a2, 0x79DB($a2)
    ctx->r6 = MEM_BU(0X79DB, ctx->r6);
    // lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // lbu         $a3, 0x79DC($a3)
    ctx->r7 = MEM_BU(0X79DC, ctx->r7);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79D4($at)
    MEM_H(0X79D4, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x63
    ctx->r2 = 0 | 0X63;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79D8($at)
    MEM_B(0X79D8, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79D9($at)
    MEM_B(0X79D9, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DA($at)
    MEM_B(0X79DA, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DB($at)
    MEM_B(0X79DB, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DC($at)
    MEM_B(0X79DC, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $zero, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79EB($at)
    MEM_B(0X79EB, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79EC($at)
    MEM_B(0X79EC, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79ED($at)
    MEM_B(0X79ED, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v1, 0x79E4($at)
    MEM_B(0X79E4, ctx->r1) = ctx->r3;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $a0, 0x79E5($at)
    MEM_B(0X79E5, ctx->r1) = ctx->r4;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $a1, 0x79E6($at)
    MEM_B(0X79E6, ctx->r1) = ctx->r5;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $a2, 0x79E7($at)
    MEM_B(0X79E7, ctx->r1) = ctx->r6;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $a3, 0x79E8($at)
    MEM_B(0X79E8, ctx->r1) = ctx->r7;
L_80016520:
    // jal         0x80017C60
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x80016CD0
    // nop

    Map_Load(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lh          $v0, 0x79D4($v0)
    ctx->r2 = MEM_H(0X79D4, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80016520
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80016520;
    }
    // nop

    // lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // addiu       $a1, $a1, 0xA90
    ctx->r5 = ADD32(ctx->r5, 0XA90);
    // jal         0x8003044C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SetStateCallback(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, 0x79E0($v0)
    ctx->r2 = MEM_W(0X79E0, ctx->r2);
    // nop

    // lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(0X14, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
