class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int listLen = lists.size();
		if (listLen == 0) {
			return nullptr;
		}
		int left = 0;
		int right = listLen - 1;
		int middle = (left + right) / 2;
		while (middle >= 0) {
			while (left < right) {
				lists[left] = mergeTwoLists(lists[left], lists[right]);
				left++;
				right--;
			}
			if (middle == 0) {
				break;
			}
			right = right == left ? left : left - 1;
			left = 0;
			middle = (left + right) / 2;
		}
		return lists[0];
	}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr) {
			return list2;
		}
		if (list2 == nullptr) {
			return list1;
		}
		if (list1->val < list2->val) {
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		list2->next = mergeTwoLists(list1, list2->next);
		return list2;
	}
};