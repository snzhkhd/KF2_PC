#include "recomp.h"
#include "disable_warnings.h"

void sub_80017DB4(uint8_t* rdram, recomp_context* ctx) 
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // lw          $s0, -0x57B8($s0)
    ctx->r16 = MEM_W(-0X57B8, ctx->r16);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // beq         $v1, $v0, L_80017EF8
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x21
        ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
        goto L_80017EF8;
    }
    // slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // beq         $v0, $zero, L_80017DF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80017DF8;
    }
    // nop

    // beq         $v1, $zero, L_80017F18
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_80017F18;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // beq         $v1, $v0, L_80017E0C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80017E0C;
    }
    // nop

    // j           L_80017F18
    // nop

    goto L_80017F18;
    // nop

L_80017DF8:
    // ori         $v0, $zero, 0x30
    ctx->r2 = 0 | 0X30;
    // beq         $v1, $v0, L_80017E0C
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x40
        ctx->r2 = 0 | 0X40;
        goto L_80017E0C;
    }
    // ori         $v0, $zero, 0x40
    ctx->r2 = 0 | 0X40;
    // bne         $v1, $v0, L_80017F18
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80017F18;
    }
    // nop

L_80017E0C:
    // lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(0X1, ctx->r16);
    // nop

    // beq         $v1, $zero, L_80017E2C
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80017E2C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // beq         $v1, $v0, L_80017E64
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0x10
        ctx->r2 = 0 | 0X10;
        goto L_80017E64;
    }
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // j           L_80017F18
    // nop

    goto L_80017F18;
    // nop

L_80017E2C:
    // lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(0X10, ctx->r16);
    // lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(0XC, ctx->r16);
    // jal         0x8004CF44
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    CdReadWithRetry(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    after_0:
    // bne         $v0, $zero, L_80017F14
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80017F14;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
L_80017E48:
    // addiu       $a1, $s0, 0x6
    ctx->r5 = ADD32(ctx->r16, 0X6);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // beq         $v0, $zero, L_80017E48
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_80017E48;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // j           L_80017F18
    // nop

    goto L_80017F18;
    // nop

L_80017E64:
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v1, $v0, L_80017ED8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80017ED8;
    }
    // nop

    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(0X10, ctx->r16);
    // jal         0x800182A0
    // nop

    VerifyChecksum(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // beq         $v0, $zero, L_80017EAC
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_80017EAC;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_80017E90:
    // addiu       $a1, $s0, 0x6
    ctx->r5 = ADD32(ctx->r16, 0X6);
    // jal         0x8004CAC0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    KF_CdControl(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // beq         $v0, $zero, L_80017E90
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0x16
        ctx->r4 = 0 | 0X16;
        goto L_80017E90;
    }
    // ori         $a0, $zero, 0x16
    ctx->r4 = 0 | 0X16;
    // j           L_80017F18
    // nop

    goto L_80017F18;
    // nop

L_80017EAC:
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80017EC8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80017EC8;
    }
    // nop

    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_80017EC8:
    // jal         0x80017D2C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    NextCdTask(rdram, ctx);
    goto after_5;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // j           L_80017F18
    // nop

    goto L_80017F18;
    // nop

L_80017ED8:
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80017F18
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80017F18;
    }
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_6;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // j           L_80017F18
    // nop

    goto L_80017F18;
    // nop

L_80017EF8:
    // lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(0X1, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80017F18
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80017F18;
    }
    // nop

    // jal         0x8004F418
    // ori         $a0, $zero, 0x80
    ctx->r4 = 0 | 0X80;
    sub_8004F418(rdram, ctx);
    goto after_7;
    // ori         $a0, $zero, 0x80
    ctx->r4 = 0 | 0X80;
    after_7:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80017F14:
    // sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
L_80017F18:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
