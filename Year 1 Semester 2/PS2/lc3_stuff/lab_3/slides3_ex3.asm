.ORIG x3000
LD R6, ADDR
ADD R0, R0, #6
STR R0, R6, #0
AND R0, R0, #0
ADD R0, R0, #5
STR R0, R6, #1
AND R0, R0, #0
LDR R1, R6, #0
LDR R2, R6, #1
REPEAT ADD R3, R3, R1
ADD R2, R2, #-1
BRp REPEAT
STR R3, R6, #2
HALT
ADDR .FILL x3100
.END