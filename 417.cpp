class Solution {
public:
    vector<vector<vector<bool>>> dp;
    vector<vector<int>> arr;
    int n, m;
    
    void dfs(int i , int j , int flag , int h){
        if(i <0 || i>=n || j<0 || j>=m)return;
        if(dp[i][j][flag])return;
        if(arr[i][j] >= h){
            dp[i][j][flag] = true;
            dfs(i , j+1 , flag , arr[i][j]);
            dfs(i+1 , j , flag , arr[i][j]);
            dfs(i , j-1 , flag , arr[i][j]);
            dfs(i-1 , j , flag , arr[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        arr = heights;
        n = arr.size();
        m = arr[0].size();
        dp = vector<vector<vector<bool>>>(n , vector<vector<bool>>(m , vector<bool>(2 , false)));
        for(int j=0 ; j<m ; j++){
            dfs(n-1 , j , 0 , INT_MIN);
            dfs(0 , j , 1 , INT_MIN);
        }
        for(int i=0 ; i<n ; i++){
            dfs(i , m-1 , 0 , INT_MIN);
            dfs(i , 0 , 1 , INT_MIN);
        }
        
        vector<vector<int>> res;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(dp[i][j][0] == dp[i][j][1] && dp[i][j][0] == true){
                    res.push_back({i , j});
                }
            }
        }
        return res;
    }
};