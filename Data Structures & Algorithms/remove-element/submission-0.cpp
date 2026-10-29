class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lastNotKIndex = nums.size()-1;
        while (lastNotKIndex >= 0 && nums[lastNotKIndex] == val) {
            lastNotKIndex--;
        }
        int cnt = 0;
        int i = 0;
        while (i <= lastNotKIndex) {
            if (nums[i] == val) {
                swap(nums[i], nums[lastNotKIndex]);
                lastNotKIndex--;
                cnt++;
            } 
            
            while (lastNotKIndex >= i && nums[lastNotKIndex] == val) {
                lastNotKIndex--;
            }
            i++;
        }
        return lastNotKIndex+1;
    } 
};