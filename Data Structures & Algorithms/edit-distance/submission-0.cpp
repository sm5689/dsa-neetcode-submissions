class Solution {
public:
    int minDistanceHelper(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if (i < 0) return j+1;
        if (j < 0) return i+1;
        if (dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return 0 + minDistanceHelper(i-1, j-1, word1, word2, dp);
        return dp[i][j] = 1 + min(minDistanceHelper(i, j-1, word1, word2, dp), min(minDistanceHelper(i-1, j, word1, word2, dp), minDistanceHelper(i-1, j-1, word1, word2, dp)));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length(), -1));
        return minDistanceHelper(word1.length()-1, word2.length()-1, word1, word2, dp);
    }
};
