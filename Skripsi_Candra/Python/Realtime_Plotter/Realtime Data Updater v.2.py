## REALTIME DATA UPDATER for REALTIME DATA PLOTTER ##
## 

"""
Created on Mon Aug 17 10:00:00 2020

@author: candra wardaya
"""

print("=========================")
print("Real-time Data Updater v.2")
print("=========================")

#import
import pandas as pd
import csv
import time
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from tqdm import tqdm

#input
#print("File location (example: H:\Python Plotter\Opened Data)")
fileloc = str(input("[File location (ex. C:\\folder)]: "))
filelocation = fileloc.replace("\\", "/")
filename = str(input("[File name (without .csv)     ]: "))

print("")

#resaving data opened
fieldnames = ["PV", "OP"]
with open(filename+'_cache.csv', 'w') as f:
    csv_writer = csv.DictWriter(f, fieldnames = fieldnames)
    csv_writer.writeheader()

print("")
print("Please open 'Real-time Data Plotter.py' immediately after the instruction below!")
print("")

while True:
    decision = str(input("[Continue?(anykey) ]: "))
    if decision == 'y' or 'Y':
        break

for i in tqdm(range(10)):
    time.sleep(0.5)
    pass

#output
print("PV | OP")
i = 0
while True:
    i += 1
    data = pd.read_csv(filelocation + '/' + filename + '.csv')
    op = str(data["OP"][i])
    pv = str(data["PV"][i])
    with open(filename+'_cache.csv', 'a') as f:
        csv_writer = csv.DictWriter(f, fieldnames = fieldnames)
        info = {"PV":pv, "OP":op}
        csv_writer.writerow(info)
        print(pv+"  "+op)
    #time delay
    time.sleep(0.3)
