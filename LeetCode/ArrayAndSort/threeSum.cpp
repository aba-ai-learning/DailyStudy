class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int size = nums.size();
        if (size < 3)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < size - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            auto j = i + 1;
            auto k = size - 1;

            while (j < k)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    j++;
                    continue;
                }
                if (k < size - 1 && nums[k] == nums[k + 1])
                {
                    k--;
                    continue;
                }

                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                }
            }
        }

        return res;
    }
};