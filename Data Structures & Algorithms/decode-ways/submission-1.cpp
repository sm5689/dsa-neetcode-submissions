class Solution {
public:
    int numDecodingsHelper(int index, string& s, vector<int>& dp) {
        if (index == s.length()) return 1;
        if (s[index] == '0') return 0;
        if (dp[index] != -1) return dp[index];
        int total = numDecodingsHelper(index+1, s, dp);
        if (index+1 < s.length()) {
            int num = (s[index]-'0')*10 + (s[index+1])-'0';
            if (num <= 26) {
                total+= numDecodingsHelper(index+2, s, dp);
            }
        }
        return dp[index]=total;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, -1);
        return numDecodingsHelper(0, s, dp);
    }
};
