#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"

void KF_ApplyMatrixLV(uint8_t* rdram, recomp_context* ctx) {
    MATRIX* m = (MATRIX*)GET_PTR(ctx->r4);  // a0
    VECTOR* v0 = (VECTOR*)GET_PTR(ctx->r5); // a1
    VECTOR* v1 = (VECTOR*)GET_PTR(ctx->r6); // a2
	
	ctx_to_gte(ctx);
    ApplyMatrixLV(m, v0, v1);
	gte_to_ctx(ctx);
    ctx->r2 = ctx->r6;
}

//void KF_ApplyMatrixLV(uint8_t* rdram, recomp_context* ctx) {
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lw          $t0, 0x0($a0)
//    ctx->r8 = MEM_W(0X0, ctx->r4);
//    // lw          $t1, 0x4($a0)
//    ctx->r9 = MEM_W(0X4, ctx->r4);
//    // lw          $t2, 0x8($a0)
//    ctx->r10 = MEM_W(0X8, ctx->r4);
//    // lw          $t3, 0xC($a0)
//    ctx->r11 = MEM_W(0XC, ctx->r4);
//    // lw          $t4, 0x10($a0)
//    ctx->r12 = MEM_W(0X10, ctx->r4);
//    // ctc2        $t0, $0
//    gte_ctc2(ctx, 8, 0);
//    // ctc2        $t1, $1
//    gte_ctc2(ctx, 9, 1);
//    // ctc2        $t2, $2
//    gte_ctc2(ctx, 10, 2);
//    // ctc2        $t3, $3
//    gte_ctc2(ctx, 11, 3);
//    // ctc2        $t4, $4
//    gte_ctc2(ctx, 12, 4);
//    // lw          $t0, 0x0($a1)
//    ctx->r8 = MEM_W(0X0, ctx->r5);
//    // lw          $t1, 0x4($a1)
//    ctx->r9 = MEM_W(0X4, ctx->r5);
//    // lw          $t2, 0x8($a1)
//    ctx->r10 = MEM_W(0X8, ctx->r5);
//    // bgez        $t0, L_8006160C
//    if (SIGNED(ctx->r8) >= 0) {
//        // sra         $t3, $t0, 15
//        ctx->r11 = S32(ctx->r8) >> 15;
//        goto L_8006160C;
//    }
//    // sra         $t3, $t0, 15
//    ctx->r11 = S32(ctx->r8) >> 15;
//    // negu        $t0, $t0
//    ctx->r8 = SUB32(0, ctx->r8);
//    // sra         $t3, $t0, 15
//    ctx->r11 = S32(ctx->r8) >> 15;
//    // andi        $t0, $t0, 0x7FFF
//    ctx->r8 = ctx->r8 & 0X7FFF;
//    // negu        $t3, $t3
//    ctx->r11 = SUB32(0, ctx->r11);
//    // b           L_80061610
//    // negu        $t0, $t0
//    ctx->r8 = SUB32(0, ctx->r8);
//    goto L_80061610;
//    // negu        $t0, $t0
//    ctx->r8 = SUB32(0, ctx->r8);
//    // sra         $t3, $t0, 15
//    ctx->r11 = S32(ctx->r8) >> 15;
//L_8006160C:
//    // andi        $t0, $t0, 0x7FFF
//    ctx->r8 = ctx->r8 & 0X7FFF;
//L_80061610:
//    // bgez        $t1, L_80061634
//    if (SIGNED(ctx->r9) >= 0) {
//        // sra         $t4, $t1, 15
//        ctx->r12 = S32(ctx->r9) >> 15;
//        goto L_80061634;
//    }
//    // sra         $t4, $t1, 15
//    ctx->r12 = S32(ctx->r9) >> 15;
//    // negu        $t1, $t1
//    ctx->r9 = SUB32(0, ctx->r9);
//    // sra         $t4, $t1, 15
//    ctx->r12 = S32(ctx->r9) >> 15;
//    // andi        $t1, $t1, 0x7FFF
//    ctx->r9 = ctx->r9 & 0X7FFF;
//    // negu        $t4, $t4
//    ctx->r12 = SUB32(0, ctx->r12);
//    // b           L_80061638
//    // negu        $t1, $t1
//    ctx->r9 = SUB32(0, ctx->r9);
//    goto L_80061638;
//    // negu        $t1, $t1
//    ctx->r9 = SUB32(0, ctx->r9);
//    // sra         $t4, $t1, 15
//    ctx->r12 = S32(ctx->r9) >> 15;
//L_80061634:
//    // andi        $t1, $t1, 0x7FFF
//    ctx->r9 = ctx->r9 & 0X7FFF;
//L_80061638:
//    // bgez        $t2, L_8006165C
//    if (SIGNED(ctx->r10) >= 0) {
//        // sra         $t5, $t2, 15
//        ctx->r13 = S32(ctx->r10) >> 15;
//        goto L_8006165C;
//    }
//    // sra         $t5, $t2, 15
//    ctx->r13 = S32(ctx->r10) >> 15;
//    // negu        $t2, $t2
//    ctx->r10 = SUB32(0, ctx->r10);
//    // sra         $t5, $t2, 15
//    ctx->r13 = S32(ctx->r10) >> 15;
//    // andi        $t2, $t2, 0x7FFF
//    ctx->r10 = ctx->r10 & 0X7FFF;
//    // negu        $t5, $t5
//    ctx->r13 = SUB32(0, ctx->r13);
//    // b           L_80061660
//    // negu        $t2, $t2
//    ctx->r10 = SUB32(0, ctx->r10);
//    goto L_80061660;
//    // negu        $t2, $t2
//    ctx->r10 = SUB32(0, ctx->r10);
//    // sra         $t5, $t2, 15
//    ctx->r13 = S32(ctx->r10) >> 15;
//L_8006165C:
//    // andi        $t2, $t2, 0x7FFF
//    ctx->r10 = ctx->r10 & 0X7FFF;
//L_80061660:
//    // mtc2        $t3, $9
//    gte_mtc2(ctx, 11, 9);
//    // mtc2        $t4, $10
//    gte_mtc2(ctx, 12, 10);
//    // mtc2        $t5, $11
//    gte_mtc2(ctx, 13, 11);
//    // nop
//
//    // .word       0x4A41E012                   # INVALID     $s2, $at, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
//    gte_command(ctx, 0x4A41E012);
//    // mfc2        $t3, $25
//    ctx->r11 = gte_mfc2(ctx, 25);
//    // mfc2        $t4, $26
//    ctx->r12 = gte_mfc2(ctx, 26);
//    // mfc2        $t5, $27
//    ctx->r13 = gte_mfc2(ctx, 27);
//    // mtc2        $t0, $9
//    gte_mtc2(ctx, 8, 9);
//    // mtc2        $t1, $10
//    gte_mtc2(ctx, 9, 10);
//    // mtc2        $t2, $11
//    gte_mtc2(ctx, 10, 11);
//    // nop
//
//    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
//    gte_command(ctx, 0x4A49E012);
//    // bgez        $t3, L_800616AC
//    if (SIGNED(ctx->r11) >= 0) {
//        // nop
//    
//        goto L_800616AC;
//    }
//    // nop
//
//    // negu        $t3, $t3
//    ctx->r11 = SUB32(0, ctx->r11);
//    // sll         $t3, $t3, 3
//    ctx->r11 = S32(ctx->r11) << 3;
//    // b           L_800616B0
//    // negu        $t3, $t3
//    ctx->r11 = SUB32(0, ctx->r11);
//    goto L_800616B0;
//    // negu        $t3, $t3
//    ctx->r11 = SUB32(0, ctx->r11);
//L_800616AC:
//    // sll         $t3, $t3, 3
//    ctx->r11 = S32(ctx->r11) << 3;
//L_800616B0:
//    // bgez        $t4, L_800616C8
//    if (SIGNED(ctx->r12) >= 0) {
//        // nop
//    
//        goto L_800616C8;
//    }
//    // nop
//
//    // negu        $t4, $t4
//    ctx->r12 = SUB32(0, ctx->r12);
//    // sll         $t4, $t4, 3
//    ctx->r12 = S32(ctx->r12) << 3;
//    // b           L_800616CC
//    // negu        $t4, $t4
//    ctx->r12 = SUB32(0, ctx->r12);
//    goto L_800616CC;
//    // negu        $t4, $t4
//    ctx->r12 = SUB32(0, ctx->r12);
//L_800616C8:
//    // sll         $t4, $t4, 3
//    ctx->r12 = S32(ctx->r12) << 3;
//L_800616CC:
//    // bgez        $t5, L_800616E4
//    if (SIGNED(ctx->r13) >= 0) {
//        // nop
//    
//        goto L_800616E4;
//    }
//    // nop
//
//    // negu        $t5, $t5
//    ctx->r13 = SUB32(0, ctx->r13);
//    // sll         $t5, $t5, 3
//    ctx->r13 = S32(ctx->r13) << 3;
//    // b           L_800616E8
//    // negu        $t5, $t5
//    ctx->r13 = SUB32(0, ctx->r13);
//    goto L_800616E8;
//    // negu        $t5, $t5
//    ctx->r13 = SUB32(0, ctx->r13);
//L_800616E4:
//    // sll         $t5, $t5, 3
//    ctx->r13 = S32(ctx->r13) << 3;
//L_800616E8:
//    // mfc2        $t0, $25
//    ctx->r8 = gte_mfc2(ctx, 25);
//    // mfc2        $t1, $26
//    ctx->r9 = gte_mfc2(ctx, 26);
//    // mfc2        $t2, $27
//    ctx->r10 = gte_mfc2(ctx, 27);
//    // addu        $t0, $t0, $t3
//    ctx->r8 = ADD32(ctx->r8, ctx->r11);
//    // addu        $t1, $t1, $t4
//    ctx->r9 = ADD32(ctx->r9, ctx->r12);
//    // addu        $t2, $t2, $t5
//    ctx->r10 = ADD32(ctx->r10, ctx->r13);
//    // sw          $t0, 0x0($a2)
//    MEM_W(0X0, ctx->r6) = ctx->r8;
//    // sw          $t1, 0x4($a2)
//    MEM_W(0X4, ctx->r6) = ctx->r9;
//    // sw          $t2, 0x8($a2)
//    MEM_W(0X8, ctx->r6) = ctx->r10;
//    // jr          $ra
//    // addu        $v0, $a2, $zero
//    ctx->r2 = ADD32(ctx->r6, 0);
//    return;
//    // addu        $v0, $a2, $zero
//    ctx->r2 = ADD32(ctx->r6, 0);
//;}
