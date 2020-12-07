import csv
import time
import paho.mqtt.client as mqtt

def on_connect(client,userdata,flags,rc):
    if rc == 0:
        print('connected OK')
    else:
        print('Bad Connection Returned code', rc)


broker = '192.168.43.233'
client = mqtt.Client('multitopic_publisher')

client.on_connect = on_connect
print("Connecting to broker", broker)
client.connect(broker,1883,60)

fileloc = str(input("Lokasi file: "))
filelocation = fileloc.replace("\\", "/")
print("Lokasi berkas: " + filelocation)
filename = str(input("Nama berkas: "))
print(filename)

with open(filelocation + '/' + filename +'.csv', newline = '')as f:
    reader=csv.reader(f)
    data=[tuple(row[1:]) for row in reader]

topik = data[0]
nilai = data[1:8642]

jumlah=len(data)
banyaktopik = len(topik)

l=0

for i in range(jumlah):
    l=0
    for k in nilai:
        for j in range (banyaktopik):
            print(topik[l+j],k[i+j])
            client.publish(topik[l+j],k[i+j])
        time.sleep(0.2) #sampling time
    break
