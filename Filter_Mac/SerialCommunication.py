import serial

class SerialCommunication():
    input_data = []
    ser = ""

    def __init__(self, usb_root, bps):
        self.ser = serial.Serial(usb_root, bps)
        print("Serial Connected")

    def __del__(self):
        try:
            self.ser.close()
            print("Serial Disconnected")
        except AttributeError:
            pass

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

        return self.input_data

    def DelInputData(self):
        del self.input_data[:100]
