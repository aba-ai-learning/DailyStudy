/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

n = 0, res = 0
n = 1, res = 1
n = 2, res = 2
n = 3, res = res(n-1) + res(n-2) = 3
n = 4, res = res(n-1) + res(n-2) = 5
n = 5, res = 

还是Fibonacci
*/

class Solution
{
public:
    int rectCover(int number)
    {
        int prenum = 2;
        int preprenum = 1;
        int num = 0;
        if (number <= 2)
            return number;
        for (int i = 3; i <= number; i++)
        {
            num = prenum + preprenum;
            preprenum = prenum;
            prenum = num;
        }
        return num;
    }
};