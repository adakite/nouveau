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
#ifndef __nv_fb_hwref_h__
#define __nv_fb_hwref_h__

#define __nv_fb_compat_0(c) \
	((c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_fb_compat_1(c) \
	((c==__nv_gf100__) || (c==__nv_gf104__) || (c==__nv_gf106__) || (c==__nv_gf108__) || (c==__nv_gf110__) || (c==__nv_gf117__) || (c==__nv_gf119__) || (c==__nv_gk104__) || (c==__nv_gk106__) || (c==__nv_gk107__) || (c==__nv_gk110__) || (c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_fb_compat_2(c) \
	((c==__nv_gk20a__) || (c==__nv_gm204__) || (c==__nv_gm20b__))
#define __nv_fb_compat_3(c) \
	((c==__nv_gk208__) || (c==__nv_gk20a__) || (c==__nv_gm107__) || (c==__nv_gm204__) || (c==__nv_gm20b__))

#ifndef __nv_chipset_target__
#error "__nv_chipset_target__ not defined"
#endif


#if __nv_fb_compat_0(__nv_chipset_target__)
#	define NV_PFB_FBHUB_NUM_ACTIVE_LTCS 0x100800
#	define NV_PFB_PRI_MMU_CTRL_USE_PDB_BIG_PAGE_SIZE 11:11
#	define NV_PFB_PRI_MMU_WPR_INFO 0x100cd4
#	define NV_PFB_PRI_MMU_WPR_INFO_INDEX 3:0
#	define NV_PFB_PRI_MMU_WPR_INFO_INDEX_ALLOW_READ 0
#	define NV_PFB_PRI_MMU_WPR_INFO_INDEX_ALLOW_WRITE 1
#	define NV_PFB_PRI_MMU_WPR_INFO_INDEX_WPR1_ADDR_LO 2
#	define NV_PFB_PRI_MMU_WPR_INFO_INDEX_WPR1_ADDR_HI 3
#	define NV_PFB_PRI_MMU_WPR_INFO_INDEX_WPR2_ADDR_LO 4
#	define NV_PFB_PRI_MMU_WPR_INFO_INDEX_WPR2_ADDR_HI 5
#	define NV_PFB_PRI_MMU_PHYS_SECURE 0x100ce4
#endif
#if __nv_fb_compat_1(__nv_chipset_target__)
#	define NV_PFB_PRI_MMU_CTRL 0x100c80
#	define NV_PFB_PRI_MMU_CTRL_VM_PG_SIZE 0:0
#	define NV_PFB_PRI_MMU_CTRL_VM_PG_SIZE_128KB 0
#	define NV_PFB_PRI_MMU_CTRL_VM_PG_SIZE_64KB 1
#	define NV_PFB_PRI_MMU_CTRL_PRI_FIFO_EMPTY 15:15
#	define NV_PFB_PRI_MMU_CTRL_PRI_FIFO_SPACE 23:16
#	define NV_PFB_PRI_MMU_INVALIDATE_PDB 0x100cb8
#	define NV_PFB_PRI_MMU_INVALIDATE_PDB_APERTURE 1:1
#	define NV_PFB_PRI_MMU_INVALIDATE_PDB_APERTURE_VID_MEM 0
#	define NV_PFB_PRI_MMU_INVALIDATE_PDB_ADDR 31:4
#	define NV_PFB_PRI_MMU_INVALIDATE 0x100cbc
#	define NV_PFB_PRI_MMU_INVALIDATE_ALL_VA 0:0
#	define NV_PFB_PRI_MMU_INVALIDATE_ALL_PDB 1:1
#	define NV_PFB_PRI_MMU_INVALIDATE_TRIGGER 31:31
#endif
#if __nv_fb_compat_2(__nv_chipset_target__)
#	define NV_PFB_PRI_MMU_DEBUG_CTRL 0x100cc4
#	define NV_PFB_PRI_MMU_DEBUG_CTRL_DEBUG 16:16
#	define NV_PFB_PRI_MMU_DEBUG_WR 0x100cc8
#	define NV_PFB_PRI_MMU_DEBUG_WR_APERTURE 1:0
#	define NV_PFB_PRI_MMU_DEBUG_WR_APERTURE_VID_MEM 0
#	define NV_PFB_PRI_MMU_DEBUG_WR_VOL 2:2
#	define NV_PFB_PRI_MMU_DEBUG_WR_ADDR 31:4
#	define NV_PFB_PRI_MMU_DEBUG_WR_ADDR_ALIGNMENT 12
#	define NV_PFB_PRI_MMU_DEBUG_RD 0x100ccc
#	define NV_PFB_PRI_MMU_DEBUG_RD_APERTURE 1:0
#	define NV_PFB_PRI_MMU_DEBUG_RD_APERTURE_VID_MEM 0
#	define NV_PFB_PRI_MMU_DEBUG_RD_VOL 2:2
#	define NV_PFB_PRI_MMU_DEBUG_RD_ADDR 31:4
#	define NV_PFB_PRI_MMU_DEBUG_RD_ADDR_ALIGNMENT 12
#endif
#if __nv_fb_compat_3(__nv_chipset_target__)
#	define NV_PFB_PRI_MMU_VPR_INFO 0x100cd0
#	define NV_PFB_PRI_MMU_VPR_INFO_INDEX 1:0
#	define NV_PFB_PRI_MMU_VPR_INFO_INDEX_ADDR_LO 0
#	define NV_PFB_PRI_MMU_VPR_INFO_INDEX_ADDR_HI 1
#	define NV_PFB_PRI_MMU_VPR_INFO_INDEX_CYA_LO 2
#	define NV_PFB_PRI_MMU_VPR_INFO_INDEX_CYA_HI 3
#	define NV_PFB_PRI_MMU_VPR_INFO_FETCH 2:2
#endif
#endif /* __nv_fb_hwref_h__ */
