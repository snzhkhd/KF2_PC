#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"

void KF_StoreImage(uint8_t* rdram, recomp_context* ctx)
{
    printf("KF_StoreImage\n");
    RECT16* rect = (RECT16*)GET_PTR(ctx->r4);      // a0: Область VRAM (X, Y, W, H)
    u_long* p = (u_long*)GET_PTR(ctx->r5);  // a1: Куда сохранить в RAM

    // Вызываем нативный StoreImage из Psy-X
    StoreImage(rect, p);
    ctx->pc = ctx->r31;
    return;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x38
//    ctx->r29 = ADD32(ctx->r29, -0X38);
//    // sw          $s1, 0x24($sp)
//    MEM_W(0X24, ctx->r29) = ctx->r17;
//    // addu        $s1, $a0, $zero
//    ctx->r17 = ADD32(ctx->r4, 0);
//    // sw          $s2, 0x28($sp)
//    MEM_W(0X28, ctx->r29) = ctx->r18;
//    // addu        $s2, $a1, $zero
//    ctx->r18 = ADD32(ctx->r5, 0);
//    // sw          $ra, 0x34($sp)
//    MEM_W(0X34, ctx->r29) = ctx->r31;
//    // sw          $s4, 0x30($sp)
//    MEM_W(0X30, ctx->r29) = ctx->r20;
//    // sw          $s3, 0x2C($sp)
//    MEM_W(0X2C, ctx->r29) = ctx->r19;
//    // jal         0x800655A8
//    // sw          $s0, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r16;
//    SyncVSyncStatus(rdram, ctx);
//    goto after_0;
//    // sw          $s0, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r16;
//    after_0:
//    // lh          $a0, 0x4($s1)
//    ctx->r4 = MEM_H(0X4, ctx->r17);
//    // nop
//
//    // bltz        $a0, L_800649B4
//    if (SIGNED(ctx->r4) < 0) {
//        // addu        $v1, $a0, $zero
//        ctx->r3 = ADD32(ctx->r4, 0);
//        goto L_800649B4;
//    }
//    // addu        $v1, $a0, $zero
//    ctx->r3 = ADD32(ctx->r4, 0);
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // addiu       $a1, $a1, 0x61A4
//    ctx->r5 = ADD32(ctx->r5, 0X61A4);
//    // lhu         $v0, 0x0($a1)
//    ctx->r2 = MEM_HU(0X0, ctx->r5);
//    // nop
//
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // slt         $v0, $v0, $a0
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
//    // beq         $v0, $zero, L_800649B8
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_800649B8;
//    }
//    // nop
//
//    // lhu         $v1, 0x0($a1)
//    ctx->r3 = MEM_HU(0X0, ctx->r5);
//    // j           L_800649B8
//    // nop
//
//    goto L_800649B8;
//    // nop
//
//L_800649B4:
//    // addu        $v1, $zero, $zero
//    ctx->r3 = ADD32(0, 0);
//L_800649B8:
//    // lh          $a1, 0x6($s1)
//    ctx->r5 = MEM_H(0X6, ctx->r17);
//    // sh          $v1, 0x4($s1)
//    MEM_H(0X4, ctx->r17) = ctx->r3;
//    // bltz        $a1, L_800649F8
//    if (SIGNED(ctx->r5) < 0) {
//        // addu        $v1, $a1, $zero
//        ctx->r3 = ADD32(ctx->r5, 0);
//        goto L_800649F8;
//    }
//    // addu        $v1, $a1, $zero
//    ctx->r3 = ADD32(ctx->r5, 0);
//    // lui         $a2, 0x8007
//    ctx->r6 = S32(0X8007 << 16);
//    // addiu       $a2, $a2, 0x61A6
//    ctx->r6 = ADD32(ctx->r6, 0X61A6);
//    // lhu         $v0, 0x0($a2)
//    ctx->r2 = MEM_HU(0X0, ctx->r6);
//    // nop
//
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // slt         $v0, $v0, $a1
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
//    // beq         $v0, $zero, L_800649FC
//    if (ctx->r2 == 0) {
//        // addu        $a0, $v1, $zero
//        ctx->r4 = ADD32(ctx->r3, 0);
//        goto L_800649FC;
//    }
//    // addu        $a0, $v1, $zero
//    ctx->r4 = ADD32(ctx->r3, 0);
//    // lhu         $a0, 0x0($a2)
//    ctx->r4 = MEM_HU(0X0, ctx->r6);
//    // j           L_80064A00
//    // sll         $v0, $a0, 16
//    ctx->r2 = S32(ctx->r4) << 16;
//    goto L_80064A00;
//    // sll         $v0, $a0, 16
//    ctx->r2 = S32(ctx->r4) << 16;
//L_800649F8:
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//L_800649FC:
//    // sll         $v0, $a0, 16
//    ctx->r2 = S32(ctx->r4) << 16;
//L_80064A00:
//    // lh          $v1, 0x4($s1)
//    ctx->r3 = MEM_H(0X4, ctx->r17);
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // mult        $v1, $v0
//    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
//    // sh          $a0, 0x6($s1)
//    MEM_H(0X6, ctx->r17) = ctx->r4;
//    // mflo        $v0
//    ctx->r2 = lo;
//    // addiu       $v0, $v0, 0x1
//    ctx->r2 = ADD32(ctx->r2, 0X1);
//    // srl         $v1, $v0, 31
//    ctx->r3 = S32(U32(ctx->r2) >> 31);
//    // addu        $v0, $v0, $v1
//    ctx->r2 = ADD32(ctx->r2, ctx->r3);
//    // sra         $a0, $v0, 1
//    ctx->r4 = S32(ctx->r2) >> 1;
//    // bgtz        $a0, L_80064A34
//    if (SIGNED(ctx->r4) > 0) {
//        // sra         $s0, $v0, 5
//        ctx->r16 = S32(ctx->r2) >> 5;
//        goto L_80064A34;
//    }
//    // sra         $s0, $v0, 5
//    ctx->r16 = S32(ctx->r2) >> 5;
//    // j           L_80064BC4
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    goto L_80064BC4;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//L_80064A34:
//    // addu        $v1, $s0, $zero
//    ctx->r3 = ADD32(ctx->r16, 0);
//    // sll         $v0, $v1, 4
//    ctx->r2 = S32(ctx->r3) << 4;
//    // subu        $s0, $a0, $v0
//    ctx->r16 = SUB32(ctx->r4, ctx->r2);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6274($v0)
//    ctx->r2 = MEM_W(0X6274, ctx->r2);
//    // addu        $s4, $v1, $zero
//    ctx->r20 = ADD32(ctx->r3, 0);
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // lui         $v1, 0x400
//    ctx->r3 = S32(0X400 << 16);
//    // and         $v0, $v0, $v1
//    ctx->r2 = ctx->r2 & ctx->r3;
//    // bne         $v0, $zero, L_80064A94
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_80064A94;
//    }
//    // nop
//
//    // lui         $s3, 0x400
//    ctx->r19 = S32(0X400 << 16);
//L_80064A64:
//    // jal         0x800655DC
//    // nop
//
//    GPU_CheckTimeout_800655DC(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // bne         $v0, $zero, L_80064BC4
//    if (ctx->r2 != 0) {
//        // addiu       $v0, $zero, -0x1
//        ctx->r2 = ADD32(0, -0X1);
//        goto L_80064BC4;
//    }
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6274($v0)
//    ctx->r2 = MEM_W(0X6274, ctx->r2);
//    // nop
//
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // nop
//
//    // and         $v0, $v0, $s3
//    ctx->r2 = ctx->r2 & ctx->r19;
//    // beq         $v0, $zero, L_80064A64
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80064A64;
//    }
//    // nop
//
//L_80064A94:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6274($v1)
//    ctx->r3 = MEM_W(0X6274, ctx->r3);
//    // lui         $v0, 0x400
//    ctx->r2 = S32(0X400 << 16);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6270($v1)
//    ctx->r3 = MEM_W(0X6270, ctx->r3);
//    // lui         $v0, 0x100
//    ctx->r2 = S32(0X100 << 16);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6270($v1)
//    ctx->r3 = MEM_W(0X6270, ctx->r3);
//    // lui         $v0, 0xC000
//    ctx->r2 = S32(0XC000 << 16);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6270($v1)
//    ctx->r3 = MEM_W(0X6270, ctx->r3);
//    // lw          $v0, 0x0($s1)
//    ctx->r2 = MEM_W(0X0, ctx->r17);
//    // nop
//
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6270($v1)
//    ctx->r3 = MEM_W(0X6270, ctx->r3);
//    // lw          $v0, 0x4($s1)
//    ctx->r2 = MEM_W(0X4, ctx->r17);
//    // nop
//
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6274($v0)
//    ctx->r2 = MEM_W(0X6274, ctx->r2);
//    // nop
//
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // lui         $v1, 0x800
//    ctx->r3 = S32(0X800 << 16);
//    // and         $v0, $v0, $v1
//    ctx->r2 = ctx->r2 & ctx->r3;
//    // bne         $v0, $zero, L_80064B40
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_80064B40;
//    }
//    // nop
//
//    // lui         $s1, 0x800
//    ctx->r17 = S32(0X800 << 16);
//L_80064B10:
//    // jal         0x800655DC
//    // nop
//
//    GPU_CheckTimeout_800655DC(rdram, ctx);
//    goto after_2;
//    // nop
//
//    after_2:
//    // bne         $v0, $zero, L_80064BC4
//    if (ctx->r2 != 0) {
//        // addiu       $v0, $zero, -0x1
//        ctx->r2 = ADD32(0, -0X1);
//        goto L_80064BC4;
//    }
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6274($v0)
//    ctx->r2 = MEM_W(0X6274, ctx->r2);
//    // nop
//
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // nop
//
//    // and         $v0, $v0, $s1
//    ctx->r2 = ctx->r2 & ctx->r17;
//    // beq         $v0, $zero, L_80064B10
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80064B10;
//    }
//    // nop
//
//L_80064B40:
//    // addiu       $s0, $s0, -0x1
//    ctx->r16 = ADD32(ctx->r16, -0X1);
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // beq         $s0, $v0, L_80064B74
//    if (ctx->r16 == ctx->r2) {
//        // nop
//    
//        goto L_80064B74;
//    }
//    // nop
//
//    // addiu       $v1, $zero, -0x1
//    ctx->r3 = ADD32(0, -0X1);
//L_80064B54:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6270($v0)
//    ctx->r2 = MEM_W(0X6270, ctx->r2);
//    // nop
//
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // addiu       $s0, $s0, -0x1
//    ctx->r16 = ADD32(ctx->r16, -0X1);
//    // sw          $v0, 0x0($s2)
//    MEM_W(0X0, ctx->r18) = ctx->r2;
//    // bne         $s0, $v1, L_80064B54
//    if (ctx->r16 != ctx->r3) {
//        // addiu       $s2, $s2, 0x4
//        ctx->r18 = ADD32(ctx->r18, 0X4);
//        goto L_80064B54;
//    }
//    // addiu       $s2, $s2, 0x4
//    ctx->r18 = ADD32(ctx->r18, 0X4);
//L_80064B74:
//    // beq         $s4, $zero, L_80064BC0
//    if (ctx->r20 == 0) {
//        // lui         $v1, 0x400
//        ctx->r3 = S32(0X400 << 16);
//        goto L_80064BC0;
//    }
//    // lui         $v1, 0x400
//    ctx->r3 = S32(0X400 << 16);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6274($v0)
//    ctx->r2 = MEM_W(0X6274, ctx->r2);
//    // ori         $v1, $v1, 0x3
//    ctx->r3 = ctx->r3 | 0X3;
//    // sw          $v1, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r3;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6278($v0)
//    ctx->r2 = MEM_W(0X6278, ctx->r2);
//    // lui         $a0, 0x100
//    ctx->r4 = S32(0X100 << 16);
//    // sw          $s2, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r18;
//    // sll         $v0, $s4, 16
//    ctx->r2 = S32(ctx->r20) << 16;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x627C($v1)
//    ctx->r3 = MEM_W(0X627C, ctx->r3);
//    // ori         $v0, $v0, 0x10
//    ctx->r2 = ctx->r2 | 0X10;
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6280($v0)
//    ctx->r2 = MEM_W(0X6280, ctx->r2);
//    // ori         $a0, $a0, 0x200
//    ctx->r4 = ctx->r4 | 0X200;
//    // sw          $a0, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r4;
//L_80064BC0:
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_80064BC4:
//    // lw          $ra, 0x34($sp)
//    ctx->r31 = MEM_W(0X34, ctx->r29);
//    // lw          $s4, 0x30($sp)
//    ctx->r20 = MEM_W(0X30, ctx->r29);
//    // lw          $s3, 0x2C($sp)
//    ctx->r19 = MEM_W(0X2C, ctx->r29);
//    // lw          $s2, 0x28($sp)
//    ctx->r18 = MEM_W(0X28, ctx->r29);
//    // lw          $s1, 0x24($sp)
//    ctx->r17 = MEM_W(0X24, ctx->r29);
//    // lw          $s0, 0x20($sp)
//    ctx->r16 = MEM_W(0X20, ctx->r29);
//    // addiu       $sp, $sp, 0x38
//    ctx->r29 = ADD32(ctx->r29, 0X38);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
