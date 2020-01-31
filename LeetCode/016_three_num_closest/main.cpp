/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        if (nums.size() < 3)
        {
            return 0;
        }
        if (nums.size() == 3)
        {
            return nums[0] + nums[1] + nums[2];
        }

        int sumnum = nums[0] + nums[1] + nums[2];
        int error = abs(sumnum - target);

        sort(nums.begin(), nums.end());

        for (auto i = nums.begin(); i < nums.end() - 2; ++i)
        {
            auto j = i + 1;
            auto k = nums.end() - 1;

            while (j < k)
            {
                if (abs(*i + *j + *k - target) < error)
                {
                    sumnum = *i + *j + *k;
                    error = abs(*i + *j + *k - target);
                }

                if (*i + *j + *k - target > 0)
                {
                    --k;
                }
                else if (*i + *j + *k - target < 0)
                {
                    ++j;
                }
                else
                {
                    return sumnum;
                }
            }
        }
        return sumnum;
    }
};