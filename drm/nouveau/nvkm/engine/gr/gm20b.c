/*
 * Copyright (c) 2015, NVIDIA CORPORATION. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#include "gk20a.h"
#include "ctxgf100.h"

#include <nvif/class.h>
#include <subdev/timer.h>

static struct nvkm_oclass
gm20b_gr_sclass[] = {
	{ FERMI_TWOD_A, &nvkm_object_ofuncs },
	{ KEPLER_INLINE_TO_MEMORY_B, &nvkm_object_ofuncs },
	{ MAXWELL_DMA_COPY_A, &nvkm_object_ofuncs },
	{ MAXWELL_B, &gf100_fermi_ofuncs, gf100_gr_9097_omthds },
	{ MAXWELL_COMPUTE_B, &nvkm_object_ofuncs, gf100_gr_90c0_omthds },
	{}
};

static void
gm20b_gr_init_gpc_mmu(struct gf100_gr_priv *priv)
{
	u32 val;

	/* TODO update once secure boot works */
	val = nv_rd32(priv, 0x100c80);
	val &= 0xf000087f;
	nv_wr32(priv, 0x418880, val);
	nv_wr32(priv, 0x418890, 0);
	nv_wr32(priv, 0x418894, 0);

	nv_wr32(priv, 0x4188b0, nv_rd32(priv, 0x100cc4));
	nv_wr32(priv, 0x4188b4, nv_rd32(priv, 0x100cc8));
	nv_wr32(priv, 0x4188b8, nv_rd32(priv, 0x100ccc));

	nv_wr32(priv, 0x4188ac, nv_rd32(priv, 0x100800));
}

static void
gm20b_gr_set_hww_esr_report_mask(struct gf100_gr_priv *priv)
{
	nv_wr32(priv, 0x419e44, 0xdffffe);
	nv_wr32(priv, 0x419e4c, 0x5);
}

struct nvkm_oclass *
gm20b_gr_oclass = &(struct gk20a_gr_oclass) {
	.gf100 = {
		.base.handle = NV_ENGINE(GR, 0x2b),
		.base.ofuncs = &(struct nvkm_ofuncs) {
			.ctor = gk20a_gr_ctor,
			.dtor = gf100_gr_dtor,
			.init = gk20a_gr_init,
			.fini = _nvkm_gr_fini,
		},
		.cclass = &gm20b_grctx_oclass,
		.sclass = gm20b_gr_sclass,
		.ppc_nr = 1,
	},
	.init_gpc_mmu = gm20b_gr_init_gpc_mmu,
	.set_hww_esr_report_mask = gm20b_gr_set_hww_esr_report_mask,
}.gf100.base;
