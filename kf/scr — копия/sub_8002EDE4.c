#include "recomp.h"
#include "disable_warnings.h"

void sub_8002EDE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x753C($v0)
    ctx->r2 = MEM_W(-0X753C, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8002EF70
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002EF70;
    }
    // nop

    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x7538($v0)
    ctx->r2 = MEM_W(-0X7538, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8002EF70
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002EF70;
    }
    // nop

    // lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // lw          $a1, -0x7534($a1)
    ctx->r5 = MEM_W(-0X7534, ctx->r5);
    // nop

    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // beq         $v0, $zero, L_8002EF70
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002EF70;
    }
    // nop

    // lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // lw          $a3, -0x7544($a3)
    ctx->r7 = MEM_W(-0X7544, ctx->r7);
    // nop

    // sltiu       $v0, $a3, 0x50
    ctx->r2 = ctx->r7 < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_8002EF60
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002EF60;
    }
    // nop

    // lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // lw          $a2, -0x7540($a2)
    ctx->r6 = MEM_W(-0X7540, ctx->r6);
    // nop

    // sltiu       $v0, $a2, 0x50
    ctx->r2 = ctx->r6 < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_8002EF60
    if (ctx->r2 == 0) {
        // addu        $a1, $a1, $a0
        ctx->r5 = ADD32(ctx->r5, ctx->r4);
        goto L_8002EF60;
    }
    // addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x428C
    ctx->r4 = ADD32(ctx->r4, -0X428C);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // lbu         $a1, 0x0($a1)
    ctx->r5 = MEM_BU(0X0, ctx->r5);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lw          $v1, -0x7550($v1)
    ctx->r3 = MEM_W(-0X7550, ctx->r3);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lbu         $v0, -0x7548($v0)
    ctx->r2 = MEM_BU(-0X7548, ctx->r2);
    // nop

    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // bne         $v0, $zero, L_8002EED8
    if (ctx->r2 != 0) {
        // addu        $a0, $a2, $v1
        ctx->r4 = ADD32(ctx->r6, ctx->r3);
        goto L_8002EED8;
    }
    // addu        $a0, $a2, $v1
    ctx->r4 = ADD32(ctx->r6, ctx->r3);
L_8002EEB4:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x7534($v0)
    ctx->r2 = MEM_W(-0X7534, ctx->r2);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lbu         $v1, -0x7548($v1)
    ctx->r3 = MEM_BU(-0X7548, ctx->r3);
    // lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(0X0, ctx->r2);
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // and         $a0, $a0, $v1
    ctx->r4 = ctx->r4 & ctx->r3;
    // j           L_8002EF20
    // sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    goto L_8002EF20;
    // sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_8002EED8:
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8002EEB4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8002EEB4;
    }
    // nop

    // lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(0X4, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8002EF20
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002EF20;
    }
    // nop

L_8002EEFC:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x7534($v0)
    ctx->r2 = MEM_W(-0X7534, ctx->r2);
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lbu         $a0, -0x7547($a0)
    ctx->r4 = MEM_BU(-0X7547, ctx->r4);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // j           L_8002EF70
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    goto L_8002EF70;
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8002EF20:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x754C($v0)
    ctx->r2 = MEM_W(-0X754C, ctx->r2);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // ori         $v0, $zero, 0xFF
    ctx->r2 = 0 | 0XFF;
    // beq         $v1, $v0, L_8002EF70
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8002EF70;
    }
    // nop

    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lbu         $v0, -0x7547($v0)
    ctx->r2 = MEM_BU(-0X7547, ctx->r2);
    // nop

    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8002EF70
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002EF70;
    }
    // nop

    // j           L_8002EEFC
    // nop

    goto L_8002EEFC;
    // nop

L_8002EF60:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x7534($v0)
    ctx->r2 = MEM_W(-0X7534, ctx->r2);
    // nop

    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8002EF70:
    // jr          $ra
    // nop

    return;
    // nop

;}
