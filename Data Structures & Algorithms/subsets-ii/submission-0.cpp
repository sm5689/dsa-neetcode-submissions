class Solution {
public:
    void dfs(int index, vector<vector<int>>& subsets, vector<int>& temp, vector<int>& nums) {
        if (index == nums.size()) {
            subsets.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        dfs(index+1, subsets, temp, nums);
        temp.pop_back();
        int i = index+1;
        while (i < nums.size() && nums[i] == nums[index]) {
            i++;
        }
        dfs(i, subsets, temp, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(0, subsets, temp, nums);
        return subsets;
    }
};
