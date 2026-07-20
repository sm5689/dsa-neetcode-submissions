class Solution {
public:
    void combiSumHelper(int index, vector<int>& temp, vector<vector<int>>& sol,
                        vector<int>& nums, int target) 
                        {
                            if ( target == 0 ) {
                                sol.push_back(temp);
                                return;
                            }

                            if (index >= nums.size()) {
                                if (target == 0) {
                                    sol.push_back(temp);
                                } 
                                return;
                            }

                            temp.push_back(nums[index]);

                            if (nums[index] <= target) {
                                combiSumHelper(index, temp, sol, nums, target-nums[index]);
                            }

                            temp.pop_back();
                            
                            combiSumHelper(index+1, temp, sol, nums, target);
                        }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        vector<int> temp;
        combiSumHelper(0, temp, sol, nums, target);
        return sol;
    }
};
