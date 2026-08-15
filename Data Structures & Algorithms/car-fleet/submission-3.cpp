class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> totalTime;
        vector<pair<int, int>> posSpeed;
        float top = -1;
        int cnt = 0;
        for (int i = 0; i< speed.size(); i++) {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.begin(), posSpeed.end());
        for (int i = 0; i< speed.size(); i++) {
            float t = (float)(target - posSpeed[i].first)/(float)(posSpeed[i].second);
            totalTime.push_back(t);
        }
        for (int i = speed.size()-1; i>= 0; i--) {
            if (top!= -1 && totalTime[i] <= top) {
                continue;
            }
            top = max(top, totalTime[i]);
            cnt++;
        }
        return cnt;
    }
};
