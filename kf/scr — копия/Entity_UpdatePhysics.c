#include "recomp.h"
#include "disable_warnings.h"

void Entity_UpdatePhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // lh          $a0, 0x24($s0)
    ctx->r4 = MEM_H(0X24, ctx->r16);
    // lbu         $v1, 0x7($s0)
    ctx->r3 = MEM_BU(0X7, ctx->r16);
    // lh          $a1, 0x22($s0)
    ctx->r5 = MEM_H(0X22, ctx->r16);
    // lhu         $a3, 0x1C($s0)
    ctx->r7 = MEM_HU(0X1C, ctx->r16);
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(0X6, ctx->r16);
    // sll         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) << 11;
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1E($s0)
    ctx->r2 = MEM_HU(0X1E, ctx->r16);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(0X2C, ctx->r16);
    // lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(0X34, ctx->r16);
    // jal         0x8002E19C
    // nop

    Map_GetCellData(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // bltz        $v0, L_8003B7E8
    if (SIGNED(ctx->r2) < 0) {
        // sw          $v0, 0x30($s0)
        MEM_W(0X30, ctx->r16) = ctx->r2;
        goto L_8003B7E8;
    }
    // sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
L_8003B7E8:
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_8003B80C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B80C;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, -0x2A80($v0)
    ctx->r2 = MEM_W(-0X2A80, ctx->r2);
    // nop

    // sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
L_8003B80C:
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // bne         $v0, $zero, L_8003B834
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B834;
    }
    // nop

    // lh          $v0, 0x26($s0)
    ctx->r2 = MEM_H(0X26, ctx->r16);
    // lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(0X30, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
L_8003B834:
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
