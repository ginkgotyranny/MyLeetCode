class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (n != 0) {
			fast = fast->next;
			n--;
		}
		if (fast == nullptr) {
			return head->next;
		}
		fast = fast->next;
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return head;
	}
};