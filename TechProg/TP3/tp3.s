	.file	"tp3.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Entrez 5 valeurs dans le tableau: "
.LC1:
	.string	"valeur n\302\260 %d: "
.LC2:
	.string	"%d"
	.text
	.globl	Exo2
	.type	Exo2, @function
Exo2:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$.LC0, %edi
	call	puts
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-36(%rbp), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -32(%rbp,%rax,4)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$4, -4(%rbp)
	jle	.L3
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	Exo2, .-Exo2
	.section	.rodata
.LC3:
	.string	"entrez les valeurs: "
.LC4:
	.string	"%d\342\210\227c "
.LC5:
	.string	"Resultat %d %d %d %d"
	.text
	.globl	Exo1
	.type	Exo1, @function
Exo1:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L5
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L7
.L5:
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L7
.L8:
	addl	$1, -4(%rbp)
	movl	-12(%rbp), %eax
	subl	%eax, -8(%rbp)
.L7:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	.L8
	movl	-20(%rbp), %edx
	movl	-16(%rbp), %eax
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %ecx
	movl	%esi, %r8d
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	Exo1, .-Exo1
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	call	Exo2
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Debian 5.4.0-6) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
