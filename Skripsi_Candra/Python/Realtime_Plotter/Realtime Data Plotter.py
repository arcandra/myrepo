## REALTIME DATA PLOTTER ##
## 

"""
Created on Mon Aug 17 10:00:00 2020

@author: candra wardaya
"""

print("=========================")
print("Real-time Data Plotter v.1")
print("=========================")

#import
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import pandas as pd
import csv

#retrieve
file = str(input("[File name]: "))

#animate
def animate(i):
    data2 = pd.read_csv(file+'_cache.csv')
    x = data2["OP"]
    y = data2["PV"]
    
    plt.cla()
    plt.plot(x,y)
    plt.ylabel("PV")
    plt.xlabel("OP")

ani = FuncAnimation(plt.gcf(), animate, interval = 1000)

plt.tight_layout()
plt.show()

#exec(open('Realtime Data Updater.py').read())
