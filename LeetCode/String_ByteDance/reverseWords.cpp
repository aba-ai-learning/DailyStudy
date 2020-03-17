class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> words;
        string res;
        string tmpstr;
        for (auto i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                tmpstr += s[i];
            }
            else
            {
                if (tmpstr.size() != 0)
                {
                    words.push(tmpstr);
                }
                tmpstr.clear();
            }
        }

        if (tmpstr.size() != 0)
        {
            words.push(tmpstr);
        }

        while (!words.empty())
        {
            res += words.top();
            words.pop();
            res += ' ';
        }
        return res.substr(0, res.size() - 1);
    }
};