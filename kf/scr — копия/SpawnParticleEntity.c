#include "recomp.h"
#include "disable_warnings.h"

void SpawnParticleEntity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // jal         0x80042C44
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    AllocateParticleSlot(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800440CC
    if (ctx->r16 == 0) {
        // nop
    
        goto L_800440CC;
    }
    // nop

    // sb          $s2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r18;
    // beq         $s4, $zero, L_80042D9C
    if (ctx->r20 == 0) {
        // sb          $s3, 0x1($s0)
        MEM_B(0X1, ctx->r16) = ctx->r19;
        goto L_80042D9C;
    }
    // sb          $s3, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r19;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(0X4, ctx->r20);
    // lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(0X8, ctx->r20);
    // lw          $a1, 0xC($s4)
    ctx->r5 = MEM_W(0XC, ctx->r20);
    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // sw          $a0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r4;
    // sw          $a1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r5;
L_80042D9C:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(0X58, ctx->r29);
    // nop

    // beq         $a2, $zero, L_80042DDC
    if (ctx->r6 == 0) {
        // ori         $v0, $zero, 0x1000
        ctx->r2 = 0 | 0X1000;
        goto L_80042DDC;
    }
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // swl         $v0, 0x37($s0)
    do_swl(rdram, 0X37, ctx->r16, ctx->r2);
    // swr         $v0, 0x34($s0)
    do_swr(rdram, 0X34, ctx->r16, ctx->r2);
    // swl         $v1, 0x3B($s0)
    do_swl(rdram, 0X3B, ctx->r16, ctx->r3);
    // swr         $v1, 0x38($s0)
    do_swr(rdram, 0X38, ctx->r16, ctx->r3);
    // j           L_80042DE8
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    goto L_80042DE8;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
L_80042DDC:
    // sh          $zero, 0x38($s0)
    MEM_H(0X38, ctx->r16) = 0;
    // sh          $zero, 0x36($s0)
    MEM_H(0X36, ctx->r16) = 0;
    // sh          $zero, 0x34($s0)
    MEM_H(0X34, ctx->r16) = 0;
L_80042DE8:
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // sb          $s5, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r21;
    // sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // sh          $zero, 0x26($s0)
    MEM_H(0X26, ctx->r16) = 0;
    // sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // sh          $zero, 0x12($s0)
    MEM_H(0X12, ctx->r16) = 0;
    // sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80042E40
    if (ctx->r2 == 0) {
        // sb          $v1, 0x8($s0)
        MEM_B(0X8, ctx->r16) = ctx->r3;
        goto L_80042E40;
    }
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A6F($v1)
    ctx->r3 = MEM_BU(-0X4A6F, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80042E44
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80042E44;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_80042E44
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    goto L_80042E44;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
L_80042E40:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80042E44:
    // sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // lh          $v0, 0x34($s0)
    ctx->r2 = MEM_H(0X34, ctx->r16);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x36($s0)
    ctx->r2 = MEM_H(0X36, ctx->r16);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lh          $v0, 0x38($s0)
    ctx->r2 = MEM_H(0X38, ctx->r16);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a0, 0xC
    ctx->r4 = S32(0XC << 16);
    // ori         $a0, $a0, 0x5C10
    ctx->r4 = ctx->r4 | 0X5C10;
    // sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $a0, $zero, L_80042EB4
    if (ctx->r4 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80042EB4;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_80042EB8
    // sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    goto L_80042EB8;
    // sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
L_80042EB4:
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
L_80042EB8:
    // lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(0X1, ctx->r16);
    // nop

    // sltiu       $v0, $v1, 0x7B
    ctx->r2 = ctx->r3 < 0X7B ? 1 : 0;
    // beq         $v0, $zero, L_800440C4
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_800440C4;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x2598
    ctx->r1 = ADD32(ctx->r1, 0X2598);
    // addu        $at, $at, $v0
    gpr jr_addend_80042EE0;
    jr_addend_80042EE0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80042EE0 >> 2) {
        case 0: goto L_8004309C; break;
        case 1: goto L_80042FAC; break;
        case 2: goto L_80043674; break;
        case 3: goto L_80043E14; break;
        case 4: goto L_80042F38; break;
        case 5: goto L_80043134; break;
        case 6: goto L_800433D8; break;
        case 7: goto L_80042EE8; break;
        case 8: goto L_80043334; break;
        case 9: goto L_800431E4; break;
        case 10: goto L_80043364; break;
        case 11: goto L_800435C0; break;
        case 12: goto L_8004370C; break;
        case 13: goto L_80043070; break;
        case 14: goto L_80043D90; break;
        case 15: goto L_80043D58; break;
        case 16: goto L_80043D80; break;
        case 17: goto L_80043D6C; break;
        case 18: goto L_800440C4; break;
        case 19: goto L_80043D90; break;
        case 20: goto L_800436CC; break;
        case 21: goto L_800440C4; break;
        case 22: goto L_80043DB0; break;
        case 23: goto L_80043FBC; break;
        case 24: goto L_80044010; break;
        case 25: goto L_800430BC; break;
        case 26: goto L_80042FDC; break;
        case 27: goto L_8004301C; break;
        case 28: goto L_80042F9C; break;
        case 29: goto L_80043F60; break;
        case 30: goto L_80043F58; break;
        case 31: goto L_80043F60; break;
        case 32: goto L_80042F1C; break;
        case 33: goto L_8004327C; break;
        case 34: goto L_80043B28; break;
        case 35: goto L_80043B30; break;
        case 36: goto L_800440C4; break;
        case 37: goto L_800440C4; break;
        case 38: goto L_80043A7C; break;
        case 39: goto L_80043A7C; break;
        case 40: goto L_80043A08; break;
        case 41: goto L_800440C4; break;
        case 42: goto L_80043850; break;
        case 43: goto L_800440C4; break;
        case 44: goto L_800440C4; break;
        case 45: goto L_80043940; break;
        case 46: goto L_80043918; break;
        case 47: goto L_80043F50; break;
        case 48: goto L_80043F48; break;
        case 49: goto L_80042EE8; break;
        case 50: goto L_80043B9C; break;
        case 51: goto L_80043650; break;
        case 52: goto L_80043650; break;
        case 53: goto L_8004326C; break;
        case 54: goto L_800435B8; break;
        case 55: goto L_800440C4; break;
        case 56: goto L_800440C4; break;
        case 57: goto L_800440C4; break;
        case 58: goto L_800440C4; break;
        case 59: goto L_800440C4; break;
        case 60: goto L_800440C4; break;
        case 61: goto L_800440C4; break;
        case 62: goto L_800440C4; break;
        case 63: goto L_800440C4; break;
        case 64: goto L_800440C4; break;
        case 65: goto L_800440C4; break;
        case 66: goto L_800440C4; break;
        case 67: goto L_800440C4; break;
        case 68: goto L_800440C4; break;
        case 69: goto L_800440C4; break;
        case 70: goto L_800440C4; break;
        case 71: goto L_800440C4; break;
        case 72: goto L_800440C4; break;
        case 73: goto L_800440C4; break;
        case 74: goto L_800440C4; break;
        case 75: goto L_800440C4; break;
        case 76: goto L_800440C4; break;
        case 77: goto L_800440C4; break;
        case 78: goto L_800440C4; break;
        case 79: goto L_800440C4; break;
        case 80: goto L_800440C4; break;
        case 81: goto L_800440C4; break;
        case 82: goto L_800440C4; break;
        case 83: goto L_800440C4; break;
        case 84: goto L_800440C4; break;
        case 85: goto L_800440C4; break;
        case 86: goto L_800440C4; break;
        case 87: goto L_800440C4; break;
        case 88: goto L_800440C4; break;
        case 89: goto L_800440C4; break;
        case 90: goto L_800440C4; break;
        case 91: goto L_800440C4; break;
        case 92: goto L_800440C4; break;
        case 93: goto L_800440C4; break;
        case 94: goto L_800440C4; break;
        case 95: goto L_800440C4; break;
        case 96: goto L_800440C4; break;
        case 97: goto L_800440C4; break;
        case 98: goto L_800440C4; break;
        case 99: goto L_800440C4; break;
        case 100: goto L_800437B0; break;
        case 101: goto L_80043BF0; break;
        case 102: goto L_80043C24; break;
        case 103: goto L_80043554; break;
        case 104: goto L_80043594; break;
        case 105: goto L_8004315C; break;
        case 106: goto L_80043300; break;
        case 107: goto L_800434DC; break;
        case 108: goto L_800440C4; break;
        case 109: goto L_80044020; break;
        case 110: goto L_800440C4; break;
        case 111: goto L_80043048; break;
        case 112: goto L_800440C4; break;
        case 113: goto L_80043898; break;
        case 114: goto L_80043E64; break;
        case 115: goto L_80043898; break;
        case 116: goto L_80043994; break;
        case 117: goto L_8004399C; break;
        case 118: goto L_8004361C; break;
        case 119: goto L_8004361C; break;
        case 120: goto L_8004408C; break;
        case 121: goto L_80043548; break;
        case 122: goto L_80043588; break;
        default: switch_error(__func__, 0x80042EE0, 0x80012598);
    }
    // nop

L_80042EE8:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x2D
    ctx->r5 = 0 | 0X2D;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1800
    ctx->r6 = 0 | 0X1800;
    SetupEntityAnimation(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x1800
    ctx->r6 = 0 | 0X1800;
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x23
    ctx->r5 = 0 | 0X23;
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // jal         0x8004248C
    // sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    PlayEntitySound(rdram, ctx);
    goto after_2;
    // sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    after_2:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80042F1C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x21
    ctx->r5 = 0 | 0X21;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1800
    ctx->r6 = 0 | 0X1800;
    SetupEntityAnimation(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0x1800
    ctx->r6 = 0 | 0X1800;
    after_3:
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // j           L_800440CC
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    goto L_800440CC;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
L_80042F38:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1F
    ctx->r2 = 0 | 0X1F;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x32C8
    ctx->r2 = 0 | 0X32C8;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // jal         0x8004248C
    // sb          $v1, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r3;
    PlayEntitySound(rdram, ctx);
    goto after_4;
    // sb          $v1, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r3;
    after_4:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80042F9C:
    // ori         $v0, $zero, 0x800
    ctx->r2 = 0 | 0X800;
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
L_80042FAC:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x1B
    ctx->r5 = 0 | 0X1B;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x46
    ctx->r2 = 0 | 0X46;
    // j           L_800434CC
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    goto L_800434CC;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
L_80042FDC:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x24
    ctx->r2 = 0 | 0X24;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x46
    ctx->r2 = 0 | 0X46;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x258
    ctx->r2 = 0 | 0X258;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // j           L_800440CC
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    goto L_800440CC;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
L_8004301C:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x25
    ctx->r2 = 0 | 0X25;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x46
    ctx->r2 = 0 | 0X46;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    // j           L_800436FC
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    goto L_800436FC;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
L_80043048:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x21
    ctx->r5 = 0 | 0X21;
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // jal         0x8004248C
    // sh          $v1, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r3;
    PlayEntitySound(rdram, ctx);
    goto after_5;
    // sh          $v1, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r3;
    after_5:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043070:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x21
    ctx->r5 = 0 | 0X21;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    SetupEntityAnimation(rdram, ctx);
    goto after_6;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_6:
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x2A
    ctx->r5 = 0 | 0X2A;
    PlayEntitySound(rdram, ctx);
    goto after_7;
    // ori         $a1, $zero, 0x2A
    ctx->r5 = 0 | 0X2A;
    after_7:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8004309C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0xE
    ctx->r5 = 0 | 0XE;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x200
    ctx->r6 = 0 | 0X200;
    SetupEntityAnimation(rdram, ctx);
    goto after_8;
    // ori         $a2, $zero, 0x200
    ctx->r6 = 0 | 0X200;
    after_8:
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // j           L_800440CC
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    goto L_800440CC;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
L_800430BC:
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a0, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r4);
    // swr         $a0, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r4);
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r2;
    // j           L_800440CC
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    goto L_800440CC;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
L_80043134:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x21
    ctx->r5 = 0 | 0X21;
    // sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(0X4, ctx->r17);
    // ori         $v0, $zero, 0x46
    ctx->r2 = 0 | 0X46;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // jal         0x8004248C
    // sb          $v1, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r3;
    PlayEntitySound(rdram, ctx);
    goto after_10;
    // sb          $v1, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r3;
    after_10:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8004315C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0xE
    ctx->r5 = 0 | 0XE;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    SetupEntityAnimation(rdram, ctx);
    goto after_11;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_11:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // jal         0x80062BF0
    // sh          $v0, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_13;
    // sh          $v0, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r2;
    after_13:
    // lhu         $v1, 0x34($s0)
    ctx->r3 = MEM_HU(0X34, ctx->r16);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_14;
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    after_14:
    // lhu         $v1, 0x36($s0)
    ctx->r3 = MEM_HU(0X36, ctx->r16);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_15;
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    after_15:
    // lhu         $v1, 0x38($s0)
    ctx->r3 = MEM_HU(0X38, ctx->r16);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r3;
    // lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(0X4, ctx->r17);
    // nop

    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(0X8, ctx->r17);
    // nop

    // sb          $v0, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r2;
    // lhu         $v1, 0xC($s1)
    ctx->r3 = MEM_HU(0XC, ctx->r17);
    // j           L_80043358
    // ori         $v0, $zero, 0x46
    ctx->r2 = 0 | 0X46;
    goto L_80043358;
    // ori         $v0, $zero, 0x46
    ctx->r2 = 0 | 0X46;
L_800431E4:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    SetupEntityAnimation(rdram, ctx);
    goto after_16;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_16:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // lhu         $v1, 0x34($s0)
    ctx->r3 = MEM_HU(0X34, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_18;
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    after_18:
    // lhu         $v1, 0x36($s0)
    ctx->r3 = MEM_HU(0X36, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_19;
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    after_19:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x26
    ctx->r5 = 0 | 0X26;
    // lhu         $v1, 0x38($s0)
    ctx->r3 = MEM_HU(0X38, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(0X4, ctx->r17);
    // ori         $v0, $zero, 0x64
    ctx->r2 = 0 | 0X64;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // jal         0x8004248C
    // sb          $v1, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r3;
    PlayEntitySound(rdram, ctx);
    goto after_20;
    // sb          $v1, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r3;
    after_20:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8004326C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x21
    ctx->r5 = 0 | 0X21;
    // j           L_80043288
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    goto L_80043288;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
L_8004327C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x21
    ctx->r5 = 0 | 0X21;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
L_80043288:
    // jal         0x80042C88
    // nop

    SetupEntityAnimation(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_22;
    // nop

    after_22:
    // lhu         $v1, 0x34($s0)
    ctx->r3 = MEM_HU(0X34, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_23;
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    after_23:
    // lhu         $v1, 0x36($s0)
    ctx->r3 = MEM_HU(0X36, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_24;
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    after_24:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x21
    ctx->r5 = 0 | 0X21;
    // ori         $v1, $zero, 0x64
    ctx->r3 = 0 | 0X64;
    // ori         $a2, $zero, 0x3
    ctx->r6 = 0 | 0X3;
    // sh          $v1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x38($s0)
    ctx->r3 = MEM_HU(0X38, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sb          $a2, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r6;
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x8004248C
    // sh          $v1, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r3;
    PlayEntitySound(rdram, ctx);
    goto after_25;
    // sh          $v1, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r3;
    after_25:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043300:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    SetupEntityAnimation(rdram, ctx);
    goto after_26;
    // ori         $a2, $zero, 0x2000
    ctx->r6 = 0 | 0X2000;
    after_26:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x36($s0)
    ctx->r2 = MEM_HU(0X36, ctx->r16);
    // ori         $a1, $zero, 0x24
    ctx->r5 = 0 | 0X24;
    // addiu       $v0, $v0, -0x64
    ctx->r2 = ADD32(ctx->r2, -0X64);
    // jal         0x8004248C
    // sh          $v0, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r2;
    PlayEntitySound(rdram, ctx);
    goto after_27;
    // sh          $v0, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r2;
    after_27:
    // ori         $v0, $zero, 0x64
    ctx->r2 = 0 | 0X64;
    // j           L_800440CC
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    goto L_800440CC;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
L_80043334:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    SetupEntityAnimation(rdram, ctx);
    goto after_28;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_28:
    // lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(0X4, ctx->r17);
    // nop

    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
    // lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(0X8, ctx->r17);
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
L_80043358:
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // j           L_800440CC
    // sh          $v1, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r3;
    goto L_800440CC;
    // sh          $v1, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r3;
L_80043364:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x15
    ctx->r2 = 0 | 0X15;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xBB8
    ctx->r2 = 0 | 0XBB8;
    // sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // ori         $a1, $zero, 0x27
    ctx->r5 = 0 | 0X27;
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a2, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r6);
    // swr         $a2, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r6);
    // ori         $v0, $zero, 0x96
    ctx->r2 = 0 | 0X96;
    // j           L_800434CC
    // sb          $zero, 0x41($s0)
    MEM_B(0X41, ctx->r16) = 0;
    goto L_800434CC;
    // sb          $zero, 0x41($s0)
    MEM_B(0X41, ctx->r16) = 0;
L_800433D8:
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // ori         $v1, $zero, 0x1000
    ctx->r3 = 0 | 0X1000;
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // ori         $a3, $zero, 0x17
    ctx->r7 = 0 | 0X17;
    // sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // sh          $v1, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r3;
    // sh          $v1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r3;
    // sh          $v1, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r3;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // sh          $v1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r3;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a0, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r4);
    // swr         $a0, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r4);
    // lw          $v1, 0xE0($gp)
    ctx->r3 = MEM_W(0XE0, ctx->r28);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, -0x19AC
    ctx->r4 = ADD32(ctx->r4, -0X19AC);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // sw          $a2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r6;
    // sw          $v1, 0xE0($gp)
    MEM_W(0XE0, ctx->r28) = ctx->r3;
L_8004346C:
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(0X18, ctx->r16);
    // lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(0X1C, ctx->r16);
    // lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(0X20, ctx->r16);
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // sw          $a0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r4;
    // sw          $a1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r5;
    // lwl         $v0, 0x27($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X27, ctx->r16);
    // lwr         $v0, 0x24($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X24, ctx->r16);
    // lwl         $v1, 0x2B($s0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X2B, ctx->r16);
    // lwr         $v1, 0x28($s0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X28, ctx->r16);
    // swl         $v0, 0x13($a2)
    do_swl(rdram, 0X13, ctx->r6, ctx->r2);
    // swr         $v0, 0x10($a2)
    do_swr(rdram, 0X10, ctx->r6, ctx->r2);
    // swl         $v1, 0x17($a2)
    do_swl(rdram, 0X17, ctx->r6, ctx->r3);
    // swr         $v1, 0x14($a2)
    do_swr(rdram, 0X14, ctx->r6, ctx->r3);
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // bne         $a3, $t0, L_8004346C
    if (ctx->r7 != ctx->r8) {
        // addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
        goto L_8004346C;
    }
    // addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x22
    ctx->r5 = 0 | 0X22;
    // ori         $v0, $zero, 0x96
    ctx->r2 = 0 | 0X96;
    // sb          $zero, 0x44($s0)
    MEM_B(0X44, ctx->r16) = 0;
    // sb          $zero, 0x45($s0)
    MEM_B(0X45, ctx->r16) = 0;
L_800434CC:
    // jal         0x8004248C
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    PlayEntitySound(rdram, ctx);
    goto after_29;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    after_29:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800434DC:
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x23
    ctx->r2 = 0 | 0X23;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a0, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r4);
    // swr         $a0, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r4);
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043548:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // j           L_8004355C
    // ori         $a1, $zero, 0x2E
    ctx->r5 = 0 | 0X2E;
    goto L_8004355C;
    // ori         $a1, $zero, 0x2E
    ctx->r5 = 0 | 0X2E;
L_80043554:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0xF
    ctx->r5 = 0 | 0XF;
L_8004355C:
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    SetupEntityAnimation(rdram, ctx);
    goto after_30;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_30:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0x64
    ctx->r2 = 0 | 0X64;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // ori         $a1, $zero, 0x28
    ctx->r5 = 0 | 0X28;
    // jal         0x8004248C
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    PlayEntitySound(rdram, ctx);
    goto after_31;
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    after_31:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043588:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // j           L_8004359C
    // ori         $a1, $zero, 0x2F
    ctx->r5 = 0 | 0X2F;
    goto L_8004359C;
    // ori         $a1, $zero, 0x2F
    ctx->r5 = 0 | 0X2F;
L_80043594:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
L_8004359C:
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    SetupEntityAnimation(rdram, ctx);
    goto after_32;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_32:
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // ori         $v0, $zero, 0xF
    ctx->r2 = 0 | 0XF;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // j           L_800440CC
    // sh          $v1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r3;
    goto L_800440CC;
    // sh          $v1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r3;
L_800435B8:
    // j           L_800435C4
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
    goto L_800435C4;
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
L_800435C0:
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
L_800435C4:
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // bgez        $v0, L_80043610
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80043610;
    }
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_80043610:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // j           L_800440CC
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    goto L_800440CC;
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
L_8004361C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x13
    ctx->r2 = 0 | 0X13;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x23
    ctx->r2 = 0 | 0X23;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // j           L_80043A4C
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    goto L_80043A4C;
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
L_80043650:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x25
    ctx->r2 = 0 | 0X25;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // j           L_800436FC
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    goto L_800436FC;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
L_80043674:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // j           L_80044000
    // ori         $a1, $zero, 0x1E
    ctx->r5 = 0 | 0X1E;
    goto L_80044000;
    // ori         $a1, $zero, 0x1E
    ctx->r5 = 0 | 0X1E;
L_800436CC:
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xB
    ctx->r2 = 0 | 0XB;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
L_800436FC:
    // sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // j           L_800440CC
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    goto L_800440CC;
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
L_8004370C:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x22
    ctx->r2 = 0 | 0X22;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x49
    ctx->r2 = 0 | 0X49;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a0, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r4);
    // swr         $a0, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r4);
    // ori         $v0, $zero, 0x7530
    ctx->r2 = 0 | 0X7530;
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // nop

    // sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(0X14, ctx->r17);
    // nop

    // sh          $v0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(0X18, ctx->r17);
    // j           L_800440CC
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    goto L_800440CC;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
L_800437B0:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x22
    ctx->r2 = 0 | 0X22;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a0, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r4);
    // swr         $a0, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r4);
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_33;
    // nop

    after_33:
    // lhu         $v1, 0x26($s0)
    ctx->r3 = MEM_HU(0X26, ctx->r16);
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // addiu       $v1, $v1, -0x80
    ctx->r3 = ADD32(ctx->r3, -0X80);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_34;
    // sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    after_34:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x29
    ctx->r5 = 0 | 0X29;
    // lhu         $v1, 0x24($s0)
    ctx->r3 = MEM_HU(0X24, ctx->r16);
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // addiu       $v1, $v1, -0x80
    ctx->r3 = ADD32(ctx->r3, -0X80);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x8004248C
    // sh          $v1, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r3;
    PlayEntitySound(rdram, ctx);
    goto after_35;
    // sh          $v1, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r3;
    after_35:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043850:
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x11
    ctx->r2 = 0 | 0X11;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    // lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(0X4, ctx->r17);
    // j           L_800440CC
    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
    goto L_800440CC;
    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
L_80043898:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xD
    ctx->r2 = 0 | 0XD;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // ori         $a1, $zero, 0x29
    ctx->r5 = 0 | 0X29;
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a2, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r6);
    // swr         $a2, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r6);
    // ori         $v0, $zero, 0x1388
    ctx->r2 = 0 | 0X1388;
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // jal         0x8004248C
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    PlayEntitySound(rdram, ctx);
    goto after_36;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    after_36:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043918:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    SetupEntityAnimation(rdram, ctx);
    goto after_37;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_37:
    // sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    // lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(0X4, ctx->r17);
    // sh          $zero, 0x36($s0)
    MEM_H(0X36, ctx->r16) = 0;
    // j           L_800440CC
    // sb          $v0, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r2;
    goto L_800440CC;
    // sb          $v0, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r2;
L_80043940:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x17
    ctx->r5 = 0 | 0X17;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // jal         0x8004248C
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    PlayEntitySound(rdram, ctx);
    goto after_38;
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    after_38:
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // j           L_800440CC
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    goto L_800440CC;
    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
L_80043994:
    // j           L_80044014
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    goto L_80044014;
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
L_8004399C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0x31
    ctx->r2 = 0 | 0X31;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a2, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r6);
    // swr         $a2, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r6);
    // j           L_80043BE0
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    goto L_80043BE0;
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
L_80043A08:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // ori         $a1, $zero, 0x32
    ctx->r5 = 0 | 0X32;
L_80043A4C:
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a2, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r6);
    // swr         $a2, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r6);
    // jal         0x8004248C
    // nop

    PlayEntitySound(rdram, ctx);
    goto after_39;
    // nop

    after_39:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043A7C:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x2C
    ctx->r2 = 0 | 0X2C;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x32
    ctx->r2 = 0 | 0X32;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a0, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r4);
    // swr         $a0, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r4);
    // jal         0x80062BF0
    // nop

    rand_recomp(rdram, ctx);
    goto after_40;
    // nop

    after_40:
    // lhu         $v1, 0x26($s0)
    ctx->r3 = MEM_HU(0X26, ctx->r16);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // addiu       $v1, $v1, -0x100
    ctx->r3 = ADD32(ctx->r3, -0X100);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_41;
    // sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    after_41:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    // ori         $v1, $zero, 0x2000
    ctx->r3 = 0 | 0X2000;
    // lhu         $a2, 0x24($s0)
    ctx->r6 = MEM_HU(0X24, ctx->r16);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    // sh          $v1, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r3;
    // sh          $v1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r3;
    // sh          $v1, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r3;
    // addiu       $a2, $a2, -0x100
    ctx->r6 = ADD32(ctx->r6, -0X100);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // jal         0x8004248C
    // sh          $a2, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r6;
    PlayEntitySound(rdram, ctx);
    goto after_42;
    // sh          $a2, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r6;
    after_42:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043B28:
    // j           L_80043B34
    // ori         $v0, $zero, 0x28
    ctx->r2 = 0 | 0X28;
    goto L_80043B34;
    // ori         $v0, $zero, 0x28
    ctx->r2 = 0 | 0X28;
L_80043B30:
    // ori         $v0, $zero, 0x29
    ctx->r2 = 0 | 0X29;
L_80043B34:
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a2, 0x7($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X7, ctx->r2);
    // lwr         $a2, 0x4($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a2, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r6);
    // swr         $a2, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r6);
    // j           L_80043BE0
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    goto L_80043BE0;
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
L_80043B9C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x18
    ctx->r5 = 0 | 0X18;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xB
    ctx->r2 = 0 | 0XB;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
L_80043BE0:
    // jal         0x8004248C
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    PlayEntitySound(rdram, ctx);
    goto after_43;
    // sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    after_43:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043BF0:
    // lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(0X10, ctx->r17);
    // lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(0X4, ctx->r17);
    // jal         0x80042C88
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    SetupEntityAnimation(rdram, ctx);
    goto after_44;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_44:
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(0X14, ctx->r17);
    // j           L_800440CC
    // sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
    goto L_800440CC;
    // sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
L_80043C24:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // lw          $v0, 0x184($gp)
    ctx->r2 = MEM_W(0X184, ctx->r28);
    // lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // lw          $a1, -0x5A50($a1)
    ctx->r5 = MEM_W(-0X5A50, ctx->r5);
    // nop

    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // bgez        $v0, L_800440D0
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_800440D0;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lui         $v0, 0xB60B
    ctx->r2 = S32(0XB60B << 16);
    // lhu         $v1, 0x40($s0)
    ctx->r3 = MEM_HU(0X40, ctx->r16);
    // ori         $v0, $v0, 0x60B7
    ctx->r2 = ctx->r2 | 0X60B7;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) >> 16;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $v0, $a1, 0x1E
    ctx->r2 = ADD32(ctx->r5, 0X1E);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sw          $v0, 0x184($gp)
    MEM_W(0X184, ctx->r28) = ctx->r2;
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // slti        $v0, $a2, 0x80
    ctx->r2 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80043CC8
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
        goto L_80043CC8;
    }
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // ori         $a2, $zero, 0x7F
    ctx->r6 = 0 | 0X7F;
