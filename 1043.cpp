class Solution {
public:
    vector<int> v;
    int k;
    vector<int> dp;
    
    // int dfs(int i , int start , int size){
    //     if(i >= v.size())return 0;  
    //     if(size >= k){
    //         int mx = INT_MIN;
    //         for(int j=start ; j<i ;j++){
    //             mx = max(mx , v[j]);
    //         }
    //         int sum=0;
    //         if(mx != INT_MIN)sum = mx*k;
    //         return sum + dfs(i+1 , i+1 , 1);
    //     }else{
    //         int mx = INT_MIN;
    //         for(int j=start ; j<i ;j++){
    //             mx = max(mx , v[j]);
    //         }
    //         int sum=0;
    //         if(mx != INT_MIN)sum = mx*(i-start+1);
    //         return max(dfs(i+1 , start , size+1) , sum + dfs(i+1 , i+1 , 1));
    //     }
    // }
    
    int dfs(int i){
        if(i == v.size())return 0;
        if(dp[i] != -1)return dp[i];
        int mx = INT_MIN;
        int sum = INT_MIN;
        
        for(int j=0 ; j<k ; j++){
            int curr = i+j;
            if(curr >= v.size())break;
            mx = max(mx , v[curr]);
            int l = mx*(j+1);
            int r = dfs(curr+1);
            sum = max(sum , l+r);
        }
        dp[i] = sum;
        return sum;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int kk) {
        v = arr;
        k = kk;
        int n = arr.size();
        dp = vector<int>(n+1 , -1);
        return dfs(0);
    }
};              
                            