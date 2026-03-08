#include "recomp.h"
#include "disable_warnings.h"

void sub_8002A964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // ori         $s1, $zero, 0x6A4
    ctx->r17 = 0 | 0X6A4;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // ori         $s0, $zero, 0x31
    ctx->r16 = 0 | 0X31;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x49EC($v0)
    ctx->r2 = MEM_H(-0X49EC, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A64($v1)
    ctx->r3 = MEM_W(-0X4A64, ctx->r3);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $a0, -0x4A60($a0)
    ctx->r4 = MEM_W(-0X4A60, ctx->r4);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // lw          $a1, -0x4A5C($a1)
    ctx->r5 = MEM_W(-0X4A5C, ctx->r5);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x49EA($v0)
    ctx->r2 = MEM_H(-0X49EA, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lh          $v1, -0x49E8($v1)
    ctx->r3 = MEM_H(-0X49E8, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(0X1C, ctx->r29);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    sub_8002E4F4(rdram, ctx);
    goto after_0;
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    after_0:
    // bne         $v0, $zero, L_8002AA78
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002AA78;
    }
    // nop

L_8002A9E8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x49EA($v0)
    ctx->r2 = MEM_H(-0X49EA, ctx->r2);
    // nop

    // slti        $v0, $v0, 0xA0
    ctx->r2 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
    // bne         $v0, $zero, L_8002AA38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002AA38;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A7C($v0)
    ctx->r2 = MEM_W(-0X2A7C, ctx->r2);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x7D01
    ctx->r2 = SIGNED(ctx->r2) < 0X7D01 ? 1 : 0;
    // bne         $v0, $zero, L_8002AA38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002AA38;
    }
    // nop

    // jal         0x8002C06C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8002C06C(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $v0, -0x4A67($at)
    MEM_B(-0X4A67, ctx->r1) = ctx->r2;
L_8002AA38:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(0X1C, ctx->r29);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x49EA($v0)
    ctx->r2 = MEM_HU(-0X49EA, ctx->r2);
    // lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(0X20, ctx->r29);
    // addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v1, -0x4A64($at)
    MEM_W(-0X4A64, ctx->r1) = ctx->r3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $a0, -0x4A60($at)
    MEM_W(-0X4A60, ctx->r1) = ctx->r4;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $a1, -0x4A5C($at)
    MEM_W(-0X4A5C, ctx->r1) = ctx->r5;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x49EA($at)
    MEM_H(-0X49EA, ctx->r1) = ctx->r2;
    // j           L_8002ABE0
    // nop

    goto L_8002ABE0;
    // nop

L_8002AA78:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(-0X4A60, ctx->r2);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(0X1C, ctx->r29);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    sub_8002E4F4(rdram, ctx);
    goto after_2;
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    after_2:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bne         $v1, $zero, L_8002ABA0
    if (ctx->r3 != 0) {
        // addiu       $v0, $zero, -0x6
        ctx->r2 = ADD32(0, -0X6);
        goto L_8002ABA0;
    }
    // addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(0X1C, ctx->r29);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x49EA($at)
    MEM_H(-0X49EA, ctx->r1) = ctx->r2;
    // jal         0x8002E4F4
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    sub_8002E4F4(rdram, ctx);
    goto after_3;
    // ori         $a3, $zero, 0x320
    ctx->r7 = 0 | 0X320;
    after_3:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bne         $v1, $zero, L_8002ABA0
    if (ctx->r3 != 0) {
        // addiu       $v0, $zero, -0x6
        ctx->r2 = ADD32(0, -0X6);
        goto L_8002ABA0;
    }
    // addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
    // ori         $s1, $zero, 0x20
    ctx->r17 = 0 | 0X20;
L_8002AAE8:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x49EC
    ctx->r16 = ADD32(ctx->r16, -0X49EC);
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(0X0, ctx->r16);
    // lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(0X4, ctx->r16);
    // jal         0x80015954
    // nop

    CalculateDistance(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // slt         $v0, $s1, $a1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8002AB1C
    if (ctx->r2 != 0) {
        // subu        $a0, $a1, $s1
        ctx->r4 = SUB32(ctx->r5, ctx->r17);
        goto L_8002AB1C;
    }
    // subu        $a0, $a1, $s1
    ctx->r4 = SUB32(ctx->r5, ctx->r17);
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // j           L_8002ABD8
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    goto L_8002ABD8;
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_8002AB1C:
    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(0X0, ctx->r16);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_8002AB3C
    if (ctx->r5 != 0) {
        // nop
    
        goto L_8002AB3C;
    }
    // nop

    // break       7
    do_break(2147658552);
L_8002AB3C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_8002AB54
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002AB54;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8002AB54
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8002AB54;
    }
    // nop

    // break       6
    do_break(2147658576);
L_8002AB54:
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(0X4, ctx->r16);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_8002AB78
    if (ctx->r5 != 0) {
        // nop
    
        goto L_8002AB78;
    }
    // nop

    // break       7
    do_break(2147658612);
L_8002AB78:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_8002AB90
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002AB90;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8002AB90
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8002AB90;
    }
    // nop

    // break       6
    do_break(2147658636);
L_8002AB90:
    // mflo        $v0
    ctx->r2 = lo;
    // sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
    // j           L_8002A9E8
    // sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    goto L_8002A9E8;
    // sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
L_8002ABA0:
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // bne         $v0, $zero, L_8002ABEC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8002ABEC;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $a0, -0x2A7C($a0)
    ctx->r4 = MEM_W(-0X2A7C, ctx->r4);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v1, -0x4A60($v1)
    ctx->r3 = MEM_W(-0X4A60, ctx->r3);
    // addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8002ABEC
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8002ABEC;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // j           L_8002AAE8
    // ori         $s1, $zero, 0x38
    ctx->r17 = 0 | 0X38;
    goto L_8002AAE8;
    // ori         $s1, $zero, 0x38
    ctx->r17 = 0 | 0X38;
L_8002ABD8:
    // j           L_8002ABEC
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    goto L_8002ABEC;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_8002ABE0:
    // jal         0x80025E30
    // nop

    Player_CheckHeadroom(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002ABEC:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
