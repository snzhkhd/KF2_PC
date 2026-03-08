#include "recomp.h"
#include "disable_warnings.h"

void sub_80065748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x1000
    ctx->r3 = S32(0X1000 << 16);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6274($v0)
    ctx->r2 = MEM_W(0X6274, ctx->r2);
    // ori         $v1, $v1, 0x7
    ctx->r3 = ctx->r3 | 0X7;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x6270($a1)
    ctx->r5 = MEM_W(0X6270, ctx->r5);
    // lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // ori         $v1, $zero, 0x2
    ctx->r3 = 0 | 0X2;
    // beq         $v0, $v1, L_800657F4
    if (ctx->r2 == ctx->r3) {
        // lui         $v1, 0xE100
        ctx->r3 = S32(0XE100 << 16);
        goto L_800657F4;
    }
    // lui         $v1, 0xE100
    ctx->r3 = S32(0XE100 << 16);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6274($v0)
    ctx->r2 = MEM_W(0X6274, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // ori         $v1, $v1, 0x1000
    ctx->r3 = ctx->r3 | 0X1000;
    // andi        $v0, $v0, 0x3FFF
    ctx->r2 = ctx->r2 & 0X3FFF;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6270($v0)
    ctx->r2 = MEM_W(0X6270, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6274($v1)
    ctx->r3 = MEM_W(0X6274, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // bne         $v0, $zero, L_800657D4
    if (ctx->r2 != 0) {
        // andi        $v0, $a0, 0x8
        ctx->r2 = ctx->r4 & 0X8;
        goto L_800657D4;
    }
    // andi        $v0, $a0, 0x8
    ctx->r2 = ctx->r4 & 0X8;
    // j           L_80065820
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80065820;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800657D4:
    // bne         $v0, $zero, L_800657E4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x2000
        ctx->r2 = S32(0X2000 << 16);
        goto L_800657E4;
    }
    // lui         $v0, 0x2000
    ctx->r2 = S32(0X2000 << 16);
    // j           L_80065820
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_80065820;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_800657E4:
    // ori         $v0, $v0, 0x504
    ctx->r2 = ctx->r2 | 0X504;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // j           L_80065820
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    goto L_80065820;
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
L_800657F4:
    // andi        $v0, $a0, 0x8
    ctx->r2 = ctx->r4 & 0X8;
    // beq         $v0, $zero, L_8006581C
    if (ctx->r2 == 0) {
        // lui         $a0, 0x900
        ctx->r4 = S32(0X900 << 16);
        goto L_8006581C;
    }
    // lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6274($v1)
    ctx->r3 = MEM_W(0X6274, ctx->r3);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // j           L_80065820
    // nop

    goto L_80065820;
    // nop

L_8006581C:
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
L_80065820:
    // jr          $ra
    // nop

    return;
    // nop

;}
