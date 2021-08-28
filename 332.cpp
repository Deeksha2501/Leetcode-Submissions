class Solution {
public:
    unordered_map<string , priority_queue<string, vector<string>, greater<string> >> mp;
    vector<string> res;
    
    void dfs(string st){
        while(!mp[st].empty()){
            string s = mp[st].top();
            mp[st].pop();
            dfs(s);
        }
        res.insert(res.begin() , st);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {        
        for(auto v : tickets){
            string a = v[0] , b=v[1];
            mp[a].push(b);
        }
        
        dfs("JFK");   
        
        return res;
        
    }
};