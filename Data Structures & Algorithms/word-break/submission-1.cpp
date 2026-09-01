class Solution {
public:
    bool wordBreakHelper(int index, string& s, unordered_set<string>& st, vector<int>& dp) {
        if (index == s.length()) return true;
        if (dp[index] != -1) return dp[index];
        bool ans = false;
        for (int i = index; i< s.length(); i++) {
            if (st.find(s.substr(index, i-index+1)) != st.end()) {
                ans = ans || wordBreakHelper(i+1, s, st, dp);
            }
        }
        return dp[index] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.length()+1, -1);
        for (auto word : wordDict) {
            st.insert(word);
        }
        return wordBreakHelper(0, s, st, dp);
    }
};
