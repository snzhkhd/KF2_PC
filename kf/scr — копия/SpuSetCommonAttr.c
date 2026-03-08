#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libspu.h"

void KF_SpuSetCommonAttr(uint8_t* rdram, recomp_context* ctx)
{

    SpuCommonAttr* attr = (SpuCommonAttr*)GET_PTR(ctx->r4);

    if (attr) {
        SpuSetCommonAttr(attr);
    }
    ;
}


//void KF_SpuSetCommonAttr(uint8_t* rdram, recomp_context* ctx) 
//{
//
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lw          $t0, 0x0($a0)
//    ctx->r8 = MEM_W(0X0, ctx->r4);
//    // nop
//
//    // sltiu       $t1, $t0, 0x1
//    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
//    // bne         $t1, $zero, L_80054400
//    if (ctx->r9 != 0) {
//        // addiu       $sp, $sp, -0x10
//        ctx->r29 = ADD32(ctx->r29, -0X10);
//        goto L_80054400;
//    }
//    // addiu       $sp, $sp, -0x10
//    ctx->r29 = ADD32(ctx->r29, -0X10);
//    // andi        $v0, $t0, 0x1
//    ctx->r2 = ctx->r8 & 0X1;
//    // beq         $v0, $zero, L_800544B4
//    if (ctx->r2 == 0) {
//        // andi        $v0, $t0, 0x4
//        ctx->r2 = ctx->r8 & 0X4;
//        goto L_800544B4;
//    }
//    // andi        $v0, $t0, 0x4
//    ctx->r2 = ctx->r8 & 0X4;
//    // beq         $v0, $zero, L_80054468
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80054468;
//    }
//    // nop
//
//L_80054400:
//    // lh          $v1, 0x8($a0)
//    ctx->r3 = MEM_H(0X8, ctx->r4);
//    // nop
//
//    // sltiu       $v0, $v1, 0x8
//    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
//    // beq         $v0, $zero, L_80054468
//    if (ctx->r2 == 0) {
//        // sll         $v0, $v1, 2
//        ctx->r2 = S32(ctx->r3) << 2;
//        goto L_80054468;
//    }
//    // sll         $v0, $v1, 2
//    ctx->r2 = S32(ctx->r3) << 2;
//    // lui         $at, 0x8001
//    ctx->r1 = S32(0X8001 << 16);
//    // addiu       $at, $at, 0x325C
//    ctx->r1 = ADD32(ctx->r1, 0X325C);
//    // addu        $at, $at, $v0
//    gpr jr_addend_80054428 = ctx->r2;
//    ctx->r1 = ADD32(ctx->r1, ctx->r2);
//    // lw          $v0, 0x0($at)
//    // nop
//
//    // jr          $v0
//    // nop
//
//    switch (jr_addend_80054428 >> 2) {
//        case 0: goto L_80054468; break;
//        case 1: goto L_80054430; break;
//        case 2: goto L_80054438; break;
//        case 3: goto L_80054440; break;
//        case 4: goto L_80054448; break;
//        case 5: goto L_80054450; break;
//        case 6: goto L_80054458; break;
//        case 7: goto L_80054460; break;
//        default: switch_error(__func__, 0x80054428, 0x8001325C);
//    }
//    // nop
//
//L_80054430:
//    // j           L_80054470
//    // ori         $a1, $zero, 0x8000
//    ctx->r5 = 0 | 0X8000;
//    goto L_80054470;
//    // ori         $a1, $zero, 0x8000
//    ctx->r5 = 0 | 0X8000;
//L_80054438:
//    // j           L_80054470
//    // ori         $a1, $zero, 0x9000
//    ctx->r5 = 0 | 0X9000;
//    goto L_80054470;
//    // ori         $a1, $zero, 0x9000
//    ctx->r5 = 0 | 0X9000;
//L_80054440:
//    // j           L_80054470
//    // ori         $a1, $zero, 0xA000
//    ctx->r5 = 0 | 0XA000;
//    goto L_80054470;
//    // ori         $a1, $zero, 0xA000
//    ctx->r5 = 0 | 0XA000;
//L_80054448:
//    // j           L_80054470
//    // ori         $a1, $zero, 0xB000
//    ctx->r5 = 0 | 0XB000;
//    goto L_80054470;
//    // ori         $a1, $zero, 0xB000
//    ctx->r5 = 0 | 0XB000;
//L_80054450:
//    // j           L_80054470
//    // ori         $a1, $zero, 0xC000
//    ctx->r5 = 0 | 0XC000;
//    goto L_80054470;
//    // ori         $a1, $zero, 0xC000
//    ctx->r5 = 0 | 0XC000;
//L_80054458:
//    // j           L_80054470
//    // ori         $a1, $zero, 0xD000
//    ctx->r5 = 0 | 0XD000;
//    goto L_80054470;
//    // ori         $a1, $zero, 0xD000
//    ctx->r5 = 0 | 0XD000;
//L_80054460:
//    // j           L_80054470
//    // ori         $a1, $zero, 0xE000
//    ctx->r5 = 0 | 0XE000;
//    goto L_80054470;
//    // ori         $a1, $zero, 0xE000
//    ctx->r5 = 0 | 0XE000;
//L_80054468:
//    // lhu         $a3, 0x4($a0)
//    ctx->r7 = MEM_HU(0X4, ctx->r4);
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//L_80054470:
//    // beq         $a1, $zero, L_800544A4
//    if (ctx->r5 == 0) {
//        // andi        $v0, $a3, 0x7FFF
//        ctx->r2 = ctx->r7 & 0X7FFF;
//        goto L_800544A4;
//    }
//    // andi        $v0, $a3, 0x7FFF
//    ctx->r2 = ctx->r7 & 0X7FFF;
//    // lh          $a2, 0x4($a0)
//    ctx->r6 = MEM_H(0X4, ctx->r4);
//    // nop
//
//    // slti        $v0, $a2, 0x80
//    ctx->r2 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
//    // bne         $v0, $zero, L_80054494
//    if (ctx->r2 != 0) {
//        // addu        $v1, $a2, $zero
//        ctx->r3 = ADD32(ctx->r6, 0);
//        goto L_80054494;
//    }
//    // addu        $v1, $a2, $zero
//    ctx->r3 = ADD32(ctx->r6, 0);
//    // j           L_800544A0
//    // ori         $a3, $zero, 0x7F
//    ctx->r7 = 0 | 0X7F;
//    goto L_800544A0;
//    // ori         $a3, $zero, 0x7F
//    ctx->r7 = 0 | 0X7F;
//L_80054494:
//    // bgez        $a2, L_800544A0
//    if (SIGNED(ctx->r6) >= 0) {
//        // addu        $a3, $v1, $zero
//        ctx->r7 = ADD32(ctx->r3, 0);
//        goto L_800544A0;
//    }
//    // addu        $a3, $v1, $zero
//    ctx->r7 = ADD32(ctx->r3, 0);
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//L_800544A0:
//    // andi        $v0, $a3, 0x7FFF
//    ctx->r2 = ctx->r7 & 0X7FFF;
//L_800544A4:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x7CC($v1)
//    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
//    // or          $v0, $v0, $a1
//    ctx->r2 = ctx->r2 | ctx->r5;
//    // sh          $v0, 0x180($v1)
//    MEM_H(0X180, ctx->r3) = ctx->r2;
//L_800544B4:
//    // bne         $t1, $zero, L_800544CC
//    if (ctx->r9 != 0) {
//        // andi        $v0, $t0, 0x2
//        ctx->r2 = ctx->r8 & 0X2;
//        goto L_800544CC;
//    }
//    // andi        $v0, $t0, 0x2
//    ctx->r2 = ctx->r8 & 0X2;
//    // beq         $v0, $zero, L_80054580
//    if (ctx->r2 == 0) {
//        // andi        $v0, $t0, 0x8
//        ctx->r2 = ctx->r8 & 0X8;
//        goto L_80054580;
//    }
//    // andi        $v0, $t0, 0x8
//    ctx->r2 = ctx->r8 & 0X8;
//    // beq         $v0, $zero, L_80054534
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80054534;
//    }
//    // nop
//
//L_800544CC:
//    // lh          $v1, 0xA($a0)
//    ctx->r3 = MEM_H(0XA, ctx->r4);
//    // nop
//
//    // sltiu       $v0, $v1, 0x8
//    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
//    // beq         $v0, $zero, L_80054534
//    if (ctx->r2 == 0) {
//        // sll         $v0, $v1, 2
//        ctx->r2 = S32(ctx->r3) << 2;
//        goto L_80054534;
//    }
//    // sll         $v0, $v1, 2
//    ctx->r2 = S32(ctx->r3) << 2;
//    // lui         $at, 0x8001
//    ctx->r1 = S32(0X8001 << 16);
//    // addiu       $at, $at, 0x327C
//    ctx->r1 = ADD32(ctx->r1, 0X327C);
//    // addu        $at, $at, $v0
//    gpr jr_addend_800544F4 = ctx->r2;
//    ctx->r1 = ADD32(ctx->r1, ctx->r2);
//    // lw          $v0, 0x0($at)
//    // nop
//
//    // jr          $v0
//    // nop
//
//    switch (jr_addend_800544F4 >> 2) {
//        case 0: goto L_80054534; break;
//        case 1: goto L_800544FC; break;
//        case 2: goto L_80054504; break;
//        case 3: goto L_8005450C; break;
//        case 4: goto L_80054514; break;
//        case 5: goto L_8005451C; break;
//        case 6: goto L_80054524; break;
//        case 7: goto L_8005452C; break;
//        default: switch_error(__func__, 0x800544F4, 0x8001327C);
//    }
//    // nop
//
//L_800544FC:
//    // j           L_8005453C
//    // ori         $a1, $zero, 0x8000
//    ctx->r5 = 0 | 0X8000;
//    goto L_8005453C;
//    // ori         $a1, $zero, 0x8000
//    ctx->r5 = 0 | 0X8000;
//L_80054504:
//    // j           L_8005453C
//    // ori         $a1, $zero, 0x9000
//    ctx->r5 = 0 | 0X9000;
//    goto L_8005453C;
//    // ori         $a1, $zero, 0x9000
//    ctx->r5 = 0 | 0X9000;
//L_8005450C:
//    // j           L_8005453C
//    // ori         $a1, $zero, 0xA000
//    ctx->r5 = 0 | 0XA000;
//    goto L_8005453C;
//    // ori         $a1, $zero, 0xA000
//    ctx->r5 = 0 | 0XA000;
//L_80054514:
//    // j           L_8005453C
//    // ori         $a1, $zero, 0xB000
//    ctx->r5 = 0 | 0XB000;
//    goto L_8005453C;
//    // ori         $a1, $zero, 0xB000
//    ctx->r5 = 0 | 0XB000;
//L_8005451C:
//    // j           L_8005453C
//    // ori         $a1, $zero, 0xC000
//    ctx->r5 = 0 | 0XC000;
//    goto L_8005453C;
//    // ori         $a1, $zero, 0xC000
//    ctx->r5 = 0 | 0XC000;
//L_80054524:
//    // j           L_8005453C
//    // ori         $a1, $zero, 0xD000
//    ctx->r5 = 0 | 0XD000;
//    goto L_8005453C;
//    // ori         $a1, $zero, 0xD000
//    ctx->r5 = 0 | 0XD000;
//L_8005452C:
//    // j           L_8005453C
//    // ori         $a1, $zero, 0xE000
//    ctx->r5 = 0 | 0XE000;
//    goto L_8005453C;
//    // ori         $a1, $zero, 0xE000
//    ctx->r5 = 0 | 0XE000;
//L_80054534:
//    // lhu         $t2, 0x6($a0)
//    ctx->r10 = MEM_HU(0X6, ctx->r4);
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//L_8005453C:
//    // beq         $a1, $zero, L_80054570
//    if (ctx->r5 == 0) {
//        // andi        $v0, $t2, 0x7FFF
//        ctx->r2 = ctx->r10 & 0X7FFF;
//        goto L_80054570;
//    }
//    // andi        $v0, $t2, 0x7FFF
//    ctx->r2 = ctx->r10 & 0X7FFF;
//    // lh          $a2, 0x6($a0)
//    ctx->r6 = MEM_H(0X6, ctx->r4);
//    // nop
//
//    // slti        $v0, $a2, 0x80
//    ctx->r2 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
//    // bne         $v0, $zero, L_80054560
//    if (ctx->r2 != 0) {
//        // addu        $v1, $a2, $zero
//        ctx->r3 = ADD32(ctx->r6, 0);
//        goto L_80054560;
//    }
//    // addu        $v1, $a2, $zero
//    ctx->r3 = ADD32(ctx->r6, 0);
//    // j           L_8005456C
//    // ori         $t2, $zero, 0x7F
//    ctx->r10 = 0 | 0X7F;
//    goto L_8005456C;
//    // ori         $t2, $zero, 0x7F
//    ctx->r10 = 0 | 0X7F;
//L_80054560:
//    // bgez        $a2, L_8005456C
//    if (SIGNED(ctx->r6) >= 0) {
//        // addu        $t2, $v1, $zero
//        ctx->r10 = ADD32(ctx->r3, 0);
//        goto L_8005456C;
//    }
//    // addu        $t2, $v1, $zero
//    ctx->r10 = ADD32(ctx->r3, 0);
//    // addu        $t2, $zero, $zero
//    ctx->r10 = ADD32(0, 0);
//L_8005456C:
//    // andi        $v0, $t2, 0x7FFF
//    ctx->r2 = ctx->r10 & 0X7FFF;
//L_80054570:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x7CC($v1)
//    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
//    // or          $v0, $v0, $a1
//    ctx->r2 = ctx->r2 | ctx->r5;
//    // sh          $v0, 0x182($v1)
//    MEM_H(0X182, ctx->r3) = ctx->r2;
//L_80054580:
//    // bne         $t1, $zero, L_80054590
//    if (ctx->r9 != 0) {
//        // andi        $v0, $t0, 0x40
//        ctx->r2 = ctx->r8 & 0X40;
//        goto L_80054590;
//    }
//    // andi        $v0, $t0, 0x40
//    ctx->r2 = ctx->r8 & 0X40;
//    // beq         $v0, $zero, L_800545A4
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_800545A4;
//    }
//    // nop
//
//L_80054590:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x7CC($v1)
//    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
//    // lhu         $v0, 0x10($a0)
//    ctx->r2 = MEM_HU(0X10, ctx->r4);
//    // nop
//
//    // sh          $v0, 0x1B0($v1)
//    MEM_H(0X1B0, ctx->r3) = ctx->r2;
//L_800545A4:
//    // bne         $t1, $zero, L_800545B4
//    if (ctx->r9 != 0) {
//        // andi        $v0, $t0, 0x80
//        ctx->r2 = ctx->r8 & 0X80;
//        goto L_800545B4;
//    }
//    // andi        $v0, $t0, 0x80
//    ctx->r2 = ctx->r8 & 0X80;
//    // beq         $v0, $zero, L_800545C8
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_800545C8;
//    }
//    // nop
//
//L_800545B4:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x7CC($v1)
//    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
//    // lhu         $v0, 0x12($a0)
//    ctx->r2 = MEM_HU(0X12, ctx->r4);
//    // nop
//
//    // sh          $v0, 0x1B2($v1)
//    MEM_H(0X1B2, ctx->r3) = ctx->r2;
//L_800545C8:
//    // bne         $t1, $zero, L_800545D8
//    if (ctx->r9 != 0) {
//        // andi        $v0, $t0, 0x100
//        ctx->r2 = ctx->r8 & 0X100;
//        goto L_800545D8;
//    }
//    // andi        $v0, $t0, 0x100
//    ctx->r2 = ctx->r8 & 0X100;
//    // beq         $v0, $zero, L_8005461C
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8005461C;
//    }
//    // nop
//
//L_800545D8:
//    // lw          $v0, 0x14($a0)
//    ctx->r2 = MEM_W(0X14, ctx->r4);
//    // nop
//
//    // bne         $v0, $zero, L_80054600
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_80054600;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x7CC($v0)
//    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
//    // nop
//
//    // lhu         $v1, 0x1AA($v0)
//    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
//    // j           L_80054618
//    // andi        $v1, $v1, 0xFFFB
//    ctx->r3 = ctx->r3 & 0XFFFB;
//    goto L_80054618;
//    // andi        $v1, $v1, 0xFFFB
//    ctx->r3 = ctx->r3 & 0XFFFB;
//L_80054600:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x7CC($v0)
//    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
//    // nop
//
//    // lhu         $v1, 0x1AA($v0)
//    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
//    // nop
//
//    // ori         $v1, $v1, 0x4
//    ctx->r3 = ctx->r3 | 0X4;
//L_80054618:
//    // sh          $v1, 0x1AA($v0)
//    MEM_H(0X1AA, ctx->r2) = ctx->r3;
//L_8005461C:
//    // bne         $t1, $zero, L_8005462C
//    if (ctx->r9 != 0) {
//        // andi        $v0, $t0, 0x200
//        ctx->r2 = ctx->r8 & 0X200;
//        goto L_8005462C;
//    }
//    // andi        $v0, $t0, 0x200
//    ctx->r2 = ctx->r8 & 0X200;
//    // beq         $v0, $zero, L_80054670
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80054670;
//    }
//    // nop
//
//L_8005462C:
//    // lw          $v0, 0x18($a0)
//    ctx->r2 = MEM_W(0X18, ctx->r4);
//    // nop
//
//    // bne         $v0, $zero, L_80054654
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_80054654;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x7CC($v0)
//    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
//    // nop
//
//    // lhu         $v1, 0x1AA($v0)
//    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
//    // j           L_8005466C
//    // andi        $v1, $v1, 0xFFFE
//    ctx->r3 = ctx->r3 & 0XFFFE;
//    goto L_8005466C;
//    // andi        $v1, $v1, 0xFFFE
//    ctx->r3 = ctx->r3 & 0XFFFE;
//L_80054654:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x7CC($v0)
//    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
//    // nop
//
//    // lhu         $v1, 0x1AA($v0)
//    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
//    // nop
//
//    // ori         $v1, $v1, 0x1
//    ctx->r3 = ctx->r3 | 0X1;
//L_8005466C:
//    // sh          $v1, 0x1AA($v0)
//    MEM_H(0X1AA, ctx->r2) = ctx->r3;
//L_80054670:
//    // bne         $t1, $zero, L_80054680
//    if (ctx->r9 != 0) {
//        // andi        $v0, $t0, 0x400
//        ctx->r2 = ctx->r8 & 0X400;
//        goto L_80054680;
//    }
//    // andi        $v0, $t0, 0x400
//    ctx->r2 = ctx->r8 & 0X400;
//    // beq         $v0, $zero, L_80054694
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80054694;
//    }
//    // nop
//
//L_80054680:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x7CC($v1)
//    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
//    // lhu         $v0, 0x1C($a0)
//    ctx->r2 = MEM_HU(0X1C, ctx->r4);
//    // nop
//
//    // sh          $v0, 0x1B4($v1)
//    MEM_H(0X1B4, ctx->r3) = ctx->r2;
//L_80054694:
//    // bne         $t1, $zero, L_800546A4
//    if (ctx->r9 != 0) {
//        // andi        $v0, $t0, 0x800
//        ctx->r2 = ctx->r8 & 0X800;
//        goto L_800546A4;
//    }
//    // andi        $v0, $t0, 0x800
//    ctx->r2 = ctx->r8 & 0X800;
//    // beq         $v0, $zero, L_800546B8
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_800546B8;
//    }
//    // nop
//
//L_800546A4:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x7CC($v1)
//    ctx->r3 = MEM_W(-0X7CC, ctx->r3);
//    // lhu         $v0, 0x1E($a0)
//    ctx->r2 = MEM_HU(0X1E, ctx->r4);
//    // nop
//
//    // sh          $v0, 0x1B6($v1)
//    MEM_H(0X1B6, ctx->r3) = ctx->r2;
//L_800546B8:
//    // bne         $t1, $zero, L_800546C8
//    if (ctx->r9 != 0) {
//        // andi        $v0, $t0, 0x1000
//        ctx->r2 = ctx->r8 & 0X1000;
//        goto L_800546C8;
//    }
//    // andi        $v0, $t0, 0x1000
//    ctx->r2 = ctx->r8 & 0X1000;
//    // beq         $v0, $zero, L_8005470C
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8005470C;
//    }
//    // nop
//
//L_800546C8:
//    // lw          $v0, 0x20($a0)
//    ctx->r2 = MEM_W(0X20, ctx->r4);
//    // nop
//
//    // bne         $v0, $zero, L_800546F0
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_800546F0;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x7CC($v0)
//    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
//    // nop
//
//    // lhu         $v1, 0x1AA($v0)
//    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
//    // j           L_80054708
//    // andi        $v1, $v1, 0xFFF7
//    ctx->r3 = ctx->r3 & 0XFFF7;
//    goto L_80054708;
//    // andi        $v1, $v1, 0xFFF7
//    ctx->r3 = ctx->r3 & 0XFFF7;
//L_800546F0:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x7CC($v0)
//    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
//    // nop
//
//    // lhu         $v1, 0x1AA($v0)
//    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
//    // nop
//
//    // ori         $v1, $v1, 0x8
//    ctx->r3 = ctx->r3 | 0X8;
//L_80054708:
//    // sh          $v1, 0x1AA($v0)
//    MEM_H(0X1AA, ctx->r2) = ctx->r3;
//L_8005470C:
//    // bne         $t1, $zero, L_8005471C
//    if (ctx->r9 != 0) {
//        // andi        $v0, $t0, 0x2000
//        ctx->r2 = ctx->r8 & 0X2000;
//        goto L_8005471C;
//    }
//    // andi        $v0, $t0, 0x2000
//    ctx->r2 = ctx->r8 & 0X2000;
//    // beq         $v0, $zero, L_80054760
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80054760;
//    }
//    // nop
//
//L_8005471C:
//    // lw          $v0, 0x24($a0)
//    ctx->r2 = MEM_W(0X24, ctx->r4);
//    // nop
//
//    // bne         $v0, $zero, L_80054744
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_80054744;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x7CC($v0)
//    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
//    // nop
//
//    // lhu         $v1, 0x1AA($v0)
//    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
//    // j           L_8005475C
//    // andi        $v1, $v1, 0xFFFD
//    ctx->r3 = ctx->r3 & 0XFFFD;
//    goto L_8005475C;
//    // andi        $v1, $v1, 0xFFFD
//    ctx->r3 = ctx->r3 & 0XFFFD;
//L_80054744:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x7CC($v0)
//    ctx->r2 = MEM_W(-0X7CC, ctx->r2);
//    // nop
//
//    // lhu         $v1, 0x1AA($v0)
//    ctx->r3 = MEM_HU(0X1AA, ctx->r2);
//    // nop
//
//    // ori         $v1, $v1, 0x2
//    ctx->r3 = ctx->r3 | 0X2;
//L_8005475C:
//    // sh          $v1, 0x1AA($v0)
//    MEM_H(0X1AA, ctx->r2) = ctx->r3;
//L_80054760:
//    // addiu       $sp, $sp, 0x10
//    ctx->r29 = ADD32(ctx->r29, 0X10);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop
//
//;}
