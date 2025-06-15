	.file	"globalVars.c"
	.intel_syntax noprefix
	.text
	.globl	useMeOtherFile
	.data
	.align 4
	.type	useMeOtherFile, @object
	.size	useMeOtherFile, 4
useMeOtherFile:
	.long	69
	.align 4
	.type	thisFileOnly, @object
	.size	thisFileOnly, 4
thisFileOnly:
	.long	420
	.text
	.globl	outerFunction
	.type	outerFunction, @function
outerFunction:
.LFB6:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	eax, 0
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	outerFunction, .-outerFunction
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR thisFileOnly[rip], 10
	mov	DWORD PTR useMeOtherFile[rip], 11
	mov	DWORD PTR -4[rbp], 10
	mov	eax, 0
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
