class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A)
    {
        long sum = 0;
        long size = A.size();
        if (size < 3)
        {
            return false;
        }
        for (auto i = 0; i < size; ++i)
        {
            sum += A[i];
        }
        if (sum % 3 != 0)
        {
            return false;
        }
        long sum_part = sum / 3;
        int count = 0;
        long tmp_sum = 0;

        for (auto i = 0; i < size; ++i)
        {
            tmp_sum += A[i];
            if (tmp_sum == sum_part)
            {
                tmp_sum = 0;
                count += 1;
            }
        }

        if (count >= 3)
        {
            return true;
        }

        return false;
    }
};