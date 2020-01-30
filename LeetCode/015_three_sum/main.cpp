/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (vector<int>::iterator it = nums.begin(); it != nums.end() - 2; ++it)
        {
            for (vector<int>::iterator it2 = it + 1; it2 != nums.end() - 1; it2++)
            {
                int target = -(*it + *it2);
                for (vector<int>::iterator it3 = it2 + 1; it3 != nums.end(); it3++)
                {
                    if (*it3 == target)
                    {
                        res.push_back({(*it), (*it2), (*it3)});
                    }
                }
            }
            vector<int>::iterator next_it = it + 1;
            if (*it == *next_it)
                it++;
        }
        return res;
    }
};