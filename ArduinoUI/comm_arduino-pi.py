import serial
import time

serial_comm = serial.Serial('COM3', 9600)
serial_comm.timeout = 1

loop = True
while loop:
    buttonval = serial_comm.readline().decode('ascii')
    print(buttonval)
    if buttonval == "button_forward_value":
        i = input("end program (yes/no): ").strip()
        if i == 'yes':
            print('finished program')
            break
        elif i == 'no':
            print('ok')
            continue
        else:
            print('invalid')
        time.sleep(.5)


serial_comm.close()
    