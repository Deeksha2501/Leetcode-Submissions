class Solution {
public:
    vector<int> colors;
    vector<vector<int>> gph;
    
    bool dfs(int i , int c){
        if(colors[i] != 0){
            return colors[i] == c;
        }
        colors[i] = c;
        vector<int> v  = gph[i];
        for(int node : v){
            bool x = dfs(node , -c);
            if(x == false)return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        gph = graph;
        colors = vector<int>(n+1 , 0);
        for (int i = 0; i < n; i++) {           
            if (colors[i] == 0 && !dfs(i , 1)) {
                return false;
            }
        }
        return true;
    }
};