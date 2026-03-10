#include "recomp.h"
#include "disable_warnings.h"

void VRAM_ReserveTextureSpace(uint8_t* rdram, recomp_context* ctx) 
{
   /* printf("VRAM_ReserveTextureSpace\n");*/
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // jal         0x8002F948
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    VRAM_FindFreeSlot(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8002FA38
    if (ctx->r16 == 0) {
        // nop
    
        goto L_8002FA38;
    }
    // nop

    // lbu         $v0, 0x38($sp)
    ctx->r2 = MEM_BU(0X38, ctx->r29);
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // sb          $s1, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r17;
    // sb          $s2, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r18;
    // sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // sh          $s3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r19;
    // sh          $s4, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r20;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(0X38, ctx->r29);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_8002FA24
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8002FA24;
    }
    // nop

    // lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(0X3C, ctx->r29);
    // lhu         $a0, 0x40($sp)
    ctx->r4 = MEM_HU(0X40, ctx->r29);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // lh          $v1, 0xC($s0)
    ctx->r3 = MEM_HS(0XC, ctx->r16);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $a0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r4;
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x80017C18
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    AllocateMemory(rdram, ctx);
    goto after_1;
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    after_1:
    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
L_8002FA24:
    // lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(0X10, ctx->r16);
    // jal         0x8006335C
    // addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    StoreImageWithCallback(rdram, ctx);
    goto after_2;
    // addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_2:
    // jal         0x800630D0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    KF_DrawSync(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
L_8002FA38:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
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

;}
