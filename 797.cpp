class Solution {
public:
    vector<vector<int>> g;
    int n;
    vector<vector<int>> res;
    
    void dfs(int i , vector<int> v){
        if(i == n-1){
            v.push_back(i);
            res.push_back(v);
            return;
        }
        v.push_back(i);
        vector<int> ch = g[i];
        for(int in=0 ; in < ch.size() ; in++){
            dfs(ch[in] , v);
        }
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        g = graph;
        n = graph.size();
        vector<int> v;
        dfs(0 , v);
        return res;
    }
};