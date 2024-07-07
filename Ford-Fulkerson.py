from collections import defaultdict

# This class represents a directed graph using adjacency list representation
class Graph:
    def __init__(self, graph):
        self.graph = graph  # residual graph
        self.ROW = len(graph)
        self.parent = [-1] * self.ROW

    # Using BFS as a search algorithm
    def bfs(self, source, sink):
        visited = [False] * self.ROW
        queue = []
        queue.append(source)
        visited[source] = True

        while queue:
            u = queue.pop(0)

            for ind, val in enumerate(self.graph[u]):
                if visited[ind] == False and val > 0:
                    queue.append(ind)
                    visited[ind] = True
                    self.parent[ind] = u

                    if ind == sink:
                        return True
        return False

    # Ford-Fulkerson Algorithm
    def ford_fulkerson(self, source, sink):
        max_flow = 0

        while self.bfs(source, sink):
            path_flow = float("Inf")
            s = sink

            while s != source:
                path_flow = min(path_flow, self.graph[self.parent[s]][s])
                s = self.parent[s]

            # Adding the path flows
            v = sink
            while v != source:
                u = self.parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = self.parent[v]

            max_flow += path_flow

        return max_flow


# Create a graph given in the above diagram
graph = [[0, 16, 13, 0, 0, 0],
         [0, 0, 10, 12, 0, 0],
         [0, 4, 0, 0, 14, 0],
         [0, 0, 9, 0, 0, 20],
         [0, 0, 0, 7, 0, 4],
         [0, 0, 0, 0, 0, 0]]

g = Graph(graph)

source = 0  # Source
sink = 5    # Sink

print("The maximum possible flow is %d" % g.ford_fulkerson(source, sink))
