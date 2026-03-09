#include "recomp.h"
#include "disable_warnings.h"

void sub_80054A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // lw          $v0, -0x2550($v0)
    ctx->r2 = MEM_W(-0X2550, ctx->r2);
    // nop

    // lbu         $v1, 0x18($v0)
    ctx->r3 = MEM_BU(0X18, ctx->r2);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lbu         $a0, -0x192C($a0)
    ctx->r4 = MEM_BU(-0X192C, ctx->r4);
    // sll         $v0, $v1, 14
    ctx->r2 = S32(ctx->r3) << 14;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3F01
    ctx->r3 = 0 | 0X3F01;
    // div         $zero, $v0, $v1
	if (ctx->r3 != 0)
	{
		lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); 
		hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
	}
	else
	{
		lo = 0;
		hi = 0;
	}
    
    // bne         $v1, $zero, L_80054A50
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054A50;
    }
    // nop

    // break       7
    do_break(2147830348);
L_80054A50:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80054A68
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80054A68;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80054A68
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80054A68;
    }
    // nop

    // break       6
    do_break(2147830372);
L_80054A68:
    // mflo        $a3
    ctx->r7 = lo;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x1926($v0)
    ctx->r2 = MEM_BU(-0X1926, ctx->r2);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x1923($v0)
    ctx->r2 = MEM_BU(-0X1923, ctx->r2);
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // nop

    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80054AB0
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054AB0;
    }
    // nop

    // break       7
    do_break(2147830444);
L_80054AB0:
    // mflo        $a2
    ctx->r6 = lo;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lhu         $a0, -0x191A($a0)
    ctx->r4 = MEM_HU(-0X191A, ctx->r4);
    // addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4) << 16;
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, -0x1916($v0)
    ctx->r2 = MEM_HS(-0X1916, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // srl         $v1, $a1, 24
    ctx->r3 = S32(U32(ctx->r5) >> 24);
    // sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2) << 3;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addiu       $at, $at, -0x2248
    ctx->r1 = ADD32(ctx->r1, -0X2248);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lw          $v1, 0x0($at)
    ctx->r3 = MEM_W(0X0, ctx->r1);
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // ori         $v0, $zero, 0x21
    ctx->r2 = 0 | 0X21;
    // beq         $a1, $v0, L_80054B78
    if (ctx->r5 == ctx->r2) {
        // addu        $a3, $a2, $zero
        ctx->r7 = ADD32(ctx->r6, 0);
        goto L_80054B78;
    }
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // lhu         $v0, 0x74($a0)
    ctx->r2 = MEM_HU(0X74, ctx->r4);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x7F
    ctx->r3 = 0 | 0X7F;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80054B48
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054B48;
    }
    // nop

    // break       7
    do_break(2147830596);
L_80054B48:
    // mflo        $a3
    ctx->r7 = lo;
    // lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(0X76, ctx->r4);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80054B74
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054B74;
    }
    // nop

    // break       7
    do_break(2147830640);
L_80054B74:
    // mflo        $a2
    ctx->r6 = lo;
L_80054B78:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1922($v1)
    ctx->r3 = MEM_BU(-0X1922, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80054BB8
    if (ctx->r2 == 0) {
        // mult        $a2, $v1
        result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80054BB8;
    }
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3F
    ctx->r3 = 0 | 0X3F;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80054BAC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054BAC;
    }
    // nop

    // break       7
    do_break(2147830696);
L_80054BAC:
    // mflo        $a2
    ctx->r6 = lo;
    // j           L_80054BE4
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    goto L_80054BE4;
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
L_80054BB8:
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // ori         $v0, $zero, 0x3F
    ctx->r2 = 0 | 0X3F;
    // divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // bne         $v0, $zero, L_80054BE0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80054BE0;
    }
    // nop

    // break       7
    do_break(2147830748);
L_80054BE0:
    // mflo        $a1
    ctx->r5 = lo;
