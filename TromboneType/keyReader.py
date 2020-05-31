import serial
ser = serial.Serial()
ser.port = 'COM4'
ser.open()
ser.readline()

output_file = open("output.txt","w")


while True:
    try:
        ser_bytes = ser.readline().strip().decode("ascii")

        print(ser_bytes) 

        if ser_bytes[0] == 1:
            break
    except:
        print("Keyboard Interrupt")
        break

output_file.write(ser_bytes[2])