	.text
.globl _rnd_arr
_rnd_arr:
LFB6:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	fnstcw -2(%rbp);
	movzwl	-2(%rbp), %eax
	andb	$243, %ah
	movw	%ax, -2(%rbp)
	movzwl	-2(%rbp), %eax
	movw	%ax, -2(%rbp)
	fldcw -2(%rbp);
	stmxcsr -8(%rbp)
	movl	-8(%rbp), %eax
	andb	$159, %ah
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -8(%rbp)
	ldmxcsr -8(%rbp)
	leave
	ret
LFE6:
.globl _rnd_zero
_rnd_zero:
LFB7:
	pushq	%rbp
LCFI2:
	movq	%rsp, %rbp
LCFI3:
	fnstcw -2(%rbp);
	movzwl	-2(%rbp), %eax
	andb	$243, %ah
	movw	%ax, -2(%rbp)
	movzwl	-2(%rbp), %eax
	orb	$12, %ah
	movw	%ax, -2(%rbp)
	fldcw -2(%rbp);
	stmxcsr -8(%rbp)
	movl	-8(%rbp), %eax
	andb	$159, %ah
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	orb	$96, %ah
	movl	%eax, -8(%rbp)
	ldmxcsr -8(%rbp)
	leave
	ret
LFE7:
.globl _rnd_plinf
_rnd_plinf:
LFB8:
	pushq	%rbp
LCFI4:
	movq	%rsp, %rbp
LCFI5:
	fnstcw -2(%rbp);
	movzwl	-2(%rbp), %eax
	andb	$243, %ah
	movw	%ax, -2(%rbp)
	movzwl	-2(%rbp), %eax
	orb	$8, %ah
	movw	%ax, -2(%rbp)
	fldcw -2(%rbp);
	stmxcsr -8(%rbp)
	movl	-8(%rbp), %eax
	andb	$159, %ah
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	orb	$64, %ah
	movl	%eax, -8(%rbp)
	ldmxcsr -8(%rbp)
	leave
	ret
LFE8:
.globl _rnd_moinf
_rnd_moinf:
LFB9:
	pushq	%rbp
LCFI6:
	movq	%rsp, %rbp
LCFI7:
	fnstcw -2(%rbp);
	movzwl	-2(%rbp), %eax
	andb	$243, %ah
	movw	%ax, -2(%rbp)
	movzwl	-2(%rbp), %eax
	orb	$4, %ah
	movw	%ax, -2(%rbp)
	fldcw -2(%rbp);
	stmxcsr -8(%rbp)
	movl	-8(%rbp), %eax
	andb	$159, %ah
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	orb	$32, %ah
	movl	%eax, -8(%rbp)
	ldmxcsr -8(%rbp)
	leave
	ret
LFE9:
.globl _rnd_switch
_rnd_switch:
LFB10:
	pushq	%rbp
LCFI8:
	movq	%rsp, %rbp
LCFI9:
	fnstcw -2(%rbp);
	movzwl	-2(%rbp), %eax
	andw	$1024, %ax
	movw	%ax, -4(%rbp)
	movzwl	-4(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movzwl	-4(%rbp), %eax
	notl	%eax
	andw	$1024, %ax
	orl	%edx, %eax
	movw	%ax, -6(%rbp)
	movzwl	-2(%rbp), %eax
	andb	$243, %ah
	movw	%ax, -2(%rbp)
	movzwl	-2(%rbp), %eax
	orw	-6(%rbp), %ax
	movw	%ax, -2(%rbp)
	fldcw -2(%rbp);
	stmxcsr -12(%rbp)
	movl	-12(%rbp), %eax
	andb	$159, %ah
	movl	%eax, -12(%rbp)
	movzwl	-6(%rbp), %eax
	leal	0(,%rax,8), %edx
	movl	-12(%rbp), %eax
	orl	%edx, %eax
	movl	%eax, -12(%rbp)
	ldmxcsr -12(%rbp)
	leave
	ret
LFE10:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0x0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
.globl _rnd_arr.eh
_rnd_arr.eh:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB6-.
	.set L$set$2,LFE6-LFB6
	.quad L$set$2
	.byte	0x0
	.byte	0x4
	.set L$set$3,LCFI0-LFB6
	.long L$set$3
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE1:
.globl _rnd_zero.eh
_rnd_zero.eh:
LSFDE3:
	.set L$set$5,LEFDE3-LASFDE3
	.long L$set$5
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB7-.
	.set L$set$6,LFE7-LFB7
	.quad L$set$6
	.byte	0x0
	.byte	0x4
	.set L$set$7,LCFI2-LFB7
	.long L$set$7
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$8,LCFI3-LCFI2
	.long L$set$8
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE3:
.globl _rnd_plinf.eh
_rnd_plinf.eh:
LSFDE5:
	.set L$set$9,LEFDE5-LASFDE5
	.long L$set$9
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB8-.
	.set L$set$10,LFE8-LFB8
	.quad L$set$10
	.byte	0x0
	.byte	0x4
	.set L$set$11,LCFI4-LFB8
	.long L$set$11
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$12,LCFI5-LCFI4
	.long L$set$12
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE5:
.globl _rnd_moinf.eh
_rnd_moinf.eh:
LSFDE7:
	.set L$set$13,LEFDE7-LASFDE7
	.long L$set$13
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB9-.
	.set L$set$14,LFE9-LFB9
	.quad L$set$14
	.byte	0x0
	.byte	0x4
	.set L$set$15,LCFI6-LFB9
	.long L$set$15
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$16,LCFI7-LCFI6
	.long L$set$16
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE7:
.globl _rnd_switch.eh
_rnd_switch.eh:
LSFDE9:
	.set L$set$17,LEFDE9-LASFDE9
	.long L$set$17
LASFDE9:
	.long	LASFDE9-EH_frame1
	.quad	LFB10-.
	.set L$set$18,LFE10-LFB10
	.quad L$set$18
	.byte	0x0
	.byte	0x4
	.set L$set$19,LCFI8-LFB10
	.long L$set$19
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$20,LCFI9-LCFI8
	.long L$set$20
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE9:
	.subsections_via_symbols
