/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
【分析】 每个台阶可以看作一块木板，让青蛙跳上去，n个台阶就有n块木板，最后一块木板是青蛙到达的位子， 
必须存在，其他 (n-1) 块木板可以任意选择是否存在，
则每个木板有存在和不存在两种选择，(n-1) 块木板 就有 [2^(n-1)] 种跳法，可以直接得到结果。
*/

#include <stdexcept>

class Solution
{
public:
    int jumpFloorII(int number)
    {
        if (number < 0)
            std::runtime_error("number >= 0");

        if (number == 0)
            return number;
        int total = 1;
        for (int i = 1; i < number; i++)
            total *= 2;
        return total;
    }
};

int main()
{
    return 0;
}