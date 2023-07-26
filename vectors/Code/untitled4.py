import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

a = np.array([1, 1, 1])
b = np.array([2, 4, 5])
c = np.array([1, 2, 3])

# Calculate the sum of vectors b and c
sum_vector = b + c

# Calculate the unit vector along the sum of vectors b and c
magnitude_sum_vector = np.linalg.norm(sum_vector)
unit_vector = sum_vector / magnitude_sum_vector

i_unit = np.array([1, 0, 0])
j_unit = np.array([0, 1, 0])
k_unit = np.array([0, 0, 1])

# 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Unit vector
ax.quiver(0, 0, 0, *i_unit, color='b', label='i')
ax.quiver(0, 0, 0, *j_unit, color='g', label='j')
ax.quiver(0, 0, 0, *k_unit, color='r', label='k')
ax.quiver(0, 0, 0, *unit_vector, color='purple', label='Unit vector (b+c)')

# Set labels for the axes
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# Set axis limits based on the maximum value of unit vectors
ax.set_xlim([0, 1])
ax.set_ylim([0, 1])
ax.set_zlim([0, 1])

ax.set_aspect('auto')
ax.legend()

plt.show()

