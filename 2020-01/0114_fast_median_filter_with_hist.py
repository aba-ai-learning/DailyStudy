
import cv2
import numpy as np
import math


def calcMedian(histogram, threshholdvalue):
    tmpnum = 0
    for i in range(len(histogram)):
        tmpnum += histogram[i]
        if tmpnum > threshholdvalue:
            return i

    return None


def fast_median_filter(input, window_size):
    h, w = input.shape
    output = np.zeros(input.shape, dtype=np.uint8)
    print(input.shape)
    N = window_size*window_size
    threshholdvalue = N/2 + 1
    radius = (window_size - 1) / 2
    right = w - radius
    bot = h - radius

    histogram = [0 for i in range(256)]

    for i in range(radius, right, 1):
        for j in range(radius, bot, 1):
            ## build first histogram
            if j == radius:
                histogram = [0 for _ in range(256)]
                for y in range(i-radius, i+radius, 1):
                    for x in range(j-radius, j+radius, 1):
                        value = input[x][y]
                        histogram[value] += 1
            else:
                #update histogram : minus left add right
                left = j-radius-1
                right = j+radius
                for y in range(i-radius, i+radius, 1):
                    valuel = input[left][y]
                    valuer = input[right][y]
                    histogram[valuel] -= 1
                    histogram[valuer] += 1

            ###calc median with histogram
            medianvalue = calcMedian(histogram, threshholdvalue)
            output[j][i] = medianvalue

    # ##border keep 0
    # for i in range(0, radius):

    return output


if __name__ == '__main__':

    imgpath = 'test_.jpg'
    img = cv2.imread(imgpath)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    output = fast_median_filter(img, 5)
    cv2.imwrite('fast_median_filter.jpg', output)
