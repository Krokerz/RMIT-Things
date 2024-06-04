.ORIG x3000
TRAP 0x31

ADD R1, R1, #-1
TRAP 0x33

LEA R0, MAIN
TRAP 0x30

AND R4, R3, #1

BRp NOTEVEN
    LEA R0, EVEN
NOTEVEN
BRz NOTODD
    ADD R3, R3, #-10

    BRzp NOTLESS
        LEA R0, LESSODD
    NOTLESS
    BRn NOTMORE
        LEA R0, MOREODD
    NOTMORE
NOTODD

TRAP 0x30

HALT

MAIN .STRINGZ "The block beneath the player tile is "
EVEN .STRINGZ "even-numbered"
LESSODD .STRINGZ "odd-numbered and less than 10"
MOREODD .STRINGZ "odd-numbered and more than 10"

.END