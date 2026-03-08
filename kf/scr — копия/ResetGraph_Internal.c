#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"
#include <cstring>

void ResetGraph_Internal(uint8_t* rdram, recomp_context* ctx) 
{
    int mode = (int)ctx->r4;
    printf("[HLE GPU] ResetGraph(%d) called\n", mode);

    // 1. Сбрасываем Psy-X
    ctx->r2 = ResetGraph(mode);

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

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // addu        $s0, $a0, $zero
//    ctx->r16 = ADD32(ctx->r4, 0);
//    // sw          $ra, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r31;
//    // jal         0x80061CD0
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    SetIntrMask(rdram, ctx);
//    goto after_0;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_0:
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
//    // andi        $v1, $s0, 0x7
//    ctx->r3 = ctx->r16 & 0X7;
//    // beq         $v1, $zero, L_80065378
//    if (ctx->r3 == 0) {
//        // ori         $v0, $zero, 0x1
//        ctx->r2 = 0 | 0X1;
//        goto L_80065378;
//    }
//    // ori         $v0, $zero, 0x1
//    ctx->r2 = 0 | 0X1;
//    // beq         $v1, $v0, L_800653DC
//    if (ctx->r3 == ctx->r2) {
//        // ori         $v0, $zero, 0x401
//        ctx->r2 = 0 | 0X401;
//        goto L_800653DC;
//    }
//    // ori         $v0, $zero, 0x401
//    ctx->r2 = 0 | 0X401;
//    // j           L_80065428
//    // nop
//
//    goto L_80065428;
//    // nop
//
//L_80065378:
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
//    // lui         $a0, 0x8008
//    ctx->r4 = S32(0X8008 << 16);
//    // addiu       $a0, $a0, -0x6FB4
//    ctx->r4 = ADD32(ctx->r4, -0X6FB4);
//    // lw          $v0, 0x0($v1)
//    ctx->r2 = MEM_W(0X0, ctx->r3);
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    // ori         $v0, $v0, 0x800
//    ctx->r2 = ctx->r2 | 0X800;
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x6274($v0)
//    ctx->r2 = MEM_W(0X6274, ctx->r2);
//    // ori         $a2, $zero, 0x100
//    ctx->r6 = 0 | 0X100;
//    // sw          $zero, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = 0;
//    // jal         0x80065828
//    // nop
//
//    memset_1(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // lui         $a0, 0x801C
//    ctx->r4 = S32(0X801C << 16);
//    // addiu       $a0, $a0, -0x7530
//    ctx->r4 = ADD32(ctx->r4, -0X7530);
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    // jal         0x80065828
//    // ori         $a2, $zero, 0x1800
//    ctx->r6 = 0 | 0X1800;
//    memset_1(rdram, ctx);
//    goto after_2;
//    // ori         $a2, $zero, 0x1800
//    ctx->r6 = 0 | 0X1800;
//    after_2:
//    // j           L_80065428
//    // nop
//
//    goto L_80065428;
//    // nop
//
//L_800653DC:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6280($v1)
//    ctx->r3 = MEM_W(0X6280, ctx->r3);
//    // nop
//
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
//L_80065428:
//    // lui         $a0, 0x8007
//    ctx->r4 = S32(0X8007 << 16);
//    // lw          $a0, 0x62B4($a0)
//    ctx->r4 = MEM_W(0X62B4, ctx->r4);
//    // jal         0x80061CD0
//    // nop
//
//    SetIntrMask(rdram, ctx);
//    goto after_3;
//    // nop
//
//    after_3:
//    // andi        $v0, $s0, 0x7
//    ctx->r2 = ctx->r16 & 0X7;
//    // bne         $v0, $zero, L_8006544C
//    if (ctx->r2 != 0) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_8006544C;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // jal         0x80065748
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    sub_80065748(rdram, ctx);
//    goto after_4;
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    after_4:
//L_8006544C:
//    // lw          $ra, 0x14($sp)
//    ctx->r31 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
