	.cstring
LC0:
	.ascii "Enter radius (i.e. 10): \0"
LC1:
	.ascii "%d\0"
LC3:
	.ascii "\12\12Area = %d\0"
	.text
.globl _main
_main:
LFB3:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	leaq	LC0(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movq	_radius@GOTPCREL(%rip), %rsi
	leaq	LC1(%rip), %rdi
	movl	$0, %eax
	call	_scanf
	movq	_radius@GOTPCREL(%rip), %rax
	movl	(%rax), %eax
	cvtsi2sd	%eax, %xmm1
	movsd	LC2(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movq	_radius@GOTPCREL(%rip), %rax
	movl	(%rax), %eax
	cvtsi2sd	%eax, %xmm0
	mulsd	%xmm1, %xmm0
	cvttsd2si	%xmm0, %edx
	movq	_area@GOTPCREL(%rip), %rax
	movl	%edx, (%rax)
	movq	_area@GOTPCREL(%rip), %rax
	movl	(%rax), %esi
	leaq	LC3(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$0, %eax
	leave
	ret
LFE3:
.comm _radius,4,2
.comm _area,4,2
	.literal8
	.align 3
LC2:
	.long	4028335726
	.long	1074340345
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
.globl _main.eh
_main.eh:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB3-.
	.set L$set$2,LFE3-LFB3
	.quad L$set$2
	.byte	0x0
	.byte	0x4
	.set L$set$3,LCFI0-LFB3
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
	.subsections_via_symbols
