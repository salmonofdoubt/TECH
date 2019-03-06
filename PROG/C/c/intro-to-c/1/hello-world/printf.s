	.file	"printf.c"
	.section	.rodata
.LC0:
	.string	"Hello "
	.string	"World!"
.LC1:
	.string	"0x%x\n"
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	$.LC0, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movq	-8(%rbp), %rax
	addq	$7, %rax
	movq	%rax, %rdi
	call	puts
	movl	$.LC1, %eax
	movl	$255, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
