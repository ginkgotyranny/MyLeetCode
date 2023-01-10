class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* middle = listMiddle(head);
        ListNode* cur = middle->next;
        middle->next = nullptr;
        middle = cur;
        ListNode* right = sortList(middle);
        ListNode* left = sortList(head);
        return mergeList(left, right);
    }

    ListNode* listMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* mergeList(ListNode* left, ListNode* right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        if (left->val <= right->val) {
            left->next = mergeList(left->next, right);
            return left;
        }
        right->next = mergeList(left, right->next);
        return right;
    }
};