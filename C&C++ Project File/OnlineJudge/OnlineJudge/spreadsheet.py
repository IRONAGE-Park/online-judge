fr = open("spreadsheet.inp", "r")
fw = open("spreadsheet.out", "w");

def toDecimal(Alphabet):
    dec = 0
    i = len(Alphabet) - 1
    for p in range(len(Alphabet)):
        dec = dec + (ord(Alphabet[i]) - 64) * pow(26, p)
        i = i - 1
    return dec

def toAlphabet(Decimal):
    alp = ""
    while Decimal :
        alp = alp + chr(((Decimal - 1) % 26) + 65)
        Decimal = (Decimal - 1) / 26
    return alp[::-1]

def toSheet(str):
    answer = ""
    i = 1
    while str[i] < 'A' :
        i = i + 1
    ni = i
    i = i + 1
    answer = answer + toAlphabet(int(str[i:])) + str[1:ni]
    return answer

def toNumbering(str):
    answer = "R"
    i = 0
    while str[i] >= 'A' :
        i = i + 1
    ni = i
    answer = answer + str[i:] + "C" + repr(toDecimal(str[0:ni]))
    return answer

def CheckForm(str):
    if str[0] == 'R':
        i = 1
        while str[i] >= 'A' :
            i = i + 1
        while str[i] < 'A' :
            i = i + 1
        if str[i] == 'C':
            return True
        return False
    return False

testcase = int(fr.readline())
lines = fr.readlines()

for str in lines:
    if str[-1] == '\n' :
        str = str[:-2]
    if CheckForm(str):
        str = toSheet(str[:])
    else :
        str = toNumbering(str[:])
    fw.write(str + '\n')
    testcase = testcase - 1

fr.close()
fw.close()
