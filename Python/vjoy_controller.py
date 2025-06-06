import serial
import pyvjoy

arduino = serial.Serial('COM3', 9600, timeout=1)
j = pyvjoy.VJoyDevice(1)

while True:
    line = arduino.readline().decode().strip()
    if line:
        try:
            x, y, b1, b2, b3, b4 = map(int, line.split(','))

            j.data.wAxisX = x
            j.data.wAxisY = y

            j.set_button(1, b1)
            j.set_button(2, b2)
            j.set_button(3, b3)
            j.set_button(4, b4)

            j.update()
        except ValueError:
            continue
