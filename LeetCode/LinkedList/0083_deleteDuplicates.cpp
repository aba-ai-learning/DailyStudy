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
        if (head == nullptr)
        {
            return head;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        ListNode *curr = head;
        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
};