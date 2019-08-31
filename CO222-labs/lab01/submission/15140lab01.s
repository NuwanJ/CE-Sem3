	.file	"15140lab01.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
.LC1:
	.string	"-1"
.global	__floatsisf
.global	__mulsf3
.global	__addsf3
.LC2:
	.string	"%.2f\n"
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
	push r28
	push r29
	rcall .
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 2 */
/* stack size = 4 */
.L__stack_usage = 4
	std Y+2,__zero_reg__
	std Y+1,__zero_reg__
	movw r24,r28
	adiw r24,1
	push r25
	push r24
	ldi r24,lo8(.LC0)
	ldi r25,hi8(.LC0)
	push r25
	push r24
	call scanf
	ldd r22,Y+1
	ldd r23,Y+2
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	cp __zero_reg__,r22
	cpc __zero_reg__,r23
	brlt .L2
	ldi r24,lo8(.LC1)
	ldi r25,hi8(.LC1)
	call puts
	rjmp .L3
.L2:
	cpi r22,31
	cpc r23,__zero_reg__
	brge .L4
	mov __tmp_reg__,r23
	lsl r0
	sbc r24,r24
	sbc r25,r25
	call __floatsisf
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(32)
	ldi r21,lo8(64)
	call __mulsf3
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(-16)
	ldi r21,lo8(65)
	rjmp .L5
.L4:
	cpi r22,61
	cpc r23,__zero_reg__
	brge .L6
	subi r22,30
	sbc r23,__zero_reg__
	mov __tmp_reg__,r23
	lsl r0
	sbc r24,r24
	sbc r25,r25
	call __floatsisf
	ldi r18,lo8(51)
	ldi r19,lo8(51)
	ldi r20,lo8(-101)
	ldi r21,lo8(64)
	call __mulsf3
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(-106)
	ldi r21,lo8(66)
	call __addsf3
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(112)
	ldi r21,lo8(66)
	rjmp .L5
.L6:
	cpi r22,91
	cpc r23,__zero_reg__
	brge .L7
	subi r22,60
	sbc r23,__zero_reg__
	mov __tmp_reg__,r23
	lsl r0
	sbc r24,r24
	sbc r25,r25
	call __floatsisf
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(32)
	ldi r21,lo8(65)
	call __mulsf3
	ldi r18,0
	ldi r19,lo8(-128)
	ldi r20,lo8(-21)
	ldi r21,lo8(67)
	call __addsf3
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(-76)
	ldi r21,lo8(66)
	rjmp .L5
.L7:
	cpi r22,121
	cpc r23,__zero_reg__
	brge .L8
	subi r22,90
	sbc r23,__zero_reg__
	mov __tmp_reg__,r23
	lsl r0
	sbc r24,r24
	sbc r25,r25
	call __floatsisf
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(-34)
	ldi r21,lo8(65)
	call __mulsf3
	ldi r18,0
	ldi r19,lo8(-64)
	ldi r20,lo8(64)
	ldi r21,lo8(68)
	rjmp .L10
.L8:
	cpi r22,-75
	cpc r23,__zero_reg__
	brge .L9
	subi r22,120
	sbc r23,__zero_reg__
	mov __tmp_reg__,r23
	lsl r0
	sbc r24,r24
	sbc r25,r25
	call __floatsisf
	ldi r18,0
	ldi r19,0
	ldi r20,0
	ldi r21,lo8(66)
	call __mulsf3
	ldi r18,0
	ldi r19,lo8(112)
	ldi r20,lo8(-56)
	ldi r21,lo8(68)
.L10:
	call __addsf3
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(-16)
	ldi r21,lo8(67)
	rjmp .L5
.L9:
	subi r22,-76
	sbc r23,__zero_reg__
	mov __tmp_reg__,r23
	lsl r0
	sbc r24,r24
	sbc r25,r25
	call __floatsisf
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(52)
	ldi r21,lo8(66)
	call __mulsf3
	ldi r18,0
	ldi r19,lo8(56)
	ldi r20,lo8(92)
	ldi r21,lo8(69)
	call __addsf3
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(7)
	ldi r21,lo8(68)
.L5:
	call __addsf3
	push r25
	push r24
	push r23
	push r22
	ldi r24,lo8(.LC2)
	ldi r25,hi8(.LC2)
	push r25
	push r24
	call printf
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
.L3:
	ldi r24,0
	ldi r25,0
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 5.4.0"
.global __do_copy_data
