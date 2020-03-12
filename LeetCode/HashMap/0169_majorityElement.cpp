class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int size = nums.size();
        int limit = int(size / 2) + 1;
        unordered_map<int, int> hashmap;
        for (auto i = 0; i < size; i++)
        {
            hashmap[nums[i]] += 1;
            if (hashmap[nums[i]] >= limit)
            {
                return nums[i];
            }
        }
        return -1;
    }
};