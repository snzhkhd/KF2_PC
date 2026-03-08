#include "recomp.h"
#include "disable_warnings.h"

void LoadFileByIndex(uint8_t* rdram, recomp_context* ctx) 
{
    char* v1 = (char*)GET_PTR(ctx->r5);
    printf("LoadFileByIndex <%s>\n", v1);
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x8B8
    ctx->r29 = ADD32(ctx->r29, -0X8B8);
    // sw          $ra, 0x8B0($sp)
    MEM_W(0X8B0, ctx->r29) = ctx->r31;
    // sw          $s1, 0x8AC($sp)
    MEM_W(0X8AC, ctx->r29) = ctx->r17;
    // sw          $s0, 0x8A8($sp)
    MEM_W(0X8A8, ctx->r29) = ctx->r16;
    // lw          $v0, 0x58($gp)
    ctx->r2 = MEM_W(0X58, ctx->r28);
    // lb          $v1, 0x5C($gp)
    ctx->r3 = MEM_B(0X5C, ctx->r28);
    // sw          $v0, 0x868($sp)
    MEM_W(0X868, ctx->r29) = ctx->r2;
    // sb          $v1, 0x86C($sp)
    MEM_B(0X86C, ctx->r29) = ctx->r3;
    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // addiu       $s0, $sp, 0x868
    ctx->r16 = ADD32(ctx->r29, 0X868);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x57B4
    ctx->r3 = ADD32(ctx->r3, -0X57B4);
    // jal         0x80062B90
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    strcat_recomp(rdram, ctx);
    goto after_0;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    after_0:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x6320
    ctx->r5 = ADD32(ctx->r5, 0X6320);
    // jal         0x80062B90
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    strcat_recomp(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // addiu       $a0, $sp, 0x850
    ctx->r4 = ADD32(ctx->r29, 0X850);
L_80018B34:
    // jal         0x8004F4AC
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    KF_CdSearchFile(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // bne         $v0, $zero, L_80018B5C
    if (ctx->r2 != 0) {
        // ori         $a2, $zero, 0x800
        ctx->r6 = 0 | 0X800;
        goto L_80018B5C;
    }
    // ori         $a2, $zero, 0x800
    ctx->r6 = 0 | 0X800;
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x1074
    ctx->r4 = ADD32(ctx->r4, 0X1074);
    // jal         0x80062BA0
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    psx_printf(rdram, ctx);
    goto after_3;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // j           L_80018B34
    // addiu       $a0, $sp, 0x850
    ctx->r4 = ADD32(ctx->r29, 0X850);
    goto L_80018B34;
    // addiu       $a0, $sp, 0x850
    ctx->r4 = ADD32(ctx->r29, 0X850);
L_80018B5C:
    // lwl         $v0, 0x853($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X853, ctx->r29);
    // lwr         $v0, 0x850($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X850, ctx->r29);
    // nop

    // swl         $v0, 0x7($s1)
    do_swl(rdram, 0X7, ctx->r17, ctx->r2);
    // swr         $v0, 0x4($s1)
    do_swr(rdram, 0X4, ctx->r17, ctx->r2);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // lw          $v0, 0x854($sp)
    ctx->r2 = MEM_W(0X854, ctx->r29);
    // jal         0x80018890
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    CalculateSectorCount(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    after_4:
    // lhu         $a0, 0x10($sp)
    ctx->r4 = MEM_HU(0X10, ctx->r29);
    // nop

    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // jal         0x80017C18
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    AllocateMemory(rdram, ctx);
    goto after_5;
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    after_5:
    // lhu         $a1, 0x10($sp)
    ctx->r5 = MEM_HU(0X10, ctx->r29);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x1098
    ctx->r4 = ADD32(ctx->r4, 0X1098);
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // jal         0x80062BA0
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    psx_printf(rdram, ctx);
    goto after_6;
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    after_6:
    // addiu       $a1, $sp, 0x12
    ctx->r5 = ADD32(ctx->r29, 0X12);
    // lhu         $a2, 0x10($sp)
    ctx->r6 = MEM_HU(0X10, ctx->r29);
    // lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(0X0, ctx->r17);
    // jal         0x800176B4
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    CopyToFinalBuffer(rdram, ctx);
    goto after_7;
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_7:
    // lw          $ra, 0x8B0($sp)
    ctx->r31 = MEM_W(0X8B0, ctx->r29);
    // lw          $s1, 0x8AC($sp)
    ctx->r17 = MEM_W(0X8AC, ctx->r29);
    // lw          $s0, 0x8A8($sp)
    ctx->r16 = MEM_W(0X8A8, ctx->r29);
    // addiu       $sp, $sp, 0x8B8
    ctx->r29 = ADD32(ctx->r29, 0X8B8);
    // jr          $ra
    // nop

    return;
    // nop

;}
