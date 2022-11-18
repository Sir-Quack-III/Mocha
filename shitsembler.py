from enum import Enum

#    +------------------+    #
#    |   welcome to     |    #
#    |  ENUM  VALLEY    |    #
#    +------------------+    #
#            |               #
#            |               #

class Regs(Enum):
    R0  =  0
    R1  =  1
    R2  =  2
    R3  =  3
    R4  =  4
    R5  =  5
    R6  =  6
    R7  =  7
    R8  =  8
    R9  =  9
    R10 = 10
    R11 = 11
    R12 = 12
    R13 = 13
    R14 = 14
    R15 = 15

class TokType(Enum):
    REG     = 0
    NUM     = 1
    OP      = 2
    LABEL   = 3
    COMMA   = 4
    COLON   = 5
    NEWLINE = 6
    EOF     = 7

class OpType(Enum):
    NOP = 0
    MOV = 1
    LDI = 2
    LDA = 3
    ST  = 4
    PSH = 5
    POP = 6
    CAL = 7
    RET = 8
    CMP = 9
    JMP = 10
    JEQ = 11
    JNE = 12
    JCR = 13
    JOV = 14
    JNG = 15
    JC1 = 16
    JC2 = 17
    JC3 = 18
    JC4 = 19
    ADD = 20
    SUB = 21
    MUL = 22
    DIV = 23
    INC = 24
    DEC = 25

class Token:
    def __init__(self, type, value):
        self.type = type
        self.value = value

    def __repr__(self):
        return f"Token({self.type}, {self.value})"

class Reg(Token):
    def __init__(self, value):
        super().__init__(TokType("REG"), value)

class Instr(Token):
    def __init__(self, value):
        super().__init__(TokType("OP"), value)

class Lexer:
    def __init__(self):
        super().__init__()
    def decode_reg(self, reg):
        if reg[0] == "R":
            return Regs[reg].value
        else:
            return int(reg)
    def lex(self, str):
        out = []
        snl = str.split("\n")
        for i in range(len(snl)):
            cr = snl[i].split(" ")
            for j in range(len(cr)):
                if cr[j] == "":
                    continue
                if cr[j][0] == "nop":
                    out.append(Token(TokType("NOP"), 0))
        

if __name__ == "__main__":
    l = Lexer("fuck you")