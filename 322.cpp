class Solution {
public:
    vector<int> cns;
    vector<vector<int> > memo;
    // int amt;
    int n;
    
    int dfs(int i , int amt){
        if(amt == 0)return 0;
        if(i >= cns.size())return INT_MAX;
        if(memo[i][amt] != -1)return memo[i][amt];
        if(cns[i] <= amt){
            int a = dfs(i , amt-cns[i]);
            if(a != INT_MAX)a++;
            memo[i][amt] = min(a , dfs(i+1 , amt));
            return memo[i][amt];
        }else{
            memo[i][amt] = dfs(i+1 , amt);
            return memo[i][amt];
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        cns = coins;
        n = cns.size();
        memo = vector<vector<int>>(n+1 , vector<int>(amount+1 , -1));
        
        int res = dfs(0 , amount);
        if(res == INT_MAX)return -1;
        
        return res;
        
        
    }
};