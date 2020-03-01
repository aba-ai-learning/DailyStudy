https://towardsdatascience.com/image-segmentation-using-pythons-scikit-image-module-533a61ecc980


#### SLIC (Simple Linear Iterative Clustering)
SLIC algorithm actually uses a machine learning algorithm called K-Means under the hood. It takes in all the pixel values of the image and tries to separate them out into the given number of sub-regions. Read the Reference Paper here.

https://blog.csdn.net/u013593585/article/details/52043424



#### Felzenszwalb

This algorithm also uses a machine learning algorithm called minimum-spanning tree clustering under the hood. Felzenszwaib doesn’t tell us the exact number of clusters that the image will be partitioned into. It’s going to run and generate as many clusters as it thinks is appropriate for that
given scale or zoom factor on the image. The Reference Paper can be accessed here.

https://blog.csdn.net/ttransposition/article/details/38024557

该方案可以模拟动漫的涂抹效果

