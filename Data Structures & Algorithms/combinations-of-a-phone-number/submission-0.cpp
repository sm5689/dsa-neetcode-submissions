class Solution {
public:
    void helper(int index, string& digits, string& temp, vector<string>& finalList, unordered_map<char, string>& phone) {
        if (index >= digits.length()) {
            finalList.push_back(temp);
            return;
        }
        string curr = phone[digits[index]];
        for (int i = 0; i< curr.length(); i++) {
            string t = temp;
            temp = temp+curr[i];
            helper(index+1, digits, temp, finalList, phone);
            temp = t;
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        unordered_map<char, string> phone;
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        vector<string> finalList;
        string temp = "";
        helper(0, digits, temp, finalList, phone);
        return finalList;
    }
};
