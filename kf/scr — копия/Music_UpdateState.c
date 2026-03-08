#include "recomp.h"
#include "disable_warnings.h"

void Music_UpdateState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // addiu       $a2, $a2, 0x6478
    ctx->r6 = ADD32(ctx->r6, 0X6478);
    // lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // addiu       $a1, $a1, 0x140
    ctx->r5 = ADD32(ctx->r5, 0X140);
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(0X8, ctx->r6);
    // nop

    // sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // addiu       $a2, $a2, 0x6484
    ctx->r6 = ADD32(ctx->r6, 0X6484);
    // lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // addiu       $a1, $a1, 0x14C
    ctx->r5 = ADD32(ctx->r5, 0X14C);
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(0X8, ctx->r6);
    // nop

    // sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x178($at)
    MEM_B(0X178, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x177($at)
    MEM_B(0X177, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x1D4($at)
    MEM_B(0X1D4, ctx->r1) = ctx->r2;
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sb          $v0, 0x1D3($at)
    MEM_B(0X1D3, ctx->r1) = ctx->r2;
    // beq         $a0, $a1, L_800248D0
    if (ctx->r4 == ctx->r5) {
        // nop
    
        goto L_800248D0;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A74($v1)
    ctx->r3 = MEM_BU(-0X4A74, ctx->r3);
    // lbu         $v0, 0xF4($gp)
    ctx->r2 = MEM_BU(0XF4, ctx->r28);
    // nop

    // beq         $v1, $v0, L_800248F0
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800248F0;
    }
    // nop

    // bne         $v1, $zero, L_800248E0
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800248E0;
    }
    // nop

L_800248D0:
    // jal         0x80014058
    // nop

    Music_Stop(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8002491C
    // nop

    goto L_8002491C;
    // nop

L_800248E0:
    // jal         0x80013FC0
    // nop

    Music_PlaySEQ(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_8002491C
    // nop

    goto L_8002491C;
    // nop

L_800248F0:
    // bne         $v1, $a1, L_8002491C
    if (ctx->r3 != ctx->r5) {
        // nop
    
        goto L_8002491C;
    }
    // nop

    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x59D0($v0)
    ctx->r2 = MEM_W(-0X59D0, ctx->r2);
    // nop

    // bne         $v0, $v1, L_8002491C
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8002491C;
    }
    // nop

    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x8005247C
    // nop

    Music_PlayTrack(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8002491C:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
