	.text
	.global foo
	.global main
main:
	mov $3, %rdi
	mov $4, %rsi
	mov $5, %rdx
	call foo
	mov %rax, %rdi
	mov $60, %rax
	syscall
	
foo:
	push %rbp
	mov %rsp, %rbp
	mov %rdi, %rax
	add %rsi, %rax
	add %rdx, %rax
	xor %rdx, %rdx
	mov $3, %rcx
	div %rcx
	leave
	ret
	
