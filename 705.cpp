class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> set;
    int prime=997;
    
    MyHashSet() {
        set = vector<vector<int>>(1000);
    }
    
    int getKey(int k){
        return k%prime;
    }
    
    void add(int key) {
        int k = getKey(key);
        if(contains(key))return;
        set[k].push_back(key);
    }
    
    void remove(int key) {
        int k = getKey(key);
        vector<int> &v = set[k];
        auto it = v.begin();
        for(; it!= v.end() ; it++){
            if(*it == key){
                v.erase(it);
                break;
            }
        }
        // set[k] = v;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k = getKey(key);
        vector<int> v = set[k];
        for(auto i : v){
            if( i == key)return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */