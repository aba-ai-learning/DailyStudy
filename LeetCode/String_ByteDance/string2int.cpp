#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int m = num1.size();
        int n = num2.size();

        vector<int> res(m + n, 0);
        string result;

        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                int temp = (num1[i] - '0') * (num2[j] - '0');
                int sum = temp + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        for (int i = 0; i < res.size(); ++i)
        {
            if (res[i] == 0 && result == "")
            {
                continue;
            }
            result += ('0' + res[i]);
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string a = "123";
    string b = "456";
    string res = sol.multiply(a,b);
    cout << res << endl;
}