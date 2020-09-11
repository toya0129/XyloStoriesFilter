#import
from ctypes import *
import ctypes
import serial
import RPi.GPIO as GPIO
from time import sleep

# Initialize
old_out = ""
out = ""
gpioPi = [2,3,4,17,27,22,10,9]

# Serial Initialize
ser = serial.Serial("/dev/serial0",115200)

# Filter Library Initialize
lib = CDLL("./XyloStoriesFilter.so")
#lib = ctypes.cdll.LoadLibrary("./XyloStoriesFilter.so")
lib.XyloStoriesFilter.argtypes = [c_int,c_char_p]
lib.XyloStoriesFilter.restype = c_char_p

# GPIO Initialize
def GPIOSetup():
    i = 0
    GPIO.setmode(GPIO.BCM)
    for i in range(8):
        GPIO.setup(gpioPi[i],GPIO.OUT)
        GPIO.output(gpioPi[i],GPIO.LOW)
        sleep(0.001)

def XyloStories():
    global old_out
    size = 0
    readData = 0
    checkData = ""
    inputData = ""
    while readData < 100:
        if ser.in_waiting:
            checkData = ser.readline()
            try:
                inputData = inputData + checkData
                readData += 1
            except:
                print('Error')
                checkData = ""
    
    size = len(inputData)
    out = lib.XyloStoriesFilter(size,inputData)
    print('out = ' + out)
    print('old_out = ' + old_out)
    if out and out != old_out:
        print('Filter OK')
        SendGPIO(out[0])
    old_out = out
        
def SendGPIO(sound):
    sound = int(sound)
    print('sound = ' +  str(sound))
    GPIO.output(gpioPi[sound - 1],GPIO.HIGH)
    sleep(0.5)
    GPIO.output(gpioPi[sound - 1],GPIO.LOW )
    sleep(0.001)
    

if __name__ == '__main__':
    print('Program Start')
    try:
        GPIOSetup()
        while 1:
            XyloStories()
    except KeyboardInterrupt:
        print('Program Finish')
        GPIO.clearnup()
        ser.close()
