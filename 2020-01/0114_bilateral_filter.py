import cv2
import numpy as np
import math

def distance(x,y, i,j):
    return np.sqrt((x-i)**2+(y-j)**2)


def gaussian(x, sigma):
    alpha = (1.0 / (2 * math.pi * (sigma ** 2)))
    return alpha * math.exp(-x**2/2*sigma**2)



def bilateral_filter_pixel(inputimg, window_size, x,y, sigma_s, sigma_r):
    i_filtered = 0
    i = 0
    wp = 0
    half =  window_size / 2
    while i < window_size:
        j = 0
        while j < window_size:
            neighbour_x = x - half + i
            neighbour_y = y - half + j
            try:
                neighbour_value = inputimg[neighbour_x][neighbour_y]
            except:
                neighbour_value = 0
            gd = gaussian(distance(x,y,neighbour_x,neighbour_y),sigma_s)
            gi = gaussian(inputimg[x][y] - neighbour_value, sigma_r)
            w = gd*gi
            i_filtered += w*neighbour_value
            wp += w
            j += 1
        i += 1
    i_filtered = i_filtered / wp

    return int(round(i_filtered))

def bilateral_filter(inputimg, window_size, sigma_s, sigma_r):
    outputimg = np.zeros(inputimg.shape)
    print(inputimg.shape)

    i = 0
    while i < len(outputimg):
        j = 0
        while j < len(outputimg[0]):
            outputimg[i][j] = bilateral_filter_pixel(inputimg, window_size, i, j, sigma_s, sigma_r)
            j += 1
        i += 1
        print(i)

    return outputimg



if __name__ == '__main__':
    imgpath = 'test_.jpg'
    img = cv2.imread(imgpath)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    output = bilateral_filter(img, 5, 12, 16)
    cv2.imwrite('bilateral_filter_res.jpg', output)
    cv2.imshow('view', output)
    cv2.waitKey(0)