#include "recomp.h"
#include "disable_warnings.h"

void ResolveCurrentMetaTile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // ori         $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 | 0X7FFF;
    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_8002D590
    if (ctx->r2 != 0) {
        // sltu        $v0, $v1, $a2
        ctx->r2 = ctx->r3 < ctx->r6 ? 1 : 0;
        goto L_8002D590;
    }
    // sltu        $v0, $v1, $a2
    ctx->r2 = ctx->r3 < ctx->r6 ? 1 : 0;
    // bne         $v0, $zero, L_8002D590
    if (ctx->r2 != 0) {
        // sra         $v0, $a2, 11
        ctx->r2 = S32(ctx->r6) >> 11;
        goto L_8002D590;
    }
    // sra         $v0, $a2, 11
    ctx->r2 = S32(ctx->r6) >> 11;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x428C
    ctx->r4 = ADD32(ctx->r4, -0X428C);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // sra         $v0, $a1, 7
    ctx->r2 = S32(ctx->r5) >> 7;
    // lbu         $a3, 0x1($a0)
    ctx->r7 = MEM_BU(0X1, ctx->r4);
    // lbu         $a2, 0x6($a0)
    ctx->r6 = MEM_BU(0X6, ctx->r4);
    // negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    // sltu        $v0, $a2, $a3
    ctx->r2 = ctx->r6 < ctx->r7 ? 1 : 0;
    // beq         $v0, $zero, L_8002D56C
    if (ctx->r2 == 0) {
        // andi        $v0, $a1, 0xFFFF
        ctx->r2 = ctx->r5 & 0XFFFF;
        goto L_8002D56C;
    }
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(0X1, ctx->r4);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8002D52C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D52C;
    }
    // nop

    // bne         $a2, $zero, L_8002D544
    if (ctx->r6 != 0) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_8002D544;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
L_8002D52C:
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $zero, -0x2A82($at)
    MEM_H(-0X2A82, ctx->r1) = 0;
    // lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(0X1, ctx->r4);
    // j           L_8002D558
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    goto L_8002D558;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8002D540:
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
L_8002D544:
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v0, -0x2A82($at)
    MEM_H(-0X2A82, ctx->r1) = ctx->r2;
    // lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(0X6, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8002D558:
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, -0x2A80($at)
    MEM_W(-0X2A80, ctx->r1) = ctx->r2;
    // j           L_8002D5A8
    // nop

    goto L_8002D5A8;
    // nop

L_8002D56C:
    // lbu         $v1, 0x6($a0)
    ctx->r3 = MEM_BU(0X6, ctx->r4);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8002D540
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002D540;
    }
    // nop

    // bne         $a3, $zero, L_8002D52C
    if (ctx->r7 != 0) {
        // ori         $v0, $zero, 0x5
        ctx->r2 = 0 | 0X5;
        goto L_8002D52C;
    }
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // j           L_8002D544
    // nop

    goto L_8002D544;
    // nop

L_8002D590:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x1DD4
    ctx->r4 = ADD32(ctx->r4, -0X1DD4);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $zero, -0x2A82($at)
    MEM_H(-0X2A82, ctx->r1) = 0;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $zero, -0x2A80($at)
    MEM_W(-0X2A80, ctx->r1) = 0;
L_8002D5A8:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A80($v0)
    ctx->r2 = MEM_W(-0X2A80, ctx->r2);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $a0, -0x2A8C($at)
    MEM_W(-0X2A8C, ctx->r1) = ctx->r4;
    // jr          $ra
    // nop

    return;
    // nop

;}
