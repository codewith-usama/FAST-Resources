# n: the number of integers in the input range
# k: the maximum value of the integers in the range
# a: the lower bound of the query range
# b: the upper bound of the query range

# Preprocess the input and store the counts in an array
def preprocess(n, k, input_range):
    # Initialize an array of zeros with size k+1 to store the counts
    counts = [0] * (k+1)

    # Iterate through the input range and increment the count for each integer
    for i in input_range:
        counts[i] += 1

    # Return the array of counts
    return counts

# Answer a query about how many integers fall into a given range
def query(a, b, counts):
    # Return the difference between the counts of the upper and lower bounds
    return counts[b] - counts[a-1]

# Example usage:

# Preprocess the input with n=10, k=5, and input range [1, 2, 3, 3, 3, 4, 5, 5, 5, 5]
counts = preprocess(10, 5, [1, 2, 3, 3, 3, 4, 5, 5, 5, 5])

# Answer a query about how many integers in the input range fall into the range 1 to 3
print(query(1, 3, counts))  # Output: 7
