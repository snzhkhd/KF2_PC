#include "recomp.h"
#include "disable_warnings.h"

void sub_8001F77C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xCA0
    ctx->r29 = ADD32(ctx->r29, -0XCA0);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $ra, 0xC9C($sp)
    MEM_W(0XC9C, ctx->r29) = ctx->r31;
    // sw          $s4, 0xC98($sp)
    MEM_W(0XC98, ctx->r29) = ctx->r20;
    // sw          $s3, 0xC94($sp)
    MEM_W(0XC94, ctx->r29) = ctx->r19;
    // sw          $s2, 0xC90($sp)
    MEM_W(0XC90, ctx->r29) = ctx->r18;
    // sw          $s1, 0xC8C($sp)
    MEM_W(0XC8C, ctx->r29) = ctx->r17;
    // sw          $s0, 0xC88($sp)
    MEM_W(0XC88, ctx->r29) = ctx->r16;
    // sw          $zero, 0xC80($sp)
    MEM_W(0XC80, ctx->r29) = 0;
    // jal         0x800246CC
    // sw          $v0, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r2;
    SetupMenuUIBuffers(rdram, ctx);
    goto after_0;
    // sw          $v0, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r2;
    after_0:
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x2190
    ctx->r4 = ADD32(ctx->r4, -0X2190);
    // addiu       $s3, $sp, 0x50
    ctx->r19 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addiu       $s2, $sp, 0xB90
    ctx->r18 = ADD32(ctx->r29, 0XB90);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $s1, $sp, 0xC08
    ctx->r17 = ADD32(ctx->r29, 0XC08);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // ori         $v0, $zero, 0x77
    ctx->r2 = 0 | 0X77;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80019CD0
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    GetInventoryItems(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x800249BC
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    InitListWidget(rdram, ctx);
    goto after_2;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // lbu         $a1, 0x7B($gp)
    ctx->r5 = MEM_BU(0X7B, ctx->r28);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sb          $s0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r16;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // jal         0x80024A8C
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    ListNavigating(rdram, ctx);
    goto after_3;
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    after_3:
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // nop

    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lbu         $s1, 0x0($s1)
    ctx->r17 = MEM_BU(0X0, ctx->r17);
    // jal         0x80024CAC
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    Draw3dPreview(rdram, ctx);
    goto after_4;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // bne         $v0, $zero, L_8001F994
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8001F994;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8001F834:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001F858
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001F858;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80023388
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_6;
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_6:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_8001F858:
    // jal         0x800228B4
    // ori         $a1, $zero, 0xC
    ctx->r5 = 0 | 0XC;
    RenderItemList(rdram, ctx);
    goto after_7;
    // ori         $a1, $zero, 0xC
    ctx->r5 = 0 | 0XC;
    after_7:
    // jal         0x80024620
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_8;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_8:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001F834
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001F834;
    }
    // nop

    // jal         0x80024DA8
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    PlaySfx(rdram, ctx);
    goto after_9;
    // ori         $a0, $zero, 0x10
    ctx->r4 = 0 | 0X10;
    after_9:
    // jal         0x80024ED4
    // addiu       $s3, $zero, -0x63
    ctx->r19 = ADD32(0, -0X63);
    WaitForButtonRelease(rdram, ctx);
    goto after_10;
    // addiu       $s3, $zero, -0x63
    ctx->r19 = ADD32(0, -0X63);
    after_10:
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
    // addiu       $s2, $sp, 0xC08
    ctx->r18 = ADD32(ctx->r29, 0XC08);
L_8001F88C:
    // lw          $v0, 0xC80($sp)
    ctx->r2 = MEM_W(0XC80, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001F8AC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001F8AC;
    }
    // nop

    // lw          $v0, 0xC84($sp)
    ctx->r2 = MEM_W(0XC84, ctx->r29);
    // nop

    // beq         $v0, $s3, L_8001F8B4
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_8001F8B4;
    }
    // nop

L_8001F8AC:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_11;
    // nop

    after_11:
