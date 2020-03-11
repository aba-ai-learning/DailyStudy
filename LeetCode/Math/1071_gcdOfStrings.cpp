/*
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

 

示例 1：

输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
示例 2：

输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
示例 3：

输入：str1 = "LEET", str2 = "CODE"
输出：""
 

提示：

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] 和 str2[i] 为大写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



int gcd(int m,int n)
{
        int t = 1;
        while(t != 0)
        {
                t=m%n;
                m=n;
                n=t;
        }
        return m;
}

*/

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if ((str1 + str2) != (str2 + str1))
            return "";
        int res = gcd(str1.size(), str2.size());
        return str1.substr(0, res);
    }

    int gcd(int a, int b)
    {
        int t = 1;
        while (t != 0)
        {
            t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};