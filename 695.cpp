class Solution {
public:
    void dfs(int i , int j, vector<vector<int>>& grid , vector<vector<bool>>& vis, int &count ){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0)return;
        if(vis[i][j] == true || grid[i][j] == 0)return;
        
        count++;
        vis[i][j] = true;
        dfs(i+1 , j , grid , vis , count);
        dfs(i , j+1 , grid , vis , count);
        dfs(i-1 , j , grid , vis , count);
        dfs(i , j-1 , grid , vis , count);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        
        int res = 0;
        
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                int count = 0;
                dfs(i , j , grid , vis , count);
                res = max(res , count);
            }
        }
        
        return res;
    }
};
