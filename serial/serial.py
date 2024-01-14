import serial

PORT = 'COM7'
BAUD = 2000000


def flipxbm(xbm):
    output = ''
    i = 0
    while i < len(xbm):
        if xbm[i] == 'x' and xbm[i:i+3] != 'xbm':
            output += str(hex(int(xbm[i+1:i+3], 16) ^ (2 ** 8 - 1)))
            i += 3 
        else:
            output += xbm[i]
            i+=1
    return output

def readserialbitmap(comport, baudrate):
    ser = serial.Serial(comport, baudrate, timeout=0.1) # 1/timeout is the frequency at which the port is read
    bitmap = ''
    frame = 0

    print('Waiting for data...')

    while True:
        data = ser.readline().decode().strip()
        if data:
            bitmap += data + '\n'
            if "}" in data:
                print('Captured frame: ', frame)

                with open(str(frame) + '.xbm', 'w') as file:
                    file.write(flipxbm(bitmap))

                bitmap = ''
                frame+=1

if __name__ == '__main__':
    readserialbitmap(PORT, BAUD)
