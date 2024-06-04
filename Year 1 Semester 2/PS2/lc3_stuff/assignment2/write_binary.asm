.ORIG x3000
LD R4, NUMBER_TO_CONVERT
ADD R5, R5, #1

TRAP 0x31
ADD R0, R0, #1

LOOP
    AND R3, R3, #0

    AND R6, R4, R5
    BRz NOPE
        ADD R3, R3, #1
    NOPE

    TRAP 0x34

    ADD R0, R0, #1
    ADD R5, R5, R5
BRnp LOOP

HALT

NUMBER_TO_CONVERT .FILL #0 ; Note: Please do not change the name of this constant

.END