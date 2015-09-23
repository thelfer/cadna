	.globl	.rnd_switch                    
	.globl	rnd_switch{DS}                 


# .text section


	.csect	    
.rnd_switch:                                   # 0x00000000 (H.10.NO_SYMBOL)
	stu	1,-64(1)
#	cal	3,0(0)
#	st	3,56(1)
        mffs 4
        stfd 4,50(1)
        l 3,54(1)
        xori 3,3,0x0001
        st 3,54(1)
        lfd 4,50(1)
        mtfsf 0xF,4
#        mtfsb0 30
#        mtfsb0 31
	ai	1,1,64
	bcr	20,0


	.globl	.rnd_arr                    
	.globl	rnd_arr{DS}                 


# .text section


	.csect	    
.rnd_arr:                                   # 0x00000000 (H.10.NO_SYMBOL)
	stu	1,-64(1)
#	cal	3,0(0)
#	st	3,56(1)
        mtfsb0 30
        mtfsb0 31
	ai	1,1,64
	bcr	20,0


	.globl	.rnd_moinf                    
	.globl	rnd_moinf{DS}                 


# .text section


	.csect	    
.rnd_moinf:                                   # 0x00000000 (H.10.NO_SYMBOL)
	stu	1,-64(1)
#	cal	3,0(0)
#	st	3,56(1)
        mtfsb1 30
        mtfsb1 31
	ai	1,1,64
	bcr	20,0

	.globl	.rnd_plinf                    
	.globl	rnd_plinf{DS}                 


# .text section


	.csect	    
.rnd_plinf:                                   # 0x00000000 (H.10.NO_SYMBOL)
	stu	1,-64(1)
#	cal	3,0(0)
#	st	3,56(1)
        mtfsb1 30
        mtfsb0 31
	ai	1,1,64
	bcr	20,0

	.globl	.rnd_zero                    
	.globl	rnd_zero{DS}                 


# .text section


	.csect	    
.rnd_zero:                                   # 0x00000000 (H.10.NO_SYMBOL)
	stu	1,-64(1)
#	cal	3,0(0)
#	st	3,56(1)
        mtfsb0 30
        mtfsb1 31
	ai	1,1,64
	bcr	20,0

