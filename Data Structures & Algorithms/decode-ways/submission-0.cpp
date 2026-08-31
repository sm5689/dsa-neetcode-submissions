class Solution {
public:
    int numDecodingsHelper(int index, string& s, unordered_map<string, char>& mpp, vector<int>& dp) {
        if (index == s.length()) return 1;
        if (dp[index] != -1) return dp[index];
        int total = 0;
        for (int i = index; i< s.length() && i-index+1 <= 2; i++) {
            string sub = s.substr(index, i-index+1);
            if (mpp.find(sub) == mpp.end()) {
                continue;
            }
            total = total+numDecodingsHelper(i+1, s, mpp, dp);
        }
        return dp[index] = total;
    }
    int numDecodings(string s) {
        unordered_map<string, char> mpp;
        vector<int> dp(s.length()+1, -1);
        for (int i = 0; i< 26; i++) {
            mpp[to_string(i+1)] = 'A'+i;
        }
        return numDecodingsHelper(0, s, mpp, dp);
    }
};
