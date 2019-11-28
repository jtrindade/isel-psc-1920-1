
	.text
	
	.global func

func:
	subq $16, %rsp

	movq %rdi, %rax
	addq %rsi, %rax
	addq %rdx, %rax
	addq %rcx, %rax
	movq %rax, 8(%rsp)

	movq %r8, %rax
	addq %r9, %rax
	addq 24(%rsp), %rax
	addq 32(%rsp), %rax
	movq %rax, 0(%rsp)

	movq 8(%rsp), %rdi
	movq 0(%rsp), %rsi
	call sum
	
	addq $16, %rsp
	ret
