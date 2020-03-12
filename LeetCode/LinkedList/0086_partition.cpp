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
    ListNode *partition(ListNode *head, int x)
    {
        vector<ListNode *> list_smaller;
        vector<ListNode *> list_bigger;
        while (head != nullptr)
        {
            if (head->val >= x)
            {
                list_bigger.push_back(head);
            }
            else
            {
                list_smaller.push_back(head);
            }
            head = head->next;
        }
        int size_smaller = list_smaller.size();
        for (auto i = 0; i < size_smaller - 1; ++i)
        {
            list_smaller[i]->next = list_smaller[i + 1];
        }
        int size_bigger = list_bigger.size();
        if (size_bigger > 0 && size_smaller > 0)
        {
            list_smaller[size_smaller - 1]->next = list_bigger[0];
        }
        for (auto i = 0; i < size_bigger - 1; ++i)
        {
            list_bigger[i]->next = list_bigger[i + 1];
        }
        if (list_smaller.size() > 0)
        {
            return list_smaller[0];
        }

        if (list_bigger.size() > 0)
        {
            return list_bigger[0];
        }
        return nullptr;
    }
};