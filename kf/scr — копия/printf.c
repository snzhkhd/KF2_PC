#include "_context.h"
#include "recomp.h"
#include "disable_warnings.h"
#include <string>

void psx_printf(uint8_t* rdram, recomp_context* ctx) 
{
    uint32_t fmt_ptr = ctx->r4; // $a0
    if (fmt_ptr < 0x80000000 || fmt_ptr >= 0x80200000) return;

    const char* fmt = (const char*)&rdram[fmt_ptr & 0x1FFFFF];

    // Собираем аргументы ($a1, $a2, $a3, и один со стека)
    uint32_t args[4] = { ctx->r5, ctx->r6, ctx->r7, *(uint32_t*)&rdram[(ctx->r29 + 0x10) & 0x1FFFFF] };
    int arg_idx = 0;

    printf("[GAME] ");
    for (int i = 0; fmt[i] != '\0'; i++) {
        if (fmt[i] == '%' && fmt[i + 1] != '\0') {
            i++;
            // Пропускаем флаги форматирования (типа %08X, %2d)
            while ((fmt[i] >= '0' && fmt[i] <= '9') || fmt[i] == 'l') i++;

            uint32_t val = (arg_idx < 4) ? args[arg_idx++] : 0;

            if (fmt[i] == 's') { // Безопасное чтение строк!
                if (val >= 0x80000000 && val < 0x80200000) {
                    printf("%s", &rdram[val & 0x1FFFFF]);
                }
                else {
                    printf("null_ptr");
                }
            }
            else if (fmt[i] == 'd' || fmt[i] == 'i') {
                printf("%d", (int)val);
            }
            else if (fmt[i] == 'x' || fmt[i] == 'X') {
                printf("%X", val);
            }
            else if (fmt[i] == 'c') {
                printf("%c", (char)val);
            }
        }
        else {
            putchar(fmt[i]);
        }
    }

    if (strlen(fmt) > 0 && fmt[strlen(fmt) - 1] != '\n') 
        printf("\n");
    ctx->r2 = 0;
    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// addiu       $t2, $zero, 0xA0
    //ctx->r10 = ADD32(0, 0XA0);
    //// jr          $t2
    //// addiu       $t1, $zero, 0x3F
    //ctx->r9 = ADD32(0, 0X3F);
    //LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    //return;
    //// addiu       $t1, $zero, 0x3F
    //ctx->r9 = ADD32(0, 0X3F);
}
