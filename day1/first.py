import sys

SIZE = 100
translator = {"L": -1, "R": 1}
start = 50
code = 0

with open(sys.argv[1]) as fh:
    while line := fh.readline():
        step = int(line.strip()[1:])
        direction = translator[line[0]]
        start = (start + direction*step) % SIZE

        if start == 0:
            code += 1
        
        print(line.strip(), start)

print(code)
