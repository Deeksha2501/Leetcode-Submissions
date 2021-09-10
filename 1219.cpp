class Solution {
public:
    vector<vector<int>> g;
    int n , m;
    
    int dfs(int i , int j){

        if(i < 0 || j<0 || i>=n || j>=m)return 0;
        
        if(g[i][j] == 0)return 0;
        int sum = g[i][j];
        g[i][j] = 0;
        int temp = max({
            dfs(i+1 , j),
            dfs(i , j+1), 
            dfs(i-1 , j), 
            dfs(i , j-1)                         
        });
        g[i][j] = sum;
        return sum + temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        g = grid;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]){
                    res = max(res , dfs(i , j));
                }
            }
        }
        return res;
    }
};
