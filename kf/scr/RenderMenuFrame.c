#include "recomp.h"
#include "disable_warnings.h"

void RenderMenuFrame(uint8_t* rdram, recomp_context* ctx) 
{
   
    // До
    //uint32_t ctx240 = MEM_W(0xF0, MEM_W(0, 0x80076198));
    //printf("[RenderMenuFrame] before ctx+240=0x%08X\n", ctx240);

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x4A66($v0)
    ctx->r2 = MEM_H(-0X4A66, ctx->r2);
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7B98
    ctx->r4 = ADD32(ctx->r4, 0X7B98);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_H(0X0, ctx->r18);
    // nop

    // beq         $v0, $zero, L_80022820
    if (ctx->r2 == 0) {
        // addiu       $s1, $s2, 0x1C
        ctx->r17 = ADD32(ctx->r18, 0X1C);
        goto L_80022820;
    }
    // addiu       $s1, $s2, 0x1C
    ctx->r17 = ADD32(ctx->r18, 0X1C);
    // lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // addiu       $s0, $s0, 0x7AE4
    ctx->r16 = ADD32(ctx->r16, 0X7AE4);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80023944
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    ui_DrawFrame(rdram, ctx);
    goto after_0;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // addiu       $a0, $s0, -0x30
    ctx->r4 = ADD32(ctx->r16, -0X30);
    // jal         0x80023E20
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    ui_DrawText(rdram, ctx);
    goto after_1;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
L_80022820:
    // blez        $s4, L_8002288C
    if (SIGNED(ctx->r20) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8002288C;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
L_8002282C:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AE4
    ctx->r4 = ADD32(ctx->r4, 0X7AE4);
    // bne         $s0, $s3, L_8002284C
    if (ctx->r16 != ctx->r19) {
        // nop
    
        goto L_8002284C;
    }
    // nop

    // bne         $s5, $s2, L_8002284C
    if (ctx->r21 != ctx->r18) {
        // nop
    
        goto L_8002284C;
    }
    // nop

    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AF0
    ctx->r4 = ADD32(ctx->r4, 0X7AF0);
L_8002284C:
    // jal         0x80023944
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    ui_DrawFrame(rdram, ctx);
    goto after_2;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // bne         $s0, $s3, L_8002286C
    if (ctx->r16 != ctx->r19) {
        // nop
    
        goto L_8002286C;
    }
    // nop

    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AC0
    ctx->r4 = ADD32(ctx->r4, 0X7AC0);
    // jal         0x80023AE8
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    UI_DrawCursor(rdram, ctx);
    goto after_3;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
L_8002286C:
    // lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // addiu       $a0, $a0, 0x7AB4
    ctx->r4 = ADD32(ctx->r4, 0X7AB4);
    // jal         0x80023E20
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    ui_DrawText(rdram, ctx);
    goto after_4;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $s4
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // bne         $v0, $zero, L_8002282C
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
        goto L_8002282C;
    }
    // addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_8002288C:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    // После  
    //uint32_t ot_base = MEM_W(0, 0x8019015C); // g_GpuCommandBuffer
    //uint32_t* ot20 = (uint32_t*)GET_PTR(ot_base + 80);  // index 20
    //uint32_t* ot0 = (uint32_t*)GET_PTR(ot_base);        // index 0 (терминатор)

    //printf("[OTag check] base=0x%08X ot[0]=0x%08X ot[20]=0x%08X\n",
    //    ot_base, *ot0, *ot20);

    //// Если ot[20] != 0 — примитив там, проверяем его данные
    //uint32_t prim_addr = *ot20 & 0x00FFFFFF;
    //if (prim_addr > 0x10000) {
    //    uint32_t* prim = (uint32_t*)GET_PTR(prim_addr | 0x80000000);
    //    printf("[Prim at ot[20]] ");
    //    for (int i = 0; i < 8; i++) printf("%08X ", prim[i]);
    //    printf("\n");
    //}

    return;
    // nop

;}
