#include "recomp.h"
#include "disable_warnings.h"
#include <string>

/*
00000000 FileDescriptor  struc  # (sizeof=0xC, mappedto_13)
00000000 ram_buffer:     .word ?
00000004 cd_sector_low:  .word ?
00000008 cd_sector_high: .word ?
0000000C FileDescriptor  ends
*/

struct FileDescriptor
{
    uint32_t ram_buffer;
    uint32_t cd_sector_low;
    uint32_t cd_sector_high;
};


std::string GetNameType(int type)
{
    switch (type)
    {
    case 0 : return "MO";
    case 1:  return "RTMD";
    case 2:  return "RTIM";
    case 3:  return "TALK";
    case 4:  return "VAB";
    case 5:  return "FDAT";
    case 6:  return "ITEM";
    }
    return "unk";
}

void ReadFromFile(uint8_t* rdram, recomp_context* ctx) 
{

    uint16_t type = (uint16_t)ctx->r4;
    uint16_t a2 = (uint16_t)ctx->r5;

    //// g_FileDescriptors — адрес массива в PS1 RAM
    uint32_t desc_base = 0x801BA84C;
    uint32_t desc_addr = desc_base + type * 12;

    uint32_t ram_buffer = MEM_W(0, desc_addr);
    //uint32_t cd_sector_low = MEM_W(4, desc_addr);

    //CdlLOC* loc = (CdlLOC*)GET_PTR(desc_addr + 4);
    //int lba = KFCD_CdPosToInt(loc);

    //// Размер: (next_offset - cur_offset) << 11
    uint16_t cur = *(uint16_t*)GET_PTR(ram_buffer + 2 * a2);
    uint16_t next = *(uint16_t*)GET_PTR(ram_buffer + 2 * a2 + 2);
    int size = (next - cur) << 11;

    //printf("[ReadFromFile] type=%s(%d) a2=%d LBA=%d size=%d bytes\n",
    //    GetNameType(type).c_str(), type, a2, lba + cur, size);
    printf("[ReadFromFile] type=%s(%d) a2=%d size=%d bytes\n", GetNameType(type).c_str(), type, a2, size);

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x57B4
    ctx->r3 = ADD32(ctx->r3, -0X57B4);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // sll         $s2, $a1, 1
    ctx->r18 = S32(ctx->r5) << 1;
    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // lhu         $s1, 0x0($v0)
    ctx->r17 = MEM_HU(0X0, ctx->r2);
    // beq         $a2, $zero, L_8001846C
    if (ctx->r6 == 0) {
        // addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_8001846C;
    }
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // jal         0x80018150
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    ConvertCdAddress(rdram, ctx);
    goto after_0;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
L_8001846C:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // nop

    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
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
