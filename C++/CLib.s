	.file	"CLib.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.align 4
	.type	_ZL10increament, @object
	.size	_ZL10increament, 4
_ZL10increament:
	.long	100
	.text
	.globl	_Z10initializeP9CStashTagi
	.type	_Z10initializeP9CStashTagi, @function
_Z10initializeP9CStashTagi:
.LFB1021:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	$0, 4(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rax
	movl	$0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1021:
	.size	_Z10initializeP9CStashTagi, .-_Z10initializeP9CStashTagi
	.globl	_Z3addP9CStashTagPKv
	.type	_Z3addP9CStashTagPKv, @function
_Z3addP9CStashTagPKv:
.LFB1022:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	8(%rax), %edx
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	%eax, %edx
	jne	.L3
	movq	-24(%rbp), %rax
	movl	$100, %esi
	movq	%rax, %rdi
	call	_Z7inflateP9CStashTagi
.L3:
	movq	-24(%rbp), %rax
	movl	8(%rax), %edx
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	movl	%eax, -12(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -16(%rbp)
.L5:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	-16(%rbp), %eax
	jle	.L4
	movq	-24(%rbp), %rax
	movq	16(%rax), %rdx
	movl	-12(%rbp), %ecx
	movl	-16(%rbp), %eax
	addl	%ecx, %eax
	cltq
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	movslq	%eax, %rcx
	movq	-8(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	addl	$1, -16(%rbp)
	jmp	.L5
.L4:
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 8(%rax)
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	subl	$1, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1022:
	.size	_Z3addP9CStashTagPKv, .-_Z3addP9CStashTagPKv
	.section	.rodata
.LC0:
	.string	"CLib.cpp"
.LC1:
	.string	"0 <= index"
	.text
	.globl	_Z5fetchP9CStashTagi
	.type	_Z5fetchP9CStashTagi, @function
_Z5fetchP9CStashTagi:
.LFB1023:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jns	.L8
	movl	$_ZZ5fetchP9CStashTagiE19__PRETTY_FUNCTION__, %ecx
	movl	$29, %edx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	__assert_fail
.L8:
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	-12(%rbp), %eax
	jg	.L9
	movl	$0, %eax
	jmp	.L10
.L9:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	imull	-12(%rbp), %eax
	cltq
	addq	%rdx, %rax
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1023:
	.size	_Z5fetchP9CStashTagi, .-_Z5fetchP9CStashTagi
	.globl	_Z5countP9CStashTag
	.type	_Z5countP9CStashTag, @function
_Z5countP9CStashTag:
.LFB1024:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1024:
	.size	_Z5countP9CStashTag, .-_Z5countP9CStashTag
	.section	.rodata
.LC2:
	.string	"increase > 0"
	.text
	.globl	_Z7inflateP9CStashTagi
	.type	_Z7inflateP9CStashTagi, @function
_Z7inflateP9CStashTagi:
.LFB1025:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	cmpl	$0, -44(%rbp)
	jg	.L14
	movl	$_ZZ7inflateP9CStashTagiE19__PRETTY_FUNCTION__, %ecx
	movl	$41, %edx
	movl	$.LC0, %esi
	movl	$.LC2, %edi
	call	__assert_fail
.L14:
	movq	-40(%rbp), %rax
	movl	4(%rax), %edx
	movl	-44(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	imull	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
	movq	-40(%rbp), %rax
	movl	4(%rax), %edx
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-16(%rbp), %eax
	cltq
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, -8(%rbp)
	movl	$0, -24(%rbp)
.L16:
	movl	-24(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	.L15
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rcx
	movl	-24(%rbp), %eax
	cltq
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	addl	$1, -24(%rbp)
	jmp	.L16
.L15:
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L17
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L17:
	movq	-40(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 16(%rax)
	movq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, 4(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1025:
	.size	_Z7inflateP9CStashTagi, .-_Z7inflateP9CStashTagi
	.section	.rodata
.LC3:
	.string	"freeing storage"
	.text
	.globl	_Z7cleanupP9CStashTag
	.type	_Z7cleanupP9CStashTag, @function
_Z7cleanupP9CStashTag:
.LFB1026:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L20
	movl	$.LC3, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L20
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L20:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1026:
	.size	_Z7cleanupP9CStashTag, .-_Z7cleanupP9CStashTag
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1035:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L23
	cmpl	$65535, -8(%rbp)
	jne	.L23
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L23:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1035:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z10initializeP9CStashTagi, @function
_GLOBAL__sub_I__Z10initializeP9CStashTagi:
.LFB1036:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1036:
	.size	_GLOBAL__sub_I__Z10initializeP9CStashTagi, .-_GLOBAL__sub_I__Z10initializeP9CStashTagi
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z10initializeP9CStashTagi
	.section	.rodata
	.align 16
	.type	_ZZ5fetchP9CStashTagiE19__PRETTY_FUNCTION__, @object
	.size	_ZZ5fetchP9CStashTagiE19__PRETTY_FUNCTION__, 26
_ZZ5fetchP9CStashTagiE19__PRETTY_FUNCTION__:
	.string	"void* fetch(CStash*, int)"
	.align 16
	.type	_ZZ7inflateP9CStashTagiE19__PRETTY_FUNCTION__, @object
	.size	_ZZ7inflateP9CStashTagiE19__PRETTY_FUNCTION__, 27
_ZZ7inflateP9CStashTagiE19__PRETTY_FUNCTION__:
	.string	"void inflate(CStash*, int)"
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
