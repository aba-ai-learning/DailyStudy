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
        if (nums.size() < 3)
            return res;

        if (nums.size() == 3)
        {
            if (nums[0] + nums[1] + nums[2] == 0)
            {
                res.emplace_back(std::move(nums));
            }
            return res;
        }

        for (auto it = nums.begin(); it != nums.end() - 2; it++)
        {
            if (*it > 0)
                break;

            if (it != nums.begin() && *it == *(it - 1))
            {
                continue;
            }

            for (auto it2 = it + 1; it2 != nums.end() - 1; it2++)
            {
                int target = -(*it + *it2);

                for (auto it3 = nums.end() - 1; it3 >= it2 + 1; it3--)
                {
                    if (it3 < nums.end() - 1 && *it3 == *(it3 + 1))
                    {
                        continue;
                    }

                    if (*it3 == target)
                    {
                        vector<int> tmp = {(*it), (*it2), (*it3)};
                        res.push_back(tmp);
                    }
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>>res =  sol.threeSum(nums);
}