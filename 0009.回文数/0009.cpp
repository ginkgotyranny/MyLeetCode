class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int rev = 0;
        int y = x;
        while (y != 0) {
            if (ans > INT_MAX / 10) {
                return false;
            }
            ans = ans * 10 + y % 10;
            y /= 10;
        }
        return ans == x;
    }
};