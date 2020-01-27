/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int current_num = 0;
        while(x)
        {
            if (current_num > 0 && ((std::numeric_limits<int>::max() - x % 10) / 10) < current_num)
            {
                return 0;
            }
            if(current_num < 0 && ((std::numeric_limits<int>::min() - x % 10) / 10) > current_num)
            {
                return 0;
            }
            current_num =  current_num * 10 + x % 10;
            x = x/10;
        }
        return current_num;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int x = 345;
    int res = sol.reverse(x);
    cout << res << endl;
}