L_8001F8B4:
    // lw          $v0, 0xC80($sp)
    ctx->r2 = MEM_W(0XC80, ctx->r29);
    // nop

    // bne         $v0, $s4, L_8001F8F0
    if (ctx->r2 != ctx->r20) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001F8F0;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // ori         $a1, $zero, 0x8
    ctx->r5 = 0 | 0X8;
    // ori         $a2, $zero, 0xC
    ctx->r6 = 0 | 0XC;
    // andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // jal         0x80022468
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    ShowEquipmentMenu(rdram, ctx);
    goto after_12;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_12:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001F8EC
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0xC84($sp)
        MEM_W(0XC84, ctx->r29) = ctx->r2;
        goto L_8001F8EC;
    }
    // sw          $v0, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r2;
    // j           L_8001F8F0
    // sw          $s3, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r19;
    goto L_8001F8F0;
    // sw          $s3, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r19;
L_8001F8EC:
    // sw          $s1, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r17;
L_8001F8F0:
    // lw          $v0, 0xC84($sp)
    ctx->r2 = MEM_W(0XC84, ctx->r29);
    // nop

    // bne         $v0, $s3, L_8001F980
    if (ctx->r2 != ctx->r19) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001F980;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $a2, $sp, 0xC80
    ctx->r6 = ADD32(ctx->r29, 0XC80);
    // jal         0x80020578
    // addiu       $a3, $sp, 0xC84
    ctx->r7 = ADD32(ctx->r29, 0XC84);
    ProcessListNavigation(rdram, ctx);
    goto after_13;
    // addiu       $a3, $sp, 0xC84
    ctx->r7 = ADD32(ctx->r29, 0XC84);
    after_13:
    // lbu         $v1, 0x39($sp)
    ctx->r3 = MEM_BU(0X39, ctx->r29);
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // sb          $v0, 0x7B($gp)
    MEM_B(0X7B, ctx->r28) = ctx->r2;
    // lw          $v0, 0xC80($sp)
    ctx->r2 = MEM_W(0XC80, ctx->r29);
    // lbu         $s1, 0x0($v1)
    ctx->r17 = MEM_BU(0X0, ctx->r3);
    // bne         $v0, $s4, L_8001F938
    if (ctx->r2 != ctx->r20) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001F938;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_14;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_14:
L_8001F938:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001F95C
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001F95C;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80023388
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_16;
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_16:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_8001F95C:
    // jal         0x800228B4
    // ori         $a1, $zero, 0xC
    ctx->r5 = 0 | 0XC;
    RenderItemList(rdram, ctx);
    goto after_17;
    // ori         $a1, $zero, 0xC
    ctx->r5 = 0 | 0XC;
    after_17:
    // jal         0x80024620
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_18;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_18:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001F938
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001F938;
    }
    // nop

    // j           L_8001F88C
    // nop

    goto L_8001F88C;
    // nop

L_8001F980:
    // jal         0x80024D70
    // nop

    Flush3dRender(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // jal         0x80024820
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    Music_UpdateState(rdram, ctx);
    goto after_20;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_20:
    // lw          $v0, 0xC84($sp)
    ctx->r2 = MEM_W(0XC84, ctx->r29);
L_8001F994:
    // lw          $ra, 0xC9C($sp)
    ctx->r31 = MEM_W(0XC9C, ctx->r29);
    // lw          $s4, 0xC98($sp)
    ctx->r20 = MEM_W(0XC98, ctx->r29);
    // lw          $s3, 0xC94($sp)
    ctx->r19 = MEM_W(0XC94, ctx->r29);
    // lw          $s2, 0xC90($sp)
    ctx->r18 = MEM_W(0XC90, ctx->r29);
    // lw          $s1, 0xC8C($sp)
    ctx->r17 = MEM_W(0XC8C, ctx->r29);
    // lw          $s0, 0xC88($sp)
    ctx->r16 = MEM_W(0XC88, ctx->r29);
    // addiu       $sp, $sp, 0xCA0
    ctx->r29 = ADD32(ctx->r29, 0XCA0);
    // jr          $ra
    // nop

    return;
    // nop

;}
