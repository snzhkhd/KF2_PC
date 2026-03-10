# King's Field 2 — PS1→PC Port:

### Dependencies
- OpenAL-soft (1.21.x or newer)
- SDL2 (2.0.16 or newer)



## General Architecture

**Technology Stack**:
- **PS1Recom** [(link)](https://github.com/snzhkhd/PS1Recomp.git) — MIPS→C static recompiler. Generates C code where each PS1 function has the following signature:
  ```cpp
  void func_XXXXXXXX(uint8_t* rdram, recomp_context* ctx);
  ```
- **PsyX 2.8** — PS1 SDK emulation layer (SDL2 + OpenGL). Includes renderer, GTE, pad input, SPU, etc. [(link)](https://github.com/OpenDriver2/PsyCross.git)
- **HLE (High Level Emulation)** — BIOS calls and system functions.

---

## recomp_context

```cpp
typedef struct recomp_context {
    uint32_t r0..r31;   // MIPS General Purpose Registers (r0 is always 0)
    uint32_t lo, hi;    // HI/LO registers for multiplication/division
    uint32_t pc;        // Program Counter
    uint32_t cp2d[32];  // GTE data registers (Cop2 data)
    uint32_t cp2c[32];  // GTE control registers (Cop2 control)
    uint32_t cop0_status; // Cop0 Status register
} recomp_context;
```

---

## Memory

- PS1 RAM: 2MB, `uint8_t rdram[]`
- PS1 addresses: `0x80000000..0x801FFFFF`
- Masks: `addr & 0x1FFFFF` 
- Access macros:
  ```cpp
  GET_PTR(ps1_addr)        // → uint8_t* в rdram
  MEM_W(offset, base)      // → uint32_t& (read/write)
  MEM_H(offset, base)      // → uint16_t&
  MEM_B(offset, base)      // → uint8_t&
  WRITE_W(addr, value)     // запись uint32_t
  ```

---

## Function table
```cpp
std::map<uint32_t, recomp_func_t> g_func_table;
// Регистрация:
REGISTER_FUNC(0x8005F2C8, sub_8005F2C8);
// Вызов:
recomp_func_t fn = lookup_recomp_func(0x80017D2C);
if (fn) fn(rdram, ctx);
```
---


## CD-ROM system

### Disk Image
```cpp
FILE* g_cdImage; // It is open as a binary
// Сектор данных: lba*2352 + 24
fseek(g_cdImage, lba * 2352 + 24, SEEK_SET);
fread(buf, 1, 2048, g_cdImage);
```

### Stream Structure (40 bytes, in PS1 RAM)
```
stream[0]      = type (0x10=tilemap, 0x20=SPU, 0x40=textures/audio)
stream[1]      = state (0=reading, 1=verifying)
stream[2..5]   = CdlLOC current position
stream[6..9]   = CdlLOC base position
stream[12]     = destination buffer address (uint32_t)
stream[16]     = chunks_rem — current chunk (uint16_t)
stream[20]     = callback address (uint32_t)
stream[34]     = remaining chunks (uint16_t) — for CalculateNextCdChunk
stream[36]     = data_ready flag (1=data ready)
```

---

## Gamepad

```cpp
// PsyX_pad.cpp
extern u_char g_pad1_buf[34]; // static buffer
extern int g_padCommEnable;   // must be 1

// Byte-swap + inversion for PS1 format:
u_short raw = *(u_short*)&g_pad1_buf[2];
raw = ((raw >> 8) & 0xFF) | ((raw << 8) & 0xFF00);
u_short buttons = ~raw; // 1=pressed
```

---

## Renderer (PsyX/OpenGL)

- `TriggerGpuDma` — entry point for GPU DMA commands
- `GR_CopyRGBAFramebufferToVRAM` — alpha: `r==0 && g==0 && b==0 ? 0 : 1`
- `DrawAllSplits` — finalizes `numVerts` before rendering
- `PsyX_BeginScene` — requires `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)`

---
## Project File Structure

```
OpenKF2/
├── main.cpp              — entry point, EXE loading, main loop
├── kf_cd.cpp             — custom HLE CD handling, KFCD_CdControl\KFCD_Init\KFCD_CdPosToInt\KFCD_CdRead\KFCD_CdReadSync\KFCD_CdSync
├── recomp.cpp            — Implementation of A0/B0/C0 dispatchers, global variables
├── gte.h\cpp             — GTE functions (ctx_to_gte, gte_command, etc.)
├── kf/
│   ├── recomp.h          — Declarations of A0/B0/C0 dispatchers, global variables (extern struct recomp_context* g_ctx;\g_pad1_buf\g_pad2_buf)
│   ├── _context.h        — uint8_t rdram[2 * 1024 * 1024], macros GET_PTR(addr) (&rdram[(addr) & 0x1FFFFF]), MEM_W, etc.
│   └── scr/              — implementation of recompiled functions. recomp_overlays.inl table
│       ├── funcs.h       — declarations of all recompiled game functions.
│       ├── recomp_overlays.inl — table of all functions.
│       └── *.c           — remaining 966 game functions (C code compiled as C++)
└── PsyX/                 — external library
```

