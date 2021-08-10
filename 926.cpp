class Solution {
public:
    vector<vector<int>> mem;
    
    int dfs(string s , int i , bool flag){
        if(i>=s.length())return 0;
        if(mem[i][flag] != -1)return mem[i][flag];
        if(flag){
            return mem[i][flag] = ('1' - s[i]) + dfs(s , i+1 , true);
        }else{
            if(s[i] == '0')return mem[i][flag] = dfs(s , i+1 , false);
            return mem[i][flag] = min({
                dfs(s , i+1 , true), //rehne do 1
                1+dfs(s , i+1 , false)  //change karo 0 mein
            });
        }
    }
    
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        
        vector<int> pre(n);
        pre[0] = s[0]-'0';
        for(int i=1 ; i<n ; i++){
            pre[i] += pre[i-1] + s[i]-'0';
        }
        
        int res = n-pre[n-1];
        int total = pre[n-1];
        
        for(int i=1 ; i<=n ; i++){
            int l_ones = pre[i-1];
            int r_ones = total - pre[i-1];
            int temp = l_ones + (n-i)-r_ones;
            res = min(temp, res);
        }
        
        return res;
        
        
        // mem = vector<vector<int>>(n , vector<int>(2 , -1));
        // return dfs(s , 0 , false);
    }
};



class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int sum = 0 , n = s.length();
        vector<int> presum(n);
        presum[0] = s[0] - '0';
        sum = presum[0];
        
        for(int i=1 ; i<s.length() ; i++){
            sum += s[i] - '0';
            presum[i] += sum;
            // cout<<"\npresum = "<<presum[i]<<" at i = "<<i;
        }
        
        
        int res=INT_MAX;
        
        for(int i=0 ; i<n ; i++){
            int zeroes=0;
            if(i > 0)zeroes = presum[i-1];
            int flips = zeroes;
            int ones = sum - presum[i];
            flips += ((n-i-1) - ones);
            // cout<<"\nflips = "<<flips;
            res = min(res , flips);
        }
        
        return res;
        
    }
};