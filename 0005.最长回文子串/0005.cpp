class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        string ans = s.substr(0, 1);
        for (int i = 0; i < s.length(); i++) {
            int l = i, r;
            while (s[i] == s[i + 1]) {
                i++;
            }
            r = i + 1;
            l--;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                r++;
                l--;
            }

            if (l <0 && r > ans.length()) {
                ans = s.substr(0, r);
            }
            else if (r >= s.length() && (r - l - 1) > ans.length()) {
                ans = s.substr(l + 1, r - l - 1);
            }
            else if (l >= 0 && r<s.length() && (r - l - 1) > ans.length()) {
                ans = s.substr(l + 1, r - l - 1);
            }
        }
        return ans;
    }
};