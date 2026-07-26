class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longestLength = 0;
        int currLength = 0;
        unordered_map<int, int> mpp;
        for (int right = 0; right < s.length(); right++) {
            if (mpp.find(s[right]) != mpp.end() && mpp[s[right]] >= left) {
                left = mpp[s[right]]+1;
            }
            mpp[s[right]] = right;
            longestLength = max(longestLength, right-left+1);
        }
        return longestLength;
    }
};
