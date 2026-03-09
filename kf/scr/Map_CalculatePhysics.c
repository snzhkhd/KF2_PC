#include "recomp.h"
#include "disable_warnings.h"

void Map_CalculatePhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // addu        $t9, $a1, $zero
    ctx->r25 = ADD32(ctx->r5, 0);
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x86A0
    ctx->r2 = ctx->r2 | 0X86A0;
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // ori         $a2, $a2, 0x63C0
    ctx->r6 = ctx->r6 | 0X63C0;
    // sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lhu         $a0, -0x2A82($a0)
    ctx->r4 = MEM_HU(-0X2A82, ctx->r4);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A8C($v1)
    ctx->r3 = MEM_W(-0X2A8C, ctx->r3);
    // lui         $a1, 0xFFF
    ctx->r5 = S32(0XFFF << 16);
    // sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // lw          $s7, 0x90($sp)
    ctx->r23 = MEM_W(0X90, ctx->r29);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A7C($at)
    MEM_W(-0X2A7C, ctx->r1) = ctx->r2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A74($at)
    MEM_W(-0X2A74, ctx->r1) = ctx->r2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A70($at)
    MEM_W(-0X2A70, ctx->r1) = ctx->r2;
    // lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // and         $v0, $s7, $v0
    ctx->r2 = ctx->r23 & ctx->r2;
    // sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A80($v0)
    ctx->r2 = MEM_W(-0X2A80, ctx->r2);
    // and         $s7, $s7, $a1
    ctx->r23 = ctx->r23 & ctx->r5;
    // sw          $s7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r23;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $t8, -0x2A88($at)
    MEM_W(-0X2A88, ctx->r1) = ctx->r24;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A78($at)
    MEM_W(-0X2A78, ctx->r1) = ctx->r2;
