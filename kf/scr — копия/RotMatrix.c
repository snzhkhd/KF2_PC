#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

// MATRIX* RotMatrix(SVECTOR* r, MATRIX* m);
void KF_RotMatrix(uint8_t* rdram, recomp_context* ctx) 
{
    //SVECTOR* r = (SVECTOR*)GET_PTR(ctx->r4); // a0 - входные углы
    //MATRIX* m = (MATRIX*)GET_PTR(ctx->r5);  // a1 - матрица (результат)

    //if (r && m) 
    //{
    //    ctx_to_gte(ctx);
    //    RotMatrix(r, m);
    //    gte_to_ctx(ctx);
    //}

    //// Возвращаем в v0 адрес результирующей матрицы (из r5)
    //ctx->r2 = ctx->r5;


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0;
    // lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(0X0, ctx->r4);
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // bgez        $t7, L_8005F6DC
    if (SIGNED(ctx->r15) >= 0) {
        // andi        $t9, $t7, 0xFFF
        ctx->r25 = ctx->r15 & 0XFFF;
        goto L_8005F6DC;
    }
    // andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // negu        $t7, $t7
    ctx->r15 = SUB32(0, ctx->r15);
    // bgez        $t7, L_8005F6B4
    if (SIGNED(ctx->r15) >= 0) {
        // andi        $t7, $t7, 0xFFF
        ctx->r15 = ctx->r15 & 0XFFF;
        goto L_8005F6B4;
    }
    // andi        $t7, $t7, 0xFFF
    ctx->r15 = ctx->r15 & 0XFFF;
L_8005F6B4:
    // sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15) << 2;
    // lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // lw          $t9, 0x38C($t9)
    ctx->r25 = MEM_W(0X38C, ctx->r25);
    // nop

    // sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25) << 16;
    // sra         $t8, $t8, 16
    ctx->r24 = S32(ctx->r24) >> 16;
    // negu        $t3, $t8
    ctx->r11 = SUB32(0, ctx->r24);
    // j           L_8005F6FC
    // sra         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25) >> 16;
    goto L_8005F6FC;
    // sra         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25) >> 16;
L_8005F6DC:
    // sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25) << 2;
    // lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // lw          $t9, 0x38C($t9)
    ctx->r25 = MEM_W(0X38C, ctx->r25);
    // nop

    // sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25) << 16;
    // sra         $t3, $t8, 16
    ctx->r11 = S32(ctx->r24) >> 16;
    // sra         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25) >> 16;
L_8005F6FC:
    // lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(0X2, ctx->r4);
    // nop

    // bgez        $t7, L_8005F740
    if (SIGNED(ctx->r15) >= 0) {
        // andi        $t9, $t7, 0xFFF
        ctx->r25 = ctx->r15 & 0XFFF;
        goto L_8005F740;
    }
    // andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // negu        $t7, $t7
    ctx->r15 = SUB32(0, ctx->r15);
    // bgez        $t7, L_8005F718
    if (SIGNED(ctx->r15) >= 0) {
        // andi        $t7, $t7, 0xFFF
        ctx->r15 = ctx->r15 & 0XFFF;
        goto L_8005F718;
    }
    // andi        $t7, $t7, 0xFFF
    ctx->r15 = ctx->r15 & 0XFFF;
L_8005F718:
    // sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15) << 2;
    // lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // lw          $t9, 0x38C($t9)
    ctx->r25 = MEM_W(0X38C, ctx->r25);
    // nop

    // sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25) << 16;
    // sra         $t4, $t4, 16
    ctx->r12 = S32(ctx->r12) >> 16;
    // negu        $t6, $t4
    ctx->r14 = SUB32(0, ctx->r12);
    // j           L_8005F764
    // sra         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25) >> 16;
    goto L_8005F764;
    // sra         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25) >> 16;
L_8005F740:
    // sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25) << 2;
    // lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // lw          $t9, 0x38C($t9)
    ctx->r25 = MEM_W(0X38C, ctx->r25);
    // nop

    // sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25) << 16;
    // sra         $t6, $t6, 16
    ctx->r14 = S32(ctx->r14) >> 16;
    // negu        $t4, $t6
    ctx->r12 = SUB32(0, ctx->r14);
    // sra         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25) >> 16;
L_8005F764:
    // multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(0X4, ctx->r4);
    // sh          $t6, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r14;
    // mflo        $t8
    ctx->r24 = lo;
    // negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // sra         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25) >> 12;
    // multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t6, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r14;
    // bgez        $t7, L_8005F7CC
    if (SIGNED(ctx->r15) >= 0) {
        // andi        $t9, $t7, 0xFFF
        ctx->r25 = ctx->r15 & 0XFFF;
        goto L_8005F7CC;
    }
    // andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // mflo        $t8
    ctx->r24 = lo;
    // sra         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24) >> 12;
    // sh          $t6, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r14;
    // negu        $t7, $t7
    ctx->r15 = SUB32(0, ctx->r15);
    // bgez        $t7, L_8005F7A4
    if (SIGNED(ctx->r15) >= 0) {
        // andi        $t7, $t7, 0xFFF
        ctx->r15 = ctx->r15 & 0XFFF;
        goto L_8005F7A4;
    }
    // andi        $t7, $t7, 0xFFF
    ctx->r15 = ctx->r15 & 0XFFF;
L_8005F7A4:
    // sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15) << 2;
    // lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // lw          $t9, 0x38C($t9)
    ctx->r25 = MEM_W(0X38C, ctx->r25);
    // nop

    // sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25) << 16;
    // sra         $t8, $t8, 16
    ctx->r24 = S32(ctx->r24) >> 16;
    // negu        $t5, $t8
    ctx->r13 = SUB32(0, ctx->r24);
    // j           L_8005F7F8
    // sra         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25) >> 16;
    goto L_8005F7F8;
    // sra         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25) >> 16;
L_8005F7CC:
    // mflo        $t7
    ctx->r15 = lo;
    // sra         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15) >> 12;
    // sh          $t6, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r14;
    // sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25) << 2;
    // lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // lw          $t9, 0x38C($t9)
    ctx->r25 = MEM_W(0X38C, ctx->r25);
    // nop

    // sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25) << 16;
    // sra         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24) >> 16;
    // sra         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25) >> 16;
L_8005F7F8:
    // multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t7
    ctx->r15 = lo;
    // sra         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15) >> 12;
    // sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t7
    ctx->r15 = lo;
    // negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // sra         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14) >> 12;
    // multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // nop

    // mflo        $t7
    ctx->r15 = lo;
    // sra         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15) >> 12;
    // nop

    // multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t7
    ctx->r15 = lo;
    // sra         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15) >> 12;
    // nop

    // multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t7
    ctx->r15 = lo;
    // sra         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15) >> 12;
    // subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t7, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r15;
    // nop

    // mflo        $t6
    ctx->r14 = lo;
    // sra         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14) >> 12;
    // nop

    // multu       $t5, $t3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t6
    ctx->r14 = lo;
    // sra         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14) >> 12;
    // addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // multu       $t5, $t4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t6, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r14;
    // nop

    // mflo        $t7
    ctx->r15 = lo;
    // sra         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15) >> 12;
    // nop

    // multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t7
    ctx->r15 = lo;
    // sra         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15) >> 12;
    // nop

    // multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t7
    ctx->r15 = lo;
    // sra         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15) >> 12;
    // addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t7, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r15;
    // nop

    // mflo        $t6
    ctx->r14 = lo;
    // sra         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14) >> 12;
    // nop

    // multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t6
    ctx->r14 = lo;
    // sra         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14) >> 12;
    // subu        $t6, $t9, $t7
    ctx->r14 = SUB32(ctx->r25, ctx->r15);
    // sh          $t6, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r14;
    // jr          $ra
    // nop

    return;
    // nop
}