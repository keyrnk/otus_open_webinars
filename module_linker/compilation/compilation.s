	.arch armv8-a
	.text
	.zerofill __DATA,__bss,__ZStL8__ioinit,1,0
	.text
	.align	2
	.globl __Z13some_functioni
__Z13some_functioni:
LFB1810:
	sub	sp, sp, #16
LCFI0:
	str	w0, [sp, 12]
	nop
	add	sp, sp, 16
LCFI1:
	ret
LFE1810:
	.align	2
	.globl __Z19some_other_functionf
__Z19some_other_functionf:
LFB1811:
	sub	sp, sp, #16
LCFI2:
	str	s0, [sp, 12]
	nop
	add	sp, sp, 16
LCFI3:
	ret
LFE1811:
	.cstring
	.align	3
lC0:
	.ascii "Hey!\0"
	.text
	.align	2
	.globl _main
_main:
LFB1812:
	stp	x29, x30, [sp, -16]!
LCFI4:
	mov	x29, sp
	mov	w0, 41
	bl	__Z13some_functioni
	mov	w0, 1107820544
	fmov	s0, w0
	bl	__Z19some_other_functionf
	adrp	x0, lC0@PAGE
	add	x1, x0, lC0@PAGEOFF;momd
	adrp	x0, __ZSt4cout@GOTPAGE
	ldr	x0, [x0, __ZSt4cout@GOTPAGEOFF]
	bl	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	adrp	x1, __ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPAGE
	ldr	x1, [x1, __ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPAGEOFF]
	bl	__ZNSolsEPFRSoS_E
	mov	w1, 10
	adrp	x0, __ZSt4cout@GOTPAGE
	ldr	x0, [x0, __ZSt4cout@GOTPAGEOFF]
	bl	__ZNSolsEi
	mov	w0, 0
	ldp	x29, x30, [sp], 16
LCFI5:
	ret
LFE1812:
	.align	2
__Z41__static_initialization_and_destruction_0ii:
LFB2344:
	stp	x29, x30, [sp, -32]!
LCFI6:
	mov	x29, sp
	str	w0, [sp, 28]
	str	w1, [sp, 24]
	ldr	w0, [sp, 28]
	cmp	w0, 1
	bne	L7
	ldr	w1, [sp, 24]
	mov	w0, 65535
	cmp	w1, w0
	bne	L7
	adrp	x0, __ZStL8__ioinit@PAGE
	add	x0, x0, __ZStL8__ioinit@PAGEOFF;momd
	bl	__ZNSt8ios_base4InitC1Ev
	adrp	x0, ___dso_handle@PAGE
	add	x2, x0, ___dso_handle@PAGEOFF;momd
	adrp	x0, __ZStL8__ioinit@PAGE
	add	x1, x0, __ZStL8__ioinit@PAGEOFF;momd
	adrp	x0, __ZNSt8ios_base4InitD1Ev@GOTPAGE
	ldr	x0, [x0, __ZNSt8ios_base4InitD1Ev@GOTPAGEOFF]
	bl	___cxa_atexit
L7:
	nop
	ldp	x29, x30, [sp], 32
LCFI7:
	ret
LFE2344:
	.align	2
__GLOBAL__sub_I_compilation.cpp:
LFB2345:
	stp	x29, x30, [sp, -16]!
LCFI8:
	mov	x29, sp
	mov	w1, 65535
	mov	w0, 1
	bl	__Z41__static_initialization_and_destruction_0ii
	ldp	x29, x30, [sp], 16
LCFI9:
	ret
LFE2345:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB1810-.
	.set L$set$2,LFE1810-LFB1810
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB1810
	.long L$set$3
	.byte	0xe
	.uleb128 0x10
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE1:
LSFDE3:
	.set L$set$5,LEFDE3-LASFDE3
	.long L$set$5
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB1811-.
	.set L$set$6,LFE1811-LFB1811
	.quad L$set$6
	.uleb128 0
	.byte	0x4
	.set L$set$7,LCFI2-LFB1811
	.long L$set$7
	.byte	0xe
	.uleb128 0x10
	.byte	0x4
	.set L$set$8,LCFI3-LCFI2
	.long L$set$8
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE3:
LSFDE5:
	.set L$set$9,LEFDE5-LASFDE5
	.long L$set$9
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB1812-.
	.set L$set$10,LFE1812-LFB1812
	.quad L$set$10
	.uleb128 0
	.byte	0x4
	.set L$set$11,LCFI4-LFB1812
	.long L$set$11
	.byte	0xe
	.uleb128 0x10
	.byte	0x9d
	.uleb128 0x2
	.byte	0x9e
	.uleb128 0x1
	.byte	0x4
	.set L$set$12,LCFI5-LCFI4
	.long L$set$12
	.byte	0xde
	.byte	0xdd
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE5:
LSFDE7:
	.set L$set$13,LEFDE7-LASFDE7
	.long L$set$13
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB2344-.
	.set L$set$14,LFE2344-LFB2344
	.quad L$set$14
	.uleb128 0
	.byte	0x4
	.set L$set$15,LCFI6-LFB2344
	.long L$set$15
	.byte	0xe
	.uleb128 0x20
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
	.byte	0x4
	.set L$set$16,LCFI7-LCFI6
	.long L$set$16
	.byte	0xde
	.byte	0xdd
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE7:
LSFDE9:
	.set L$set$17,LEFDE9-LASFDE9
	.long L$set$17
LASFDE9:
	.long	LASFDE9-EH_frame1
	.quad	LFB2345-.
	.set L$set$18,LFE2345-LFB2345
	.quad L$set$18
	.uleb128 0
	.byte	0x4
	.set L$set$19,LCFI8-LFB2345
	.long L$set$19
	.byte	0xe
	.uleb128 0x10
	.byte	0x9d
	.uleb128 0x2
	.byte	0x9e
	.uleb128 0x1
	.byte	0x4
	.set L$set$20,LCFI9-LCFI8
	.long L$set$20
	.byte	0xde
	.byte	0xdd
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE9:
	.private_extern ___dso_handle
	.ident	"GCC: (Homebrew GCC 12.2.0) 12.2.0"
	.mod_init_func
_Mod.init:
	.align	3
	.xword	__GLOBAL__sub_I_compilation.cpp
	.subsections_via_symbols
