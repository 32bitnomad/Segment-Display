import psutil
import serial

import time

ser = serial.Serial(
    port="COM12", baudrate=153600, bytesize=8, timeout=10, stopbits=serial.STOPBITS_ONE
)

while(1):
    try:
        cpu = psutil.cpu_percent(interval=None)
        print('The CPU usage is: ', cpu)
        ser.write(("C:"+str(cpu)+"\n").encode())
        time.sleep(0.2)
        
        ram = psutil.virtual_memory()[2]
        print('RAM memory % used:', ram)
        ser.write(("R:"+str(int(ram))+"\n").encode())
        time.sleep(0.2)
        
        print('battery  % :',psutil.sensors_battery()[0])
        ser.write(("B:"+str((psutil.sensors_battery()[0]))+"\n").encode())
        time.sleep(0.2)
        print('battery plug % :',psutil.sensors_battery()[2])
        ser.write(("P:"+str(int((psutil.sensors_battery()[2])))+"\n").encode())
        time.sleep(1)
    except:
        print("An error occurred:", e)
        time.sleep(1)