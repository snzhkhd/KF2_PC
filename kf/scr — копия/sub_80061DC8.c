#include "recomp.h"
#include "disable_warnings.h"

void sub_80061DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // addiu       $s1, $s1, 0x5044
    ctx->r17 = ADD32(ctx->r17, 0X5044);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80061E24
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80061E24;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x60D0($v0)
    ctx->r2 = MEM_W(0X60D0, ctx->r2);
    // nop

    // lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(0X0, ctx->r2);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x35C8
    ctx->r4 = ADD32(ctx->r4, 0X35C8);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x80062B40
    // nop

    KF_ReturnFromException(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80061E24:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x60D0($a0)
    ctx->r4 = MEM_W(0X60D0, ctx->r4);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, 0x5046($at)
    MEM_H(0X5046, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lhu         $v0, 0x5074($v0)
    ctx->r2 = MEM_HU(0X5074, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x60D4($v1)
    ctx->r3 = MEM_W(0X60D4, ctx->r3);
    // lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(0X0, ctx->r4);
    // lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(0X0, ctx->r3);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // and         $s0, $v1, $v0
    ctx->r16 = ctx->r3 & ctx->r2;
    // beq         $s0, $zero, L_80061EF4
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80061EF4;
    }
    // nop

    // ori         $s3, $zero, 0x1
    ctx->r19 = 0 | 0X1;
    // addiu       $s4, $s1, 0x4
    ctx->r20 = ADD32(ctx->r17, 0X4);
L_80061E68:
    // beq         $s0, $zero, L_80061EC4
    if (ctx->r16 == 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_80061EC4;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
L_80061E74:
    // slti        $v0, $s1, 0xB
    ctx->r2 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
    // beq         $v0, $zero, L_80061EC4
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x1
        ctx->r2 = ctx->r16 & 0X1;
        goto L_80061EC4;
    }
    // andi        $v0, $s0, 0x1
    ctx->r2 = ctx->r16 & 0X1;
    // beq         $v0, $zero, L_80061EB0
    if (ctx->r2 == 0) {
        // sllv        $v0, $s3, $s1
        ctx->r2 = S32(ctx->r19) << (ctx->r17 & 31);
        goto L_80061EB0;
    }
    // sllv        $v0, $s3, $s1
    ctx->r2 = S32(ctx->r19) << (ctx->r17 & 31);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x60D0($v1)
    ctx->r3 = MEM_W(0X60D0, ctx->r3);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // beq         $v0, $zero, L_80061EB0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061EB0;
    }
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_80061EB0:
    // addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // srl         $s0, $s0, 1
    ctx->r16 = S32(U32(ctx->r16) >> 1);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // bne         $v0, $zero, L_80061E74
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80061E74;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80061EC4:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x60D0($a0)
    ctx->r4 = MEM_W(0X60D0, ctx->r4);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lhu         $v0, 0x5074($v0)
    ctx->r2 = MEM_HU(0X5074, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x60D4($v1)
    ctx->r3 = MEM_W(0X60D4, ctx->r3);
    // lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(0X0, ctx->r4);
    // lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(0X0, ctx->r3);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // and         $s0, $v1, $v0
    ctx->r16 = ctx->r3 & ctx->r2;
    // bne         $s0, $zero, L_80061E68
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80061E68;
    }
    // nop

L_80061EF4:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x60D0($a1)
    ctx->r5 = MEM_W(0X60D0, ctx->r5);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // lw          $a2, 0x60D4($a2)
    ctx->r6 = MEM_W(0X60D4, ctx->r6);
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(0X0, ctx->r6);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80061F74
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061F74;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x60DC($v0)
    ctx->r2 = MEM_W(0X60DC, ctx->r2);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v1, 0x60DC($at)
    MEM_W(0X60DC, ctx->r1) = ctx->r3;
    // bne         $v0, $zero, L_80061F7C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80061F7C;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x35E4
    ctx->r4 = ADD32(ctx->r4, 0X35E4);
    // lhu         $a1, 0x0($a1)
    ctx->r5 = MEM_HU(0X0, ctx->r5);
    // lhu         $a2, 0x0($a2)
    ctx->r6 = MEM_HU(0X0, ctx->r6);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x60D0($v0)
    ctx->r2 = MEM_W(0X60D0, ctx->r2);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x60DC($at)
    MEM_W(0X60DC, ctx->r1) = 0;
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // j           L_80061F7C
    // nop

    goto L_80061F7C;
    // nop

L_80061F74:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x60DC($at)
    MEM_W(0X60DC, ctx->r1) = 0;
L_80061F7C:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $zero, 0x5046($at)
    MEM_H(0X5046, ctx->r1) = 0;
    // jal         0x80062B40
    // nop

    KF_ReturnFromException(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
