class Solution {
public:
    int n;
    vector<int> p;
    int fee;
    vector<vector<int>> mem , dp;
    
    int dfs(int i , bool flag){
        if(i >= n)return 0;
        if(mem[i][flag] != -1)return mem[i][flag];
        if(flag){
            return mem[i][flag] = max({
                p[i]-fee + dfs(i+1 , !flag),
                dfs(i+1 , flag)
            });
        }else{
            return mem[i][flag] = max({
                dfs(i+1 , !flag) - p[i],
                dfs(i+1, flag)
            });
        }
    }
    
    int maxProfit(vector<int>& prices, int f) {
        n = prices.size();
        p = prices;
        fee = f;
        // mem = vector<vector<int>>(n+1 , vector<int>(2 , -1));
        dp = vector<vector<int>>(n+1 , vector<int>(2 , 0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=1 ; j>=0 ; j--){
                if(j){
                    dp[i][j] = max({
                        p[i]-fee + dp[i+1][!j],
                        dp[i+1][j]
                    });
                }else{
                    dp[i][j] = max({
                        dp[i+1][!j] - p[i],
                        dp[i+1][j]
                    });
                }
            }
        }
        return dp[0][0];
        // return dfs(0  , false);
    }
};