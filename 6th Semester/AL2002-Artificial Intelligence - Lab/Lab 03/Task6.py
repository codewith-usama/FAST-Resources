import heapq


def dijkstra(graph, start, end):
    # Initialize distances and visited nodes
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    visited = set()
    # Use a heap to track the nodes with the smallest tentative distance
    heap = [(0, start)]
    while heap:
        # Get the node with the smallest tentative distance
        (dist, node) = heapq.heappop(heap)
        # If we have already visited this node, skip it
        if node in visited:
            continue
        # Mark the node as visited
        visited.add(node)
        # Update the distances of the neighboring nodes
        for neighbor, cost in graph[node].items():
            new_distance = distances[node] + cost
            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                # Add the neighbor to the heap with the updated distance
                heapq.heappush(heap, (new_distance, neighbor))
    # Return the shortest distance and path from start to end
    path = []
    node = end
    while node != start:
        path.append(node)
        node = min(graph[node], key=lambda x: distances[x] + graph[node][x])
    path.append(start)
    path.reverse()
    return distances[end], path


# Example usage
graph = {
    'A': {'B': 5, 'C': 2},
    'B': {'A': 5, 'C': 1, 'D': 3},
    'C': {'A': 2, 'B': 1, 'D': 1},
    'D': {'B': 3, 'C': 1, 'E': 4},
    'E': {'D': 4}
}
start = 'A'
end = 'E'
distance, path = dijkstra(graph, start, end)
print(f"Shortest distance from {start} to {end} is {distance}")
print(f"Shortest path is {' -> '.join(path)}")
