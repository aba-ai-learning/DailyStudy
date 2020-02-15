import cv2
import numpy as np


def adjust_brightness_gamma_correction(img, gamma):
    """Adjust brightness of an Image.
    Args:
        img (numpy ndarray): numpy ndarray to be adjusted.
        brightness_factor (float):  How much to adjust the brightness. Can be
            any non negative number. 0 gives a black image, 1 gives the
            original image while 2 increases the brightness by a factor of 2.
    Returns:
        numpy ndarray: Brightness adjusted image.
    """
    gamma_table = [np.power(x / 255.0, gamma) * 255.0 for x in range(256)]
    gamma_table = np.round(np.array(gamma_table)).astype(np.uint8)

    # table = np.array([ i*gamma for i in range (0,256)]).clip(0,255).astype('uint8')
    # same thing but a bit slower
    # cv2.convertScaleAbs(img, alpha=brightness_factor, beta=0)
    if img.shape[2] == 1:
        out = cv2.LUT(img, gamma_table)[:, :, np.newaxis]
    else:
        out = cv2.LUT(img, gamma_table)
    return out

if __name__ == '__main__':

    imgpath = '../images/wxy.png'
    img = cv2.imread(imgpath, cv2.IMREAD_UNCHANGED)
    img = cv2.resize(img,(500,500))
    out = adjust_brightness_gamma_correction(img, 1.5)
    cv2.imshow('view', out)
    cv2.imshow('input', img)
    cv2.waitKey(0)
