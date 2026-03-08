#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

//void SetupGTE(uint8_t* rdram, recomp_context* ctx)
//{
//    uint32_t struct_addr = ctx->r4; // a0 (адрес структуры камеры)
//    int width = (int)ctx->r5;       // a1 (320)
//    int height = (int)ctx->r6;      // a2 (240)
//    int dist = (int)ctx->r7;        // a3 (100)
//
//    // Аргументы со стека
//    int a4 = (int)MEM_W(16, ctx->r29); // 0
//    int a5 = (int)MEM_W(20, ctx->r29); // 0x10000
//
//    // --- Логика из игры (восстановлена по дизассемблеру) ---
//    // FromSoftware вычисляет коэффициенты для проекции
//
//    int v7 = width / 2;
//    int v10 = height / 2;
//
//    // Защита от деления на ноль (из оригинала)
//    if (v7 == 0 || v10 == 0 || dist == 0) {
//        printf("[HLE ERROR] SetupGTE called with invalid args!\n");
//        return;
//    }
//
//    int v8 = dist << 12;
//    int v9 = v8 / v7;      // Scale X
//    int v11 = v8 / v10;    // Scale Y
//
//    // Вычисление соотношений сторон?
//    int v12 = v7 << 12;
//    int v13 = (dist != 0) ? (v12 / dist) : 0;
//
//    int v14 = v10 << 12;
//    int v15 = (dist != 0) ? (v14 / dist) : 0;
//
//    // --- Запись в память игры (КРИТИЧНО ВАЖНО!) ---
//    // Используем смещения из твоего дизассемблера: v6[59], v6[99] и т.д.
//    // v6 - это указатель на int32 (слова)
//
//    uint32_t* v6 = (uint32_t*)GET_PTR(struct_addr);
//
//    v6[59] = struct_addr; // a1 в оригинале был первым аргументом (адрес)
//    v6[103] = a4;
//    v6[102] = a5;
//    v6[99] = v9;  // Коэффициент масштабирования X
//    v6[101] = v11; // Коэффициент масштабирования Y
//    v6[98] = v13;
//    v6[100] = v15;
//
//    // --- Настройка Psy-X ---
//    SetGeomOffset(v7, v10); // Центр экрана (160, 120)
//    SetGeomScreen(dist);    // Дистанция (100)
//
//    printf("[HLE GTE] SetupGTE: W=%d, H=%d, Dist=%d. Struct updated at 0x%08X\n", width, height, dist, struct_addr);
//
//    ctx->r2 = v15; // Оригинал возвращает v15
//}

void KF_InitClip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // srl         $v1, $a1, 31
    ctx->r3 = S32(U32(ctx->r5) >> 31);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $a1, $a3, 12
    ctx->r5 = S32(ctx->r7) << 12;
    // div         $zero, $a1, $v1
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8005EF58
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8005EF58;
    }
    // nop

    // break       7
    do_break(2147872596);
L_8005EF58:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8005EF70
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8005EF70;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a1, $at, L_8005EF70
    if (ctx->r5 != ctx->r1) {
        // nop
    
        goto L_8005EF70;
    }
    // nop

    // break       6
    do_break(2147872620);
L_8005EF70:
    // mflo        $t0
    ctx->r8 = lo;
    // srl         $v0, $a2, 31
    ctx->r2 = S32(U32(ctx->r6) >> 31);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8005EF90
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005EF90;
    }
    // nop

    // break       7
    do_break(2147872652);
L_8005EF90:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8005EFA8
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8005EFA8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a1, $at, L_8005EFA8
    if (ctx->r5 != ctx->r1) {
        // nop
    
        goto L_8005EFA8;
    }
    // nop

    // break       6
    do_break(2147872676);
L_8005EFA8:
    // mflo        $a1
    ctx->r5 = lo;
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // div         $zero, $v1, $a3
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r7)));
    // bne         $a3, $zero, L_8005EFC0
    if (ctx->r7 != 0) {
        // nop
    
        goto L_8005EFC0;
    }
    // nop

    // break       7
    do_break(2147872700);
L_8005EFC0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a3, $at, L_8005EFD8
    if (ctx->r7 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8005EFD8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8005EFD8
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8005EFD8;
    }
    // nop

    // break       6
    do_break(2147872724);
L_8005EFD8:
    // mflo        $v1
    ctx->r3 = lo;
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // div         $zero, $v0, $a3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r7)));
    // bne         $a3, $zero, L_8005EFF0
    if (ctx->r7 != 0) {
        // nop
    
        goto L_8005EFF0;
    }
    // nop

    // break       7
    do_break(2147872748);
L_8005EFF0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a3, $at, L_8005F008
    if (ctx->r7 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8005F008;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8005F008
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8005F008;
    }
    // nop

    // break       6
    do_break(2147872772);
L_8005F008:
    // mflo        $v0
    ctx->r2 = lo;
    // lw          $a2, 0x10($sp)
    ctx->r6 = MEM_W(0X10, ctx->r29);
    // lw          $a3, 0x14($sp)
    ctx->r7 = MEM_W(0X14, ctx->r29);
    // sw          $a0, 0xEC($gp)
    MEM_W(0XEC, ctx->r28) = ctx->r4;
    // sw          $a2, 0x19C($gp)
    MEM_W(0X19C, ctx->r28) = ctx->r6;
    // sw          $a3, 0x198($gp)
    MEM_W(0X198, ctx->r28) = ctx->r7;
    // sw          $t0, 0x18C($gp)
    MEM_W(0X18C, ctx->r28) = ctx->r8;
    // sw          $a1, 0x194($gp)
    MEM_W(0X194, ctx->r28) = ctx->r5;
    // sw          $v1, 0x188($gp)
    MEM_W(0X188, ctx->r28) = ctx->r3;
    // sw          $v0, 0x190($gp)
    MEM_W(0X190, ctx->r28) = ctx->r2;
    // jr          $ra
    // nop

    return;
    // nop

;}
