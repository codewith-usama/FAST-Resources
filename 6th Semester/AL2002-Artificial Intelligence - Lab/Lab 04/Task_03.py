from queue import Queue

goal_state = [1, 2, 3, 4, 5, 6, 7, 8, 0]

# Define the actions that can be taken
actions = {
    0: [1, 3],
    1: [0, 2, 4],
    2: [1, 5],
    3: [0, 4, 6],
    4: [1, 3, 5, 7],
    5: [2, 4, 8],
    6: [3, 7],
    7: [4, 6, 8],
    8: [5, 7]
}

# Define the depth-first search algorithm


def dfs(initial_state):
    stack = [(initial_state, [])]
    visited = set()

    while stack:
        state, path = stack.pop()

        if state == goal_state:
            return path

        if tuple(state) not in visited:
            visited.add(tuple(state))

            for i, tile in enumerate(state):
                if tile == 0:
                    for action in actions[i]:
                        new_state = state[:]
                        new_state[i], new_state[action] = new_state[action], new_state[i]
                        stack.append((new_state, path + [action]))

    return None

# Define the breadth-first search algorithm


def bfs(initial_state):
    queue = Queue()
    queue.put((initial_state, []))
    visited = set()

    while not queue.empty():
        state, path = queue.get()

        if state == goal_state:
            return path

        if tuple(state) not in visited:
            visited.add(tuple(state))

            for i, tile in enumerate(state):
                if tile == 0:
                    for action in actions[i]:
                        new_state = state[:]
                        new_state[i], new_state[action] = new_state[action], new_state[i]
                        queue.put((new_state, path + [action]))

    return None


# Test the algorithms
initial_state = [2, 8, 3, 1, 6, 4, 7, 0, 5]

print("Initial state:")
print(initial_state)

print("\nDFS solution:")
dfs_solution = dfs(initial_state)
if dfs_solution:
    print(dfs_solution)
else:
    print("No solution found.")

print("\nBFS solution:")
bfs_solution = bfs(initial_state)
if bfs_solution:
    print(bfs_solution)
else:
    print("No solution found.")
