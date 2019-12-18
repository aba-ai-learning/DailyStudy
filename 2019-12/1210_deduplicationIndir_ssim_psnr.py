#!/usr/bin/env python
# -*- coding: utf-8 -*-

from skimage.measure import compare_ssim, compare_psnr
import os
import cv2

def delete(filename):
    os.remove(filename)

if __name__ == "__main__":

    ## we suppose the image is get from a video and all the similar images are adjacent and named by the frames number
    image_dir = ''
    image_list = [os.path.join(rootdir, file) for rootdir, _, files in os.walk(path) for file in files if
                  (file.endswith('.jpg'))]
    delete_list = []
    image_list.sort()
    for curr_index, imgpath in enumerate(image_list):
        if not os.path.exists(image_list[curr_index]):
            print("not exist", image_list[curr_index])
            break
        if not os.path.exists(image_list[curr_index+1]):
            print("not exist", image_list[curr_index+1])
            break
        img1 = cv2.imread(image_list[curr_index])
        img2 = cv2.imread(image_list[curr_index+1])
        if img1 is None or img2 is None:
            break

        ## compute the ssim and psnr of two adjcent images
        ssim = compare_ssim(img1, img2, multichannel=True)
        psnr = compare_psnr(img1, img2)

        ## if the images are computed to be similar, throw it to the delete list
        if ssim > 0.85 or psnr > 20:
            delete_list.append(image_list[curr_index+1])
            print(ssim, image_list[curr_index], image_list[curr_index+1])
        else:
            print("small ssim", image_list[curr_index],image_list[curr_index+1], ssim)
        curr_index += 1
        if curr_index > len(image_list) - 2:
            break

    ## delete the duplication
    for item in delete_list:
        delete(item)



