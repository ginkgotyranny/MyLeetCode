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
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		vector<int> res;
		ListNode* tail = head;
		while (tail != nullptr) {
			res.push_back(tail->val);
			tail = tail->next;
		}

		reverse(res.begin() + left - 1, res.begin() + right);

		tail = head;
		int index = 0;
		while (tail != nullptr) {
			tail->val = res[index];
			tail = tail->next;
			index++;
		}
		return head;
	}
};