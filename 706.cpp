class MyHashMap {
public:
    
    vector<int> mp;
    vector<vector<pair<int , int>>> um;
    int size=769;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        // mp = vector<int>(1000001 , -1);
        um.resize(769);
    }
    
    int getInd(int key){
        return key%size;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        // mp[key] = value;
        int in = getInd(key);
        vector<pair<int , int>> v = um[in];
        for(auto &it : v){
            if(it.first == key){
                it.second = value;
                // cout<<"hi"<<endl;
                um[in] = v;
                return;
            }
        }
        
        v.push_back({key , value});
        um[in] = v;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        // return mp[key];
        int in = getInd(key);
        vector<pair<int , int>> v = um[in];
        for(auto it : v){
            if(it.first == key){
                return it.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        // mp[key] = -1;
        int in = getInd(key);
        vector<pair<int , int>> v = um[in];
        for(int i=0 ; i<v.size() ; i++){
            pair<int , int> p = v[i];
            if(p.first == key){
                v.erase(v.begin() + i);
                um[in] = v;
                return;
            }
        }
        // v.push_back({key , value});
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */