import matplotlib.pyplot as plt 
import numpy as np 
import sys

# read data
data = np.loadtxt(sys.argv[1])


# plot data
fig, axes = plt.subplots(1, 1)
axes.plot(data[:, 1], data[:, 3], '-o', label="Forward")
axes.plot(data[:, 1], data[:, 5], '-s', label="Central")
axes.plot(data[:, 1], data[:, 7], '-d', label="Richardson")
axes.set_xscale("log")
axes.set_yscale("log")
axes.set_xlabel(r"$h$")
axes.set_ylabel(r"Error")

plt.legend()

fig.savefig("fig_python.pdf")