L_80043CC8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4C3C($v0)
    ctx->r2 = MEM_H(-0X4C3C, ctx->r2);
    // nop

    // beq         $v0, $a0, L_80043D00
    if (ctx->r2 == ctx->r4) {
        // sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2) << 3;
        goto L_80043D00;
    }
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x59AC
    ctx->r1 = ADD32(ctx->r1, -0X59AC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // nop

    // beq         $v1, $a0, L_80043D00
    if (ctx->r3 == ctx->r4) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_80043D00;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // bne         $v1, $v0, L_80043D38
    if (ctx->r3 != ctx->r2) {
        // ori         $a0, $zero, 0xEC
        ctx->r4 = 0 | 0XEC;
        goto L_80043D38;
    }
    // ori         $a0, $zero, 0xEC
    ctx->r4 = 0 | 0XEC;
L_80043D00:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4C1E($v0)
    ctx->r2 = MEM_H(-0X4C1E, ctx->r2);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // beq         $v0, $a0, L_800440CC
    if (ctx->r2 == ctx->r4) {
        // sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2) << 3;
        goto L_800440CC;
    }
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // addiu       $at, $at, -0x59AC
    ctx->r1 = ADD32(ctx->r1, -0X59AC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v1, 0x0($at)
    ctx->r3 = MEM_H(0X0, ctx->r1);
    // nop

    // beq         $v1, $a0, L_800440CC
    if (ctx->r3 == ctx->r4) {
        // ori         $v0, $zero, 0xFE
        ctx->r2 = 0 | 0XFE;
        goto L_800440CC;
    }
    // ori         $v0, $zero, 0xFE
    ctx->r2 = 0 | 0XFE;
    // beq         $v1, $v0, L_800440CC
    if (ctx->r3 == ctx->r2) {
        // ori         $a0, $zero, 0xEF
        ctx->r4 = 0 | 0XEF;
        goto L_800440CC;
    }
    // ori         $a0, $zero, 0xEF
    ctx->r4 = 0 | 0XEF;
L_80043D38:
    // addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // ori         $a3, $zero, 0x6D60
    ctx->r7 = 0 | 0X6D60;
    // ori         $v0, $zero, 0x7148
    ctx->r2 = 0 | 0X7148;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80014414
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    PlayPositionalSound3D_Wrap(rdram, ctx);
    goto after_45;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_45:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043D58:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80042CC8
    // ori         $a1, $zero, 0x19
    ctx->r5 = 0 | 0X19;
    sub_80042CC8(rdram, ctx);
    goto after_46;
    // ori         $a1, $zero, 0x19
    ctx->r5 = 0 | 0X19;
    after_46:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043D6C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80042CC8
    // ori         $a1, $zero, 0x1A
    ctx->r5 = 0 | 0X1A;
    sub_80042CC8(rdram, ctx);
    goto after_47;
    // ori         $a1, $zero, 0x1A
    ctx->r5 = 0 | 0X1A;
    after_47:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043D80:
    // ori         $a0, $zero, 0x2B
    ctx->r4 = 0 | 0X2B;
    // ori         $a1, $zero, 0x78
    ctx->r5 = 0 | 0X78;
    // j           L_80043D9C
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
    goto L_80043D9C;
    // ori         $v0, $zero, 0x8
    ctx->r2 = 0 | 0X8;
L_80043D90:
    // ori         $a0, $zero, 0x2B
    ctx->r4 = 0 | 0X2B;
    // ori         $a1, $zero, 0x78
    ctx->r5 = 0 | 0X78;
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
L_80043D9C:
    // sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // jal         0x80014570
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    PlaySoundEffect(rdram, ctx);
    goto after_48;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    after_48:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043DB0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x1E
    ctx->r5 = 0 | 0X1E;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    SetupEntityAnimation(rdram, ctx);
    goto after_49;
    // ori         $a2, $zero, 0x1000
    ctx->r6 = 0 | 0X1000;
    after_49:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    // sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1E
    ctx->r2 = 0 | 0X1E;
    // jal         0x80062BF0
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_50;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    after_50:
    // lhu         $v1, 0x34($s0)
    ctx->r3 = MEM_HU(0X34, ctx->r16);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_51;
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    after_51:
    // lhu         $v1, 0x36($s0)
    ctx->r3 = MEM_HU(0X36, ctx->r16);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_52;
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    after_52:
    // lhu         $v1, 0x38($s0)
    ctx->r3 = MEM_HU(0X38, ctx->r16);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // j           L_80044080
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    goto L_80044080;
    // addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
L_80043E14:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x1F
    ctx->r5 = 0 | 0X1F;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xB
    ctx->r2 = 0 | 0XB;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x44
    ctx->r2 = 0 | 0X44;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // sh          $zero, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = 0;
    // jal         0x8004248C
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    PlayEntitySound(rdram, ctx);
    goto after_53;
    // sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    after_53:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80043E64:
    // lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(0X18, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x26
    ctx->r2 = 0 | 0X26;
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x2D
    ctx->r2 = 0 | 0X2D;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // jal         0x80062BF0
    // sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_54;
    // sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    after_54:
    // lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(0X14, ctx->r16);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // jal         0x80062BF0
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_55;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_55:
    // lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(0X1C, ctx->r16);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xA
    ctx->r2 = 0 | 0XA;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(0X18, ctx->r16);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // jal         0x8002E318
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    CollisionWithTilemap(rdram, ctx);
    goto after_56;
    // ori         $a3, $zero, 0xA
    ctx->r7 = 0 | 0XA;
    after_56:
    // beq         $v0, $zero, L_80043EFC
    if (ctx->r2 == 0) {
        // ori         $v1, $zero, 0x64
        ctx->r3 = 0 | 0X64;
        goto L_80043EFC;
    }
    // ori         $v1, $zero, 0x64
    ctx->r3 = 0 | 0X64;
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80043EFC:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // addiu       $v0, $v0, -0xAAA
    ctx->r2 = ADD32(ctx->r2, -0XAAA);
    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(0X18, ctx->r16);
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    // sh          $v1, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, -0x4000
    ctx->r2 = ADD32(ctx->r2, -0X4000);
    // sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x258
    ctx->r2 = 0 | 0X258;
    // sh          $v0, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x4000
    ctx->r2 = 0 | 0X4000;
    // addiu       $a0, $a0, -0xAAA
    ctx->r4 = ADD32(ctx->r4, -0XAAA);
    // sh          $v0, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // sh          $v0, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r2;
    // j           L_800440CC
    // sw          $a0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r4;
    goto L_800440CC;
    // sw          $a0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r4;
L_80043F48:
    // j           L_80043F64
    // ori         $v0, $zero, 0x2A
    ctx->r2 = 0 | 0X2A;
    goto L_80043F64;
    // ori         $v0, $zero, 0x2A
    ctx->r2 = 0 | 0X2A;
L_80043F50:
    // j           L_80043F64
    // ori         $v0, $zero, 0x2B
    ctx->r2 = 0 | 0X2B;
    goto L_80043F64;
    // ori         $v0, $zero, 0x2B
    ctx->r2 = 0 | 0X2B;
L_80043F58:
    // j           L_80043F64
    // ori         $v0, $zero, 0x1D
    ctx->r2 = 0 | 0X1D;
    goto L_80043F64;
    // ori         $v0, $zero, 0x1D
    ctx->r2 = 0 | 0X1D;
L_80043F60:
    // ori         $v0, $zero, 0x1C
    ctx->r2 = 0 | 0X1C;
L_80043F64:
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(0X2, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x80
    ctx->r2 = 0 | 0X80;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // sb          $v1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r3;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r3);
    // swr         $v1, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r3);
    // swl         $a0, 0x2B($s0)
    do_swl(rdram, 0X2B, ctx->r16, ctx->r4);
    // swr         $a0, 0x28($s0)
    do_swr(rdram, 0X28, ctx->r16, ctx->r4);
    // sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // j           L_800440CC
    // sh          $zero, 0x42($s0)
    MEM_H(0X42, ctx->r16) = 0;
    goto L_800440CC;
    // sh          $zero, 0x42($s0)
    MEM_H(0X42, ctx->r16) = 0;
L_80043FBC:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    SetupEntityAnimation(rdram, ctx);
    goto after_57;
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    after_57:
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // sh          $zero, 0x38($s0)
    MEM_H(0X38, ctx->r16) = 0;
    // sh          $zero, 0x36($s0)
    MEM_H(0X36, ctx->r16) = 0;
    // sh          $zero, 0x34($s0)
    MEM_H(0X34, ctx->r16) = 0;
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // ori         $a1, $zero, 0x26
    ctx->r5 = 0 | 0X26;
L_80044000:
    // jal         0x8004248C
    // sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    PlayEntitySound(rdram, ctx);
    goto after_58;
    // sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    after_58:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80044010:
    // ori         $v0, $zero, 0x46
    ctx->r2 = 0 | 0X46;
L_80044014:
    // sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // j           L_800440CC
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    goto L_800440CC;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
L_80044020:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0xE
    ctx->r5 = 0 | 0XE;
    // jal         0x80042C88
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    SetupEntityAnimation(rdram, ctx);
    goto after_59;
    // ori         $a2, $zero, 0x400
    ctx->r6 = 0 | 0X400;
    after_59:
    // ori         $v0, $zero, 0x14
    ctx->r2 = 0 | 0X14;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(0X4, ctx->r17);
    // jal         0x80062BF0
    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_60;
    // sb          $v0, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r2;
    after_60:
    // lhu         $v1, 0x34($s0)
    ctx->r3 = MEM_HU(0X34, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_61;
    // sh          $v1, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r3;
    after_61:
    // lhu         $v1, 0x36($s0)
    ctx->r3 = MEM_HU(0X36, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80062BF0
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_62;
    // sh          $v1, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r3;
    after_62:
    // lhu         $v1, 0x38($s0)
    ctx->r3 = MEM_HU(0X38, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
L_80044080:
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_800440CC
    // sh          $v1, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r3;
    goto L_800440CC;
    // sh          $v1, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r3;
L_8004408C:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x32
    ctx->r5 = 0 | 0X32;
    // jal         0x80042C88
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    SetupEntityAnimation(rdram, ctx);
    goto after_63;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_63:
    // ori         $v0, $zero, 0x64
    ctx->r2 = 0 | 0X64;
    // jal         0x80062BF0
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_64;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    after_64:
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_800440CC
    if (ctx->r2 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800440CC;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8004248C
    // ori         $a1, $zero, 0x21
    ctx->r5 = 0 | 0X21;
    PlayEntitySound(rdram, ctx);
    goto after_65;
    // ori         $a1, $zero, 0x21
    ctx->r5 = 0 | 0X21;
    after_65:
    // j           L_800440D0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800440D0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800440C4:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_800440CC:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800440D0:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
