class Solution {
public:
    
    vector<vector<int>> mat;
    vector<vector<bool>> vis;
    int sum=0;
    
    // bool isValid(int i , int j){
    //     return (i >=0 && i < mat.size() && j >=0 && j < mat[0].size() && mat[i][j] == 1);
    // }
    
    int dfs(int i , int j ){
        if(!(i >=0 && i < mat.size() && j >=0 && j < mat[0].size()))return 1;
        if(mat[i][j] == 0)return 1;
        if(vis[i][j])return 0;
        vis[i][j] = true;
        return dfs(i+1 , j) + dfs(i, j+1) + dfs(i-1 , j) + dfs(i , j-1);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        mat = grid;
        vis = vector<vector<bool>>(grid.size() , vector<bool>(grid[0].size() , false));
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j]==1)return dfs(i,j);
            }
        }
        return sum;
    }
};