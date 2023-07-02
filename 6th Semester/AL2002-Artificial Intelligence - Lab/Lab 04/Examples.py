# Example 1
from collections import defaultdict
graph = {
    '5': ['3', '7'],
    '3': ['2', '4'],
    '7': ['8'],
    '2': [],
    '4': ['8'],
    '8': []
}
visited = []  # List for visited nodes.
queue = []  # Initialize a queue
def bfs(visited, graph, node):  # function for BFS


    visited.append(node)
    queue.append(node)
    while queue:  # Creating loop to visit each node
        m = queue.pop(0)
        print(m, end=" ")
    for neighbour in graph[m]:
        if neighbour not in visited:
            visited.append(neighbour)
            queue.append(neighbour)
print("Following is the Breadth-First Search")
bfs(visited, graph, '5')


# Example 2
# create the graph
graph,cost = [[] for i in range(8)],{}
# add edge
graph[0].append(1)
graph[0].append(3)
graph[3].append(1)
graph[3].append(6)
graph[3].append(4)
graph[1].append(6)
graph[4].append(2)
graph[4].append(5)
graph[2].append(1)
graph[5].append(2)
graph[5].append(6)
graph[6].append(4)
# add the cost
cost[(0, 1)] = 2
cost[(0, 3)] = 5
cost[(1, 6)] = 1
cost[(3, 1)] = 5
cost[(3, 6)] = 6
cost[(3, 4)] = 2
cost[(2, 1)] = 4
cost[(4, 2)] = 4
cost[(4, 5)] = 3
cost[(5, 2)] = 6
cost[(5, 6)] = 3
cost[(6, 4)] = 7
# goal state
goal = []
# set the goal
# there can be multiple goal states
goal.append(6)
# get the answer
answer = uniform_cost_search(goal, 0)
# print the answer
print("Minimum cost from 0 to 6 is = ",answer[0])


def uniform_cost_search(goal, start):


    # minimum cost upto
    # goal state from starting
    global graph, cost
    answer = []
    # create a priority queue
    queue = []
    # set the answer vector to max value
    for i in range(len(goal)):
        answer.append(10**8)
    # insert the starting index
    queue.append([0, start])
    #  map to store visited node
    visited = {}
    # count
    count = 0
    # while the queue is not empty
    while (len(queue) > 0):
        # get the top element of the
        queue = sorted(queue)
        p = queue[-1]
        # pop the element
        del queue[-1]
        # get the original value
        p[0] *= -1
        # check if the element is part of
        # the goal list
        if (p[1] in goal):
            # get the position
            index = goal.index(p[1])
            # if a new goal is reached
            if (answer[index] == 10**8):
                count += 1
            # if the cost is less
            if (answer[index] > p[0]):
                answer[index] = p[0]
            # pop the element
            del queue[-1]
            queue = sorted(queue)
            if (count == len(goal)):
                return answer
        # check for the non visited nodes
        # which are adjacent to present node
    if (p[1] not in visited):
        for i in range(len(graph[p[1]])):
            # value is multiplied by -1 so that
            # least priority is at the top
            queue.append([(p[0] + cost[(p[1], graph[p[1]][i])]) * -1, graph[p[1]][i]])
        # mark as visited
        visited[p[1]] = 1

    return answer


# Example 3
class Node(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

class BinarySearchTree(object):
    def __init__(self, value):
        self.root = Node(value)
    
    def insert(self, value):
        current = self.root
        while current:
            if value > current.value:
                if current.right is None:
                    current.right = Node(value)
                    break
                else:
                    current = current.right
            else:
                if current.left is None:
                    current.left = Node(value)
                    break
                else:
                    current = current.left
    def Breadth_first_search(self, root):
# """In BFS the Node Values at each level of the Tree are traversed before going to next level"""
        visited = []
        if root:
            visited.append(root)
            print (root.value)
        current = root
        while current:
            if current.left:
                print (current.left.value)
                visited.append(current.left)
            if current.right:
                print (current.right.value)
                visited.append(current.right)
            visited.pop(0)
            if not visited:
                break
            current = visited[0]
t = BinarySearchTree(100)
t.insert(12)
t.insert(92)
t.insert(112)
t.insert(123)
t.insert(2)
t.insert(11)
t.insert(52)
t.insert(3)
t.insert(66)
t.insert(10)
print ("Output of Breadth First search is ") 
t.Breadth_first_search(t.root)


# Example 4
# This class represents a directed graph using adjacency list representation
class Graph:
    def init(self, vertices): #No. of vertices
        self.V = vertices
        # default dictionary to
        # store graphself.graph = defaultdict(list)
    # function to add an edge to graphdef
    # addEdge(self, u, v):
    #     self.graph[u].append(v)


def IDDFS(self, src, target, maxDepth):

    # Repeatedly depth-limit search till the
    # maximum depth
    for i in range(maxDepth):
        if (self.DLS(src, target, i)):
            return True
        return False
# Create a graph given in the
# above diagramg = Graph(7)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 3)
g.addEdge(1, 4)
g.addEdge(2, 5)
g.addEdge(2, 6)
target = 6
maxDepth = 3
src = 0
if g.IDDFS(src, target, maxDepth) == True:
    print("Target is reachable from source within max depth")
else:
    print ("Target is NOT reachable from source within max depth")
