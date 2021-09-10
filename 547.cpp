class Solution {
public:
    vector<vector<int>> arr;
    vector<bool> vis;
    int n, m;
    
    void dfs(int i){
        if(i>=n)return;
        if(vis[i] == true)return;
        vis[i] = true;
        for(int ii=0 ; ii<n ; ii++){
            if(arr[i][ii] == 1)dfs(ii);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        arr = isConnected;
        n = arr.size();
        m = arr[0].size();
        int cnt=0;
        vis = vector<bool>(n+1 , false);
        for(int i=0 ; i<n ; i++){
            if(vis[i] == false){
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};

// [[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]

