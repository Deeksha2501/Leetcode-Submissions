class Solution {
public:
    vector<vector<int>> arr , dp;
    int n,m;
    
    int dfs(int i , int j){
        if( i== n-1 && j==m-1)return arr[i][j];
        if(i>=n || j>=m)return INT_MAX;
        if(dp[i][j] != -1)return dp[i][j];
        return dp[i][j] = arr[i][j] + min({
            dfs(i+1 , j),
            dfs(i , j+1)
        });
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        arr = grid;
        n = arr.size();
        m = arr[0].size();
        dp = vector<vector<int>>(n+1 , vector<int>(m+1 , -1));
        return dfs(0 , 0);
    }
};