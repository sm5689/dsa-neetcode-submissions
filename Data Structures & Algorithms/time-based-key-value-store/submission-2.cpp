class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> tm;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (tm.find(key) == tm.end()) return "";
        auto& target = tm[key];
        int start = 0;
        int end = target.size()-1;
        while (start <= end) {
            int mid = (start+end)/2;
            if (target[mid].second == timestamp) return target[mid].first;
            if (target[mid].second < timestamp) start = mid+1;
            else end = mid-1;
        }
        return end >= 0 ? target[end].first : "";
    }
};
