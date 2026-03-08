#include "recomp.h"
#include "disable_warnings.h"
#include <string>
/*
FFFFFFFF LoadingTilemap:  = 0
FFFFFFFF LoadingScript:   = 1
FFFFFFFF LoadingDatabase: = 2
FFFFFFFF LoadingTileset:  = 3
FFFFFFFF LoadingTextures: = 4
FFFFFFFF LoadingMusic:    = 5
FFFFFFFF Ready:           = 6
FFFFFFFF Unknown0x07:     = 7
FFFFFFFF Unknown0x08:     = 8
FFFFFFFF Unknown0x09:     = 9
FFFFFFFF Unknown0x0A:     = 10
FFFFFFFF Waiting:         = 240
*/

std::string GetStateName(int state)
{
    switch (state)
    {
    case 0: return "LoadingTilemap";
    case 1: return "LoadingScript";
    case 2: return "LoadingDatabase";
    case 3: return "LoadingTileset";
    case 4: return "LoadingTextures";
    case 5: return "LoadingMusic";
    case 6: return "Ready";
    case 7: return "Unknown0x07";
    case 8: return "Unknown0x08";
    case 9: return "Unknown0x09";
    case 10: return "Unknown0x0A";
    case 240: return "Waiting";
    }
    return "unknown!";
}



