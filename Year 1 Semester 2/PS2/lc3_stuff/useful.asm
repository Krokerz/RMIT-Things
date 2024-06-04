.ORIG x3000
LD R5, ADDR

LD R0, X
STR R0, R5, #0

LD R1, Y
STR R1, R5, #1

JSR INV
STR R6, R5, #2

HALT

; All results are stored in R6

; Uses: R0
; -R0
INV
    NOT R6, R0
    ADD R6, R6, #1
RET

; Uses: R0
; |R0|
ABS
    ADD R6, R0, #0
    BRzp ABS_NOTNEG
        ;INV
        NOT R6, R0
        ADD R6, R6, #1
    ABS_NOTNEG
RET

; Uses: R0, R1
; R0 * R1
; For negative R: -(|R0| * |R1|)
MUL
    AND R6, R6, #0
    MUL_LOOP
        ADD R1, R1, #-1
        BRzp MUL_NOTNEG
            BR MUL_STOP
        MUL_NOTNEG

        ADD R6, R6, R0
    BR MUL_LOOP
    MUL_STOP
RET

; Uses: R0, R1
; R0 / R1
; For negative R: -(|R0| / |R1|)
DIV
    AND R6, R6, #0

    ;INV
    NOT R1, R1
    ADD R1, R1, #1

    DIV_LOOP
        ADD R0, R0, R1
        BRp DIV_NOTPOS
            BR DIV_STOP
        DIV_NOTPOS
        
        ADD R6, R6, #1
    BR DIV_LOOP
    DIV_STOP
RET

; Uses: R0, R1, R2
; R0 mod R2
; For negative R: hell naw
MOD
    AND R6, R6, #0

    ;INV
    NOT R2, R2
    ADD R2, R2, #1

    MOD_LOOP
        ADD R1, R0, R2
        BRp MOD_NOTPOS
            ADD R6, R6, R0
            BR MOD_STOP
        MOD_NOTPOS

        ADD R0, R0, R2
    BR MOD_LOOP
    MOD_STOP
RET

; Uses: R0, R1, R2, R3
; R0 ^ R3
POW
    ADD R6, R6, #1
    POW_LOOP
        ADD R3, R3, #-1
        BRzp POW_NOTNEG
            BR POW_STOP
        POW_NOTNEG

        ;MUL
        ADD R1, R1, R0
        POW_MUL_LOOP
            ADD R1, R1, #-1
            BRzp POW_MUL_NOTNEG
                BR POW_MUL_STOP
            POW_MUL_NOTNEG

            ADD R2, R2, R6
        BR POW_MUL_LOOP
        POW_MUL_STOP

        AND R6, R6, #0
        ADD R6, R6, R2
    BR POW_LOOP
    POW_STOP
RET

; Uses: R0, R1
; R0 OR R1
OR
    NOT R0, R0
    NOT R1, R1
    
    AND R6, R0, R1
    NOT R6, R6
RET

; Uses: R0, R1
; R0 XOR R1
XOR
    NOT R0, R0
    AND R0, R0, R1
    NOT R0, R0

    NOT R1, R1
    AND R1, R1, R0
    NOT R1, R1

    AND R6, R0, R1
RET

ADDR .FILL x5000
X .FILL #3
Y .FILL #4

.END