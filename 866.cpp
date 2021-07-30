class Solution {
public:
     bool isPrime(int n){
         if (n < 2) return false;
        int r = (int) sqrt(n);
        for (int d = 2; d <= r; ++d)
            if (n % d == 0) return false;
        return true;
     }
    
    int primePalindrome(int n) {
       for(int l=1 ; l<=5 ; l++) {
           for(int root = pow(10, l-1) ; root<pow(10, l) ; root++){
               string ss = to_string(root);
               for(int k=l-2 ; k>=0 ; k--){
                   ss = ss + ss[k];
               }
               int x = stoi(ss);
               // cout<<"x = "<<x;
               if(x >= n && isPrime(x))return x;
           }
        
       for(int root = pow(10, l-1) ; root<pow(10, l) ; root++){
           string ss = to_string(root);
           for(int k=l-1 ; k>=0 ; k--){
               ss = ss + ss[k];
           }
           int x = stoi(ss);
           if(x >= n && isPrime(x))return x;
       }
    }
        return INT_MAX;
    }
};