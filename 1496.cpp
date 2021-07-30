struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};   

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<pair<int, int> , hash_pair > st;
        int x=0, y=0;
        
        pair<int , int> p;
        p.first = x;
        p.second = y;
        st.insert(p);
        
        for(int i=0 ; i<path.length() ; i++){
            if(path[i] == 'N'){
                y--;
            }
            if(path[i] == 'E'){
                x++;
            }
            if(path[i] == 'W'){
                x--;
            }
            if(path[i] == 'S'){
                y++;
            }
            
            p.first = x;
            p.second = y;
            if(st.find(p) != st.end()){
                return true;
            }else{
                st.insert(p);
            }
        }
        return false;
    }
};