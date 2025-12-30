import sys
from functools import reduce
distances = {}

def euclDistanceSquared(u, v):
    if not distances.get((u, v)):
        # store result
        distances[(u, v)] = sum([(v[i] - u[i])**2 for i in range(len(u))])
    
    return distances[(u, v)]

def getArea(p1, p2):
    return reduce(lambda x, y: x*y, [abs(p2[i] - p1[i])+1 for i in range(len(p1))])

# main(int argc, char * argv[])
if __name__ == '__main__':
    red_flags = []
    with open(sys.argv[1]) as fh:
        while line := fh.readline():
            x, y = map(int, line.rstrip().split(','))
            red_flags.append((x, y))
    
    # sort by distance to origin
    ola = sorted(red_flags, key=lambda x: euclDistanceSquared((0, 0), x))
    
    print(getArea(ola[0], ola[len(ola)-1]), ola[0], ola[len(ola)-1])
