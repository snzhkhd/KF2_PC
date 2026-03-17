#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"

#include "SDL2/SDL_video.h"
extern SDL_Window* g_window;

void BeginDraw2D(uint8_t* rdram, recomp_context* ctx) 
{

    PsyX_BeginScene();

    // Переключаем на 4:3 для 2D
    if (g_widescreenEnabled)
    {
        int windowW, windowH;
        SDL_GetWindowSize(g_window, &windowW, &windowH);
        float targetAspect = 4.0f / 3.0f;
        int vpH = windowH;
        int vpW = (int)(windowH * targetAspect);
        int vpX = (windowW - vpW) / 2;
        GR_SetViewPort(vpX, 0, vpW, vpH);
    }


 //   printf("BeginDraw2D\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // addiu       $s0, $s0, 0x138
    ctx->r16 = ADD32(ctx->r16, 0X138);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v1, $s0, 0x8
    ctx->r3 = ADD32(ctx->r16, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a0, $a0, 15
    ctx->r4 = S32(ctx->r4) << 15;
    // lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // sw          $v0, 0x158($at)
    MEM_W(0X158, ctx->r1) = ctx->r2;
    // addiu       $v0, $s0, 0x24
    ctx->r2 = ADD32(ctx->r16, 0X24);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $a0, 0x15C($at)
    MEM_W(0X15C, ctx->r1) = ctx->r4;
    // jal         0x8006353C
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    KF_ClearOTagR(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0x2000
    ctx->r5 = 0 | 0X2000;
    after_0:
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // lw          $v1, 0x158($v1)
    ctx->r3 = MEM_W(0X158, ctx->r3);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $v0, 0x158($v0)
    ctx->r2 = MEM_W(0X158, ctx->r2);
    // nop

    // lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(0X8, ctx->r2);
    // nop

    // sw          $v0, 0xF0($gp)
    MEM_W(0XF0, ctx->r28) = ctx->r2;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80024594
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xF0
        ctx->r2 = 0 | 0XF0;
        goto L_80024594;
    }
    // ori         $v0, $zero, 0xF0
    ctx->r2 = 0 | 0XF0;
    // sh          $zero, 0xFC($gp)
    MEM_H(0XFC, ctx->r28) = 0;
    // sh          $v0, 0xFE($gp)
    MEM_H(0XFE, ctx->r28) = ctx->r2;
    // j           L_8002459C
    // nop

    goto L_8002459C;
    // nop

L_80024594:
    // sh          $zero, 0xFC($gp)
    MEM_H(0XFC, ctx->r28) = 0;
    // sh          $zero, 0xFE($gp)
    MEM_H(0XFE, ctx->r28) = 0;
L_8002459C:
    // lw          $v1, 0x74($gp)
    ctx->r3 = MEM_W(0X74, ctx->r28);
    // nop

    // bne         $v1, $zero, L_800245B8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800245B8;
    }
    // nop

    // lw          $v0, 0x70($gp)
    ctx->r2 = MEM_W(0X70, ctx->r28);
    // j           L_800245D0
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    goto L_800245D0;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800245B8:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_800245D4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800245D4;
    }
    // nop

    // lw          $v0, 0x70($gp)
    ctx->r2 = MEM_W(0X70, ctx->r28);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800245D0:
    // sw          $v0, 0x70($gp)
    MEM_W(0X70, ctx->r28) = ctx->r2;
L_800245D4:
    // lw          $v0, 0x70($gp)
    ctx->r2 = MEM_W(0X70, ctx->r28);
    // nop

    // slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_800245F4
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0x7
        ctx->r2 = 0 | 0X7;
        goto L_800245F4;
    }
    // ori         $v0, $zero, 0x7
    ctx->r2 = 0 | 0X7;
    // sw          $v0, 0x70($gp)
    MEM_W(0X70, ctx->r28) = ctx->r2;
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sw          $v0, 0x74($gp)
    MEM_W(0X74, ctx->r28) = ctx->r2;
L_800245F4:
    // lw          $v0, 0x70($gp)
    ctx->r2 = MEM_W(0X70, ctx->r28);
    // nop

    // bgez        $v0, L_8002460C
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8002460C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $zero, 0x70($gp)
    MEM_W(0X70, ctx->r28) = 0;
    // sw          $v0, 0x74($gp)
    MEM_W(0X74, ctx->r28) = ctx->r2;
L_8002460C:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop


    uint32_t gp = 0x800762C0;
    uint32_t ptr_240 = MEM_W(0xF0, gp);  // $gp + 0xF0
    uint32_t ptr_248 = MEM_W(0xF8, gp);  // $gp + 0xF8
    uint32_t ptr_252 = MEM_W(0xFC, gp);  // $gp + 0xFC


    uint32_t cmd_buf = MEM_W(0, 0x8019015C);    //8019015C g_GpuCommandBuffer
    uint32_t cmd_mirror = MEM_W(0, 0x80180158); // 80180158 g_GpuCmdBufferMirror

     
   /* printf("[BeginDraw2D] gp+0xF0=0x%08X gp+0xF8=0x%08X\n", ptr_240, ptr_248);
    printf("[BeginDraw2D] g_GpuCommandBuffer=0x%08X mirror=0x%08X\n", cmd_buf, cmd_mirror);*/
    return;
    // nop

;}
