class Solution {
public:
    pair<int, int> expandAroundCenter(string& s, int start, int end, int& cnt) {
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            start--, end++;
            cnt++;
        }
        return {start+1, end-1};
    }
    int countSubstrings(string s) {
        int start = 0;
        int end = 0;
        int cnt = 0;
        for (int i = 0; i< s.length(); i++) {
            auto odd = expandAroundCenter(s, i, i, cnt);
            auto even = expandAroundCenter(s, i, i+1, cnt);
            if (odd.second - odd.first >= end - start) {
                start = odd.first;
                end = odd.second;
            }
            if (even.second - even.first >= end - start) {
                start = even.first;
                end = even.second;
            }
        }
        return cnt;
    }
};
