#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_NextPrim(uint8_t* rdram, recomp_context* ctx)
{
    // 1. Получаем адрес текущего примитива из r4 (a0)
    void* p = GET_PTR(ctx->r4);

    // 2. Вызываем Psy-X. 
    // Она вернет указатель в памяти нашего процесса (напр. 0x000001D2...)
    void* next_host_ptr = nextPrim(p);

    // 3. Конвертируем обратно в адрес PS1 для регистра r2 (v0)
    if (next_host_ptr == (void*)-1 || !next_host_ptr) {
        ctx->r2 = 0xFFFFFFFF; // Маркер конца списка
    }
    else {
        // Считаем разницу между указателями, чтобы получить офсет
        uint32_t offset = (uint32_t)((uint8_t*)next_host_ptr - rdram);
        ctx->r2 = 0x80000000 | (offset & 0x1FFFFF);
    }
}