
	.text
	
	.global xfind
xfind:
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	
	movq %rdi, %rbx
	movq %rsi, %r12
	movq %rdx, %r13
	movq %rcx, %r14
	movq %r8, %r15
	
	jmp xf_firstTest
xf_next:
	decq %r12
	
	movq %r15, %rsi
	movq %rbx, %rdi
	call *%r14
	
	testl %eax, %eax
	jz xf_test

	movq %rbx, %rax
	jmp xf_done

xf_test:
	addq %r13, %rbx
xf_firstTest:
	testq %r12, %r12
	jnz xf_next
	xorq %rax, %rax  # rax <- NULL
xf_done:	
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx	
	ret
