//注意查找左边界和查找有边界时的开闭状态

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res = {-1, -1};
        if (nums.size() < 1)
            return res;

        int lo = 0, hi = nums.size() - 1;
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            nums[mi] < target ? lo = mi + 1 : hi = mi;
        }

        if (lo == nums.size())
            return res;
        if (target == nums[lo])
            res[0] = lo;
        else
            return res;
        // 第二次二分查找，找到右边界
        hi = nums.size();
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            target < nums[mi] ? hi = mi : lo = mi + 1;
        }
        res[1] = lo - 1;
        return res;
    }
};