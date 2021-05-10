class Solution {
public:
    // bool ifPrime(int n){
    //     int count = 0;
    //     for(int i=1 ; i*i<=n ; i++){
    //         if(n%i == 0){
    //             count++;
    //             if(i != n/i)count++;
    //             if(count>2)return false;
    //         }
    //     }
    //     if(count>2)return false;
    //     return true;
    // }
    
    int countPrimes(int n) {
        bool primes[n+1];
        for(int i=0 ; i<n+1 ; i++){
            primes[i] = false;
        }
        
        int count=0;
        for(int i=2 ; i<n ; i++){
            if(primes[i] == false){
                count++;
                for(int j = 2; i*j < n ; j++){
                    primes[j*i] = true;
                }
            }
        }
        return count;
    }
};