import sys
from queue import PriorityQueue

START = "S"
EMPTY = "."
SPLITTER = "^"

diagram = []
# "main" function
with open(sys.argv[1]) as fh:
    while line := fh.readline():
        diagram.append(line.rstrip())


res = 1 # we always have at least 1 beam
first_beam = diagram[0].find(START)

beam_indexes = PriorityQueue(maxsize=len(diagram[0]))
beam_indexes.put(first_beam)
for i in range(1, len(diagram)):
    # skip lines that do not split the beam
    if (i % 2) == 1:
        continue