L_8002D678:
    // lbu         $v0, 0x3($t8)
    ctx->r2 = MEM_BU(0X3, ctx->r24);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x428C
    ctx->r1 = ADD32(ctx->r1, -0X428C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x428C
    ctx->r3 = ADD32(ctx->r3, -0X428C);
    // addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($t0)
    ctx->r2 = MEM_HS(0X0, ctx->r8);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $s7, 0x90($sp)
    ctx->r23 = MEM_W(0X90, ctx->r29);
    // nop

    // subu        $s0, $t9, $s7
    ctx->r16 = SUB32(ctx->r25, ctx->r23);
    // addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // lh          $s1, 0x0($t0)
    ctx->r17 = MEM_HS(0X0, ctx->r8);
    // nop

    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $a3, $v0, 12
    ctx->r7 = S32(ctx->r2) >> 12;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_8002E0EC
    if (ctx->r17 == ctx->r2) {
        // addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
        goto L_8002E0EC;
    }
    // addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // addiu       $t4, $v1, 0x180C
    ctx->r12 = ADD32(ctx->r3, 0X180C);
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
    // ori         $s3, $zero, 0x2
    ctx->r19 = 0 | 0X2;
    // ori         $s2, $zero, 0x3
    ctx->r18 = 0 | 0X3;
    // ori         $v1, $zero, 0x800
    ctx->r3 = 0 | 0X800;
    // lw          $s7, 0x0($sp)
    ctx->r23 = MEM_W(0X0, ctx->r29);
    // subu        $t5, $v1, $a3
    ctx->r13 = SUB32(ctx->r3, ctx->r7);
    // andi        $t3, $s7, 0x7FF
    ctx->r11 = ctx->r23 & 0X7FF;
    // addu        $t7, $t3, $zero
    ctx->r15 = ADD32(ctx->r11, 0);
    // negu        $v0, $t7
    ctx->r2 = SUB32(0, ctx->r15);
    // lw          $s7, 0x8($sp)
    ctx->r23 = MEM_W(0X8, ctx->r29);
    // subu        $s5, $v1, $t3
    ctx->r21 = SUB32(ctx->r3, ctx->r11);
    // andi        $t2, $s7, 0x7FF
    ctx->r10 = ctx->r23 & 0X7FF;
    // addu        $t6, $t2, $zero
    ctx->r14 = ADD32(ctx->r10, 0);
    // subu        $s7, $t7, $t6
    ctx->r23 = SUB32(ctx->r15, ctx->r14);
    // subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // sw          $s7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r23;
    // subu        $s7, $t6, $t7
    ctx->r23 = SUB32(ctx->r14, ctx->r15);
    // sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // addu        $s7, $t7, $t6
    ctx->r23 = ADD32(ctx->r15, ctx->r14);
    // subu        $s6, $v1, $t2
    ctx->r22 = SUB32(ctx->r3, ctx->r10);
    // sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // addiu       $s7, $t6, 0x800
    ctx->r23 = ADD32(ctx->r14, 0X800);
    // sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // addiu       $s7, $t7, 0x800
    ctx->r23 = ADD32(ctx->r15, 0X800);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
L_8002D748:
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // nop

    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // sltiu       $v0, $v1, 0x31
    ctx->r2 = ctx->r3 < 0X31 ? 1 : 0;
    // beq         $v0, $zero, L_8002E0DC
    if (ctx->r2 == 0) {
        // addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
        goto L_8002E0DC;
    }
    // addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1448
    ctx->r1 = ADD32(ctx->r1, 0X1448);
    // addu        $at, $at, $v0
    gpr jr_addend_8002D780;
    jr_addend_8002D780 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8002D780 >> 2) {
        case 0: goto L_8002D788; break;
        case 1: goto L_8002D7C8; break;
        case 2: goto L_8002E0DC; break;
        case 3: goto L_8002E0DC; break;
        case 4: goto L_8002E0DC; break;
        case 5: goto L_8002E0DC; break;
        case 6: goto L_8002E0DC; break;
        case 7: goto L_8002E0DC; break;
        case 8: goto L_8002E04C; break;
        case 9: goto L_8002E0BC; break;
        case 10: goto L_8002E0DC; break;
        case 11: goto L_8002E0DC; break;
        case 12: goto L_8002E0DC; break;
        case 13: goto L_8002E0DC; break;
        case 14: goto L_8002E0DC; break;
        case 15: goto L_8002E0DC; break;
        case 16: goto L_8002D84C; break;
        case 17: goto L_8002D940; break;
        case 18: goto L_8002DA18; break;
        case 19: goto L_8002DB18; break;
        case 20: goto L_8002E0DC; break;
        case 21: goto L_8002E0DC; break;
        case 22: goto L_8002E0DC; break;
        case 23: goto L_8002E0DC; break;
        case 24: goto L_8002E0DC; break;
        case 25: goto L_8002E0DC; break;
        case 26: goto L_8002E0DC; break;
        case 27: goto L_8002E0DC; break;
        case 28: goto L_8002E0DC; break;
        case 29: goto L_8002E0DC; break;
        case 30: goto L_8002E0DC; break;
        case 31: goto L_8002E0DC; break;
        case 32: goto L_8002DBC8; break;
        case 33: goto L_8002DF00; break;
        case 34: goto L_8002DDD4; break;
        case 35: goto L_8002E0DC; break;
        case 36: goto L_8002E0DC; break;
        case 37: goto L_8002E0DC; break;
        case 38: goto L_8002E0DC; break;
        case 39: goto L_8002E0DC; break;
        case 40: goto L_8002E0DC; break;
        case 41: goto L_8002E0DC; break;
        case 42: goto L_8002E0DC; break;
        case 43: goto L_8002E0DC; break;
        case 44: goto L_8002E0DC; break;
        case 45: goto L_8002E0DC; break;
        case 46: goto L_8002E0DC; break;
        case 47: goto L_8002E0DC; break;
        case 48: goto L_8002DFF0; break;
        default: switch_error(__func__, 0x8002D780, 0x80011448);
    }
    // nop

L_8002D788:
    // addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // lw          $s7, 0x10($sp)
    ctx->r23 = MEM_W(0X10, ctx->r29);
    // nop

    // bne         $s7, $zero, L_8002E0DC
    if (ctx->r23 != 0) {
        // addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
        goto L_8002E0DC;
    }
    // addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // lh          $a0, 0x0($v0)
    ctx->r4 = MEM_HS(0X0, ctx->r2);
    // lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(0X0, ctx->r12);
    // lw          $v0, 0x4($t4)
    ctx->r2 = MEM_W(0X4, ctx->r12);
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002D7BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D7BC;
    }
    // nop

    // sw          $a0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r4;
L_8002D7BC:
    // lw          $v0, 0x4($t4)
    ctx->r2 = MEM_W(0X4, ctx->r12);
    // j           L_8002DED0
    // slt         $v0, $v0, $t9
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    goto L_8002DED0;
    // slt         $v0, $v0, $t9
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
L_8002D7C8:
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // bne         $s7, $zero, L_8002E0DC
    if (ctx->r23 != 0) {
        // addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
        goto L_8002E0DC;
    }
    // addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_HS(0X0, ctx->r4);
    // lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(0X0, ctx->r12);
    // nop

    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // slt         $v0, $s0, $a1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_8002D83C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D83C;
    }
    // nop

    // lh          $v0, 0x2($a0)
    ctx->r2 = MEM_HS(0X2, ctx->r4);
    // nop

    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // beq         $v0, $zero, L_8002D814
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D814;
    }
    // nop

    // j           L_8002D83C
    // ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
    goto L_8002D83C;
    // ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
