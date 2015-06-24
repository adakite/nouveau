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
#ifndef __NV_MMU_HW_H__
#define __NV_MMU_HW_H__

/* This should be a full list of all gpus recognized by nouveau */
#define __nv_g80__ 0x80
#define __nv_g84__ 0x84
#define __nv_g86__ 0x86
#define __nv_g92__ 0x92
#define __nv_g94__ 0x94
#define __nv_g96__ 0x96
#define __nv_g98__ 0x98
#define __nv_gt200__ 0xa0
#define __nv_gt215__ 0xa3
#define __nv_gt216__ 0xa5
#define __nv_gt218__ 0xa8
#define __nv_gf100__ 0xc0
#define __nv_gf110__ 0xc8
#define __nv_gf104__ 0xc4
#define __nv_gf106__ 0xc3
#define __nv_gf108__ 0xc1
#define __nv_gf117__ 0xd7
#define __nv_gf119__ 0xd9
#define __nv_gk104__ 0xe4
#define __nv_gk106__ 0xe6
#define __nv_gk107__ 0xe7
#define __nv_gk110__ 0xf0
#define __nv_gk208__ 0x108
#define __nv_gk20a__ 0xea
#define __nv_gm107__ 0x117
#define __nv_gm204__ 0x124
#define __nv_gm20b__ 0x12b

/*
 * These are compatibility clauses across  "mmu" for the GPUs given above.
 * Differences between hardware source definitions result in equivalence
 * classes of GPUs for these defs.  This can often be changes from one arch
 * to the next (e.g. Fermi->Kepler).  But it can also happen for other reasons.
 * Spurious definition changes (unfortunate) and legit changes which occur at
 * non-arch boundaries can also show up here.  The names aren't important.
 * The important thing is we can spot where definitions may be in use when
 * they aren't appropriate...
 *
 */

#define __nv_mmu_compat_0(c)                                        \
	((c==__nv_g80__) || (c==__nv_g84__) || (c==__nv_g86__) ||       \
	 (c==__nv_g92__) || (c==__nv_g94__) || (c==__nv_g96__) ||       \
	 (c==__nv_g98__) || (c==__nv_gt200__) || (c==__nv_gt215__) ||   \
	 (c==__nv_gt216__) || (c==__nv_gt218__))

#define __nv_mmu_compat_1(c)                                            \
	((c==__nv_gf100__) || (c==__nv_gf100b__) || (c==__nv_gf104__) ||    \
	 (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf117__) ||     \
	 (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) ||     \
	 (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) ||     \
	 (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) ||     \
	 (c==__nv_gm20b__))

#define __nv_mmu_compat_2(c)                                            \
	((c==__nv_g80__) || (c==__nv_g84__) || (c==__nv_g86__) ||           \
	 (c==__nv_g92__) || (c==__nv_g94__) || (c==__nv_g96__) ||           \
	 (c==__nv_g98__) || (c==__nv_gf100__) || (c==__nv_gf100b__) ||      \
	 (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) ||     \
	 (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) ||     \
	 (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) ||     \
	 (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) ||     \
	 (c==__nv_gm204__) || (c==__nv_gm20b__) || (c==__nv_gt200__) ||     \
	 (c==__nv_gt215__) || (c==__nv_gt216__) || (c==__nv_gt218__))

#define __nv_mmu_compat_3(c)                                        \
	((c==__nv_g94__) || (c==__nv_g96__) || (c==__nv_g98__) ||       \
	 (c==__nv_gt200__) || (c==__nv_gt215__) || (c==__nv_gt216__) || \
	 (c==__nv_gt218__))

#define __nv_mmu_compat_4(c)                                        \
	((c==__nv_gt200__) || (c==__nv_gt215__) || (c==__nv_gt216__) || \
	 (c==__nv_gt218__))

#define __nv_mmu_compat_5(c)                                  \
	((c==__nv_g80__) || (c==__nv_g84__) || (c==__nv_g86__) || \
	 (c==__nv_g92__) || (c==__nv_g94__) || (c==__nv_g96__) || \
	 (c==__nv_g98__) || (c==__nv_gt200__))

#define __nv_mmu_compat_6(c)                                        \
	((c==__nv_gt215__) || (c==__nv_gt216__) || (c==__nv_gt218__))

