/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *curr = dummyhead;
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        int flag = false;
        int prev = head->val;
        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            if (curr->next->val == curr->next->next->val)
            {
                curr->next = curr->next->next;
                flag = true;
            }
            else
            {
                if (flag)
                {
                    curr->next = curr->next->next;
                }
                else
                {
                    curr = curr->next;
                }
                flag = false;
            }
        }
        if (flag)
        {
            curr->next = curr->next->next;
        }

        return dummyhead->next;
    }
};