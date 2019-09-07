#import
from ctypes import *
import serial
from time import sleep

# Initialize
old_out = ""
out = ""

# Serial Initialize
ser = serial.Serial("/dev/cu.usbmodem14401",115200)

# Filter Library Initialize
lib = CDLL("XyloStoriesFilter.so")
lib.XyloStoriesFilter.argtypes = [c_int,c_char_p]
lib.XyloStoriesFilter.restype = c_char_p

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
                print("Error")
                checkData = ""

    size = len(inputData)
    out = lib.XyloStoriesFilter(size,inputData)
    print('out = {}'.format(out))
    print('out_old = {}'.format(old_out))
    if out and out != old_out:
        print("Filter OK")
        print(out)
    old_out = out

if __name__ == '__main__':
    print("program start")
    try:
        while 1:
            XyloStories()
    except KeyboardInterrupt:
        print('Program Finish')
        ser.close()
