global	_ft_strcpy
section .text

_ft_strcpy:
		push	rdi
		push	rsi
		jmp		cpy
cpy:
		
		cmp		BYTE [rsi], 0
		je		last
		mov		dl, [rsi]
		mov		[rdi], dl
		inc		rsi
		inc		rdi
		jmp		cpy

last:
		mov		dl, [rsi]
		mov		[rdi], dl
		jmp		return

return:

		pop		rsi
		pop		rdi
		mov		rax, rdi
		ret
