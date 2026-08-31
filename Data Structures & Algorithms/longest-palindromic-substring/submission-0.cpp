class Solution {
public:
    pair<int, int> expandAroundCenter(string& s, int start, int end) {
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            start--, end++;
        }
        return {start+1, end-1};
    }
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        for (int i = 0; i< s.length(); i++) {
            auto odd = expandAroundCenter(s, i, i);
            auto even = expandAroundCenter(s, i, i+1);
            if (odd.second - odd.first > end - start) {
                start = odd.first;
                end = odd.second;
            }
            if (even.second - even.first > end - start) {
                start = even.first;
                end = even.second;
            }
        }
        return s.substr(start, end-start+1);
    }
};
