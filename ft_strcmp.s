global	_ft_strcmp
section .text

_ft_strcmp:
		jmp		cmp

cmp:
		mov		al, BYTE [rdi]
		mov		cl, BYTE [rsi]
		cmp		al, 0
		je		cnt
		cmp		cl, 0
		je		cnt
		cmp		al, cl
		jne		cnt
		inc		rdi
		inc		rsi
		jmp		cmp

cnt:
		sub		al, cl
		movsx	rax, al
		ret
