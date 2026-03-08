#include "recomp.h"
#include "disable_warnings.h"

void SpuVoice_Trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2248
    ctx->r3 = ADD32(ctx->r3, -0X2248);
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a2, $a1, $v1
    ctx->r6 = ADD32(ctx->r5, ctx->r3);
    // lw          $v1, 0x90($a2)
    ctx->r3 = MEM_W(0X90, ctx->r6);
    // nop

    // andi        $v0, $v1, 0x204
    ctx->r2 = ctx->r3 & 0X204;
    // bne         $v0, $zero, L_80052474
    if (ctx->r2 != 0) {
        // andi        $v0, $v1, 0x100
        ctx->r2 = ctx->r3 & 0X100;
        goto L_80052474;
    }
    // andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // bne         $v0, $zero, L_80052474
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
        goto L_80052474;
    }
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // sw          $v0, 0x90($a2)
    MEM_W(0X90, ctx->r6) = ctx->r2;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // lw          $v0, 0x90($v1)
    ctx->r2 = MEM_W(0X90, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
L_80052474:
    // jr          $ra
    // nop

    return;
    // nop

;}
