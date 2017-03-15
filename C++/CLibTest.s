	.file	"CLibTest.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"fetch(&intStash, "
.LC1:
	.string	") = "
.LC2:
	.string	"CLibTest.cpp"
.LC3:
	.string	"in"
.LC4:
	.string	"fetch(&stringStash, "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1085:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1085
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$640, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1Ev
.LEHE0:
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
.LEHB1:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
.LEHE1:
	movl	$80, -652(%rbp)
	movl	$4, %edx
	leaq	-640(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
.LEHB2:
	call	_Z10initializeP9CStashTagi
	movl	$0, -656(%rbp)
.L3:
	movl	-656(%rbp), %eax
	cmpl	$99, %eax
	jg	.L2
	leaq	-656(%rbp), %rdx
	leaq	-640(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z3addP9CStashTagPKv
	movl	-656(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -656(%rbp)
	jmp	.L3
.L2:
	movl	$0, -656(%rbp)
.L5:
	leaq	-640(%rbp), %rax
	movq	%rax, %rdi
	call	_Z5countP9CStashTag
	movl	%eax, %edx
	movl	-656(%rbp), %eax
	cmpl	%eax, %edx
	setg	%al
	testb	%al, %al
	je	.L4
	movl	-656(%rbp), %edx
	leaq	-640(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_Z5fetchP9CStashTagi
	movl	(%rax), %ebx
	movl	-656(%rbp), %r12d
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	-656(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -656(%rbp)
	jmp	.L5
.L4:
	movl	$1, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$4, %eax
	movl	%eax, %edx
	leaq	-608(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_Z10initializeP9CStashTagi
	leaq	-544(%rbp), %rax
	movl	$8, %edx
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode
	leaq	-544(%rbp), %rax
	addq	$256, %rax
	movq	%rax, %rdi
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv
	testq	%rax, %rax
	jne	.L6
	movl	$_ZZ4mainE19__PRETTY_FUNCTION__, %ecx
	movl	$24, %edx
	movl	$.LC2, %esi
	movl	$.LC3, %edi
	call	__assert_fail
.L6:
	leaq	-576(%rbp), %rdx
	leaq	-544(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movq	(%rax), %rdx
	subq	$24, %rdx
	movq	(%rdx), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdi
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	je	.L7
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv
	movq	%rax, %rdx
	leaq	-608(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z3addP9CStashTagPKv
	jmp	.L6
.L7:
	movl	$0, -656(%rbp)
.L9:
	movl	-656(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -656(%rbp)
	leaq	-608(%rbp), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_Z5fetchP9CStashTagi
	movq	%rax, -648(%rbp)
	cmpq	$0, -648(%rbp)
	setne	%al
	testb	%al, %al
	je	.L8
	movl	-656(%rbp), %ebx
	movl	$.LC4, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movq	-648(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	jmp	.L9
.L8:
	leaq	-640(%rbp), %rax
	movq	%rax, %rdi
	call	_Z7cleanupP9CStashTag
	leaq	-608(%rbp), %rax
	movq	%rax, %rdi
	call	_Z7cleanupP9CStashTag
.LEHE2:
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
.LEHB3:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.LEHE3:
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
.LEHB4:
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
.LEHE4:
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L13
	jmp	.L16
.L15:
	movq	%rax, %rbx
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L12
.L14:
	movq	%rax, %rbx
.L12:
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB5:
	call	_Unwind_Resume
.LEHE5:
.L16:
	call	__stack_chk_fail
.L13:
	addq	$640, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1085:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1085:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1085-.LLSDACSB1085
.LLSDACSB1085:
	.uleb128 .LEHB0-.LFB1085
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1085
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L14-.LFB1085
	.uleb128 0
	.uleb128 .LEHB2-.LFB1085
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L15-.LFB1085
	.uleb128 0
	.uleb128 .LEHB3-.LFB1085
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L14-.LFB1085
	.uleb128 0
	.uleb128 .LEHB4-.LFB1085
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB5-.LFB1085
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE1085:
	.text
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1169:
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
	jne	.L19
	cmpl	$65535, -8(%rbp)
	jne	.L19
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L19:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1169:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1170:
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
.LFE1170:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 8
	.type	_ZZ4mainE19__PRETTY_FUNCTION__, @object
	.size	_ZZ4mainE19__PRETTY_FUNCTION__, 11
_ZZ4mainE19__PRETTY_FUNCTION__:
	.string	"int main()"
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
