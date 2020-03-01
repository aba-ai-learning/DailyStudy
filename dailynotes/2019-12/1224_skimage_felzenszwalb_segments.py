from skimage.segmentation import slic, felzenszwalb
import cv2
from skimage.color import label2rgb
import os

if __name__ == '__main__':
    img_dir = 'img_dir/'
    save_dir = 'save_dir/'
    if not os.path.exists(save_dir):
        os.mkdir(save_dir)

    image_list = os.listdir(img_dir)
    for index, imagename in enumerate(image_list):
        print(index)
        imgpath = os.path.join(img_dir, imagename)
        img = cv2.imread(imgpath)
        image_felzenszwalb = felzenszwalb(img)
        image_felzenszwalb_colored = label2rgb(
            image_felzenszwalb, img, kind='avg')

        cv2.imwrite(os.path.join(save_dir, imagename),
                    image_felzenszwalb_colored)
