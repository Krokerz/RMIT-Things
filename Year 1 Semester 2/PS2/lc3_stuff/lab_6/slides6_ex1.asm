.ORIG x3000
LD R6, ADDR

LD R1, X
STR R1, R6, #0
BRzp NOTNEG
    LEA R0, ERR1
    PUTS
    HALT
NOTNEG

LD R2, Y
STR R2, R6, #1
BRp ISPOS
    LEA R0, ERR2
    PUTS
    HALT
ISPOS

LEA R0, CORR
PUTS
JSR DIV

HALT

DIV
    ADD R3, R3, R2
    NOT R2, R2
    ADD R2, R2, #1

    LOOP
        ADD R4, R4, #1
        ADD R1, R1, R2
    BRp LOOP
    ADD R4, R4, #-1
    ADD R1, R1, R3

    STR R4, R6, #2
    STR R1, R6, #3
RET

X .FILL #5
Y .FILL #3
ADDR .FILL x3100
ERR1 .STRINGZ "X must be non-negative"
ERR2 .STRINGZ "Y must be positive"
CORR .STRINGZ "The inputs are valid"

.END