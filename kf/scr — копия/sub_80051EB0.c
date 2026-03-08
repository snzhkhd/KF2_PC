#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libspu.h"

void sub_80051EB0(uint8_t* rdram, recomp_context* ctx)
{
    printf("sub_80051EB0  SpuSetTransferMode\n");
    uint32_t ram_addr = ctx->r4;  // Откуда копировать (RAM)
    uint32_t size = ctx->r5;  // Размер данных
    uint32_t a3 = ctx->r6;  // Аргумент для возврата

    uint8_t* real_ram = &rdram[ram_addr & 0x1FFFFF];

    // TODO: Нужно будет выяснить, в какой адрес SPU RAM игра хочет положить эти данные.
    // В оригинале это вычисляется в sub_80052050.
    uint32_t spu_dest_addr = 0x1000; // Условный адрес для примера

    // Отправляем данные в SPU через высокоуровневый API Psy-X
    SpuSetTransferMode(SpuTransByDMA);
    SpuSetTransferStartAddr(spu_dest_addr);
    SpuWrite(real_ram, size); // Psy-X сам перекинет данные в OpenAL

    ctx->r2 = a3; // Возвращаем успех
}
//void sub_80051EB0(uint8_t* rdram, recomp_context* ctx) {
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x28
//    ctx->r29 = ADD32(ctx->r29, -0X28);
//    // sw          $ra, 0x24($sp)
//    MEM_W(0X24, ctx->r29) = ctx->r31;
//    // sw          $s4, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r20;
//    // sw          $s3, 0x1C($sp)
//    MEM_W(0X1C, ctx->r29) = ctx->r19;
//    // sw          $s2, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r18;
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // addu        $s4, $a0, $zero
//    ctx->r20 = ADD32(ctx->r4, 0);
//    // addu        $a0, $a2, $zero
//    ctx->r4 = ADD32(ctx->r6, 0);
//    // andi        $v0, $a0, 0xFFFF
//    ctx->r2 = ctx->r4 & 0XFFFF;
//    // sltiu       $v0, $v0, 0x11
//    ctx->r2 = ctx->r2 < 0X11 ? 1 : 0;
//    // beq         $v0, $zero, L_80051F70
//    if (ctx->r2 == 0) {
//        // addu        $s3, $a1, $zero
//        ctx->r19 = ADD32(ctx->r5, 0);
//        goto L_80051F70;
//    }
//    // addu        $s3, $a1, $zero
//    ctx->r19 = ADD32(ctx->r5, 0);
//    // sll         $v0, $a2, 16
//    ctx->r2 = S32(ctx->r6) << 16;
//    // sra         $s1, $v0, 16
//    ctx->r17 = S32(ctx->r2) >> 16;
//    // lui         $at, 0x801A
//    ctx->r1 = S32(0X801A << 16);
//    // addiu       $at, $at, -0x1910
//    ctx->r1 = ADD32(ctx->r1, -0X1910);
//    // addu        $at, $at, $s1
//    ctx->r1 = ADD32(ctx->r1, ctx->r17);
//    // lbu         $v1, 0x0($at)
//    ctx->r3 = MEM_BU(0X0, ctx->r1);
//    // ori         $v0, $zero, 0x2
//    ctx->r2 = 0 | 0X2;
//    // bne         $v1, $v0, L_80051F70
//    if (ctx->r3 != ctx->r2) {
//        // nop
//    
//        goto L_80051F70;
//    }
//    // nop
//
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x18($v0)
//    ctx->r2 = MEM_W(-0X18, ctx->r2);
//    // nop
//
//    // bne         $v0, $zero, L_80051F5C
//    if (ctx->r2 != 0) {
//        // sll         $s0, $s1, 2
//        ctx->r16 = S32(ctx->r17) << 2;
//        goto L_80051F5C;
//    }
//    // sll         $s0, $s1, 2
//    ctx->r16 = S32(ctx->r17) << 2;
//    // lui         $at, 0x801E
//    ctx->r1 = S32(0X801E << 16);
//    // addiu       $at, $at, -0x10A4
//    ctx->r1 = ADD32(ctx->r1, -0X10A4);
//    // addu        $at, $at, $s0
//    ctx->r1 = ADD32(ctx->r1, ctx->r16);
//    // lw          $v0, 0x0($at)
//    ctx->r2 = MEM_W(0X0, ctx->r1);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sh          $a0, -0x14($at)
//    MEM_H(-0X14, ctx->r1) = ctx->r4;
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, -0x18($at)
//    MEM_W(-0X18, ctx->r1) = ctx->r2;
//    // jal         0x8005201C
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    sub_8005201C(rdram, ctx);
//    goto after_0;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_0:
//    // lui         $at, 0x801E
//    ctx->r1 = S32(0X801E << 16);
//    // addiu       $at, $at, -0x105C
//    ctx->r1 = ADD32(ctx->r1, -0X105C);
//    // addu        $at, $at, $s0
//    ctx->r1 = ADD32(ctx->r1, ctx->r16);
//    // lw          $a0, 0x0($at)
//    ctx->r4 = MEM_W(0X0, ctx->r1);
//    // jal         0x80052050
//    // nop
//
//    sub_80052050(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//L_80051F5C:
//    // lui         $s2, 0x8007
//    ctx->r18 = S32(0X8007 << 16);
//    // lh          $s2, -0x14($s2)
//    ctx->r18 = MEM_H(-0X14, ctx->r18);
//    // nop
//
//    // beq         $s2, $s1, L_80051F80
//    if (ctx->r18 == ctx->r17) {
//        // addu        $s0, $s3, $zero
//        ctx->r16 = ADD32(ctx->r19, 0);
//        goto L_80051F80;
//    }
//    // addu        $s0, $s3, $zero
//    ctx->r16 = ADD32(ctx->r19, 0);
//L_80051F70:
//    // jal         0x8005208C
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    sub_8005208C(rdram, ctx);
//    goto after_2;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_2:
//    // j           L_80051FFC
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    goto L_80051FFC;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//L_80051F80:
//    // lui         $v1, 0x8007
//    ctx->r3 = S32(0X8007 << 16);
//    // lw          $v1, -0x18($v1)
//    ctx->r3 = MEM_W(-0X18, ctx->r3);
//    // nop
//
//    // sltu        $v0, $v1, $s0
//    ctx->r2 = ctx->r3 < ctx->r16 ? 1 : 0;
//    // beq         $v0, $zero, L_80051F9C
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80051F9C;
//    }
//    // nop
//
//    // addu        $s0, $v1, $zero
//    ctx->r16 = ADD32(ctx->r3, 0);
//L_80051F9C:
//    // jal         0x8005208C
//    // ori         $a0, $zero, 0x1
//    ctx->r4 = 0 | 0X1;
//    sub_8005208C(rdram, ctx);
//    goto after_3;
//    // ori         $a0, $zero, 0x1
//    ctx->r4 = 0 | 0X1;
//    after_3:
//    // addu        $a0, $s4, $zero
//    ctx->r4 = ADD32(ctx->r20, 0);
//    // jal         0x800520C8
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    sub_800520C8(rdram, ctx);
//    goto after_4;
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    after_4:
//    // lui         $v0, 0x8007
//    ctx->r2 = S32(0X8007 << 16);
//    // lw          $v0, -0x18($v0)
//    ctx->r2 = MEM_W(-0X18, ctx->r2);
//    // nop
//
//    // subu        $v0, $v0, $s0
//    ctx->r2 = SUB32(ctx->r2, ctx->r16);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $v0, -0x18($at)
//    MEM_W(-0X18, ctx->r1) = ctx->r2;
//    // bne         $v0, $zero, L_80051FFC
//    if (ctx->r2 != 0) {
//        // addiu       $v0, $zero, -0x2
//        ctx->r2 = ADD32(0, -0X2);
//        goto L_80051FFC;
//    }
//    // addiu       $v0, $zero, -0x2
//    ctx->r2 = ADD32(0, -0X2);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sw          $zero, -0x18($at)
//    MEM_W(-0X18, ctx->r1) = 0;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // lui         $at, 0x8007
//    ctx->r1 = S32(0X8007 << 16);
//    // sh          $v0, -0x14($at)
//    MEM_H(-0X14, ctx->r1) = ctx->r2;
//    // ori         $v0, $zero, 0x1
//    ctx->r2 = 0 | 0X1;
//    // lui         $at, 0x801A
//    ctx->r1 = S32(0X801A << 16);
//    // addiu       $at, $at, -0x1910
//    ctx->r1 = ADD32(ctx->r1, -0X1910);
//    // addu        $at, $at, $s2
//    ctx->r1 = ADD32(ctx->r1, ctx->r18);
//    // sb          $v0, 0x0($at)
//    MEM_B(0X0, ctx->r1) = ctx->r2;
//    // addu        $v0, $s2, $zero
//    ctx->r2 = ADD32(ctx->r18, 0);
//L_80051FFC:
//    // lw          $ra, 0x24($sp)
//    ctx->r31 = MEM_W(0X24, ctx->r29);
//    // lw          $s4, 0x20($sp)
//    ctx->r20 = MEM_W(0X20, ctx->r29);
//    // lw          $s3, 0x1C($sp)
//    ctx->r19 = MEM_W(0X1C, ctx->r29);
//    // lw          $s2, 0x18($sp)
//    ctx->r18 = MEM_W(0X18, ctx->r29);
//    // lw          $s1, 0x14($sp)
//    ctx->r17 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // jr          $ra
//    // addiu       $sp, $sp, 0x28
//    ctx->r29 = ADD32(ctx->r29, 0X28);
//    return;
//    // addiu       $sp, $sp, 0x28
//    ctx->r29 = ADD32(ctx->r29, 0X28);
//;}
