class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push(beginWord);
        st.erase(beginWord);
        int cnt = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i< n; i++) {
                string front = q.front();
                q.pop();
                if (front == endWord) return cnt;
                for (int j = 0; j< front.length(); j++) {
                    char ch = front[j];
                    for (char k = 'a'; k<= 'z'; k++) {
                        front[j] = k;
                        if (st.find(front) != st.end()) {
                            q.push(front);
                            st.erase(front);
                        }
                    }
                    front[j] = ch;
                }
            }
            cnt++;
        }
        return 0;
    }
};
