from itertools import permutations
import sys


def tsp(dist):
    n = len(dist)
    cities = list(range(n))
    min_dist = sys.maxsize
    for perm in permutations(cities):
        dist_sum = 0
        for i in range(n):
            dist_sum += dist[perm[i]][perm[(i + 1) % n]]
        min_dist = min(min_dist, dist_sum)
    return min_dist


if __name__ == '__main__':
    dist = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]
    print("Shortest distance:", tsp(dist))
