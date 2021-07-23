class Solution {
public:
    vector<int> nums1, nums2;
    vector<vector<int>> mem , dp;
    int n, m;
    
    int dfs(int i , int j){
        if(i >= n || j>= m)return 0;
        if(mem[i][j] != -1)return mem[i][j];
        if(nums1[i] == nums2[j]){
            return mem[i][j] = 1 + dfs(i+1 , j+1);
        }else{
            return mem[i][j] = max({
                dfs(i+1 , j),
                dfs(i , j+1)
            });
        }
        
    }
    
    int maxUncrossedLines(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        n = n1.size();
        m = n2.size();
        mem = vector<vector<int> >(n+1 , vector<int>(m+1 , -1));        
        dp = vector<vector<int> >(n+1 , vector<int>(m+1 , 0));
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                if(nums1[i] == nums2[j])dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
            }
        }

        // return dfs(0 , 0);
        return dp[0][0];
    }
};