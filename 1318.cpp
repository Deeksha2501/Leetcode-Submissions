class Solution {
public:
    int minFlips(int a, int b, int c) {
        int temp = a | b , temp1 = a ^ b;
        
        int xr = temp ^ c;
        int res=0;
        while(xr > 0){
            res++;
            int bit = xr & ~(xr-1);
            xr = xr & (xr-1);
            if(((temp & bit) > 0) && ((temp1 & bit) == 0)){
                res++; 
            }
        }
        return res;
    }
};