global	_ft_strdup
extern	___error
extern	_ft_strlen
extern	_ft_strcpy
extern	_malloc
section .text

_ft_strdup:
		push	rdi
		call	_ft_strlen
		inc		rax
		mov		rdi, rax
		call	_malloc
		jc		error
		pop		rdi
		mov		rsi, rdi
		mov		rdi, rax
		call	_ft_strcpy
		ret

error:
		mov		r8, rax
		call	___error
		mov		[rax], r8
		mov		rax, -1
		ret
		