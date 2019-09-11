#import
from ctypes import *
import serial
import socket
from time import sleep

# Initialize
HOST = '127.0.0.1'
PORT = 9999
old_out = ""
out = ""
sound_count = 0

# Serial Initialize
ser = serial.Serial("/dev/cu.usbmodem14401",115200)

# Socket Initialize
client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

# Filter Library Initialize
lib = CDLL("XyloStoriesFilter.so")
lib.XyloStoriesFilter.argtypes = [c_int,c_char_p]
lib.XyloStoriesFilter.restype = c_char_p

def ServerConnect_local():
    client.connect((HOST,PORT))
    print("Server Connected")

def XyloStories():
    global old_out
    global sound_count
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
    print('out = {}'.format(out))
    print('out_old = {}'.format(old_out))

    if out:
        if out is not old_out or sound_count == 10:
            print("Filter OK")
            send = out[0]
            sound_count = 0
        else:
            send = '\n'
            sound_count = sound_count + 1
    else:
        send = '\n'

    client.send(send.encode('utf-8'))
    old_out = out


if __name__ == '__main__':
    print("program start")
    try:
        ServerConnect_local()
        while 1:
            XyloStories()
    except (KeyboardInterrupt, socket.error):
        print('Program Finish')
        ser.close()
        client.close()
