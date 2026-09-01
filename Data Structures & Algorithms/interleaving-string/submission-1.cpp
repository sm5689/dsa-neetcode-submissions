class Solution {
public:
    bool isInterleaveHelper(int i1, int i2, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if (i1 == s1.length() && i2 == s2.length()) return true;
        if (dp[i1][i2] != -1) return dp[i1][i2];
        bool pick = false;
        if (i1 < s1.length() && s1[i1] == s3[i1+i2]) pick = pick || isInterleaveHelper(i1+1, i2, s1, s2, s3, dp);
        if (!pick && i2 < s2.length() && s2[i2] == s3[i2+i1]) pick = pick || isInterleaveHelper(i1, i2+1, s1, s2, s3, dp);
        return dp[i1][i2] = pick;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.length()+1, vector<int>(s1.length()+1, -1));
        if (s1.length()+s2.length() != s3.length()) return false;
        return isInterleaveHelper(0, 0, s1, s2, s3, dp);
    }
};