L_8002D814:
    // lw          $v0, 0x4($t4)
    ctx->r2 = MEM_W(0X4, ctx->r12);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002D82C
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_8002D82C;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // sw          $v1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r3;
L_8002D82C:
    // lui         $v0, 0xFFFE
    ctx->r2 = S32(0XFFFE << 16);
    // ori         $v0, $v0, 0x7960
    ctx->r2 = ctx->r2 | 0X7960;
    // j           L_8002E0E0
    // sw          $v0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r2;
    goto L_8002E0E0;
    // sw          $v0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r2;
L_8002D83C:
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $a1, -0x2A78($at)
    MEM_W(-0X2A78, ctx->r1) = ctx->r5;
    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002D84C:
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // lbu         $v0, 0x2($t8)
    ctx->r2 = MEM_BU(0X2, ctx->r24);
    // lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(0X6, ctx->r5);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $s4, L_8002D908
    if (ctx->r3 == ctx->r20) {
        // ori         $a2, $zero, 0x5
        ctx->r6 = 0 | 0X5;
        goto L_8002D908;
    }
    // ori         $a2, $zero, 0x5
    ctx->r6 = 0 | 0X5;
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8002D88C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D88C;
    }
    // nop

    // beq         $v1, $zero, L_8002D8A4
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002D8A4;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002D88C:
    // beq         $v1, $s3, L_8002D914
    if (ctx->r3 == ctx->r19) {
        // nop
    
        goto L_8002D914;
    }
    // nop

    // beq         $v1, $s2, L_8002D934
    if (ctx->r3 == ctx->r18) {
        // nop
    
        goto L_8002D934;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002D8A4:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // slt         $v0, $v0, $t3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

L_8002D8BC:
    // lh          $a0, 0x2($a1)
    ctx->r4 = MEM_HS(0X2, ctx->r5);
    // lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(0X0, ctx->r12);
    // lh          $v1, 0x4($a1)
    ctx->r3 = MEM_HS(0X4, ctx->r5);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $s0, $a0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8002D900
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D900;
    }
    // nop

    // lw          $v0, 0x4($t4)
    ctx->r2 = MEM_W(0X4, ctx->r12);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002E0DC
    if (ctx->r2 == 0) {
        // slt         $v0, $v1, $t9
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
        goto L_8002E0DC;
    }
    // slt         $v0, $v1, $t9
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // beq         $v0, $zero, L_8002E0DC
    if (ctx->r2 == 0) {
        // sw          $v1, 0x4($t4)
        MEM_W(0X4, ctx->r12) = ctx->r3;
        goto L_8002E0DC;
    }
    // sw          $v1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r3;
    // j           L_8002E0DC
    // or          $t1, $t1, $a2
    ctx->r9 = ctx->r9 | ctx->r6;
    goto L_8002E0DC;
    // or          $t1, $t1, $a2
    ctx->r9 = ctx->r9 | ctx->r6;
L_8002D900:
    // j           L_8002E0DC
    // sw          $a0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r4;
    goto L_8002E0DC;
    // sw          $a0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r4;
L_8002D908:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // j           L_8002DA88
    // subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
    goto L_8002DA88;
    // subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
L_8002D914:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
    // slt         $v0, $t3, $v0
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D8BC;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002D934:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // j           L_8002DADC
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    goto L_8002DADC;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
L_8002D940:
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // lbu         $v0, 0x2($t8)
    ctx->r2 = MEM_BU(0X2, ctx->r24);
    // lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(0X6, ctx->r5);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $s4, L_8002D9B8
    if (ctx->r3 == ctx->r20) {
        // ori         $a2, $zero, 0x5
        ctx->r6 = 0 | 0X5;
        goto L_8002D9B8;
    }
    // ori         $a2, $zero, 0x5
    ctx->r6 = 0 | 0X5;
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8002D980
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D980;
    }
    // nop

    // beq         $v1, $zero, L_8002D998
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002D998;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002D980:
    // beq         $v1, $s3, L_8002D9D8
    if (ctx->r3 == ctx->r19) {
        // nop
    
        goto L_8002D9D8;
    }
    // nop

    // beq         $v1, $s2, L_8002D9F8
    if (ctx->r3 == ctx->r18) {
        // nop
    
        goto L_8002D9F8;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002D998:
    // lh          $v1, 0x0($a1)
    ctx->r3 = MEM_HS(0X0, ctx->r5);
    // nop

    // addu        $v0, $v1, $a3
    ctx->r2 = ADD32(ctx->r3, ctx->r7);
    // slt         $v0, $v0, $t3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // subu        $v0, $t5, $v1
        ctx->r2 = SUB32(ctx->r13, ctx->r3);
        goto L_8002D8BC;
    }
    // subu        $v0, $t5, $v1
    ctx->r2 = SUB32(ctx->r13, ctx->r3);
    // j           L_8002DA88
    // nop

    goto L_8002DA88;
    // nop

