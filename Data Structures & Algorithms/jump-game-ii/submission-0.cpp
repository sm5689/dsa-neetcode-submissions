class Solution {
public:
    int jump(vector<int>& nums) {
        int total = 0;
        int l = 0;
        int r = 0;
        int farthest = 0;
        while (r < nums.size()-1) {
            for (int i = l; i<= r; i++) {
                farthest = max(farthest, nums[i]+i);
            }
            l = r+1;
            r = farthest;
            total++;
        }
        return total;
    }
};
