class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMaxes(n, 0);
        preMaxes[0] = height[0];
        vector<int> sufMaxes(n, 0);
        sufMaxes[n-1] = height[n-1];
        for (int i = 1; i< n; i++) {
            preMaxes[i] = max(height[i], preMaxes[i-1]);
        }
        for (int i = n-2; i>= 0; i--) {
            sufMaxes[i] = max(height[i], sufMaxes[i+1]);
        }
        int maxi = 0;
        for (int i = 0; i< n; i++) {
            if (height[i] < preMaxes[i] && height[i] < sufMaxes[i]) {
                maxi+= min(preMaxes[i], sufMaxes[i]) - height[i];
            }
        }
        return maxi;
    } 
};
