import cv2
import numpy as np


def affinetransform(img, M):
    if not isinstance(M, np.ndarray):
        M = np.array(M)
    h, w, c = img.shape
    outimg = np.zeros(img.shape, dtype=np.uint8)

    for i in range(h):
        for j in range(w):
            pixel_value = img[i, j, :]
            pos = np.array([i, j])
            M_scale_rotate = M[:, :2]
            new_pos = np.dot(M_scale_rotate, pos)
            new_pos = new_pos + M[:, 2]
            u, v = new_pos
            if u < h and v < w:
                outimg[u, v, :] = pixel_value

    cv2.imshow('view', outimg)
    cv2.waitKey(0)

    return outimg


def getaffinetransform(pts1, pts2):
    M = np.zeros((2, 3))
    cx = 0
    cy = 0
    alpha = 1  # cos(angle) * scale
    beta = 0  # sin(angle) * scale
    deltax = (1 - alpha) * cx - beta * cy
    deltay = beta * cx + (1 - alpha) * cy

    return M


imgpath = 'image/test.png'
img = cv2.imread(imgpath)

img = cv2.resize(img, (500, 500))
cv2.imshow('orig', img)
# cv2.waitKey(0)

cx = 0
cy = 0
alpha = 1  # cos(angle) * scale
beta = 0  # sin(angle) * scale
deltax = (1-alpha) * cx - beta*cy
deltay = beta * cx + (1-alpha)*cy

M = [
    [alpha, beta, deltax],
    [-beta, alpha, deltay]
]

transimg = affinetransform(img, M)
