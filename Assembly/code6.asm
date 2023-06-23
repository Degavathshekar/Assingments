.include "/home/degavathshekar/Documents/code6/src/m328Pdef.inc"
ldi r16,0x04
out DDRB,r16
ldi r17,0x20
out DDRD,r17
ldi r18,0x02
sts TCCR1B,r18

clr r19
ldi r20,0x20

loop: 
     eor r19,r20
     out PORTB,r19
     ldi r21,0x1f
     rcall delay
     rjmp loop
delay:
lp2:
   IN r22,TIFR1
   ldi r23,0x01
   and r22,r23
   breq delay
   out TIFR1,r23
   ldi r24,TCNT1L
   ldi r25,TCNT1H
   ldi r26,0x00
   ldi r27,0x40
   and r24,r26
   and r25,r27
   ldi r28,14
loop1:
      lsr r25
      lsr r24
      dec r28
      brneloop1
  
     ldi r29,TCNT1L
     ldi r30,TCNT1H
     ldi r31,0x00
     ldi r16,0x80
     and r29,r31
     and r30,r16
     ldi r17,15
loop2:
      lsr r30
      lsr r29
      dec r17
      brne loop2
or r25,r30
lsl r25
lsl r25
out PORTB,r25
dec r21
breq loop
brne lp2
ret
