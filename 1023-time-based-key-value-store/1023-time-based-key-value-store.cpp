class TimeMap {
private:

unordered_map<string, vector<pair<string, int>>> mp;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mp[key].push_back({value, timestamp});
        
    }
    
    string get(string key, int timestamp) {

        if(mp.find(key) == mp.end()) return "";

        if(timestamp < mp[key][0].second) return "";

        int left = 0;
        int right = mp[key].size() - 1;
        while(left <= right)
        {
            int mid = left - (left - right)/2;
            if(mp[key][mid].second > timestamp) right = mid - 1;
            else left = mid + 1;
        }

        return mp[key][right].first;

        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */