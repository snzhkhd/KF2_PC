#include "recomp.h"
#include "disable_warnings.h"

void sub_8001F9B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x530
    ctx->r29 = ADD32(ctx->r29, -0X530);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $ra, 0x528($sp)
    MEM_W(0X528, ctx->r29) = ctx->r31;
    // sw          $s5, 0x524($sp)
    MEM_W(0X524, ctx->r29) = ctx->r21;
    // sw          $s4, 0x520($sp)
    MEM_W(0X520, ctx->r29) = ctx->r20;
    // sw          $s3, 0x51C($sp)
    MEM_W(0X51C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x518($sp)
    MEM_W(0X518, ctx->r29) = ctx->r18;
    // sw          $s1, 0x514($sp)
    MEM_W(0X514, ctx->r29) = ctx->r17;
    // sw          $s0, 0x510($sp)
    MEM_W(0X510, ctx->r29) = ctx->r16;
    // sw          $zero, 0x508($sp)
    MEM_W(0X508, ctx->r29) = 0;
    // jal         0x800246CC
    // sw          $v0, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r2;
    SetupMenuUIBuffers(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r2;
    after_0:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x2A98
    ctx->r4 = ADD32(ctx->r4, -0X2A98);
    // addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addiu       $s2, $sp, 0x418
    ctx->r18 = ADD32(ctx->r29, 0X418);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $s0, $sp, 0x4E0
    ctx->r16 = ADD32(ctx->r29, 0X4E0);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
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
    // lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // addiu       $s5, $s5, -0x2190
    ctx->r21 = ADD32(ctx->r21, -0X2190);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $s3, $sp, 0x440
    ctx->r19 = ADD32(ctx->r29, 0X440);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // ori         $v0, $zero, 0x4
    ctx->r2 = 0 | 0X4;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8001F3F8
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    CollectBuyData(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // ori         $a1, $zero, 0x5
    ctx->r5 = 0 | 0X5;
    // jal         0x800249BC
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    InitListWidget(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_3:
    // lbu         $v1, 0x41($sp)
    ctx->r3 = MEM_BU(0X41, ctx->r29);
    // ori         $v0, $zero, 0x18
    ctx->r2 = 0 | 0X18;
    // sb          $s1, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r17;
    // sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // sb          $v0, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r2;
    // addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // lbu         $s0, 0x0($s0)
    ctx->r16 = MEM_BU(0X0, ctx->r16);
    // jal         0x80024CAC
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    Draw3dPreview(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // bne         $v0, $zero, L_8001FD00
    if (ctx->r2 != 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_8001FD00;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8001FA94:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lbu         $v0, 0x3E($sp)
    ctx->r2 = MEM_BU(0X3E, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001FAB8
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_8001FAB8;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // jal         0x80023388
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_6;
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_6:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_8001FAB8:
    // jal         0x800228B4
    // ori         $a1, $zero, 0xF
    ctx->r5 = 0 | 0XF;
    RenderItemList(rdram, ctx);
    goto after_7;
    // ori         $a1, $zero, 0xF
    ctx->r5 = 0 | 0XF;
    after_7:
    // jal         0x80024620
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_8;
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_8:
    // slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001FA94
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001FA94;
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
    // addiu       $s2, $sp, 0x4E0
    ctx->r18 = ADD32(ctx->r29, 0X4E0);
L_8001FAEC:
    // lw          $v0, 0x508($sp)
    ctx->r2 = MEM_W(0X508, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001FB0C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001FB0C;
    }
    // nop

    // lw          $v0, 0x50C($sp)
    ctx->r2 = MEM_W(0X50C, ctx->r29);
    // nop

    // beq         $v0, $s3, L_8001FB14
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_8001FB14;
    }
    // nop

L_8001FB0C:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_11;
    // nop

    after_11:
L_8001FB14:
    // lw          $v0, 0x508($sp)
    ctx->r2 = MEM_W(0X508, ctx->r29);
    // nop

    // bne         $v0, $s4, L_8001FB50
    if (ctx->r2 != ctx->r20) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_8001FB50;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // ori         $a1, $zero, 0x9
    ctx->r5 = 0 | 0X9;
    // ori         $a2, $zero, 0xF
    ctx->r6 = 0 | 0XF;
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // jal         0x80022468
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    ShowEquipmentMenu(rdram, ctx);
    goto after_12;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_12:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8001FB4C
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x50C($sp)
        MEM_W(0X50C, ctx->r29) = ctx->r2;
        goto L_8001FB4C;
    }
    // sw          $v0, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r2;
    // j           L_8001FB50
    // sw          $s3, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r19;
    goto L_8001FB50;
    // sw          $s3, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r19;
L_8001FB4C:
    // sw          $s0, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r16;
L_8001FB50:
    // lw          $v0, 0x50C($sp)
    ctx->r2 = MEM_W(0X50C, ctx->r29);
    // nop

    // bne         $v0, $s3, L_8001FC68
    if (ctx->r2 != ctx->r19) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_8001FC68;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $a2, $sp, 0x508
    ctx->r6 = ADD32(ctx->r29, 0X508);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x50C
    ctx->r7 = ADD32(ctx->r29, 0X50C);
    ProcessListNavigation(rdram, ctx);
    goto after_13;
    // addiu       $a3, $sp, 0x50C
    ctx->r7 = ADD32(ctx->r29, 0X50C);
    after_13:
    // lbu         $a0, 0x41($sp)
    ctx->r4 = MEM_BU(0X41, ctx->r29);
    // lw          $v1, 0x508($sp)
    ctx->r3 = MEM_W(0X508, ctx->r29);
    // addu        $v0, $s2, $a0
    ctx->r2 = ADD32(ctx->r18, ctx->r4);
    // lbu         $s0, 0x0($v0)
    ctx->r16 = MEM_BU(0X0, ctx->r2);
    // bne         $v1, $s4, L_8001FC20
    if (ctx->r3 != ctx->r20) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_8001FC20;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(0X50, ctx->r29);
    // lw          $a0, 0x6C($gp)
    ctx->r4 = MEM_W(0X6C, ctx->r28);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0x60($s5)
    ctx->r2 = MEM_BU(0X60, ctx->r21);
    // mflo        $v1
    ctx->r3 = lo;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8001FC04
    if (ctx->r2 != 0) {
        // andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
        goto L_8001FC04;
    }
    // andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // ori         $v0, $zero, 0x75
    ctx->r2 = 0 | 0X75;
    // bne         $v1, $v0, L_8001FBEC
    if (ctx->r3 != ctx->r2) {
        // addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
        goto L_8001FBEC;
    }
    // addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // lbu         $v1, 0x75($s5)
    ctx->r3 = MEM_BU(0X75, ctx->r21);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slti        $v1, $v1, 0x64
    ctx->r3 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // beq         $v1, $zero, L_8001FC04
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8001FC04;
    }
    // nop

    // j           L_8001FC14
    // nop

    goto L_8001FC14;
    // nop

L_8001FBEC:
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // slti        $v0, $v0, 0x64
    ctx->r2 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // bne         $v0, $zero, L_8001FC14
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001FC14;
    }
    // nop

L_8001FC04:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_14;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_14:
    // j           L_8001FC1C
    // sw          $zero, 0x508($sp)
    MEM_W(0X508, ctx->r29) = 0;
    goto L_8001FC1C;
    // sw          $zero, 0x508($sp)
    MEM_W(0X508, ctx->r29) = 0;
L_8001FC14:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_15;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_15:
L_8001FC1C:
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8001FC20:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // lbu         $v0, 0x3E($sp)
    ctx->r2 = MEM_BU(0X3E, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8001FC44
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_8001FC44;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // jal         0x80023388
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_17;
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_17:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_8001FC44:
    // jal         0x800228B4
    // ori         $a1, $zero, 0xF
    ctx->r5 = 0 | 0XF;
    RenderItemList(rdram, ctx);
    goto after_18;
    // ori         $a1, $zero, 0xF
    ctx->r5 = 0 | 0XF;
    after_18:
    // jal         0x80024620
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_19;
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_19:
    // slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8001FC20
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001FC20;
    }
    // nop

    // j           L_8001FAEC
    // nop

    goto L_8001FAEC;
    // nop

L_8001FC68:
    // jal         0x80024D70
    // nop

    Flush3dRender(rdram, ctx);
    goto after_20;
    // nop

    after_20:
    // lw          $v1, 0x50C($sp)
    ctx->r3 = MEM_W(0X50C, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8001FCF8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8001FCF8;
    }
    // nop

    // lbu         $v0, 0x41($sp)
    ctx->r2 = MEM_BU(0X41, ctx->r29);
    // lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(0X50, ctx->r29);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lw          $v0, 0x6C($gp)
    ctx->r2 = MEM_W(0X6C, ctx->r28);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0x60($s5)
    ctx->r2 = MEM_BU(0X60, ctx->r21);
    // mflo        $v1
    ctx->r3 = lo;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sb          $v0, 0x60($s5)
    MEM_B(0X60, ctx->r21) = ctx->r2;
    // lw          $v1, 0x50C($sp)
    ctx->r3 = MEM_W(0X50C, ctx->r29);
    // ori         $v0, $zero, 0x75
    ctx->r2 = 0 | 0X75;
    // bne         $v1, $v0, L_8001FCE4
    if (ctx->r3 != ctx->r2) {
        // addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
        goto L_8001FCE4;
    }
    // addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // lw          $v0, 0x6C($gp)
    ctx->r2 = MEM_W(0X6C, ctx->r28);
    // nop

    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x75($s5)
    ctx->r2 = MEM_BU(0X75, ctx->r21);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8001FCF8
    // sb          $v0, 0x75($s5)
    MEM_B(0X75, ctx->r21) = ctx->r2;
    goto L_8001FCF8;
    // sb          $v0, 0x75($s5)
    MEM_B(0X75, ctx->r21) = ctx->r2;
L_8001FCE4:
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // lbu         $a0, 0x6C($gp)
    ctx->r4 = MEM_BU(0X6C, ctx->r28);
    // nop

    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8001FCF8:
    // jal         0x80024820
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    Music_UpdateState(rdram, ctx);
    goto after_21;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_21:
L_8001FD00:
    // lw          $ra, 0x528($sp)
    ctx->r31 = MEM_W(0X528, ctx->r29);
    // lw          $s5, 0x524($sp)
    ctx->r21 = MEM_W(0X524, ctx->r29);
    // lw          $s4, 0x520($sp)
    ctx->r20 = MEM_W(0X520, ctx->r29);
    // lw          $s3, 0x51C($sp)
    ctx->r19 = MEM_W(0X51C, ctx->r29);
    // lw          $s2, 0x518($sp)
    ctx->r18 = MEM_W(0X518, ctx->r29);
    // lw          $s1, 0x514($sp)
    ctx->r17 = MEM_W(0X514, ctx->r29);
    // lw          $s0, 0x510($sp)
    ctx->r16 = MEM_W(0X510, ctx->r29);
    // addiu       $sp, $sp, 0x530
    ctx->r29 = ADD32(ctx->r29, 0X530);
    // jr          $ra
    // nop

    return;
    // nop

;}
