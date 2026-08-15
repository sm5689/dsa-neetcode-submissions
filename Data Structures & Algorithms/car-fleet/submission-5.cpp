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
        for (int i = speed.size()-1; i>= 0 ; i--) {
            float t = (float)(target - posSpeed[i].first)/(float)(posSpeed[i].second);
            
            if (top!= -1 && t <= top) {
                continue;
            }
            top = t;
            cnt++;
        }
        return cnt;
    }
};
