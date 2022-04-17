global	_ft_strlen
section .text

_ft_strlen:
		mov		rax, 0
		jmp		while

plus:
		inc		rax
		jmp		while

while:
		cmp		BYTE [rdi+rax], 0
		je		return
		jmp		plus

return:
		ret
