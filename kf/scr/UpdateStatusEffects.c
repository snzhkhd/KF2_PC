#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libpad.h"
#include "..//UI.h"

#include <SDL2/SDL_scancode.h>


void KF_RenderMessageOrig(uint8_t* rdram, recomp_context* ctx);

void KF_RenderMessage(uint8_t* rdram, recomp_context* ctx)
{
    if (IsKeyPressed(SDL_SCANCODE_F1))
    {

        ShowCustomMessage(rdram, bMouseEnable ? "Mouse Captured" : "Mouse Released", 1.0f);
    }

    if (g_customMsg.active && g_customMsg.state > 0) 
    {
        // Сохраняем оригинальные ректы и colour
        uint8_t savedColour = MEM_BU(0, 0x80194DF8);
        uint8_t savedRects[7 * 0x12];
        memcpy(savedRects, GET_PTR(0x8006E238), sizeof(savedRects));

        // Ставим наши
        UpdateCustomMessageState();
        MEM_B(0, 0x80194DF8) = (uint8_t)g_customMsg.alpha;

        int charCount = 0;
        for (int i = 0; i < 24 && g_customMsg.chars[i] != 0xFF; i++)
            charCount++;

        // Рисуем порциями по 7 символов
        int drawn = 0;
        while (drawn < charCount) {
            int batch = charCount - drawn;
            if (batch > 7) batch = 7;

            for (int i = 0; i < batch; i++)
                FillRectWithChar(rdram, i, g_customMsg.chars[drawn + i],
                    g_customMsg.posX + (drawn + i) * 7, g_customMsg.posY);
            for (int i = batch; i < 7; i++)
                MEM_B(0x00, 0x8006E238 + i * 0x12) = 0;
            MEM_B(0x00, 0x8006E238 + 7 * 0x12) = 0xFF;

            KF_RenderMessageOrig(rdram, ctx);

            drawn += batch;
        }

        // Восстанавливаем
        memcpy(GET_PTR(0x8006E238), savedRects, sizeof(savedRects));
        MEM_B(0, 0x80194DF8) = savedColour;

        // И рисуем оригинал (если есть)
        KF_RenderMessageOrig(rdram, ctx);


    }
    else
        KF_RenderMessageOrig(rdram, ctx);


}


void KF_RenderMessageOrig(uint8_t* rdram, recomp_context* ctx) 
{
    
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lbu         $v0, 0x4DF8($v0)
    ctx->r2 = MEM_BU(0X4DF8, ctx->r2);
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // addiu       $s0, $s0, -0x1DC8
    ctx->r16 = ADD32(ctx->r16, -0X1DC8);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sb          $v0, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r2;
    // sb          $v0, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r2;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_80035CAC
    if (ctx->r3 == ctx->r2) {
        // ori         $s1, $zero, 0xFF
        ctx->r17 = 0 | 0XFF;
        goto L_80035CAC;
    }
    // ori         $s1, $zero, 0xFF
    ctx->r17 = 0 | 0XFF;
L_80035C6C:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80035C98
    if (ctx->r2 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80035C98;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x20
    ctx->r5 = 0 | 0X20;
    // jal         0x80035ADC
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    sub_80035ADC(rdram, ctx);
    goto after_0;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $zero, 0x40
    ctx->r5 = 0 | 0X40;
    // jal         0x80035ADC
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    sub_80035ADC(rdram, ctx);
    goto after_1;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_1:
L_80035C98:
    // addiu       $s0, $s0, 0x12
    ctx->r16 = ADD32(ctx->r16, 0X12);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v0, $s1, L_80035C6C
    if (ctx->r2 != ctx->r17) {
        // nop
    
        goto L_80035C6C;
    }
    // nop

L_80035CAC:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
