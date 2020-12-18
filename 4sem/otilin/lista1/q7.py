#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np


a = np.linspace(0, 1000, 100000)
b0 = 700 - a
b1 = 200 - a
b2i = np.array([600 for i in a])
b3 = np.array([400 for i in a])


plt.xlim(0, 1000)
plt.ylim(0, 1000)

plt.plot(a, b0)
plt.plot(a, b1)
plt.plot(b2i, a)
plt.plot(a, b3)


#plt.show()
plt.savefig("q7.png", dpi=500)
