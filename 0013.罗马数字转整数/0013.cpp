class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50, mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;
        int ans = 0;
        int index = 0;
        while (index < s.length()) {
            if (index + 1 < s.length() && mp[s[index]] < mp[s[index + 1]]) {
                ans = ans + mp[s[index + 1]] - mp[s[index]];
                index += 2;
            }
            else {
                ans += mp[s[index]];
                index++;
            }
        }
        return ans;
    }
};