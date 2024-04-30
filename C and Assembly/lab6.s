
.file "sum.s"

.section	.rodata.str1.1,"aMS",@progbits,1
PR_1:
	.string "\nSize of the array: %i\n"
Result:
	.string "\nThe sum is: %i"
	
PInt:
	.string "%i "
	
.data
.align 8
array:
	.quad 1
	.quad 2
	.quad 3
	.quad 4
	.quad 5
	.quad 6
	.quad 7
	.quad 8
	.quad 9
	.quad 10

.globl sum
	.type	sum, @function
.text
sum:
	pushq %rbp		# stack frame management
	movq %rsp, %rbp	# stack frame management
	
	pushq %rsi
	pushq %rdi
	movq $PR_1,%rdi	
	movq $0,%rax
	call printf
	popq %rdi
	popq %rsi

	movq $0, %rax
	
loop:
	decq %rsi		
	jl exit
	addq (%rdi, %rsi,8), %rax
jmp loop
exit:
	leave
	ret
.size sum,.-sum
