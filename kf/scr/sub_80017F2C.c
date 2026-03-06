#include "recomp.h"
#include "disable_warnings.h"

void sub_80017F2C(uint8_t* rdram, recomp_context* ctx) 
{
    printf("sub_80017F2C\n");
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
    // nop

    // beq         $v1, $zero, L_80017F98
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0x20
        ctx->r2 = 0 | 0X20;
        goto L_80017F98;
    }
    // ori         $v0, $zero, 0x20
    ctx->r2 = 0 | 0X20;
    // bne         $v1, $v0, L_80017F98
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80017F98;
    }
    // nop

    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // jal         0x8004CEBC
    // ori         $a1, $zero, 0x200
    ctx->r5 = 0 | 0X200;
    sub_8004CEBC(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0x200
    ctx->r5 = 0 | 0X200;
    after_0:
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(0X14, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // beq         $v1, $zero, L_80017F80
    if (ctx->r3 == 0) {
        // sw          $v0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r2;
        goto L_80017F80;
    }
    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // jalr        $v1
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_80017F80:
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80017F98
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80017F98;
    }
    // nop

    // jal         0x80017D2C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    NextCdTask(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_80017F98:
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
