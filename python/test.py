import matplotlib.pyplot as plt
import numpy as np
# Generate a random number, you can refer your data values also
data = np.random.rand(4, 2)
rows = list('1234')  # rows categories
columns = list('MF')  # column categories
fig, ax = plt.subplots()
# Advance color controls
ax.pcolor(data, cmap=plt.cm.Reds, edgecolors='k')
ax.set_xticks(np.arange(0, 2)+0.5)
ax.set_yticks(np.arange(0, 4)+0.5)
# Here we position the tick labels for x and y axis
ax.xaxis.tick_bottom()
ax.yaxis.tick_left()
# Values against each labels
ax.set_xticklabels(columns, minor=False, fontsize=20)
ax.set_yticklabels(rows, minor=False, fontsize=20)
plt.show()
test
