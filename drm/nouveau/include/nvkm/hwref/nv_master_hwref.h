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
#ifndef __nv_master_hwref_h__
#define __nv_master_hwref_h__

#define __nv_master_compat_0(c) \
	((c==__nv_g80__) || (c==__nv_g84__) || (c==__nv_g86__) || (c==__nv_g92__) || (c==__nv_g94__) || (c==__nv_g96__) || (c==__nv_g98__) || (c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__) || (c==__nv_gt200__) || (c==__nv_gt215__) || (c==__nv_gt216__) || (c==__nv_gt218__))
#define __nv_master_compat_1(c) \
	((c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_master_compat_2(c) \
	((c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_master_compat_3(c) \
	((c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_master_compat_4(c) \
	((c==__nv_gt215__) || (c==__nv_gt216__) || (c==__nv_gt218__))
#define __nv_master_compat_5(c) \
	((c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_master_compat_6(c) \
	((c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__) || (c==__nv_gt200__) || (c==__nv_gt215__) || (c==__nv_gt216__) || (c==__nv_gt218__))
#define __nv_master_compat_7(c) \
	((c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__) || (c==__nv_gt215__) || (c==__nv_gt216__) || (c==__nv_gt218__))
#define __nv_master_compat_8(c) \
	((c==__nv_gt200__))
#define __nv_master_compat_9(c) \
	((c==__nv_gm204__) || (c==__nv_gm20b__))

#ifndef __nv_chipset_target__
#error "__nv_chipset_target__ not defined"
#endif


#if __nv_master_compat_0(__nv_chipset_target__)
#	define NV_PMC_BOOT_0 0
#	define NV_PMC_BOOT_0_MINOR_REVISION 3:0
#	define NV_PMC_BOOT_0_MAJOR_REVISION 7:4
#	define NV_PMC_BOOT_0_IMPLEMENTATION 23:20
#	define NV_PMC_BOOT_0_ARCHITECTURE 28:24
#	define NV_PMC_INTR_0 0x100
#	define NV_PMC_INTR_0_PFIFO 8:8
#	define NV_PMC_INTR_0_PGRAPH 12:12
#	define NV_PMC_INTR_0_PBUS 28:28
#	define NV_PMC_INTR_EN_0 0x140
#	define NV_PMC_INTR_EN_0_INTA 1:0
#	define NV_PMC_INTR_EN_0_INTA_HARDWARE 1
#	define NV_PMC_ENABLE 0x200
#	define NV_PMC_ENABLE_PMEDIA 4:4
#	define NV_PMC_ENABLE_PFIFO 8:8
#	define NV_PMC_ENABLE_PGRAPH 12:12
#	define NV_PMC_ENABLE_PFB 20:20
#endif
#if __nv_master_compat_1(__nv_chipset_target__)
#	define NV_PMC_ELPG_ENABLE 0x20c
#endif
#if __nv_master_compat_2(__nv_chipset_target__)
#	define NV_PMC_ENABLE_CE2 21:21
#	define NV_PMC_ELPG_ENABLE_XBAR 2:2
#	define NV_PMC_ELPG_ENABLE_PFB 20:20
#	define NV_PMC_ELPG_ENABLE_HUB 29:29
#endif
#if __nv_master_compat_3(__nv_chipset_target__)
#	define NV_PMC_INTR_0_PMU 24:24
#	define NV_PMC_INTR_0_LTC 25:25
#	define NV_PMC_INTR_0_PRIV_RING 30:30
#	define NV_PMC_INTR_MSK_0_PMU 24:24
#	define NV_PMC_ENABLE_CE0 6:6
#	define NV_PMC_INTR_MSK_1_PMU 24:24
#	define NV_PMC_INTR_LTC 0x17c
#	define NV_PMC_ENABLE_XBAR 2:2
#	define NV_PMC_ENABLE_L2 3:3
#	define NV_PMC_ENABLE_PRIV_RING 5:5
#	define NV_PMC_ENABLE_PWR 13:13
#	define NV_PMC_ENABLE_BLG 27:27
#	define NV_PMC_ENABLE_PERFMON 28:28
#	define NV_PMC_ENABLE_HUB 29:29
#	define NV_PMC_ENABLE_PB 0x204
#	define NV_PMC_ENABLE_PB_0 0:0
#	define NV_PMC_ENABLE_PB_SEL(i) (i):(i)
#endif
#if __nv_master_compat_4(__nv_chipset_target__)
#	define NV_PMC_INTR_0_PMU 18:18
#	define NV_PMC_INTR_MSK_0_PMU 18:18
#	define NV_PMC_ENABLE_CE0 13:13
#endif
#if __nv_master_compat_5(__nv_chipset_target__)
#	define NV_PMC_INTR(i) (0x100+(i)*4)
#	define NV_PMC_INTR_PFIFO 8:8
#	define NV_PMC_INTR_PMU 24:24
#	define NV_PMC_INTR_LTC_ALL 25:25
#	define NV_PMC_INTR_PBUS 28:28
#	define NV_PMC_INTR_PRIV_RING 30:30
#endif
#if __nv_master_compat_6(__nv_chipset_target__)
#	define NV_PMC_INTR_1 0x104
#	define NV_PMC_INTR_MSK_0 0x640
#	define NV_PMC_INTR_EN_1_INTA 1:0
#	define NV_PMC_INTR_EN_1_INTA_HARDWARE 1
#endif
#if __nv_master_compat_7(__nv_chipset_target__)
#	define NV_PMC_INTR_MSK_1 0x644
#	define NV_PMC_INTR_EN_1 0x144
#endif
#if __nv_master_compat_8(__nv_chipset_target__)
#	define NV_PMC_INTR_MSK_1 0x680
#	define NV_PMC_INTR_EN_1 0x540
#endif
#if __nv_master_compat_9(__nv_chipset_target__)
#	define NV_PMC_INTR_PGRAPH 12:12
#endif
#endif /* __nv_master_hwref_h__ */
