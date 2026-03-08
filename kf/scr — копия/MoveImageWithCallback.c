#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"

void MoveImageWithCallback(uint8_t* rdram, recomp_context* ctx) 
{

    uint32_t rect_addr = ctx->r4;  // a0: указатель на src RECT16
    uint16_t dst_x = (uint16_t)ctx->r5;  // a1: dst X
    uint16_t dst_y = (uint16_t)ctx->r6;  // a2: dst Y

    RECT16* src_rect = (RECT16*)GET_PTR(rect_addr);

    if (!src_rect) {
        ctx->r2 = -1;
        return;
    }

    if (src_rect->w == 0 || src_rect->h == 0) {
        ctx->r2 = -1;
        return;
    }

    printf("[HLE GPU] MoveImage: src(%d,%d,%d,%d) -> dst(%d,%d)\n",
        src_rect->x, src_rect->y, src_rect->w, src_rect->h,
        dst_x, dst_y);

    // Вызываем Psy-X напрямую, минуя DMA
    MoveImage(src_rect, dst_x, dst_y);

    ctx->r2 = 0;

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x20
//    ctx->r29 = ADD32(ctx->r29, -0X20);
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // addu        $s0, $a0, $zero
//    ctx->r16 = ADD32(ctx->r4, 0);
//    // sw          $s2, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r18;
//    // addu        $s2, $a1, $zero
//    ctx->r18 = ADD32(ctx->r5, 0);
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // addu        $s1, $a2, $zero
//    ctx->r17 = ADD32(ctx->r6, 0);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x3788
//    ctx->r4 = ADD32(ctx->r4, 0X3788);
//    // sw          $ra, 0x1C($sp)
//    MEM_W(0X1C, ctx->r29) = ctx->r31;
//    // jal         0x8006313C
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    JustReturn2(rdram, ctx);
//    goto after_0;
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    after_0:
//    // lh          $v0, 0x4($s0)
//    ctx->r2 = MEM_H(0X4, ctx->r16);
//    // nop
//
//    // beq         $v0, $zero, L_80063468
//    if (ctx->r2 == 0) {
//        // addiu       $v0, $zero, -0x1
//        ctx->r2 = ADD32(0, -0X1);
//        goto L_80063468;
//    }
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // lh          $v0, 0x6($s0)
//    ctx->r2 = MEM_H(0X6, ctx->r16);
//    // nop
//
//    // bne         $v0, $zero, L_80063418
//    if (ctx->r2 != 0) {
//        // sll         $v0, $s1, 16
//        ctx->r2 = S32(ctx->r17) << 16;
//        goto L_80063418;
//    }
//    // sll         $v0, $s1, 16
//    ctx->r2 = S32(ctx->r17) << 16;
//    // j           L_80063468
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    goto L_80063468;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//L_80063418:
//    // andi        $v1, $s2, 0xFFFF
//    ctx->r3 = ctx->r18 & 0XFFFF;
//    // or          $v0, $v0, $v1
//    ctx->r2 = ctx->r2 | ctx->r3;
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // addiu       $a1, $a1, 0x6250
//    ctx->r5 = ADD32(ctx->r5, 0X6250);
//    // lw          $a0, 0x0($s0)
//    ctx->r4 = MEM_W(0X0, ctx->r16);
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, 0x6198($v1)
//    ctx->r3 = MEM_W(0X6198, ctx->r3);
//    // ori         $a2, $zero, 0x14
//    ctx->r6 = 0 | 0X14;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, 0x6254($at)
//    MEM_W(0X6254, ctx->r1) = ctx->r2;
//    // sw          $a0, 0x0($a1)
//    MEM_W(0X0, ctx->r5) = ctx->r4;
//    // lw          $v0, 0x4($s0)
//    ctx->r2 = MEM_W(0X4, ctx->r16);
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, 0x6258($at)
//    MEM_W(0X6258, ctx->r1) = ctx->r2;
//    // lw          $a0, 0x18($v1)
//    ctx->r4 = MEM_W(0X18, ctx->r3);
//    // lw          $v0, 0x8($v1)
//    ctx->r2 = MEM_W(0X8, ctx->r3);
//    // nop
//
//    // jalr        $v0
//    // addiu       $a1, $a1, -0x8
//    ctx->r5 = ADD32(ctx->r5, -0X8);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_1;
//    // addiu       $a1, $a1, -0x8
//    ctx->r5 = ADD32(ctx->r5, -0X8);
//    after_1:
//L_80063468:
//    // lw          $ra, 0x1C($sp)
//    ctx->r31 = MEM_W(0X1C, ctx->r29);
//    // lw          $s2, 0x18($sp)
//    ctx->r18 = MEM_W(0X18, ctx->r29);
//    // lw          $s1, 0x14($sp)
//    ctx->r17 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x20
//    ctx->r29 = ADD32(ctx->r29, 0X20);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
