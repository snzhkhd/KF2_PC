#include "recomp.h"
#include "disable_warnings.h"

void ShowUseMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x5F0
    ctx->r29 = ADD32(ctx->r29, -0X5F0);
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x2190
    ctx->r4 = ADD32(ctx->r4, -0X2190);
    // sw          $s2, 0x5E0($sp)
    MEM_W(0X5E0, ctx->r29) = ctx->r18;
    // addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // sw          $s1, 0x5DC($sp)
    MEM_W(0X5DC, ctx->r29) = ctx->r17;
    // addiu       $s1, $sp, 0x560
    ctx->r17 = ADD32(ctx->r29, 0X560);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sw          $s4, 0x5E8($sp)
    MEM_W(0X5E8, ctx->r29) = ctx->r20;
    // addiu       $s4, $sp, 0x598
    ctx->r20 = ADD32(ctx->r29, 0X598);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0x5D4($sp)
    MEM_W(0X5D4, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x43
    ctx->r2 = 0 | 0X43;
    // sw          $zero, 0x5D0($sp)
    MEM_W(0X5D0, ctx->r29) = 0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x77
    ctx->r2 = 0 | 0X77;
    // sw          $ra, 0x5EC($sp)
    MEM_W(0X5EC, ctx->r29) = ctx->r31;
    // sw          $s3, 0x5E4($sp)
    MEM_W(0X5E4, ctx->r29) = ctx->r19;
    // sw          $s0, 0x5D8($sp)
    MEM_W(0X5D8, ctx->r29) = ctx->r16;
    // jal         0x80019CD0
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    GetInventoryItems(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x800249BC
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    InitListWidget(rdram, ctx);
    goto after_1;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // lbu         $a1, 0x78($gp)
    ctx->r5 = MEM_BU(0X78, ctx->r28);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sb          $s0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r16;
    // sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // jal         0x80024A8C
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    ListNavigating(rdram, ctx);
    goto after_2;
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    after_2:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_80019B38
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019B38;
    }
    // nop

    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // nop

    // addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(0X0, ctx->r2);
    // jal         0x80024CAC
    // nop

    Draw3dPreview(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // beq         $v0, $zero, L_80019B3C
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, -0x63
        ctx->r18 = ADD32(0, -0X63);
        goto L_80019B3C;
    }
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
L_80019B30:
    // j           L_80019CAC
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80019CAC;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80019B38:
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
L_80019B3C:
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
    // addiu       $s1, $sp, 0x598
    ctx->r17 = ADD32(ctx->r29, 0X598);
L_80019B44:
    // lw          $v0, 0x5D0($sp)
    ctx->r2 = MEM_W(0X5D0, ctx->r29);
    // nop

    // bne         $v0, $zero, L_80019B64
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80019B64;
    }
    // nop

    // lw          $v0, 0x5D4($sp)
    ctx->r2 = MEM_W(0X5D4, ctx->r29);
    // nop

    // beq         $v0, $s2, L_80019B6C
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_80019B6C;
    }
    // nop

L_80019B64:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_80019B6C:
    // lw          $v0, 0x5D0($sp)
    ctx->r2 = MEM_W(0X5D0, ctx->r29);
    // nop

    // bne         $v0, $s4, L_80019BA8
    if (ctx->r2 != ctx->r20) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_80019BA8;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    // jal         0x80022468
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    ShowEquipmentMenu(rdram, ctx);
    goto after_5;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_5:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80019BA4
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x5D4($sp)
        MEM_W(0X5D4, ctx->r29) = ctx->r2;
        goto L_80019BA4;
    }
    // sw          $v0, 0x5D4($sp)
    MEM_W(0X5D4, ctx->r29) = ctx->r2;
    // j           L_80019BA8
    // sw          $s2, 0x5D4($sp)
    MEM_W(0X5D4, ctx->r29) = ctx->r18;
    goto L_80019BA8;
    // sw          $s2, 0x5D4($sp)
    MEM_W(0X5D4, ctx->r29) = ctx->r18;
L_80019BA4:
    // sw          $s0, 0x5D4($sp)
    MEM_W(0X5D4, ctx->r29) = ctx->r16;
