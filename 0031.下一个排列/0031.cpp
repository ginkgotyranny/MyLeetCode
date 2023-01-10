class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) 
            return;

        auto i = nums.rbegin() + 1;
        while (i != nums.rend() && *i >= *(i-1)) 
            i++;

        auto j = nums.rbegin();
        if (i != nums.rend()) {
            while (*j <= *i)
                ++j;

            std::iter_swap(i, j);
        }

        std::reverse(nums.rbegin(), i);
    }
};