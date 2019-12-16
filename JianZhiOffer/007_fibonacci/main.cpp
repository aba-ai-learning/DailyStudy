/*
用递归太耗时
*/

#include <iostream>
#include <exception>

using namespace std;

class Solution
{
public:
    int Fibonacci(int n)
    {
        int prenum = 1;
        int preprenum = 0;
        int num = 0;
        if (n < 0)
            std::invalid_argument("input should be larger than 0");
        if(n <= 1)
            return n;
        for(int i = 2; i <= n; i ++)
        {
            num = prenum+preprenum;
            preprenum = prenum;
            prenum = num;
            
        }
        return num;
    }
};

int main(int argc, char*argv[])
{
    Solution sol;
    int res = sol.Fibonacci(4);
    cout << res;
}