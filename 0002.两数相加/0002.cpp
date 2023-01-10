class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* head = new ListNode;
        ListNode* tail = head;
        while (l1 != nullptr || l2 != nullptr || flag != 0) {
            int num1 = 0;
            int num2 = 0;
            if (l1 != nullptr) {
                num1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                num2 = l2->val;
                l2 = l2->next;
            }
            int addNum = (num1 + num2 + flag) % 10;
            flag = (num1 + num2 + flag) / 10;
            ListNode* cur = new ListNode(addNum);
            tail->next = cur;
            tail = tail->next;
        }
        return head->next;
    }
};