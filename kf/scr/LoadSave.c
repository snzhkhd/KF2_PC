#include "recomp.h"
#include "disable_warnings.h"

void LoadSave(uint8_t* rdram, recomp_context* ctx) 
{
    printf("LoadSave\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // ori         $a0, $zero, 0xFF
    ctx->r4 = 0 | 0XFF;
    // ori         $a1, $zero, 0xFF
    ctx->r5 = 0 | 0XFF;
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // jal         0x80027ED0
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    sub_80027ED0(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x4AA1
    ctx->r16 = ADD32(ctx->r16, -0X4AA1);
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // jal         0x8002810C
    // nop

    sub_8002810C(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80025F30
    // nop

    FinalizePlayerInit(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4ADA($v0)
    ctx->r2 = MEM_HS(-0X4ADA, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80026078
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_80026078;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // ori         $a2, $zero, 0xF
    ctx->r6 = 0 | 0XF;
    // jal         0x80042D2C
    // addiu       $a3, $s0, 0x3D
    ctx->r7 = ADD32(ctx->r16, 0X3D);
    SpawnParticleEntity(rdram, ctx);
    goto after_3;
    // addiu       $a3, $s0, 0x3D
    ctx->r7 = ADD32(ctx->r16, 0X3D);
    after_3:
L_80026078:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4AD8($v0)
    ctx->r2 = MEM_HS(-0X4AD8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800260A0
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0xA
        ctx->r4 = 0 | 0XA;
        goto L_800260A0;
    }
    // ori         $a0, $zero, 0xA
    ctx->r4 = 0 | 0XA;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    // ori         $a2, $zero, 0x11
    ctx->r6 = 0 | 0X11;
    // jal         0x80042D2C
    // addiu       $a3, $s0, 0x3D
    ctx->r7 = ADD32(ctx->r16, 0X3D);
    SpawnParticleEntity(rdram, ctx);
    goto after_4;
    // addiu       $a3, $s0, 0x3D
    ctx->r7 = ADD32(ctx->r16, 0X3D);
    after_4:
L_800260A0:
    // jal         0x80026430
    // nop

    CalculatePlayerStats(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
