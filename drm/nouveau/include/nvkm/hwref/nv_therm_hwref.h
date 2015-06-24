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
#ifndef __nv_therm_hwref_h__
#define __nv_therm_hwref_h__

#define __nv_therm_compat_0(c) \
	((c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_therm_compat_1(c) \
	((c==__nv_g84__) || (c==__nv_g86__) || (c==__nv_g92__) || (c==__nv_g94__) || (c==__nv_g96__) || (c==__nv_g98__) || (c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__) || (c==__nv_gt200__) || (c==__nv_gt215__) || (c==__nv_gt216__) || (c==__nv_gt218__))
#define __nv_therm_compat_2(c) \
	((c==__nv_gk20a__) || (c==__nv_gm20b__))
#define __nv_therm_compat_3(c) \
	((c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_therm_compat_4(c) \
	((c==__nv_g80__) || (c==__nv_g84__) || (c==__nv_g86__) || (c==__nv_g92__) || (c==__nv_g94__) || (c==__nv_g96__) || (c==__nv_g98__) || (c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__) || (c==__nv_gt200__) || (c==__nv_gt215__) || (c==__nv_gt216__) || (c==__nv_gt218__))

#ifndef __nv_chipset_target__
#error "__nv_chipset_target__ not defined"
#endif


#if __nv_therm_compat_0(__nv_chipset_target__)
#	define NV_THERM_CLK_SLOWDOWN_0(i) (0x20160+((i)*4))
#	define NV_THERM_CLK_SLOWDOWN_0_IDLE_FACTOR 21:16
#	define NV_THERM_GATE_CTRL(i) (0x20200+((i)*4))
#	define NV_THERM_GATE_CTRL_ENG_CLK 1:0
#	define NV_THERM_GATE_CTRL_ENG_CLK_RUN 0
#	define NV_THERM_GATE_CTRL_ENG_CLK_AUTO 1
#	define NV_THERM_GATE_CTRL_ENG_CLK_STOP 2
#	define NV_THERM_GATE_CTRL_BLK_CLK 3:2
#	define NV_THERM_GATE_CTRL_BLK_CLK_RUN 0
#	define NV_THERM_GATE_CTRL_BLK_CLK_AUTO 1
#	define NV_THERM_GATE_CTRL_ENG_PWR 5:4
#	define NV_THERM_GATE_CTRL_ENG_PWR_AUTO 1
#	define NV_THERM_GATE_CTRL_ENG_PWR_OFF 2
#	define NV_THERM_GATE_CTRL_ENG_IDLE_FILT_EXP 12:8
#	define NV_THERM_GATE_CTRL_ENG_IDLE_FILT_MANT 15:13
#	define NV_THERM_GATE_CTRL_ENG_DELAY_AFTER 23:20
#	define NV_THERM_FECS_IDLE_FILTER 0x20288
#	define NV_THERM_FECS_IDLE_FILTER_VALUE 31:0
#	define NV_THERM_HUBMMU_IDLE_FILTER 0x2028c
#	define NV_THERM_HUBMMU_IDLE_FILTER_VALUE 31:0
#endif
#if __nv_therm_compat_1(__nv_chipset_target__)
#	define NV_THERM_CONFIG1 0x20050
#endif
#if __nv_therm_compat_2(__nv_chipset_target__)
#	define NV_THERM_EVT_EXT_THERM_0 0x20700
#	define NV_THERM_EVT_EXT_THERM_1 0x20704
#	define NV_THERM_EVT_EXT_THERM_2 0x20708
#endif
#if __nv_therm_compat_3(__nv_chipset_target__)
#	define NV_THERM_USE_A 0x20798
#endif
#if __nv_therm_compat_4(__nv_chipset_target__)
#	define NV_THERM_WEIGHT_1 0x20024
#endif
#endif /* __nv_therm_hwref_h__ */
