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
	ListNode* rotateRight(ListNode* head, int k) {
		vector<int> res;
		ListNode* nhead = new ListNode(0);
        ListNode* ans = nhead;
        ListNode* tmp = head;
		while (tmp != nullptr) {
			res.push_back(tmp->val);
			tmp = tmp->next;
		}

		if (k == 0 || res.size() == 0 || k % res.size() == 0) {
			return head;
		}
		int fast = k % res.size();
		int slow = -1;
		for (; fast <= res.size(); fast++) {
			slow++;
		}
		for (int i = slow; i < res.size(); i++) {
			ListNode* cur = new ListNode(res[i]);
			nhead->next = cur;
            nhead = nhead->next;
		}
		for (int i = 0; i < slow; i++) {
			ListNode* cur = new ListNode(res[i]);
			nhead->next = cur;
            nhead = nhead->next;
		}
		return ans->next;
	}
};