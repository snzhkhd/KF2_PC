#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libspu.h"

void KF_SpuInitMalloc(uint8_t* rdram, recomp_context* ctx)
{
    // 1. Первый аргумент (int num) — количество блоков.
    // Передается по значению в r4 (a0).
    int num = (int)ctx->r4;

    // 2. Второй аргумент (char *top) — указатель на буфер в RAM игры.
    // Это адрес, поэтому превращаем его в наш указатель через GET_PTR.
    char* top = (char*)GET_PTR(ctx->r5);

    // 3. Вызываем Psy-X. 
    int result = SpuInitMalloc(num, top);

    // 4. Записываем результат в r2 (v0).
    ctx->r2 = (uint32_t)result;
    ;
}


//void KF_SpuInitMalloc(uint8_t* rdram, recomp_context* ctx) {
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addu        $v0, $a0, $zero
//    ctx->r2 = ADD32(ctx->r4, 0);
//    // bgtz        $v0, L_80059758
//    if (SIGNED(ctx->r2) > 0) {
//        // lui         $v1, 0x4000
//        ctx->r3 = S32(0X4000 << 16);
//        goto L_80059758;
//    }
//    // lui         $v1, 0x4000
//    ctx->r3 = S32(0X4000 << 16);
//    // j           L_80059790
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    goto L_80059790;
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_80059758:
//    // lui         $a0, 0x8007
//    ctx->r4 = S32(0X8007 << 16);
//    // lw          $a0, -0x7A8($a0)
//    ctx->r4 = MEM_W(-0X7A8, ctx->r4);
//    // ori         $v1, $v1, 0x1010
//    ctx->r3 = ctx->r3 | 0X1010;
//    // sw          $v1, 0x0($a1)
//    MEM_W(0X0, ctx->r5) = ctx->r3;
//    // lui         $v1, 0x1
//    ctx->r3 = S32(0X1 << 16);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $a1, 0x28($at)
//    MEM_W(0X28, ctx->r1) = ctx->r5;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $zero, 0x24($at)
//    MEM_W(0X24, ctx->r1) = 0;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, 0x20($at)
//    MEM_W(0X20, ctx->r1) = ctx->r2;
//    // sllv        $v1, $v1, $a0
//    ctx->r3 = S32(ctx->r3) << (ctx->r4 & 31);
//    // addiu       $v1, $v1, -0x1010
//    ctx->r3 = ADD32(ctx->r3, -0X1010);
//    // sw          $v1, 0x4($a1)
//    MEM_W(0X4, ctx->r5) = ctx->r3;
//L_80059790:
//    // jr          $ra
//    // nop
//
//    return;
//    // nop
//
//;}
