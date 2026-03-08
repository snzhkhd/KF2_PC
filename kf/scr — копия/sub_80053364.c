#include "recomp.h"
#include "disable_warnings.h"

void sub_80053364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // beq         $s0, $zero, L_8005338C
    if (ctx->r16 == 0) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_8005338C;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $s0, $v0, L_800533AC
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_800533AC;
    }
    // nop

    // j           L_80053418
    // nop

    goto L_80053418;
    // nop

L_8005338C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $v1, 0x1AA($v0)
    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x76C($at)
    MEM_W(-0X76C, ctx->r1) = 0;
    // j           L_80053414
    // andi        $v1, $v1, 0xFF7F
    ctx->r3 = ctx->r3 & 0XFF7F;
    goto L_80053414;
    // andi        $v1, $v1, 0xFF7F
    ctx->r3 = ctx->r3 & 0XFF7F;
L_800533AC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x768($v0)
    ctx->r2 = MEM_W(-0X768, ctx->r2);
    // nop

    // beq         $v0, $s0, L_800533F8
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_800533F8;
    }
    // nop

    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, -0x750($a0)
    ctx->r4 = MEM_W(-0X750, ctx->r4);
    // jal         0x8005314C
    // nop

    sub_8005314C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_800533F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800533F8;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $v1, 0x1AA($v0)
    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, -0x76C($at)
    MEM_W(-0X76C, ctx->r1) = 0;
    // j           L_80053414
    // andi        $v1, $v1, 0xFF7F
    ctx->r3 = ctx->r3 & 0XFF7F;
    goto L_80053414;
    // andi        $v1, $v1, 0xFF7F
    ctx->r3 = ctx->r3 & 0XFF7F;
L_800533F8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x7CC($v0)
    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
    // nop

    // lhu         $v1, 0x1AA($v0)
    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s0, -0x76C($at)
    MEM_W(-0X76C, ctx->r1) = ctx->r16;
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
L_80053414:
    // sh          $v1, 0x1AA($v0)
    MEM_H(0X1AA, ctx->r2) = ctx->r3;
L_80053418:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x76C($v0)
    ctx->r2 = MEM_W(-0X76C, ctx->r2);
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
