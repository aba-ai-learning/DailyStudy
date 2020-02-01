/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        if (nums.size() < 4)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());
        for (auto i = nums.begin(); i < nums.end() - 3; ++i)
        {
            if (target > 0 && *i > target)
            {
                break;
            }
            if (target < 0 && *i > 0)
            {
                break;
            }
            if (i > nums.begin() && *(i) == *(i - 1))
            {
                continue;
            }

            for (auto j = i + 1; j < nums.end() - 2; ++j)
            {

                if (j > i + 1 && *(j) == *(j - 1))
                {
                    continue;
                }

                auto k = j + 1;
                auto l = nums.end() - 1;

                while (k < l)
                {
                    if (k > j + 1 && *(k) == *(k - 1))
                    {
                        ++k;
                        continue;
                    }
                    if (l < nums.end() - 1 && *(l) == *(l + 1))
                    {
                        --l;
                        continue;
                    }

                    if (*i + *j + *k + *l > target)
                    {
                        --l;
                    }
                    else if (*i + *j + *k + *l < target)
                    {
                        ++k;
                    }
                    else
                    {
                        ret.push_back({(*i), (*j), (*k), (*l)});
                        --l;
                        ++k;
                    }
                }
            }
        }

        return ret;
    }
};