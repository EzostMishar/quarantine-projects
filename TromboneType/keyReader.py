import serial
ser = serial.Serial()
ser.port = 'COM4'
ser.open()
ser.readline()

while True:
    try:
        ser_bytes = ser.readline().strip().decode("ascii")

        print(ser_bytes) 
    except:
        print("Keyboard Interrupt")
        break