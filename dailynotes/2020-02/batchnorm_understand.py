import torch
import torch.nn as nn

if __name__ == "__main__":
    torch.manual_seed(7)

    N = 8
    C = 16
    H = 3
    W = 3
    input = torch.rand((N,C,H,W))
    bn = nn.BatchNorm2d(C)

    output = bn(input)

    print(output.shape)