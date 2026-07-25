class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for (auto str : strs) {
            vector<int> freq(26, 0);
            for (int i = 0; i< str.length(); i++) {
                freq[str[i]-'a']++;
            }
            string key = "";
            for (int i = 0; i< 26; i++) {
                key += to_string(freq[i])+"#";
            }
            mpp[key].push_back(str);
        }
        vector<vector<string>> anagrams;
        for (auto p : mpp) {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
