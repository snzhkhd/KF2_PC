#include "recomp.h"
#include "disable_warnings.h"

void ProcessTIMContainer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // jal         0x80065874
    // nop

    KF_OpenTIM(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_800373EC:
    // jal         0x80065884
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    KF_ReadTIM(rdram, ctx);
    goto after_1;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // beq         $v0, $zero, L_8003743C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003743C;
    }
    // nop

    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // nop

    // beq         $a1, $zero, L_80037418
    if (ctx->r5 == 0) {
        // nop
    
        goto L_80037418;
    }
    // nop

    // lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(0X14, ctx->r29);
    // jal         0x800632F8
    // nop

    LoadImageWithCallback(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_80037418:
    // lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(0X20, ctx->r29);
    // nop

    // beq         $a1, $zero, L_800373EC
    if (ctx->r5 == 0) {
        // nop
    
        goto L_800373EC;
    }
    // nop

    // lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(0X1C, ctx->r29);
    // jal         0x800632F8
    // nop

    LoadImageWithCallback(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_800373EC
    // nop

    goto L_800373EC;
    // nop

L_8003743C:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
