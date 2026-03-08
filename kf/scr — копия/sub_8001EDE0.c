#include "recomp.h"
#include "disable_warnings.h"

void sub_8001EDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // lui         $s6, 0x8006
    ctx->r22 = S32(0X8006 << 16);
    // addiu       $s6, $s6, 0x7AE4
    ctx->r22 = ADD32(ctx->r22, 0X7AE4);
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // addiu       $s5, $s5, -0x4A66
    ctx->r21 = ADD32(ctx->r21, -0X4A66);
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // lui         $s4, 0x8006
    ctx->r20 = S32(0X8006 << 16);
    // addiu       $s4, $s4, 0x7CCC
    ctx->r20 = ADD32(ctx->r20, 0X7CCC);
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
L_8001EE38:
    // jal         0x800244E0
    // addu        $s1, $s7, $zero
    ctx->r17 = ADD32(ctx->r23, 0);
    BeginDraw2D(rdram, ctx);
    goto after_0;
    // addu        $s1, $s7, $zero
    ctx->r17 = ADD32(ctx->r23, 0);
    after_0:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(0X0, ctx->r21);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
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
    // addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // jal         0x80023944
    // addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    ui_DrawFrame(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    after_1:
    // lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(0X0, ctx->r21);
    // addiu       $a0, $s6, -0x30
    ctx->r4 = ADD32(ctx->r22, -0X30);
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
    // addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // jal         0x80023E20
    // addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    ui_DrawText(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    after_2:
    // blez        $s3, L_8001EECC
    if (SIGNED(ctx->r19) <= 0) {
        // nop
    
        goto L_8001EECC;
    }
    // nop

L_8001EEAC:
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
    // bne         $v0, $zero, L_8001EEAC
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
        goto L_8001EEAC;
    }
    // addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_8001EECC:
    // lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(0X68, ctx->r29);
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(0X60, ctx->r29);
    // lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(0X64, ctx->r29);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(0X6C, ctx->r29);
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
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
    // bne         $v0, $zero, L_8001EE38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001EE38;
    }
    // nop

    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(0X48, ctx->r29);
    // lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(0X44, ctx->r29);
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
