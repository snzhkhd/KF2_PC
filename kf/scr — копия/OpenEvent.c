#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libapi.h"

void KF_OpenEvent(uint8_t* rdram, recomp_context* ctx) {
    uint32_t desc = (uint32_t)ctx->r4; // Класс события (напр. 0xF2000001)
    int spec = (int)ctx->r5;      // Спецификация
    int mode = (int)ctx->r6;      // Режим (0x2000 - callback, 0x1000 - flag)
    uint32_t func = (uint32_t)ctx->r7; // Адрес функции в памяти PS1 (если есть)

    // ВАЖНО: Если игра передает функцию-обработчик (func != 0), 
    // Psy-X ожидает нативный указатель. Для начала передаем NULL.
    // Большинство игр (включая KF2) используют события только для VSync, 
    // где обработчик не нужен, просто ждут через WaitEvent.
    ctx->r2 = (uint32_t)OpenEvent(desc, spec, mode, NULL);
    ;
}
