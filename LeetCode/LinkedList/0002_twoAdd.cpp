/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
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
            int tmp = l1->val + flag;
            ListNode *next = new ListNode(tmp % 10);
            flag = tmp / 10;
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

    head2->next = node4;

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