L_8002D9B8:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // subu        $v1, $t5, $v0
    ctx->r3 = SUB32(ctx->r13, ctx->r2);
    // slt         $v0, $t2, $v1
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // slt         $v0, $t3, $v1
        ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8002D8BC;
    }
    // slt         $v0, $t3, $v1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // j           L_8002DAB4
    // nop

    goto L_8002DAB4;
    // nop

L_8002D9D8:
    // lh          $v1, 0x0($a1)
    ctx->r3 = MEM_HS(0X0, ctx->r5);
    // nop

    // subu        $v0, $t5, $v1
    ctx->r2 = SUB32(ctx->r13, ctx->r3);
    // slt         $v0, $t3, $v0
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // addu        $v0, $v1, $a3
        ctx->r2 = ADD32(ctx->r3, ctx->r7);
        goto L_8002D8BC;
    }
    // addu        $v0, $v1, $a3
    ctx->r2 = ADD32(ctx->r3, ctx->r7);
    // j           L_8002DADC
    // nop

    goto L_8002DADC;
    // nop

L_8002D9F8:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // slt         $v0, $v1, $t2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // slt         $v0, $v1, $t3
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
        goto L_8002D8BC;
    }
    // slt         $v0, $v1, $t3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // j           L_8002DB08
    // nop

    goto L_8002DB08;
    // nop

L_8002DA18:
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // lbu         $v0, 0x2($t8)
    ctx->r2 = MEM_BU(0X2, ctx->r24);
    // lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(0X6, ctx->r5);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $s4, L_8002DA9C
    if (ctx->r3 == ctx->r20) {
        // ori         $a2, $zero, 0x5
        ctx->r6 = 0 | 0X5;
        goto L_8002DA9C;
    }
    // ori         $a2, $zero, 0x5
    ctx->r6 = 0 | 0X5;
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8002DA58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002DA58;
    }
    // nop

    // beq         $v1, $zero, L_8002DA70
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002DA70;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DA58:
    // beq         $v1, $s3, L_8002DAC4
    if (ctx->r3 == ctx->r19) {
        // nop
    
        goto L_8002DAC4;
    }
    // nop

    // beq         $v1, $s2, L_8002DAF0
    if (ctx->r3 == ctx->r18) {
        // nop
    
        goto L_8002DAF0;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DA70:
    // lh          $v1, 0x0($a1)
    ctx->r3 = MEM_HS(0X0, ctx->r5);
    // nop

    // addu        $v0, $v1, $a3
    ctx->r2 = ADD32(ctx->r3, ctx->r7);
    // slt         $v0, $v0, $t3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // subu        $v0, $t5, $v1
        ctx->r2 = SUB32(ctx->r13, ctx->r3);
        goto L_8002E0DC;
    }
    // subu        $v0, $t5, $v1
    ctx->r2 = SUB32(ctx->r13, ctx->r3);
L_8002DA88:
    // slt         $v0, $t2, $v0
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D8BC;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DA9C:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // subu        $v1, $t5, $v0
    ctx->r3 = SUB32(ctx->r13, ctx->r2);
    // slt         $v0, $t2, $v1
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // slt         $v0, $t3, $v1
        ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8002E0DC;
    }
    // slt         $v0, $t3, $v1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
L_8002DAB4:
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D8BC;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DAC4:
    // lh          $v1, 0x0($a1)
    ctx->r3 = MEM_HS(0X0, ctx->r5);
    // nop

    // subu        $v0, $t5, $v1
    ctx->r2 = SUB32(ctx->r13, ctx->r3);
    // slt         $v0, $t3, $v0
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $a3
        ctx->r2 = ADD32(ctx->r3, ctx->r7);
        goto L_8002E0DC;
    }
    // addu        $v0, $v1, $a3
    ctx->r2 = ADD32(ctx->r3, ctx->r7);
L_8002DADC:
    // slt         $v0, $v0, $t2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D8BC;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DAF0:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // slt         $v0, $v1, $t2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // slt         $v0, $v1, $t3
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
        goto L_8002E0DC;
    }
    // slt         $v0, $v1, $t3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
