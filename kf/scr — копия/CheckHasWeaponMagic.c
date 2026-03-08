#include "recomp.h"
#include "disable_warnings.h"

void CheckHasWeaponMagic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x1900
    ctx->r3 = ADD32(ctx->r3, -0X1900);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a2, $a2, -0x4B24
    ctx->r6 = ADD32(ctx->r6, -0X4B24);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // lhu         $v1, 0x16($a0)
    ctx->r3 = MEM_HU(0X16, ctx->r4);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80029068
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80029068;
    }
    // nop

    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sw          $a0, -0x4AC0($at)
    MEM_W(-0X4AC0, ctx->r1) = ctx->r4;
    // beq         $a1, $zero, L_80028F50
    if (ctx->r5 == 0) {
        // addiu       $v1, $s1, -0x26
        ctx->r3 = ADD32(ctx->r17, -0X26);
        goto L_80028F50;
    }
    // addiu       $v1, $s1, -0x26
    ctx->r3 = ADD32(ctx->r17, -0X26);
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $zero, -0x4B1E($at)
    MEM_H(-0X4B1E, ctx->r1) = 0;
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // lhu         $v1, 0x16($a0)
    ctx->r3 = MEM_HU(0X16, ctx->r4);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // addiu       $v1, $s1, -0x26
    ctx->r3 = ADD32(ctx->r17, -0X26);
L_80028F50:
    // sltiu       $v0, $v1, 0xD
    ctx->r2 = ctx->r3 < 0XD ? 1 : 0;
    // beq         $v0, $zero, L_8002903C
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8002903C;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addiu       $at, $at, 0x135C
    ctx->r1 = ADD32(ctx->r1, 0X135C);
    // addu        $at, $at, $v0
    gpr jr_addend_80028F70;
    jr_addend_80028F70 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80028F70 >> 2) {
        case 0: goto L_80028FE8; break;
        case 1: goto L_80028F78; break;
        case 2: goto L_80028FB0; break;
        case 3: goto L_8002903C; break;
        case 4: goto L_8002903C; break;
        case 5: goto L_8002903C; break;
        case 6: goto L_8002903C; break;
        case 7: goto L_8002903C; break;
        case 8: goto L_8002903C; break;
        case 9: goto L_8002903C; break;
        case 10: goto L_8002903C; break;
        case 11: goto L_80028F90; break;
        case 12: goto L_80028F90; break;
        default: switch_error(__func__, 0x80028F70, 0x8001135C);
    }
    // nop

L_80028F78:
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, -0x1DE0
    ctx->r1 = ADD32(ctx->r1, -0X1DE0);
    // addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // lbu         $a0, 0x0($at)
    ctx->r4 = MEM_BU(0X0, ctx->r1);
    // j           L_80028F94
    // nop

    goto L_80028F94;
    // nop

L_80028F90:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80028F94:
    // jal         0x80028D54
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    Local2World(rdram, ctx);
    goto after_0;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80028498
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    SpawnMagicProjectile(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // j           L_80029068
    // nop

    goto L_80029068;
    // nop

L_80028FB0:
    // sll         $s0, $s0, 9
    ctx->r16 = S32(ctx->r16) << 9;
    // jal         0x800602D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    FixedCos(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A24($at)
    MEM_H(-0X4A24, ctx->r1) = ctx->r2;
    // jal         0x800601F4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    FixedSin(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A22($at)
    MEM_H(-0X4A22, ctx->r1) = ctx->r2;
    // j           L_80029058
    // ori         $v0, $zero, 0x258
    ctx->r2 = 0 | 0X258;
    goto L_80029058;
    // ori         $v0, $zero, 0x258
    ctx->r2 = 0 | 0X258;
L_80028FE8:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // addiu       $s2, $s2, -0x4A24
    ctx->r18 = ADD32(ctx->r18, -0X4A24);
    // ori         $s3, $zero, 0x190
    ctx->r19 = 0 | 0X190;
L_80028FF8:
    // jal         0x800602D0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    FixedCos(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // jal         0x800601F4
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    FixedSin(rdram, ctx);
    goto after_5;
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    after_5:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // jal         0x80028498
    // sh          $s3, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r19;
    SpawnMagicProjectile(rdram, ctx);
    goto after_6;
    // sh          $s3, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r19;
    after_6:
    // addiu       $s0, $s0, 0x2AC
    ctx->r16 = ADD32(ctx->r16, 0X2AC);
    // slti        $v0, $s0, 0xFFF
    ctx->r2 = SIGNED(ctx->r16) < 0XFFF ? 1 : 0;
    // beq         $v0, $zero, L_80029068
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80029068;
    }
    // nop

    // j           L_80028FF8
    // nop

    goto L_80028FF8;
    // nop

L_8002903C:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $v0, $zero, 0xC8
    ctx->r2 = 0 | 0XC8;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A24($at)
    MEM_H(-0X4A24, ctx->r1) = ctx->r2;
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A22($at)
    MEM_H(-0X4A22, ctx->r1) = ctx->r2;
    // ori         $v0, $zero, 0x190
    ctx->r2 = 0 | 0X190;
L_80029058:
    // lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // sh          $v0, -0x4A20($at)
    MEM_H(-0X4A20, ctx->r1) = ctx->r2;
    // jal         0x80028498
    // nop

    SpawnMagicProjectile(rdram, ctx);
    goto after_7;
    // nop

    after_7:
L_80029068:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
