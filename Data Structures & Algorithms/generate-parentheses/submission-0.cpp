class Solution {
public:
    void helper(int n, string s, vector<string>& ans, int open, int close) {
        if (close > open) return;
        if (open+close == 2*n && open == close) {
            ans.push_back(s); return;
        } 
        string tmp = s;
        s = s+'(';
        if (open <= n) helper(n, s, ans, open+1, close);
        s = tmp;
        if (open > close) {
            s = s+')';
            helper(n, s, ans, open, close+1);
        } 
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        helper(n, s, ans, 0, 0);
        return ans;
    }
};
