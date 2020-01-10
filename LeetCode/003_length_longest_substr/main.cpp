#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int size = s.length();
        int tmp = 0;
        int max = 0;
        for (int i = 0; i < size; i++)
        {
            for(int j = tmp; j < i; j++)
            {
                if (s[i] == s[j])
                {
                    tmp = j+1;
                }
            }
            if (i-tmp + 1 > max)
                max = i-tmp+1;
        }
    }
};