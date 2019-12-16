/*
TODO:递归方法为什么array总是空？ 引用传递OK

输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
该解是使用栈先入后出的特性，也可以使用递归的方法
*/

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : 
    val(x), next(nullptr){} 
};

class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> array;
        stack<int> stk;
        while (head != nullptr)
        {
            stk.push(head->val);
            head = head->next;
        }
        while (!stk.empty())
        {
            array.push_back(stk.top());
            stk.pop();
        }
        return array;
    }
};

void printListFromTailToHeadRec(ListNode *head, vector<int>& array)
{
    if (head != nullptr)
    {
        if (head->next != nullptr)
        {
            printListFromTailToHeadRec(head->next, array);
        }
        array.push_back(head->val);
    }
}

int main(int argc, char* argv[])
{
    ListNode *head = new ListNode(0);
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;

    Solution sol;
    vector<int> a;
    // a = sol.printListFromTailToHead(head);
    printListFromTailToHeadRec(head, a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}