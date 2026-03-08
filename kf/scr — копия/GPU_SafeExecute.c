#include "recomp.h"
#include "disable_warnings.h"

#define ADDR_KF_LOADIMAGE (0x80010000 + 0x000546f8/*offset KF_LoadImage из IDA*/)

void GPU_SafeExecute(uint8_t* rdram, recomp_context* ctx)
{
    uint32_t gpuFuncAddr = ctx->r4;
    uint32_t arg1 = ctx->r5;
    uint32_t arg3 = ctx->r6;
    uint32_t callbackArg = ctx->r7;

    // ќпредел€ем Ч это LoadImage или что-то другое
    bool is_load_image = (gpuFuncAddr == ADDR_KF_LOADIMAGE);

    recomp_func_t func = lookup_recomp_func(gpuFuncAddr);
    if (func) {
        uint32_t saved_ra = ctx->r31;
        ctx->r4 = arg1;
        ctx->r5 = callbackArg;
        func(rdram, ctx);
        ctx->r31 = saved_ra;
    }

    WRITE_W(0x1F801814, 0x1C000000);

    // Callback вызываем “ќЋ№ ќ после LoadImage
    if (is_load_image) {
        uint32_t* p_stream = (uint32_t*)GET_PTR(ADDR_G_ACTIVECDSTREAM);
        if (p_stream && *p_stream) {
            uint32_t stream = *p_stream;
            uint32_t callback_addr = MEM_W(20, stream); // CDStream+20
            if (callback_addr) {
                recomp_func_t cb = lookup_recomp_func(callback_addr);
                printf("[GPU_SafeExecute] CDStream callback_addr  0x%08X\n", callback_addr);
                if (cb) {
                    printf("[GPU_SafeExecute] LoadImage done, calling OnCDReadComplete\n");
                    ctx->r4 = stream;
                    cb(rdram, ctx);
                }
            }
        }
    }

    ctx->r2 = 0;
    /*
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0;
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // jal         0x800655A8
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    SyncVSyncStatus(rdram, ctx);
    goto after_0;
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    after_0:
    // j           L_80064D68
    // nop

    goto L_80064D68;
    // nop

L_80064D50:
    // jal         0x800655DC
    // nop

    sub_800655DC(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // bne         $v0, $zero, L_80064FF0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80064FF0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // jal         0x80065010
    // nop

    sub_80065010(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_80064D68:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A4($v0)
    ctx->r2 = MEM_W(0X62A4, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A8($v1)
    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // beq         $v0, $v1, L_80064D50
    if (ctx->r2 == ctx->r3) {
        // nop

        goto L_80064D50;
    }
    // nop

    // jal         0x80061CD0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SetIntrMask(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // addiu       $v1, $v1, 0x61A8
    ctx->r3 = ADD32(ctx->r3, 0X61A8);
    // ori         $a0, $zero, 0x1
    ctx->r4 = 0 | 0X1;
    // sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lbu         $v1, 0x61A1($v1)
    ctx->r3 = MEM_BU(0X61A1, ctx->r3);
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x62AC($at)
    MEM_W(0X62AC, ctx->r1) = ctx->r2;
    // beq         $v1, $zero, L_80064E08
    if (ctx->r3 == 0) {
        // lui         $a0, 0x400
        ctx->r4 = S32(0X400 << 16);
        goto L_80064E08;
    }
    // lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A8($v0)
    ctx->r2 = MEM_W(0X62A8, ctx->r2);
    // nop

    // bne         $v1, $v0, L_80064E68
    if (ctx->r3 != ctx->r2) {
        // nop

        goto L_80064E68;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x6280($v0)
    ctx->r2 = MEM_W(0X6280, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80064E68
    if (ctx->r2 != 0) {
        // nop

        goto L_80064E68;
    }
    // nop

    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x61AC($v0)
    ctx->r2 = MEM_W(0X61AC, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80064E68
    if (ctx->r2 != 0) {
        // nop

        goto L_80064E68;
    }
    // nop

L_80064E08:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x6274($v1)
    ctx->r3 = MEM_W(0X6274, ctx->r3);
L_80064E10:
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // beq         $v0, $zero, L_80064E10
    if (ctx->r2 == 0) {
        // nop

        goto L_80064E10;
    }
    // nop

    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jalr        $s3
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
    goto after_4;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x62AC($a0)
    ctx->r4 = MEM_W(0X62AC, ctx->r4);
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x6294
    ctx->r2 = ADD32(ctx->r2, 0X6294);
    // sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s0, 0x6298($at)
    MEM_W(0X6298, ctx->r1) = ctx->r16;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $s2, 0x629C($at)
    MEM_W(0X629C, ctx->r1) = ctx->r18;
    // jal         0x80061CD0
    // nop

    SetIntrMask(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_80064FF0
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80064FF0;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80064E68:
    // lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // addiu       $a1, $a1, 0x5010
    ctx->r5 = ADD32(ctx->r5, 0X5010);
    // jal         0x80061BB4
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    DMACallback(rdram, ctx);
    goto after_6;
    // ori         $a0, $zero, 0x2
    ctx->r4 = 0 | 0X2;
    after_6:
    // beq         $s1, $zero, L_80064F2C
    if (ctx->r17 == 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_80064F2C;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // addiu       $t0, $t0, -0x7524
    ctx->r8 = ADD32(ctx->r8, -0X7524);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80064E90:
    // bgez        $v0, L_80064E9C
    if (SIGNED(ctx->r2) >= 0) {
        // nop

        goto L_80064E9C;
    }
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_80064E9C:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80064EE0
    if (ctx->r2 == 0) {
        // sll         $a0, $a2, 2
        ctx->r4 = S32(ctx->r6) << 2;
        goto L_80064EE0;
    }
    // sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6) << 2;
    // lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(0X0, ctx->r7);
    // addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // j           L_80064E90
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    goto L_80064E90;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80064EE0:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A4($v0)
    ctx->r2 = MEM_W(0X62A4, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) << 5;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x7524
    ctx->r3 = ADD32(ctx->r3, -0X7524);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x752C
    ctx->r1 = ADD32(ctx->r1, -0X752C);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // sw          $v0, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r2;
    // j           L_80064F54
    // nop

    goto L_80064F54;
    // nop

L_80064F2C:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x752C
    ctx->r1 = ADD32(ctx->r1, -0X752C);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $s0, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r16;
L_80064F54:
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x7528
    ctx->r1 = ADD32(ctx->r1, -0X7528);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $s2, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r18;
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A4($v1)
    ctx->r3 = MEM_W(0X62A4, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // addiu       $at, $at, -0x7530
    ctx->r1 = ADD32(ctx->r1, -0X7530);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $s3, 0x0($at)
    MEM_W(0X0, ctx->r1) = ctx->r19;
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A4($v0)
    ctx->r2 = MEM_W(0X62A4, ctx->r2);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // lw          $a0, 0x62AC($a0)
    ctx->r4 = MEM_W(0X62AC, ctx->r4);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // sw          $v0, 0x62A4($at)
    MEM_W(0X62A4, ctx->r1) = ctx->r2;
    // jal         0x80061CD0
    // nop

    SetIntrMask(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // jal         0x80065010
    // nop

    sub_80065010(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // lw          $v0, 0x62A4($v0)
    ctx->r2 = MEM_W(0X62A4, ctx->r2);
    // lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // lw          $v1, 0x62A8($v1)
    ctx->r3 = MEM_W(0X62A8, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
L_80064FF0:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop
   */
    ;
}
