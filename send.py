import time
import serial

ser = serial.Serial(
    port='/dev/ttyS0',
    baudrate=115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)

while 1:
    ser.write('0x7E','0x7E','0x00','0x0A','0x01','0x01','0x00','0xFF','0xFF','0x00','0x31','0x30','0x30','0x8B');

    time.sleep(1)