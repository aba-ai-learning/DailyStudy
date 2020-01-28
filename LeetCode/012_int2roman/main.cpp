/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-roman
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

看千位 累加M
看百位 如果大于500
*/

#include <string>

using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        int thousand_num = num / 1000;
        if (thousand_num == 1)
            roman += "M";
        else if (thousand_num == 2)
            roman += "MM";
        else if (thousand_num == 3)
            roman += "MMM";
        else
            roman += "";

        int res_num = num % 1000;
        int hundred_num = res_num / 100;
        if(hundred_num == 9)
            roman += "CM";
        else if(hundred_num == 8)
            roman += "DCCC";
        else if (hundred_num == 7)
            roman += "DCC";
        else if (hundred_num == 6)
            roman += "DC";
        else if (hundred_num == 5)
            roman += "D";
        else if (hundred_num == 4)
            roman += "CD";
        else if (hundred_num == 3)
            roman += "CCC";
        else if (hundred_num == 2)
            roman += "CC";
        else if (hundred_num == 1)
            roman += "C";
        else
            roman += "";

        res_num = num % 100;
        int decimal_num = res_num / 10;
        if (decimal_num == 9)
            roman += "XC";
        else if (decimal_num == 8)
            roman += "LXXX";
        else if (decimal_num == 7)
            roman += "LXX";
        else if (decimal_num == 6)
            roman += "LX";
        else if (decimal_num == 5)
            roman += "L";
        else if (decimal_num == 4)
            roman += "XL";
        else if (decimal_num == 3)
            roman += "XXX";
        else if (decimal_num == 2)
            roman += "XX";
        else if (decimal_num == 1)
            roman += "X";
        else
            roman += "";

        res_num = num % 10;
        if (res_num == 9)
            roman += "IX";
        else if (res_num == 8)
            roman += "VIII";
        else if (res_num == 7)
            roman += "VII";
        else if (res_num == 6)
            roman += "VI";
        else if (res_num == 5)
            roman += "V";
        else if (res_num == 4)
            roman += "IV";
        else if (res_num == 3)
            roman += "III";
        else if (res_num == 2)
            roman += "II";
        else if (res_num == 1)
            roman += "I";
        else
            roman += "";
        
        return roman;
    }
};