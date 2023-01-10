class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int max_l = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }
                else {
                    int cur = i - stk.top();
                    max_l = max(max_l, cur);
                }
            }
        }
        return max_l;
    }
};