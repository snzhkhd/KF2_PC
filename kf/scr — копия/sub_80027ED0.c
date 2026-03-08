#include "recomp.h"
#include "disable_warnings.h"

void sub_80027ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // sltiu       $v0, $a1, 0x7
    ctx->r2 = ctx->r5 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80027F6C
    if (ctx->r2 == 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_80027F6C;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x1264
    ctx->r1 = ADD32(ctx->r1, 0X1264);
    // addu        $at, $at, $v0
    gpr jr_addend_80027EFC;
    jr_addend_80027EFC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80027EFC >> 2) {
        case 0: goto L_80027F04; break;
        case 1: goto L_80027F14; break;
        case 2: goto L_80027F24; break;
        case 3: goto L_80027F34; break;
        case 4: goto L_80027F44; break;
        case 5: goto L_80027F54; break;
        case 6: goto L_80027F64; break;
        default: switch_error(__func__, 0x80027EFC, 0x80011264);
    }
    // nop

L_80027F04:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4A7C($at)
    MEM_B(-0X4A7C, ctx->r1) = ctx->r4;
    // j           L_80027F6C
    // nop

    goto L_80027F6C;
    // nop

L_80027F14:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4A7B($at)
    MEM_B(-0X4A7B, ctx->r1) = ctx->r4;
    // j           L_80027F6C
    // nop

    goto L_80027F6C;
    // nop

L_80027F24:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4A79($at)
    MEM_B(-0X4A79, ctx->r1) = ctx->r4;
    // j           L_80027F6C
    // nop

    goto L_80027F6C;
    // nop

L_80027F34:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4A78($at)
    MEM_B(-0X4A78, ctx->r1) = ctx->r4;
    // j           L_80027F6C
    // nop

    goto L_80027F6C;
    // nop

L_80027F44:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4A7A($at)
    MEM_B(-0X4A7A, ctx->r1) = ctx->r4;
    // j           L_80027F6C
    // nop

    goto L_80027F6C;
    // nop

L_80027F54:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4A77($at)
    MEM_B(-0X4A77, ctx->r1) = ctx->r4;
    // j           L_80027F6C
    // nop

    goto L_80027F6C;
    // nop

L_80027F64:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sb          $a0, -0x4A76($at)
    MEM_B(-0X4A76, ctx->r1) = ctx->r4;
L_80027F6C:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A7C($v1)
    ctx->r3 = MEM_BU(-0X4A7C, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80027F9C
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_80027F9C;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2CE8
    ctx->r3 = ADD32(ctx->r3, -0X2CE8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A98($at)
    MEM_W(-0X4A98, ctx->r1) = ctx->r2;
    // j           L_80027FA4
    // nop

    goto L_80027FA4;
    // nop

L_80027F9C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4A98($at)
    MEM_W(-0X4A98, ctx->r1) = 0;
L_80027FA4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A7B($v1)
    ctx->r3 = MEM_BU(-0X4A7B, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80027FD4
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_80027FD4;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2CE8
    ctx->r3 = ADD32(ctx->r3, -0X2CE8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A94($at)
    MEM_W(-0X4A94, ctx->r1) = ctx->r2;
    // j           L_80027FDC
    // nop

    goto L_80027FDC;
    // nop

L_80027FD4:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4A94($at)
    MEM_W(-0X4A94, ctx->r1) = 0;
L_80027FDC:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A79($v1)
    ctx->r3 = MEM_BU(-0X4A79, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8002800C
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_8002800C;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2CE8
    ctx->r3 = ADD32(ctx->r3, -0X2CE8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A8C($at)
    MEM_W(-0X4A8C, ctx->r1) = ctx->r2;
    // j           L_80028014
    // nop

    goto L_80028014;
    // nop

L_8002800C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4A8C($at)
    MEM_W(-0X4A8C, ctx->r1) = 0;
L_80028014:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A78($v1)
    ctx->r3 = MEM_BU(-0X4A78, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80028044
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_80028044;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2CE8
    ctx->r3 = ADD32(ctx->r3, -0X2CE8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A88($at)
    MEM_W(-0X4A88, ctx->r1) = ctx->r2;
    // j           L_8002804C
    // nop

    goto L_8002804C;
    // nop

L_80028044:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4A88($at)
    MEM_W(-0X4A88, ctx->r1) = 0;
L_8002804C:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A7A($v1)
    ctx->r3 = MEM_BU(-0X4A7A, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8002807C
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_8002807C;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2CE8
    ctx->r3 = ADD32(ctx->r3, -0X2CE8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A90($at)
    MEM_W(-0X4A90, ctx->r1) = ctx->r2;
    // j           L_80028084
    // nop

    goto L_80028084;
    // nop

L_8002807C:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4A90($at)
    MEM_W(-0X4A90, ctx->r1) = 0;
L_80028084:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A77($v1)
    ctx->r3 = MEM_BU(-0X4A77, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_800280B4
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_800280B4;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2CE8
    ctx->r3 = ADD32(ctx->r3, -0X2CE8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A84($at)
    MEM_W(-0X4A84, ctx->r1) = ctx->r2;
    // j           L_800280BC
    // nop

    goto L_800280BC;
    // nop

L_800280B4:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4A84($at)
    MEM_W(-0X4A84, ctx->r1) = 0;
L_800280BC:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x4A76($v1)
    ctx->r3 = MEM_BU(-0X4A76, ctx->r3);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_800280EC
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 5
        ctx->r2 = S32(ctx->r3) << 5;
        goto L_800280EC;
    }
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2CE8
    ctx->r3 = ADD32(ctx->r3, -0X2CE8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $v0, -0x4A80($at)
    MEM_W(-0X4A80, ctx->r1) = ctx->r2;
    // j           L_800280F4
    // nop

    goto L_800280F4;
    // nop

L_800280EC:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $zero, -0x4A80($at)
    MEM_W(-0X4A80, ctx->r1) = 0;
L_800280F4:
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
