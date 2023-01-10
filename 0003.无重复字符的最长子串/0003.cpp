class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int front = 0;
        int back = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.find_first_of(s[front], back) < front) {
                back = s.find_first_of(s[i], back) + 1;  
            }
            maxLen = max(maxLen, front - back + 1);
            front++;
        }
        return maxLen;
    }
};