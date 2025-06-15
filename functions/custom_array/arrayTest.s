	.file	"arrayTest.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
    // STACK setup
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6

    // Make space on the stack for our Array
	sub	rsp, 48
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax

    // Place the value 10 onto the stackArray
	mov	DWORD PTR -24[rbp], 10

    // Bellow we are using the Instruction Pointer (rip) to store a global/static value
    // This is refered to as RIP-relative addressing
    //
    //     We are storing the heapArray in the .bss section
    //     And using the RIP (Instruction Pointer) as a reference

    // This might be a bit misleading, because the RIP is always changing, but dont worry!
    //      The Linker will resolve heapArray.2833 to an offset that you can add to RIP to get to the actuall address of the heapArray
    //      This is what makes it RIP-Relative-Addressing
    //  In actuall binary it would look something like this:
    //      mov DWORD PTR [RIP + 0x1fe9], 0xf
    //  
    //  Where the address added to RIP is inserted into the assembly by the Linker
    //

	mov	DWORD PTR heapArray.2833[rip+8], 15

    // ^ What makes static varibles interesting:
    //      They are always defined and allocated in the .bss or .data section
    //          Therefore apart of your Executable Binary!
    //      Will not be thrown away when a function exits because of it
    //


	mov	edi, 20
	call	malloc@PLT
	mov	QWORD PTR -40[rbp], rax
	mov	rax, QWORD PTR -40[rbp]
	add	rax, 8
	mov	DWORD PTR [rax], 13

    // Exit function, cleanup stack and do stack-protection security
	mov	eax, 0
	mov	rdx, QWORD PTR -8[rbp]
	xor	rdx, QWORD PTR fs:40
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main

    // Define a symbol LOCAL to this file
    // And Reserve it in the .bss section (.comm) reserving 20 Bytes. Uninitialized Data
	.local	heapArray.2833         // Declare a local symbol
	.comm	heapArray.2833,20,16   // Allocate 20 Bytes of memory from that symbol address in the data .bss section
	
    
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
