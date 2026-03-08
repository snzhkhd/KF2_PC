#include "recomp.h"
#include "disable_warnings.h"

void RenderStaticMenuBox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // lui         $fp, 0x8006
    ctx->r30 = S32(0X8006 << 16);
    // addiu       $fp, $fp, 0x7AE4
    ctx->r30 = ADD32(ctx->r30, 0X7AE4);
    // sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // lui         $s7, 0x801A
    ctx->r23 = S32(0X801A << 16);
    // addiu       $s7, $s7, -0x4A66
    ctx->r23 = ADD32(ctx->r23, -0X4A66);
    // sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // lui         $s6, 0x8006
    ctx->r22 = S32(0X8006 << 16);
    // addiu       $s6, $s6, 0x7CCC
    ctx->r22 = ADD32(ctx->r22, 0X7CCC);
    // sll         $v0, $s5, 3
    ctx->r2 = S32(ctx->r21) << 3;
    // subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // addiu       $s4, $v0, 0x1C
    ctx->r20 = ADD32(ctx->r2, 0X1C);
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
L_8001C5F4:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // slti        $v0, $s5, 0x6
    ctx->r2 = SIGNED(ctx->r21) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_8001C668
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001C668;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lh          $v0, 0x0($s7)
    ctx->r2 = MEM_H(0X0, ctx->r23);
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5) << 5;
    // addu        $a1, $a1, $s6
    ctx->r5 = ADD32(ctx->r5, ctx->r22);
    // jal         0x80023944
    // addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    ui_DrawFrame(rdram, ctx);
    goto after_1;
    // addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    after_1:
    // lh          $v0, 0x0($s7)
    ctx->r2 = MEM_H(0X0, ctx->r23);
    // addiu       $a0, $fp, -0x30
    ctx->r4 = ADD32(ctx->r30, -0X30);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5) << 5;
    // addu        $a1, $a1, $s6
    ctx->r5 = ADD32(ctx->r5, ctx->r22);
    // jal         0x80023E20
    // addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    ui_DrawText(rdram, ctx);
    goto after_2;
    // addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    after_2:
L_8001C668:
    // lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(0X18, ctx->r29);
    // blez        $s3, L_8001C694
    if (SIGNED(ctx->r19) <= 0) {
        // nop
    
        goto L_8001C694;
    }
    // nop

L_8001C674:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AB4
    ctx->r4 = ADD32(ctx->r4, 0X7AB4);
    // jal         0x80023E20
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    ui_DrawText(rdram, ctx);
    goto after_3;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_8001C674
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
        goto L_8001C674;
    }
    // addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_8001C694:
    // lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(0X74, ctx->r29);
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(0X68, ctx->r29);
    // lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(0X6C, ctx->r29);
    // lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(0X70, ctx->r29);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(0X78, ctx->r29);
    // jal         0x80024298
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    DrawTextureNPatch(rdram, ctx);
    goto after_4;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_4:
    // jal         0x80024620
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_5;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_5:
    // slti        $v0, $s2, 0x2
    ctx->r2 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001C5F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001C5F4;
    }
    // nop

    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
    // lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(0X50, ctx->r29);
    // lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(0X4C, ctx->r29);
    // lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
