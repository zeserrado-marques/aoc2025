import sys
import math

distances = {}

def euclDistanceSquared(u, v):
    if not distances.get((u, v)):
        # store result
        distances[(u, v)] = sum([(v[i] - u[i])**2 for i in range(len(u))])
    
    return distances[(u, v)]


def closestCircuits(crds, connected):
    smallest = math.inf
    points = None
    for i in range(len(crds)):
        for j in range(i+1, len(crds)):
            dist = euclDistanceSquared(crds[i], crds[j])
            if smallest > dist and not connected[i][j]:
                smallest = dist
                points = [i, j]
    return points

# find the index of circuit where point is
def getCircuit(circuits, point):
    for i in range(len(circuits)):
        if point in circuits[i]:
            return i
            


if __name__ == "__main__":
    crds = []
    with open(sys.argv[1]) as fh:
        while line := fh.readline():
            x, y, z = map(int, line.rstrip().split(","))
            crds.append((x, y, z)) # extend with circuit ID. starts with its own

    circuits = [[i] for i in range(len(crds))]
    connected = [[0 for _ in range(len(crds))] for _ in range(len(crds))]
    
    N = len(crds)
    
    k = 0
    while k < N:
        points = closestCircuits(crds, connected)
        
        if points is None:
            break
        
        connected[points[0]][points[1]] = True
        # assign to circuits
        # find if i is already in a circuit, and get that circuit
        i = getCircuit(circuits, points[0])
        # same for j
        j = getCircuit(circuits, points[1])
        # if they're in different circuits, join them
        if i != j:
            circuits[i] += circuits[j]
            circuits.remove(circuits[j])
        k+=1
        

    

    circuits.sort(key=lambda x: len(x), reverse=True)
    
    print(circuits[:3])
    
    res = 1
    for a in circuits[:3]:
        res*=len(a)
    print(res)