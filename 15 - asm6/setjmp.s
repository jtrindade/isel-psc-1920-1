
	.text
	
	.global xsetjmp
	.global xlongjmp
	
xsetjmp:
	movq %rbx,  0(%rdi)
	movq %r12,  8(%rdi)
	movq %r13, 16(%rdi)
	movq %r14, 24(%rdi)
	movq %r15, 32(%rdi)
	movq %rbp, 40(%rdi)
	movq %rsp, 48(%rdi)
	movq (%rsp), %rax
	movq %rax, 56(%rdi)
	xorl %eax, %eax
	ret

xlongjmp:
	movq  0(%rdi), %rbx
	movq  8(%rdi), %r12
	movq 16(%rdi), %r13
	movq 24(%rdi), %r14
	movq 32(%rdi), %r15
	movq 40(%rdi), %rbp
	movq 48(%rdi), %rsp
	movq 56(%rdi), %rax
	movq %rax, (%rsp)
	movq %rsi, %rax
	ret
