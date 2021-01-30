## import
import sys
sys.dont_write_bytecode = True

import numpy as np

from ctypes import *
import ctypes.util
from numpy.ctypeslib import ndpointer
from numba.decorators import jit as optional_jit

# Thread
import threading

# 自作ライブラリ
from SerialCommunication import *
from SocketClient import *


# グローバル変数
serial_root = "/dev/cu.usbmodem14401"
serial_bps = 115200

socket_host = '127.0.0.1'
socket_port = 9999

sub_thread = list()
label = ["c","d","e","f","g","a","b","c2"]

class XyloStories():
    lib = np.ctypeslib.load_library("test.so",".")
    _DOUBLE_P = ndpointer(dtype=np.float64)
    lib.XyloStoriesFilter.argtypes = [_DOUBLE_P, c_int32, c_int32, _DOUBLE_P]
    lib.XyloStoriesFilter.restype = None

    flag = 0

    def XyloStories(self, data, socket):
        global sub_thread

        filter_thread = threading.Thread(target=self.__FilterThread, args=(data, socket))
        filter_thread.start()

        sub_thread.append(filter_thread)

    def __FilterThread(self, data, socket):
        results = [0] * 8

        add_data = [0] * 8
        max_index = 0

        # シングルスレッド
        for i in range(8):
            results[i] = self.__Filter(data, i)

        # マルチスレッド
        # th = [None] * 8
        # for i in range(8):
        #     th[i] = threading.Thread(target=__Filter, args=(data, i, results))
        #     th[i].start()
        # for i in range(8):
        #     th[i].join()

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
            for data in results[max_index]:
                if data > 0.07:
                    print('oto = {}'.format(label[max_index]))
                    socket.SendData(max_index + 1)
                    break
        else:
            socket.SendData("none")

    # シングルスレッド用
    def __Filter(self, input_data, num):
        array = np.array(input_data)
        out = np.zeros_like(array)

        num_c = ctypes.c_int(num)
        size = len(array)
        size = ctypes.c_int(size)

        self.lib.XyloStoriesFilter(array, num_c, size, out)

        outarray = np.array(out)
        outarray = outarray / 32768
        outarray = np.abs(np.fft.fft(outarray))

        return outarray

    # マルチスレッド用
    # def __Filter(self, input_data, num, out):
    #     array = np.array(input_data)
    #     out = np.zeros_like(array)
    #
    #     num_c = ctypes.c_int(num)
    #     size = len(array)
    #     size = ctypes.c_int(size)
    #
    #     self.lib.XyloStoriesFilter(array, num_c, size, out)
    #
    #     outarray = np.array(out)
    #     outarray = outarray / 32768
    #     outarray = np.abs(np.fft.fft(outarray))
    #
    #     out = outarray

    # def EndFlagCheck():
    #     if self.flag == 1:
    #         raise KeyboardInterrupt
    #
    # def FlagChange():
    #     self.flag = 1

if __name__ == '__main__':
    print("Program Start")

    try:
        # シリアル通信の接続
        serial_communication = SerialCommunication(serial_root, serial_bps)
        # ソケット通信の接続
        socket_client = SocketClient(socket_host, socket_port)

        while 1:
            # データの取得
            data = serial_communication.InputData()

            # フィルター制御
            XyloStories().XyloStories(data, socket_client)

            # データの削除
            serial_communication.DelInputData()

            # サーバーの状態確認
            socket_client.CheckServer()

            # Flag Check
            # XyloStories().EndFlagCheck()

    except KeyboardInterrupt:
        print("--- Forced Termination ---")
    except serial.serialutil.SerialException:
        print("--- Please Connect Serial Port ---")
    except ConnectionRefusedError:
        print("--- Please Start the Socket Server ---")
    finally:
        for th in sub_thread:
            th.join()

        print("Program End")
