.ORIG x3000
LD R6, ADDR
LD R0, VAL
STR R0, R6, #0

JSR FIBO

HALT

FIBO
    ADD R0, R0, #-1
    BRzp NOTINV
        LEA R0, ERR
        PUTS
        RET
    NOTINV

    ADD R0, R0, #-1
    BRzp NOTDONE
        ADD R1, R1, #1
        BR DONE
    NOTDONE

    ADD R4, R4, #1
    ADD R5, R5, #1
    LOOP
        ADD R1, R4, R5
        ADD R0, R0, #-1
        BRnz DONE
            AND R4, R4, #0
            ADD R4, R4, R5
            AND R5, R5, #0
            ADD R5, R5, R1
            AND R1, R1, #0
            BR LOOP
        DONE
    STR R1, R6, #1

    AND R4, R4, #0
    ADD R4, R4, #1
    AND R5, R5, #0
    ADD R5, R5, #1
    ADD R2, R2, #2

    DEFLOOP
        ADD R3, R4, R5
        BRnz OVERFLOW
            ADD R2, R2, #1
            AND R4, R4, #0
            ADD R4, R4, R5
            AND R5, R5, #0
            ADD R5, R5, R3
            AND R3, R3, #0
            BR DEFLOOP
        OVERFLOW
    STR R2, R6, #2
    STR R5, R6, #3
RET

VAL .FILL #5
ADDR .FILL x3100
ERR .STRINGZ "Woopsies! somethin went wrong :'("

.END