#include "recomp.h"
#include "disable_warnings.h"

void sub_8005599C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x192E($v0)
    ctx->r2 = MEM_BU(-0X192E, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1920($v1)
    ctx->r3 = MEM_BU(-0X1920, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x191F($a0)
    ctx->r4 = MEM_BU(-0X191F, ctx->r4);
    // addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // bgez        $a0, L_800559C4
    if (SIGNED(ctx->r4) >= 0) {
        // subu        $v1, $v0, $v1
        ctx->r3 = SUB32(ctx->r2, ctx->r3);
        goto L_800559C4;
    }
    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
L_800559C4:
    // ori         $v0, $zero, 0xC
    ctx->r2 = 0 | 0XC;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_800559D8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800559D8;
    }
    // nop

    // break       7
    do_break(2147834324);
L_800559D8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_800559F0
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800559F0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_800559F0
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_800559F0;
    }
    // nop

    // break       6
    do_break(2147834348);
L_800559F0:
    // mflo        $a2
    ctx->r6 = lo;
    // mfhi        $a1
    ctx->r5 = hi;
    // srl         $v1, $a0, 3
    ctx->r3 = S32(U32(ctx->r4) >> 3);
    // sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80055A0C
    if (ctx->r2 != 0) {
        // sll         $v0, $a1, 4
        ctx->r2 = S32(ctx->r5) << 4;
        goto L_80055A0C;
    }
    // sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5) << 4;
    // ori         $v1, $zero, 0xF
    ctx->r3 = 0 | 0XF;
L_80055A0C:
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x48
    ctx->r1 = ADD32(ctx->r1, 0X48);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // addiu       $v0, $a2, -0x5
    ctx->r2 = ADD32(ctx->r6, -0X5);
    // blez        $v0, L_80055A3C
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80055A3C;
    }
    // nop

    // j           L_80055A50
    // sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3) << (ctx->r2 & 31);
    goto L_80055A50;
    // sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3) << (ctx->r2 & 31);
L_80055A3C:
    // bgez        $v0, L_80055A50
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80055A50;
    }
    // nop

    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // srav        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3) >> (ctx->r2 & 31);
L_80055A50:
    // jr          $ra
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
;}
