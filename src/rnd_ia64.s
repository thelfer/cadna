	.file	"arit-ia64-mi.c"
	.pred.safe_across_calls p1-p5,p16-p63
	.text
	.align 16
	.global rnd_moinf#
	.proc rnd_moinf#
rnd_moinf:
	.prologue 2, 2
	.vframe r2
	mov r2 = r12
	.body
#APP
	mov.m r14=ar.fpsr
#NO_APP
	;;
	st8 [r2] = r14
	ld8 r15 = [r2]
	addl r14 = -3073, r0
	;;
	and r15 = r14, r15
	addl r14 = 2048, r0
	;;
	or r14 = r14, r15
	;;
	st8 [r2] = r14
	ld8 r14 = [r2]
	;;
#APP
	mov.m ar.fpsr=r14
#NO_APP
	.restore sp
	mov r12 = r2
	br.ret.sptk.many b0
	;;
	.endp rnd_moinf#
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
	.file	"arit-ia64-pi.c"
	.pred.safe_across_calls p1-p5,p16-p63
	.text
	.align 16
	.global rnd_plinf#
	.proc rnd_plinf#
rnd_plinf:
	.prologue 2, 2
	.vframe r2
	mov r2 = r12
	.body
#APP
	mov.m r14=ar.fpsr
#NO_APP
	;;
	st8 [r2] = r14
	ld8 r15 = [r2]
	addl r14 = -3073, r0
	;;
	and r15 = r14, r15
	addl r14 = 1024, r0
	;;
	or r14 = r14, r15
	;;
	st8 [r2] = r14
	ld8 r14 = [r2]
	;;
#APP
	mov.m ar.fpsr=r14
#NO_APP
	.restore sp
	mov r12 = r2
	br.ret.sptk.many b0
	;;
	.endp rnd_plinf#
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
	.file	"arit-ia64-rn.c"
	.pred.safe_across_calls p1-p5,p16-p63
	.text
	.align 16
	.global rnd_arr#
	.proc rnd_arr#
rnd_arr:
	.prologue 2, 2
	.vframe r2
	mov r2 = r12
	.body
#APP
	mov.m r14=ar.fpsr
#NO_APP
	;;
	st8 [r2] = r14
	ld8 r15 = [r2]
	addl r14 = -3073, r0
	;;
	and r14 = r14, r15
	;;
	st8 [r2] = r14
	ld8 r14 = [r2]
	;;
#APP
	mov.m ar.fpsr=r14
#NO_APP
	.restore sp
	mov r12 = r2
	br.ret.sptk.many b0
	;;
	.endp rnd_arr#
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
	.file	"arit-ia64-tz.c"
	.pred.safe_across_calls p1-p5,p16-p63
	.text
	.align 16
	.global rnd_switch#
	.proc rnd_switch#
rnd_switch:
	.prologue 2, 2
	.vframe r2
	mov r2 = r12
	.body
#APP
	mov.m r14=ar.fpsr
#NO_APP
	;;
	st8 [r2] = r14
	ld8 r15 = [r2]
	addl r14 = 3072, r0
	;;
	xor r14 = r14, r15
	;;
	st8 [r2] = r14
	ld8 r14 = [r2]
	;;
#APP
	mov.m ar.fpsr=r14
#NO_APP
	.restore sp
	mov r12 = r2
	br.ret.sptk.many b0
	;;
	.endp rnd_switch#
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
	.file	"arit-ia64-tz.c"
	.pred.safe_across_calls p1-p5,p16-p63
	.text
	.align 16
	.global rnd_zero#
	.proc rnd_zero#
rnd_zero:
	.prologue 2, 2
	.vframe r2
	mov r2 = r12
	.body
#APP
	mov.m r14=ar.fpsr
#NO_APP
	;;
	st8 [r2] = r14
	ld8 r15 = [r2]
	addl r14 = 3072, r0
	;;
	or r14 = r14, r15
	;;
	st8 [r2] = r14
	ld8 r14 = [r2]
	;;
#APP
	mov.m ar.fpsr=r14
#NO_APP
	.restore sp
	mov r12 = r2
	br.ret.sptk.many b0
	;;
	.endp rnd_zero#
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.3 20041212 (Red Hat 3.4.3-9.EL4)"
