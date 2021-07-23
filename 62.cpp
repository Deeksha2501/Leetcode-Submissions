class Solution {
public:
    int m , n;
    vector<vector<int>> mem;
    
    int dfs(int i , int j){
        if(i == n-1 && j == m-1)return 1;
        if( i >=n || j>= m)return 0;
        if(mem[i][j] != -1)return mem[i][j];
        return mem[i][j] = dfs(i+1 , j) + dfs(i , j+1);
    }
    
    int uniquePaths(int nn, int mm) {
        n = nn, m = mm;
        mem = vector<vector<int>>(n+1 , vector<int>(m+1 , -1));
        return dfs(0 , 0);
    }
};