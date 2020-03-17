class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int size = strs.size();
        if (size == 0)
        {
            return "";
        }
        int flag = false;
        int length = strs[0].size();
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            char tmp = strs[0][i];
            for (int j = 0; j < size; j++)
            {
                if (strs[j].size() < i + 1)
                {
                    flag = false;
                    break;
                }
                if (strs[j][i] != tmp)
                {
                    flag = false;
                    break;
                }
                flag = true;
            }
            if (flag)
                count++;
            else
            {
                break;
            }
        }

        return strs[0].substr(0, count);
    }
};