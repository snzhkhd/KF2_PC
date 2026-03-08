#include "recomp.h"
#include "disable_warnings.h"

void SaveDataMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $ra, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r31;
    // sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
L_8001BEF8:
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // nop

    // bne         $v0, $s3, L_8001BF18
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_8001BF18;
    }
    // nop

    // lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(0X58, ctx->r29);
    // nop

    // beq         $v0, $s2, L_8001BF20
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_8001BF20;
    }
    // nop

L_8001BF18:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_8001BF20:
    // lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(0X50, ctx->r29);
    // nop

    // beq         $v1, $zero, L_8001BF40
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_8001BF40;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_8001BF58
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8001BF58;
    }
    // nop

    // j           L_8001BF70
    // nop

    goto L_8001BF70;
    // nop

L_8001BF40:
    // jal         0x8001C068
    // nop

    sub_8001C068(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // bne         $v0, $zero, L_8001BF70
    if (ctx->r2 != 0) {
        // sw          $v0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_8001BF70;
    }
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // j           L_8001BF6C
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    goto L_8001BF6C;
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
L_8001BF58:
    // jal         0x8001C700
    // nop

    KF_SaveLoad(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $zero, L_8001BF70
    if (ctx->r2 != 0) {
        // sw          $v0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_8001BF70;
    }
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_8001BF6C:
    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_8001BF70:
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // nop

    // beq         $v0, $s3, L_8001BF94
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_8001BF94;
    }
    // nop

    // lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(0X58, ctx->r29);
    // nop

    // bne         $v0, $s3, L_8001BF98
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_8001BF98;
    }
    // nop

    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
L_8001BF94:
    // lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(0X58, ctx->r29);
L_8001BF98:
    // nop

    // bne         $v0, $s2, L_8001BFFC
    if (ctx->r2 != ctx->r18) {
        // addiu       $v0, $sp, 0x58
        ctx->r2 = ADD32(ctx->r29, 0X58);
        goto L_8001BFFC;
    }
    // addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // jal         0x80020420
    // addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    MenuInputProcess(rdram, ctx);
    goto after_3;
    // addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_3:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001BFC4:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_4;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_4:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(0X54, ctx->r29);
    // jal         0x80022774
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    RenderMenuFrame(rdram, ctx);
    goto after_5;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_5:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001BFC4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001BFC4;
    }
    // nop

    // j           L_8001BEF8
    // nop

    goto L_8001BEF8;
    // nop

L_8001BFFC:
    // lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(0X58, ctx->r29);
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // bne         $v1, $v0, L_8001C044
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8001C044;
    }
    // nop

    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001C010:
    // jal         0x8006263C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_VSync(rdram, ctx);
    goto after_7;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x1E
    ctx->r2 = SIGNED(ctx->r16) < 0X1E ? 1 : 0;
    // bne         $v0, $zero, L_8001C010
    if (ctx->r2 != 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8001C010;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lh          $a0, -0x59D4($a0)
    ctx->r4 = MEM_H(-0X59D4, ctx->r4);
    // jal         0x80052198
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CDAudio_SetVolume(rdram, ctx);
    goto after_8;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_8:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // sb          $v0, 0x3F0($at)
    MEM_B(0X3F0, ctx->r1) = ctx->r2;
L_8001C044:
    // lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(0X58, ctx->r29);
    // lw          $ra, 0x70($sp)
    ctx->r31 = MEM_W(0X70, ctx->r29);
    // lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(0X6C, ctx->r29);
    // lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(0X68, ctx->r29);
    // lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(0X64, ctx->r29);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
