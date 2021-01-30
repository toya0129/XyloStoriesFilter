## impot
import sys
# キャッシュファイルを作成させない
sys.dont_write_bytecode = True

import threading

import numpy as np
from ctypes import *
import ctypes.util
from numpy.ctypeslib import ndpointer

# 自作ファイルimport
from DataControl import *
# from SocketClient import *

class XyloStoriesFilter():
    # Filterのライブラリ読み込み
    lib = np.ctypeslib.load_library("test.so",".")
    _DOUBLE_P = ndpointer(dtype=np.float64)
    lib.XyloStoriesFilter.argtypes = [_DOUBLE_P, c_int32, c_int32, _DOUBLE_P]
    lib.XyloStoriesFilter.restype = None

    # 変数
    max = [0] * 8
    label = ["c", "d","e","f","g","a","b","c2"]

    def XyloStoriesFilter(self, data):
        sub_thread = threading.Thread(target=__FilterThread, args=(data, ))
        sub_thread.start()

    def GetterMax(self):
        for i in range(len(self.max)):
            print('{i} = {max}'.format(i = i, max = self.max[i]))

    def __FilterThread(self, data):
        results = [0] * 8

        add_data = [0] * 8
        max_index = 0

        for i in range(8):
            results[i] = __Filter(data, i)

        # 判別
        for i in range(8):
            for d in results[i]:
                add_data[i] += d

        for i in range(1,8):
            if add_data[max_index] < add_data[i]:
                max_index = i

        if add_data[max_index] > 0.4:
            print('oto = {}'.format(label[max_index]))
            # SocketClient().SendData(data_format)

    def __Filter(self, data, num):
        trigger = 0
        data_format = num + 1

        # C言語用に変数型を変更
        array = np.array(data)
        out = np.zeros_like(array)
        num_c = ctypes.c_int(num)
        size = len(array)
        size = ctypes.c_int(size)

        self.lib.XyloStoriesFilter(array, num_c, size, out)

        # 周波数成分
        outarray = np.array(out)
        outarray = outarray / 32768
        outarray = np.abs(np.fft.fft(outarray))

        return outarray


if __name__ == '__main__':
    print("Program Start")

    try:
        # SocketClient().ServerConnectLocal()

        while 1:
            DataControl().InputData()

    except (KeyboardInterrupt):
        DataControl().SerialDisconnect()
        # SocketClient().Disconnected()

        XyloStoriesFilter().GetterMax()

        print("Program Finish")
