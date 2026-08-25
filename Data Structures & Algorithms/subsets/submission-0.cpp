class Solution {
public:
    void dfs(int index, vector<vector<int>>& sol, vector<int> temp, vector<int>& nums) {
        if (index == nums.size()) {
            sol.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        dfs(index+1, sol, temp, nums);
        temp.pop_back();
        dfs(index+1, sol, temp, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        dfs(0, sol, {}, nums);
        return sol;
    }
};
