class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int l1 = s1.size(), l2 = s2.size();
        if (l1 > l2)
            return false;
        vector<int> a(26), b(26);
        for (char c : s1)
            a[c - 'a']++;
        for (int i = 0; i < l2; ++i)
        {
            b[s2[i] - 'a']++;
            if (i >= l1)
                b[s2[i - l1] - 'a']--;
            if (i >= l1 - 1)
            {
                if (a == b)
                    return true;
                else
                    continue;
            }
        }
        return false;
    }
};