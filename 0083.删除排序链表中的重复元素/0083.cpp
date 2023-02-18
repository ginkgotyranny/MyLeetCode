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
	ListNode* deleteDuplicates(ListNode* head) {
		map<int, int> mp;
		while (head != nullptr) {
			mp[head->val]++;
			head = head->next;
		}
		ListNode* newHead = new ListNode(0);
		ListNode* ans = newHead;
		for (auto num : mp) {
			ListNode* cur = new ListNode(num.first);
			newHead->next = cur;
            newHead = newHead->next;
		}
		return ans->next;
	}
};