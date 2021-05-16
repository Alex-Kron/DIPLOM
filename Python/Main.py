import serial
import keyboard
import cv2

connection = False
port = serial.Serial("COM3", 9600)
web = cv2.VideoCapture(1)
#web.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
#web.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)

while not keyboard.is_pressed('Esc'):
    sensor = port.read()
    print(sensor)
    if sensor == b'1':
        ret, img = web.read()
        cv2.imshow('Palm vein', img)
        cv2.waitKey(1)
    else:
        cv2.destroyAllWindows()

port.close()
web.release()
print("Turn off the sensor")
