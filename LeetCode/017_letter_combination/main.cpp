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
    vector<string> table =
        {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };

    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;
        if (digits.empty())
        {
            return ret;
        }

        std::function<void(std::string ref, int depth)> func;
        func = [&](string ref, int depth) -> void {
            int number = ref[depth] - '0' - 2;
            string map_string = table[number];

            if (depth == digits.size() - 1)
            {
                for (auto c : map_string)
                {
                    ref[depth] = c;
                    ret.push_back(ref);
                }
            }
            else
            {
                for (auto c : map_string)
                {
                    ref[depth] = c;
                    func(ref, depth + 1);
                }
            }
        };

        func(digits, 0);

        return ret;
    }
};