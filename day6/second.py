import sys
import re
from functools import reduce

res = 0
matriz = []
ops = "";
translator = {"+": lambda x, y: x+y , "*": lambda x, y: x*y}

# jesus christ, man. calcutes values on a column
def cephalopod_math(n_spaces, pos):
    nums = ["" for _ in range(n_spaces)]
    for i in range(n_spaces):
        for row in matriz:
            row = row[pos:pos+n_spaces]
            nums[i] += row[i]

    # nums = list(map(int, nums[::-1]))
    return reduce(translator[ops[pos]], map(int, nums))  

# "main" function
with open(sys.argv[1]) as fh:
    while line := fh.readline():
        if (re.search("\\d", line) != None):
            line = line[:len(line)-1]
            matriz.append(line)
        else:
            ops = line[:len(line)-1]

pos = 0
while (spaces := re.search(r"\+|\*", ops[pos+1:])) != None:
    n_spaces = spaces.start()
    res += cephalopod_math(n_spaces, pos)   
    pos += n_spaces+1

n_spaces = len(ops[pos:])
res += cephalopod_math(n_spaces, pos)
print(res)
