class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i< nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];

            int begin = i+1;
            int end = nums.size()-1;

            while (begin < end) {
                
                int curr = nums[begin] + nums[end];

                if (curr == target) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[begin]);
                    temp.push_back(nums[end]);
                    ans.push_back(temp);
                    while (begin < end && nums[begin] == nums[begin+1]) begin++;
                    while (begin < end && nums[end] == nums[end-1]) end--;
                    begin++;
                    end--;
                }
                else if (curr > target) end--;
                else begin++;
            }
        }
        return ans;
    }
};
