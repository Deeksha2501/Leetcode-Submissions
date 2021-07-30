class Solution {
public:
    int maximalSquare(vector<vector<char>>& matr) {
        int n = matr.size();
        int m = matr[0].size();
        
        vector<vector<int>> dp(n , vector<int>(m , 0));
        
        int res=0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                int mn=INT_MAX;
                if(i>0 && j>0)mn = min({mn , dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1]});
                if(mn == INT_MAX)mn = 0;
                if(matr[i][j] == '1')dp[i][j] = 1 + mn;
                
                res = max(res , dp[i][j]*dp[i][j]);
            }
        }
        
        return res;
        
    }
};
