#include "recomp.h"
#include "disable_warnings.h"

void UseMagicMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x2B8
    ctx->r29 = ADD32(ctx->r29, -0X2B8);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x1900
    ctx->r4 = ADD32(ctx->r4, -0X1900);
    // sw          $s2, 0x2A8($sp)
    MEM_W(0X2A8, ctx->r29) = ctx->r18;
    // addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // sw          $s1, 0x2A4($sp)
    MEM_W(0X2A4, ctx->r29) = ctx->r17;
    // addiu       $s1, $sp, 0x230
    ctx->r17 = ADD32(ctx->r29, 0X230);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addiu       $a3, $sp, 0x280
    ctx->r7 = ADD32(ctx->r29, 0X280);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0xE
    ctx->r2 = 0 | 0XE;
    // sw          $zero, 0x298($sp)
    MEM_W(0X298, ctx->r29) = 0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x13
    ctx->r2 = 0 | 0X13;
    // sw          $ra, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r31;
    // sw          $s4, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r19;
    // sw          $s0, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = ctx->r16;
    // jal         0x8001A9E4
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    CollectAvailableSpells(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
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
    // addiu       $s3, $zero, -0x63
    ctx->r19 = ADD32(0, -0X63);
    // ori         $s4, $zero, 0x1
    ctx->r20 = 0 | 0X1;
    // lbu         $a1, 0x79($gp)
    ctx->r5 = MEM_BU(0X79, ctx->r28);
    // ori         $v0, $zero, 0x6
    ctx->r2 = 0 | 0X6;
    // sb          $v0, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x83
    ctx->r2 = 0 | 0X83;
    // sb          $v0, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sb          $s0, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r16;
    // sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // jal         0x80024A8C
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    ListNavigating(rdram, ctx);
    goto after_2;
    // sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    after_2:
L_8001A8C8:
    // lw          $v0, 0x298($sp)
    ctx->r2 = MEM_W(0X298, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001A8E8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001A8E8;
    }
    // nop

    // lw          $v0, 0x29C($sp)
    ctx->r2 = MEM_W(0X29C, ctx->r29);
    // nop

    // beq         $v0, $s3, L_8001A8F0
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_8001A8F0;
    }
    // nop

L_8001A8E8:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_8001A8F0:
    // lw          $v0, 0x298($sp)
    ctx->r2 = MEM_W(0X298, ctx->r29);
    // nop

    // bne         $v0, $s4, L_8001A93C
    if (ctx->r2 != ctx->r20) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001A93C;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x2
    ctx->r6 = 0 | 0X2;
    // jal         0x80022468
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    ShowEquipmentMenu(rdram, ctx);
    goto after_4;
    // ori         $a3, $zero, 0xFF
    ctx->r7 = 0 | 0XFF;
    after_4:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001A924
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x29C($sp)
        MEM_W(0X29C, ctx->r29) = ctx->r2;
        goto L_8001A924;
    }
    // sw          $v0, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r2;
    // j           L_8001A93C
    // sw          $s3, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r19;
    goto L_8001A93C;
    // sw          $s3, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r19;
L_8001A924:
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // nop

    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lbu         $v0, 0x280($v0)
    ctx->r2 = MEM_BU(0X280, ctx->r2);
    // nop

    // sw          $v0, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r2;
L_8001A93C:
    // lw          $v0, 0x29C($sp)
    ctx->r2 = MEM_W(0X29C, ctx->r29);
    // nop

    // bne         $v0, $s3, L_8001A9A8
    if (ctx->r2 != ctx->r19) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001A9A8;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $sp, 0x298
    ctx->r6 = ADD32(ctx->r29, 0X298);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x29C
    ctx->r7 = ADD32(ctx->r29, 0X29C);
    ProcessListNavigation(rdram, ctx);
    goto after_5;
    // addiu       $a3, $sp, 0x29C
    ctx->r7 = ADD32(ctx->r29, 0X29C);
    after_5:
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // lw          $v1, 0x298($sp)
    ctx->r3 = MEM_W(0X298, ctx->r29);
    // sb          $v0, 0x79($gp)
    MEM_B(0X79, ctx->r28) = ctx->r2;
    // bne         $v1, $s4, L_8001A978
    if (ctx->r3 != ctx->r20) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001A978;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_6;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_6:
L_8001A978:
    // jal         0x800244E0
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    BeginDraw2D(rdram, ctx);
    goto after_7;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_7:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x800228B4
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    RenderItemList(rdram, ctx);
    goto after_8;
    // ori         $a1, $zero, 0x2
    ctx->r5 = 0 | 0X2;
    after_8:
    // jal         0x80024620
    // nop

    EndDraw2D(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001A978
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001A978;
    }
    // nop

    // j           L_8001A8C8
    // nop

    goto L_8001A8C8;
    // nop

L_8001A9A8:
    // lw          $v1, 0x29C($sp)
    ctx->r3 = MEM_W(0X29C, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8001A9BC
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $v1, 0x1000
        ctx->r2 = ctx->r3 | 0X1000;
        goto L_8001A9BC;
    }
    // ori         $v0, $v1, 0x1000
    ctx->r2 = ctx->r3 | 0X1000;
    // sw          $v0, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r2;
L_8001A9BC:
    // lw          $v0, 0x29C($sp)
    ctx->r2 = MEM_W(0X29C, ctx->r29);
    // lw          $ra, 0x2B4($sp)
    ctx->r31 = MEM_W(0X2B4, ctx->r29);
    // lw          $s4, 0x2B0($sp)
    ctx->r20 = MEM_W(0X2B0, ctx->r29);
    // lw          $s3, 0x2AC($sp)
    ctx->r19 = MEM_W(0X2AC, ctx->r29);
    // lw          $s2, 0x2A8($sp)
    ctx->r18 = MEM_W(0X2A8, ctx->r29);
    // lw          $s1, 0x2A4($sp)
    ctx->r17 = MEM_W(0X2A4, ctx->r29);
    // lw          $s0, 0x2A0($sp)
    ctx->r16 = MEM_W(0X2A0, ctx->r29);
    // addiu       $sp, $sp, 0x2B8
    ctx->r29 = ADD32(ctx->r29, 0X2B8);
    // jr          $ra
    // nop

    return;
    // nop

;}
