#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np


x = np.linspace(0, 10, 1000)
y0 = 7 - x
y1 = 10 - x
y2 = 12 - 2*x
y3 = (12 - x)/2


plt.xlim(0, 12)
plt.ylim(0, 12)

plt.plot(x, y0, label="7 - x")
plt.plot(x, y1, label="10 - x")
plt.plot(x, y2, label="12 - 2*x")
plt.plot(x, y3, label="(12-x)/2")


#plt.show()
plt.savefig("q5.png", dpi=500)
