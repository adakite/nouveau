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
#ifndef __nv_bus_hwref_h__
#define __nv_bus_hwref_h__

#define __nv_bus_compat_0(c) \
	((c==__nv_g80__) || (c==__nv_g84__) || (c==__nv_g86__) || (c==__nv_g92__) || (c==__nv_g94__) || (c==__nv_g96__) || (c==__nv_g98__) || (c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__) || (c==__nv_gt200__) || (c==__nv_gt215__) || (c==__nv_gt216__) || (c==__nv_gt218__))
#define __nv_bus_compat_1(c) \
	((c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_bus_compat_2(c) \
	((c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))

#ifndef __nv_chipset_target__
#error "__nv_chipset_target__ not defined"
#endif


#if __nv_bus_compat_0(__nv_chipset_target__)
#	define NV_PBUS_INTR_0 0x1100
#	define NV_PBUS_INTR_0_PRI_TIMEOUT 3:3
#	define NV_PBUS_INTR_EN_0 0x1140
#	define NV_PBUS_INTR_EN_0_PRI_TIMEOUT 3:3
#	define NV_PBUS_BAR1_BLOCK 0x1704
#	define NV_PBUS_BAR1_BLOCK_PTR 27:0
#	define NV_PBUS_BAR1_BLOCK_TARGET 29:28
#	define NV_PBUS_BAR1_BLOCK_TARGET_VID_MEM 0
#endif
#if __nv_bus_compat_1(__nv_chipset_target__)
#	define NV_PBUS_INTR_0_PRI_SQUASH 1:1
#	define NV_PBUS_INTR_0_PRI_FECSERR 2:2
#	define NV_PBUS_INTR_EN_0_PRI_SQUASH 1:1
#	define NV_PBUS_INTR_EN_0_PRI_FECSERR 2:2
#	define NV_PBUS_BAR1_BLOCK_MODE 31:31
#	define NV_PBUS_BAR1_BLOCK_MODE_VIRTUAL 1
#	define NV_PBUS_BAR2_BLOCK 0x1714
#	define NV_PBUS_BAR2_BLOCK_PTR 27:0
#	define NV_PBUS_BAR2_BLOCK_TARGET 29:28
#	define NV_PBUS_BAR2_BLOCK_TARGET_VID_MEM 0
#	define NV_PBUS_BAR2_BLOCK_MODE 31:31
#	define NV_PBUS_BAR2_BLOCK_MODE_VIRTUAL 1
#endif
#if __nv_bus_compat_2(__nv_chipset_target__)
#	define NV_PBUS_BAR1_BLOCK_PTR_SHIFT 12
#	define NV_PBUS_BAR2_BLOCK_PTR_SHIFT 12
#endif
#endif /* __nv_bus_hwref_h__ */
