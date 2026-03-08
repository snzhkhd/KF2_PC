#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lhu         $v1, 0x14($s0)
    ctx->r3 = MEM_HU(0X14, ctx->r16);
    // nop

    // beq         $v1, $zero, L_8002C2F0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8002C2F0;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4AC8($v0)
    ctx->r2 = MEM_W(-0X4AC8, ctx->r2);
    // nop

    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_8002C2D8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002C2D8;
    }
    // nop

    // break       7
    do_break(2147664596);
L_8002C2D8:
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // bne         $v1, $zero, L_8002C2F0
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002C2F0;
    }
    // nop

    // jal         0x8002C1E0
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    sub_8002C1E0(rdram, ctx);
    goto after_0;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_0:
L_8002C2F0:
    // lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(0X16, ctx->r16);
    // nop

    // beq         $a0, $zero, L_8002C334
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8002C334;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4AC8($v0)
    ctx->r2 = MEM_W(-0X4AC8, ctx->r2);
    // nop

    // divu        $zero, $v0, $a0
    lo = S32(U32(ctx->r2) / U32(ctx->r4)); hi = S32(U32(ctx->r2) % U32(ctx->r4));
    // bne         $a0, $zero, L_8002C31C
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8002C31C;
    }
    // nop

    // break       7
    do_break(2147664664);
L_8002C31C:
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // bne         $v1, $zero, L_8002C334
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002C334;
    }
    // nop

    // jal         0x8002C1E0
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    sub_8002C1E0(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
L_8002C334:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
