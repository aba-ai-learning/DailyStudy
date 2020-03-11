class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return 0;
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (low < high)
        {
            mid = int((low + high) / 2);
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (nums[low] >= target)
            return low;
        else if (nums[high] >= target)
            return high;
        else
            return high + 1;
    }
};