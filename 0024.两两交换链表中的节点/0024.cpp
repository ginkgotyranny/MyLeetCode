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
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* nhead = new ListNode(0);
		ListNode* ans = nhead;
		ListNode* cur = head;
		while (cur != nullptr && cur->next != nullptr) {
			ListNode* next = cur->next->next;
			nhead->next = cur->next;
			cur->next->next = cur;
			cur->next = next;
			cur = cur->next;
			nhead = nhead->next->next;
		}
		return ans->next;
	}
};