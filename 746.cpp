class Solution {
public:
    vector<int> cost;
    vector<int> dp;
    
    int dfs(int i){
        if(i >= cost.size())return 0;
        if(dp[i] != -1)return dp[i];
        dp[i] = cost[i] + min(dfs(i+1) , dfs(i+2));
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& c) {
        int n = c.size();
        cost = c;
        dp = vector<int>(n+1 , -1);
        return min(dfs(0)  , dfs(1));
        // int sum=0;
        // int i=n;
        // for(i ; i>1 ; i--){
        //     cout<<"i = "<<i;
        //     sum += min(cost[i-1] , cost[i-2]);
        //     if(cost[i-1]>=cost[i-2])i--;
        // }
        // if(i == 2)sum += cost[0];
        // return sum;
    }
};