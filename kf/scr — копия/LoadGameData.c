#include "recomp.h"
#include "disable_warnings.h"

void LoadGameData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // addiu       $s0, $s0, -0x1EE4
    ctx->r16 = ADD32(ctx->r16, -0X1EE4);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // addiu       $v1, $v1, 0x79D9
    ctx->r3 = ADD32(ctx->r3, 0X79D9);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DB($at)
    MEM_B(0X79DB, ctx->r1) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $v0, 0x79DA($at)
    MEM_B(0X79DA, ctx->r1) = ctx->r2;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $zero, 0x79D4($at)
    MEM_H(0X79D4, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sh          $zero, 0x79D6($at)
    MEM_H(0X79D6, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79D8($at)
    MEM_B(0X79D8, ctx->r1) = 0;
    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79DA($at)
    MEM_B(0X79DA, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79DB($at)
    MEM_B(0X79DB, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79DC($at)
    MEM_B(0X79DC, ctx->r1) = 0;
    // lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // sb          $zero, 0x79DD($at)
    MEM_B(0X79DD, ctx->r1) = 0;
    // jal         0x80018AD8
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    LoadFileByIndex(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_0:
    // ori         $a0, $zero, 0x3
    ctx->r4 = 0 | 0X3;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x100C
    ctx->r5 = ADD32(ctx->r5, 0X100C);
    // jal         0x80018AD8
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    LoadFileByIndex(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_1:
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x1018
    ctx->r5 = ADD32(ctx->r5, 0X1018);
    // jal         0x80018AD8
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    LoadFileByIndex(rdram, ctx);
    goto after_2;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_2:
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x1024
    ctx->r5 = ADD32(ctx->r5, 0X1024);
    // jal         0x80018AD8
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    LoadFileByIndex(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_3:
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x1030
    ctx->r5 = ADD32(ctx->r5, 0X1030);
    // jal         0x80018AD8
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    LoadFileByIndex(rdram, ctx);
    goto after_4;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_4:
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x103C
    ctx->r5 = ADD32(ctx->r5, 0X103C);
    // jal         0x80018AD8
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    LoadFileByIndex(rdram, ctx);
    goto after_5;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_5:
    // ori         $a0, $zero, 0x6
    ctx->r4 = 0 | 0X6;
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x1048
    ctx->r5 = ADD32(ctx->r5, 0X1048);
    // jal         0x80018AD8
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    LoadFileByIndex(rdram, ctx);
    goto after_6;
    // ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    after_6:
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    // ori         $a1, $zero, 0x30
    ctx->r5 = 0 | 0X30;
    // jal         0x800188CC
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LoadTFile(rdram, ctx);
    goto after_7;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_7:
    // ori         $a0, $zero, 0x5
    ctx->r4 = 0 | 0X5;
    // jal         0x8001737C
    // ori         $a1, $zero, 0x2F
    ctx->r5 = 0 | 0X2F;
    QueueCDReadTask(rdram, ctx);
    goto after_8;
    // ori         $a1, $zero, 0x2F
    ctx->r5 = 0 | 0X2F;
    after_8:
    // ori         $a0, $zero, 0x4
    ctx->r4 = 0 | 0X4;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014BB0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    StartAudioStream(rdram, ctx);
    goto after_9;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_9:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    MemcpyDword(rdram, ctx);
    goto after_10;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_10:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x4754
    ctx->r4 = ADD32(ctx->r4, -0X4754);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    MemcpyDword(rdram, ctx);
    goto after_11;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_11:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, -0x2A48
    ctx->r4 = ADD32(ctx->r4, -0X2A48);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    MemcpyDword(rdram, ctx);
    goto after_12;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_12:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, -0x6E6C
    ctx->r4 = ADD32(ctx->r4, -0X6E6C);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    MemcpyDword(rdram, ctx);
    goto after_13;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_13:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x1900
    ctx->r4 = ADD32(ctx->r4, -0X1900);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    MemcpyDword(rdram, ctx);
    goto after_14;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_14:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x1B1C
    ctx->r4 = ADD32(ctx->r4, -0X1B1C);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    MemcpyDword(rdram, ctx);
    goto after_15;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_15:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x5574
    ctx->r4 = ADD32(ctx->r4, -0X5574);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    MemcpyDword(rdram, ctx);
    goto after_16;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_16:
    // lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // addiu       $s1, $s1, -0x2EE4
    ctx->r17 = ADD32(ctx->r17, -0X2EE4);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    MemcpyDword(rdram, ctx);
    goto after_17;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_17:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // jal         0x80036490
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    KF_MOPackPrepareTMD(rdram, ctx);
    goto after_18;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    after_18:
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // addiu       $s1, $s1, -0x71BC
    ctx->r17 = ADD32(ctx->r17, -0X71BC);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80017684
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    MemcpyDword(rdram, ctx);
    goto after_19;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_19:
    // ori         $a0, $zero, 0x28
    ctx->r4 = 0 | 0X28;
    // jal         0x80036490
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    KF_MOPackPrepareTMD(rdram, ctx);
    goto after_20;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_20:
    // jal         0x80027BCC
    // nop

    PlayerSetDefault(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
