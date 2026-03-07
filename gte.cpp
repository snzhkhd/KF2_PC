#include "gte.h"
#include "psx/gtereg.h"
#include <string>
    





void ctx_to_gte(recomp_context* ctx)
{
    memcpy(&gteRegs.CP2D, ctx->cp2d, 32 * 4);
    memcpy(&gteRegs.CP2C, ctx->cp2c, 32 * 4);
}
void gte_to_ctx(recomp_context* ctx)
{
    memcpy(ctx->cp2d, &gteRegs.CP2D, 32 * 4);
    memcpy(ctx->cp2c, &gteRegs.CP2C, 32 * 4);
}