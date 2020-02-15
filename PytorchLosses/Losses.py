import torch
import torch.nn as nn
import torch.nn.functional as F

class L1Loss(nn.Module):
    def __init__(self, reduction='mean'):
        super(L1Loss, self).__init__()
        self.reduction = reduction
        assert reduction in ['none', 'mean', 'sum']

    def forward(self, input, target):
        input = input.view(input.size(0), -1)
        target = target.view(target.size(0), -1)
        res = torch.abs(target - input)
        
        if self.reduction == 'none':
            return res
        elif self.reduction == 'mean':
            return res.mean()
        elif self.reduction == 'sum':
            return res.sum()
        else:
            raise NotImplementedError

class L2Loss(nn.Module):
    def __init__(self, reduction='mean'):
        super(L2Loss, self).__init__()
        self.reduction = reduction
        assert reduction in ['none', 'mean', 'sum']

    def forward(self, input, target):

        input = input.view(input.size(0), -1)
        target = target.view(target.size(0), -1)

        res = torch.pow(target - input, 2)
        
        if self.reduction == 'none':
            return res
        elif self.reduction == 'mean':
            return res.mean()
        elif self.reduction == 'sum':
            return res.sum()
        else:
            print("not correct reduction")


class CrossEntropyLoss(nn.Module):
    def __init__(self, reduction='mean'):
        super(CrossEntropyLoss, self).__init__()
        self.reduction = reduction
        assert reduction in ['none', 'mean', 'sum']

    def forward(self, input, target):
        # assert (target.type == 'torch.long')
        pt = []
        for index, item in enumerate(input):
            class_index = target[index]
            pt_index = torch.exp(item[class_index]) / torch.sum(torch.exp(item))
            pt.append(pt_index)

        pt = torch.tensor(pt)
        res = -torch.log(pt)

        if self.reduction == 'none':
            return res
        elif self.reduction == 'mean':
            return res.mean()
        elif self.reduction == 'sum':
            return res.sum()
        else:
            print("not correct reduction")


class BCELoss(nn.Module):
    def __init__(self, reduction='mean'):
        super(BCELoss, self).__init__()
        self.reduction = reduction
        assert reduction in ['none','mean','sum']

    def forward(self, input, target):
        pt = []
        for index,value in enumerate(target):
            if value:
                pt.append(input[index])
            else:
                pt.append(1-input[index])

        pt = torch.tensor(pt)
        res = -torch.log(pt)

        if self.reduction == 'none':
            return res
        elif self.reduction == 'mean':
            return res.mean()
        elif self.reduction == 'sum':
            return res.sum()
        else:
            print("not correct reduction")


class BCEWithLogits(nn.Module):
    def __init__(self, reduction='mean'):
        super(BCEWithLogits, self).__init__()
        self.reduction = reduction
        assert reduction in ['none','mean','sum']

    def forward(self, input, target):
        pt = []


        for index,value in enumerate(target):
            if value:
                pt.append(input[index])
            else:
                pt.append(1-input[index])

        pt = torch.tensor(pt)
        res = -torch.log(pt)

        if self.reduction == 'none':
            return res
        elif self.reduction == 'mean':
            return res.mean()
        elif self.reduction == 'sum':
            return res.sum()
        else:
            print("not correct reduction")



if __name__ == '__main__':
    N = 8
    C = 3
    H = 10
    W = 10

    torch.manual_seed(7)
    torch.cuda.manual_seed_all(7)


    x = torch.rand((N, C, H, W))
    y = torch.rand((N, C, H, W))


    #L1Loss Input (N, *)  Target(N, *)
    myl1loss = L1Loss()
    torchl1loss = nn.L1Loss()
    assert myl1loss(x,y) == torchl1loss(x,y)

    #L2Loss Input (N, *)  Target(N, *)
    myl2loss = L2Loss()
    torchl2loss = nn.MSELoss()
    assert myl2loss(x,y) == torchl2loss(x,y)

    #CrossEntropyLoss Input (N, C) Target(N)
    input = torch.rand((N,C))
    target = torch.empty(N, dtype=torch.long).random_(C)

    torchceloss = nn.CrossEntropyLoss()
    myceloss = CrossEntropyLoss()
    assert torchceloss(input, target) == myceloss(input, target)

    ## BCELoss Input (sigmmoid(N))  Target(N).random(2)
    torchbceloss = nn.BCELoss()
    mybce = BCELoss()
    m = nn.Sigmoid()
    input = torch.rand((N))
    target = torch.empty(N).random_(2)
    assert torchbceloss(m(input), target) == mybce(m(input), target)


    ## BCEWithLogits
    torchbcewithlogits = nn.BCEWithLogitsLoss()
    mybcewithlogits = 








