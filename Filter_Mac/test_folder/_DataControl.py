import serial

class DataControl():
    input_data = []
    ser = ""

    def __init__(self, usb_root, bps):
        self.ser = serial.Serial(usb_root, bps)

    def SerialDisconnect(self):
        self.ser.close()
        print("Serial Disconnected")

    def InputData(self):
        check_data = ""

        while len(self.input_data) < 300:
            if self.ser.in_waiting:
                check_data = self.ser.readline()
                try:
                    self.input_data.append(float(check_data))
                except:
                    print('Error')
                    checkData = ""

        XyloStoriesFilter().XyloStoriesFilter(self.input_data)
        del self.input_data[:100]
