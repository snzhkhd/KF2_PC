#include "recomp.h"
#include "disable_warnings.h"

void PackMaterialFlags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61A0
    ctx->r2 = ADD32(ctx->r2, 0X61A0);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80064098
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80064098;
    }
    // nop

    // beq         $a1, $zero, L_80064088
    if (ctx->r5 == 0) {
        // lui         $v1, 0xE100
        ctx->r3 = S32(0XE100 << 16);
        goto L_80064088;
    }
    // lui         $v1, 0xE100
    ctx->r3 = S32(0XE100 << 16);
    // ori         $v1, $v1, 0x800
    ctx->r3 = ctx->r3 | 0X800;
L_80064088:
    // beq         $a0, $zero, L_800640B0
    if (ctx->r4 == 0) {
        // andi        $v0, $a2, 0x27FF
        ctx->r2 = ctx->r6 & 0X27FF;
        goto L_800640B0;
    }
    // andi        $v0, $a2, 0x27FF
    ctx->r2 = ctx->r6 & 0X27FF;
    // j           L_800640B0
    // ori         $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 | 0X1000;
    goto L_800640B0;
    // ori         $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 | 0X1000;
L_80064098:
    // beq         $a1, $zero, L_800640A4
    if (ctx->r5 == 0) {
        // lui         $v1, 0xE100
        ctx->r3 = S32(0XE100 << 16);
        goto L_800640A4;
    }
    // lui         $v1, 0xE100
    ctx->r3 = S32(0XE100 << 16);
    // ori         $v1, $v1, 0x200
    ctx->r3 = ctx->r3 | 0X200;
L_800640A4:
    // beq         $a0, $zero, L_800640B0
    if (ctx->r4 == 0) {
        // andi        $v0, $a2, 0x9FF
        ctx->r2 = ctx->r6 & 0X9FF;
        goto L_800640B0;
    }
    // andi        $v0, $a2, 0x9FF
    ctx->r2 = ctx->r6 & 0X9FF;
    // ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_800640B0:
    // jr          $ra
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    return;
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
;}