L_8002DB08:
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D8BC;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DB18:
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // lbu         $v0, 0x2($t8)
    ctx->r2 = MEM_BU(0X2, ctx->r24);
    // lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(0X6, ctx->r5);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $s4, L_8002DB80
    if (ctx->r3 == ctx->r20) {
        // ori         $a2, $zero, 0x6
        ctx->r6 = 0 | 0X6;
        goto L_8002DB80;
    }
    // ori         $a2, $zero, 0x6
    ctx->r6 = 0 | 0X6;
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8002DB58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002DB58;
    }
    // nop

    // beq         $v1, $zero, L_8002DB70
    if (ctx->r3 == 0) {
        // addiu       $v1, $a3, -0x800
        ctx->r3 = ADD32(ctx->r7, -0X800);
        goto L_8002DB70;
    }
    // addiu       $v1, $a3, -0x800
    ctx->r3 = ADD32(ctx->r7, -0X800);
    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DB58:
    // beq         $v1, $s3, L_8002DB94
    if (ctx->r3 == ctx->r19) {
        // nop
    
        goto L_8002DB94;
    }
    // nop

    // beq         $v1, $s2, L_8002DBA8
    if (ctx->r3 == ctx->r18) {
        // nop
    
        goto L_8002DBA8;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DB70:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // lw          $s7, 0x20($sp)
    ctx->r23 = MEM_W(0X20, ctx->r29);
    // j           L_8002DBB4
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8002DBB4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8002DB80:
    // addiu       $v1, $a3, -0x1000
    ctx->r3 = ADD32(ctx->r7, -0X1000);
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // lw          $s7, 0x28($sp)
    ctx->r23 = MEM_W(0X28, ctx->r29);
    // j           L_8002DBB4
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8002DBB4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8002DB94:
    // addiu       $v1, $a3, -0x800
    ctx->r3 = ADD32(ctx->r7, -0X800);
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(0X30, ctx->r29);
    // j           L_8002DBB4
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8002DBB4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8002DBA8:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(0X38, ctx->r29);
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
L_8002DBB4:
    // slt         $v0, $v0, $s7
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r23) ? 1 : 0;
    // beq         $v0, $zero, L_8002D8BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D8BC;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DBC8:
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // lbu         $v0, 0x2($t8)
    ctx->r2 = MEM_BU(0X2, ctx->r24);
    // lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(0X6, ctx->r5);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $s4, L_8002DC90
    if (ctx->r3 == ctx->r20) {
        // addiu       $t0, $t0, 0xC
        ctx->r8 = ADD32(ctx->r8, 0XC);
        goto L_8002DC90;
    }
    // addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8002DC04
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002DC04;
    }
    // nop

    // beq         $v1, $zero, L_8002DC1C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002DC1C;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DC04:
    // beq         $v1, $s3, L_8002DCFC
    if (ctx->r3 == ctx->r19) {
        // addiu       $v0, $a3, 0x800
        ctx->r2 = ADD32(ctx->r7, 0X800);
        goto L_8002DCFC;
    }
    // addiu       $v0, $a3, 0x800
    ctx->r2 = ADD32(ctx->r7, 0X800);
    // beq         $v1, $s2, L_8002DD68
    if (ctx->r3 == ctx->r18) {
        // nop
    
        goto L_8002DD68;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DC1C:
    // lh          $v0, 0x2($a1)
    ctx->r2 = MEM_HS(0X2, ctx->r5);
    // nop

    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // slt         $v0, $t7, $v0
    ctx->r2 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0x4($a1)
    ctx->r2 = MEM_HS(0X4, ctx->r5);
    // nop

    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // slt         $v0, $v0, $t7
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0xA($a1)
    ctx->r2 = MEM_HS(0XA, ctx->r5);
    // nop

    // div         $zero, $t2, $v0
	if (ctx->r2 != 0)
	{
		lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
	}
	else
	{
		lo = 0;
		hi = 0;
	}
    
    // bne         $v0, $zero, L_8002DC64
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002DC64;
    }
    // nop

    // break       7
    do_break(2147671136);
L_8002DC64:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8002DC7C
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002DC7C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $t2, $at, L_8002DC7C
    if (ctx->r10 != ctx->r1) {
        // nop
    
        goto L_8002DC7C;
    }
    // nop

    // break       6
    do_break(2147671160);
L_8002DC7C:
    // mflo        $a0
    ctx->r4 = lo;
L_8002DC80:
    // lh          $v1, 0x8($a1)
    ctx->r3 = MEM_HS(0X8, ctx->r5);
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // j           L_8002DEA4
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    goto L_8002DEA4;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8002DC90:
    // lh          $v1, 0x2($a1)
    ctx->r3 = MEM_HS(0X2, ctx->r5);
    // addiu       $v0, $a3, 0x800
    ctx->r2 = ADD32(ctx->r7, 0X800);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slt         $v0, $v0, $t6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0x4($a1)
    ctx->r2 = MEM_HS(0X4, ctx->r5);
    // nop

    // subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
    // slt         $v0, $t6, $v0
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0xA($a1)
    ctx->r2 = MEM_HS(0XA, ctx->r5);
    // nop

    // div         $zero, $t3, $v0
	if (ctx->r2 != 0)
	{
		lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
	}
    else { lo = 0; hi = 0; }
    // bne         $v0, $zero, L_8002DCD8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002DCD8;
    }
    // nop

    // break       7
    do_break(2147671252);
