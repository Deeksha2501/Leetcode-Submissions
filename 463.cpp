class Solution {
public:
    vector<vector<int>> grid;
    int n, m;
    
    int dfs(int i, int j){
        if(i <0 || j<0 || i>=n || j>= m)return 1;
        if(grid[i][j] == 0)return 1;
        if(grid[i][j] == 2)return 0;
        grid[i][j] = 2;
        return dfs(i , j+1)+
               dfs(i+1 , j)+
               dfs(i , j-1)+
               dfs(i-1 , j);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        if(n == 0)return 0;
        m = grid[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1)return dfs(i,j);
            }
        }
        return 0;
    }
};