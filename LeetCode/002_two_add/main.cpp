#include <vector>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode head(0);
        ListNode *p = &head;
        int flag = 0;
        while (l1 && l2)
        {
            int tmp = l1->val + l2->val + flag;
            ListNode *next = new ListNode(tmp % 10);
            flag = tmp / 10;
            p->next = next;
            p = p->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        while (l1)
        {
            //优化点，判断flag=0后p->next = l1
            int tmp = l1->val+flag;
            ListNode *next = new ListNode(tmp%10);
            flag = tmp/10;
            p->next = next;
            p = p->next;
            l1 = l1 ? l1->next : nullptr;
        }
        while (l2)
        {
            int tmp = l2->val + flag;
            ListNode *next = new ListNode(tmp % 10);
            flag = tmp / 10;
            p->next = next;
            p = p->next;
            l2 = l2 ? l2->next : nullptr;
        }
        while (flag)
        {
            ListNode *next = new ListNode(flag);
            p->next = next;
        }
        return head.next;
    }
};

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(0);
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);

    ListNode *head2 = new ListNode(3);
    ListNode *node4 = new ListNode(5);

    head2->next  = node4;

    head->next = node1;
    node1->next = node2;
    node2->next = node3;

    Solution sol;

    ListNode *res = sol.addTwoNumbers(head, head2);

    while (res != nullptr)
    {
        std::cout << res->val << std::endl;
        res = res->next;
    }
    std::cout << "Print Done" << std::endl;
}