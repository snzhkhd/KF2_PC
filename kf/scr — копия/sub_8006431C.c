#include "recomp.h"
#include "disable_warnings.h"

void sub_8006431C(uint8_t* rdram, recomp_context* ctx) {
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

    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_8006434C
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x2
        ctx->r2 = 0 | 0X2;
        goto L_8006434C;
    }
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // beq         $v1, $v0, L_80064374
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80064374;
    }
    // nop

    // j           L_800643CC
    // nop

    goto L_800643CC;
    // nop

L_8006434C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x61A3($v0)
    ctx->r2 = MEM_BU(0X61A3, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800643CC
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x400
        ctx->r2 = 0 | 0X400;
        goto L_800643CC;
    }
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    // lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(0X4, ctx->r4);
    // lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(0X0, ctx->r4);
L_80064368:
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // j           L_800643D0
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    goto L_800643D0;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
L_80064374:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x61A3($v0)
    ctx->r2 = MEM_BU(0X61A3, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800643AC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800643AC;
    }
    // nop

    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(0X0, ctx->r4);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // j           L_80064368
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
    goto L_80064368;
    // ori         $v0, $zero, 0x400
    ctx->r2 = 0 | 0X400;
L_800643AC:
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_800643D0
    // sra         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) >> 1;
    goto L_800643D0;
    // sra         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) >> 1;
L_800643CC:
    // lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(0X0, ctx->r4);
L_800643D0:
    // jr          $ra
    // nop

    return;
    // nop

;}
