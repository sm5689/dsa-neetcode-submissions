class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    void helper(int index, string& s, vector<vector<string>>& pali, vector<string>& tp) {
        if (index == s.length()) {
            pali.push_back(tp);
            return;
        }
        for (int i = index; i< s.length(); i++) {
            if (isPalindrome(s, index, i)) {
                tp.push_back(s.substr(index, i-index+1));
                helper(i+1, s, pali, tp);
                tp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pali;
        vector<string> tp;
        helper(0, s, pali, tp);
        return pali;
    }
};
