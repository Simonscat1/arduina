import serial
import time

messages = {
    b'u': 0,
    b'd': 0,
    b's': 1
}


def get_connection(port):
    ser = serial.Serial(port, timeout=1)
    return ser


def process(ser):
    message = input('Enter command: ')
    message_b = message.encode()
    ser.write(message_b)
    if messages[message_b] > 0:
        while ser.in_waiting != messages[message_b]:
            time.sleep(0.1)
            print('waiting')
        data = ser.read(messages[message_b])
        #data = data.decode()
        print(ord(data)*4)


if __name__ == '__main__':
    ser = get_connection('/dev/ttyUSB0')
    while True:
        process(ser)
