#include "recomp.h"
#include "disable_warnings.h"

void DropMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xCA8
    ctx->r29 = ADD32(ctx->r29, -0XCA8);
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x2190
    ctx->r4 = ADD32(ctx->r4, -0X2190);
    // sw          $s2, 0xC90($sp)
    MEM_W(0XC90, ctx->r29) = ctx->r18;
    // addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // sw          $s1, 0xC8C($sp)
    MEM_W(0XC8C, ctx->r29) = ctx->r17;
    // addiu       $s1, $sp, 0xB90
    ctx->r17 = ADD32(ctx->r29, 0XB90);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sw          $s3, 0xC94($sp)
    MEM_W(0XC94, ctx->r29) = ctx->r19;
    // addiu       $s3, $sp, 0xC08
    ctx->r19 = ADD32(ctx->r29, 0XC08);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x77
    ctx->r2 = 0 | 0X77;
    // sw          $ra, 0xCA0($sp)
    MEM_W(0XCA0, ctx->r29) = ctx->r31;
    // sw          $s5, 0xC9C($sp)
    MEM_W(0XC9C, ctx->r29) = ctx->r21;
    // sw          $s4, 0xC98($sp)
    MEM_W(0XC98, ctx->r29) = ctx->r20;
    // sw          $s0, 0xC88($sp)
    MEM_W(0XC88, ctx->r29) = ctx->r16;
    // sw          $zero, 0xC80($sp)
    MEM_W(0XC80, ctx->r29) = 0;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80019DD4
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    CollectEquippableItems(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x4
    ctx->r6 = 0 | 0X4;
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
    // lbu         $a1, 0x7A($gp)
    ctx->r5 = MEM_BU(0X7A, ctx->r28);
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

    // beq         $v0, $zero, L_8001BD60
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, -0x63
        ctx->r18 = ADD32(0, -0X63);
        goto L_8001BD60;
    }
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
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
    // bne         $v0, $zero, L_8001BE98
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001BE98;
    }
    // nop

L_8001BD60:
    // ori         $s5, $zero, 0x1
    ctx->r21 = 0 | 0X1;
    // addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
L_8001BD68:
    // lw          $v0, 0xC80($sp)
    ctx->r2 = MEM_W(0XC80, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001BD88
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001BD88;
    }
    // nop

    // lw          $v0, 0xC84($sp)
    ctx->r2 = MEM_W(0XC84, ctx->r29);
    // nop

    // beq         $v0, $s2, L_8001BD90
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_8001BD90;
    }
    // nop

L_8001BD88:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8001BD90:
    // lw          $v0, 0xC80($sp)
    ctx->r2 = MEM_W(0XC80, ctx->r29);
    // nop

    // bne         $v0, $s5, L_8001BDD4
    if (ctx->r2 != ctx->r21) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001BDD4;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(0X0, ctx->r2);
    // jal         0x80022468
    // ori         $a2, $zero, 0x7
    ctx->r6 = 0 | 0X7;
    ShowEquipmentMenu(rdram, ctx);
    goto after_5;
    // ori         $a2, $zero, 0x7
    ctx->r6 = 0 | 0X7;
    after_5:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001BDCC
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0xC84($sp)
        MEM_W(0XC84, ctx->r29) = ctx->r2;
        goto L_8001BDCC;
    }
    // sw          $v0, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r2;
    // j           L_8001BDD4
    // sw          $s2, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r18;
    goto L_8001BDD4;
    // sw          $s2, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r18;
L_8001BDCC:
    // andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // sw          $v0, 0xC84($sp)
    MEM_W(0XC84, ctx->r29) = ctx->r2;
L_8001BDD4:
    // lw          $v0, 0xC84($sp)
    ctx->r2 = MEM_W(0XC84, ctx->r29);
    // nop

    // bne         $v0, $s2, L_8001BE64
    if (ctx->r2 != ctx->r18) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001BE64;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $a2, $sp, 0xC80
    ctx->r6 = ADD32(ctx->r29, 0XC80);
    // jal         0x80020578
    // addiu       $a3, $sp, 0xC84
    ctx->r7 = ADD32(ctx->r29, 0XC84);
    ProcessListNavigation(rdram, ctx);
    goto after_6;
    // addiu       $a3, $sp, 0xC84
    ctx->r7 = ADD32(ctx->r29, 0XC84);
    after_6:
    // lbu         $v1, 0x39($sp)
    ctx->r3 = MEM_BU(0X39, ctx->r29);
    // lbu         $v0, 0x39($sp)
    ctx->r2 = MEM_BU(0X39, ctx->r29);
    // addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // sb          $v0, 0x7A($gp)
    MEM_B(0X7A, ctx->r28) = ctx->r2;
    // lw          $v0, 0xC80($sp)
    ctx->r2 = MEM_W(0XC80, ctx->r29);
    // lbu         $s4, 0x0($v1)
    ctx->r20 = MEM_BU(0X0, ctx->r3);
    // bne         $v0, $s5, L_8001BE1C
    if (ctx->r2 != ctx->r21) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8001BE1C;
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
L_8001BE1C:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lbu         $v0, 0x36($sp)
    ctx->r2 = MEM_BU(0X36, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001BE40
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001BE40;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80023388
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_9;
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    after_9:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_8001BE40:
    // jal         0x800228B4
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    RenderItemList(rdram, ctx);
    goto after_10;
    // ori         $a1, $zero, 0x7
    ctx->r5 = 0 | 0X7;
    after_10:
    // jal         0x80024620
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_11;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_11:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001BE1C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001BE1C;
    }
    // nop

    // j           L_8001BD68
    // nop

    goto L_8001BD68;
    // nop

L_8001BE64:
    // jal         0x80024D70
    // nop

    Flush3dRender(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lw          $a0, 0xC84($sp)
    ctx->r4 = MEM_W(0XC84, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_8001BE98
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_8001BE98;
    }
    // nop

    // lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // addiu       $v1, $v1, -0x2190
    ctx->r3 = ADD32(ctx->r3, -0X2190);
    // addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8001BE98:
    // lw          $ra, 0xCA0($sp)
    ctx->r31 = MEM_W(0XCA0, ctx->r29);
    // lw          $s5, 0xC9C($sp)
    ctx->r21 = MEM_W(0XC9C, ctx->r29);
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
    // addiu       $sp, $sp, 0xCA8
    ctx->r29 = ADD32(ctx->r29, 0XCA8);
    // jr          $ra
    // nop

    return;
    // nop

;}
