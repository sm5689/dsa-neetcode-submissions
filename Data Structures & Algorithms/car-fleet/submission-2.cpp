class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> totalTime;
        vector<pair<int, int>> posSpeed;
        stack<float> st;
        for (int i = 0; i< speed.size(); i++) {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.begin(), posSpeed.end());
        for (int i = 0; i< speed.size(); i++) {
            float t = (float)(target - posSpeed[i].first)/(float)(posSpeed[i].second);
            totalTime.push_back(t);
        }
        for (int i = speed.size()-1; i>= 0; i--) {
            if (!st.empty() && totalTime[i] <= st.top()) {
                continue;
            }
            st.push(totalTime[i]);
        }
        return st.size();
    }
};