void Map_Load(uint8_t* rdram, recomp_context* ctx) 
{
    //801779D6 g_CurrentMapLoadState
    // int state = (int16_t)MEM_H(0, 0x801779D6);
    // printf("Map_Load state <%s>\n", GetStateName(state).c_str() );

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lh          $v1, 0x79D4($v1)
    ctx->r3 = MEM_H(0X79D4, ctx->r3);
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // beq         $v1, $zero, L_80017348
    if (ctx->r3 == 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80017348;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80017348
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80017348;
    }
    // nop

    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lh          $v1, 0x79D6($v1)
    ctx->r3 = MEM_H(0X79D6, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80017348
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80017348;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1058
    ctx->r1 = ADD32(ctx->r1, 0X1058);
    // addu        $at, $at, $v0
    gpr jr_addend_80016D34;
    jr_addend_80016D34 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80016D34 >> 2) {
        case 0: goto L_80016D3C; break;
        case 1: goto L_80016DAC; break;
        case 2: goto L_80016E8C; break;
        case 3: goto L_80016EDC; break;
        case 4: goto L_800170D8; break;
        case 5: goto L_800171E4; break;
        case 6: goto L_80017318; break;
        default: switch_error(__func__, 0x80016D34, 0x80011058);
    }
    // nop

L_80016D3C:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E4($v1)
    ctx->r3 = MEM_BU(0X79E4, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80016EDC
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80016EDC;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x6810
    ctx->r2 = ADD32(ctx->r2, -0X6810);
    // ori         $s1, $zero, 0x18B
    ctx->r17 = 0 | 0X18B;
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80016D6C:
    // sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $v1, L_80016D6C
    if (ctx->r17 != ctx->r3) {
        // addiu       $v0, $v0, 0x44
        ctx->r2 = ADD32(ctx->r2, 0X44);
        goto L_80016D6C;
    }
    // addiu       $v0, $v0, 0x44
    ctx->r2 = ADD32(ctx->r2, 0X44);
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    // lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // addiu       $a2, $a2, -0x5754
    ctx->r6 = ADD32(ctx->r6, -0X5754);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E4($v0)
    ctx->r2 = MEM_BU(0X79E4, ctx->r2);
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x6C6C
    ctx->r7 = ADD32(ctx->r7, 0X6C6C);
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // jal         0x800184A4
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    TLoadFileASync1(rdram, ctx);
    goto after_0;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_0:
    // j           L_80017348
    // nop

    goto L_80017348;
    // nop

L_80016DAC:
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, -0x5754
    ctx->r16 = ADD32(ctx->r16, -0X5754);
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a2, $a2, 0x1190
    ctx->r6 = ADD32(ctx->r6, 0X1190);
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x6C94
    ctx->r7 = ADD32(ctx->r7, 0X6C94);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E4($v1)
    ctx->r3 = MEM_BU(0X79E4, ctx->r3);
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // addiu       $v0, $v0, 0x7A28
    ctx->r2 = ADD32(ctx->r2, 0X7A28);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v0, 0x79E0($at)
    MEM_W(0X79E0, ctx->r1) = ctx->r2;
    // sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3) << 1;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // jal         0x800184A4
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    TLoadFileASync1(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_1:
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x428C
    ctx->r4 = ADD32(ctx->r4, -0X428C);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // ori         $a2, $zero, 0x3E80
    ctx->r6 = 0 | 0X3E80;
    MemcpyDword(rdram, ctx);
    goto after_2;
    // ori         $a2, $zero, 0x3E80
    ctx->r6 = 0 | 0X3E80;
    after_2:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, -0x428C
    ctx->r4 = ADD32(ctx->r4, -0X428C);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // ori         $a2, $zero, 0x600
    ctx->r6 = 0 | 0X600;
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // jal         0x80017684
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    MemcpyDword(rdram, ctx);
    goto after_3;
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lb          $a0, 0x79EB($a0)
    ctx->r4 = MEM_B(0X79EB, ctx->r4);
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // beq         $a0, $v0, L_80016E70
    if (ctx->r4 == ctx->r2) {
        // sll         $a0, $a0, 11
        ctx->r4 = S32(ctx->r4) << 11;
        goto L_80016E70;
    }
    // sll         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) << 11;
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // lb          $a1, 0x79ED($a1)
    ctx->r5 = MEM_B(0X79ED, ctx->r5);
    // lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // lb          $a2, 0x79EC($a2)
    ctx->r6 = MEM_B(0X79EC, ctx->r6);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79E9($at)
    MEM_B(0X79E9, ctx->r1) = ctx->r2;
    // negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // sll         $a1, $a1, 7
    ctx->r5 = S32(ctx->r5) << 7;
    // jal         0x80016580
    // sll         $a2, $a2, 11
    ctx->r6 = S32(ctx->r6) << 11;
    sub_80016580(rdram, ctx);
    goto after_4;
    // sll         $a2, $a2, 11
    ctx->r6 = S32(ctx->r6) << 11;
    after_4:
L_80016E70:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E4($v0)
    ctx->r2 = MEM_BU(0X79E4, ctx->r2);
    // nop

    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DD($at)
    MEM_B(0X79DD, ctx->r1) = ctx->r2;
    // j           L_80017348
    // nop

    goto L_80017348;
    // nop

L_80016E8C:
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    // lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // addiu       $a2, $a2, -0x5754
    ctx->r6 = ADD32(ctx->r6, -0X5754);
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x6C80
    ctx->r7 = ADD32(ctx->r7, 0X6C80);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E4($v1)
    ctx->r3 = MEM_BU(0X79E4, ctx->r3);
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = ctx->r2;
    // sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3) << 1;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // jal         0x800184A4
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    TLoadFileASync1(rdram, ctx);
    goto after_5;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_5:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, 0x1190
    ctx->r2 = ADD32(ctx->r2, 0X1190);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sw          $v0, 0x79E0($at)
    MEM_W(0X79E0, ctx->r1) = ctx->r2;
    // j           L_80017348
    // nop

    goto L_80017348;
    // nop

L_80016EDC:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x79E5
    ctx->r3 = ADD32(ctx->r3, 0X79E5);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // ori         $s0, $zero, 0xFF
    ctx->r16 = 0 | 0XFF;
    // beq         $v0, $s0, L_80016F18
    if (ctx->r2 == ctx->r16) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80016F18;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // addiu       $a2, $a2, 0xA90
    ctx->r6 = ADD32(ctx->r6, 0XA90);
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x6CA8
    ctx->r7 = ADD32(ctx->r7, 0X6CA8);
    // lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(0X0, ctx->r3);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = ctx->r2;
    // jal         0x800184A4
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    TLoadFileASync1(rdram, ctx);
    goto after_6;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_6:
L_80016F18:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E4($v0)
    ctx->r2 = MEM_BU(0X79E4, ctx->r2);
    // nop

    // beq         $v0, $s0, L_800170C4
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_800170C4;
    }
    // nop

    // lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // addiu       $s2, $s2, -0x5754
    ctx->r18 = ADD32(ctx->r18, -0X5754);
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // addiu       $s0, $s0, -0x19F8
    ctx->r16 = ADD32(ctx->r16, -0X19F8);
    // ori         $s1, $zero, 0xC7
    ctx->r17 = 0 | 0XC7;
    // ori         $s4, $zero, 0xFF
    ctx->r20 = 0 | 0XFF;
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_80016F48:
    // lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(0X5C, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80016F60
    if (ctx->r4 == 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80016F60;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // jal         0x80037138
    // nop

    Resource_UnlinkAndFree(rdram, ctx);
    goto after_7;
    // nop

    after_7:
L_80016F60:
    // sb          $s4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r20;
    // bne         $s1, $s3, L_80016F48
    if (ctx->r17 != ctx->r19) {
        // addiu       $s0, $s0, 0x7C
        ctx->r16 = ADD32(ctx->r16, 0X7C);
        goto L_80016F48;
    }
    // addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // ori         $s1, $zero, 0x18B
    ctx->r17 = 0 | 0X18B;
    // ori         $s5, $zero, 0x20
    ctx->r21 = 0 | 0X20;
    // ori         $s3, $zero, 0xFF
    ctx->r19 = 0 | 0XFF;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // addiu       $s0, $s0, -0x680A
    ctx->r16 = ADD32(ctx->r16, -0X680A);
L_80016F84:
    // lw          $a0, 0x2E($s0)
    ctx->r4 = MEM_W(0X2E, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80016F9C
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80016F9C;
    }
    // nop

    // jal         0x80037138
    // nop

    Resource_UnlinkAndFree(rdram, ctx);
    goto after_8;
    // nop

    after_8:
L_80016F9C:
    // lbu         $v0, -0x2($s0)
    ctx->r2 = MEM_BU(-0X2, ctx->r16);
    // nop

    // bne         $v0, $s5, L_80016FBC
    if (ctx->r2 != ctx->r21) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80016FBC;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // lw          $a0, 0x3A($s0)
    ctx->r4 = MEM_W(0X3A, ctx->r16);
    // jal         0x80017C40
    // nop

    KF_PadChkVsync(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // sb          $s3, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r19;
L_80016FBC:
    // sh          $s3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r19;
    // bne         $s1, $s4, L_80016F84
    if (ctx->r17 != ctx->r20) {
        // addiu       $s0, $s0, 0x44
        ctx->r16 = ADD32(ctx->r16, 0X44);
        goto L_80016F84;
    }
    // addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lb          $v1, 0x79EB($v1)
    ctx->r3 = MEM_B(0X79EB, ctx->r3);
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // beq         $v1, $v0, L_80017028
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80017028;
    }
    // nop

    // ori         $s1, $zero, 0x1900
    ctx->r17 = 0 | 0X1900;
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x4285
    ctx->r4 = ADD32(ctx->r4, -0X4285);
L_80016FE8:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // lbu         $v0, -0x5($a0)
    ctx->r2 = MEM_BU(-0X5, ctx->r4);
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // sb          $v0, -0x5($a0)
    MEM_B(-0X5, ctx->r4) = ctx->r2;
    // sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // bne         $s1, $zero, L_80016FE8
    if (ctx->r17 != 0) {
        // addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
        goto L_80016FE8;
    }
    // addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // ori         $a2, $zero, 0x320
    ctx->r6 = 0 | 0X320;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A64($a0)
    ctx->r4 = MEM_W(-0X4A64, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A5C($a1)
    ctx->r5 = MEM_W(-0X4A5C, ctx->r5);
    // jal         0x8002E25C
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    Map_MarkOccupiedTiles(rdram, ctx);
    goto after_10;
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    after_10:
L_80017028:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, 0x46E8
    ctx->r4 = ADD32(ctx->r4, 0X46E8);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80017684
    // ori         $a2, $zero, 0xCB0
    ctx->r6 = 0 | 0XCB0;
    MemcpyDword(rdram, ctx);
    goto after_11;
    // ori         $a2, $zero, 0xCB0
    ctx->r6 = 0 | 0XCB0;
    after_11:
    // jal         0x80042244
    // nop

    sub_80042244(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // jal         0x800422B8
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    sub_800422B8(rdram, ctx);
    goto after_13;
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_13:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // jal         0x8003830C
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    Map_InitializeObjects(rdram, ctx);
    goto after_14;
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_14:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // jal         0x800372AC
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    sub_800372AC(rdram, ctx);
    goto after_15;
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_15:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // lbu         $a0, 0x79E4($a0)
    ctx->r4 = MEM_BU(0X79E4, ctx->r4);
    // jal         0x8004B31C
    // nop

    sub_8004B31C(rdram, ctx);
    goto after_16;
    // nop

    after_16:
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
    goto after_17;
    // nop

    after_17:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4B32($at)
    MEM_B(-0X4B32, ctx->r1) = ctx->r2;
L_800170C4:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E5($v1)
    ctx->r3 = MEM_BU(0X79E5, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // bne         $v1, $v0, L_80017348
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80017348;
    }
    // nop

L_800170D8:
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // lbu         $a1, 0x79E6($a1)
    ctx->r5 = MEM_BU(0X79E6, ctx->r5);
    // ori         $s0, $zero, 0xFF
    ctx->r16 = 0 | 0XFF;
    // beq         $a1, $s0, L_800170F4
    if (ctx->r5 == ctx->r16) {
        // nop
    
        goto L_800170F4;
    }
    // nop

    // jal         0x8001737C
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    QueueCDReadTask(rdram, ctx);
    goto after_18;
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    after_18:
L_800170F4:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E7($v1)
    ctx->r3 = MEM_BU(0X79E7, ctx->r3);
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79EA($at)
    MEM_B(0X79EA, ctx->r1) = 0;
    // bne         $v1, $s0, L_800171C8
    if (ctx->r3 != ctx->r16) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_800171C8;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E8($v0)
    ctx->r2 = MEM_BU(0X79E8, ctx->r2);
    // nop

    // bne         $v0, $v1, L_800171C8
    if (ctx->r2 != ctx->r3) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_800171C8;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
L_80017120:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, 0x79E4
    ctx->r4 = ADD32(ctx->r4, 0X79E4);
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // ori         $v1, $zero, 0xFF
    ctx->r3 = 0 | 0XFF;
    // beq         $v0, $v1, L_80017148
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80017148;
    }
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79D8($at)
    MEM_B(0X79D8, ctx->r1) = ctx->r2;
L_80017148:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E5($v0)
    ctx->r2 = MEM_BU(0X79E5, ctx->r2);
    // nop

    // beq         $v0, $v1, L_80017164
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80017164;
    }
    // nop

    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79D9($at)
    MEM_B(0X79D9, ctx->r1) = ctx->r2;
L_80017164:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E6($v0)
    ctx->r2 = MEM_BU(0X79E6, ctx->r2);
    // nop

    // beq         $v0, $v1, L_80017180
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80017180;
    }
    // nop

    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DA($at)
    MEM_B(0X79DA, ctx->r1) = ctx->r2;
L_80017180:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E7($v0)
    ctx->r2 = MEM_BU(0X79E7, ctx->r2);
    // nop

    // beq         $v0, $v1, L_8001719C
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_8001719C;
    }
    // nop

    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DB($at)
    MEM_B(0X79DB, ctx->r1) = ctx->r2;
L_8001719C:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E8($v0)
    ctx->r2 = MEM_BU(0X79E8, ctx->r2);
    // nop

    // beq         $v0, $v1, L_800171B8
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_800171B8;
    }
    // nop

    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DC($at)
    MEM_B(0X79DC, ctx->r1) = ctx->r2;
