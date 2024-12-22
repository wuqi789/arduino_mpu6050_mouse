import serial
from serial import Serial
from pynput.mouse import Button, Controller

mouse = Controller()
try:
    ser = serial.Serial('COM5', baudrate=9600)
    while 1:
        dump = ser.readline()
        dump = str(dump)
        dump = dump[2:-5]
        data = dump.split(
            ',')
        print(data)
        if data[0] == "DATAL":
            mouse.move(int(data[1]),
                       int(data[2]))
        # if data[
        #     0] == "DATAB":
        #     if data[1] == 'L':
        #         mouse.press(Button.left)
        #         mouse.release(Button.left)
        #     if data[1] == 'R':
        #         mouse.press(Button.right)
        #         mouse.release(Button.right)
except:
    print("Mouse not found or disconnected.")
    k = input("Press any key to exit.")