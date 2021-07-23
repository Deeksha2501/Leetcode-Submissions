class Solution {
public:
    vector<int> nums;
    int n,sum;
    
    
    bool dfs(int curr_sum , int k , vector<int> vis , int in){
        if(k == 0)return true;
        if(curr_sum == sum)return dfs(0 , k-1 , vis , 0);
        for(int i=in ; i<n ; i++){
            if(!vis[i] && curr_sum + nums[i] <= sum){
                vis[i] = true;
                bool x = dfs(curr_sum + nums[i] , k , vis , i+1);
                if(x)return true;
                vis[i] = false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        nums = arr;
        n = nums.size();
        int s=0;
        for(int i=0 ; i<n ; i++){
            s += nums[i];
        }
        if(s%k != 0)return false;
        sum = s/k;
        
        vector<int> vis(n);
        return dfs(0 , k , vis,0);
    }
};