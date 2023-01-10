class Solution {
public:
	int divide(int dividend, int divisor) {
		int flag = 1;
		if (dividend < 0) {
			flag *= -1;
		}
		if (divisor < 0) {
			flag *= -1;
		}
		
		long absdiv = abs(dividend);
		long absdivs = abs(divisor);
		long ans = div(absdiv, absdivs);
		ans = flag == 1 ? ans : -ans;
		ans = max(ans, (long)INT_MIN);
		ans = min(ans, (long)INT_MAX);
		return ans;
	}
	
	long div(long a, long b) {
		if (a < b) {
			return 0;
		}
		long count = 1;
		long tb = b;
		while ((tb + tb) <= a) {
			count *= 2;
			tb *= 2;
		}
		return div(a - tb, b) + count;
	}
};