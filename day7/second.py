import sys
import re

START = "S"
EMPTY = "."
SPLITTER = "\\^"

diagram = []

def get_splitter_indexes(line: str, pattern: re.Pattern): 
    '''
    find indexes for all occurences of pattern in line
    '''
    indexes = []
    pos = 0
    while m := pattern.search(line, pos):
        indexes.append(m.start())
        pos = m.start() + 1
    
    return indexes

# "main" function
with open(sys.argv[1]) as fh:
    while line := fh.readline():
        diagram.append(line.rstrip())


res = 0
first_beam = diagram[0].find(START)
beam_indexes = [first_beam]

# regex to find all where splitters are
pattern = re.compile(SPLITTER)

for i in range(1, len(diagram)):
    # skip lines that do not split the beam
    if (i % 2) == 1:
        continue
    
    split_ids = get_splitter_indexes(diagram[i], pattern)
    
    # print(diagram[i])
    # print(split_ids)
    
    new_beams = []
    for id in split_ids:
        if id in beam_indexes:
            new_beams += [id-1, id+1]
            beam_indexes.remove(id) # because splitter is here, there's no new beam going through here
    
    # print(new_beams)
    
    # new beams joining the club
    for beam in new_beams:
        if beam not in beam_indexes:
            beam_indexes.append(beam)
            res+=1
    
print(res)
