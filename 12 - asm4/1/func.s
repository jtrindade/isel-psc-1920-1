
	.section .rodata
nl: .byte '\n'
	
	.text
	
	.global println
	
println:
	pushq %rdi
	call  strlen
	popq  %rdi

	movq  %rax, %rdx      # count <- strlen(str)
	movq  %rdi, %rsi      # buf   <- str
	movq  $1, %rdi        # fd    <- 1 (stdout)
	movq  $1, %rax        # syscall number = 1  (sys_write)
	syscall

	movq  $1, %rdx        # count <- 1
	leaq  nl(%rip), %rsi  # buf   <- &nl
	movq  $1, %rdi        # fd    <- 1 (stdout)
	movq  $1, %rax        # syscall number = 1  (sys_write)
	syscall

	ret
