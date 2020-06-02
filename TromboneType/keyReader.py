import serial
ser = serial.Serial()
ser.port = 'COM4'
ser.open()
ser.readline()
fout = open("output.txt","w+")

while True:
    try:
        ser_bytes = ser.readline().strip().decode("ascii")

        print(ser_bytes) 

        if ser_bytes[0] == '1':
            fout.write(ser_bytes[2])
    except:
        print("Keyboard Interrupt")
        break

fout.close()