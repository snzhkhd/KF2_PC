#include "recomp.h"
#include "disable_warnings.h"

void LOCKSMITH_CopyKey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x530
    ctx->r29 = ADD32(ctx->r29, -0X530);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x2A20
    ctx->r4 = ADD32(ctx->r4, -0X2A20);
    // sw          $s3, 0x51C($sp)
    MEM_W(0X51C, ctx->r29) = ctx->r19;
    // addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // sw          $s1, 0x514($sp)
    MEM_W(0X514, ctx->r29) = ctx->r17;
    // addiu       $s1, $sp, 0x418
    ctx->r17 = ADD32(ctx->r29, 0X418);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sw          $s5, 0x524($sp)
    MEM_W(0X524, ctx->r29) = ctx->r21;
    // addiu       $s5, $sp, 0x4E0
    ctx->r21 = ADD32(ctx->r29, 0X4E0);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // addiu       $v0, $zero, -0x63
    ctx->r2 = ADD32(0, -0X63);
    // sw          $v0, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x77
    ctx->r2 = 0 | 0X77;
    // sw          $ra, 0x52C($sp)
    MEM_W(0X52C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x528($sp)
    MEM_W(0X528, ctx->r29) = ctx->r22;
    // sw          $s4, 0x520($sp)
    MEM_W(0X520, ctx->r29) = ctx->r20;
    // sw          $s2, 0x518($sp)
    MEM_W(0X518, ctx->r29) = ctx->r18;
    // sw          $s0, 0x510($sp)
    MEM_W(0X510, ctx->r29) = ctx->r16;
    // sw          $zero, 0x508($sp)
    MEM_W(0X508, ctx->r29) = 0;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80019CD0
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    GetInventoryItems(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_0:
    // lui         $s6, 0x800A
    ctx->r22 = S32(0X800A << 16);
    // addiu       $s6, $s6, -0x2190
    ctx->r22 = ADD32(ctx->r22, -0X2190);
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $s2, $sp, 0x440
    ctx->r18 = ADD32(ctx->r29, 0X440);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // ori         $v0, $zero, 0x5
    ctx->r2 = 0 | 0X5;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // jal         0x8001F3F8
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    CollectBuyData(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // ori         $a1, $zero, 0x4
    ctx->r5 = 0 | 0X4;
    // jal         0x800249BC
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    InitListWidget(rdram, ctx);
    goto after_2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // lbu         $v0, 0x41($sp)
    ctx->r2 = MEM_BU(0X41, ctx->r29);
    // ori         $v1, $zero, 0x18
    ctx->r3 = 0 | 0X18;
    // sb          $s0, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r16;
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // sb          $v1, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r3;
    // addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(0X0, ctx->r2);
    // jal         0x80024CAC
    // nop

    Draw3dPreview(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // bne         $v0, $zero, L_8002012C
    if (ctx->r2 != 0) {
        // addiu       $s2, $zero, -0x63
        ctx->r18 = ADD32(0, -0X63);
        goto L_8002012C;
    }
    // addiu       $s2, $zero, -0x63
    ctx->r18 = ADD32(0, -0X63);
    // ori         $s3, $zero, 0x1
    ctx->r19 = 0 | 0X1;
    // addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
L_8001FF78:
    // lw          $v0, 0x508($sp)
    ctx->r2 = MEM_W(0X508, ctx->r29);
    // nop

    // bne         $v0, $zero, L_8001FF98
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001FF98;
    }
    // nop

    // lw          $v0, 0x50C($sp)
    ctx->r2 = MEM_W(0X50C, ctx->r29);
    // nop

    // beq         $v0, $s2, L_8001FFA0
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_8001FFA0;
    }
    // nop

L_8001FF98:
    // jal         0x80024ED4
    // nop

    WaitForButtonRelease(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8001FFA0:
    // lw          $v0, 0x508($sp)
    ctx->r2 = MEM_W(0X508, ctx->r29);
    // nop

    // bne         $v0, $s3, L_8001FFDC
    if (ctx->r2 != ctx->r19) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_8001FFDC;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // ori         $a1, $zero, 0x3
    ctx->r5 = 0 | 0X3;
    // ori         $a2, $zero, 0xD
    ctx->r6 = 0 | 0XD;
    // andi        $s0, $s4, 0xFF
    ctx->r16 = ctx->r20 & 0XFF;
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
    // bne         $v0, $v1, L_8001FFD8
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x50C($sp)
        MEM_W(0X50C, ctx->r29) = ctx->r2;
        goto L_8001FFD8;
    }
    // sw          $v0, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r2;
    // j           L_8001FFDC
    // sw          $s2, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r18;
    goto L_8001FFDC;
    // sw          $s2, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r18;
L_8001FFD8:
    // sw          $s0, 0x50C($sp)
    MEM_W(0X50C, ctx->r29) = ctx->r16;
L_8001FFDC:
    // lw          $v0, 0x50C($sp)
    ctx->r2 = MEM_W(0X50C, ctx->r29);
    // nop

    // bne         $v0, $s2, L_800200C4
    if (ctx->r2 != ctx->r18) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_800200C4;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $a2, $sp, 0x508
    ctx->r6 = ADD32(ctx->r29, 0X508);
    // jal         0x80020578
    // addiu       $a3, $sp, 0x50C
    ctx->r7 = ADD32(ctx->r29, 0X50C);
    ProcessListNavigation(rdram, ctx);
    goto after_6;
    // addiu       $a3, $sp, 0x50C
    ctx->r7 = ADD32(ctx->r29, 0X50C);
    after_6:
    // lbu         $a0, 0x41($sp)
    ctx->r4 = MEM_BU(0X41, ctx->r29);
    // lw          $v1, 0x508($sp)
    ctx->r3 = MEM_W(0X508, ctx->r29);
    // addu        $v0, $s1, $a0
    ctx->r2 = ADD32(ctx->r17, ctx->r4);
    // lbu         $s4, 0x0($v0)
    ctx->r20 = MEM_BU(0X0, ctx->r2);
    // bne         $v1, $s3, L_8002007C
    if (ctx->r3 != ctx->r19) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8002007C;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
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
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x4B10($v0)
    ctx->r2 = MEM_W(-0X4B10, ctx->r2);
    // mflo        $v1
    ctx->r3 = lo;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80020060
    if (ctx->r2 != 0) {
        // addu        $v0, $s4, $s6
        ctx->r2 = ADD32(ctx->r20, ctx->r22);
        goto L_80020060;
    }
    // addu        $v0, $s4, $s6
    ctx->r2 = ADD32(ctx->r20, ctx->r22);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // slti        $v0, $v0, 0x64
    ctx->r2 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // bne         $v0, $zero, L_80020070
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80020070;
    }
    // nop

L_80020060:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    PlaySfx(rdram, ctx);
    goto after_7;
    // ori         $a0, $zero, 0x12
    ctx->r4 = 0 | 0X12;
    after_7:
    // j           L_8002007C
    // sw          $zero, 0x508($sp)
    MEM_W(0X508, ctx->r29) = 0;
    goto L_8002007C;
    // sw          $zero, 0x508($sp)
    MEM_W(0X508, ctx->r29) = 0;
L_80020070:
    // jal         0x80024DA8
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    PlaySfx(rdram, ctx);
    goto after_8;
    // ori         $a0, $zero, 0x11
    ctx->r4 = 0 | 0X11;
    after_8:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8002007C:
    // jal         0x800244E0
    // nop

    BeginDraw2D(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lbu         $v0, 0x3E($sp)
    ctx->r2 = MEM_BU(0X3E, ctx->r29);
    // nop

    // beq         $v0, $zero, L_800200A0
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_800200A0;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // jal         0x80023388
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    Update3dPreview(rdram, ctx);
    goto after_10;
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    after_10:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_800200A0:
    // jal         0x800228B4
    // ori         $a1, $zero, 0xD
    ctx->r5 = 0 | 0XD;
    RenderItemList(rdram, ctx);
    goto after_11;
    // ori         $a1, $zero, 0xD
    ctx->r5 = 0 | 0XD;
    after_11:
    // jal         0x80024620
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    EndDraw2D(rdram, ctx);
    goto after_12;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_12:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8002007C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002007C;
    }
    // nop

    // j           L_8001FF78
    // nop

    goto L_8001FF78;
    // nop

L_800200C4:
    // jal         0x80024D70
    // nop

    Flush3dRender(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lw          $a1, 0x50C($sp)
    ctx->r5 = MEM_W(0X50C, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a1, $v0, L_8002012C
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_8002012C;
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
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x4B10
    ctx->r4 = ADD32(ctx->r4, -0X4B10);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // addu        $a0, $s6, $a1
    ctx->r4 = ADD32(ctx->r22, ctx->r5);
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // lbu         $v1, 0x6C($gp)
    ctx->r3 = MEM_BU(0X6C, ctx->r28);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8002012C:
    // lw          $ra, 0x52C($sp)
    ctx->r31 = MEM_W(0X52C, ctx->r29);
    // lw          $s6, 0x528($sp)
    ctx->r22 = MEM_W(0X528, ctx->r29);
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
