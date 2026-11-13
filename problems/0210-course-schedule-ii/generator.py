def chain(rng, n, cyclic=False):
    edges = [[i,i-1] for i in range(n-1,0,-1)]
    if cyclic:
        edges.append([0,n-1])
    return {"numCourses":n, "prerequisites":edges}

def wide_dag(rng, n, width):
    # Each course depends on the preceding width courses; unique directed pairs.
    edges = [[i,j] for i in range(n-1,0,-1) for j in range(max(0,i-width),i)]
    return {"numCourses":n,"prerequisites":edges}

def independent(rng, n):
    return {"numCourses":n,"prerequisites":[]}
