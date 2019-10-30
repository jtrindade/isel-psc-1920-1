
	.text
	.globl func
func:
	movq %rdi, %rax
	addq %rsi, %rax
	ret
