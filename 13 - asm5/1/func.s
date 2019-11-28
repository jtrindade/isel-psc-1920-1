
	.text
	
	.global func

func:
	xorl %eax, %eax

	addq %rdi, %rax
	addq %rsi, %rax
	addq %rdx, %rax
	addq %rcx, %rax
	addq %r8, %rax
	addq %r9, %rax
	addq 8(%rsp), %rax
	addq 16(%rsp), %rax

	ret
