class Solution {
public:
    vector<int> arr;
    vector<vector<int> > memo;
    int n;
    
    bool dfs(int i , int sum){
        if(sum == 0)return true;
        if(i >= n || sum<0)return false;
        if(memo[i][sum] != -1)return memo[i][sum];
        memo[i][sum] = dfs(i+1 , sum-arr[i]) || dfs(i+1 , sum);
        return memo[i][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        int sum=0;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
        }
        
        if(sum%2)return false;
        
        int s = sum/2;
        
        vector<vector<bool> > dp = vector<vector<bool> >(n+1 , vector<bool>(s+1));
        for(int i=0;i<=n;i++)dp[i][0]=true;
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=1 ; j<=s ; j++){
                if(nums[i] <= j){
                    dp[i][j] = dp[i+1][j-nums[i]] || dp[i+1][j];
                }else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        
        return dp[0][s];
    }
};