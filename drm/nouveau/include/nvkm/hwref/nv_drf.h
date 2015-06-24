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

#ifndef __nv_drf_h__
#define __nv_drf_h__
/*
 * For registers, consider a hierarchical naming scheme:
 *
 *    "D" -> device/engine
 *    "R" -> register within the device
 *    "F" -> field hi:lo bits within the register
 *
 * Memory objects can be treated similarly:
 *
 *    "D" -> data/struct
 *    "W" -> offset within
 *    "F" -> field hi:lo bits within a word
 *
 * To construct names assume the following naming pattern:
 *
 *    NV_<D>              : a range of addresses/offsets
 *    NV_<D>_<R>          : a specific register offset
 *    NV_<D>_<R>_<F>      : a range of bits
 *    NV_<D>_<R>_<F>_<V>  : a specific value for use in a field
 *
 * E.g.:
 *
 *    #define NV_PGRAPH                   0x0040FFFF:0x00400000
 *    #define NV_PGRAPH_STATUS            0x400700
 *    #define NV_PGRAPH_STATUS_STATE      0:0
 *    #define NV_PGRAPH_STATUS_STATE_BUSY 1
 *
 * To refer to a specific register, say, create a macro to take the
 * D and R as parameters and construct the appropriate name:
 *
 *    #define NV_DRF_REG(D,R)           NV_ ## D ## _ ## R
 *
 * For fields, append "F" and for specific field enumerants, the "F" and
 * a "V":
 *    #define NV_DRF_FIELD(D,R,F)       NV_ ## D ## _ ## R ## _ ## F
 *    #define NV_DRF_FIELD_VAL(D,R,F,V) NV_ ## D ## _ ## R ## _ ## F ## _ ## V
 *
 * To refer to the high part of a range (here, a bit field) use the a
 * conditional ternary as follows: ( <0|1> ? <hi> : <lo> )
 *
 *    #define NV_DRF_FIELD_HI(D,R,F) ( 1 ? NV_DRF_FIELD(D,R,F) )
 *    #define NV_DRF_FIELD_LO(D,R,F) ( 0 ? NV_DRF_FIELD(D,R,F) )
 *
 * To illustrate:
 *
 *    #define NV_PGRAPH_FOO_BAR 2:1
 *    NV_DRF_FIELD_HI(PGRAPH,FOO,BAR) -> ( 1 ? 2:1 ) -> 2
 *    NV_DRF_FIELD_LO(PGRAPH,FOO,BAR) -> ( 0 ? 2:1 ) -> 1
 *
 * From these we can create various macros for managing the bits within fields;
 * placing field values, extracting them, masking them, etc.
 *
 * A specific field's value can be thought of in two ways:
 *    . "in-place"
 *    . or as a "value" shifted to the bit-0 position.
 *
 * The latter is suitable for math ops, etc.  The first is suitable for
 * "oring" with other fields within the register.  
 *
 * We say "get field" to name the operation which extracts and shifts the
 * appropriate bits to bit zero.  We say "set field" to name the operation
 * which takes a value, masks it and then shifts it to the field's position.
 *
 * Field enumerants are treated as a special case of "set" which appends a
 * "V" position to the token pasting.  Illustrated (see below for drf_* macro
 * definitions):
 *
 *    #define D 0x100:0x0   // the example "device" 
 *    #define D_R 0x20      // a "register" 
 *    #define D_R_F 5:1     // a "field"
 *    #define D_R_F_FOO 0   // a field value
 *    #define D_R_F_BAR 1   //      ""
 *    #define D_R_F_BAZ 9   //      ""
 *
 *    expanding drf_setv(D, R, F, BAZ) we get:
 *
 *     drf_set(D,R,F, D_R_F_BAZ)                                           ->
 *     drf_set(D,R,F, 9)                                                   ->
 *    (9 & drf_mask(D, R, F))                          << drf_shift(D,R,F) ->
 *    (9 & (~0 >> 31-drf_width(D, R, F)))              << drf_lo(D,R,F)    ->
 *    (9 & (~0 >> 31-(1+drf_hi(D,R,F)-drf_lo(D,R,F)))) << drf_lo(D,R,F)    ->
 *    (9 & (~0 >> 31-(1+(1?D_R_F) - (0?D_R_F))))       << (0?D_R_F)        ->
 *    (9 & (~0 >> 31-(1+(1?5:1)   - (0?5:1))))         << (0?5:1)          ->
 *    (9 & (~0 >> 31-(1+    (5)   - (1))))             << (1)              ->
 *    (9 & (~0 >> 31-(1+5-1)))                         << (1)              ->
 *    (9 & (0xffffffff >> (31-5)))                     <<  1               ->
 *    (9 & (0xffffffff >> 26))                         <<  1               ->
 *    (9 & 0x1f)                                       <<  1               ->
 *     9                                               <<  1               ->
 *     0x12
 *
 * Note that the above collapses neatly at compile time.  That's a feature.
 *
 * An important thing to note is that values "in-place" are suitable for bit-wise
 * oring (|) to accumulate multiple fields for use in the same register.  To extend
 * the previous example:
 *    #define D_R_FTOO  6:6  // a second 1-bit wide "field"
 *    #define D_R_FTOO_ENABLED  1
 *    #define D_R_FTOO_DISABLED 0
 *
 * The following would be correct usage to form a new register value for
 * the example register "D_R":
 *     drf_setv(D,R, F, BAZ) | drf_setv(D,R, FTOO, ENABLED)
 *
 * The following illustrates the reverse, inspecting values on a per-field
 * basis:
 *     u32 d_r = read_reg(drf_r(D, R));
 *
 *     if ( drf_get(D, R, FTOO, d_r) == drf_v(D, R, FTOO, ENABLED) ) {
 *         cout << "the FTOO value of register d_r is _ENABLED";
 *     }
 *
 */

#define drf_lo(D,R,F)       (0 ? NV_##D##_##R##_##F)
#define drf_hi(D,R,F)       (1 ? NV_##D##_##R##_##F)
#define drf_width(D,R,F)    (1 + f_hi(D,R,F) - f_lo(D,R,F))
#define drf_shift(D,R,F)    f_lo(D,R,F)
#define drf_mask(D,R,F)     ( (~((u32)0)) >> (31-(f_width(D,R,F))) )
#define drf_get(D,R,F,g)    ( ((g) >> f_shift(D,R,F)) & f_mask(D,R,F) )
#define drf_set(D,R,F,s)    ( ((s) & f_mask(D,R,F)) << f_shift(D,R,F) )
#define drf_v(D,R,F,V)      (D ##_## R ##_## F ##_## V)
#define drf_setv(D,R,F,V)   f_set(D,R,F, drf_v(D,R,F,V))
#define drf_r(D,R)          (D ##_## R)


/*
 * When multi-word memory structures are being referenced it is
 * common for the bit #s to be offsets from the begining of the
 * structure.  So, they can be >32 and we must account for which
 * word and intra-word offset is appropriate (div 32, mod 32) in
 * u32 space.
 */
#define drf_hi_w32(D,R,F)  (f_hi(D,R,F) / 32)
#define drf_hi_b32(D,R,F)  (f_hi(D,R,F) % 32)
#define drf_lo_w32(D,R,F)  (f_lo(D,R,F) / 32)
#define drf_lo_b32(D,R,F)  (f_lo(D,R,F) % 32)


#endif /* __nv_drf_h__ */
