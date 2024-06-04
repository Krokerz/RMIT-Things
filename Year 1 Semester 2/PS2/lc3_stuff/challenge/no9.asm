.ORIG x3000
TRAP 0x31

LD R3, GRASSBLOCK
LD R5, Z_DIST

ZLOOP
    ADD R2, R2, R5
    JSR XPLACE
    
    NOT R6, R5
    ADD R6, R6, #1
    ADD R6, R6, R6

    ADD R2, R2, R6
    JSR XPLACE

    ADD R2, R2, R5

    ADD R5, R5, #-1
BRzp ZLOOP

HALT

XPLACE
    LD R4, X_DIST

    XLOOP
        ADD R0, R0, R4
        TRAP 0x34
        
        NOT R6, R4
        ADD R6, R6, #1
        ADD R6, R6, R6

        ADD R0, R0, R6
        TRAP 0x34

        ADD R0, R0, R4

        ADD R4, R4, #-1
    BRzp XLOOP
RET

X_DIST .FILL #2
Z_DIST .FILL #3
GRASSBLOCK .FILL #2

.END