L_80054BE4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x1925($v1)
    ctx->r3 = MEM_BU(-0X1925, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80054C24
    if (ctx->r2 == 0) {
        // mult        $a2, $v1
        result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80054C24;
    }
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3F
    ctx->r3 = 0 | 0X3F;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80054C18
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054C18;
    }
    // nop

    // break       7
    do_break(2147830804);
L_80054C18:
    // mflo        $a2
    ctx->r6 = lo;
    // j           L_80054C50
    // nop

    goto L_80054C50;
    // nop

L_80054C24:
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // ori         $v0, $zero, 0x3F
    ctx->r2 = 0 | 0X3F;
    // divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // bne         $v0, $zero, L_80054C4C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80054C4C;
    }
    // nop

    // break       7
    do_break(2147830856);
L_80054C4C:
    // mflo        $a1
    ctx->r5 = lo;
L_80054C50:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v1, -0x192B($v1)
    ctx->r3 = MEM_BU(-0X192B, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80054C90
    if (ctx->r2 == 0) {
        // mult        $a2, $v1
        result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80054C90;
    }
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3F
    ctx->r3 = 0 | 0X3F;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80054C84
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054C84;
    }
    // nop

    // break       7
    do_break(2147830912);
L_80054C84:
    // mflo        $a2
    ctx->r6 = lo;
    // j           L_80054CBC
    // nop

    goto L_80054CBC;
    // nop

L_80054C90:
    // ori         $v0, $zero, 0x7F
    ctx->r2 = 0 | 0X7F;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // ori         $v0, $zero, 0x3F
    ctx->r2 = 0 | 0X3F;
    // divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // bne         $v0, $zero, L_80054CB8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80054CB8;
    }
    // nop

    // break       7
    do_break(2147830964);
L_80054CB8:
    // mflo        $a1
    ctx->r5 = lo;
L_80054CBC:
    // lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // lh          $v1, 0xA88($v1)
    ctx->r3 = MEM_HS(0XA88, ctx->r3);
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // bne         $v1, $v0, L_80054CEC
    if (ctx->r3 != ctx->r2) {
        // mult        $a1, $a1
        result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80054CEC;
    }
    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sltu        $v0, $a1, $a2
    ctx->r2 = ctx->r5 < ctx->r6 ? 1 : 0;
    // beq         $v0, $zero, L_80054CE4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80054CE4;
    }
    // nop

    // j           L_80054CE8
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    goto L_80054CE8;
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_80054CE4:
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_80054CE8:
    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80054CEC:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // ori         $v1, $zero, 0x3FFF
    ctx->r3 = 0 | 0X3FFF;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80054D08
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054D08;
    }
    // nop

    // break       7
    do_break(2147831044);
L_80054D08:
    // mflo        $a1
    ctx->r5 = lo;
    // mult        $a2, $a2
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80054D2C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80054D2C;
    }
    // nop

    // break       7
    do_break(2147831080);
L_80054D2C:
    // mflo        $a2
    ctx->r6 = lo;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, -0x7744
    ctx->r4 = ADD32(ctx->r4, -0X7744);
    // andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7744
    ctx->r1 = ADD32(ctx->r1, -0X7744);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $t0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r8;
    // addiu       $v0, $a0, -0x4
    ctx->r2 = ADD32(ctx->r4, -0X4);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x1916
    ctx->r4 = ADD32(ctx->r4, -0X1916);
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // lh          $v1, 0x0($a0)
    ctx->r3 = MEM_HS(0X0, ctx->r4);
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lbu         $v0, 0x0($at)
    ctx->r2 = MEM_BU(0X0, ctx->r1);
    // nop

    // ori         $v0, $v0, 0x7
    ctx->r2 = ctx->r2 | 0X7;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75C8
    ctx->r1 = ADD32(ctx->r1, -0X75C8);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $v0, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r2;
    // lh          $v1, 0x0($a0)
    ctx->r3 = MEM_HS(0X0, ctx->r4);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x75AC
    ctx->r1 = ADD32(ctx->r1, -0X75AC);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $t0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r8;
    // lh          $v1, 0x0($a0)
    ctx->r3 = MEM_HS(0X0, ctx->r4);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // ori         $v1, $zero, 0x1
    ctx->r3 = 0 | 0X1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addiu       $at, $at, -0x7595
    ctx->r1 = ADD32(ctx->r1, -0X7595);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, 0x0($at)
    MEM_B(0X0, ctx->r1) = ctx->r3;
    // lh          $v1, 0x0($a0)
    ctx->r3 = MEM_HS(0X0, ctx->r4);
    // nop

    // slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80054E1C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x1
        ctx->r2 = 0 | 0X1;
        goto L_80054E1C;
    }
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sllv        $a3, $v0, $v1
    ctx->r7 = S32(ctx->r2) << (ctx->r3 & 31);
    // j           L_80054E28
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_80054E28;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80054E1C:
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // sllv        $a2, $v0, $v1
    ctx->r6 = S32(ctx->r2) << (ctx->r3 & 31);
