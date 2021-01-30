## import
import sys
sys.dont_write_bytecode = True

import serial

import socket

# Thread
import threading
import time

import numpy as np

from ctypes import *
import ctypes.util
from numpy.ctypeslib import ndpointer
from numba.decorators import jit as optional_jit

# グラフ描画
from DrawGraph import *

trigger = 1
test_li = list()

# Initialize
input_data = list()
rate = 5000

# out = []

max = [0] * 8
max_add = [0] * 8

label = ["c", "d","e","f","g","a","b","c2"]
real = RealTimeGraph(label)

# Socket Initialize
client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
HOST = '127.0.0.1'
PORT = 9999

lib = np.ctypeslib.load_library("test.so",".")
_DOUBLE_P = ndpointer(dtype=np.float64)
lib.XyloStoriesFilter.argtypes = [_DOUBLE_P, c_int32, c_int32, _DOUBLE_P]
lib.XyloStoriesFilter.restype = None

# Serial Initialize
ser = serial.Serial("/dev/cu.usbmodem14401",115200)

# main
def InputData():
    global input_data
    global test_li

    input_data = list()
    check_data = ""

    while len(input_data) < 300:
        if ser.in_waiting:
            checkData = ser.readline()
            try:
                input_data.append(float(checkData))
            except:
                print('Error')
                checkData = ""
    # print("finish")

    # new version
    sub_thread = threading.Thread(target=FilterThread, args=(input_data, ))
    sub_thread.start()
    test_li.append(sub_thread)

    # グラフプロット時
    # old version
    # GraphPlot(input_data)

    del input_data[:100]

# filter control thread
def FilterThread(data):
    try:
        global max
        global max_add

        results = [0] * 8

        add_data = [0] * 8
        max_index = 0

        th = [None] * 8

        # for i in range(8):
        #     results[i] = Filter(data, i)

        for i in range(8):
            th[i] = threading.Thread(target=__Filter, args=(data, i, results))
            th[i].start()

        for j in range(8):
            th[i].join()

        # Judgment
        # 足し合わせる
        for i in range(8):
            for data in results[i]:
                add_data[i] += data
        # 数値が大きい音を判別
        for i in range(1,8):
            if add_data[max_index] < add_data[i]:
                max_index = i
        # 無音時ではない
        if add_data[max_index] > 0.4:
            # for data in results[max_index]:
            #     if data > 0.07:
            print('oto = {}'.format(label[max_index]))
            SendData(max_index + 1)
                    # break
        else:
            # print("none")
            SendData(99)

        # 記録用
        for i in range(8):
            if max_add[i] < add_data[i]:
                max_add[i] = add_data[i]
            for d in results[i]:
                if max[i] < d:
                    max[i] = d
    except KeyboardInterrupt:
        print("wwww")

# thread
def Filter(input_data, num):
    test = 0
    array = np.array(input_data)
    out = np.zeros_like(array)

    num_c = ctypes.c_int(num)
    size = len(array)
    size = ctypes.c_int(size)

    lib.XyloStoriesFilter(array, num_c, size, out)

    outarray = np.array(out)
    outarray = outarray / 32768
    outarray = np.abs(np.fft.fft(outarray))

    return outarray

    # # Graph Plot
    # real.MultiPlot(data, num, "volume")
    # real.MultiPlot(data, num, "freq")
    # DrawGraph().VolumeGraphPlot(data)
    # DrawGraph().FreqGraphPlot(data, 0, 3000)
    # DrawGraph().SpecGraphPlot(data)

def __Filter(input_data, num, aaa):
    test = 0
    array = np.array(input_data)
    out = np.zeros_like(array)

    num_c = ctypes.c_int(num)
    size = len(array)
    size = ctypes.c_int(size)

    lib.XyloStoriesFilter(array, num_c, size, out)

    outarray = np.array(out)
    outarray = outarray / 32768
    outarray = np.abs(np.fft.fft(outarray))

    aaa[num] = outarray

# データ送信用
def SendData(data):
    try:
        if data != 99:
            send = str(data) + "\n"
        else:
            send = '\n'
    except:
        send = '\n'

    client.send(send.encode('utf-8'))


# グラフプロット用
def GraphPlot(data):
    # global max_a

    # r = [0] * 8

    for i in range(8):
        # r[i] = Plot(data, i)

        ## old version
        thread = threading.Thread(target=Plot, args=(data, i))
        thread.start()
        test_li.append(thread)

    # for i in range(8):
    #     for j in r[i]:
    #         if max_a[i] < j:
    #             max_a[i] = j


def Plot(input_data, num):
    global out
    global real

    array = np.array(input_data)
    out = np.zeros_like(array)

    # tp = np.uintp
    # mpp = (array.__array_interface__['data'][0] + np.arange(array.shape[0])*array.strides[0]).astype(tp)

    num_c = ctypes.c_int(num)
    size = len(array)
    size = ctypes.c_int(size)

    lib.XyloStoriesFilter(array, num_c, size, out)

    outarray = np.array(out)
    outarray = outarray / 32768
    outarray = np.abs(np.fft.fft(outarray))

    # return outarray

    ## Graph Plot
    # real.MultiPlot(data, num, "volume")
    # real.MultiPlot(data, num, "freq")
    # DrawGraph().VolumeGraphPlot(data)
    # DrawGraph().FreqGraphPlot(data, 0, 3000)
    # DrawGraph().SpecGraphPlot(data)

    #記録用
    for i in outarray:
        if max[num] < i:
            max[num] = i

def TimerThread():
    global trigger
    time.sleep(5)
    trigger = 0

def ServerConnect_local():
    client.connect((HOST,PORT))
    print("Server Connected")

if __name__ == '__main__':
    print("program start")
    # thread = threading.Thread(target=TimerThread)
    # thread.start()

    try:
        ServerConnect_local()
        while 1:
        # while trigger == 1:
            InputData()

        print("finish")

    except (KeyboardInterrupt):
        print("forced termination")

    finally:
        for li in test_li:
            li.join()

        print("program end")

        for i in range(8):
            print('{label} : max = {max} : max_add = {add}'.format(label=label[i], max=max[i], add=max_add[i]))

        ser.close()
        client.close()
