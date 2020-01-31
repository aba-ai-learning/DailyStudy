/*

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <map>


using namespace std;
class Solution
{
public:
    map<string, vector<string>> table =
        {
            {"2", {"a", "b", "c"}},
            {"3", {"d", "e", "f"}},
            {"4", {"g", "h", "i"}},
            {"5", {"j", "k", "l"}},
            {"6", {"m", "n", "o"}},
            {"7", {"p", "q", "r", "s"}},
            {"8", {"t", "u", "v"}},
            {"9", {"w", "x", "y", "z"}},
    };

    vector<string> letterCombinations(string digits)
    {
        int length = digits.size();
        vector<string> ret;
        if (length == 1)
        {
            return table[digits];
        }

        string sub_digits = digits.substr(0, length - 1);
        string last_digit = digits.substr(length - 1);

        // for(auto suffix : table[last_digit])
        // {
        //     vector<string> tmp = letterCombinations(sub_digits)
        // }

        for (auto item : letterCombinations(sub_digits))
        {
            for (auto suffix : table[last_digit])
            {
                ret.push_back((item + suffix));
            }
        }
        return ret;
    }
};