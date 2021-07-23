class Solution {
public:
    vector<vector<int> >dp;
    
    int solve(int n , int e){
        if(n == 0 || n == 1)return n;
        if(e == 1)return n;
        if(dp[n][e] != -1)return dp[n][e];
        int res=INT_MAX;
        for(int k=1 ; k<n ; k++){
            // int l,r;
            // string sl = to_string(k-1) + " " + to_string(e-1);
            // if(mp.find(sl) != mp.end())l = mp[sl];
            // else 
            int l = solve(k-1,e-1);
            
            // string sr = to_string(n-k) + " " + to_string(e);
            // if(mp.find(sr) != mp.end())r = mp[sr];
            // else 
            int r = solve(n-k , e);
            
            int temp = 1 + max(l,r);
            res = min(temp, res);
        }
        
        return dp[n][e] = res;
    }
    
    int twoEggDrop(int n) {
        dp = vector<vector<int>>(n+1 , vector<int>(3 , -1));
        return solve(n , 2);
    }
};