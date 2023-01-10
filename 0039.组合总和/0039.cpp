class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& candidates, int target, int sum, int start)
    {
        if (sum > target) return;
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            path.push_back(candidates[i]);
            dfs(res, path, candidates, target, sum + candidates[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, candidates, target, 0, 0);
        return res;
    }
};