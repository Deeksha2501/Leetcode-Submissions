class Solution {
public:
    vector<vector<bool>> vis;
    vector<vector<char>> g;
    int n, m;
    
    void dfs(int i , int j){        
        if(i < 0 || i >=n || j < 0 || j >= m)return;
        if(g[i][j] == '0')return;
        if(vis[i][j])return;
        vis[i][j] = true;

        dfs(i+ 1 , j);        
        dfs(i , j+1);
        dfs(i - 1 , j);
        dfs(i , j - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<bool>>(n+1 , vector<bool>(m+1 , false));
        
        int count=0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i , j);
                    count++;
                }
            }
        }
        
        return count;
        
    }
};