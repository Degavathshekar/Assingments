import numpy as np
a = np.array([1, 1, 1])
b = np.array([2, 4, -5])
c = np.array([1, 2, 3])

# Calculate the sum of vectors b and c
sum_vector = b + c

# Calculate the unit vector along the sum of vectors b and c
magnitude = np.linalg.norm(sum_vector)
unit_vector = sum_vector / magnitude
result = a@unit_vector
print(result)


