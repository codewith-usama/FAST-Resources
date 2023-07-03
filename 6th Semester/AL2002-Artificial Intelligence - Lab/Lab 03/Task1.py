import math

# Define the coordinates of the reference point
ref_point = (4, 0)

# Define the coordinates of the locations to calculate distance for
locations = [(1, 2), (3, 4), (5, 6)]

# Calculate the distance between the reference point and each location
for loc in locations:
    distance = math.sqrt((loc[0] - ref_point[0]) **
                         2 + (loc[1] - ref_point[1]) ** 2)
    print(f"Distance between {ref_point} and {loc}: {distance}")
