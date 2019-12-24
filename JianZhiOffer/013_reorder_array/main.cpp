/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

sol 1: 二重循环，遇到偶奇则调换 [2,3,1,6,5,7,4] -> [3,2,1,6,5,7,4] -> ...
sol 2: 抽出所有的偶数放到另一个vector，在放到原vector后面
*/

#include <vector>
using namespace std;
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        vector<int> even;
        vector<int>::iterator it1, it2;
        for(it1=array.begin(); it1 != array.end(); )
        {
            if(*it1 % 2 == 0)
            {
                even.push_back(*it1);
                it1 = array.erase(it1);
            }
            else
            {
                ++it1;
            }
            
        }
        for(it2 = even.begin(); it2 != even.end(); ++it2)
        {
            array.push_back(*it2);
        }
    }
};