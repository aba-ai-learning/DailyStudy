/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

思路: 
for index, value in enumerate(nums):
    target_rest = target - value
    if target_rest in hashmap:
        return [hashmap[value], index]
    else:
        hashmap[value] = index


c++ 中map插入方式
1. hashmap.insert(pair<int, int>(1, 3));
2. hashmap[3] = 5;

map & unordered_map

The map::count() is a built-in function in C++ STL which returns 1 
if the element with key K is present in the map container. 
It returns 0 if the element with key K is not present in the container.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
#include <unordered_map>
#include <assert.h>

using namespace std;
vector<int> twoSum(vector<int> nums, int target)
{
    unordered_map<int, int> hashmap;
    int length = nums.size();
    for (int i = 0; i < length; i++)
    {
        if (hashmap.count(target - nums[i]))
            return {hashmap[target - nums[i]], i};
        hashmap[nums[i]] = i;
    }

}

int main(int argv, char *argc[])
{
    std::vector<int> nums{2, 7, 11, 15};
    std::vector<int> ret{0, 1};
    assert(twoSum(nums, 9) == ret);
    return 0;
}