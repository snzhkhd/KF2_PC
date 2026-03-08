#include "recomp.h"
#include "disable_warnings.h"

void sub_8004AE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // addiu       $a1, $a1, 0x529C
    ctx->r5 = ADD32(ctx->r5, 0X529C);
    // lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(0X0, ctx->r5);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8004AEBC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004AEBC;
    }
    // nop

    // ori         $a2, $zero, 0xFF
    ctx->r6 = 0 | 0XFF;
L_8004AE70:
    // lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(0X0, ctx->r5);
    // nop

    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8004AE9C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004AE9C;
    }
    // nop

    // beq         $v1, $zero, L_8004AE9C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004AE9C;
    }
    // nop

    // lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(0X8, ctx->r5);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
L_8004AE9C:
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // bne         $v0, $a2, L_8004AE70
    if (ctx->r2 != ctx->r6) {
        // nop
    
        goto L_8004AE70;
    }
    // nop

L_8004AEBC:
    // jr          $ra
    // nop

    return;
    // nop

;}
