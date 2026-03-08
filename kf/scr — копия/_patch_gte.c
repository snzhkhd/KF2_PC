#include "recomp.h"
#include "disable_warnings.h"

void _patch_gte(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $ra, 0x6424($at)
    MEM_W(0X6424, ctx->r1) = ctx->r31;
    // jal         0x80062840
    // nop

    KF_EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $t2, $zero, 0xB0
    ctx->r10 = ADD32(0, 0XB0);
    // jalr        $t2
    // addiu       $t1, $zero, 0x56
    ctx->r9 = ADD32(0, 0X56);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    goto after_1;
    // addiu       $t1, $zero, 0x56
    ctx->r9 = ADD32(0, 0X56);
    after_1:
    // lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(0X18, ctx->r2);
    // addiu       $t2, $t2, -0x9A0
    ctx->r10 = ADD32(ctx->r10, -0X9A0);
    // addiu       $t1, $t1, -0x968
    ctx->r9 = ADD32(ctx->r9, -0X968);
L_8005F628:
    // lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(0X0, ctx->r10);
    // addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // bne         $t2, $t1, L_8005F628
    if (ctx->r10 != ctx->r9) {
        // sw          $v1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r3;
        goto L_8005F628;
    }
    // sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // jal         0x80062B50
    // nop

    KF_FlushCache(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80062AF0
    // nop

    KF_ExitCriticalSection(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $ra, 0x8007
    ctx->r31 = S32(0X8007 << 16);
    // lw          $ra, 0x6424($ra)
    ctx->r31 = MEM_W(0X6424, ctx->r31);
    // nop

    // jr          $ra
    // nop

    return;
    // nop

;}
