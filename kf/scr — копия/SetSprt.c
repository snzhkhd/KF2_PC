#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void KF_SetSprt(uint8_t* rdram, recomp_context* ctx) {
	SetSprt((SPRT*)GET_PTR(ctx->r4));
	;
}
