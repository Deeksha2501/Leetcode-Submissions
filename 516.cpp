class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(string s , string t , int i , int j){
        int n=s.length();
        int m=t.length();
        if(i >= n || j >= m)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == t[j])dp[i][j] = 1 + solve(s , t , i+1 , j+1);
        else
            dp[i][j] = max(solve(s , t , i , j+1) , solve(s, t, i+1 , j));
        return dp[i][j];
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin() , s.end());
        int n=s.length();
        int m=t.length();
        dp = vector<vector<int>>(n+1 , vector<int>(m+1));
        
        for(int i=0 ; i<n ; i++){
            dp[i][n] == 0;
            dp[n][i] == 0;
        }
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                
                if(s[i]==t[j])dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i][j+1] , dp[i+1][j]);
            }
        }
         
        return dp[0][0];
        
        // return solve(s , t , 0 , 0);
        
    }
};