class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int start = 0, end = 0, maxlen = 0, length = 0;
        unordered_map<char, int> hash;

        while (end < s.size())
        {
            char tmp = s[end];
            if (hash.find(tmp) != hash.end() && hash[tmp] >= start)
            {
                start = hash[tmp] + 1;
                length = end - start + 1 - 1;
            }
            hash[tmp] = end;
            end++;
            length++;

            maxlen = max(maxlen, length);
        }

        return maxlen;
    }
};