class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> presum(n);
        
        int sum=s[0]-'a';
        presum[0] = sum;
        for(int i=1 ; i<s.length() ; i++){
            sum += s[i]-'a';
            presum[i] = sum;
        }
        
        
        int res=INT_MAX;
        for(int i=0 ; i<n ; i++){
            int flips =0;
            if(i > 0)flips = presum[i-1];
            int bs = sum - presum[i];
            flips += ((n-i-1) - bs);
            res = min(flips , res);
        }
        
        return res;
        
    }
};