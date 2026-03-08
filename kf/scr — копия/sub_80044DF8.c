#include "recomp.h"
#include "disable_warnings.h"

void sub_80044DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lw          $a2, 0x1184($a2)
    ctx->r6 = MEM_W(0X1184, ctx->r6);
    // nop

    // lbu         $v0, 0xD($a2)
    ctx->r2 = MEM_BU(0XD, ctx->r6);
    // nop

    // beq         $v0, $zero, L_80044E5C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80044E5C;
    }
    // nop

    // lh          $v1, 0x1A8($gp)
    ctx->r3 = MEM_H(0X1A8, ctx->r28);
    // lw          $v0, 0x14($a2)
    ctx->r2 = MEM_W(0X14, ctx->r6);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lh          $v1, 0x646A($v1)
    ctx->r3 = MEM_H(0X646A, ctx->r3);
    // lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(0X18, ctx->r6);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lh          $v1, 0x646C($v1)
    ctx->r3 = MEM_H(0X646C, ctx->r3);
    // lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(0X1C, ctx->r6);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // j           L_80044E8C
    // sw          $v0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r2;
    goto L_80044E8C;
    // sw          $v0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r2;
L_80044E5C:
    // lh          $v1, 0x34($a2)
    ctx->r3 = MEM_H(0X34, ctx->r6);
    // lw          $v0, 0x14($a2)
    ctx->r2 = MEM_W(0X14, ctx->r6);
    // lh          $a0, 0x36($a2)
    ctx->r4 = MEM_H(0X36, ctx->r6);
    // lh          $a1, 0x38($a2)
    ctx->r5 = MEM_H(0X38, ctx->r6);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(0X18, ctx->r6);
    // lw          $v1, 0x1C($a2)
    ctx->r3 = MEM_W(0X1C, ctx->r6);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // sw          $v1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r3;
L_80044E8C:
    // lh          $v1, 0x34($a2)
    ctx->r3 = MEM_H(0X34, ctx->r6);
    // lw          $v0, 0x14($a2)
    ctx->r2 = MEM_W(0X14, ctx->r6);
    // lh          $a0, 0x36($a2)
    ctx->r4 = MEM_H(0X36, ctx->r6);
    // lh          $a1, 0x38($a2)
    ctx->r5 = MEM_H(0X38, ctx->r6);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(0X18, ctx->r6);
    // lw          $v1, 0x1C($a2)
    ctx->r3 = MEM_W(0X1C, ctx->r6);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // jr          $ra
    // sw          $v1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r3;
    return;
    // sw          $v1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r3;
;}
