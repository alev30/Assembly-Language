.data

num1:
	.long 32
	.long 32

num2:
	.long 32
	.long 32

total:
	.long 60
	.long 60

.text

.global _start

_start:
	movl $num1, %ecx
	movl $num2, %ebx
	addl (%ecx), %edx
	addl (%ebx), %edx
	addl $4, %ebx
	addl $4, %ecx
	addl (%ecx), %eax
	addl (%ebx), %eax
	jc carry
	jmp done

carry:
	addl $1, %edx

done: movl %ecx, total

