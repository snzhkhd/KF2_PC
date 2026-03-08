#include "recomp.h"
#include "disable_warnings.h"

void SectorToMSF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x1B4E
    ctx->r3 = S32(0X1B4E << 16);
    // ori         $v1, $v1, 0x81B5
    ctx->r3 = ctx->r3 | 0X81B5;
    // addiu       $a0, $a0, 0x96
    ctx->r4 = ADD32(ctx->r4, 0X96);
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // lui         $a3, 0x6666
    ctx->r7 = S32(0X6666 << 16);
    // ori         $a3, $a3, 0x6667
    ctx->r7 = ctx->r7 | 0X6667;
    // sra         $v1, $a0, 31
    ctx->r3 = S32(ctx->r4) >> 31;
    // mfhi        $a2
    ctx->r6 = hi;
    // sra         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6) >> 3;
    // subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // sll         $a1, $a2, 2
    ctx->r5 = S32(ctx->r6) << 2;
    // addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5) << 4;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t0
    ctx->r8 = hi;
    // lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $a2, 31
    ctx->r3 = S32(ctx->r6) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // sra         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9) >> 5;
    // subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // sll         $v1, $t1, 4
    ctx->r3 = S32(ctx->r9) << 4;
    // subu        $v1, $v1, $t1
    ctx->r3 = SUB32(ctx->r3, ctx->r9);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // mult        $a2, $a3
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8) >> 2;
    // sra         $v1, $a0, 31
    ctx->r3 = S32(ctx->r4) >> 31;
    // subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8) << 2;
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // mfhi        $a1
    ctx->r5 = hi;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sra         $v1, $a2, 31
    ctx->r3 = S32(ctx->r6) >> 31;
    // mult        $t1, $a3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a3, $t0, 4
    ctx->r7 = S32(ctx->r8) << 4;
    // addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // sra         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) >> 2;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5) << 4;
    // sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5) << 2;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // sra         $a0, $t1, 31
    ctx->r4 = S32(ctx->r9) >> 31;
    // sb          $a3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r7;
    // mfhi        $v1
    ctx->r3 = hi;
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $a1, $v1, 4
    ctx->r5 = S32(ctx->r3) << 4;
    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // jr          $ra
    // sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    return;
    // sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
;}
