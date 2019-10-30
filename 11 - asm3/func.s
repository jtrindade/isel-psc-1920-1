
	.text
	
	.global xputs
	
xputs:
	pushq %rbx
	movq %rdi, %rbx
	jmp xp_test
xp_next:
	call putchar
	incq %rbx
xp_test:
	movzxb (%rbx), %edi
	testl %edi, %edi
	jnz xp_next
xp_done:
	movl $10, %edi
	call putchar
	pop %rbx
	ret

	.global callMyFunc

callMyFunc:
	call myfunc
	ret
	
	
	
	
	
	
	
	
	