/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


题解：
有两种方式，一种是用双指针
1. 设置dummyhead防止特殊情况（链表长度为1）
2. p,q两个节点指针指向dummyhead
3. p向前移动n个后再同时移动p,q 
4. 将q的下一个节点指向它的下下个
返回dummyhead.next
这种方式时间复杂度O(L) 空间复杂度O(1)


还有一种用vector<ListNode *> 将所有的节点地址存下来后
直接倒数第n+1个指向它的下下个，这种方法时间和空间复杂度都是O(L)


*/

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummyhead = ListNode(0);
        dummyhead.next = head;
        ListNode *list_p = new ListNode(0);
        ListNode *list_q = new ListNode(0);
        list_p->next = &dummyhead;
        list_q->next = &dummyhead;

        while (n > 0 && list_p->next)
        {
            list_p = list_p->next;
            n--;
        }

        while (list_p->next)
        {
            list_p = list_p->next;
            list_q = list_q->next;
        }
        list_q->next = list_q->next->next;

        return dummyhead.next;
    }

    ListNode *removeNthFromEnd2(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        vector<ListNode *> vec;
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        vec.push_back(dummyhead);
        while (head)
        {
            vec.push_back(head);
            head = head->next;
        }
        int size = vec.size();

        vec[size - n - 1]->next = vec[size - n - 1]->next->next;

        return dummyhead->next;
    }
};

