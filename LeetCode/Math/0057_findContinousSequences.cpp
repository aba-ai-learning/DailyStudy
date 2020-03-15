/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> res;
        int limit = int(target / 2) + 1;
        int sum = 0;
        for (auto i = 1; i <= limit; ++i)
        {
            for (auto j = i; j <= limit; ++j)
            {
                sum += j;
                if (sum == target)
                {
                    vector<int> singleres;
                    for (auto k = i; k <= j; ++k)
                    {
                        singleres.push_back(k);
                    }
                    res.push_back(singleres);
                    sum = 0;
                    break;
                }
                else if (sum > target)
                {
                    sum = 0;
                    break;
                }
            }
        }

        return res;
    }
};