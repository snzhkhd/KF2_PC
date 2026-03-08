#include "recomp.h"
#include "disable_warnings.h"

void sub_8002ECC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // ori         $t1, $zero, 0x1
    ctx->r9 = 0 | 0X1;
    // andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
L_8002ECD0:
    // sltiu       $v0, $a1, 0x18
    ctx->r2 = ctx->r5 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8002ED1C
    if (ctx->r2 == 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_8002ED1C;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // beq         $t0, $zero, L_8002ECF8
    if (ctx->r8 == 0) {
        // nop
    
        goto L_8002ECF8;
    }
    // nop

    // beq         $t0, $t1, L_8002ED08
    if (ctx->r8 == ctx->r9) {
        // nop
    
        goto L_8002ED08;
    }
    // nop

    // j           L_8002ED14
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    goto L_8002ED14;
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
L_8002ECF8:
    // bne         $v0, $a3, L_8002ED10
    if (ctx->r2 != ctx->r7) {
        // nop
    
        goto L_8002ED10;
    }
    // nop

    // j           L_8002ED10
    // ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
    goto L_8002ED10;
    // ori         $t0, $zero, 0x1
    ctx->r8 = 0 | 0X1;
L_8002ED08:
    // bne         $v0, $a3, L_8002ED1C
    if (ctx->r2 != ctx->r7) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_8002ED1C;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_8002ED10:
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
L_8002ED14:
    // j           L_8002ECD0
    // addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    goto L_8002ECD0;
    // addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
L_8002ED1C:
    // jr          $ra
    // nop

    return;
    // nop

;}
