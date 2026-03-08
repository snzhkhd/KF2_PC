#include "_context.h"
#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"
#include <cstring>

void KF_ResetGraph(uint8_t* rdram, recomp_context* ctx)
{
    //int mode = (int)ctx->r4;
    //printf("[HLE GPU] ResetGraph(%d) called\n", mode);

    //// 1. Сбрасываем Psy-X
    //ResetGraph(mode);

    //// 2. Эмулируем логику игры: зануляем внутренние структуры в rdram
    //// Адреса из IDA
    //memset(GET_PTR(0x800761A0), 0, 128);       // Текущий Env
    //memset(GET_PTR(0x800761B0), 0xFF, 0x5C);   // DRAWENV backup
    //memset(GET_PTR(0x8007620C), 0xFF, 20);     // Еще одна таблица

    //// Если mode == 0 (полный сброс), чистим таблицы примитивов
    //if (mode == 0) {
    //    memset(GET_PTR(0x8007904C), 0, 0x100); // Таблица команд
    //    memset(GET_PTR(0x801B8AD0), 0, 6144);  // Огромный буфер (вертексы?)
    //}

    //// 3. ВОССТАНАВЛИВАЕМ БИТЫ ГОТОВНОСТИ GPU
    //// После ResetGraph_Internal игра обнулила этот регистр.
    //// Нам нужно вернуть 0x1C000000 (Ready), иначе следующая функция зависнет.
    //uint32_t* gpu_stat = (uint32_t*)GET_PTR(0x1F801814);
    //*gpu_stat = 0x1C000000;

    //ctx->r2 = 0;

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // andi        $v0, $s1, 0x7
    ctx->r2 = ctx->r17 & 0X7;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // bne         $v0, $zero, L_80062D24
    if (ctx->r2 != 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80062D24;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3670
    ctx->r4 = ADD32(ctx->r4, 0X3670);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x6158
    ctx->r5 = ADD32(ctx->r5, 0X6158);
    // lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // addiu       $s0, $s0, 0x61A0
    ctx->r16 = ADD32(ctx->r16, 0X61A0);
    // jal         0x80062BA0
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    psx_printf(rdram, ctx);
    goto after_0;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80065828
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    memset_1(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x80
    ctx->r6 = 0 | 0X80;
    after_1:
    // jal         0x80061B54
    // nop

    KF_ResetCallback(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x6198($a0)
    ctx->r4 = MEM_W(0X6198, ctx->r4);
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // jal         0x80065854
    // and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    GPU_cw(rdram, ctx);
    goto after_3;
    // and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    after_3:
    // jal         0x80065324
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    ResetGraph_Internal(rdram, ctx);
    goto after_4;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sb          $v1, 0x61A1($at)
    MEM_B(0X61A1, ctx->r1) = ctx->r3;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x6220
    ctx->r1 = ADD32(ctx->r1, 0X6220);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v1, 0x0($at)
    ctx->r3 = MEM_HU(0X0, ctx->r1);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v1, 0x61A4($at)
    MEM_H(0X61A4, ctx->r1) = ctx->r3;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // addiu       $at, $at, 0x6234
    ctx->r1 = ADD32(ctx->r1, 0X6234);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v0, 0x0($at)
    ctx->r2 = MEM_HU(0X0, ctx->r1);
    // nop

    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sh          $v0, 0x61A6($at)
    MEM_H(0X61A6, ctx->r1) = ctx->r2;
    // jal         0x80065828
    // ori         $a2, $zero, 0x5C
    ctx->r6 = 0 | 0X5C;
    memset_1(rdram, ctx);
    goto after_5;
    // ori         $a2, $zero, 0x5C
    ctx->r6 = 0 | 0X5C;
    after_5:
    // addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // jal         0x80065828
    // ori         $a2, $zero, 0x14
    ctx->r6 = 0 | 0X14;
    memset_1(rdram, ctx);
    goto after_6;
    // ori         $a2, $zero, 0x14
    ctx->r6 = 0 | 0X14;
    after_6:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // j           L_80062D74
    // nop

    goto L_80062D74;
    // nop

L_80062D24:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lbu         $v0, 0x61A2($v0)
    ctx->r2 = MEM_BU(0X61A2, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80062D58
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80062D58;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3690
    ctx->r4 = ADD32(ctx->r4, 0X3690);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x619C($v0)
    ctx->r2 = MEM_W(0X619C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_7;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_7:
L_80062D58:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6198($v0)
    ctx->r2 = MEM_W(0X6198, ctx->r2);
    // nop

    // lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(0X34, ctx->r2);
    // nop

    // jalr        $v0
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    after_8:
L_80062D74:
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

}