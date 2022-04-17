global	_ft_write
extern ___error
section .text

_ft_write:
		mov		rax, 0x2000004
		syscall
		jc		error			; if carry flag goto error
		ret

error:
		mov		r8, rax			; save err val
		call	___error		; get err addr
		mov		[rax], r8		; err val to addr
		mov		rax, -1
		ret
