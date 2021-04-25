



/*
 * Lab1.asm
 *
 *  Created: 08.09.2020 11:17:11
 *   Author: User
 */ 


  .include "m16def.inc"
  //temp is pointer to r16
 .def temp = r16
 //count is pointer to r17
 .def count=r17

 //Move to init
 rjmp init
 ;
 init:
 //Assign $80 to r 16
 ldi temp, $80
 //Send temp to SPL port
 out SPL, temp
 //Assign 5 to r17
 ldi count, 5
 m1:
 //Increment r18
 inc r18
 //Increment r19
 inc r19
 //r18 = r18 + r19
 add r18, r19
 //r20 = r18
 mov r20, r18
 //Push r20 value in stack ESP
 push r20
 //Pop r21 value from stack ESP
 pop r21
 //r20 - 2
 subi r20, 2
 //count--
 dec count 
 //if count != 0
 brne m1
 ret