https://stackoverflow.com/questions/45463778/instance-normalisation-vs-batch-normalisation
https://www.zhihu.com/question/68730628

different normalization
![avatar](https://pic2.zhimg.com/v2-2a2c4f841de556581100ba45d2191171_r.jpg)


BatchNorm是channel-independent的， InstanceNorm是Channel，Batch-independent
所以直观的感受是bn能够做到share weights in batch
对于传统任务，我们更多的学到的是一批图像的特性，而对于style transfer，我们将一张图像当做一个domain来获取单张图片的style 或者content，所以用instanceNorm比较合适

所以对于cartoongan，generator用IN， 而discriminator用BN
