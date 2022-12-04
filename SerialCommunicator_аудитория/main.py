import serial
import time
messages = {b'u': 0,
           b'd': 0,
           b's' : 5}

def get_connects(port):
    ser = serial.Serial(port, timeout=1)
    return ser

def process(ser):
    message = input("Enter command: ")
    message_b = message.encode()
    ser.write(message_b)
    if message[message_b] > 0:
        while ser.in_waiting == message[message_b]:
            time.sleep(0.1)
        data = ser.read(message[message_b])
        data = data.decode()
        print(data)
if name == 'main':
    ser = get_connects('COM4')

    while(True):
        process(ser)