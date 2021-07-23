class Solution {
public:
    int n , m;
    vector<vector<int>> arr , dp;
    
    
    int dfs(int i , int j){
        if(i >= n)return INT_MAX;
        if(j < 0 || j >= m)return INT_MAX;
        if(i == n-1)return arr[i][j];
        if(dp[i][j] != -1)return dp[i][j];
        int dl=0, b=0, dr=0;
        dl = dfs(i+1 , j-1 );
        b = dfs(i+1 , j);
        dr = dfs(i+1 , j+1);
        return dp[i][j] = arr[i][j] + min({dl , b , dr});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        arr = matrix;
        n = arr.size();
        m = arr[0].size();
        dp = vector<vector<int>>(n+1 , vector<int>(m+1 , -1));
        int mn = INT_MAX;
        for(int j=0 ; j<m ; j++){
            mn = min(mn , dfs(0 , j));
        }
        return mn;
    }
};