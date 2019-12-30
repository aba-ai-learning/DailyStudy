### bn 的作用
保证网络输入的特征分布的一致性，均值为0，方差为1，同时为了适当恢复表征能力，加入了两个参数
当参数一个为均值一个为方差时还原

### bn 公式

(x - E(x))/Var(x) * lambda + beta

### bn的learnable parameters
lambda 和 beta是在前向的过程中学习到的，为了一定程度还原因为mvn失去的特征

### pytorch中冻结bn层的坑
因为参数和其他层不一样，不是反向的时候学习的，所以required_grad=False并不能冻结这个参数，只有eval()模式下
才能冻结bn层的参数


pytorch接口
BatchNormNd(nchannel, affine=True) affine用来控制是否有可学习参数，即lambda和beta

