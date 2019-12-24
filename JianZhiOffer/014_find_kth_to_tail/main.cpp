/*
输入一个链表，输出该链表中倒数第k个结点。
O(n)解法：
        p指针先跑，并且记录节点数，当p指针跑了k-1个节点后，pre指针开始跑，
        当p指针跑到最后时，pre所指指针就是倒数第k个节点
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
        ListNode* p1 = pListHead;
        while (p != nullptr)
        {
            count_num += 1;
            p = p->next;
        }
        if(k > count_num)
            return nullptr;
        else
        {
            ktohead = count_num - k;
            for(int i = 0; i < ktohead; i++){
                p1 = p1->next;
            }
            return p1;
        }
        

    }
};