L_80019BA8:
    // lw          $v0, 0x5D4($sp)
    ctx->r2 = MEM_W(0X5D4, ctx->r29);
    // nop

    // bne         $v0, $s2, L_80019C80
    if (ctx->r2 != ctx->r18) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_80019C80;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $a2, $sp, 0x5D0
    ctx->r6 = ADD32(ctx->r29, 0X5D0);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x5D4
    ctx->r7 = ADD32(ctx->r29, 0X5D4);
    ProcessListNavigation(rdram, ctx);
    goto after_6;
    // addiu       $a3, $sp, 0x5D4
    ctx->r7 = ADD32(ctx->r29, 0X5D4);
    after_6:
    // lbu         $v1, 0x39($sp)
    ctx->r3 = MEM_BU(0X39, ctx->r29);
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // sb          $v0, 0x78($gp)
    MEM_B(0X78, ctx->r28) = ctx->r2;
    // lw          $v0, 0x5D0($sp)
    ctx->r2 = MEM_W(0X5D0, ctx->r29);
    // lbu         $s3, 0x0($v1)
    ctx->r19 = MEM_BU(0X0, ctx->r3);
    // bne         $v0, $s4, L_80019C38
    if (ctx->r2 != ctx->r20) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80019C38;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_7;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_7:
    // addiu       $v0, $s3, -0x43
    ctx->r2 = ADD32(ctx->r19, -0X43);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80019C0C
    if (ctx->r2 != 0) {
        // andi        $v1, $s3, 0xFF
        ctx->r3 = ctx->r19 & 0XFF;
        goto L_80019C0C;
    }
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // ori         $v0, $zero, 0x45
    ctx->r2 = 0 | 0X45;
    // bne         $v1, $v0, L_80019C38
    if (ctx->r3 != ctx->r2) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80019C38;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80019C0C:
    // jal         0x80024D70
    // andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    Flush3dRender(rdram, ctx);
    goto after_8;
    // andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    after_8:
    // jal         0x8001A428
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    DrawTexture(rdram, ctx);
    goto after_9;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_10;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_10:
    // jal         0x80024CAC
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    Draw3dPreview(rdram, ctx);
    goto after_11;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // bne         $v0, $zero, L_80019B30
    if (ctx->r2 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80019B30;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sw          $zero, 0x5D0($sp)
    MEM_W(0X5D0, ctx->r29) = 0;
L_80019C38:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_80019C5C
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_80019C5C;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80023388
    // andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_13;
    // andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    after_13:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_80019C5C:
    // jal         0x800228B4
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    RenderItemList(rdram, ctx);
    goto after_14;
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    after_14:
    // jal         0x80024620
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_15;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_15:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80019C38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80019C38;
    }
    // nop

    // j           L_80019B44
    // nop

    goto L_80019B44;
    // nop

L_80019C80:
    // jal         0x80024D70
    // nop

    Flush3dRender(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // lw          $a0, 0x5D4($sp)
    ctx->r4 = MEM_W(0X5D4, ctx->r29);
    // nop

    // addiu       $v0, $a0, -0x47
    ctx->r2 = ADD32(ctx->r4, -0X47);
    // sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_80019CA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019CA8;
    }
    // nop

    // jal         0x8001A0BC
    // nop

    UseConsumableItem(rdram, ctx);
    goto after_17;
    // nop

    after_17:
L_80019CA8:
    // lw          $v0, 0x5D4($sp)
    ctx->r2 = MEM_W(0X5D4, ctx->r29);
L_80019CAC:
    // lw          $ra, 0x5EC($sp)
    ctx->r31 = MEM_W(0X5EC, ctx->r29);
    // lw          $s4, 0x5E8($sp)
    ctx->r20 = MEM_W(0X5E8, ctx->r29);
    // lw          $s3, 0x5E4($sp)
    ctx->r19 = MEM_W(0X5E4, ctx->r29);
    // lw          $s2, 0x5E0($sp)
    ctx->r18 = MEM_W(0X5E0, ctx->r29);
    // lw          $s1, 0x5DC($sp)
    ctx->r17 = MEM_W(0X5DC, ctx->r29);
    // lw          $s0, 0x5D8($sp)
    ctx->r16 = MEM_W(0X5D8, ctx->r29);
    // addiu       $sp, $sp, 0x5F0
    ctx->r29 = ADD32(ctx->r29, 0X5F0);
    // jr          $ra
    // nop

    return;
    // nop

;}
