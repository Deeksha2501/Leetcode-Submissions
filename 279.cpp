class Solution {
public:
    vector<int> sqs, dp;
    
    int dfs(int n){
        if(n == 0)return 0;
        if(n < 0)return INT_MAX;
        if(dp[n] != -1)return dp[n];
        int res = INT_MAX;
        for(int i=0 ; i<sqs.size() ; i++){
            res = min(res , dfs(n-sqs[i]));
        }
        if(res != INT_MAX)res++;
        return dp[n] = res;
    }
    
    int numSquares(int n) {
        int i=1;
        while(i*i <= n){
            sqs.push_back(i*i);
            i++;
        }
        
        dp = vector<int>(n+1 , -1);
        
        int cnt = dfs(n);
        if(cnt == INT_MAX)return -1;
        return cnt;
    }
};