#import
from ctypes import *
# import ctypes.util
# from numpy.ctypeslib import ndpointer
# import numpy as np
import serial
# import re

# Initialize
size = 0
out = ""

# Serial Initialize
ser = serial.Serial("/dev/cu.usbmodem14401",9600)

# Filter Library Initialize
lib = CDLL("XyloStoriesFilter.so")
lib.XyloStoriesFilter.argtypes = [c_int,c_char_p]
lib.XyloStoriesFilter.restype = c_char_p

def XyloStories():
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
                checkData = ""

    size = len(inputData)
    out = lib.XyloStoriesFilter(size,inputData)
    print(out)


if __name__ == '__main__':
    print("program start")
    while 1:
        XyloStories()
