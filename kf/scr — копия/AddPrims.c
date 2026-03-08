#include "..//_context.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"
#include <stdio.h>

void KF_AddPrims(uint8_t* rdram, recomp_context* ctx)
{
    // Согласно твоему анализу в IDA:
    // a0 (r4) - Указатель на ячейку в Ordering Table (куда вставляем цепочку)
    // a1 (r5) - Адрес начала цепочки (который станет новым указателем в OT)
    // a2 (r6) - Указатель на TAG последнего элемента цепочки
    // a3 (r7) - Маска (обычно 0x00FFFFFF)
    //printf("KF_AddPrims\n");
    //uint32_t* ot_cell = (uint32_t*)GET_PTR(ctx->r4);
    //uint32_t* last_prim_tag = (uint32_t*)GET_PTR(ctx->r6);
    //uint32_t mask = ctx->r7;

    //// 1. Последний элемент цепочки должен указывать туда, куда раньше указывал OT
    //*last_prim_tag = (*last_prim_tag & 0xFF000000) | (*ot_cell & mask);

    //// 2. Ячейка OT теперь указывает на начало нашей новой цепочки
    //uint32_t result = (*ot_cell & 0xFF000000) | (ctx->r5 & mask);
    //*ot_cell = result;

    //ctx->r2 = result;

    // a0 (r4) - куда вставляем (Ordering Table entry)
    void* ot = GET_PTR(ctx->r4);

    // a1 (r5) - начало нашей цепочки (p0)
    void* p0 = GET_PTR(ctx->r5);

    // a2 (r6) - конец нашей цепочки (p1)
    void* p1 = GET_PTR(ctx->r6);

    // Вызываем Psy-X
    if (ot && p0 && p1) {
        AddPrims(ot, p0, p1);
    }

}
