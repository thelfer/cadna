	.text
.globl _rnd_arr_
_rnd_arr_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	fnstcw -10(%ebp);
	movzwl	-10(%ebp), %eax
	andb	$243, %ah
	movw	%ax, -10(%ebp)
	movzwl	-10(%ebp), %eax
	movw	%ax, -10(%ebp)
	fldcw -10(%ebp);
	stmxcsr -16(%ebp)
	movl	-16(%ebp), %eax
	andb	$159, %ah
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -16(%ebp)
	ldmxcsr -16(%ebp)
	leave
	ret
.globl _rnd_zero_
_rnd_zero_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	fnstcw -10(%ebp);
	movzwl	-10(%ebp), %eax
	andb	$243, %ah
	movw	%ax, -10(%ebp)
	movzwl	-10(%ebp), %eax
	orb	$12, %ah
	movw	%ax, -10(%ebp)
	fldcw -10(%ebp);
	stmxcsr -16(%ebp)
	movl	-16(%ebp), %eax
	andb	$159, %ah
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	orb	$96, %ah
	movl	%eax, -16(%ebp)
	ldmxcsr -16(%ebp)
	leave
	ret
.globl _rnd_plinf_
_rnd_plinf_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	fnstcw -10(%ebp);
	movzwl	-10(%ebp), %eax
	andb	$243, %ah
	movw	%ax, -10(%ebp)
	movzwl	-10(%ebp), %eax
	orb	$8, %ah
	movw	%ax, -10(%ebp)
	fldcw -10(%ebp);
	stmxcsr -16(%ebp)
	movl	-16(%ebp), %eax
	andb	$159, %ah
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	orb	$64, %ah
	movl	%eax, -16(%ebp)
	ldmxcsr -16(%ebp)
	leave
	ret
.globl _rnd_moinf_
_rnd_moinf_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	fnstcw -10(%ebp);
	movzwl	-10(%ebp), %eax
	andb	$243, %ah
	movw	%ax, -10(%ebp)
	movzwl	-10(%ebp), %eax
	orb	$4, %ah
	movw	%ax, -10(%ebp)
	fldcw -10(%ebp);
	stmxcsr -16(%ebp)
	movl	-16(%ebp), %eax
	andb	$159, %ah
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	orb	$32, %ah
	movl	%eax, -16(%ebp)
	ldmxcsr -16(%ebp)
	leave
	ret
.globl _rnd_switch_
_rnd_switch_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	fnstcw -14(%ebp);
	movzwl	-14(%ebp), %eax
	andw	$1024, %ax
	movw	%ax, -12(%ebp)
	movzwl	-12(%ebp), %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movzwl	-12(%ebp), %eax
	notl	%eax
	andw	$1024, %ax
	orl	%edx, %eax
	movw	%ax, -10(%ebp)
	movzwl	-14(%ebp), %eax
	andb	$243, %ah
	movw	%ax, -14(%ebp)
	movzwl	-14(%ebp), %eax
	orw	-10(%ebp), %ax
	movw	%ax, -14(%ebp)
	fldcw -14(%ebp);
	stmxcsr -20(%ebp)
	movl	-20(%ebp), %eax
	andb	$159, %ah
	movl	%eax, -20(%ebp)
	movzwl	-10(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-20(%ebp), %eax
	orl	%edx, %eax
	movl	%eax, -20(%ebp)
	ldmxcsr -20(%ebp)
	leave
	ret