L_8002DCD8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8002DCF0
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002DCF0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $t3, $at, L_8002DCF0
    if (ctx->r11 != ctx->r1) {
        // nop
    
        goto L_8002DCF0;
    }
    // nop

    // break       6
    do_break(2147671276);
L_8002DCF0:
    // mflo        $a0
    ctx->r4 = lo;
    // j           L_8002DC80
    // nop

    goto L_8002DC80;
    // nop

L_8002DCFC:
    // lh          $v1, 0x2($a1)
    ctx->r3 = MEM_HS(0X2, ctx->r5);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slt         $v0, $v0, $t7
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0x4($a1)
    ctx->r2 = MEM_HS(0X4, ctx->r5);
    // nop

    // subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
    // slt         $v0, $t7, $v0
    ctx->r2 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0xA($a1)
    ctx->r2 = MEM_HS(0XA, ctx->r5);
    // nop

    // div         $zero, $s6, $v0
	if (ctx->r2 != 0)
	{
		lo = S32(S64(S32(ctx->r22)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r22)) % S64(S32(ctx->r2)));
	}
    else { lo = 0; hi = 0; }
    // bne         $v0, $zero, L_8002DD44
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002DD44;
    }
    // nop

    // break       7
    do_break(2147671360);
L_8002DD44:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8002DD5C
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002DD5C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $s6, $at, L_8002DD5C
    if (ctx->r22 != ctx->r1) {
        // nop
    
        goto L_8002DD5C;
    }
    // nop

    // break       6
    do_break(2147671384);
L_8002DD5C:
    // mflo        $a0
    ctx->r4 = lo;
    // j           L_8002DC80
    // nop

    goto L_8002DC80;
    // nop

L_8002DD68:
    // lh          $v0, 0x2($a1)
    ctx->r2 = MEM_HS(0X2, ctx->r5);
    // nop

    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // slt         $v0, $t6, $v0
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0x4($a1)
    ctx->r2 = MEM_HS(0X4, ctx->r5);
    // nop

    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // slt         $v0, $v0, $t6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0xA($a1)
    ctx->r2 = MEM_HS(0XA, ctx->r5);
    // nop

    // div         $zero, $s5, $v0
	if (ctx->r2 != 0)
	{
		lo = S32(S64(S32(ctx->r21)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r21)) % S64(S32(ctx->r2)));
	}
    else { lo = 0; hi = 0; }
    // bne         $v0, $zero, L_8002DDB0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002DDB0;
    }
    // nop

    // break       7
    do_break(2147671468);
L_8002DDB0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8002DDC8
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002DDC8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $s5, $at, L_8002DDC8
    if (ctx->r21 != ctx->r1) {
        // nop
    
        goto L_8002DDC8;
    }
    // nop

    // break       6
    do_break(2147671492);
L_8002DDC8:
    // mflo        $a0
    ctx->r4 = lo;
    // j           L_8002DC80
    // nop

    goto L_8002DC80;
    // nop

L_8002DDD4:
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // lbu         $v0, 0x2($t8)
    ctx->r2 = MEM_BU(0X2, ctx->r24);
    // lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(0X6, ctx->r5);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $s4, L_8002DEE0
    if (ctx->r3 == ctx->r20) {
        // addiu       $t0, $t0, 0xC
        ctx->r8 = ADD32(ctx->r8, 0XC);
        goto L_8002DEE0;
    }
    // addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8002DE10
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002DE10;
    }
    // nop

    // beq         $v1, $zero, L_8002DE28
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002DE28;
    }
    // nop

    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DE10:
    // beq         $v1, $s3, L_8002DEE8
    if (ctx->r3 == ctx->r19) {
        // nop
    
        goto L_8002DEE8;
    }
    // nop

    // beq         $v1, $s2, L_8002DEF4
    if (ctx->r3 == ctx->r18) {
        // ori         $v0, $zero, 0x1000
        ctx->r2 = 0 | 0X1000;
        goto L_8002DEF4;
    }
    // ori         $v0, $zero, 0x1000
    ctx->r2 = 0 | 0X1000;
    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DE28:
    // lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(0X40, ctx->r29);
    // nop

    // subu        $a0, $s7, $t7
    ctx->r4 = SUB32(ctx->r23, ctx->r15);
