/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0
*/

class Solution
{
public:
    double mypow(double base, int exp)
    {
        double res = 1;
        for(int i =0; i < exp; i++)
        {
            res *= base;
        }
        return res;
    }
    double Power(double base, int exponent)
    {
        if (exponent >= 0)
        {
            return mypow(base, exponent);
        }
        else
        {
            return 1 / mypow(base, -exponent);
        }
    }
};