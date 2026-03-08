#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"

void KF_ClearImage(uint8_t* rdram, recomp_context* ctx) 
{
    uint32_t rect_addr = ctx->r4;
    uint32_t color = ctx->r5;

    // Распаковываем цвет
    uint8_t r = color & 0xFF;
    uint8_t g = (color >> 8) & 0xFF;
    uint8_t b = (color >> 16) & 0xFF;

    // Получаем реальный указатель на RECT в памяти ПК
    RECT16* rect = (RECT16*)GET_PTR(rect_addr);

    if (rect) {
        printf("[HLE GPU] ClearImage(x=%d, y=%d, w=%d, h=%d, R=%d, G=%d, B=%d)\n",
            rect->x, rect->y, rect->w, rect->h, r, g, b);

        // Вызываем функцию очистки экрана из Psy-X (OpenGL)
        ClearImage(rect, r, g, b);
    }

    ctx->r2 = 0;

    /*
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v1, 0x4($t0)
    ctx->r3 = MEM_H(0X4, ctx->r8);
    // nop

    // bltz        $v1, L_80064530
    if (SIGNED(ctx->r3) < 0) {
        // addu        $t1, $a1, $zero
        ctx->r9 = ADD32(ctx->r5, 0);
        goto L_80064530;
    }
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61A4
    ctx->r2 = ADD32(ctx->r2, 0X61A4);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80064534
    if (ctx->r2 == 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80064534;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // j           L_80064534
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    goto L_80064534;
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80064530:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80064534:
    // lh          $v1, 0x6($t0)
    ctx->r3 = MEM_H(0X6, ctx->r8);
    // nop

    // bltz        $v1, L_80064574
    if (SIGNED(ctx->r3) < 0) {
        // sh          $v0, 0x4($t0)
        MEM_H(0X4, ctx->r8) = ctx->r2;
        goto L_80064574;
    }
    // sh          $v0, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r2;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x61A6
    ctx->r2 = ADD32(ctx->r2, 0X61A6);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80064578
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80064578;
    }
    // nop

    // j           L_80064578
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    goto L_80064578;
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80064574:
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80064578:
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // nop

    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // bne         $v0, $zero, L_800645A0
    if (ctx->r2 != 0) {
        // sh          $v1, 0x6($t0)
        MEM_H(0X6, ctx->r8) = ctx->r3;
        goto L_800645A0;
    }
    // sh          $v1, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r3;
    // lhu         $v0, 0x4($t0)
    ctx->r2 = MEM_HU(0X4, ctx->r8);
    // nop

    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // beq         $v0, $zero, L_80064678
    if (ctx->r2 == 0) {
        // lui         $v0, 0x4FF
        ctx->r2 = S32(0X4FF << 16);
        goto L_80064678;
    }
    // lui         $v0, 0x4FF
    ctx->r2 = S32(0X4FF << 16);
L_800645A0:
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // lui         $a1, 0xE4FF
    ctx->r5 = S32(0XE4FF << 16);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // lui         $a3, 0x3FF
    ctx->r7 = S32(0X3FF << 16);
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // addiu       $a2, $a2, -0x6FD4
    ctx->r6 = ADD32(ctx->r6, -0X6FD4);
    // and         $v0, $a2, $a0
    ctx->r2 = ctx->r6 & ctx->r4;
    // lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // lui         $s0, 0xE300
    ctx->r16 = S32(0XE300 << 16);
    // lui         $s1, 0xE500
    ctx->r17 = S32(0XE500 << 16);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FF4($at)
    MEM_W(-0X6FF4, ctx->r1) = ctx->r2;
    // lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // and         $a0, $t1, $a0
    ctx->r4 = ctx->r9 & ctx->r4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FE4($at)
    MEM_W(-0X6FE4, ctx->r1) = ctx->r2;
    // lui         $v0, 0x6000
    ctx->r2 = S32(0X6000 << 16);
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $s0, -0x6FF0($at)
    MEM_W(-0X6FF0, ctx->r1) = ctx->r16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a1, -0x6FEC($at)
    MEM_W(-0X6FEC, ctx->r1) = ctx->r5;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $s1, -0x6FE8($at)
    MEM_W(-0X6FE8, ctx->r1) = ctx->r17;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a0, -0x6FE0($at)
    MEM_W(-0X6FE0, ctx->r1) = ctx->r4;
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FDC($at)
    MEM_W(-0X6FDC, ctx->r1) = ctx->r2;
    // lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(0X4, ctx->r8);
    // sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FD8($at)
    MEM_W(-0X6FD8, ctx->r1) = ctx->r2;
    // jal         0x80064CC8
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    sub_80064CC8(rdram, ctx);
    goto after_0;
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    after_0:
    // or          $v0, $v0, $s0
    ctx->r2 = ctx->r2 | ctx->r16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FD0($at)
    MEM_W(-0X6FD0, ctx->r1) = ctx->r2;
    // jal         0x80064CC8
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    sub_80064CC8(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    after_1:
    // lui         $v1, 0xE400
    ctx->r3 = S32(0XE400 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FCC($at)
    MEM_W(-0X6FCC, ctx->r1) = ctx->r2;
    // jal         0x80064CC8
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    sub_80064CC8(rdram, ctx);
    goto after_2;
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    after_2:
    // or          $v0, $v0, $s1
    ctx->r2 = ctx->r2 | ctx->r17;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FC8($at)
    MEM_W(-0X6FC8, ctx->r1) = ctx->r2;
    // j           L_800646CC
    // nop

    goto L_800646CC;
    // nop

L_80064678:
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FF4($at)
    MEM_W(-0X6FF4, ctx->r1) = ctx->r2;
    // lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // and         $v1, $t1, $v1
    ctx->r3 = ctx->r9 & ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FF0($at)
    MEM_W(-0X6FF0, ctx->r1) = ctx->r2;
    // lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, -0x6FEC($at)
    MEM_W(-0X6FEC, ctx->r1) = ctx->r3;
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FE8($at)
    MEM_W(-0X6FE8, ctx->r1) = ctx->r2;
    // lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(0X4, ctx->r8);
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, -0x6FE4($at)
    MEM_W(-0X6FE4, ctx->r1) = ctx->r2;
L_800646CC:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, -0x6FF4
    ctx->r4 = ADD32(ctx->r4, -0X6FF4);
    // jal         0x80064C7C
    // nop

    TriggerGpuDma(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
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
    */
;}
