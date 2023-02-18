/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* nhead = new ListNode(0);
		ListNode* lessTail = nhead;
		ListNode* bigHead = new ListNode(0);
		ListNode* bigTail = bigHead;
		while (head != nullptr) {
			ListNode* cur = new ListNode(head->val);
			if (head->val < x) {
				lessTail->next = cur;
				lessTail = lessTail->next;
			}
			else {
				bigTail->next = cur;
				bigTail = bigTail->next;
			}
			head = head->next;
		}
		lessTail->next = bigHead->next;
		return nhead->next;
	}
};