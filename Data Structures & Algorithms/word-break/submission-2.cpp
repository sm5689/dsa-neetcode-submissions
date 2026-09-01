class Solution {
public:
    bool wordBreakHelper(int index, string& s, unordered_set<string>& st, vector<int>& dp) {
        if (index == s.length()) return true;
        if (dp[index] != -1) return dp[index];
        for (int i = index; i< s.length(); i++) {
            if (st.count(s.substr(index, i-index+1))) {
                if(wordBreakHelper(i+1, s, st, dp)) return true;
            }
        }
        return dp[index] = false;
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
