class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        vector<int> nums_reverse = nums;
        sort(nums_reverse.begin(), nums_reverse.end());
        reverse(nums_reverse.begin(), nums_reverse.end());
        return nums_reverse[k - 1];
    }
};