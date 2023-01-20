class Solution {
public:
	vector<string> kong(int kongLen, int sumNum) {
		int num = sumNum - 1;
		string cur = "";
		vector<string> res;
		if (num == 0) {
			for (int i = 0; i < kongLen; i++) {
				cur += ' ';
			}
			res.push_back(cur);
			return res;
		}
		int index = kongLen % num;
		int count = kongLen / num;
		for (int i = 0; i < count; i++) {
			cur += ' ';
		}
		for (int i = 0; i < num; i++) {
			if (i < index) {
				res.push_back(cur + ' ');
			}
			else {
				res.push_back(cur);
			}
		}
		return res;
	}

	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int len = words.size();
		vector<pair<int,int>> dict;
		int count = 0;
		vector<string> ans;
		for (int i = 0; i < len; i++) {
			count += words[i].length() + 1;
			if (count - 1 > maxWidth) {
				dict.push_back({ count - words[i].length() - 2, i - 1 });
				count = words[i].length() + 1;
			}
			else if (count - 1 == maxWidth) {
				dict.push_back({ count - 1, i });
				count = 0;
			}
		}
		if (count > 0) {
			dict.push_back({ count - 1, len - 1 });
		}

		int index = 0;
		int left = 0;
		for (int i = 0; i < dict.size() - 1; i++) {
			int sumNum = dict[i].second - index + 1;
			int kongLen = maxWidth - dict[i].first;
			index = dict[i].second + 1;
			vector<string> kongs = kong(kongLen, sumNum);
			string tmp = "";
			for (int j = left; j < dict[i].second; j++) {
				tmp += words[j] + ' ' + kongs[j - left];
			}
			tmp += words[dict[i].second];
			if (sumNum == 1) {
				tmp += kongs[0];
			}
			left = index;
			ans.push_back(tmp);
		}

		string last = "";
		for (int i = left; i <= dict[dict.size() - 1].second; i++) {
			last += words[i];
			if (last.length() == maxWidth) {
				break;
			}
			last += ' ';
		}

		while (last.length() < maxWidth) {
			last += ' ';
		}
		ans.push_back(last);
		return ans;
	}
};