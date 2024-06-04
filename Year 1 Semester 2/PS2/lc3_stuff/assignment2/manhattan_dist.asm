.ORIG x3000
TRAP 0x31

LD R4, G_X
JSR INV

ADD R4, R0, R4
BRzp NOTNEG0
    JSR INV
NOTNEG0
ADD R5, R5, R4

LD R4, G_Y
JSR INV

ADD R4, R1, R4
BRzp NOTNEG1
    JSR INV
NOTNEG1
ADD R5, R5, R4

LD R4, G_Z
JSR INV

ADD R4, R2, R4
BRzp NOTNEG2
    JSR INV
NOTNEG2
ADD R5, R5, R4

NOT R5, R5
ADD R5, R5, #1

LD R4, GOAL_DIST

ADD R5, R4, R5
BRn ISNEG
    LEA R0, INGOAL
ISNEG
BRzp ISPOS
    LEA R0, NOTGOAL
ISPOS

TRAP 0x30

HALT

INV
    NOT R4, R4
    ADD R4, R4, #1
RET

INGOAL .STRINGZ "The player is within Manhattan distance of the goal"
NOTGOAL .STRINGZ "The player is outside the goal bounds"

; Note: Please do not change the names of the constants below
G_X .FILL #6
G_Y .FILL #-60
G_Z .FILL #5
GOAL_DIST .FILL #10
.END