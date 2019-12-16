#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int value = stack2.top();
        stack2.pop();
        return value;
    }

private:
    stack<int> stack1;
    stack<int> stack2;

};

int main(int agrc, char* argv[])
{
    Solution sol;
    sol.push(1);
    sol.push(2);
    sol.push(3);
    cout << sol.pop();
    cout << sol.pop();
    sol.push(4);
    cout << sol.pop();
    cout << sol.pop();

    return 0;
}