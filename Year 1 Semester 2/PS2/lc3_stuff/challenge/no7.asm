.ORIG x3000
TRAP 0x31

ADD R1, R1, #-1

LOOP
    TRAP 0x33
    ADD R3, R3, #0
    BRz STOP

    ADD R6, R6, #1
    ADD R0, R0, #1
BR LOOP
STOP

HALT

.END