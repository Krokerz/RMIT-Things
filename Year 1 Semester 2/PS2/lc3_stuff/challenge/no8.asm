.ORIG x3000
TRAP 0x31

ADD R0, R0, #2
ADD R2, R2, #2
JSR LAMP

ADD R0, R0, #-4
JSR LAMP

ADD R0, R0, #4
ADD R2, R2, #-4
JSR LAMP

ADD R0, R0, #-4
JSR LAMP

HALT

LAMP
    LD R3, STONE
    TRAP 0x34

    ADD R1, R1, #1
    TRAP 0x34

    ADD R1, R1, #1
    TRAP 0x34

    ADD R1, R1, #1
    LD R3, GLOWSTONE
    TRAP 0x34

    ADD R1, R1, #-3
RET

STONE .FILL #1
GLOWSTONE .FILL #89

.END