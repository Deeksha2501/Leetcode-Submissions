class Solution {
public:

//     int fact(int n){
//         int res = 1;
//         for (int i = 2; i <= n; i++)
//             res = res * i;
//         return res;
//     }
    
//     int nCr(int n, int r){
//         return fact(n) / (fact(r) * fact(n - r));
//     }
    
    
    int numOfSubarrays(vector<int>& arr) {
        int m = pow(10, 9) + 7;
        int o=0,e=0,c=0;
        int n = arr.size();
        
        if(arr[0]%2){
            c = 1;
            o = 1;
        }else{
            e+=1;
        }
        
        for(int i=1 ; i<n ; i++){
            if(arr[i]%2){
                
                c = ((c%m) + (e%m) + 1)%m;
                swap(e , o);
                o = (o+1)%m;
                
            }else{
                
                c = ((c%m) + (o%m))%m;
                e = (e+1)%m;
                
            }
        }
        return c;
        
    }
};