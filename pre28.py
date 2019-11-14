import os
import numpy as np
import matplotlib.pyplot as plt

plt.figure()
data = np.loadtxt('pre28.dat')
plt.plot(data[:,1], data[:,2])

plt.axis('square')
plt.xlim([-25, 25])
plt.ylim([-25, 25])
plt.xlabel('X')
plt.ylabel('Y')
plt.savefig('friccion.png')