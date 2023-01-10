class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr || k == 1) {
			return head;
		}
		int len = 0;
		
		ListNode* nhead = new ListNode(0);
		ListNode* ans = nhead;
		ListNode* cur = head;

		while (head != nullptr) {
			len++;
			head = head->next;
		}

		int count = len / k;

		while (count != 0) {
			ListNode* tail = cur;
			int times = k - 1;
			while (times != 0 && tail != nullptr) {
				tail = tail->next;
				times--;
			}
			if (tail == nullptr) {
				break;
			}
			ListNode* next = tail->next;
			tail->next = nullptr;
			vector<ListNode*> rev = reverseList(cur);
			nhead->next = rev[0];
			nhead = rev[1];
			rev[1]->next = next;
			cur = next;
			count--;
		}
		return ans->next;
	}

	vector<ListNode*> reverseList(ListNode* head) {
		ListNode* cur = nullptr;
		while (head != nullptr) {
			ListNode* tmp = head->next;
			head->next = cur;
			cur = head;
			head = tmp;
		}
		ListNode* tail = cur;
		while (tail->next != nullptr) {
			tail = tail->next;
		}
		return {cur, tail};
	}
};