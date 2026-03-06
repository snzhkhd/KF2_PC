#include "recomp.h"
#include "disable_warnings.h"

void sub_8004EFD4(uint8_t* rdram, recomp_context* ctx) 
{
    // На PC SPU DMA не нужен — данные уже в rdram
   // PsyX сам обработает через свой SPU
    ctx->r2 = 0;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x8C4($v0)
//    ctx->r2 = MEM_W(-0X8C4, ctx->r2);
//    // lui         $a2, 0x2
//    ctx->r6 = S32(0X2 << 16);
//    // sb          $zero, 0x0($v0)
//    MEM_B(0X0, ctx->r2) = 0;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x8B8($v1)
//    ctx->r3 = MEM_W(-0X8B8, ctx->r3);
//    // ori         $v0, $zero, 0x80
//    ctx->r2 = 0 | 0X80;
//    // sb          $v0, 0x0($v1)
//    MEM_B(0X0, ctx->r3) = ctx->r2;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x860($v0)
//    ctx->r2 = MEM_W(-0X860, ctx->r2);
//    // ori         $a2, $a2, 0x943
//    ctx->r6 = ctx->r6 | 0X943;
//    // sw          $a2, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r6;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x8B4($v1)
//    ctx->r3 = MEM_W(-0X8B4, ctx->r3);
//    // ori         $v0, $zero, 0x1323
//    ctx->r2 = 0 | 0X1323;
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x85C($v1)
//    ctx->r3 = MEM_W(-0X85C, ctx->r3);
//    // nop
//
//    // lw          $v0, 0x0($v1)
//    ctx->r2 = MEM_W(0X0, ctx->r3);
//    // nop
//
//    // ori         $v0, $v0, 0x8000
//    ctx->r2 = ctx->r2 | 0X8000;
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x858($v0)
//    ctx->r2 = MEM_W(-0X858, ctx->r2);
//    // nop
//
//    // sw          $a0, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r4;
//    // lui         $v0, 0x1
//    ctx->r2 = S32(0X1 << 16);
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x854($v1)
//    ctx->r3 = MEM_W(-0X854, ctx->r3);
//    // or          $a1, $a1, $v0
//    ctx->r5 = ctx->r5 | ctx->r2;
//    // sw          $a1, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r5;
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x850($v1)
//    ctx->r3 = MEM_W(-0X850, ctx->r3);
//    // lui         $v0, 0x1100
//    ctx->r2 = S32(0X1100 << 16);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $a0, 0x8007
//    ctx->r4 = S32(0X8007 << 16);
//    // lw          $a0, -0x850($a0)
//    ctx->r4 = MEM_W(-0X850, ctx->r4);
//    // nop
//
//    // lw          $v0, 0x0($a0)
//    ctx->r2 = MEM_W(0X0, ctx->r4);
//    // lui         $v1, 0x100
//    ctx->r3 = S32(0X100 << 16);
//    // and         $v0, $v0, $v1
//    ctx->r2 = ctx->r2 & ctx->r3;
//    // beq         $v0, $zero, L_8004F09C
//    if (ctx->r2 == 0) {
//        // addu        $v1, $a0, $zero
//        ctx->r3 = ADD32(ctx->r4, 0);
//        goto L_8004F09C;
//    }
//    // addu        $v1, $a0, $zero
//    ctx->r3 = ADD32(ctx->r4, 0);
//    // lui         $a0, 0x100
//    ctx->r4 = S32(0X100 << 16);
//L_8004F088:
//    // lw          $v0, 0x0($v1)
//    ctx->r2 = MEM_W(0X0, ctx->r3);
//    // nop
//
//    // and         $v0, $v0, $a0
//    ctx->r2 = ctx->r2 & ctx->r4;
//    // bne         $v0, $zero, L_8004F088
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8004F088;
//    }
//    // nop
//
//L_8004F09C:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x8B4($v1)
//    ctx->r3 = MEM_W(-0X8B4, ctx->r3);
//    // ori         $v0, $zero, 0x1325
//    ctx->r2 = 0 | 0X1325;
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // jr          $ra
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    return;
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
;}
