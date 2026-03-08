#include "recomp.h"
#include "disable_warnings.h"

void sub_80039348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(0X4, ctx->r4);
    // nop

    // addiu       $v1, $v0, -0x2
    ctx->r3 = ADD32(ctx->r2, -0X2);
    // sltiu       $v0, $v1, 0x15
    ctx->r2 = ctx->r3 < 0X15 ? 1 : 0;
    // beq         $v0, $zero, L_800393C4
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_800393C4;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x19C0
    ctx->r1 = ADD32(ctx->r1, 0X19C0);
    // addu        $at, $at, $v0
    gpr jr_addend_80039374;
    jr_addend_80039374 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80039374 >> 2) {
        case 0: goto L_8003937C; break;
        case 1: goto L_8003937C; break;
        case 2: goto L_8003937C; break;
        case 3: goto L_8003938C; break;
        case 4: goto L_800393C4; break;
        case 5: goto L_800393C4; break;
        case 6: goto L_8003938C; break;
        case 7: goto L_800393C4; break;
        case 8: goto L_800393C4; break;
        case 9: goto L_800393C4; break;
        case 10: goto L_800393C4; break;
        case 11: goto L_800393C4; break;
        case 12: goto L_800393C4; break;
        case 13: goto L_800393BC; break;
        case 14: goto L_800393C4; break;
        case 15: goto L_800393BC; break;
        case 16: goto L_800393C4; break;
        case 17: goto L_800393C4; break;
        case 18: goto L_800393C4; break;
        case 19: goto L_800393C4; break;
        case 20: goto L_8003938C; break;
        default: switch_error(__func__, 0x80039374, 0x800119C0);
    }
    // nop

L_8003937C:
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // bne         $v0, $zero, L_800393C8
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800393C8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003938C:
    // lbu         $v1, 0x38($a0)
    ctx->r3 = MEM_BU(0X38, ctx->r4);
    // nop

    // sltiu       $v0, $v1, 0xFE
    ctx->r2 = ctx->r3 < 0XFE ? 1 : 0;
    // beq         $v0, $zero, L_800393C8
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_800393C8;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // bne         $v1, $a1, L_800393B4
    if (ctx->r3 != ctx->r5) {
        // ori         $v0, $zero, 0xFF
        ctx->r2 = 0 | 0XFF;
        goto L_800393B4;
    }
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // sb          $v0, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r2;
    // j           L_800393C8
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_800393C8;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_800393B4:
    // j           L_800393C8
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
    goto L_800393C8;
    // ori         $v0, $zero, 0x3
    ctx->r2 = 0 | 0X3;
L_800393BC:
    // j           L_800393C8
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    goto L_800393C8;
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
L_800393C4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800393C8:
    // jr          $ra
    // nop

    return;
    // nop

;}
