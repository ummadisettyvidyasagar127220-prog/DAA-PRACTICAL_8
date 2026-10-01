class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []

        self.graph[u].append(v)
        self.graph[v].append(u)   

    def dfs(self, start):
        visited = set()

        print("DFS Traversal:", end=" ")
        self.dfs_recursive(start, visited)
        print()

    def dfs_recursive(self, vertex, visited):
        visited.add(vertex)
        print(vertex, end=" ")

        for neighbour in self.graph[vertex]:
            if neighbour not in visited:
                self.dfs_recursive(neighbour, visited)

g = Graph()

g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(1, 4)
g.add_edge(2, 5)
g.add_edge(2, 6)

print("Graph:")
for vertex in g.graph:
    print(vertex, "->", g.graph[vertex])

g.dfs(0)
