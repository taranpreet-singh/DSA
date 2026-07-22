class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        // vector<pair<int, string>> req = map[key]; // this exceeds the time limit
        auto& req = map[key];
        int l = 0, r = req.size() - 1;
        string res = "";
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (req[m].first == timestamp) {
                return req[m].second;
            } else if (req[m].first < timestamp) {
                res = req[m].second; // best candidate so far
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */