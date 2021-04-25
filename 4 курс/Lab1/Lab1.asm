.include "m16def.inc"
.def outPointer = r16
.def count = r17

rjmp init

init:

ldi outPointer, $81

out SPL, outPointer

ldi count, 6

circle:

inc r18
inc r19
add r18, r19
mov r20, r18
push r20
pop r21
subi r20, 2

dec count

brne circle
ret