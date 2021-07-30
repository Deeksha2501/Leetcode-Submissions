class Solution {
public:
    int countPrimes(int n){
        vector<bool> prime(n+1, false);
        if(n <2)return 0;
        int cnt=0;
        prime[2] = false;
        for(int i=2 ; i<=n ; i++){
            if(prime[i] == false)cnt++;
            for(int j=1 ; j*i<=n ; j++){
                prime[i*j] = true;
            }
        }
        return cnt;
    }
    
    int numPrimeArrangements(int n) {
        int p = countPrimes(n);
        int pp = n-p;
        // cout<<p;
        int mod = (int) (1e9 + 7);
        long long ans=1;
        while(p){
            ans = (ans * p)%mod;
            p--;
        }
        while(pp){
            ans = (ans * pp)%mod;
            pp--;
        }
        return (int)ans;
    }
};