#include "recomp.h"
#include "disable_warnings.h"

void ListNavigating(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // lbu         $v0, 0x1E($a2)
    ctx->r2 = MEM_BU(0X1E, ctx->r6);
    // nop

    // beq         $v0, $zero, L_80024B1C
    if (ctx->r2 == 0) {
        // andi        $v1, $a1, 0xFF
        ctx->r3 = ctx->r5 & 0XFF;
        goto L_80024B1C;
    }
    // andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80024ABC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024ABC;
    }
    // nop

    // lbu         $v0, 0x1E($a2)
    ctx->r2 = MEM_BU(0X1E, ctx->r6);
    // nop

    // addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
L_80024ABC:
    // lbu         $a0, 0x1E($a2)
    ctx->r4 = MEM_BU(0X1E, ctx->r6);
    // sb          $a1, 0x21($a2)
    MEM_B(0X21, ctx->r6) = ctx->r5;
    // lbu         $v0, 0x21($a2)
    ctx->r2 = MEM_BU(0X21, ctx->r6);
    // lbu         $v1, 0x1F($a2)
    ctx->r3 = MEM_BU(0X1F, ctx->r6);
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80024B14
    if (ctx->r2 == 0) {
        // sltu        $v0, $a0, $v1
        ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
        goto L_80024B14;
    }
    // sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80024AF4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024AF4;
    }
    // nop

    // lbu         $v0, 0x21($a2)
    ctx->r2 = MEM_BU(0X21, ctx->r6);
    // sb          $zero, 0x20($a2)
    MEM_B(0X20, ctx->r6) = 0;
    // j           L_80024B1C
    // sb          $v0, 0x22($a2)
    MEM_B(0X22, ctx->r6) = ctx->r2;
    goto L_80024B1C;
    // sb          $v0, 0x22($a2)
    MEM_B(0X22, ctx->r6) = ctx->r2;
L_80024AF4:
    // lbu         $v0, 0x1E($a2)
    ctx->r2 = MEM_BU(0X1E, ctx->r6);
    // lbu         $a0, 0x1F($a2)
    ctx->r4 = MEM_BU(0X1F, ctx->r6);
    // lbu         $v1, 0x21($a2)
    ctx->r3 = MEM_BU(0X21, ctx->r6);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sb          $v0, 0x20($a2)
    MEM_B(0X20, ctx->r6) = ctx->r2;
    // j           L_80024B1C
    // sb          $v1, 0x22($a2)
    MEM_B(0X22, ctx->r6) = ctx->r3;
    goto L_80024B1C;
    // sb          $v1, 0x22($a2)
    MEM_B(0X22, ctx->r6) = ctx->r3;
L_80024B14:
    // sb          $a1, 0x20($a2)
    MEM_B(0X20, ctx->r6) = ctx->r5;
    // sb          $zero, 0x22($a2)
    MEM_B(0X22, ctx->r6) = 0;
L_80024B1C:
    // jr          $ra
    // nop

    return;
    // nop

;}
