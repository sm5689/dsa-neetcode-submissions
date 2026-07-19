class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxidx = 0;
        int curridx = 0;
        for(int i = 0; i< nums.size(); i++) {
            if (maxidx >= nums.size()-1) return true;
            if (i > maxidx) return false;
            maxidx = max(maxidx, i+nums[i]);
        }
        return false;
    }
};
