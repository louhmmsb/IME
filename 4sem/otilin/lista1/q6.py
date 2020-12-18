#!/usr/bin/env python3

#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np


a = np.linspace(0, 10, 1000)
b0 = 3 - a
b1 = 8 - 2*a
b2 = 2*a

plt.xlim(0, 8)
plt.ylim(0, 8)

plt.plot(a, b0)
plt.plot(a, b1)
plt.plot(a, b2)


#plt.show()
plt.savefig("q6.png", dpi=500)
