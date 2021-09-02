class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> mem;
    int n,dst;
    
    int dfs(int i , int k){
        if(i == dst)return 0;
        if(k == 0)return INT_MAX;
        if(mem[i][k] != -1)return mem[i][k];
        int res= INT_MAX;
        for(auto p : adj[i]){
            int temp = dfs(p.first , k-1);
            if(temp != INT_MAX){
                res = min(res , temp+p.second);
            }
        }
        return mem[i][k] = res;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        this->n = n;
        this->dst = dst;
        adj = vector<vector<pair<int , int>>>(n);
        mem = vector<vector<int>>(n , vector<int>(k+2 , -1));
        for(auto f : flights){
            int s = f[0], d = f[1], p =f[2];
            adj[s].push_back(make_pair(d , p));
        }
        int ans = dfs(src , k+1);
        if(ans == INT_MAX)return -1;
        return ans;
        // return 0;
    }
};