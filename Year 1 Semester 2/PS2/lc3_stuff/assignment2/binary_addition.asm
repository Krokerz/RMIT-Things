.ORIG x3000
JSR SETUP
ADD R2, R2, #1

JSR READ
ADD R6, R6, R5
TRAP 0x36

JSR SETUP
ADD R2, R2, #2
AND R5, R5, #0

JSR READ
ADD R6, R6, R5
TRAP 0x36

JSR SETUP
ADD R2, R2, #3

JSR WRITE

HALT

SETUP
    TRAP 0x31
    ADD R0, R0, #1
RET

READ
    ADD R4, R4, #1

   RLOOP
        TRAP 0x33

        ADD R3, R3, #-1
        BRnp NOTSTONE
            ADD R5, R5, R4
        NOTSTONE

        ADD R0, R0, #1
        ADD R4, R4, R4
    BRnp RLOOP
RET

WRITE
    ADD R4, R4, #1

    WLOOP
        AND R3, R3, #0

        AND R5, R6, R4
        BRz ISZERO
            ADD R3, R3, #1
        ISZERO

        TRAP 0x34

        ADD R0, R0, #1
        ADD R4, R4, R4
    BRnp WLOOP
RET

.END