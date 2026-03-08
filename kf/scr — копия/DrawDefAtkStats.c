#include "recomp.h"
#include "disable_warnings.h"

void DrawDefAtkStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $zero, -0x63
    ctx->r16 = ADD32(0, -0X63);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, -0x63
    ctx->r17 = ADD32(0, -0X63);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_8001BC2C:
    // beq         $s0, $s1, L_8001BC44
    if (ctx->r16 == ctx->r17) {
        // nop
    
        goto L_8001BC44;
    }
    // nop

    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8001BC88
    // nop

    goto L_8001BC88;
    // nop

L_8001BC44:
    // jal         0x80024E70
    // nop

    WaitForInputStable(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80024E3C
    // nop

    ReadPadWithFlag(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // beq         $v0, $zero, L_8001BC68
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001BC68;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_3;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_3:
    // addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_8001BC68:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x800213E8
    // nop

    sub_800213E8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_8001BC2C
    // nop

    goto L_8001BC2C;
    // nop

L_8001BC88:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
