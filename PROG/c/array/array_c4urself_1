	.cstring
	.align 3
LC1:
	.ascii "--- Value ---------     --- Addresses --------\12\0"
LC2:
	.ascii "twod_array[%d][%d] = %d\0"
LC3:
	.ascii "\11&twod_array[%d][%d] = %p\12\0"
LC4:
	.ascii ".\0"
LC5:
	.ascii "..\0"
LC6:
	.ascii "ch_array[%d] = %x %c\0"
LC7:
	.ascii "\11&ch_array[%d] = %p\12\0"
LC0:
	.ascii "ArrayT\0"
	.text
.globl _main
_main:
LFB3:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	subq	$64, %rsp
LCFI2:
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movl	$1, -48(%rbp)
	movl	$5, -44(%rbp)
	movl	$3, -40(%rbp)
	movl	$21, -32(%rbp)
	movl	$34, -28(%rbp)
	movl	$45, -24(%rbp)
	movl	$68, -20(%rbp)
	movl	LC0(%rip), %eax
	movl	%eax, -16(%rbp)
	movzwl	4+LC0(%rip), %eax
	movw	%ax, -12(%rbp)
	leaq	LC1(%rip), %rdi
	call	_puts
	movl	$0, -4(%rbp)
	jmp	L2
L3:
	movl	$0, -8(%rbp)
	jmp	L4
L5:
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	movslq	%eax,%rcx
	movslq	%edx,%rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	-48(%rbp,%rax,4), %ecx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %esi
	leaq	LC2(%rip), %rdi
	movl	$0, %eax
	call	_printf
	leaq	-48(%rbp), %rcx
	movl	-8(%rbp), %eax
	cltq
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	(%rdx,%rax), %rax
	salq	$2, %rax
	addq	%rax, %rcx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %esi
	leaq	LC3(%rip), %rdi
	movl	$0, %eax
	call	_printf
	incl	-8(%rbp)
L4:
	cmpl	$3, -8(%rbp)
	jle	L5
	leaq	LC4(%rip), %rdi
	call	_puts
	incl	-4(%rbp)
L2:
	cmpl	$1, -4(%rbp)
	jle	L3
	leaq	LC5(%rip), %rdi
	call	_puts
	movl	$0, -4(%rbp)
	jmp	L8
L9:
	movl	-4(%rbp), %eax
	cltq
	movzbl	-16(%rbp,%rax), %eax
	movsbl	%al,%ecx
	movl	-4(%rbp), %eax
	cltq
	movzbl	-16(%rbp,%rax), %eax
	movsbl	%al,%edx
	movl	-4(%rbp), %esi
	leaq	LC6(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	-4(%rbp), %eax
	cltq
	leaq	-16(%rbp), %rdx
	addq	%rax, %rdx
	movl	-4(%rbp), %esi
	leaq	LC7(%rip), %rdi
	movl	$0, %eax
	call	_printf
	incl	-4(%rbp)
L8:
	cmpl	$5, -4(%rbp)
	jle	L9
	leave
	ret
LFE3:
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
