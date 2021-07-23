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