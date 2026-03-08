#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libetc.h"

// Глобальная переменная для хранения адреса функции игры
static uint32_t g_game_vsync_handler_addr = 0;

// Это "настоящая" C-функция, которую мы отдадим в Psy-X
void NativeVsyncBridge(void) {
    if (g_game_vsync_handler_addr != 0) {
        // Ищем рекомпилированную функцию по её адресу в RAM
        recomp_func_t func = lookup_recomp_func(g_game_vsync_handler_addr);
        if (func) {
            // Вызываем её, передавая глобальные контекст и память
            // g_ctx должен быть доступен 
            func(rdram, g_ctx);
        }
    }
}

// Твой мост для игры
void KF_VSyncCallback(uint8_t* rdram, recomp_context* ctx) {
    // Аргумент a0 (r4) — это адрес функции в памяти PS1
    g_game_vsync_handler_addr = ctx->r4;

    if (g_game_vsync_handler_addr == 0) {
        // Если игра передала 0, отключаем коллбек
        VSyncCallback(NULL);
    }
    else {
        // Регистрируем наш нативный мостик в Psy-X
        VSyncCallback(NativeVsyncBridge);
    }

    ctx->r2 = 0; // Возвращаем успех
}
//void KF_VSyncCallback(uint8_t* rdram, recomp_context* ctx) {
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, 0x60CC($v0)
//    ctx->r2 = MEM_W(0X60CC, ctx->r2);
//    // addu        $a1, $a0, $zero
//    ctx->r5 = ADD32(ctx->r4, 0);
//    // sw          $ra, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r31;
//    // lw          $v0, 0x14($v0)
//    ctx->r2 = MEM_W(0X14, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_0;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_0:
//    // lw          $ra, 0x10($sp)
//    ctx->r31 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop
//
//;}