#define __nv_mmu_compat_7(c)                                        \
	((c==__nv_g84__) || (c==__nv_g86__) || (c==__nv_g92__) ||       \
	 (c==__nv_g94__) || (c==__nv_g96__) || (c==__nv_g98__) ||       \
	 (c==__nv_gt200__) || (c==__nv_gt215__) || (c==__nv_gt216__) || \
	 (c==__nv_gt218__))

#define __nv_mmu_compat_8(c)                                         \
	((c==__nv_g84__) || (c==__nv_g86__) || (c==__nv_g92__) ||        \
	 (c==__nv_g94__) || (c==__nv_g96__) || (c==__nv_g98__) ||        \
	 (c==__nv_gf100__) || (c==__nv_gf100b__) || (c==__nv_gf104__) || \
	 (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf117__) ||  \
	 (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) ||  \
	 (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) ||  \
	 (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) ||  \
	 (c==__nv_gm20b__) || (c==__nv_gt200__) || (c==__nv_gt215__) ||  \
	 (c==__nv_gt216__) || (c==__nv_gt218__))

#define __nv_mmu_compat_9(c)                    \
	((c==__nv_gm204__) || (c==__nv_gm20b__))

#define __nv_mmu_compat_10(c)                                       \
	((c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || \
	 (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || \
	 (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))

/*
 * Code using this header must target a specific chip.
 */
#ifndef __nv_chipset_target__
#error "__nv_chipset_target__ not defined"

#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PDE_4K_PDE_SIZE (0*32+6):(0*32+5)
#	define NV_MMU_PDE_4K_PDE_SIZE_128K_ENTRIES 0x0
#	define NV_MMU_PDE_4K_PDE_SIZE_16K_ENTRIES 0x2
#	define NV_MMU_PDE_4K_PDE_SIZE_32K_ENTRIES 0x1
#	define NV_MMU_PDE_4K_PDE_SIZE_8K_ENTRIES 0x3
#	define NV_MMU_PDE_ACCESS_BIT_CACHE (0*32+4):(0*32+4)
#	define NV_MMU_PDE_ACCESS_BIT_CACHE_DISABLED 0x0
#	define NV_MMU_PDE_ACCESS_BIT_CACHE_ENABLED 0x1
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PDE_ADDRESS_BIG_SYS (0*32+31):(0*32+4)
#	define NV_MMU_PDE_ADDRESS_BIG_VID (0*32+31-3):(0*32+4)
#	define NV_MMU_PDE_ADDRESS_BIG_VID_PEER (0*32+31):(0*32+32-3)
#	define NV_MMU_PDE_ADDRESS_BIG_VID_PEER_0 0x0
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PDE_ADDRESS_HIGH (1*32+7):(1*32+0)
#	define NV_MMU_PDE_ADDRESS_LOW (0*32+31):(0*32+12)
#endif
#if __nv_mmu_compat_2(__nv_chipset_target__)
#	define NV_MMU_PDE_ADDRESS_SHIFT 0xc
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PDE_ADDRESS_SMALL_SYS (1*32+31):(1*32+4)
#	define NV_MMU_PDE_ADDRESS_SMALL_VID (1*32+31-3):(1*32+4)
#	define NV_MMU_PDE_ADDRESS_SMALL_VID_PEER (1*32+31):(1*32+32-3)
#	define NV_MMU_PDE_ADDRESS_SMALL_VID_PEER_0 0x0
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PDE_APERTURE (0*32+3):(0*32+2)
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PDE_APERTURE_BIG (0*32+1):(0*32+0)
#	define NV_MMU_PDE_APERTURE_BIG_INVALID 0x0
#	define NV_MMU_PDE_APERTURE_BIG_SYSTEM_COHERENT_MEMORY 0x2
#	define NV_MMU_PDE_APERTURE_BIG_SYSTEM_NON_COHERENT_MEMORY 0x3
#	define NV_MMU_PDE_APERTURE_BIG_VIDEO_MEMORY 0x1
#	define NV_MMU_PDE_APERTURE_SMALL (1*32+1):(1*32+0)
#	define NV_MMU_PDE_APERTURE_SMALL_INVALID 0x0
#	define NV_MMU_PDE_APERTURE_SMALL_SYSTEM_COHERENT_MEMORY 0x2
#	define NV_MMU_PDE_APERTURE_SMALL_SYSTEM_NON_COHERENT_MEMORY 0x3
#	define NV_MMU_PDE_APERTURE_SMALL_VIDEO_MEMORY 0x1
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PDE_APERTURE_SYSTEM_COHERENT_MEMORY 0x2
#	define NV_MMU_PDE_APERTURE_SYSTEM_NON_COHERENT_MEMORY 0x3
#	define NV_MMU_PDE_APERTURE_VIDEO_MEMORY 0x0
#endif
#if __nv_mmu_compat_3(__nv_chipset_target__)
#	define NV_MMU_PDE_SET_INDEX_SHIFT (1*32+26):(1*32+24)
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PDE_SIZE (0*32+3):(0*32+2)
#	define NV_MMU_PDE_SIZE_EIGHTH 0x3
#	define NV_MMU_PDE_SIZE_FULL 0x0
#	define NV_MMU_PDE_SIZE_HALF 0x1
#	define NV_MMU_PDE_SIZE_QUARTER 0x2
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PDE_TYPE (0*32+1):(0*32+0)
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PDE_TYPE_16K 0x2
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PDE_TYPE_4K 0x3
#	define NV_MMU_PDE_TYPE_64K 0x1
#	define NV_MMU_PDE_TYPE_NOT_PRESENT 0x0
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PDE_VOL_BIG (1*32+3):(1*32+3)
#	define NV_MMU_PDE_VOL_BIG_FALSE 0x0
#	define NV_MMU_PDE_VOL_BIG_TRUE 0x1
#	define NV_MMU_PDE_VOL_SMALL (1*32+2):(1*32+2)
#	define NV_MMU_PDE_VOL_SMALL_FALSE 0x0
#	define NV_MMU_PDE_VOL_SMALL_TRUE 0x1
#endif
#if __nv_mmu_compat_2(__nv_chipset_target__)
#	define NV_MMU_PDE__SIZE 0x8
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PTE_ADDRESS_16K_LOW (0*32+31):(0*32+14)
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_ADDRESS_4K_LOW (0*32+31):(0*32+12)
#	define NV_MMU_PTE_ADDRESS_64K_LOW (0*32+31):(0*32+16)
#	define NV_MMU_PTE_ADDRESS_HIGH (1*32+7):(1*32+0)
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_ADDRESS_SHIFT 0xc
#	define NV_MMU_PTE_ADDRESS_SYS (0*32+31):(0*32+4)
#	define NV_MMU_PTE_ADDRESS_VID (0*32+31-3):(0*32+4)
#	define NV_MMU_PTE_ADDRESS_VID_PEER (0*32+31):(0*32+32-3)
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_APERTURE (0*32+5):(0*32+4)
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_APERTURE (1*32+2):(1*32+1)
#endif
#if __nv_mmu_compat_2(__nv_chipset_target__)
#	define NV_MMU_PTE_APERTURE_PEER_MEMORY 0x1
#	define NV_MMU_PTE_APERTURE_SYSTEM_COHERENT_MEMORY 0x2
#	define NV_MMU_PTE_APERTURE_SYSTEM_NON_COHERENT_MEMORY 0x3
#	define NV_MMU_PTE_APERTURE_VIDEO_MEMORY 0x0
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_COMPTAGLINE (1*32+28):(1*32+12)
#endif
#if __nv_mmu_compat_5(__nv_chipset_target__)
#	define NV_MMU_PTE_COMPTAGLINE (1*32+28):(1*32+17)
#endif
#if __nv_mmu_compat_6(__nv_chipset_target__)
#	define NV_MMU_PTE_COMPTAGLINE (1*32+29):(1*32+17)
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_COMPTAGS (1*32+16):(1*32+15)
#endif
#if __nv_mmu_compat_2(__nv_chipset_target__)
#	define NV_MMU_PTE_COMPTAGS_1 0x1
#	define NV_MMU_PTE_COMPTAGS_2 0x2
#	define NV_MMU_PTE_COMPTAGS_NONE 0x0
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_CONTIGUOUS (0*32+9):(0*32+7)
#	define NV_MMU_PTE_CONTIGUOUS_128_PAGE 0x7
#	define NV_MMU_PTE_CONTIGUOUS_16_PAGE 0x4
#	define NV_MMU_PTE_CONTIGUOUS_1_PAGE 0x0
#	define NV_MMU_PTE_CONTIGUOUS_2_PAGE 0x1
#	define NV_MMU_PTE_CONTIGUOUS_32_PAGE 0x5
#	define NV_MMU_PTE_CONTIGUOUS_4_PAGE 0x2
#	define NV_MMU_PTE_CONTIGUOUS_64_PAGE 0x6
#	define NV_MMU_PTE_CONTIGUOUS_8_PAGE 0x3
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_ENCRYPTED (0*32+3):(0*32+3)
#endif
#if __nv_mmu_compat_7(__nv_chipset_target__)
#	define NV_MMU_PTE_ENCRYPTED (1*32+30):(1*32+30)
#endif
#if __nv_mmu_compat_8(__nv_chipset_target__)
#	define NV_MMU_PTE_ENCRYPTED_FALSE 0x0
#	define NV_MMU_PTE_ENCRYPTED_TRUE 0x1
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND (1*32+11):(1*32+4)
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND (1*32+14):(1*32+8)
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C128_2C 0xf4
#	define NV_MMU_PTE_KIND_C128_2CR 0xf5
#	define NV_MMU_PTE_KIND_C128_MS2_2C 0xf6
#	define NV_MMU_PTE_KIND_C128_MS2_2CR 0xf7
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C128_MS4 0x7e
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C128_MS4_2C 0xf8
#	define NV_MMU_PTE_KIND_C128_MS4_2CR 0xf9
#	define NV_MMU_PTE_KIND_C128_MS8_MS16_2C 0xfa
#	define NV_MMU_PTE_KIND_C128_MS8_MS16_2CR 0xfb
#	define NV_MMU_PTE_KIND_C32_2BRA 0xdc
#	define NV_MMU_PTE_KIND_C32_2C 0xd8
#	define NV_MMU_PTE_KIND_C32_2CBA 0xda
#	define NV_MMU_PTE_KIND_C32_2CBR 0xd9
#	define NV_MMU_PTE_KIND_C32_2CRA 0xdb
#	define NV_MMU_PTE_KIND_C32_MS2_2C 0xdd
#	define NV_MMU_PTE_KIND_C32_MS2_2CBR 0xde
#	define NV_MMU_PTE_KIND_C32_MS2_2CRA 0xcc
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C32_MS4 0x78
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C32_MS4_2BRA 0xe3
#	define NV_MMU_PTE_KIND_C32_MS4_2C 0xdf
#	define NV_MMU_PTE_KIND_C32_MS4_2CBA 0xe1
#	define NV_MMU_PTE_KIND_C32_MS4_2CBR 0xe0
#	define NV_MMU_PTE_KIND_C32_MS4_2CRA 0xe2
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C32_MS4_BANKSWIZ 0x7a
#	define NV_MMU_PTE_KIND_C32_MS8 0x79
#	define NV_MMU_PTE_KIND_C32_MS8_BANKSWIZ 0x7b
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C32_MS8_MS16_2C 0xe4
#	define NV_MMU_PTE_KIND_C32_MS8_MS16_2CRA 0xe5
#	define NV_MMU_PTE_KIND_C64_2BRA 0xea
#	define NV_MMU_PTE_KIND_C64_2C 0xe6
#	define NV_MMU_PTE_KIND_C64_2CBA 0xe8
#	define NV_MMU_PTE_KIND_C64_2CBR 0xe7
#	define NV_MMU_PTE_KIND_C64_2CRA 0xe9
#	define NV_MMU_PTE_KIND_C64_MS2_2C 0xeb
#	define NV_MMU_PTE_KIND_C64_MS2_2CBR 0xec
#	define NV_MMU_PTE_KIND_C64_MS2_2CRA 0xcd
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C64_MS4 0x7c
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C64_MS4_2BRA 0xf1
#	define NV_MMU_PTE_KIND_C64_MS4_2C 0xed
#	define NV_MMU_PTE_KIND_C64_MS4_2CBA 0xef
#	define NV_MMU_PTE_KIND_C64_MS4_2CBR 0xee
#	define NV_MMU_PTE_KIND_C64_MS4_2CRA 0xf0
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C64_MS8 0x7d
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_C64_MS8_MS16_2C 0xf2
#	define NV_MMU_PTE_KIND_C64_MS8_MS16_2CRA 0xf3
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_GENERIC_16BX1 0x74
#	define NV_MMU_PTE_KIND_GENERIC_16BX1_BANKSWIZ 0x76
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_GENERIC_16BX2 0xfe
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_GENERIC_8BX2 0x70
#	define NV_MMU_PTE_KIND_GENERIC_8BX2_BANKSWIZ 0x72
#	define NV_MMU_PTE_KIND_INVALID 0x7f
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_INVALID 0xff
#endif
#if __nv_mmu_compat_2(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_PITCH 0x0
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_PITCH_NO_SWIZZLE 0xfd
#endif
#if __nv_mmu_compat_9(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8 0x2a
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24 0x11
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24 0x20
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_1Z 0x12
#	define NV_MMU_PTE_KIND_S8Z24_2CS 0x1c
#	define NV_MMU_PTE_KIND_S8Z24_2CZ 0x17
#	define NV_MMU_PTE_KIND_S8Z24_4CSZV 0x21
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_BANKSWIZ 0x28
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_MS16_1Z 0x16
#	define NV_MMU_PTE_KIND_S8Z24_MS16_2CS 0x20
#	define NV_MMU_PTE_KIND_S8Z24_MS16_2CZ 0x1b
#	define NV_MMU_PTE_KIND_S8Z24_MS16_4CSZV 0x25
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_MS2 0x21
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_MS2_1Z 0x13
#	define NV_MMU_PTE_KIND_S8Z24_MS2_2CS 0x1d
#	define NV_MMU_PTE_KIND_S8Z24_MS2_2CZ 0x18
#	define NV_MMU_PTE_KIND_S8Z24_MS2_4CSZV 0x22
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_MS2_BANKSWIZ 0x29
#	define NV_MMU_PTE_KIND_S8Z24_MS4 0x22
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_MS4_1Z 0x14
#	define NV_MMU_PTE_KIND_S8Z24_MS4_2CS 0x1e
#	define NV_MMU_PTE_KIND_S8Z24_MS4_2CZ 0x19
#	define NV_MMU_PTE_KIND_S8Z24_MS4_4CSZV 0x23
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_MS4_BANKSWIZ 0x2a
#	define NV_MMU_PTE_KIND_S8Z24_MS8 0x23
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_MS8_1Z 0x15
#	define NV_MMU_PTE_KIND_S8Z24_MS8_2CS 0x1f
#	define NV_MMU_PTE_KIND_S8Z24_MS8_2CZ 0x1a
#	define NV_MMU_PTE_KIND_S8Z24_MS8_4CSZV 0x24
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8Z24_MS8_BANKSWIZ 0x2b
#	define NV_MMU_PTE_KIND_S8ZF24 0x30
#	define NV_MMU_PTE_KIND_S8ZF24_BANKSWIZ 0x38
#	define NV_MMU_PTE_KIND_S8ZF24_MS2 0x31
#	define NV_MMU_PTE_KIND_S8ZF24_MS2_BANKSWIZ 0x39
#	define NV_MMU_PTE_KIND_S8ZF24_MS4 0x32
#	define NV_MMU_PTE_KIND_S8ZF24_MS4_BANKSWIZ 0x3a
#	define NV_MMU_PTE_KIND_S8ZF24_MS8 0x33
#	define NV_MMU_PTE_KIND_S8ZF24_MS8_BANKSWIZ 0x3b
#endif
#if __nv_mmu_compat_9(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_S8_2S 0x2b
#endif
#if __nv_mmu_compat_10(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_SMHOST_MESSAGE 0xcb
#	define NV_MMU_PTE_KIND_SMSKED_MESSAGE 0xca
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC12 0x25
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC12 0x26
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC12_1ZV 0x2e
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC12_2CS 0x32
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC12_2CZV 0x3a
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC12_2ZV 0x3e
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC12_4CSZV 0x42
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC12_BANKSWIZ 0x2d
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC4 0x24
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC4 0x27
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC4_1ZV 0x2f
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC4_2CS 0x33
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC4_2CZV 0x3b
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC4_2ZV 0x3f
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC4_4CSZV 0x43
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_V8Z24_MS4_VC4_BANKSWIZ 0x2c
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC24 0x29
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC24_1ZV 0x31
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC24_2CS 0x35
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC24_2CZV 0x3d
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC24_2ZV 0x41
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC24_4CSZV 0x45
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC8 0x26
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC8 0x28
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC8_1ZV 0x30
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC8_2CS 0x34
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC8_2CZV 0x3c
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC8_2ZV 0x40
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC8_4CSZV 0x44
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_V8Z24_MS8_VC8_BANKSWIZ 0x2e
#	define NV_MMU_PTE_KIND_V8ZF24_MS4_VC12 0x35
#	define NV_MMU_PTE_KIND_V8ZF24_MS4_VC12_BANKSWIZ 0x3d
#	define NV_MMU_PTE_KIND_V8ZF24_MS4_VC4 0x34
#	define NV_MMU_PTE_KIND_V8ZF24_MS4_VC4_BANKSWIZ 0x3c
#	define NV_MMU_PTE_KIND_V8ZF24_MS8_VC8 0x36
#	define NV_MMU_PTE_KIND_V8ZF24_MS8_VC8_BANKSWIZ 0x3e
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8C24 0x44
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8C24 0xfc
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8C24_BANKSWIZ 0x47
#	define NV_MMU_PTE_KIND_X8C24_MS4 0x45
#	define NV_MMU_PTE_KIND_X8C24_MS4_BANKSWIZ 0x4c
#	define NV_MMU_PTE_KIND_X8C24_MS8 0x46
#	define NV_MMU_PTE_KIND_X8C24_MS8_BANKSWIZ 0x4d
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC12 0x55
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC12 0x8b
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC12_1CS 0x8f
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC12_1CZV 0x9b
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC12_1ZV 0x97
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC12_2CS 0x9f
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC12_2CSZV 0xa3
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC4 0x54
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC4 0x8c
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC4_1CS 0x90
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC4_1CZV 0x9c
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC4_1ZV 0x98
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC4_2CS 0xa0
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS4_VC4_2CSZV 0xa4
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC24 0x8e
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC24_1CS 0x92
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC24_1CZV 0x9e
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC24_1ZV 0x9a
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC24_2CS 0xa2
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC24_2CSZV 0xa6
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC8 0x56
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC8 0x8d
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC8_1CS 0x91
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC8_1CZV 0x9d
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC8_1ZV 0x99
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC8_2CS 0xa1
#	define NV_MMU_PTE_KIND_X8Z24_X16V8S8_MS8_VC8_2CSZV 0xa5
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_X8ZF24_X16V8S8_MS4_VC12 0x5d
#	define NV_MMU_PTE_KIND_X8ZF24_X16V8S8_MS4_VC4 0x5c
#	define NV_MMU_PTE_KIND_X8ZF24_X16V8S8_MS8_VC8 0x5e
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16 0x1
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16 0x68
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_2C 0x2
#	define NV_MMU_PTE_KIND_Z16_2Z 0x7
#	define NV_MMU_PTE_KIND_Z16_4CZ 0xc
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_BANKSWIZ 0x6c
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_MS16_2C 0x6
#	define NV_MMU_PTE_KIND_Z16_MS16_2Z 0xb
#	define NV_MMU_PTE_KIND_Z16_MS16_4CZ 0x10
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_MS2 0x69
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_MS2_2C 0x3
#	define NV_MMU_PTE_KIND_Z16_MS2_2Z 0x8
#	define NV_MMU_PTE_KIND_Z16_MS2_4CZ 0xd
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_MS2_BANKSWIZ 0x6d
#	define NV_MMU_PTE_KIND_Z16_MS4 0x6a
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_MS4_2C 0x4
#	define NV_MMU_PTE_KIND_Z16_MS4_2Z 0x9
#	define NV_MMU_PTE_KIND_Z16_MS4_4CZ 0xe
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_MS4_BANKSWIZ 0x6e
#	define NV_MMU_PTE_KIND_Z16_MS8 0x6b
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_MS8_2C 0x5
#	define NV_MMU_PTE_KIND_Z16_MS8_2Z 0xa
#	define NV_MMU_PTE_KIND_Z16_MS8_4CZ 0xf
#endif
#if __nv_mmu_compat_4(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z16_MS8_BANKSWIZ 0x6f
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8 0x10
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8 0x46
#	define NV_MMU_PTE_KIND_Z24S8_1Z 0x47
#	define NV_MMU_PTE_KIND_Z24S8_2CS 0x4c
#	define NV_MMU_PTE_KIND_Z24S8_2CZ 0x51
#	define NV_MMU_PTE_KIND_Z24S8_4CSZV 0x56
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8_BANKSWIZ 0x18
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8_MS16_1Z 0x4b
#	define NV_MMU_PTE_KIND_Z24S8_MS16_2CS 0x50
#	define NV_MMU_PTE_KIND_Z24S8_MS16_2CZ 0x55
#	define NV_MMU_PTE_KIND_Z24S8_MS16_4CSZV 0x5a
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8_MS2 0x11
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8_MS2_1Z 0x48
#	define NV_MMU_PTE_KIND_Z24S8_MS2_2CS 0x4d
#	define NV_MMU_PTE_KIND_Z24S8_MS2_2CZ 0x52
#	define NV_MMU_PTE_KIND_Z24S8_MS2_4CSZV 0x57
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8_MS2_BANKSWIZ 0x19
#	define NV_MMU_PTE_KIND_Z24S8_MS4 0x12
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8_MS4_1Z 0x49
#	define NV_MMU_PTE_KIND_Z24S8_MS4_2CS 0x4e
#	define NV_MMU_PTE_KIND_Z24S8_MS4_2CZ 0x53
#	define NV_MMU_PTE_KIND_Z24S8_MS4_4CSZV 0x58
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8_MS4_BANKSWIZ 0x1a
#	define NV_MMU_PTE_KIND_Z24S8_MS8 0x13
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8_MS8_1Z 0x4a
#	define NV_MMU_PTE_KIND_Z24S8_MS8_2CS 0x4f
#	define NV_MMU_PTE_KIND_Z24S8_MS8_2CZ 0x54
#	define NV_MMU_PTE_KIND_Z24S8_MS8_4CSZV 0x59
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24S8_MS8_BANKSWIZ 0x1b
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC12 0x15
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC12 0x5b
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC12_1ZV 0x63
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC12_2CS 0x67
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC12_2CZV 0x6f
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC12_2ZV 0x73
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC12_4CSZV 0x77
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC12_BANKSWIZ 0x1d
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC4 0x14
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC4 0x5c
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC4_1ZV 0x64
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC4_2CS 0x68
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC4_2CZV 0x70
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC4_2ZV 0x74
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC4_4CSZV 0x78
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24V8_MS4_VC4_BANKSWIZ 0x1c
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC24 0x5e
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC24_1ZV 0x66
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC24_2CS 0x6a
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC24_2CZV 0x72
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC24_2ZV 0x76
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC24_4CSZV 0x7a
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC8 0x16
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC8 0x5d
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC8_1ZV 0x65
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC8_2CS 0x69
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC8_2CZV 0x71
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC8_2ZV 0x75
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC8_4CSZV 0x79
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_Z24V8_MS8_VC8_BANKSWIZ 0x1e
#	define NV_MMU_PTE_KIND_ZF32 0x40
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32 0x7b
#	define NV_MMU_PTE_KIND_ZF32_1Z 0x7c
#	define NV_MMU_PTE_KIND_ZF32_2CS 0x81
#	define NV_MMU_PTE_KIND_ZF32_2CZ 0x86
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_BANKSWIZ 0x48
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_MS16_1Z 0x80
#	define NV_MMU_PTE_KIND_ZF32_MS16_2CS 0x85
#	define NV_MMU_PTE_KIND_ZF32_MS16_2CZ 0x8a
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_MS2 0x41
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_MS2_1Z 0x7d
#	define NV_MMU_PTE_KIND_ZF32_MS2_2CS 0x82
#	define NV_MMU_PTE_KIND_ZF32_MS2_2CZ 0x87
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_MS2_BANKSWIZ 0x49
#	define NV_MMU_PTE_KIND_ZF32_MS4 0x42
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_MS4_1Z 0x7e
#	define NV_MMU_PTE_KIND_ZF32_MS4_2CS 0x83
#	define NV_MMU_PTE_KIND_ZF32_MS4_2CZ 0x88
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_MS4_BANKSWIZ 0x4a
#	define NV_MMU_PTE_KIND_ZF32_MS8 0x43
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_MS8_1Z 0x7f
#	define NV_MMU_PTE_KIND_ZF32_MS8_2CS 0x84
#	define NV_MMU_PTE_KIND_ZF32_MS8_2CZ 0x89
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_MS8_BANKSWIZ 0x4b
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC12 0x65
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC12 0xa7
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC12_1CS 0xab
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC12_1CZV 0xb7
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC12_1ZV 0xb3
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC12_2CS 0xbb
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC12_2CSZV 0xbf
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC4 0x64
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC4 0xa8
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC4_1CS 0xac
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC4_1CZV 0xb8
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC4_1ZV 0xb4
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC4_2CS 0xbc
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS4_VC4_2CSZV 0xc0
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC24 0xaa
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC24_1CS 0xae
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC24_1CZV 0xba
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC24_1ZV 0xb6
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC24_2CS 0xbe
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC24_2CSZV 0xc2
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC8 0x66
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC8 0xa9
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC8_1CS 0xad
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC8_1CZV 0xb9
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC8_1ZV 0xb5
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC8_2CS 0xbd
#	define NV_MMU_PTE_KIND_ZF32_X16V8S8_MS8_VC8_2CSZV 0xc1
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X24S8 0x60
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X24S8 0xc3
#	define NV_MMU_PTE_KIND_ZF32_X24S8_1CS 0xc4
#	define NV_MMU_PTE_KIND_ZF32_X24S8_2CS 0xd3
#	define NV_MMU_PTE_KIND_ZF32_X24S8_2CSZV 0xce
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS16_1CS 0xc8
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS16_2CS 0xd7
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS16_2CSZV 0xd2
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS2 0x61
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS2_1CS 0xc5
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS2_2CS 0xd4
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS2_2CSZV 0xcf
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS4 0x62
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS4_1CS 0xc6
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS4_2CS 0xd5
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS4_2CSZV 0xd0
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS8 0x63
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS8_1CS 0xc7
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS8_2CS 0xd6
#	define NV_MMU_PTE_KIND_ZF32_X24S8_MS8_2CSZV 0xd1
#endif
#if __nv_mmu_compat_7(__nv_chipset_target__)
#	define NV_MMU_PTE_LOCK (0*32+1):(0*32+1)
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_LOCK (1*32+3):(1*32+3)
#endif
#if __nv_mmu_compat_8(__nv_chipset_target__)
#	define NV_MMU_PTE_LOCK_FALSE 0x0
#	define NV_MMU_PTE_LOCK_TRUE 0x1
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_PART_STRIDE (1*32+29):(1*32+29)
#	define NV_MMU_PTE_PART_STRIDE_1024 0x1
#	define NV_MMU_PTE_PART_STRIDE_256 0x0
#	define NV_MMU_PTE_PEER (1*32+7):(1*32+6)
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_PRIVILEGE (0*32+1):(0*32+1)
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_PRIVILEGE (0*32+6):(0*32+6)
#endif
#if __nv_mmu_compat_2(__nv_chipset_target__)
#	define NV_MMU_PTE_PRIVILEGE_FALSE 0x0
#	define NV_MMU_PTE_PRIVILEGE_TRUE 0x1
#endif
#if __nv_mmu_compat_10(__nv_chipset_target__)
#	define NV_MMU_PTE_READ_DISABLE (1*32+30):(1*32+30)
#	define NV_MMU_PTE_READ_DISABLE_FALSE 0x0
#	define NV_MMU_PTE_READ_DISABLE_TRUE 0x1
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_READ_ONLY (0*32+2):(0*32+2)
#endif
#if __nv_mmu_compat_0(__nv_chipset_target__)
#	define NV_MMU_PTE_READ_ONLY (0*32+3):(0*32+3)
#endif
#if __nv_mmu_compat_2(__nv_chipset_target__)
#	define NV_MMU_PTE_READ_ONLY_FALSE 0x0
#	define NV_MMU_PTE_READ_ONLY_TRUE 0x1
#	define NV_MMU_PTE_VALID (0*32+0):(0*32+0)
#	define NV_MMU_PTE_VALID_FALSE 0x0
#	define NV_MMU_PTE_VALID_TRUE 0x1
#endif
#if __nv_mmu_compat_1(__nv_chipset_target__)
#	define NV_MMU_PTE_VOL (1*32+0):(1*32+0)
#	define NV_MMU_PTE_VOL_FALSE 0x0
#	define NV_MMU_PTE_VOL_TRUE 0x1
#endif
#if __nv_mmu_compat_10(__nv_chipset_target__)
#	define NV_MMU_PTE_WRITE_DISABLE (1*32+31):(1*32+31)
#	define NV_MMU_PTE_WRITE_DISABLE_FALSE 0x0
#	define NV_MMU_PTE_WRITE_DISABLE_TRUE 0x1
#endif
#if __nv_mmu_compat_2(__nv_chipset_target__)
#	define NV_MMU_PTE__SIZE 0x8
#endif

#endif /*__NV_MMU_HW_H__ */
