class Solution {
private:
    static bool customComp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), customComp);
        int cnt = 1;
        int lastEnd = intervals[0][1];
        for (int i = 1; i< intervals.size(); i++) {
            if (intervals[i][0] >= lastEnd) {
                cnt++;
                lastEnd = intervals[i][1];
            }
        }
        return intervals.size() - cnt;
    }
};
