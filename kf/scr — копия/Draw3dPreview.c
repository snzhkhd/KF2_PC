#include "recomp.h"
#include "disable_warnings.h"

void Draw3dPreview(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x4A71($v0)
    ctx->r2 = MEM_BU(-0X4A71, ctx->r2);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // ori         $s1, $zero, 0x1
    ctx->r17 = 0 | 0X1;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x6C($gp)
    MEM_W(0X6C, ctx->r28) = ctx->r17;
    // bne         $v0, $zero, L_80024CDC
    if (ctx->r2 != 0) {
        // addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
        goto L_80024CDC;
    }
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // j           L_80024D58
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80024D58;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80024CDC:
    // jal         0x80024D70
    // nop

    Flush3dRender(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80024D30
    if (ctx->r3 == ctx->r2) {
        // ori         $a0, $zero, 0x6
        ctx->r4 = 0 | 0X6;
        goto L_80024D30;
    }
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80018418
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    ReadFromFile(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // jal         0x80017C18
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    AllocateMemory(rdram, ctx);
    goto after_2;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_2:
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // jal         0x800188CC
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LoadTFile(rdram, ctx);
    goto after_3;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // jal         0x8003040C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    RegisterAndTransformModel(rdram, ctx);
    goto after_4;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // sw          $s1, 0x64($gp)
    MEM_W(0X64, ctx->r28) = ctx->r17;
L_80024D30:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // ori         $v1, $zero, 0x3E8
    ctx->r3 = 0 | 0X3E8;
    // sh          $v1, 0x108($gp)
    MEM_H(0X108, ctx->r28) = ctx->r3;
    // ori         $v1, $zero, 0x4
    ctx->r3 = 0 | 0X4;
    // sh          $zero, 0x104($gp)
    MEM_H(0X104, ctx->r28) = 0;
    // sh          $zero, 0x106($gp)
    MEM_H(0X106, ctx->r28) = 0;
    // sh          $zero, 0x10C($gp)
    MEM_H(0X10C, ctx->r28) = 0;
    // sh          $zero, 0x10E($gp)
    MEM_H(0X10E, ctx->r28) = 0;
    // sh          $zero, 0x110($gp)
    MEM_H(0X110, ctx->r28) = 0;
    // sw          $v1, 0x114($gp)
    MEM_W(0X114, ctx->r28) = ctx->r3;
L_80024D58:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
