#include "recomp.h"
#include "disable_warnings.h"

void ParseTIMHeader(uint8_t* rdram, recomp_context* ctx) 
{
    //printf("ParseTIMHeader\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // ori         $v0, $zero, 0x10
    ctx->r2 = 0 | 0X10;
    // beq         $v1, $v0, L_80065C0C
    if (ctx->r3 == ctx->r2) {
        // addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_80065C0C;
    }
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // j           L_80065CDC
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80065CDC;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80065C0C:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // jal         0x80062FC8
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    sub_80062FC8(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_0:
    // ori         $s2, $zero, 0x2
    ctx->r18 = 0 | 0X2;
    // bne         $v0, $s2, L_80065C38
    if (ctx->r2 != ctx->r18) {
        // nop
    
        goto L_80065C38;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3854
    ctx->r4 = ADD32(ctx->r4, 0X3854);
    // jal         0x80062BA0
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    psx_printf(rdram, ctx);
    goto after_1;
    // ori         $a1, $zero, 0x10
    ctx->r5 = 0 | 0X10;
    after_1:
L_80065C38:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $s2, L_80065C5C
    if (ctx->r2 != ctx->r18) {
        // nop
    
        goto L_80065C5C;
    }
    // nop

    // lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(0X0, ctx->r17);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3860
    ctx->r4 = ADD32(ctx->r4, 0X3860);
    // jal         0x80062BA0
    // nop

    psx_printf(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_80065C5C:
    // jal         0x80062FC8
    // nop

    sub_80062FC8(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // bne         $v0, $s2, L_80065C7C
    if (ctx->r2 != ctx->r18) {
        // nop
    
        goto L_80065C7C;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x386C
    ctx->r4 = ADD32(ctx->r4, 0X386C);
    // jal         0x80062BA0
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    psx_printf(rdram, ctx);
    goto after_5;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_5:
L_80065C7C:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_80065CB0
    if (ctx->r2 == 0) {
        // addiu       $v0, $s0, 0x4
        ctx->r2 = ADD32(ctx->r16, 0X4);
        goto L_80065CB0;
    }
    // addiu       $v0, $s0, 0x4
    ctx->r2 = ADD32(ctx->r16, 0X4);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // addiu       $v0, $s0, 0xC
    ctx->r2 = ADD32(ctx->r16, 0XC);
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // srl         $a0, $v1, 2
    ctx->r4 = S32(U32(ctx->r3) >> 2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // j           L_80065CBC
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    goto L_80065CBC;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80065CB0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
L_80065CBC:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // addiu       $v1, $s0, 0x4
    ctx->r3 = ADD32(ctx->r16, 0X4);
    // sw          $v1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r3;
    // addiu       $v1, $s0, 0xC
    ctx->r3 = ADD32(ctx->r16, 0XC);
    // sw          $v1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r3;
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
L_80065CDC:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
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
