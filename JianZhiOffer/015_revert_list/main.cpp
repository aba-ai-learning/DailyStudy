/*
翻转列表，用stack
*/
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        stack<ListNode*> s;
        ListNode* r;
        while (pHead -> next) //while phead->next != nullptr  pHead才不是null是反转的head
        {
            s.push(pHead);
            pHead = pHead->next;
        }
        r = pHead;
        while(!s.empty())
        {
            pHead->next = s.top();
            pHead = pHead->next;
        }
        return r;
    }
};