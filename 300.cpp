class Solution {
public:
    vector<int> arr;
    int n;
    unordered_map<string , int> mem;
    
    int dfs(int i , int prev){
        if(i == n)return 0;
        string s = "";
        s += to_string(i) + "+" + to_string(prev);
        if(mem.find(s) != mem.end())return mem[s];
        
        if(i == 0 || arr[i] > prev)
            return mem[s] = max(1 + dfs(i+1 , arr[i]) , dfs(i+1 , prev));
        return mem[s] = dfs(i+1 , prev);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        this->arr = nums;
        n = nums.size();
        vector<int> dp(n+1 , 1);
        int res = 1;
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(arr[j] < arr[i])dp[i] = max(dp[i] , 1+dp[j]);
            }
            res = max(res , dp[i]);
        }
        return res;
    }
};