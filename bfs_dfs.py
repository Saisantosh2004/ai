from collections import defaultdict, deque

# Function to build the graph from edges
def build_graph(edges):
    graph = defaultdict(list)
    for edge in edges:
        u, v = edge
        graph[u].append(v)
        graph[v].append(u)  # Uncomment this line if the graph is undirected
    return graph

# BFS implementation
def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)

    while queue:
        vertex = queue.popleft()
        print(vertex, end=" ")

        for neighbor in graph[vertex]:
            if neighbor not in visited:
                queue.append(neighbor)
                visited.add(neighbor)

# DFS implementation
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start, end=" ")

    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Example edges (format: (node1, node2))
edges = [(1, 2), (1, 3), (2, 4), (2, 5), (3, 6), (3, 7)]

# Build the graph from edges
graph = build_graph(edges)

# Input the starting node for traversals
start_node = int(input("Enter the starting node for traversals: "))

print("BFS traversal:")
bfs(graph, start_node)
print("\nDFS traversal:")
dfs(graph, start_node)
