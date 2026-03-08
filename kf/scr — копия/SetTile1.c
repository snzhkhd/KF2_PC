#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetTile1(uint8_t* rdram, recomp_context* ctx) {
	setTile1((TILE_1*)GET_PTR(ctx->r4));
	;
}
