/*
输入一个链表，输出该链表中倒数第k个结点。
*/

#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution
{
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        int count_num = 0;
        int ktohead = 0;
        ListNode* p = pListHead;
        while (p != nullptr)
        {
            count_num += 1;
            p = p->next;
        }
        if(k > count_num):
            return nullptr
        else
        {
            ktohead = count_num - k;
            for(int i = 0; i < ktohead; i++){
                pListHead
            }
        }
        

    }
};