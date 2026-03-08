#include "recomp.h"
#include "disable_warnings.h"

void ___MainGameLoop(uint8_t* rdram, recomp_context* ctx) 
{
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, 0x79D4
    ctx->r4 = ADD32(ctx->r4, 0X79D4);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $a2, $zero, 0x7
    ctx->r6 = 0 | 0X7;
    // sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // jal         0x800176E4
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    memset_0(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    after_0:
    // lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // addiu       $a0, $a0, 0x138
    ctx->r4 = ADD32(ctx->r4, 0X138);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x5F3C
    ctx->r6 = 0 | 0X5F3C;
    memset_0(rdram, ctx);
    goto after_1;
    // ori         $a2, $zero, 0x5F3C
    ctx->r6 = 0 | 0X5F3C;
    after_1:
    // lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // addiu       $s3, $s3, -0x4B3C
    ctx->r19 = ADD32(ctx->r19, -0X4B3C);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x59
    ctx->r6 = 0 | 0X59;
    memset_0(rdram, ctx);
    goto after_2;
    // ori         $a2, $zero, 0x59
    ctx->r6 = 0 | 0X59;
    after_2:
    // lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // addiu       $a0, $a0, 0x5198
    ctx->r4 = ADD32(ctx->r4, 0X5198);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0xE46
    ctx->r6 = 0 | 0XE46;
    memset_0(rdram, ctx);
    goto after_3;
    // ori         $a2, $zero, 0xE46
    ctx->r6 = 0 | 0XE46;
    after_3:
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x428C
    ctx->r4 = ADD32(ctx->r4, -0X428C);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x4611
    ctx->r6 = 0 | 0X4611;
    memset_0(rdram, ctx);
    goto after_4;
    // ori         $a2, $zero, 0x4611
    ctx->r6 = 0 | 0X4611;
    after_4:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x21D1
    ctx->r6 = 0 | 0X21D1;
    memset_0(rdram, ctx);
    goto after_5;
    // ori         $a2, $zero, 0x21D1
    ctx->r6 = 0 | 0X21D1;
    after_5:
    // lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // addiu       $a0, $a0, -0x19F8
    ctx->r4 = ADD32(ctx->r4, -0X19F8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x24F3
    ctx->r6 = 0 | 0X24F3;
    memset_0(rdram, ctx);
    goto after_6;
    // ori         $a2, $zero, 0x24F3
    ctx->r6 = 0 | 0X24F3;
    after_6:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x1900
    ctx->r4 = ADD32(ctx->r4, -0X1900);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0xAA3
    ctx->r6 = 0 | 0XAA3;
    memset_0(rdram, ctx);
    goto after_7;
    // ori         $a2, $zero, 0xAA3
    ctx->r6 = 0 | 0XAA3;
    after_7:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x59D8
    ctx->r4 = ADD32(ctx->r4, -0X59D8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800176E4
    // ori         $a2, $zero, 0x3A7
    ctx->r6 = 0 | 0X3A7;
    memset_0(rdram, ctx);
    goto after_8;
    // ori         $a2, $zero, 0x3A7
    ctx->r6 = 0 | 0X3A7;
    after_8:
    // ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
    // sb          $v0, 0x180($gp)
    MEM_B(0X180, ctx->r28) = ctx->r2;
    // jal         0x80018FE8
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
    InitEventSystem(rdram, ctx);
    goto after_9;
    // ori         $s2, $zero, 0x1
    ctx->r18 = 0 | 0X1;
    after_9:
    // jal         0x8002FBF0
    // nop

    InitGraphicsSystem(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x80013EA0
    // nop

    InitSoundSystem(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // jal         0x80037FA8
    // nop

    InitProjectileSystem(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // jal         0x8003BB10
    // nop

    InitEntitySystem(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // jal         0x8004860C
    // nop

    InitParticleSystem(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // jal         0x800161C8
    // nop

    LoadGameData(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // jal         0x8004AC5C
    // nop

    InitPlayerInventory(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // jal         0x80024F00
    // nop

    InitBiosEvents(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // jal         0x8002E73C
    // nop

    PrepareRenderPrimitives(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // sw          $s2, 0x51A0($at)
    MEM_W(0X51A0, ctx->r1) = ctx->r18;
    // jal         0x8002E86C
    // nop

    PrecomputeCardinalOrientations(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // ori         $v0, $zero, 0x140
    ctx->r2 = 0 | 0X140;
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x1E0
    ctx->r2 = 0 | 0X1E0;
    // sb          $zero, 0x180($gp)
    MEM_B(0X180, ctx->r28) = 0;
    // sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // jal         0x80063264
    // sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    ClearImageWithCallback(rdram, ctx);
    goto after_20;
    // sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    after_20:
    // ori         $a0, $zero, 0x7F
    ctx->r4 = 0 | 0X7F;
    // jal         0x80054388
    // ori         $a1, $zero, 0x7F
    ctx->r5 = 0 | 0X7F;
    SetMasterVolume(rdram, ctx);
    goto after_21;
    // ori         $a1, $zero, 0x7F
    ctx->r5 = 0 | 0X7F;
    after_21:
    // jal         0x8001CD28
    // nop

    ShowLoadOrNewGameMenu(rdram, ctx);
    goto after_22;
    // nop

    after_22:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_80013C5C
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80013C5C;
    }
    // nop

    // jal         0x8002601C
    // nop

    LoadSave(rdram, ctx);
    goto after_23;
    // nop

    after_23:
L_80013C5C:
    // jal         0x80018BE0
    // nop

    LoadTalkFiles(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x4A66($v0)
    ctx->r2 = MEM_HU(-0X4A66, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80013C88
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80013C88;
    }
    // nop

    // jal         0x80018D74
    // nop

    _loadTIM(rdram, ctx);
    goto after_25;
    // nop

    after_25:
L_80013C88:
    // jal         0x8001646C
    // ori         $s1, $zero, 0x40
    ctx->r17 = 0 | 0X40;
    InitTileMap(rdram, ctx);
    goto after_26;
    // ori         $s1, $zero, 0x40
    ctx->r17 = 0 | 0X40;
    after_26:
    // jal         0x80027CA8
    // ori         $s0, $zero, 0x20
    ctx->r16 = 0 | 0X20;
    Player_Spawn(rdram, ctx);
    goto after_27;
    // ori         $s0, $zero, 0x20
    ctx->r16 = 0 | 0X20;
    after_27:
    // ori         $a0, $zero, 0x140
    ctx->r4 = 0 | 0X140;
    // ori         $a1, $zero, 0x100
    ctx->r5 = 0 | 0X100;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8002F984
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    VRAM_ReserveTextureSpace(rdram, ctx);
    goto after_28;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_28:
    // ori         $a0, $zero, 0x198
    ctx->r4 = 0 | 0X198;
    // ori         $a1, $zero, 0x1C0
    ctx->r5 = 0 | 0X1C0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // jal         0x8002F984
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    VRAM_ReserveTextureSpace(rdram, ctx);
    goto after_29;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_29:
    // ori         $a0, $zero, 0x1A0
    ctx->r4 = 0 | 0X1A0;
    // ori         $a1, $zero, 0x1C0
    ctx->r5 = 0 | 0X1C0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x4
    ctx->r7 = 0 | 0X4;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // jal         0x8002F984
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    VRAM_ReserveTextureSpace(rdram, ctx);
    goto after_30;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_30:
    // ori         $a0, $zero, 0x150
    ctx->r4 = 0 | 0X150;
    // ori         $a1, $zero, 0x140
    ctx->r5 = 0 | 0X140;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x2
    ctx->r7 = 0 | 0X2;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8002F984
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    VRAM_ReserveTextureSpace(rdram, ctx);
    goto after_31;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_31:
    // ori         $a0, $zero, 0x150
    ctx->r4 = 0 | 0X150;
    // ori         $a1, $zero, 0x100
    ctx->r5 = 0 | 0X100;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // ori         $a3, $zero, 0x4
    ctx->r7 = 0 | 0X4;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8002F984
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    VRAM_ReserveTextureSpace(rdram, ctx);
    goto after_32;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_32:
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x1EE4
    ctx->r4 = ADD32(ctx->r4, -0X1EE4);
    // lui         $a1, 0x5
    ctx->r5 = S32(0X5 << 16);
    // jal         0x80017AA4
    // ori         $a1, $a1, 0xF000
    ctx->r5 = ctx->r5 | 0XF000;
    Heap_Init(rdram, ctx);
    goto after_33;
    // ori         $a1, $a1, 0xF000
    ctx->r5 = ctx->r5 | 0XF000;
    after_33:
    // ori         $a0, $zero, 0x82
    ctx->r4 = 0 | 0X82;
    // ori         $a1, $zero, 0x1000
    ctx->r5 = 0 | 0X1000;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80039898
    // addiu       $a3, $zero, -0x80
    ctx->r7 = ADD32(0, -0X80);
    FadeScreenIn(rdram, ctx);
    goto after_34;
    // addiu       $a3, $zero, -0x80
    ctx->r7 = ADD32(0, -0X80);
    after_34:
    // addiu       $s2, $s3, 0xA
    ctx->r18 = ADD32(ctx->r19, 0XA);
    // addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // ori         $s3, $zero, 0x1
    ctx->r19 = 0 | 0X1;
    // sw          $zero, 0x1A0($gp)
    MEM_W(0X1A0, ctx->r28) = 0;
L_80013D74:
    // jal         0x8002E73C
    // nop

    PrepareRenderPrimitives(rdram, ctx);
    goto after_35;
    // nop

    after_35:
    // jal         0x80039948
    // nop

    UpdateObjects(rdram, ctx);
    goto after_36;
    // nop

    after_36:
    // jal         0x8002C348
    // nop

    _ControllerInput(rdram, ctx);
    goto after_37;
    // nop

    after_37:
    // jal         0x80042064
    // nop

    Entities_UpdateAll(rdram, ctx);
    goto after_38;
    // nop

    after_38:
    // jal         0x80048668
    // nop

    UpdateParticleSystem(rdram, ctx);
    goto after_39;
    // nop

    after_39:
    // jal         0x8004AD18
    // sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    Map_ScriptUpdate(rdram, ctx);
    goto after_40;
    // sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    after_40:
    // jal         0x80016CD0
    // nop

    Map_Load(rdram, ctx);
    goto after_41;
    // nop

    after_41:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8002791C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    KF_PlayerCopyPositionRotation(rdram, ctx);
    goto after_42;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_42:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800144C0
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    UpdatePlayerMapContext(rdram, ctx);
    goto after_43;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_43:
    // jal         0x8002E86C
    // nop

    PrecomputeCardinalOrientations(rdram, ctx);
    goto after_44;
    // nop

    after_44:
    // jal         0x800173EC
    // nop

    ProcessAssetLoadQueue(rdram, ctx);
    goto after_45;
    // nop

    after_45:
    // jal         0x80014988
    // nop

    ProcessCDAudioLoad(rdram, ctx);
    goto after_46;
    // nop

    after_46:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800360A0
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    KF_GpuUpdate(rdram, ctx);

    u_short raw = *(u_short*)&g_pad1_buf[2];
    raw = ((raw >> 8) & 0xFF) | ((raw << 8) & 0xFF00);
    u_short buttons = ~raw;
    if (buttons) {
        printf("[PAD] raw=%04X buttons=%04X\n", *(u_short*)&g_pad1_buf[2], buttons);
    }

    goto after_47;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_47:
    // lw          $v0, 0x1A0($gp)
    ctx->r2 = MEM_W(0X1A0, ctx->r28);
    // nop

    // beq         $v0, $zero, L_80013D74
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80013D74;
    }
    // nop

    // jal         0x80013E68
    // nop

    KF_StopPAD(rdram, ctx);
    goto after_48;
    // nop

    after_48:
    // lw          $v1, 0x1A0($gp)
    ctx->r3 = MEM_W(0X1A0, ctx->r28);
    // nop

    // bne         $v1, $s3, L_80013E30
    if (ctx->r3 != ctx->r19) {
        // ori         $v0, $zero, 0x9
        ctx->r2 = 0 | 0X9;
        goto L_80013E30;
    }
    // ori         $v0, $zero, 0x9
    ctx->r2 = 0 | 0X9;
    // lbu         $v1, 0xCC($s2)
    ctx->r3 = MEM_BU(0XCC, ctx->r18);
    // ori         $v0, $zero, 0x2
    ctx->r2 = 0 | 0X2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // sb          $v0, 0x2F0($at)
    MEM_B(0X2F0, ctx->r1) = ctx->r2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // sb          $v1, 0x2F8($at)
    MEM_B(0X2F8, ctx->r1) = ctx->r3;
    // j           L_80013E48
    // nop

    goto L_80013E48;
    // nop

L_80013E30:
    // bne         $v1, $v0, L_80013E48
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80013E48;
    }
    // nop

    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // sb          $zero, 0x2F0($at)
    MEM_B(0X2F0, ctx->r1) = 0;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // sb          $s3, 0x2F8($at)
    MEM_B(0X2F8, ctx->r1) = ctx->r19;
L_80013E48:
    // lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(0X50, ctx->r29);
    // lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
