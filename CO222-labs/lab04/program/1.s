	.file	"1.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%c[%d;%d;%dm"
.LC1:
	.string	"%s"
	.text
.global	textcolor
	.type	textcolor, @function
textcolor:
	push r16
	push r17
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,13
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue: function */
/* frame size = 13 */
/* stack size = 17 */
.L__stack_usage = 17
	subi r20,-40
	sbci r21,-1
	push r21
	push r20
	subi r22,-30
	sbci r23,-1
	push r23
	push r22
	push r25
	push r24
	push __zero_reg__
	ldi r24,lo8(27)
	push r24
	ldi r24,lo8(.LC0)
	ldi r25,hi8(.LC0)
	push r25
	push r24
	movw r16,r28
	subi r16,-1
	sbci r17,-1
	push r17
	push r16
	call sprintf
	push r17
	push r16
	ldi r24,lo8(.LC1)
	ldi r25,hi8(.LC1)
	push r25
	push r24
	call printf
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* epilogue start */
	adiw r28,13
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	pop r17
	pop r16
	ret
	.size	textcolor, .-textcolor
	.section	.rodata.str1.1
.LC2:
	.string	"  "
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
	push r12
	push r13
	push r14
	push r15
	push r16
	push r17
	push r28
	push r29
/* prologue: function */
/* frame size = 0 */
/* stack size = 8 */
.L__stack_usage = 8
	ldi r28,0
	ldi r29,0
	ldi r16,lo8(.LC2)
	ldi r17,hi8(.LC2)
.L6:
	movw r12,r28
	ldi r24,1
	and r12,r24
	clr r13
	mov r14,__zero_reg__
	mov r15,__zero_reg__
.L5:
	movw r24,r14
	add r24,r12
	adc r25,r13
	sbrs r24,0
	rjmp .L3
	ldi r20,lo8(7)
	ldi r21,0
	ldi r22,0
	ldi r23,0
	rjmp .L9
.L3:
	ldi r20,0
	ldi r21,0
	ldi r22,lo8(7)
	ldi r23,0
.L9:
	ldi r24,0
	ldi r25,0
	call textcolor
	push r17
	push r16
	call printf
	pop __tmp_reg__
	pop __tmp_reg__
	ldi r24,-1
	sub r14,r24
	sbc r15,r24
	ldi r24,8
	cp r14,r24
	cpc r15,__zero_reg__
	brne .L5
	ldi r20,0
	ldi r21,0
	ldi r22,lo8(7)
	ldi r23,0
	ldi r24,0
	ldi r25,0
	call textcolor
	ldi r24,lo8(10)
	ldi r25,0
	call putchar
	adiw r28,1
	cpi r28,8
	cpc r29,__zero_reg__
	brne .L6
	ldi r20,0
	ldi r21,0
	ldi r22,lo8(7)
	ldi r23,0
	ldi r24,0
	ldi r25,0
	call textcolor
	ldi r24,0
	ldi r25,0
/* epilogue start */
	pop r29
	pop r28
	pop r17
	pop r16
	pop r15
	pop r14
	pop r13
	pop r12
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 5.4.0"
.global __do_copy_data
