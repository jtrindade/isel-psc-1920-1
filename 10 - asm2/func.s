
	.text
	
	.global func1
	.global func2
	.global func3
	.global func4
	.global func5
	.global func6
	
func1:
	movq $8, %rax    # endereçamento imediato
	ret
	
func2:
	movq %rdi, %rax
	addq $5, %rax
	ret
	
func3:
	movq %rdi, %rax
	addq %rsi, %rax
	ret

func4:
	xorq  %rax, %rax
	jmp   f4_start
f4_next:
	incq  %rax
f4_start:
	movb  (%rdi, %rax), %cl
	testb %cl, %cl
	jnz    f4_next
	ret
	
func5:
	xorq %rax, %rax
	notq %rax
	movl (%rdi, %rsi, 4), %eax		# endereçamento indexado
	ret
	
func6:
	movl 16(%rdi), %eax		# endereçamento baseado
	ret

	
	
	
	
	
	
	
	
	
	
	