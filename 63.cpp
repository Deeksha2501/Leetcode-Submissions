class Solution {
public:
    vector<vector<int>> grid, mem;
    int n , m;
    
    int dfs(int i , int j){
        if(i == n-1 && j == m-1 && grid[i][j] == 0)return 1;
        if(i >= n || j>= m)return 0;
        if(grid[i][j] == 1)return 0;
        if(mem[i][j] != -1)return mem[i][j];
        return mem[i][j] = dfs(i+1 , j) + dfs(i , j+1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        this->n = grid.size();
        m = grid[0].size();
        this->grid = grid;
        mem = vector<vector<int>>(n , vector<int>(m+1 , -1));
        return dfs(0 , 0);
    }
};