class Solution {
public:
    int numSub(string s) {
        long long cnt=0,sum=0;
        int mod=1000000007;
        for(char c : s){
            if(c == '0'){
                long long int temp = (cnt%mod*(cnt+1)%mod)/2;
                sum = (sum + temp)%mod;
                cnt=0;
            }else{
                cnt++;
                cnt = cnt%mod;
            }
        }
        int temp = (cnt%mod*(cnt+1)%mod)/2;
        sum = (sum + temp)%mod;
        return sum;
    }
};