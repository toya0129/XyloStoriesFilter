# import
import numpy as np
import matplotlib.pyplot as plt
import librosa
import librosa.display

class DrawGraph:
    rate = 5000

    def __Initialize(self, data):
        array = np.array(data)

        #正規化
        # inarray = inarray / 255 * 65535 - 32768
        array = array / 32768
        # inarray = inarray / 255

        return array

    def __Plot(self, x_plot, y_plot):
        plt.plot(x_plot, y_plot)
        plt.show()


    # 音量グラフ
    # 縦（振幅）　横（周波数）
    def VolumeGraphPlot(self, data):
        plot_data = self.__Initialize(data)

        # 時間軸作成
        time = np.arange(0, plot_data.shape[0] / self.rate, 1 / self.rate)

        self.__Plot(time, plot_data)

    # 周波数成分グラフ
    # 縦（振幅）　横（周波数）
    def FreqGraphPlot(self, data, start_hz, end_hz):
        plot_data = self.__Initialize(data)

        # フーリエ変換
        fft_data = np.abs(np.fft.fft(plot_data))

        # 時間軸作成
        freq_list = np.fft.fftfreq(plot_data.shape[0], d = 1.0 / self.rate)

        plt.xlim(start_hz, end_hz)
        self.__Plot(freq_list, fft_data)


    # スペクトログラフ
    # 縦（Hz） 横（時間）
    def SpecGraphPlot(self, data):
        plot_data = self.__Initialize(data)

        # フレーム長
        fft_size = 1024
        # フレームシフト長
        hop_length = int(fft_size / 4)

        # フーリエ変換
        amplitude = np.abs(librosa.core.stft(plot_data, n_fft = fft_size, hop_length = hop_length))

        log_power = librosa.core.amplitude_to_db(amplitude)

        librosa.display.specshow(log_power, sr = rate, hop_length = hop_length, x_axis = 'time', y_axis = 'hz', cmap = 'magma')
        plt.colorbar(format='%+2.0f dB')
        plt.show()


class RealTimeGraph:
    rate = 5000
    line = []
    graph_label = []
    count = 0

    def __init__(self, label):
        fig = plt.figure()
        self.graph_label = label
        self.line = [[]] * len(self.graph_label)
        for i in range(len(self.graph_label)):
            j = i + 1
            self.line[i] = fig.add_subplot(2, 4, j)
            self.line[i].set_xlim(0,3000)

    def MultiPlot(self, data, num, mode):
        array = np.array(data)
        array = array / 32768

        if mode == "volume":
            time = np.arange(0, array.shape[0] / self.rate, 1 / self.rate)
            self.line[num].plot(time, array, color='blue')

        elif mode == "freq":
            fft_data = np.abs(np.fft.fft(array))
            freq_list = np.fft.fftfreq(array.shape[0], d = 1.0 / self.rate)
            self.line[num].plot(freq_list, fft_data, color='blue', label = self.graph_label[num])
            self.line[num].legend(loc = 'upper right')


        self.count += 1

        if self.count == len(self.graph_label):
            plt.pause(0.000001)
            for i in range(len(self.graph_label)):
                self.line[i].cla()
                if mode == "freq":
                    self.line[i].set_xlim(0,3000)
            self.count = 0
