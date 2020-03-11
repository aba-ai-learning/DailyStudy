class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res = {-1, -1};
        if (nums.size() < 1)
            return res;

        int lo = 0, hi = nums.size()-1;
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if(nums[mi] < target)
            {
                lo = mi+1;
            }
            else
            {
                hi = mi;
            }
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
            if(nums[mi] > target)
            {
                hi = mi;
            }
            else
            {
                lo = mi-1;
            }
        }
        res[1] = lo - 1;
        return res;
    }
};