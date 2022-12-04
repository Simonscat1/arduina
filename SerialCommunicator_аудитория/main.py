import serial
import time

messages = {
    b'u':0,
    b'd':0,
    b'o':5
}
def get_connection(port):
    ser = serial.Serial(port, timeout=1)
    return ser

def progress(port):
    ser = get_connection(port)
    message = input("Enter command")
    messageb = message.encode()
    ser.write(messageb)
    if messages[messageb] > 0 :
        while ser.in_waiting != messages[messageb]:
            time.sleep(0.1)
            data = ser.read(messages[messageb])
            print(data)


if __name__ == '__main__':
    while True:
        progress('/dev/cu.usbmodem142301')