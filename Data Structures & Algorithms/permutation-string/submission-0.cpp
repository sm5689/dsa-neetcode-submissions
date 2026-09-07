class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_l = s1.length();
        int s2_l = s2.length();
        if (s1_l > s2_l) return false;
        vector<int> s1_total(26, 0);
        vector<int> s2_total(26, 0);

        for (int i = 0; i< s1_l; i++) {
            s1_total[s1[i]-'a']++;
        }
        for (int i = 0; i< s2_l; i++) {
            if (i >= s1_l) {
                s2_total[s2[i-s1_l]-'a']--;
            }
            s2_total[s2[i]-'a']++;
            if (s1_total == s2_total) return true;
        }
        return false;
    }
};
