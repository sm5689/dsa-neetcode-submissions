class Solution {
public:
    bool isPalindrome(string s) {

        int st = 0;
        int en = s.length()-1;
        
        while (st < en) {
            cout<< s[st] << " " << s[en] << endl;

            while (st < en && !((s[st] >= 'a' && s[st] <= 'z') || (s[st] >= 'A' && s[st] <= 'Z') || (s[st] >= '0' && s[st] <= '9'))) st++;
            while (st < en && !((s[en] >= 'a' && s[en] <= 'z') || (s[en] >= 'A' && s[en] <= 'Z') || (s[en] >= '0' && s[en] <= '9'))) en--;
            
            char st_normalized = (s[st] >= 'A' && s[st] <= 'Z') ?  s[st]+32 : s[st];
            char en_normalized = (s[en] >= 'A' && s[en] <= 'Z') ?  s[en]+32 : s[en];
            
            if (st_normalized != en_normalized) {
                return false;
            }
            
            st++;
            en--;
        }

        return true;

    }
};
