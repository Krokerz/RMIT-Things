; Multiplication example.
.ORIG x3000
; Load the values to be multiplied.
LD R0, X
LD R1, Y
; Prepare R2 for holding the result by setting its value to 0.
AND R2, R2, #0
JSR MULT
STI R2, address_result

LD R0, A
LD R1, B
; Prepare R2 for holding the result by setting its value to 0.
AND R2, R2, #0
JSR MULT
STI R2, addr

HALT
; Calculate A * B via B + B + ... + B (a total of A times).
MULT
mul_loop
ADD R2, R2, R1 ; Add B to the running total
ADD R0, R0, #-1 ; We now need one less B to be added.
BRp mul_loop ; Keep looping while there are Bs to be added.
RET

X .FILL #5
Y .FILL #3
A .FILL #2
B .FILL #4
address_result .FILL x3102
addr .FILL x3112
.END
