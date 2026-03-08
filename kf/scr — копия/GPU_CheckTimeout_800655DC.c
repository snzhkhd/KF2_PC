#include "recomp.h"
#include "disable_warnings.h"
static uint32_t last_local_vsync = 0;

void GPU_CheckTimeout_800655DC(uint8_t* rdram, recomp_context* ctx)
{
    // 1. Очищаем бит занятости DMA (Канал 2 - GPU)
    // 0x1F8010A8 - это CHCR2. Мы должны снять бит 0x01000000 (DMA Enable)
    uint32_t* chcr2 = (uint32_t*)&rdram[0x1F8010A8 & 0x1FFFFF];
    *chcr2 &= ~0x01000000;

    // 2. Ставим флаги готовности в GPU STAT (0x1F801814)
    // Говорим, что GPU готов принимать данные через DMA (бит 28) и GP0 (бит 26)
    uint32_t* gpu_stat = (uint32_t*)&rdram[0x1F801814 & 0x1FFFFF];
    *gpu_stat |= 0x14000000;

    // 3. Возвращаем 0 (ошибки таймаута нет, всё прошло "мгновенно")
    ctx->r2 = 0;
    //    uint64_t hi = 0, lo = 0, result = 0;
    //    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //    int c1cs = 0; 
    //    // addiu       $sp, $sp, -0x20
    //    ctx->r29 = ADD32(ctx->r29, -0X20);
    //    // sw          $ra, 0x18($sp)
    //    MEM_W(0X18, ctx->r29) = ctx->r31;
    //    // jal         0x8006263C
    //    // addiu       $a0, $zero, -0x1
    //    ctx->r4 = ADD32(0, -0X1);
    //    KF_VSync(rdram, ctx);
    //    goto after_0;
    //    // addiu       $a0, $zero, -0x1
    //    ctx->r4 = ADD32(0, -0X1);
    //    after_0:
    //    // lui         $v1, 0x8007
    //    ctx->r3 = S32(0X8007 << 16);
    //    // lw          $v1, 0x62B8($v1)
    //    ctx->r3 = MEM_W(0X62B8, ctx->r3);
    //    // nop
    //
    //    // slt         $v1, $v1, $v0
    //    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    //    // bne         $v1, $zero, L_8006562C
    //    if (ctx->r3 != 0) {
    //        // nop
    //    
    //        goto L_8006562C;
    //    }
    //    // nop
    //
    //    // lui         $v1, 0x8007
    //    ctx->r3 = S32(0X8007 << 16);
    //    // lw          $v1, 0x62BC($v1)
    //    ctx->r3 = MEM_W(0X62BC, ctx->r3);
    //    // nop
    //
    //    // addiu       $v0, $v1, 0x1
    //    ctx->r2 = ADD32(ctx->r3, 0X1);
    //    // lui         $at, 0x8007
    //    ctx->r1 = S32(0X8007 << 16);
    //    // sw          $v0, 0x62BC($at)
    //    MEM_W(0X62BC, ctx->r1) = ctx->r2;
    //    // lui         $v0, 0xF
    //    ctx->r2 = S32(0XF << 16);
    //    // slt         $v0, $v0, $v1
    //    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    //    // beq         $v0, $zero, L_80065734
    //    if (ctx->r2 == 0) {
    //        // nop
    //    
    //        goto L_80065734;
    //    }
    //    // nop
    //
    //L_8006562C:
    //    // lui         $v1, 0x8007
    //    ctx->r3 = S32(0X8007 << 16);
    //    // lw          $v1, 0x6274($v1)
    //    ctx->r3 = MEM_W(0X6274, ctx->r3);
    //    // lui         $a0, 0x8001
    //    ctx->r4 = S32(0X8001 << 16);
    //    // addiu       $a0, $a0, 0x3808
    //    ctx->r4 = ADD32(ctx->r4, 0X3808);
    //    // lw          $v0, 0x0($v1)
    //    ctx->r2 = MEM_W(0X0, ctx->r3);
    //    // lui         $a1, 0x8007
    //    ctx->r5 = S32(0X8007 << 16);
    //    // lw          $a1, 0x62A4($a1)
    //    ctx->r5 = MEM_W(0X62A4, ctx->r5);
    //    // lui         $v0, 0x8007
    //    ctx->r2 = S32(0X8007 << 16);
    //    // lw          $v0, 0x6278($v0)
    //    ctx->r2 = MEM_W(0X6278, ctx->r2);
    //    // lui         $t0, 0x8007
    //    ctx->r8 = S32(0X8007 << 16);
    //    // lw          $t0, 0x62A8($t0)
    //    ctx->r8 = MEM_W(0X62A8, ctx->r8);
    //    // lw          $v0, 0x0($v0)
    //    ctx->r2 = MEM_W(0X0, ctx->r2);
    //    // subu        $a1, $a1, $t0
    //    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    //    // sw          $v0, 0x10($sp)
    //    MEM_W(0X10, ctx->r29) = ctx->r2;
    //    // lui         $v0, 0x8007
    //    ctx->r2 = S32(0X8007 << 16);
    //    // lw          $v0, 0x6280($v0)
    //    ctx->r2 = MEM_W(0X6280, ctx->r2);
    //    // lw          $a2, 0x0($v1)
    //    ctx->r6 = MEM_W(0X0, ctx->r3);
    //    // lw          $a3, 0x0($v0)
    //    ctx->r7 = MEM_W(0X0, ctx->r2);
    //    // jal         0x80062BA0
    //    // andi        $a1, $a1, 0x3F
    //    ctx->r5 = ctx->r5 & 0X3F;
    //    ps1_printf(rdram, ctx);
    //    goto after_1;
    //    // andi        $a1, $a1, 0x3F
    //    ctx->r5 = ctx->r5 & 0X3F;
    //    after_1:
    //    // lui         $v0, 0x8007
    //    ctx->r2 = S32(0X8007 << 16);
    //    // addiu       $v0, $v0, 0x6294
    //    ctx->r2 = ADD32(ctx->r2, 0X6294);
    //    // lw          $a1, 0x0($v0)
    //    ctx->r5 = MEM_W(0X0, ctx->r2);
    //    // lui         $a2, 0x8007
    //    ctx->r6 = S32(0X8007 << 16);
    //    // lw          $a2, 0x6298($a2)
    //    ctx->r6 = MEM_W(0X6298, ctx->r6);
    //    // lui         $a3, 0x8007
    //    ctx->r7 = S32(0X8007 << 16);
    //    // lw          $a3, 0x629C($a3)
    //    ctx->r7 = MEM_W(0X629C, ctx->r7);
    //    // lui         $a0, 0x8001
    //    ctx->r4 = S32(0X8001 << 16);
    //    // addiu       $a0, $a0, 0x383C
    //    ctx->r4 = ADD32(ctx->r4, 0X383C);
    //    // jal         0x80062BA0
    //    // nop
    //
    //    ps1_printf(rdram, ctx);
    //    goto after_2;
    //    // nop
    //
    //    after_2:
    //    // jal         0x80061CD0
    //    // addu        $a0, $zero, $zero
    //    ctx->r4 = ADD32(0, 0);
    //    SetIntrMask(rdram, ctx);
    //    goto after_3;
    //    // addu        $a0, $zero, $zero
    //    ctx->r4 = ADD32(0, 0);
    //    after_3:
    //    // lui         $at, 0x8007
    //    ctx->r1 = S32(0X8007 << 16);
    //    // sw          $zero, 0x62A8($at)
    //    MEM_W(0X62A8, ctx->r1) = 0;
    //    // lui         $v1, 0x8007
    //    ctx->r3 = S32(0X8007 << 16);
    //    // lw          $v1, 0x62A8($v1)
    //    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    //    // lui         $at, 0x8007
    //    ctx->r1 = S32(0X8007 << 16);
    //    // sw          $v0, 0x62B4($at)
    //    MEM_W(0X62B4, ctx->r1) = ctx->r2;
    //    // lui         $at, 0x8007
    //    ctx->r1 = S32(0X8007 << 16);
    //    // sw          $v1, 0x62A4($at)
    //    MEM_W(0X62A4, ctx->r1) = ctx->r3;
    //    // lui         $v1, 0x8007
    //    ctx->r3 = S32(0X8007 << 16);
    //    // lw          $v1, 0x6280($v1)
    //    ctx->r3 = MEM_W(0X6280, ctx->r3);
    //    // ori         $v0, $zero, 0x401
    //    ctx->r2 = 0 | 0X401;
    //    // sw          $v0, 0x0($v1)
    //    MEM_W(0X0, ctx->r3) = ctx->r2;
    //    // lui         $v1, 0x8007
    //    ctx->r3 = S32(0X8007 << 16);
    //    // lw          $v1, 0x6290($v1)
    //    ctx->r3 = MEM_W(0X6290, ctx->r3);
    //    // nop
    //
    //    // lw          $v0, 0x0($v1)
    //    ctx->r2 = MEM_W(0X0, ctx->r3);
    //    // nop
    //
    //    // ori         $v0, $v0, 0x800
    //    ctx->r2 = ctx->r2 | 0X800;
    //    // sw          $v0, 0x0($v1)
    //    MEM_W(0X0, ctx->r3) = ctx->r2;
    //    // lui         $v1, 0x8007
    //    ctx->r3 = S32(0X8007 << 16);
    //    // lw          $v1, 0x6274($v1)
    //    ctx->r3 = MEM_W(0X6274, ctx->r3);
    //    // lui         $v0, 0x200
    //    ctx->r2 = S32(0X200 << 16);
    //    // sw          $v0, 0x0($v1)
    //    MEM_W(0X0, ctx->r3) = ctx->r2;
    //    // lui         $v1, 0x8007
    //    ctx->r3 = S32(0X8007 << 16);
    //    // lw          $v1, 0x6274($v1)
    //    ctx->r3 = MEM_W(0X6274, ctx->r3);
    //    // lui         $v0, 0x100
    //    ctx->r2 = S32(0X100 << 16);
    //    // sw          $v0, 0x0($v1)
    //    MEM_W(0X0, ctx->r3) = ctx->r2;
    //    // lui         $a0, 0x8007
    //    ctx->r4 = S32(0X8007 << 16);
    //    // lw          $a0, 0x62B4($a0)
    //    ctx->r4 = MEM_W(0X62B4, ctx->r4);
    //    // jal         0x80061CD0
    //    // nop
    //
    //    SetIntrMask(rdram, ctx);
    //    goto after_4;
    //    // nop
    //
    //    after_4:
    //    // j           L_80065738
    //    // addiu       $v0, $zero, -0x1
    //    ctx->r2 = ADD32(0, -0X1);
    //    goto L_80065738;
    //    // addiu       $v0, $zero, -0x1
    //    ctx->r2 = ADD32(0, -0X1);
    //L_80065734:
    //    // addu        $v0, $zero, $zero
    //    ctx->r2 = ADD32(0, 0);
    //L_80065738:
    //    // lw          $ra, 0x18($sp)
    //    ctx->r31 = MEM_W(0X18, ctx->r29);
    //    // addiu       $sp, $sp, 0x20
    //    ctx->r29 = ADD32(ctx->r29, 0X20);
    //    // jr          $ra
    //    // nop
    //
    //    return;
    //    // nop

    ;
}
