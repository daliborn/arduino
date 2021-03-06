from serial import Serial, SerialException
import time

# '/dev/cu.usbserial-1410'
location = '/dev/ttyUSB0'
ser = None
try:
    ser = Serial(location, 9600)
except SerialException:
    print('No connection: ' + location)


def write(seconds):
    ardseconds = f"{int(seconds) * 1000}\n"
    print(ardseconds)
    try:
        if ser is not None:
            time.sleep(2)
            # ser.write(b"20000\n")
            ser.write(ardseconds.encode())
    except Exception:
        print('Exception ')
        return ["0", "0", "0"]


def read():
    try:
        if ser is not None and ser.inWaiting() > 0:
            res = ser.readline().decode().rstrip()
            return res.split(',')
        else:
            return ["100", "200", "300"]
    except Exception:
        print('Exception ')
        return ["0", "0", "0"]