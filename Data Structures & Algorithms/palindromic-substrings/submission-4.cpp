class Solution {
public:
    int expandAroundCenter(string& s, int start, int end) {
        int cnt = 0;
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            start--, end++;
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int start = 0;
        int end = 0;
        int total = 0;
        for (int i = 0; i< s.length(); i++) {
            total+= expandAroundCenter(s, i, i);
            total+= expandAroundCenter(s, i, i+1);
        }
        return total;
    }
};
