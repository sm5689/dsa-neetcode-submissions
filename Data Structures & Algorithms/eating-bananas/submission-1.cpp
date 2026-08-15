class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        int sum = 0;
        for (int bananas : piles) {
            sum = sum+ceil((double)bananas/(double)k);
        }
        return sum<=h;
    }
    int getMaxi(vector<int>& piles) {
        int maxi = INT_MIN;
        for (auto bananas : piles) {
            maxi = max(maxi, bananas);
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        /*
        piles - number of bananas in ith pile 
        h - number of hours to eat all bananas 
        k - banana per hour eating rate
        choose pile and eat k bananas 
        if pile has < k bananas then finish eating pile but stay here for this hour
        to return -> min k such that eat all bananas within h hours 
        */
        int start = 1;
        int end = getMaxi(piles);
        while (start <= end) {
            int mid = (start+end) / 2;
            if (canEat(piles, h, mid)) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return start;
    }
};
