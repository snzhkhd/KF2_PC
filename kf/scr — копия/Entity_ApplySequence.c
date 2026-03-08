#include "recomp.h"
#include "disable_warnings.h"

void Entity_ApplySequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0xE($a0)
    ctx->r2 = MEM_BU(0XE, ctx->r4);
    // beq         $a1, $zero, L_8003BB80
    if (ctx->r5 == 0) {
        // sb          $v0, 0x10($a0)
        MEM_B(0X10, ctx->r4) = ctx->r2;
        goto L_8003BB80;
    }
    // sb          $v0, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r2;
    // sw          $a1, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r5;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // sb          $zero, 0xF($a0)
    MEM_B(0XF, ctx->r4) = 0;
    // j           L_8003BB90
    // sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
    goto L_8003BB90;
    // sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
L_8003BB80:
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
    // sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
L_8003BB90:
    // jr          $ra
    // nop

    return;
    // nop

;}
