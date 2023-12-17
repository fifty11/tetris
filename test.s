	.text
	.file	"main.c"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	movl	$0, -64(%rbp)
	movw	$25664, -50(%rbp)               # imm = 0x6440
	movw	$25120, -52(%rbp)               # imm = 0x6220
	movw	$17476, -54(%rbp)               # imm = 0x4444
	movw	$26112, -56(%rbp)               # imm = 0x6600
	movw	$-7168, -58(%rbp)               # imm = 0xE400
	leaq	-50(%rbp), %rax
	movq	%rax, -48(%rbp)
	leaq	-52(%rbp), %rax
	movq	%rax, -40(%rbp)
	leaq	-54(%rbp), %rax
	movq	%rax, -32(%rbp)
	leaq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	leaq	-58(%rbp), %rax
	movq	%rax, -16(%rbp)
	movb	$1, game(%rip)
	movl	$0, -68(%rbp)
.LBB0_1:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_3 Depth 2
	cmpl	$5, -68(%rbp)
	jge	.LBB0_13
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movl	$0, -72(%rbp)
.LBB0_3:                                #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cmpl	$16, -72(%rbp)
	jge	.LBB0_11
# %bb.4:                                #   in Loop: Header=BB0_3 Depth=2
	movslq	-68(%rbp), %rax
	movq	-48(%rbp,%rax,8), %rax
	movzwl	(%rax), %eax
	movl	-72(%rbp), %ecx
	movl	$1, %edx
                                        # kill: def $cl killed $ecx
	shll	%cl, %edx
	movl	%edx, %ecx
	andl	%ecx, %eax
	cmpl	$0, %eax
	je	.LBB0_6
# %bb.5:                                #   in Loop: Header=BB0_3 Depth=2
	leaq	.L.str(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	jmp	.LBB0_7
.LBB0_6:                                #   in Loop: Header=BB0_3 Depth=2
	leaq	.L.str.1(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
.LBB0_7:                                #   in Loop: Header=BB0_3 Depth=2
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	$4, %ecx
	cltd
	idivl	%ecx
	cmpl	$0, %edx
	jne	.LBB0_9
# %bb.8:                                #   in Loop: Header=BB0_3 Depth=2
	leaq	.L.str.2(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
.LBB0_9:                                #   in Loop: Header=BB0_3 Depth=2
	jmp	.LBB0_10
.LBB0_10:                               #   in Loop: Header=BB0_3 Depth=2
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	jmp	.LBB0_3
.LBB0_11:                               #   in Loop: Header=BB0_1 Depth=1
	leaq	.L.str.3(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
# %bb.12:                               #   in Loop: Header=BB0_1 Depth=1
	movl	-68(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -68(%rbp)
	jmp	.LBB0_1
.LBB0_13:
	movq	%fs:40, %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	.LBB0_15
# %bb.14:
	xorl	%eax, %eax
	addq	$80, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.LBB0_15:
	.cfi_def_cfa %rbp, 16
	callq	__stack_chk_fail@PLT
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	game,@object                    # @game
	.bss
	.globl	game
game:
	.byte	0                               # 0x0
	.size	game, 1

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"1 "
	.size	.L.str, 3

	.type	.L.str.1,@object                # @.str.1
.L.str.1:
	.asciz	"0 "
	.size	.L.str.1, 3

	.type	.L.str.2,@object                # @.str.2
.L.str.2:
	.asciz	"\n"
	.size	.L.str.2, 2

	.type	.L.str.3,@object                # @.str.3
.L.str.3:
	.asciz	"\n\n"
	.size	.L.str.3, 3

	.ident	"clang version 16.0.6"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym __stack_chk_fail
	.addrsig_sym game
