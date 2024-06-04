.ORIG x3000
LD R6, ADDR
LD R0, X
STR R0, R6, #0
LD R1, Y
STR R1, R6, #1

JSR MULT
STR R4, R6, #2

HALT

MULT
    ADD R2, R2, #1

    LOOP
        AND R3, R1, R2
        BRnz SKIP
            ADD R4, R4, R0
        SKIP

        NOT R3, R3
        ADD R3, R3, #1

        ADD R2, R2, R2
        ADD R0, R0, R0
        ADD R1, R1, R3
    BRp LOOP
RET

X .FILL #5
Y .FILL #3
ADDR .FILL x3100

.END