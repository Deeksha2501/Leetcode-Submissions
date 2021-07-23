class Solution {
public:
    int count=0;
    int t;
    vector<vector<int> > dp;
    
    int dfs(int i, vector<int> nums , int sum){
        if(i == nums.size()){
            if(sum == t){
                dp[i][1000+sum] = 1;
                return 1;
            }
            dp[i][1000+sum] = 0;
            return 0;
        }
        
        if(i > nums.size()){
            dp[i][1000+sum] = 0;
            return 0;
        }
        
        if(dp[i][1000+sum] != -1)return dp[i][1000+sum];
        
        dp[i][1000+sum] = dfs(i+1 , nums , sum + nums[i]) + dfs(i+1 , nums , sum - nums[i]);
        return dp[i][1000+sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        t = target;
        int n = nums.size();
        int sum=0;
        for(int i=0 ; i<n ; i++){
            sum += nums[i];
        }
        dp = vector<vector<int> >(n+1 , vector<int>(1000+sum+1 , -1));
        return dfs(0 , nums , 0);
        // return count;
    }
};