#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

#define ADDR_KFCullDistanceXNeg 0x80194F54
#define ADDR_KFCullDistanceZNeg 0x80194F58

void KF_RenderTilemap(uint8_t* rdram, recomp_context* ctx) 
{

    // int drawCount = 0;
    //MATRIX* world = (MATRIX*)GET_PTR(0x80194ECC);
    //world->t[0] = world->t[1] = world->t[2] = 0;

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8002FFA4
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    KF_TMDCurrentSet(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0x4F54
    ctx->r2 = ADD32(ctx->r2, 0X4F54);
    // addiu       $s2, $v0, 0xC
    ctx->r18 = ADD32(ctx->r2, 0XC);
    // ori         $s4, $zero, 0x18
    ctx->r20 = 0 | 0X18;
    // lw          $s5, 0x0($v0)
    ctx->r21 = MEM_W(0X0, ctx->r2);
    // lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // lw          $s3, 0x4F58($s3)
    ctx->r19 = MEM_W(0X4F58, ctx->r19);
L_80033A60:
    // nop

    // sltiu       $v0, $s3, 0x50
    ctx->r2 = ctx->r19 < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_80033AB0
    if (ctx->r2 == 0) {
        // addu        $s1, $s5, $zero
        ctx->r17 = ADD32(ctx->r21, 0);
        goto L_80033AB0;
    }
    // addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    // ori         $s0, $zero, 0x18
    ctx->r16 = 0 | 0X18;
L_80033A74:
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // sltiu       $v0, $a0, 0x50
    ctx->r2 = ctx->r4 < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_80033A9C
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80033A9C;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // lbu         $a2, 0x0($s2)
    ctx->r6 = MEM_BU(0X0, ctx->r18);
    // nop

    // beq         $a2, $zero, L_80033A9C
    if (ctx->r6 == 0) {
        // nop
    
        goto L_80033A9C;
    }
    // nop

    // jal         0x800338A0
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_800338A0(rdram, ctx);
    // drawCount++;
    goto after_1;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_1:
L_80033A9C:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $zero, L_80033A74
    if (ctx->r16 != 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80033A74;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // j           L_80033AB8
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    goto L_80033AB8;
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
L_80033AB0:
    // addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
L_80033AB8:
    // bne         $s4, $zero, L_80033A60
    if (ctx->r20 != 0) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80033A60;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    // printf("[Cull] drawCount=%d KFCullDistX=%d KFCullDistZ=%d\n",
        // drawCount,
        // MEM_W(0, ADDR_KFCullDistanceXNeg),
        // MEM_W(0, ADDR_KFCullDistanceZNeg));
		
    return;
    // nop

;}