L_8002DE34:
    // lh          $v1, 0x2($a1)
    ctx->r3 = MEM_HS(0X2, ctx->r5);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8002DE5C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002DE5C;
    }
    // nop

    // lh          $v1, 0x4($a1)
    ctx->r3 = MEM_HS(0X4, ctx->r5);
    // nop

    // slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8002DE60
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002DE60;
    }
    // nop

L_8002DE5C:
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_8002DE60:
    // lh          $v0, 0x2($a1)
    ctx->r2 = MEM_HS(0X2, ctx->r5);
    // lh          $v1, 0xA($a1)
    ctx->r3 = MEM_HS(0XA, ctx->r5);
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // div         $zero, $v0, $v1
    //
    if (ctx->r3 != 0) {
        lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3)));
        hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    }
    else {
        lo = 0; hi = 0;  // MIPS undefined,   0  -1
    }
    // bne         $v1, $zero, L_8002DE7C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002DE7C;
    }
    // nop

    // break       7
    do_break(2147671672);
L_8002DE7C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8002DE94
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002DE94;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8002DE94
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8002DE94;
    }
    // nop

    // break       6
    do_break(2147671696);
L_8002DE94:
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x8($a1)
    ctx->r2 = MEM_HS(0X8, ctx->r5);
    // nop

    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8002DEA4:
    // lh          $a0, 0x0($a1)
    ctx->r4 = MEM_HS(0X0, ctx->r5);
    // lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(0X0, ctx->r12);
    // lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(0X4, ctx->r12);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // mflo        $v0
    ctx->r2 = lo;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // slt         $v1, $v0, $v1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v1, $zero, L_8002E0DC
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // slt         $v0, $v0, $t9
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
L_8002DED0:
    // beq         $v0, $zero, L_8002E0DC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // j           L_8002E0DC
    // ori         $t1, $t1, 0x4
    ctx->r9 = ctx->r9 | 0X4;
    goto L_8002E0DC;
    // ori         $t1, $t1, 0x4
    ctx->r9 = ctx->r9 | 0X4;
L_8002DEE0:
    // j           L_8002DE34
    // addu        $a0, $t7, $t6
    ctx->r4 = ADD32(ctx->r15, ctx->r14);
    goto L_8002DE34;
    // addu        $a0, $t7, $t6
    ctx->r4 = ADD32(ctx->r15, ctx->r14);
L_8002DEE8:
    // lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(0X48, ctx->r29);
    // j           L_8002DE34
    // subu        $a0, $s7, $t6
    ctx->r4 = SUB32(ctx->r23, ctx->r14);
    goto L_8002DE34;
    // subu        $a0, $s7, $t6
    ctx->r4 = SUB32(ctx->r23, ctx->r14);
L_8002DEF4:
    // subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // j           L_8002DE34
    // subu        $a0, $v0, $t7
    ctx->r4 = SUB32(ctx->r2, ctx->r15);
    goto L_8002DE34;
    // subu        $a0, $v0, $t7
    ctx->r4 = SUB32(ctx->r2, ctx->r15);
L_8002DF00:
    // andi        $v0, $t1, 0x1
    ctx->r2 = ctx->r9 & 0X1;
    // beq         $v0, $zero, L_8002E0DC
    if (ctx->r2 == 0) {
        // addu        $a2, $t0, $zero
        ctx->r6 = ADD32(ctx->r8, 0);
        goto L_8002E0DC;
    }
    // addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // addiu       $t0, $t0, 0xA
    ctx->r8 = ADD32(ctx->r8, 0XA);
    // addu        $a0, $t2, $zero
    ctx->r4 = ADD32(ctx->r10, 0);
    // lbu         $v0, 0x2($t8)
    ctx->r2 = MEM_BU(0X2, ctx->r24);
    // lhu         $v1, 0x8($a2)
    ctx->r3 = MEM_HU(0X8, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // beq         $v1, $s4, L_8002DFE8
    if (ctx->r3 == ctx->r20) {
        // addu        $a1, $t3, $zero
        ctx->r5 = ADD32(ctx->r11, 0);
        goto L_8002DFE8;
    }
    // addu        $a1, $t3, $zero
    ctx->r5 = ADD32(ctx->r11, 0);
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8002DF4C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002DF4C;
    }
    // nop

    // beq         $v1, $zero, L_8002DF68
    if (ctx->r3 == 0) {
        // sll         $v1, $a0, 16
        ctx->r3 = S32(ctx->r4) << 16;
        goto L_8002DF68;
    }
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DF4C:
    // beq         $v1, $s3, L_8002DF64
    if (ctx->r3 == ctx->r19) {
        // addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
        goto L_8002DF64;
    }
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // beq         $v1, $s2, L_8002DF64
    if (ctx->r3 == ctx->r18) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_8002DF64;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // j           L_8002E0E0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8002E0E0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002DF64:
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
L_8002DF68:
    // lh          $v0, 0x0($a2)
    ctx->r2 = MEM_HS(0X0, ctx->r6);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0x2($a2)
    ctx->r2 = MEM_HS(0X2, ctx->r6);
    // nop

    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // lh          $v0, 0x4($a2)
    ctx->r2 = MEM_HS(0X4, ctx->r6);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A80($v1)
    ctx->r3 = MEM_W(-0X2A80, ctx->r3);
    // nop

    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $a0, -0x2A7C($at)
    MEM_W(-0X2A7C, ctx->r1) = ctx->r4;
    // lh          $v0, 0x6($a2)
    ctx->r2 = MEM_HS(0X6, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A78($at)
    MEM_W(-0X2A78, ctx->r1) = ctx->r2;
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002DFD8
    if (ctx->r2 == 0) {
        // slt         $v0, $a0, $t9
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
        goto L_8002DFD8;
    }
    // slt         $v0, $a0, $t9
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
L_8002DFD8:
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x6
        ctx->r2 = ADD32(0, -0X6);
        goto L_8002E0DC;
    }
    // addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
    // j           L_8002E0DC
    // and         $t1, $t1, $v0
    ctx->r9 = ctx->r9 & ctx->r2;
    goto L_8002E0DC;
    // and         $t1, $t1, $v0
    ctx->r9 = ctx->r9 & ctx->r2;
