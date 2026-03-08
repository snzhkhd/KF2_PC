#include "recomp.h"
#include "disable_warnings.h"

void sub_80059798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7) << 1;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, -0x7CC($v1)
    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
    // sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) << 1;
    // addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(0X0, ctx->r7);
    // lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(0X0, ctx->r6);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // beq         $a0, $zero, L_80059800
    if (ctx->r4 == 0) {
        // or          $t0, $v1, $v0
        ctx->r8 = ctx->r3 | ctx->r2;
        goto L_80059800;
    }
    // or          $t0, $v1, $v0
    ctx->r8 = ctx->r3 | ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $a0, $v0, L_8005983C
    if (ctx->r4 != ctx->r2) {
        // lui         $v1, 0xFF
        ctx->r3 = S32(0XFF << 16);
        goto L_8005983C;
    }
    // lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v1, $a1, $v1
    ctx->r3 = ctx->r5 & ctx->r3;
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // or          $t0, $t0, $v1
    ctx->r8 = ctx->r8 | ctx->r3;
    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // srl         $v0, $a1, 16
    ctx->r2 = S32(U32(ctx->r5) >> 16);
    // lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(0X0, ctx->r7);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // j           L_80059838
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    goto L_80059838;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80059800:
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $t0, $t0, $v0
    ctx->r8 = ctx->r8 & ctx->r2;
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // nor         $v1, $zero, $a1
    ctx->r3 = ~(0 | ctx->r5);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // srl         $v0, $a1, 16
    ctx->r2 = S32(U32(ctx->r5) >> 16);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(0X0, ctx->r7);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
L_80059838:
    // sh          $v1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r3;
L_8005983C:
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // jr          $ra
    // and         $v0, $t0, $v0
    ctx->r2 = ctx->r8 & ctx->r2;
    return;
    // and         $v0, $t0, $v0
    ctx->r2 = ctx->r8 & ctx->r2;
;}
