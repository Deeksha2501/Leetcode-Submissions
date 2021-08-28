class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string , vector<pair<int , string>>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
         if(!mp.count(key))
            return "";
        int start = 0, end = mp[key].size();
        while(start < end) {
            int mid = start + (end-start)/2;
            if(mp[key][mid].first > timestamp)
                end = mid;
            else
                start = mid + 1;
        }
        return start > 0 and start <= mp[key].size() ? mp[key][start-1].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */