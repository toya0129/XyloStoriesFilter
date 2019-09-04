#import
from ctypes import *
import ctypes
import serial
import RPi.GPIO as GPIO
from time import sleep

# Initialize
out = ""
gpioPi = [2,3,4,17,27,22,10,9]

# Serial Initialize
ser = serial.Serial("/dev/serial0",9600)

# Filter Library Initialize
lib = CDLL("./XyloStoriesFilter.so")
#lib = ctypes.cdll.LoadLibrary("./XyloStoriesFilter.so")
lib.XyloStoriesFilter.argtypes = [c_int,c_char_p]
lib.XyloStoriesFilter.restype = c_char_p

# GPIO Initialize
def GPIOSetup():
    global gpioPi
    i = 0

    GPIO.setmode(GPIO.BCM)
    for i in range(8):
        GPIO.setup(gpioPi[i],GPIO.OUT)
        GPIO.output(gpioPi[i],GPIO.LOW)
        sleep(0.001)

def XyloStories():
    global out
    global gpioPi
    
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
    if out:
        print('Filter OK')
        SendGPIO(out[0])
        
        
def SendGPIO(sound):
    sound = int(sound)
    print('sound = ' +  str(sound))
    GPIO.output(gpioPi[sound - 1],GPIO.HIGH)
    sleep(1)
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
