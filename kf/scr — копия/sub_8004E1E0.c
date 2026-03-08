#include "recomp.h"
#include "disable_warnings.h"

void sub_8004E1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x8C4($v1)
    ctx->r3 = MEM_W(-0X8C4, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8B8($v0)
    ctx->r2 = MEM_W(-0X8B8, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // beq         $v0, $zero, L_8004E264
    if (ctx->r2 == 0) {
        // ori         $v1, $zero, 0x7
        ctx->r3 = 0 | 0X7;
        goto L_8004E264;
    }
    // ori         $v1, $zero, 0x7
    ctx->r3 = 0 | 0X7;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
L_8004E214:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8B8($v0)
    ctx->r2 = MEM_W(-0X8B8, ctx->r2);
    // nop

    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8BC($v0)
    ctx->r2 = MEM_W(-0X8BC, ctx->r2);
    // nop

    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8B8($v0)
    ctx->r2 = MEM_W(-0X8B8, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v0, $zero, L_8004E214
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004E214;
    }
    // nop

L_8004E264:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0x8AA($at)
    MEM_B(-0X8AA, ctx->r1) = 0;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lbu         $v1, -0x8AA($v1)
    ctx->r3 = MEM_BU(-0X8AA, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, -0x8AB
    ctx->r2 = ADD32(ctx->r2, -0X8AB);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $zero, -0xB68($at)
    MEM_B(-0XB68, ctx->r1) = 0;
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x8C4($v1)
    ctx->r3 = MEM_W(-0X8C4, ctx->r3);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v0, -0x8AC($at)
    MEM_B(-0X8AC, ctx->r1) = ctx->r2;
    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8B8($v0)
    ctx->r2 = MEM_W(-0X8B8, ctx->r2);
    // nop

    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x8B4($v1)
    ctx->r3 = MEM_W(-0X8B4, ctx->r3);
    // ori         $v0, $zero, 0x1325
    ctx->r2 = 0 | 0X1325;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // jr          $ra
    // nop

    return;
    // nop

;}