L_800171B8:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $zero, 0x79D4($at)
    MEM_H(0X79D4, ctx->r1) = 0;
    // j           L_80017348
    // nop

    goto L_80017348;
    // nop

L_800171C8:
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x3C
    ctx->r2 = 0 | 0X3C;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79EE($at)
    MEM_H(0X79EE, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x59CC($at)
    MEM_W(-0X59CC, ctx->r1) = 0;
L_800171E4:
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // addiu       $s1, $s1, -0x59D0
    ctx->r17 = ADD32(ctx->r17, -0X59D0);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8001726C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001726C;
    }
    // nop

    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // addiu       $s0, $s0, 0x79EE
    ctx->r16 = ADD32(ctx->r16, 0X79EE);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_80017224
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_80017224;
    }
    // nop

    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_80017224:
    // lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(0X0, ctx->r16);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x80052198
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    CDAudio_SetVolume(rdram, ctx);
    goto after_19;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_19:
    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80017348
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80017348;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x8005C7A4
    // nop

    CDAudio_Stop(rdram, ctx);
    goto after_20;
    // nop

    after_20:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x8005D4F0
    // nop

    SpuVoice_StopAll(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8001726C:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x59A4($v1)
    ctx->r3 = MEM_H(-0X59A4, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80017288
    if (ctx->r3 == ctx->r2) {
        // ori         $s0, $zero, 0xFF
        ctx->r16 = 0 | 0XFF;
        goto L_80017288;
    }
    // ori         $s0, $zero, 0xFF
    ctx->r16 = 0 | 0XFF;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x59A0($at)
    MEM_W(-0X59A0, ctx->r1) = 0;
L_80017288:
    // lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // lbu         $a1, 0x79E7($a1)
    ctx->r5 = MEM_BU(0X79E7, ctx->r5);
    // nop

    // beq         $a1, $s0, L_800172A8
    if (ctx->r5 == ctx->r16) {
        // ori         $a0, $zero, 0x4
        ctx->r4 = 0 | 0X4;
        goto L_800172A8;
    }
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // jal         0x80014BB0
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    StartAudioStream(rdram, ctx);
    goto after_22;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_22:
L_800172A8:
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // lbu         $v1, 0x79E8($v1)
    ctx->r3 = MEM_BU(0X79E8, ctx->r3);
    // nop

    // beq         $v1, $s0, L_80017120
    if (ctx->r3 == ctx->r16) {
        // lui         $v0, 0x51EB
        ctx->r2 = S32(0X51EB << 16);
        goto L_80017120;
    }
    // lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x6CBC
    ctx->r7 = ADD32(ctx->r7, 0X6CBC);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, -0x59D8($a2)
    ctx->r6 = MEM_W(-0X59D8, ctx->r6);
    // mfhi        $v0
    ctx->r2 = hi;
    // srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5) << 3;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // jal         0x800184A4
    // addiu       $a1, $a1, 0x140
    ctx->r5 = ADD32(ctx->r5, 0X140);
    TLoadFileASync1(rdram, ctx);
    goto after_23;
    // addiu       $a1, $a1, 0x140
    ctx->r5 = ADD32(ctx->r5, 0X140);
    after_23:
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $v0, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = ctx->r2;
    // j           L_80017348
    // nop

    goto L_80017348;
    // nop

L_80017318:
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lbu         $v0, 0x79E8($v0)
    ctx->r2 = MEM_BU(0X79E8, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x64
    ctx->r2 = ctx->r2 < 0X64 ? 1 : 0;
    // beq         $v0, $zero, L_80017120
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80017120;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x59CC($at)
    MEM_W(-0X59CC, ctx->r1) = ctx->r2;
    // jal         0x80013FC0
    // nop

    Music_PlaySEQ(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // j           L_80017120
    // nop

    goto L_80017120;
    // nop

L_80017348:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
