/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int length = strs.size();
        string common = "";
        char current_char;
        if (length == 0)
            return "";
        int string_length = strs[0].size();

        for (int i = 0; i < string_length; i++)
        {
            current_char = strs[0][i];
            for (int j = 0; j < length; j++)
            {
                if (strs[j].size() < i)
                    return common;

                if (strs[j][i] != current_char)
                    return common;
            }
            common += current_char;
        }
        return common;
    }
};