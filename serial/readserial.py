import serial
import os
from PIL import Image
from io import BytesIO

PORT     = 'COM7'
FILENAME = 'output'
BAUD     = 2000000
FRAMES   = 85
DURATION = 25 # milliseconds per frame


def flipxbm(xbm): # unused
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

def getbitmaps():
    ser = serial.Serial(PORT, BAUD, timeout=0.1) # 1/timeout is the frequency at which the port is read
    bitmap = ''
    bitmaps = []
    frame = 0

    print('Waiting for data...')

    while True:
        data = ser.readline().decode().strip()
        if data:
            bitmap += data + '\n'
            if "}" in data:
                print('Captured frame: ', frame)

                bitmaps.append(bitmap)

                bitmap = ''
                frame+=1

        if frame >= FRAMES:
            return bitmaps

def convertgif(bitmaps, output):
    images = []

    for bitmap in bitmaps:
        image = Image.open(BytesIO(bytes(bitmap, 'utf-8')))
        images.append(image)

    images[0].save(output, save_all=True, append_images=images[1:], duration=DURATION, loop=0)

if __name__ == '__main__':
    bitmaps = getbitmaps()
    convertgif(bitmaps, os.path.dirname(os.path.realpath(__file__)) + '/' + FILENAME + '.gif')