L_80054E28:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, -0x191C($v0)
    ctx->r2 = MEM_BU(-0X191C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_80054E70
    if (ctx->r2 == 0) {
        // nor         $v1, $zero, $a3
        ctx->r3 = ~(0 | ctx->r7);
        goto L_80054E70;
    }
    // nor         $v1, $zero, $a3
    ctx->r3 = ~(0 | ctx->r7);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lhu         $v0, -0x6E90($v0)
    ctx->r2 = MEM_HU(-0X6E90, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, -0x6E88($v1)
    ctx->r3 = MEM_HU(-0X6E88, ctx->r3);
    // or          $v0, $a3, $v0
    ctx->r2 = ctx->r7 | ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, -0x6E90($at)
    MEM_H(-0X6E90, ctx->r1) = ctx->r2;
    // or          $v1, $a2, $v1
    ctx->r3 = ctx->r6 | ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v1, -0x6E88($at)
    MEM_H(-0X6E88, ctx->r1) = ctx->r3;
    // j           L_80054E9C
    // nop

    goto L_80054E9C;
    // nop

L_80054E70:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lhu         $v0, -0x6E90($v0)
    ctx->r2 = MEM_HU(-0X6E90, ctx->r2);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lhu         $a0, -0x6E88($a0)
    ctx->r4 = MEM_HU(-0X6E88, ctx->r4);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, -0x6E90($at)
    MEM_H(-0X6E90, ctx->r1) = ctx->r2;
    // nor         $v0, $zero, $a2
    ctx->r2 = ~(0 | ctx->r6);
    // and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $a0, -0x6E88($at)
    MEM_H(-0X6E88, ctx->r1) = ctx->r4;
L_80054E9C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, -0x6EA0($v1)
    ctx->r3 = MEM_HU(-0X6EA0, ctx->r3);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lhu         $a1, -0x6E98($a1)
    ctx->r5 = MEM_HU(-0X6E98, ctx->r5);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, -0xFD8($v0)
    ctx->r2 = MEM_HU(-0XFD8, ctx->r2);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lhu         $a0, -0xFD0($a0)
    ctx->r4 = MEM_HU(-0XFD0, ctx->r4);
    // or          $v1, $a3, $v1
    ctx->r3 = ctx->r7 | ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v1, -0x6EA0($at)
    MEM_H(-0X6EA0, ctx->r1) = ctx->r3;
    // or          $a1, $a2, $a1
    ctx->r5 = ctx->r6 | ctx->r5;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $a1, -0x6E98($at)
    MEM_H(-0X6E98, ctx->r1) = ctx->r5;
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $v0, -0xFD8($at)
    MEM_H(-0XFD8, ctx->r1) = ctx->r2;
    // nor         $a1, $zero, $a1
    ctx->r5 = ~(0 | ctx->r5);
    // and         $a0, $a0, $a1
    ctx->r4 = ctx->r4 & ctx->r5;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sh          $a0, -0xFD0($at)
    MEM_H(-0XFD0, ctx->r1) = ctx->r4;
    // jr          $ra
    // addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