L_8002DFE8:
    // j           L_8002DF64
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    goto L_8002DF64;
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_8002DFF0:
    // bne         $fp, $zero, L_8002E0F0
    if (ctx->r30 != 0) {
        // addu        $v0, $t1, $zero
        ctx->r2 = ADD32(ctx->r9, 0);
        goto L_8002E0F0;
    }
    // addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2A82
    ctx->r3 = ADD32(ctx->r3, -0X2A82);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // andi        $v0, $v0, 0x5
    ctx->r2 = ctx->r2 & 0X5;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(0X0, ctx->r3);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A8C($v0)
    ctx->r2 = MEM_W(-0X2A8C, ctx->r2);
    // nop

    // addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x1($t8)
    ctx->r2 = MEM_BU(0X1, ctx->r24);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A80($at)
    MEM_W(-0X2A80, ctx->r1) = ctx->r2;
    // j           L_8002D678
    // ori         $fp, $zero, 0x1
    ctx->r30 = 0 | 0X1;
    goto L_8002D678;
    // ori         $fp, $zero, 0x1
    ctx->r30 = 0 | 0X1;
L_8002E04C:
    // addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A80($v0)
    ctx->r2 = MEM_W(-0X2A80, ctx->r2);
    // lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(0X50, ctx->r29);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v1, -0x2A74($at)
    MEM_W(-0X2A74, ctx->r1) = ctx->r3;
    // bgez        $s7, L_8002E090
    if (SIGNED(ctx->r23) >= 0) {
        // addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
        goto L_8002E090;
    }
    // addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v1, -0x2A7C($at)
    MEM_W(-0X2A7C, ctx->r1) = ctx->r3;
    // slt         $v0, $v1, $t9
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // beq         $v0, $zero, L_8002E090
    if (ctx->r2 == 0) {
        // ori         $s7, $zero, 0x1
        ctx->r23 = 0 | 0X1;
        goto L_8002E090;
    }
    // ori         $s7, $zero, 0x1
    ctx->r23 = 0 | 0X1;
    // ori         $t1, $t1, 0x4
    ctx->r9 = ctx->r9 | 0X4;
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
L_8002E090:
    // lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(0X50, ctx->r29);
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // and         $v0, $s7, $v0
    ctx->r2 = ctx->r23 & ctx->r2;
    // beq         $v0, $zero, L_8002E0DC
    if (ctx->r2 == 0) {
        // slt         $v0, $v1, $s0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
        goto L_8002E0DC;
    }
    // slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v1, -0x2A78($at)
    MEM_W(-0X2A78, ctx->r1) = ctx->r3;
    // bne         $v0, $zero, L_8002E0DC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002E0DC;
    }
    // nop

    // j           L_8002E0DC
    // ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
    goto L_8002E0DC;
    // ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
L_8002E0BC:
    // addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, -0x2A80($v1)
    ctx->r3 = MEM_W(-0X2A80, ctx->r3);
    // addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A70($at)
    MEM_W(-0X2A70, ctx->r1) = ctx->r2;
L_8002E0DC:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8002E0E0:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_8002D748
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_8002D748;
    }
    // nop

L_8002E0EC:
    // addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
L_8002E0F0:
    // lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(0X78, ctx->r29);
    // lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(0X74, ctx->r29);
    // lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(0X6C, ctx->r29);
    // lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(0X68, ctx->r29);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
