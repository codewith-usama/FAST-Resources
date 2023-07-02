# DFS on Tree
# Define the tree as a nested list
tree = ['A', ['B', ['D', [], []], ['E', [], []]], ['C', ['F', [], ['H', [], []]], ['G', [], []]]]

# Define the depth-first search algorithm
def dfs(tree, visited=set()):
    if tree:
        root, left, right = tree
        visited.add(root)
        print(root, end=' ')
        dfs(left, visited)
        dfs(right, visited)

# Test the algorithm
dfs(tree)


# DFS on Graph
# Define the graph as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': [],
    'E': ['F'],
    'F': ['H'],
    'G': [],
    'H': []
}

# Define the depth-first search algorithm


def dfs(graph, start, visited=set()):
    visited.add(start)
    print(start, end=' ')

    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)


# Test the algorithm
dfs(graph, 'A')
