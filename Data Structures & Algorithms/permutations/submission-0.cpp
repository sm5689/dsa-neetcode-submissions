class Solution {
public:
    //[1, 2, 3] - [1, 3, 2]
    void helper(int index, vector<vector<int>>& sol, vector<int>& nums) {
        if (index == nums.size()) {
            sol.push_back(nums);
            return;
        }
        for (int i = index; i< nums.size(); i++) {
            swap(nums[index], nums[i]);
            helper(index+1, sol, nums);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        // vector<int> temp;
        helper(0, sol, nums);
        return sol;
    }
};
