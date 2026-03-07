#include "recomp.h"
#include "disable_warnings.h"

void CdWaitForCompletion(uint8_t* rdram, recomp_context* ctx) 
{
	printf("-->CdWaitForCompletion\n");
    // a1 = mode (0=wait, 1=poll)
    // a2 = result buffer
    uint8_t* result_buf = ctx->r5 ? (uint8_t*)GET_PTR(ctx->r5) : nullptr;

    // Заполняем статус если буфер передан
    if (result_buf) {
        result_buf[0] = 0x02; // status: complete
    }

    ctx->r2 = 0; // 0 = команда завершена
	return;
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x8006263C
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    KF_VSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s4, 0x8007
    ctx->r20 = S32(0X8007 << 16);
    // addiu       $s4, $s4, -0xAE4
    ctx->r20 = ADD32(ctx->r20, -0XAE4);
    // lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // addiu       $s3, $s3, -0x8AC
    ctx->r19 = ADD32(ctx->r19, -0X8AC);
    // addiu       $s5, $s3, 0x1
    ctx->r21 = ADD32(ctx->r19, 0X1);
    // lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // addiu       $s2, $s2, -0x88C
    ctx->r18 = ADD32(ctx->r18, -0X88C);
    // addiu       $v0, $v0, 0x1E0
    ctx->r2 = ADD32(ctx->r2, 0X1E0);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64A8($at)
    MEM_W(0X64A8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x2FCC
    ctx->r2 = ADD32(ctx->r2, 0X2FCC);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $zero, 0x64AC($at)
    MEM_W(0X64AC, ctx->r1) = 0;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64B0($at)
    MEM_W(0X64B0, ctx->r1) = ctx->r2;
L_8004EC28:
    // jal         0x8006263C
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    KF_VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x64A8($v1)
    ctx->r3 = MEM_W(0X64A8, ctx->r3);
    // nop

    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8004EC70
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8004EC70;
    }
    // nop

    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x64AC($v1)
    ctx->r3 = MEM_W(0X64AC, ctx->r3);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x64AC($at)
    MEM_W(0X64AC, ctx->r1) = ctx->r2;
    // lui         $v0, 0x1E
    ctx->r2 = S32(0X1E << 16);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8004ECE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004ECE8;
    }
    // nop

L_8004EC70:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2E78
    ctx->r4 = ADD32(ctx->r4, 0X2E78);
    // jal         0x80062C20
    // nop

    sub_80062C20(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(0X0, ctx->r19);
    // lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(0X1, ctx->r19);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // lw          $a1, 0x64B0($a1)
    ctx->r5 = MEM_W(0X64B0, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, -0xB67($v0)
    ctx->r2 = MEM_BU(-0XB67, ctx->r2);
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0xB64
    ctx->r1 = ADD32(ctx->r1, -0XB64);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $a2, 0x0($at)
    ctx->r6 = MEM_W(0X0, ctx->r1);
    // lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(0X0, ctx->r4);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x2E88
    ctx->r4 = ADD32(ctx->r4, 0X2E88);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x8004E1E0
    // nop

    sub_8004E1E0(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_8004ECEC
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004ECEC;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004ECE8:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004ECEC:
    // bne         $v0, $zero, L_8004EE38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004EE38;
    }
    // nop

    // jal         0x80061CA8
    // nop

    KF_CheckCallback(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // beq         $v0, $zero, L_8004EDB0
    if (ctx->r2 == 0) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_8004EDB0;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $s1, $v0, 0x3
    ctx->r17 = ctx->r2 & 0X3;
L_8004ED1C:
    // jal         0x8004D148
    // nop

    sub_8004D148(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8004ED9C
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x4
        ctx->r2 = ctx->r16 & 0X4;
        goto L_8004ED9C;
    }
    // andi        $v0, $s0, 0x4
    ctx->r2 = ctx->r16 & 0X4;
    // beq         $v0, $zero, L_8004ED64
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x2
        ctx->r2 = ctx->r16 & 0X2;
        goto L_8004ED64;
    }
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(-0XB84, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004ED60
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004ED60;
    }
    // nop

    // lbu         $a0, 0x0($s5)
    ctx->r4 = MEM_BU(0X0, ctx->r21);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x6498
    ctx->r5 = ADD32(ctx->r5, 0X6498);
    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_7;
    // nop

    after_7:
L_8004ED60:
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
L_8004ED64:
    // beq         $v0, $zero, L_8004ED1C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004ED1C;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0xB88($v0)
    ctx->r2 = MEM_W(-0XB88, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004ED1C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004ED1C;
    }
    // nop

    // lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(0X0, ctx->r19);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x6490
    ctx->r5 = ADD32(ctx->r5, 0X6490);
    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // j           L_8004ED1C
    // nop

    goto L_8004ED1C;
    // nop

L_8004ED9C:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, -0x8C4($v0)
    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
    // nop

    // sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
L_8004EDB0:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x6498
    ctx->r5 = ADD32(ctx->r5, 0X6498);
    // beq         $a0, $zero, L_8004EDDC
    if (ctx->r4 == 0) {
        // ori         $v1, $zero, 0x7
        ctx->r3 = 0 | 0X7;
        goto L_8004EDDC;
    }
    // ori         $v1, $zero, 0x7
    ctx->r3 = 0 | 0X7;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004EDC4:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // bne         $v1, $a2, L_8004EDC4
    if (ctx->r3 != ctx->r6) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8004EDC4;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8004EDDC:
    // jal         0x8006263C
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    KF_VSync(rdram, ctx);
    goto after_9;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_9:
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // nop

    // addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8004EE04
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004EE04;
    }
    // nop

    // jal         0x8004E73C
    // nop

    sub_8004E73C(rdram, ctx);
    goto after_10;
    // nop

    after_10:
L_8004EE04:
    // lw          $v0, -0x4($s2)
    ctx->r2 = MEM_W(-0X4, ctx->r18);
    // nop

    // bne         $v0, $zero, L_8004EE1C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004EE1C;
    }
    // nop

    // jal         0x8004EE68
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8004EE68(rdram, ctx);
    goto after_11;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
L_8004EE1C:
    // bne         $s6, $zero, L_8004EE34
    if (ctx->r22 != 0) {
        // nop
    
        goto L_8004EE34;
    }
    // nop

    // lw          $v0, -0x4($s2)
    ctx->r2 = MEM_W(-0X4, ctx->r18);
    // nop

    // bgtz        $v0, L_8004EC28
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8004EC28;
    }
    // nop

L_8004EE34:
    // lw          $v0, -0x4($s2)
    ctx->r2 = MEM_W(-0X4, ctx->r18);
L_8004EE38:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
