class Solution {
public:
    int n;
    vector<int> dp;
    int dfs(int i){
        if(i == n)return 1;
        if(i > n)return 0;
        if(dp[i] != -1)return dp[i];
        return dp[i] = dfs(i+1) + dfs(i+2);
    }
    
    int climbStairs(int nn) {
        n = nn;
        dp = vector<int>(nn+2 , 0);
        dp[n] = 1;
        dp[n+1] = 0;
        for(int i=n-1 ; i>=0 ; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }
        // return dfs(0);
        return dp[0];
    }
};