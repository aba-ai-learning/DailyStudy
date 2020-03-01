import cv2
import numpy as np
import math


def apply_median_filter(input, window_size, x, y):
    i_filtered = 0
    windowlist = []
    i = 0
    half = window_size / 2
    while i < window_size:
        j = 0
        while j < window_size:
            neighbour_x = x - half + i
            neighbour_y = y - half + j
            try:
                neighbour_value = input[neighbour_x][neighbour_y]
                windowlist.append(neighbour_value)
            except:
                neighbour_value = 0

            j += 1
        i += 1
    windowlist.sort()
    median = int(len(windowlist) / 2 + 1)
    i_filtered = windowlist[median]

    return int(round(i_filtered))


def median_filter(input, window_size):
    output = np.zeros(input.shape)
    print(input.shape)

    i = 0
    while i < len(output):
        j = 0
        while j < len(output[0]):
            output[i][j] = apply_median_filter(input, window_size, i, j)
            j += 1
        i += 1
        print(i)

    return output


if __name__ == '__main__':
    imgpath = 'test_.jpg'
    img = cv2.imread(imgpath)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    output = median_filter(img, 5)
    cv2.imwrite('median_filter_orig.jpg', output)
