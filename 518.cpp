class Solution {
public:
    vector<int> coins;
    vector<vector<int>> mem, dp;
    
    int dfs(int i , int sum){
        if(sum == 0)return 1;
        if(i >= coins.size())return 0;
        if(mem[i][sum] != -1)return mem[i][sum];
        
        if(coins[i] <= sum ){
            return mem[i][sum] =  dfs(i , sum-coins[i]) + dfs(i+1 , sum);
        }
        return mem[i][sum] = dfs(i+1 , sum);
    }
    
    int change(int amount, vector<int>& cns) {
        coins = cns;
        int n = cns.size();
        mem = vector<vector<int>>(n+1 , vector<int>(amount + 1 , -1));
        dp = vector<vector<int>>(n+1 , vector<int>(amount + 1 , 0));
        
        for(int i=0 ; i<=n ; i++){
            dp[i][0] = 1;
        }
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=0 ; j<=amount ; j++){
                if(j >= coins[i])dp[i][j] = dp[i][j-coins[i]] + dp[i+1][j];
                else dp[i][j] = dp[i+1][j];
            }
        }
        
        return dp[0][amount];
        // return dfs(0 , amount);   
    }
};