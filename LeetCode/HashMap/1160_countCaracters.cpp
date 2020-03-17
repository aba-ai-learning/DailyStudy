class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int res = 0;
        unordered_map<char, int> hash_char;
        for (auto i = 0; i < chars.size(); ++i)
        {
            ++hash_char[chars[i]];
        }

        for (auto word : words)
        {
            unordered_map<char, int> hash_word;
            for (auto i = 0; i < word.size(); ++i)
            {
                ++hash_word[word[i]];
            }
            bool word_flag = true;
            for (auto c : word)
            {
                if (hash_char[c] < hash_word[c])
                {
                    word_flag = false;
                    break;
                }
            }
            if (word_flag)
                res += word.size();
        }

        return res;
    }
};