#include "..//kf_cd.h"
#include "recomp.h"
#include "disable_warnings.h"

void CD_readm(uint8_t* rdram, recomp_context* ctx)
{
    // printf("[CD_readm] sector=%d count=%d dst=%08X\n",
        // g_cdCurrentSector, ctx->r5, ctx->r4);
		
    uint32_t dest_addr = ctx->r4;
    uint32_t count = ctx->r5;
    if (count == 0) count = 1;


    uint8_t* dest_ptr = (uint8_t*)GET_PTR(dest_addr);
    if (g_cdImage && dest_ptr) {
    //    printf("[HLE CD] CD_readm: Reading %d sectors from LBA %d to 0x%08X\n",
    //        count, g_cdCurrentSector, dest_addr);
        for (uint32_t i = 0; i < count; i++) {
            uint32_t fileOffset = (g_cdCurrentSector + i) * 2352 + 24;
            fseek(g_cdImage, fileOffset, SEEK_SET);
            fread(dest_ptr + (i * 2048), 1, 2048, g_cdImage);
        }
        g_cdCurrentSector += count;

        // ХАК: выставляем флаг "данные готовы" вручную
        // g_ActiveCdStream — адрес из IDA
        uint32_t stream_addr = /* адрес g_ActiveCdStream из IDA */ADDR_G_ACTIVECDSTREAM;
        uint32_t* stream_ptr_addr = (uint32_t*)GET_PTR(stream_addr);
        if (stream_ptr_addr) {
            uint32_t stream = *stream_ptr_addr;
            if (stream) {
                uint8_t* stream_bytes = (uint8_t*)GET_PTR(stream);
                if (stream_bytes ) // && stream_bytes[0] == 0x40) 
                {
                    stream_bytes[36] = 1;  // data_ready = 1
                //    stream_bytes[1] = 1;   // говорим что данные готовы
                //    printf("[HLE CD] CDStream data_ready flag set!\n");
                }
            }
        }
    }
    //printf("CD_readm\n");
    ctx->r2 = 0;

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0;
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // addiu       $v0, $v0, -0x898
//    ctx->r2 = ADD32(ctx->r2, -0X898);
//    // sw          $ra, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r31;
//    // sw          $a2, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r6;
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // nop
//
//    // andi        $v1, $v0, 0x30
//    ctx->r3 = ctx->r2 & 0X30;
//    // beq         $v1, $zero, L_8004EAF0
//    if (ctx->r3 == 0) {
//        // ori         $v0, $zero, 0x20
//        ctx->r2 = 0 | 0X20;
//        goto L_8004EAF0;
//    }
//    // ori         $v0, $zero, 0x20
//    ctx->r2 = 0 | 0X20;
//    // beq         $v1, $v0, L_8004EB04
//    if (ctx->r3 == ctx->r2) {
//        // ori         $v0, $zero, 0x249
//        ctx->r2 = 0 | 0X249;
//        goto L_8004EB04;
//    }
//    // ori         $v0, $zero, 0x249
//    ctx->r2 = 0 | 0X249;
//    // j           L_8004EB14
//    // ori         $v0, $zero, 0x246
//    ctx->r2 = 0 | 0X246;
//    goto L_8004EB14;
//    // ori         $v0, $zero, 0x246
//    ctx->r2 = 0 | 0X246;
//L_8004EAF0:
//    // ori         $v0, $zero, 0x200
//    ctx->r2 = 0 | 0X200;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, -0x894($at)
//    MEM_W(-0X894, ctx->r1) = ctx->r2;
//    // j           L_8004EB20
//    // nop
//
//    goto L_8004EB20;
//    // nop
//
//L_8004EB04:
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, -0x894($at)
//    MEM_W(-0X894, ctx->r1) = ctx->r2;
//    // j           L_8004EB20
//    // nop
//
//    goto L_8004EB20;
//    // nop
//
//L_8004EB14:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // addiu       $v1, $v1, -0x894
//    ctx->r3 = ADD32(ctx->r3, -0X894);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//L_8004EB20:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // addiu       $v0, $v0, -0x8A0
//    ctx->r2 = ADD32(ctx->r2, -0X8A0);
//    // sw          $a0, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r4;
//    // lui         $a0, 0x8007
//    ctx->r4 = S32(0X8007 << 16);
//    // lw          $a0, -0xB88($a0)
//    ctx->r4 = MEM_W(-0XB88, ctx->r4);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $a1, -0x8A4($at)
//    MEM_W(-0X8A4, ctx->r1) = ctx->r5;
//    // lui         $a1, 0x8007
//    ctx->r5 = S32(0X8007 << 16);
//    // lw          $a1, -0xB84($a1)
//    ctx->r5 = MEM_W(-0XB84, ctx->r5);
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0xB78($v1)
//    ctx->r3 = MEM_W(-0XB78, ctx->r3);
//    // ori         $v0, $zero, 0x8
//    ctx->r2 = 0 | 0X8;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, -0x8A8($at)
//    MEM_W(-0X8A8, ctx->r1) = ctx->r2;
//    // andi        $v1, $v1, 0xE0
//    ctx->r3 = ctx->r3 & 0XE0;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $a0, -0x888($at)
//    MEM_W(-0X888, ctx->r1) = ctx->r4;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $a1, -0x884($at)
//    MEM_W(-0X884, ctx->r1) = ctx->r5;
//    // beq         $v1, $zero, L_8004EB84
//    if (ctx->r3 == 0) {
//        // ori         $a0, $zero, 0x9
//        ctx->r4 = 0 | 0X9;
//        goto L_8004EB84;
//    }
//    // ori         $a0, $zero, 0x9
//    ctx->r4 = 0 | 0X9;
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    // addu        $a2, $zero, $zero
//    ctx->r6 = ADD32(0, 0);
//    // jal         0x8004DBE0
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    CD_cw_8004DBE0(rdram, ctx);
//    goto after_0;
//    // addu        $a3, $zero, $zero
//    ctx->r7 = ADD32(0, 0);
//    after_0:
//L_8004EB84:
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // jal         0x8004D68C
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    InitDmaChannel(rdram, ctx);
//    goto after_1;
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    after_1:
//    // jal         0x8004E73C
//    // nop
//
//    sub_8004E73C(rdram, ctx);
//    goto after_2;
//    // nop
//
//    after_2:
//    // slti        $v0, $v0, 0x1
//    ctx->r2 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
//    // negu        $v0, $v0
//    ctx->r2 = SUB32(0, ctx->r2);
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
//    ;
}
