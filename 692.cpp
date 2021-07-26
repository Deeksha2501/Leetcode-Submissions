class Solution {
public:
    
    static bool cmp(pair<int , string> a, pair<int , string> b){
        if(a.first == b.first)return a.second<b.second;
        return a.first > b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> m;
        int n=words.size();
        for(int i=0 ; i<n ; i++){
            m[words[i]]++;
        }
        vector<pair<int , string>> v;
        for(auto [key, value]: m){
            v.push_back({value , key});
        }
        
        vector<string> res;
        
        sort(v.begin() , v.end() , cmp);
        for(int i=0 ; i<k ; i++){
            res.push_back(v[i].second);
        }
        return res;
        
        
    }
};