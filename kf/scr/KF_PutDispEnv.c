#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"

void KF_PutDispEnv(uint8_t* rdram, recomp_context* ctx) 
{
  //  printf("KF_PutDispEnv\n");
    DISPENV* env = (DISPENV*)GET_PTR(ctx->r4);
    //  Psy-X  
    PutDispEnv(env);
    ctx->r2 = 0;
    /*
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61A2
    ctx->r2 = ADD32(ctx->r2, 0X61A2);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_800637F8
    if (ctx->r2 != 0) {
        // lui         $s2, 0x800
        ctx->r18 = S32(0X800 << 16);
        goto L_800637F8;
    }
    // lui         $s2, 0x800
    ctx->r18 = S32(0X800 << 16);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x37F0
    ctx->r4 = ADD32(ctx->r4, 0X37F0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x619C($v0)
    ctx->r2 = MEM_W(0X619C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
L_800637F8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x61A0($v0)
    ctx->r2 = MEM_BU(0X61A0, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80063838
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063838;
    }
    // nop

    // jal         0x8006431C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8006431C(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // j           L_80063854
    // lui         $v0, 0x500
    ctx->r2 = S32(0X500 << 16);
    goto L_80063854;
    // lui         $v0, 0x500
    ctx->r2 = S32(0X500 << 16);
L_80063838:
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) << 10;
    // andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
L_80063854:
    // or          $a0, $v0, $v1
    ctx->r4 = ctx->r2 | ctx->r3;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6198($v0)
    ctx->r2 = MEM_W(0X6198, ctx->r2);
    // nop

    // lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(0X10, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6214($v1)
    ctx->r3 = MEM_W(0X6214, ctx->r3);
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // nop

    // bne         $v1, $v0, L_800638A4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800638A4;
    }
    // nop

    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6218($v1)
    ctx->r3 = MEM_W(0X6218, ctx->r3);
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80063A60
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80063A60;
    }
    // nop

L_800638A4:
    // jal         0x80061B44
    // nop

    GsGetWorkBase(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lh          $v1, 0x8($s0)
    ctx->r3 = MEM_HS(0X8, ctx->r16);
    // sb          $v0, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r2;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $a1, $v0, 0x260
    ctx->r5 = ADD32(ctx->r2, 0X260);
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // lh          $a0, 0xA($s0)
    ctx->r4 = MEM_HS(0XA, ctx->r16);
    // bne         $v0, $zero, L_800638D8
    if (ctx->r2 != 0) {
        // addiu       $s1, $a0, 0x13
        ctx->r17 = ADD32(ctx->r4, 0X13);
        goto L_800638D8;
    }
    // addiu       $s1, $a0, 0x13
    ctx->r17 = ADD32(ctx->r4, 0X13);
    // addiu       $s1, $a0, 0x10
    ctx->r17 = ADD32(ctx->r4, 0X10);
L_800638D8:
    // lh          $v1, 0xC($s0)
    ctx->r3 = MEM_HS(0XC, ctx->r16);
    // nop

    // beq         $v1, $zero, L_800638F8
    if (ctx->r3 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_800638F8;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // j           L_800638FC
    // addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    goto L_800638FC;
    // addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
L_800638F8:
    // addiu       $a2, $a1, 0xA00
    ctx->r6 = ADD32(ctx->r5, 0XA00);
L_800638FC:
    // lh          $v0, 0xE($s0)
    ctx->r2 = MEM_HS(0XE, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80063910
    if (ctx->r2 != 0) {
        // addu        $s3, $s1, $v0
        ctx->r19 = ADD32(ctx->r17, ctx->r2);
        goto L_80063910;
    }
    // addu        $s3, $s1, $v0
    ctx->r19 = ADD32(ctx->r17, ctx->r2);
    // addiu       $s3, $s1, 0xF0
    ctx->r19 = ADD32(ctx->r17, 0XF0);
L_80063910:
    // slti        $v0, $a1, 0x1F4
    ctx->r2 = SIGNED(ctx->r5) < 0X1F4 ? 1 : 0;
    // bne         $v0, $zero, L_80063930
    if (ctx->r2 != 0) {
        // ori         $a0, $zero, 0x1F4
        ctx->r4 = 0 | 0X1F4;
        goto L_80063930;
    }
    // ori         $a0, $zero, 0x1F4
    ctx->r4 = 0 | 0X1F4;
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // slti        $v0, $a0, 0xCDB
    ctx->r2 = SIGNED(ctx->r4) < 0XCDB ? 1 : 0;
    // bne         $v0, $zero, L_80063934
    if (ctx->r2 != 0) {
        // addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
        goto L_80063934;
    }
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // ori         $a0, $zero, 0xCDA
    ctx->r4 = 0 | 0XCDA;
L_80063930:
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80063934:
    // addiu       $v1, $a1, 0x50
    ctx->r3 = ADD32(ctx->r5, 0X50);
    // slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80063950
    if (ctx->r2 != 0) {
        // slti        $v0, $a2, 0xCDB
        ctx->r2 = SIGNED(ctx->r6) < 0XCDB ? 1 : 0;
        goto L_80063950;
    }
    // slti        $v0, $a2, 0xCDB
    ctx->r2 = SIGNED(ctx->r6) < 0XCDB ? 1 : 0;
    // bne         $v0, $zero, L_80063950
    if (ctx->r2 != 0) {
        // addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
        goto L_80063950;
    }
    // addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // ori         $v1, $zero, 0xCDA
    ctx->r3 = 0 | 0XCDA;
L_80063950:
    // bltz        $s1, L_800639A4
    if (SIGNED(ctx->r17) < 0) {
        // addu        $a2, $v1, $zero
        ctx->r6 = ADD32(ctx->r3, 0);
        goto L_800639A4;
    }
    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80063978
    if (ctx->r2 == 0) {
        // slti        $v0, $s1, 0x137
        ctx->r2 = SIGNED(ctx->r17) < 0X137 ? 1 : 0;
        goto L_80063978;
    }
    // slti        $v0, $s1, 0x137
    ctx->r2 = SIGNED(ctx->r17) < 0X137 ? 1 : 0;
    // beq         $v0, $zero, L_80063984
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063984;
    }
    // nop

    // j           L_800639A8
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    goto L_800639A8;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80063978:
    // slti        $v0, $s1, 0xFF
    ctx->r2 = SIGNED(ctx->r17) < 0XFF ? 1 : 0;
    // bne         $v0, $zero, L_8006399C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006399C;
    }
    // nop

L_80063984:
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // beq         $v0, $zero, L_800639A8
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0xFE
        ctx->r4 = 0 | 0XFE;
        goto L_800639A8;
    }
    // ori         $a0, $zero, 0xFE
    ctx->r4 = 0 | 0XFE;
    // j           L_800639A8
    // ori         $a0, $zero, 0x136
    ctx->r4 = 0 | 0X136;
    goto L_800639A8;
    // ori         $a0, $zero, 0x136
    ctx->r4 = 0 | 0X136;
L_8006399C:
    // j           L_800639A8
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    goto L_800639A8;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800639A4:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800639A8:
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // addiu       $v1, $s1, 0x1
    ctx->r3 = ADD32(ctx->r17, 0X1);
    // slt         $v0, $s3, $v1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80063A04
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80063A04;
    }
    // nop

    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // beq         $v0, $zero, L_800639DC
    if (ctx->r2 == 0) {
        // slti        $v0, $s3, 0x139
        ctx->r2 = SIGNED(ctx->r19) < 0X139 ? 1 : 0;
        goto L_800639DC;
    }
    // slti        $v0, $s3, 0x139
    ctx->r2 = SIGNED(ctx->r19) < 0X139 ? 1 : 0;
    // beq         $v0, $zero, L_800639E8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800639E8;
    }
    // nop

    // j           L_80063A04
    // addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
    goto L_80063A04;
    // addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
L_800639DC:
    // slti        $v0, $s3, 0x101
    ctx->r2 = SIGNED(ctx->r19) < 0X101 ? 1 : 0;
    // bne         $v0, $zero, L_80063A00
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80063A00;
    }
    // nop

L_800639E8:
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80063A04
    if (ctx->r2 == 0) {
        // ori         $v1, $zero, 0x100
        ctx->r3 = 0 | 0X100;
        goto L_80063A04;
    }
    // ori         $v1, $zero, 0x100
    ctx->r3 = 0 | 0X100;
    // j           L_80063A04
    // ori         $v1, $zero, 0x138
    ctx->r3 = 0 | 0X138;
    goto L_80063A04;
    // ori         $v1, $zero, 0x138
    ctx->r3 = 0 | 0X138;
L_80063A00:
    // addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
L_80063A04:
    // addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // andi        $v0, $a2, 0xFFF
    ctx->r2 = ctx->r6 & 0XFFF;
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // andi        $a0, $a1, 0xFFF
    ctx->r4 = ctx->r5 & 0XFFF;
    // lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x6198($a1)
    ctx->r5 = MEM_W(0X6198, ctx->r5);
    // or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // nop

    // jalr        $v1
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_4;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_4:
    // andi        $v0, $s3, 0x3FF
    ctx->r2 = ctx->r19 & 0X3FF;
    // sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) << 10;
    // andi        $a0, $s1, 0x3FF
    ctx->r4 = ctx->r17 & 0X3FF;
    // lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x6198($a1)
    ctx->r5 = MEM_W(0X6198, ctx->r5);
    // or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // nop

    // jalr        $v1
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_5;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_5:
L_80063A60:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x621C($v1)
    ctx->r3 = MEM_W(0X621C, ctx->r3);
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // nop

    // bne         $v1, $v0, L_80063AA8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80063AA8;
    }
    // nop

    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x620C($v1)
    ctx->r3 = MEM_W(0X620C, ctx->r3);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // bne         $v1, $v0, L_80063AA8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80063AA8;
    }
    // nop

    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6210($v1)
    ctx->r3 = MEM_W(0X6210, ctx->r3);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80063B90
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80063B90;
    }
    // nop

L_80063AA8:
    // jal         0x80061B44
    // nop

    GsGetWorkBase(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // sb          $v0, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x12($s0)
    ctx->r3 = MEM_BU(0X12, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80063AC8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80063AC8;
    }
    // nop

    // ori         $s2, $s2, 0x8
    ctx->r18 = ctx->r18 | 0X8;
L_80063AC8:
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80063ADC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063ADC;
    }
    // nop

    // ori         $s2, $s2, 0x10
    ctx->r18 = ctx->r18 | 0X10;
L_80063ADC:
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80063AF0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063AF0;
    }
    // nop

    // ori         $s2, $s2, 0x20
    ctx->r18 = ctx->r18 | 0X20;
L_80063AF0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61A3
    ctx->r2 = ADD32(ctx->r2, 0X61A3);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80063B0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063B0C;
    }
    // nop

    // ori         $s2, $s2, 0x80
    ctx->r18 = ctx->r18 | 0X80;
L_80063B0C:
    // lh          $v1, 0x4($s0)
    ctx->r3 = MEM_HS(0X4, ctx->r16);
    // nop

    // slti        $v0, $v1, 0x119
    ctx->r2 = SIGNED(ctx->r3) < 0X119 ? 1 : 0;
    // bne         $v0, $zero, L_80063B54
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0x161
        ctx->r2 = SIGNED(ctx->r3) < 0X161 ? 1 : 0;
        goto L_80063B54;
    }
    // slti        $v0, $v1, 0x161
    ctx->r2 = SIGNED(ctx->r3) < 0X161 ? 1 : 0;
    // beq         $v0, $zero, L_80063B30
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x191
        ctx->r2 = SIGNED(ctx->r3) < 0X191 ? 1 : 0;
        goto L_80063B30;
    }
    // slti        $v0, $v1, 0x191
    ctx->r2 = SIGNED(ctx->r3) < 0X191 ? 1 : 0;
    // j           L_80063B54
    // ori         $s2, $s2, 0x1
    ctx->r18 = ctx->r18 | 0X1;
    goto L_80063B54;
    // ori         $s2, $s2, 0x1
    ctx->r18 = ctx->r18 | 0X1;
L_80063B30:
    // beq         $v0, $zero, L_80063B40
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x231
        ctx->r2 = SIGNED(ctx->r3) < 0X231 ? 1 : 0;
        goto L_80063B40;
    }
    // slti        $v0, $v1, 0x231
    ctx->r2 = SIGNED(ctx->r3) < 0X231 ? 1 : 0;
    // j           L_80063B54
    // ori         $s2, $s2, 0x40
    ctx->r18 = ctx->r18 | 0X40;
    goto L_80063B54;
    // ori         $s2, $s2, 0x40
    ctx->r18 = ctx->r18 | 0X40;
L_80063B40:
    // beq         $v0, $zero, L_80063B50
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063B50;
    }
    // nop

    // j           L_80063B54
    // ori         $s2, $s2, 0x2
    ctx->r18 = ctx->r18 | 0X2;
    goto L_80063B54;
    // ori         $s2, $s2, 0x2
    ctx->r18 = ctx->r18 | 0X2;
L_80063B50:
    // ori         $s2, $s2, 0x3
    ctx->r18 = ctx->r18 | 0X3;
L_80063B54:
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // lh          $v1, 0x6($s0)
    ctx->r3 = MEM_HS(0X6, ctx->r16);
    // bne         $v0, $zero, L_80063B68
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0x121
        ctx->r2 = SIGNED(ctx->r3) < 0X121 ? 1 : 0;
        goto L_80063B68;
    }
    // slti        $v0, $v1, 0x121
    ctx->r2 = SIGNED(ctx->r3) < 0X121 ? 1 : 0;
    // slti        $v0, $v1, 0x101
    ctx->r2 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
L_80063B68:
    // bne         $v0, $zero, L_80063B74
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80063B74;
    }
    // nop

    // ori         $s2, $s2, 0x24
    ctx->r18 = ctx->r18 | 0X24;
L_80063B74:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6198($v0)
    ctx->r2 = MEM_W(0X6198, ctx->r2);
    // nop

    // lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(0X10, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_7;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_7:
L_80063B90:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, 0x620C
    ctx->r4 = ADD32(ctx->r4, 0X620C);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80065864
    // ori         $a2, $zero, 0x14
    ctx->r6 = 0 | 0X14;
    memcpy_recomp(rdram, ctx);
    goto after_8;
    // ori         $a2, $zero, 0x14
    ctx->r6 = 0 | 0X14;
    after_8:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop
    */
;}
