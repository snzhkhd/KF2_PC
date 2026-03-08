#include "recomp.h"
#include "disable_warnings.h"

void ProcessListNavigation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x80024E70
    // sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    WaitForInputStable(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    after_0:
    // jal         0x80024E3C
    // nop

    ReadPadWithFlag(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lbu         $v1, 0x1E($s0)
    ctx->r3 = MEM_BU(0X1E, ctx->r16);
    // nop

    // bne         $v1, $zero, L_800205D4
    if (ctx->r3 != 0) {
        // addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
        goto L_800205D4;
    }
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // beq         $s1, $zero, L_80020874
    if (ctx->r17 == 0) {
        // nop
    
        goto L_80020874;
    }
    // nop

    // j           L_80020864
    // nop

    goto L_80020864;
    // nop

L_800205D4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F4($v0)
    ctx->r2 = MEM_W(0X62F4, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_800206BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800206BC;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_2;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_2:
    // lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(0X21, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80020640
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020640;
    }
    // nop

    // lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(0X21, ctx->r16);
    // lbu         $v1, 0x22($s0)
    ctx->r3 = MEM_BU(0X22, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v1, $zero, L_8002062C
    if (ctx->r3 != 0) {
        // sb          $v0, 0x21($s0)
        MEM_B(0X21, ctx->r16) = ctx->r2;
        goto L_8002062C;
    }
    // sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(0X20, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_8002068C
    // sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
    goto L_8002068C;
    // sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
L_8002062C:
    // lbu         $v0, 0x22($s0)
    ctx->r2 = MEM_BU(0X22, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_8002068C
    // sb          $v0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r2;
    goto L_8002068C;
    // sb          $v0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r2;
L_80020640:
    // lbu         $v0, 0x1E($s0)
    ctx->r2 = MEM_BU(0X1E, ctx->r16);
    // lbu         $v1, 0x1E($s0)
    ctx->r3 = MEM_BU(0X1E, ctx->r16);
    // lbu         $a0, 0x1F($s0)
    ctx->r4 = MEM_BU(0X1F, ctx->r16);
    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
    // sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // beq         $v1, $zero, L_80020670
    if (ctx->r3 == 0) {
        // sb          $v0, 0x21($s0)
        MEM_B(0X21, ctx->r16) = ctx->r2;
        goto L_80020670;
    }
    // sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x1E($s0)
    ctx->r2 = MEM_BU(0X1E, ctx->r16);
    // sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
    // j           L_8002068C
    // sb          $v0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r2;
    goto L_8002068C;
    // sb          $v0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r2;
L_80020670:
    // lbu         $v0, 0x1E($s0)
    ctx->r2 = MEM_BU(0X1E, ctx->r16);
    // lbu         $a0, 0x1F($s0)
    ctx->r4 = MEM_BU(0X1F, ctx->r16);
    // lbu         $v1, 0x1F($s0)
    ctx->r3 = MEM_BU(0X1F, ctx->r16);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // addiu       $v1, $v1, 0xFF
    ctx->r3 = ADD32(ctx->r3, 0XFF);
    // sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
    // sb          $v1, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r3;
L_8002068C:
    // beq         $s3, $zero, L_80020874
    if (ctx->r19 == 0) {
        // nop
    
        goto L_80020874;
    }
    // nop

    // lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(0X21, ctx->r16);
    // nop

    // addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(0X0, ctx->r2);
    // jal         0x80024CAC
    // nop

    Draw3dPreview(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // beq         $v0, $zero, L_80020874
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80020874;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_80020870
    // nop

    goto L_80020870;
    // nop

L_800206BC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F8($v0)
    ctx->r2 = MEM_W(0X62F8, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_8002077C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002077C;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_4;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_4:
    // lbu         $v0, 0x1E($s0)
    ctx->r2 = MEM_BU(0X1E, ctx->r16);
    // lbu         $v1, 0x21($s0)
    ctx->r3 = MEM_BU(0X21, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_80020740
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80020740;
    }
    // nop

    // lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(0X21, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(0X1F, ctx->r16);
    // lbu         $v1, 0x22($s0)
    ctx->r3 = MEM_BU(0X22, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v1, $v0, L_8002072C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8002072C;
    }
    // nop

    // lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(0X20, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8002074C
    // sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
    goto L_8002074C;
    // sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
L_8002072C:
    // lbu         $v0, 0x22($s0)
    ctx->r2 = MEM_BU(0X22, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8002074C
    // sb          $v0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r2;
    goto L_8002074C;
    // sb          $v0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r2;
L_80020740:
    // sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    // sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
    // sb          $zero, 0x22($s0)
    MEM_B(0X22, ctx->r16) = 0;
L_8002074C:
    // beq         $s3, $zero, L_80020874
    if (ctx->r19 == 0) {
        // nop
    
        goto L_80020874;
    }
    // nop

    // lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(0X21, ctx->r16);
    // nop

    // addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(0X0, ctx->r2);
    // jal         0x80024CAC
    // nop

    Draw3dPreview(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // beq         $v0, $zero, L_80020874
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80020874;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_80020870
    // nop

    goto L_80020870;
    // nop

L_8002077C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62FC($v0)
    ctx->r2 = MEM_W(0X62FC, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_800207C8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800207C8;
    }
    // nop

    // lw          $v0, 0x6C($gp)
    ctx->r2 = MEM_W(0X6C, ctx->r28);
    // nop

    // slti        $v0, $v0, 0x63
    ctx->r2 = SIGNED(ctx->r2) < 0X63 ? 1 : 0;
    // beq         $v0, $zero, L_80020874
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020874;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_6;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_6:
    // lw          $v0, 0x6C($gp)
    ctx->r2 = MEM_W(0X6C, ctx->r28);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x6C($gp)
    MEM_W(0X6C, ctx->r28) = ctx->r2;
    // j           L_80020874
    // nop

    goto L_80020874;
    // nop

L_800207C8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6300($v0)
    ctx->r2 = MEM_W(0X6300, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80020814
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020814;
    }
    // nop

    // lw          $v0, 0x6C($gp)
    ctx->r2 = MEM_W(0X6C, ctx->r28);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80020874
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80020874;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_7;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_7:
    // lw          $v0, 0x6C($gp)
    ctx->r2 = MEM_W(0X6C, ctx->r28);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x6C($gp)
    MEM_W(0X6C, ctx->r28) = ctx->r2;
    // j           L_80020874
    // nop

    goto L_80020874;
    // nop

L_80020814:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(0X62CC, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80020834
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80020834;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // j           L_80020874
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    goto L_80020874;
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_80020834:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D0($v0)
    ctx->r2 = MEM_W(0X62D0, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // bne         $v0, $zero, L_80020864
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80020864;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E0($v0)
    ctx->r2 = MEM_W(0X62E0, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_8002097C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002097C;
    }
    // nop

L_80020864:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_8;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_8:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80020870:
    // sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_80020874:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E0($v0)
    ctx->r2 = MEM_W(0X62E0, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_8002097C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002097C;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E4($v0)
    ctx->r2 = MEM_W(0X62E4, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_800208B4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800208B4;
    }
    // nop

    // lhu         $v0, 0x10C($gp)
    ctx->r2 = MEM_HU(0X10C, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0x10C($gp)
    MEM_H(0X10C, ctx->r28) = ctx->r2;
L_800208B4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E8($v0)
    ctx->r2 = MEM_W(0X62E8, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_800208DC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800208DC;
    }
    // nop

    // lhu         $v0, 0x10C($gp)
    ctx->r2 = MEM_HU(0X10C, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // sh          $v0, 0x10C($gp)
    MEM_H(0X10C, ctx->r28) = ctx->r2;
L_800208DC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62EC($v0)
    ctx->r2 = MEM_W(0X62EC, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80020904
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020904;
    }
    // nop

    // lhu         $v0, 0x110($gp)
    ctx->r2 = MEM_HU(0X110, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0x110($gp)
    MEM_H(0X110, ctx->r28) = ctx->r2;
L_80020904:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F0($v0)
    ctx->r2 = MEM_W(0X62F0, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_8002092C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002092C;
    }
    // nop

    // lhu         $v0, 0x110($gp)
    ctx->r2 = MEM_HU(0X110, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // sh          $v0, 0x110($gp)
    MEM_H(0X110, ctx->r28) = ctx->r2;
L_8002092C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D4($v0)
    ctx->r2 = MEM_W(0X62D4, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80020954
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020954;
    }
    // nop

    // lw          $v0, 0x114($gp)
    ctx->r2 = MEM_W(0X114, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x114($gp)
    MEM_W(0X114, ctx->r28) = ctx->r2;
L_80020954:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D8($v0)
    ctx->r2 = MEM_W(0X62D8, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_8002097C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002097C;
    }
    // nop

    // lw          $v0, 0x114($gp)
    ctx->r2 = MEM_W(0X114, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x114($gp)
    MEM_W(0X114, ctx->r28) = ctx->r2;
L_8002097C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62DC($v0)
    ctx->r2 = MEM_W(0X62DC, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80020A98
    if (ctx->r2 == 0) {
        // addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
        goto L_80020A98;
    }
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E4($v0)
    ctx->r2 = MEM_W(0X62E4, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_800209BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800209BC;
    }
    // nop

    // lhu         $v0, 0x104($gp)
    ctx->r2 = MEM_HU(0X104, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0x104($gp)
    MEM_H(0X104, ctx->r28) = ctx->r2;
L_800209BC:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62E8($v0)
    ctx->r2 = MEM_W(0X62E8, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_800209E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800209E4;
    }
    // nop

    // lhu         $v0, 0x104($gp)
    ctx->r2 = MEM_HU(0X104, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // sh          $v0, 0x104($gp)
    MEM_H(0X104, ctx->r28) = ctx->r2;
L_800209E4:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62EC($v0)
    ctx->r2 = MEM_W(0X62EC, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80020A0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020A0C;
    }
    // nop

    // lhu         $v0, 0x106($gp)
    ctx->r2 = MEM_HU(0X106, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0x106($gp)
    MEM_H(0X106, ctx->r28) = ctx->r2;
L_80020A0C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62F0($v0)
    ctx->r2 = MEM_W(0X62F0, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80020A34
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020A34;
    }
    // nop

    // lhu         $v0, 0x106($gp)
    ctx->r2 = MEM_HU(0X106, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // sh          $v0, 0x106($gp)
    MEM_H(0X106, ctx->r28) = ctx->r2;
L_80020A34:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D4($v0)
    ctx->r2 = MEM_W(0X62D4, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80020A5C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020A5C;
    }
    // nop

    // lhu         $v0, 0x108($gp)
    ctx->r2 = MEM_HU(0X108, ctx->r28);
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0x108($gp)
    MEM_H(0X108, ctx->r28) = ctx->r2;
L_80020A5C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62D8($v0)
    ctx->r2 = MEM_W(0X62D8, ctx->r2);
    // nop

    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80020A98
    if (ctx->r2 == 0) {
        // addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
        goto L_80020A98;
    }
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // lh          $v0, 0x108($gp)
    ctx->r2 = MEM_H(0X108, ctx->r28);
    // nop

    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slti        $v0, $v0, 0x1F5
    ctx->r2 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // bne         $v0, $zero, L_80020A90
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x10
        ctx->r2 = ADD32(ctx->r3, -0X10);
        goto L_80020A90;
    }
    // addiu       $v0, $v1, -0x10
    ctx->r2 = ADD32(ctx->r3, -0X10);
    // sh          $v0, 0x108($gp)
    MEM_H(0X108, ctx->r28) = ctx->r2;
L_80020A90:
    // sw          $zero, 0x68($gp)
    MEM_W(0X68, ctx->r28) = 0;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80020A98:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
